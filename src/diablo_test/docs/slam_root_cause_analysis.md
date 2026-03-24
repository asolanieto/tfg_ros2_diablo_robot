# Análisis de por qué SLAM no publica `/map` ni `map->odom`

## Hallazgos principales en la configuración actual

### 1) El puente de `scan` que corrige timestamp/QoS está implementado pero desactivado

En `robot_launch.py` aparecen comentadas las líneas que lanzan `scan_bridge.py`.
Ese bridge hace dos cosas críticas:

- Re-sella (`header.stamp`) cada `LaserScan` con tiempo actual del sistema.
- Convierte de QoS BEST_EFFORT a RELIABLE publicando en `/scan_bridged`.

Sin ese bridge, SLAM consume `/scan` directamente.
Si la marca temporal del lidar llega retrasada o desfasada respecto al reloj ROS,
`slam_toolbox` puede fallar al pedir TF en el tiempo exacto del scan y quedarse sin
actualizar mapa ni publicar `map->odom`.

### 2) `slam_toolbox` está escuchando `/scan` (no `/scan_bridged`)

`slam_localization.yaml` fija `scan_topic: "/scan"`.
Esto evita precisamente el tópico puenteado para robustecer temporización/QoS.

### 3) `odom->base_link` puede no existir al inicio (o ser inconsistente temporalmente)

`diablo_bridge.cpp` solo empieza a publicar TF/odom tras recibir al menos **dos** mensajes
de motor (el primero solo inicializa y hace `return`). Si al arrancar no hay flujo de
telemetría suficiente, SLAM no dispone de la TF base para localizar el láser y no genera mapa.

Además el bridge usa `this->now()` para odom/TF en lugar del stamp original del sensor de motores,
lo que puede introducir incoherencias temporales al cruzar con el timestamp real del scan.

### 4) Dependencia crítica de que exista `base_link -> lidar_link`

El `frame_id` del RPLidar se fuerza por launch a `lidar_link`, y la URDF define
`base_link -> lidar_link` fijo. Si por versión del launch de `rplidar_ros` ese argumento no
se aplica o el driver publica otro frame (`laser`, `rplidar`, etc.), SLAM no puede calcular la
pose del láser y queda inactivo.

## Conclusión técnica más probable

La causa más probable es **fallo temporal/QoS en el pipeline de LaserScan + disponibilidad TF en tiempo del scan**:

- `scan_bridge.py` existe para corregir justo eso.
- En el launch actual está deshabilitado.
- `slam_toolbox` consume el tópico no puenteado.

Este patrón encaja exactamente con el síntoma: SLAM “arranca” pero no publica mapa ni `map->odom`.

## Verificaciones recomendadas (runtime)

1. Comprobar que SLAM recibe scans:

```bash
ros2 topic hz /scan
ros2 topic echo /scan --once
```

2. Comprobar compatibilidad QoS real:

```bash
ros2 topic info /scan -v
```

3. Verificar cadena TF mínima en tiempo real:

```bash
ros2 run tf2_ros tf2_echo odom base_link
ros2 run tf2_ros tf2_echo base_link lidar_link
ros2 run tf2_ros tf2_echo map odom
```

4. Buscar errores típicos en logs de SLAM:

- `Failed to compute laser pose`
- `Lookup would require extrapolation`
- `Message Filter dropping message`

## Cambios concretos sugeridos (orden recomendado)

1. Activar `scan_bridge.py` en launch y usar `scan_topic: /scan_bridged` en SLAM.
2. Alinear timestamps entre odometría y scan (idealmente con tiempo de sensor coherente).
3. Confirmar que el frame del lidar publicado coincide con `lidar_link`.
4. Asegurar que `odom->base_link` se publica desde el inicio (incluso en reposo).
