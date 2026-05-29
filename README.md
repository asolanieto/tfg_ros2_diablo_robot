# Navegación autónoma del robot Diablo en ROS 2 — Simulación (Webots)

Trabajo de Fin de Grado · Universidad de Málaga · Laboratorio Space UMA

Este repositorio contiene el sistema de navegación autónoma desarrollado para el
robot **Diablo** (plataforma híbrida rueda-pata autoequilibrada) sobre **ROS 2 Humble**.

> **Esta es la rama `main`: el sistema funcionando en el simulador Webots.**
> El sistema desplegado sobre el robot físico vive en la rama
> [`hardware-integration`](../../tree/hardware-integration). Las dos ramas son
> **divergentes a propósito**: la plataforma real (una Raspberry Pi 4) no puede
> cargar con el peso de Webots ni del modelo de simulación, así que la rama de
> hardware contiene únicamente lo mínimo necesario para que el sistema funcione.
> Consulta [`docs/BRANCHES.md`](docs/BRANCHES.md) para entender la relación entre ambas.

---

## Qué hace este proyecto

Un robot móvil que navega de forma autónoma de un punto a otro evitando obstáculos.
La cadena completa, de abajo arriba:

1. **Planta** — el robot Diablo simulado en Webots, gobernado por un driver C++
   propio (`diablo_driver`).
2. **Percepción y mapeado** — un LiDAR 2D alimenta a SLAM Toolbox, que construye
   el mapa y publica la transformada `map → odom`.
3. **Navegación** — el framework [EasyNav](https://github.com/EasyNavigation)
   planifica la ruta y calcula los comandos de velocidad.
4. **Mando** — un `twist_mux` permite alternar entre control autónomo y
   teleoperación manual por teclado.

Para entender cómo encajan las piezas, los temas de sincronización de tiempo y
las decisiones de diseño, lee [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md).

---

## Estructura del repositorio

```
.
├── src/
│   ├── diablo_test/        ← Paquete PROPIO: driver, launch, configuración, mundo Webots
│   ├── EasyNavigation/     ← Fork parcheado de EasyNav (NO clonar de upstream — ver más abajo)
│   ├── easynav_plugins/    ← Fork parcheado de los plugins de EasyNav
│   └── NavMap/             ← Fork parcheado de NavMap
├── docs/                   ← Documentación del proyecto
├── dependencies.repos      ← Dependencias de terceros SIN modificar (se descargan aparte)
└── cyclonedds_pc.xml       ← Configuración DDS para visualización remota
```

### Una nota importante sobre `src/`

No todo lo que hay en `src/` se trata igual:

- **`diablo_test/`** es el código original de este TFG.
- **`EasyNavigation/`, `easynav_plugins/`, `NavMap/`** son *forks*: copias de
  proyectos de terceros a las que se han aplicado parches imprescindibles para
  que compilen y funcionen bajo ROS 2 Humble. **Se versionan dentro de este
  repositorio a propósito**, porque sin esos parches el sistema no arranca.
  Lo que se modificó está documentado en [`docs/THIRD_PARTY.md`](docs/THIRD_PARTY.md).
- El resto de dependencias (Webots-ROS 2, PCL, OpenCV...) **no están en el
  repositorio**: son copias sin modificar y se descargan con un solo comando
  durante la instalación (ver abajo).

---

## Instalación y puesta en marcha

La instalación tiene varios pasos no triviales (compilar dependencias desde
fuente, parches de CMake, etc.). Está todo explicado paso a paso en:

**→ [`docs/INSTALLATION.md`](docs/INSTALLATION.md)**

Resumen rápido para quien ya tenga el entorno listo:

```bash
# 1. Clonar el repositorio
git clone https://github.com/asolanieto/tfg_ros2_diablo_robot.git
cd tfg_ros2_diablo_robot

# 2. Descargar las dependencias de terceros sin modificar
vcs import src < dependencies.repos

# 3. Compilar
source /opt/ros/humble/setup.bash
colcon build --symlink-install

# 4. Lanzar la simulación completa
source install/setup.bash
ros2 launch diablo_test robot_launch.py
```

---

## Requisitos

| Componente | Versión |
|---|---|
| Sistema operativo | Ubuntu 22.04 LTS (Jammy) |
| ROS 2 | Humble Hawksbill |
| Simulador | Webots R2023b o superior |
| Herramientas | `vcstool`, `colcon` |

---

## Uso

```bash
# Teleoperación manual (prioridad alta en el twist_mux)
ros2 run teleop_twist_keyboard teleop_twist_keyboard \
  --ros-args -r /cmd_vel:=/cmd_vel_key

# Enviar un objetivo de navegación
ros2 action send_goal /navigate_to_pose easynav_interfaces/action/NavigateToPose \
  "{pose: {header: {frame_id: 'map'}, pose: {position: {x: 1.0, y: 0.5, z: 0.0}}}}"

# Monitorizar el error de seguimiento (para PlotJuggler)
python3 debug_monitor.py
```

---

## Documentación

| Documento | Contenido |
|---|---|
| [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md) | Arquitectura del sistema, flujo de datos y decisiones de diseño |
| [`docs/INSTALLATION.md`](docs/INSTALLATION.md) | Guía de instalación completa paso a paso |
| [`docs/BRANCHES.md`](docs/BRANCHES.md) | Por qué hay dos ramas y qué contiene cada una |
| [`docs/THIRD_PARTY.md`](docs/THIRD_PARTY.md) | Forks parcheados: qué se modificó y por qué |

---

## Autoría y licencia

Desarrollado por **Adrián Sola Nieto** como Trabajo de Fin de Grado.

Los forks de `src/EasyNavigation/`, `src/easynav_plugins/`
y `src/NavMap/` conservan la licencia original de sus proyectos de origen.
