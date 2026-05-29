# Arquitectura del sistema

Este documento describe cómo está organizado el sistema de navegación, cómo
fluyen los datos entre sus componentes y las decisiones de diseño no obvias.

Salvo que se indique lo contrario, lo descrito aquí aplica a la rama `main`
(simulación). Las diferencias de la rama `hardware-integration` se señalan de
forma explícita en cada apartado.

---

## Visión de conjunto

El sistema no es un programa monolítico, sino un conjunto de nodos ROS 2 que
cooperan pasándose mensajes por tópicos. Un criterio de diseño central ha sido
**aislar el resto del sistema respecto a la planta concreta**: la capa de
navegación es la misma tanto si debajo hay un robot simulado como uno real, lo
que permite validar en simulación y trasladar a hardware con cambios acotados.

```
        ┌─────────────────────┐
        │  Simulador Webots   │   (rama main)
        └──────────┬──────────┘
                   │
                   ▼
        ┌─────────────────────┐
        │   diablo_driver     │   Nodo C++ propio
        │  (Webots ↔ ROS 2)   │
        └──────────┬──────────┘
                   │  /scan, /odom, /joint_states_webots
                   │  TF publicada en /tf_garbage (ver "Puente de tiempo")
                   ▼
        ┌─────────────────────┐
        │   Bridges (Python)  │   Re-sellan las marcas de tiempo
        │  scan / odom / joint│
        └──────────┬──────────┘
                   │  /scan_bridged, /tf, /joint_states
                   ▼
        ┌─────────────────────┐
        │    SLAM Toolbox     │   Construye el mapa, publica TF map → odom
        └──────────┬──────────┘
                   │
                   ▼
        ┌─────────────────────┐
        │  EasyNav (system)   │   Planner + Controller + MapsManager + Localizer
        └──────────┬──────────┘
                   │  /cmd_vel_nav
                   ▼
        ┌─────────────────────┐
        │     twist_mux       │   Conmuta entre navegación y teleoperación
        └──────────┬──────────┘
                   │  /cmd_vel
                   ▼
            (de vuelta al driver)
```

En la rama `hardware-integration` la caja "Simulador Webots + diablo_driver" se
sustituye por **la controladora física + el driver del fabricante
(`diablo_ros2`) + un nodo puente propio (`diablo_bridge`)**. El resto de la
cadena (SLAM, EasyNav, twist_mux) es conceptualmente la misma.

---

## Subsistemas

### 1. Capa de planta

Representa al robot: ejecuta los comandos de movimiento y publica la información
de sensores y odometría.

- **En simulación (`main`):** un modelo virtual en Webots gobernado por
  `diablo_driver`, un nodo C++ desarrollado para este proyecto.
- **En el robot real (`hardware-integration`):** la controladora física, a la
  que se accede mediante el driver del fabricante. El nodo `diablo_bridge`
  traduce entre los mensajes propietarios del fabricante (`motion_msgs`,
  `ception_msgs`) y los mensajes estándar de ROS 2.

### 2. Percepción y mapeado

Un LiDAR 2D alimenta a **SLAM Toolbox** (`async_slam_toolbox_node`), que
construye el mapa de ocupación y publica la transformada `map → odom`.

### 3. Navegación — EasyNav

El framework EasyNav coordina cuatro componentes mediante plugins:

| Componente | Plugin usado | Función |
|---|---|---|
| Planner | `CostmapPlanner` | Planificación de ruta (A* sobre costmap 2D) |
| Controller | `MPCController` | Cálculo de velocidades (horizonte de 5 pasos) |
| Maps Manager | `CostmapMapsManager` | Costmap con filtros de obstáculos e inflado |
| Localizer | `AMCLLocalizer` | Localización del robot en el mapa |

### 4. Mando — twist_mux

`twist_mux` recibe dos fuentes de velocidad y deja pasar la de mayor prioridad:

- `/cmd_vel_key` — teleoperación manual (prioridad alta).
- `/cmd_vel_nav` — navegación autónoma de EasyNav (prioridad baja).

Su salida se remapea a `/cmd_vel`, que consume la capa de planta.

---

## Decisiones de diseño no obvias

### Puente de tiempo: por qué `use_sim_time: false` en todos los nodos

El reloj de Webots no avanza a la misma velocidad que el reloj de pared. Si SLAM
Toolbox y EasyNav comparan marcas de tiempo de relojes distintos, rechazan los
mensajes por considerarlos "caducados" (su tolerancia es de unas décimas de
segundo a pocos segundos).

La solución adoptada tiene tres piezas:

1. Todos los nodos se configuran con `use_sim_time: false`.
2. El driver publica sus transformadas en un tópico "basura" (`/tf_garbage`,
   remapeado en el archivo de lanzamiento) para que no contaminen el árbol TF
   con marcas caducadas.
3. Los *bridges* en Python vuelven a publicar copias frescas de scan, odometría
   y estados de articulación, re-sellando la marca de tiempo con el reloj del
   sistema en el momento de la publicación.

> En la rama `hardware-integration` el problema no se da igual porque no hay
> reloj de simulación; los *bridges* de re-sellado de simulación no son
> necesarios y el sistema trabaja directamente en tiempo real.

### Arranque escalonado

SLAM Toolbox y EasyNav son pesados. Para evitar un pico de CPU al arrancar
—especialmente crítico en la Raspberry Pi— el archivo de lanzamiento introduce
un retardo (`TimerAction`) antes de lanzarlos, de modo que el resto del sistema
ya esté estable cuando entran en juego.

### Odometría diferencial

Se calcula a partir de los encoders de las ruedas izquierda y derecha. Las
constantes están en el driver:

- `WHEEL_RADIUS = 0.10 m`
- `TRACK_WIDTH = 0.5805 m` — ajustado empíricamente contra el modelo, no es el
  valor del datasheet.

### Transformada estática `base_link → lidar_link`

El LiDAR está montado 0.15 m por encima de `base_link` y girado 180° alrededor
del eje Z, para alinear la dirección del escaneo con el frente del robot. Se
declara como publicador estático en el archivo de lanzamiento.

### Autoequilibrado

El robot Diablo real gestiona su equilibrio internamente, a nivel de firmware.
En Webots no existe ese controlador interno, así que las articulaciones de las
patas se bloquean en posición cero dentro del driver de simulación.

---

## Parámetros de ajuste

Todos los parámetros de navegación están en `src/diablo_test/config/`.

### Costmap (`easynav_params.yaml`)

| Parámetro | Valor de referencia | Efecto |
|---|---|---|
| `robot_radius` | 0.5 m | Huella del robot para planificación |
| `inflation_radius` | 0.7 m | Subir si el robot roza paredes |
| `inscribed_radius` | 0.35 m | Radio inscrito de la huella |
| `cost_scaling_factor` | 8.0 | Mayor = obstáculos más "finos"; menor = burbuja de seguridad más ancha |

### Controlador MPC (`easynav_params.yaml`)

| Parámetro | Valor de referencia | Efecto |
|---|---|---|
| `horizon_steps` / `dt` | 5 / 0.1 s | Ventana de predicción de 0.5 s |
| `max_linear_velocity` | 0.5 m/s | Límite duro de velocidad lineal |
| `max_angular_velocity` | 1.0 rad/s | Límite duro de velocidad angular |
| `fallback_goal_pos_tol` | 0.20 m | Tolerancia de posición del controlador de respaldo |
| `fallback_goal_yaw_tol` | 0.50 rad | Tolerancia de orientación del controlador de respaldo |

> Los valores concretos pueden diferir entre las dos ramas: la rama de hardware
> tiene su propio ajuste, calibrado contra el comportamiento del robot real.

---

## Archivos clave

| Archivo | Propósito |
|---|---|
| `src/diablo_test/src/diablo_driver.cpp` | Interfaz Webots ↔ ROS 2 (rama `main`) |
| `src/diablo_test/src/diablo_bridge.cpp` | Puente fabricante ↔ ROS 2 (rama `hardware-integration`) |
| `src/diablo_test/src/bridges/*.py` | Re-sellado de marcas de tiempo (rama `main`) |
| `src/diablo_test/launch/robot_launch.py` | Orquestación de todo el sistema |
| `src/diablo_test/config/easynav_params.yaml` | Parámetros de navegación |
| `src/diablo_test/config/slam_localization.yaml` | Configuración de SLAM Toolbox |
| `src/diablo_test/config/mux_params.yaml` | Prioridades del twist_mux |
| `cyclonedds_pc.xml` | Descubrimiento DDS para visualización remota |
| `debug_monitor.py` | Monitor de error de seguimiento para PlotJuggler |
