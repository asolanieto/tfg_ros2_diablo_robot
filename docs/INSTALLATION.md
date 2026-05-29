# Guía de instalación

Esta guía cubre la puesta en marcha del sistema desde cero. El proceso no es
trivial: el framework de navegación EasyNav fue concebido para versiones de
ROS 2 más modernas (Iron/Jazzy) y arquitecturas x86, por lo que su uso bajo
**ROS 2 Humble** requiere varios parches y compilar algunas dependencias desde
el código fuente.

> **Sobre las dos ramas.** Los pasos comunes valen para ambas. Donde el proceso
> difiere (simulación frente a robot real) se indica explícitamente. Lee primero
> [`BRANCHES.md`](BRANCHES.md) si no tienes claro qué rama necesitas.

---

## 1. Requisitos previos

| Componente | Rama `main` (simulación) | Rama `hardware-integration` (robot real) |
|---|---|---|
| Sistema operativo | Ubuntu 22.04 LTS | Ubuntu Server 22.04 LTS (en la Raspberry Pi 4) |
| ROS 2 | Humble Hawksbill | Humble Hawksbill |
| Extra | Webots R2023b o superior | LiDAR Slamtec conectado por USB |

Herramientas necesarias en ambos casos:

```bash
sudo apt update
sudo apt install python3-vcstool python3-colcon-common-extensions python3-rosdep
```

---

## 2. Clonar el repositorio

```bash
git clone https://github.com/asolanieto/tfg_ros2_diablo_robot.git
cd tfg_ros2_diablo_robot

# Solo para el robot real:
git checkout hardware-integration
```

Tras clonar, `src/` contiene únicamente el código propio y los **forks
parcheados** (EasyNavigation, easynav_plugins, NavMap y, en hardware,
diablo_ros2). Las dependencias de terceros sin modificar todavía no están: se
descargan en el siguiente paso.

---

## 3. Descargar las dependencias de terceros

El archivo `dependencies.repos` lista los repositorios externos sin modificar.
`vcstool` los descarga todos dentro de `src/` con un único comando:

```bash
vcs import src < dependencies.repos
```

Esto trae Webots-ROS 2 (solo rama `main`), `vision_opencv`, `perception_pcl`,
`yaets` y —en la rama de hardware— el driver `rplidar_ros`.

> **Por qué `vision_opencv` y `perception_pcl` se compilan desde fuente.** Los
> binarios precompilados de `cv_bridge` y `pcl_conversions` para Humble suelen
> estar incompletos: el gestor de paquetes informa de que están instalados, pero
> sus archivos de cabecera no existen físicamente en el sistema («instalación
> fantasma»). Compilarlos dentro del workspace es la vía fiable.

---

## 4. Dependencias del sistema

### 4.1. Resolución automática

```bash
rosdep update
rosdep install --from-paths src --ignore-src -r -y
```

### 4.2. Parche de la biblioteca geográfica

`rosdep` no resuelve correctamente una biblioteca de cálculo geográfico: el
compilador busca `libGeographicLib.so` mientras que el sistema la instala como
`libGeographic.so`, lo que provoca un error de enlazado (`cannot find
-lGeographicLib`). Se corrige instalando la biblioteca y creando un enlace
simbólico:

```bash
sudo apt install libgeographic-dev ros-humble-pcl-msgs

# Ajusta la ruta de arquitectura:
#   - x86_64-linux-gnu      en PC
#   - aarch64-linux-gnu     en la Raspberry Pi
sudo ln -s /usr/lib/x86_64-linux-gnu/libGeographic.so \
           /usr/lib/x86_64-linux-gnu/libGeographicLib.so
```

---

## 5. Estado de los parches

Los forks de `src/` ya vienen parcheados en este repositorio, así que **no hay
que aplicar los parches a mano**. Solo necesitas saber que existen; el detalle
de qué se modificó está en [`THIRD_PARTY.md`](THIRD_PARTY.md). En resumen:

- **EasyNavigation**: sustitución de funciones de API inexistentes en Humble y
  ajustes en los `CMakeLists.txt` para localizar las cabeceras de las
  dependencias compiladas dentro del workspace.
- **NavMap**: ajustes equivalentes en `navmap_ros/CMakeLists.txt`.
- **easynav_plugins**: se descartan plugins experimentales que dependen de
  bibliotecas no disponibles y bloqueaban la compilación.

---

## 6. Compilar el workspace

```bash
source /opt/ros/humble/setup.bash
cd ~/tfg_ros2_diablo_robot
```

**En PC (rama `main`):**

```bash
colcon build --symlink-install
```

**En la Raspberry Pi (rama `hardware-integration`):** la compilación estándar
satura la memoria de la Pi. Hay que compilar de forma secuencial y limitar la
paralelización:

```bash
colcon build --symlink-install \
  --executor sequential \
  --parallel-workers 1 \
  --cmake-args -DCMAKE_BUILD_PARALLEL_LEVEL=1
```

> **Memoria de intercambio en la Raspberry Pi.** Si la compilación sigue
> agotando la RAM y mata la sesión, conviene habilitar un archivo de
> intercambio (swap) en la tarjeta microSD antes de compilar. Consulta la
> documentación oficial de Raspberry Pi / Ubuntu para hacerlo de forma segura.

---

## 7. Configuración específica del robot real

Estos pasos solo aplican a la rama `hardware-integration`.

### 7.1. Reglas udev del LiDAR

El paquete del fabricante incluye un script que crea un enlace simbólico estable
para el puerto del LiDAR a partir de su identificador USB:

```bash
cd src/rplidar_ros
source scripts/create_udev_rules.sh
```

### 7.2. Red para visualización remota

Para visualizar los datos del robot en RViz desde otro equipo, ambos extremos
deben compartir el mismo espacio de tópicos de ROS 2. El repositorio incluye
`cyclonedds_pc.xml` con la configuración de descubrimiento DDS. Para usarlo,
exporta la variable de entorno antes de cargar el workspace, en ambas máquinas:

```bash
export CYCLONEDDS_URI=file:///ruta/al/repo/cyclonedds_pc.xml
```

Asegúrate también de fijar el **mismo `ROS_DOMAIN_ID`** en los dos equipos.

---

## 8. Lanzar el sistema

```bash
source install/setup.bash
ros2 launch diablo_test robot_launch.py
```

Esto arranca la cadena completa: capa de planta, SLAM, EasyNav y twist_mux. En
la rama de hardware, el archivo de lanzamiento incluye además el driver del
LiDAR.

---

## 9. Uso

### Teleoperación manual

```bash
ros2 run teleop_twist_keyboard teleop_twist_keyboard \
  --ros-args -r /cmd_vel:=/cmd_vel_key
```

El `twist_mux` da prioridad al control manual sobre el autónomo.

### Enviar un objetivo de navegación

```bash
ros2 action send_goal /navigate_to_pose easynav_interfaces/action/NavigateToPose \
  "{pose: {header: {frame_id: 'map'}, pose: {position: {x: 1.0, y: 0.5, z: 0.0}}}}"
```

### Visualización y depuración

RViz se lanza de forma independiente. En la rama `main`, el script
`debug_monitor.py` publica el error de seguimiento hacia el objetivo para
inspeccionarlo en PlotJuggler.

---

## 10. Problemas conocidos

| Síntoma | Causa probable | Solución |
|---|---|---|
| `cannot find -lGeographicLib` | Falta el enlace simbólico | Paso 4.2 |
| `undefined reference` a `cv_bridge` / `pcl_conversions` | Binarios precompilados incompletos | Compilar desde fuente (paso 3) |
| La compilación mata la sesión SSH en la Pi | RAM agotada | Compilación secuencial (paso 6) + swap |
| El sistema muere al cargar EasyNav (`can't compare times`) | Mezcla de fuentes de reloj | `use_sim_time: false` en todos los nodos (ver `ARCHITECTURE.md`) |
| `/scan` o las TF no aparecen en otro equipo | Configuración DDS no cargada en esa terminal | Exportar `CYCLONEDDS_URI` antes de hacer `source` (paso 7.2) |
