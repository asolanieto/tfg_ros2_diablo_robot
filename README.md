# Navegación autónoma del robot Diablo en ROS 2 — Plataforma real

Trabajo de Fin de Grado · Universidad de Málaga · Laboratorio Space UMA

Este repositorio contiene el sistema de navegación autónoma desarrollado para el
robot **Diablo** (plataforma híbrida rueda-pata autoequilibrada) sobre **ROS 2 Humble**.

> **Esta es la rama `hardware-integration`: el sistema desplegado sobre el robot
> físico**, ejecutándose en la Raspberry Pi 4 a bordo del Diablo.
> La versión en simulador Webots vive en la rama [`main`](../../tree/main).
>
> Las dos ramas son **divergentes a propósito**. La Raspberry Pi 4 tiene recursos
> muy limitados, así que esta rama prescinde por completo de Webots, del modelo de
> simulación y de todo lo que no sea estrictamente necesario para que el sistema
> funcione sobre el robot real. Consulta [`docs/BRANCHES.md`](docs/BRANCHES.md) para
> entender la relación entre ambas.

---

## Qué hace este proyecto

Un robot móvil real que navega de forma autónoma evitando obstáculos. La cadena
completa, de abajo arriba:

1. **Planta** — la controladora física del robot Diablo, accesible a través del
   driver del fabricante (`diablo_ros2`, también parcheado en este repositorio).
2. **Puente** — un nodo C++ propio (`diablo_bridge`) traduce entre la interfaz
   propietaria del fabricante y el ecosistema estándar de ROS 2 (`/cmd_vel`,
   `/odom`, TF).
3. **Percepción y mapeado** — un LiDAR Slamtec alimenta a SLAM Toolbox.
4. **Navegación** — el framework [EasyNav](https://github.com/EasyNavigation)
   planifica la ruta y calcula los comandos de velocidad.
5. **Mando** — un `twist_mux` permite alternar entre navegación autónoma y
   teleoperación manual.

Para entender cómo encajan las piezas, lee [`docs/ARCHITECTURE.md`](docs/ARCHITECTURE.md).

---

## Estructura del repositorio

```
.
├── src/
│   ├── diablo_test/        ← Paquete PROPIO: puente (bridge), launch, configuración
│   ├── auxiliar_pkg/       ← Paquete PROPIO: monitor de batería y utilidades
│   ├── diablo_ros2/        ← Fork parcheado del driver oficial del fabricante
│   ├── EasyNavigation/     ← Fork parcheado de EasyNav
│   ├── easynav_plugins/    ← Fork parcheado de los plugins de EasyNav
│   └── NavMap/             ← Fork parcheado de NavMap
├── docs/                   ← Documentación del proyecto
├── dependencies.repos      ← Dependencias de terceros SIN modificar (se descargan aparte)
└── cyclonedds_pc.xml       ← Configuración DDS para visualización remota
```

### Una nota importante sobre `src/`

No todo lo que hay en `src/` se trata igual:

- **`diablo_test/` y `auxiliar_pkg/`** son código original de este TFG.
- **`diablo_ros2/`, `EasyNavigation/`, `easynav_plugins/`, `NavMap/`** son
  *forks*: copias de proyectos de terceros con parches imprescindibles. Se
  versionan dentro del repositorio a propósito. Lo modificado está documentado en
  [`docs/THIRD_PARTY.md`](docs/THIRD_PARTY.md).
- El resto de dependencias, incluido el driver del LiDAR (`rplidar_ros`), **no
  están en el repositorio**: son copias sin modificar y se descargan con un solo
  comando durante la instalación.

---

## Instalación y puesta en marcha

La instalación sobre la Raspberry Pi tiene pasos delicados (memoria de
intercambio, compilación de dependencias desde fuente, reglas udev del LiDAR,
configuración de red...). Está todo explicado en:

**→ [`docs/INSTALLATION.md`](docs/INSTALLATION.md)**

Resumen rápido para quien ya tenga el entorno listo:

```bash
# 1. Clonar el repositorio
git clone https://github.com/asolanieto/tfg_ros2_diablo_robot.git
cd tfg_ros2_diablo_robot
git checkout hardware-integration

# 2. Descargar las dependencias de terceros sin modificar (incluye rplidar_ros)
vcs import src < dependencies.repos

# 3. Compilar (en la Pi, conviene limitar la carga de CPU)
source /opt/ros/humble/setup.bash
colcon build --symlink-install --parallel-workers 1

# 4. Lanzar el sistema completo en el robot
source install/setup.bash
ros2 launch diablo_test robot_launch.py
```

---

## Requisitos

| Componente | Versión |
|---|---|
| Sistema operativo | Ubuntu Server 22.04 LTS (Jammy) |
| ROS 2 | Humble Hawksbill |
| Hardware | Robot Diablo + Raspberry Pi 4 + LiDAR Slamtec |

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

Los forks conservan la licencia original de sus proyectos de origen.
