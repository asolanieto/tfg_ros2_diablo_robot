# Navegación Autónoma del Robot Diablo — Simulación en ROS 2 + Webots

Trabajo de Fin de Grado de **Adrián Sola Nieto** — Universidad de Málaga, laboratorio **Space UMA**.

Sistema de navegación autónoma para el robot **Diablo** (plataforma híbrida rueda-pata
autoequilibrada de DDT/Direct Drive Tech), construido sobre **ROS 2 Humble**. Esta rama
contiene la versión de **simulación en Webots**: un *driver* en C++ que interconecta el
modelo simulado del robot con ROS 2, generación de mapas con SLAM y navegación autónoma
mediante el framework **EasyNav**.

---

## ⚠️ Este repositorio tiene dos ramas, y no son intercambiables

| Rama | Escenario | Plataforma |
|------|-----------|------------|
| **`main`** *(estás aquí)* | Simulación | Webots, sobre un PC |
| **`hardware-integration`** | Robot real | Raspberry Pi 4 a bordo del Diablo |

Son **ramas divergentes a propósito**. Aunque comparten el mismo sistema de navegación,
el escenario simulado y el real son técnicamente muy distintos (capa de planta, fuente de
odometría, recursos de cómputo). La rama de hardware se mantiene deliberadamente *ligera*:
no incluye Webots ni su *driver*, para no sobrecargar la Raspberry Pi. No intentes fusionar
las ramas; consulta la que corresponda a tu objetivo.

---

## Estructura del repositorio

El workspace de ROS 2 vive bajo `src/`. **No todo el código de `src/` es del autor.**
Conviene distinguir tres categorías:

```
src/
├── diablo_test/          ← CÓDIGO PROPIO. El paquete del TFG.
│
├── EasyNavigation/       ← TERCEROS, PARCHEADO. Framework de navegación EasyNav,
├── easynav_plugins/         adaptado a ROS 2 Humble. Funciona como un "fork":
├── NavMap/                  contiene parches imprescindibles (ver docs/INSTALLATION.md).
│                            NO sustituir por la versión oficial de upstream.
│
└── (dependencias limpias)  ← TERCEROS, SIN MODIFICAR. No se versionan en este repo;
                              se descargan aparte. Ver "Instalación".
```

- **`src/diablo_test/`** — Paquete propio. Es el núcleo del TFG: el *driver* C++ del robot
  en Webots, los *bridges* de re-sellado temporal, el archivo de *launch* y toda la
  configuración de navegación.
- **`src/EasyNavigation/`, `src/easynav_plugins/`, `src/NavMap/`** — Copias parcheadas de
  frameworks de terceros. Se incluyen en el repositorio **a propósito**, porque contienen
  modificaciones necesarias para compilar y funcionar en ROS 2 Humble que no están en las
  versiones oficiales. Trátalas como un fork interno.
- **Dependencias sin modificar** (`vision_opencv`, `perception_pcl`, `yaets`) — Clones
  íntegros de repositorios públicos. **No se incluyen en este repo**; se obtienen con
  `vcstool` durante la instalación (ver abajo).

> Los parches aplicados a las carpetas de terceros están descritos en
> [`docs/INSTALLATION.md`](docs/INSTALLATION.md) y en la memoria del TFG (Sección 2.5 y Anexo 2).

---

## Requisitos

- **SO:** Ubuntu 22.04 LTS (Jammy Jellyfish)
- **ROS 2:** Humble Hawksbill
- **Simulador:** Webots R2023b o superior
- Herramientas: `colcon`, `rosdep`, `vcstool`

---

## Instalación rápida

```bash
# 1. Clonar el repositorio
git clone https://github.com/asolanieto/tfg_ros2_diablo_robot.git
cd tfg_ros2_diablo_robot

# 2. Descargar las dependencias de terceros sin modificar
vcs import src < dependencies.repos

# 3. Resolver dependencias del sistema, compilar y ejecutar
#    (hay pasos manuales: ver la guía completa)
```

La instalación completa **no es trivial** (problemas conocidos de `rosdep`, rutas de
bibliotecas, sincronización de relojes). Sigue la guía detallada:

➡️ **[`docs/INSTALLATION.md`](docs/INSTALLATION.md)**

---

## Ejecución

```bash
source /opt/ros/humble/setup.bash
source install/setup.bash

# Lanzar la pila completa de simulación (Webots + driver + SLAM + EasyNav + twist_mux)
ros2 launch diablo_test robot_launch.py
```

Teleoperación manual (tiene prioridad sobre la navegación autónoma vía `twist_mux`):

```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/cmd_vel_key
```

Enviar un objetivo de navegación:

```bash
ros2 action send_goal /navigate_to_pose easynav_interfaces/action/NavigateToPose \
  "{pose: {header: {frame_id: 'map'}, pose: {position: {x: 1.0, y: 0.5, z: 0.0}}}}"
```

---

## Documentación

| Documento | Contenido |
|-----------|-----------|
| [`docs/INSTALLATION.md`](docs/INSTALLATION.md) | Instalación paso a paso, parches y problemas conocidos |
| [`ARCHITECTURE.md`](ARCHITECTURE.md) | Arquitectura del sistema, flujo de datos y decisiones de diseño |
| [`docs/REVISION.md`](docs/REVISION.md) | Estado de limpieza del repositorio y tareas pendientes |

---

## Autor y contexto

Adrián Sola Nieto — Trabajo de Fin de Grado, Universidad de Málaga.
Robot integrado en el laboratorio **Space UMA** como plataforma de investigación.

## Licencia

Pendiente de definir. Las carpetas de terceros conservan sus licencias originales
(consultar el archivo `LICENSE` dentro de cada una).
