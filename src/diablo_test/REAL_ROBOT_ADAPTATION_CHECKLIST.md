# Adaptación a robot real: checklist para navegación + teleoperación

## Estado actual validado en esta rama

- Ya existe un **bridge de velocidad**: `/cmd_vel` (`geometry_msgs/Twist`) se traduce a `/diablo/MotionCmd` (`motion_msgs/MotionCtrl`) en `diablo_bridge.cpp`.
- Ya existe un **bridge de odometría**: se consume `/diablo/sensor/Motors`, se integra cinemática diferencial y se publica `TF odom->base_link` + `/odom`.

## Qué falta para cerrar la integración de todo el stack

### 1) Lanzador dedicado a hardware real (sin Webots)

El launch actual (`robot_launch.py`) está orientado a simulación/Webots:
- Importa `WebotsLauncher` y devuelve `webots` en el `LaunchDescription`.
- Usa `diablo_driver` y bridges pensados para “rejuvenecer” timestamps de simulación.

Para robot real, crear un launch específico que arranque solo:
1. `diablo_ctrl_node` (driver propietario)
2. `diablo_bridge` (Twist<->MotionCtrl + odometría)
3. `robot_state_publisher` (+ `joint_state_publisher` si no hay joints reales)
4. `static_transform_publisher` para `base_link->lidar_link`
5. `slam_toolbox` (mapping/localization según modo)
6. `easynav_system` / Nav stack
7. `twist_mux`
8. un teleop de teclado que publique `Twist` a `cmd_vel_key`

### 2) Unificación de tópico de láser

Ahora hay una inconsistencia de configuración:
- EasyNav consume `/scan`
- SLAM consume `/scan_bridged`

En hardware real (si tu LiDAR ya publica bien en `/scan`), unificar ambos nodos para usar `/scan` y eliminar `scan_bridge.py` salvo que necesites adaptación de QoS/timestamp.

### 3) Selección de fuente de velocidad (manual vs autónoma)

La arquitectura con `twist_mux` ya está planteada:
- entrada navegación: `cmd_vel_nav`
- entrada teclado: `cmd_vel_key`
- salida: `/cmd_vel` (hacia `diablo_bridge`)

Falta asegurar que en launch real exista efectivamente el nodo de teleop (`teleop_twist_keyboard` o equivalente) publicando a `cmd_vel_key`.

### 4) Parametrización física y calibración de odometría

`diablo_bridge` tiene constantes fijas:
- `WHEEL_RADIUS = 0.10`
- `TRACK_WIDTH = 0.5805`

Para navegación robusta, moverlas a parámetros ROS y calibrarlas en robot real (trayectoria recta larga y giros de 360°) para reducir deriva.

### 5) Covarianzas y calidad de estado

`/odom` se publica sin covarianzas explícitas. Para que localizador/controlador trabajen estables, añadir covarianzas de pose/twist coherentes con el error real del encoder.

### 6) Cadena TF completa y consistente

Validar en runtime:
- `map -> odom` (SLAM/localización)
- `odom -> base_link` (diablo_bridge)
- `base_link -> lidar_link` (static tf/URDF)

Sin huecos, duplicidades ni múltiples publicadores para la misma arista.

### 7) Seguridad de mandos

Añadir en el bridge de velocidad:
- límites de saturación de `linear.x` y `angular.z`
- watchdog de paro: si no llega `/cmd_vel` en N ms, enviar 0

Esto evita movimientos no deseados ante caídas de red/procesos.

### 8) Flujo de operación recomendado

1. Arrancar `diablo_ctrl_node`
2. Arrancar `diablo_bridge`
3. Verificar `/scan`, `/odom`, TF, y que `/cmd_vel` mueve el robot
4. Arrancar `twist_mux` + teleop de teclado (`cmd_vel_key`) y generar mapa con SLAM
5. Guardar mapa
6. Cambiar SLAM/localización a modo localización
7. Activar navegación autónoma (`cmd_vel_nav`), con takeover manual por `cmd_vel_key`

## Confirmación sobre `diablo_bridge.cpp`

Tu lectura es correcta: `diablo_bridge.cpp` **sí** traduce telemetría de motores a odometría (`/odom` + `odom->base_link`) y además convierte `/cmd_vel` a `MotionCtrl` para `/diablo/MotionCmd`.

## Controles de teclado disponibles en el teleop propietario

En `diablo_teleop/teleop.py` (publica `diablo/MotionCmd`):

- Velocidad lineal: `w/s`
- Giro yaw (izq/der): `a/d`
- Roll cuerpo: `q/e` (y `r` reset)
- Altura (`up`): `h/j/k/l`
- Pitch cuerpo/cabeceo: `u/i/o`
- Modo control de altura: `v` (on), `b` (off)
- Modo control de pitch: `n` (on), `m` (off)
- Transformación de postura: `z` (stand up), `x` (stand down)
- Salto: `c`
- “Dance / split mode”: `f` (on), `g` (off)
- Salir: `` ` ``

Nota: este teleop manda `MotionCtrl` directo, no `Twist`. Para convivir con navegación autónoma, lo más limpio es usar teclado en `cmd_vel_key` y dejar `MotionCtrl` para funciones especiales (altura/postura/salto).
