# Componentes de terceros y parches aplicados

Este repositorio contiene código de terceros tratado de dos formas distintas
según haya sido modificado o no. Este documento explica qué es cada cosa y, para
los componentes parcheados, qué se cambió y por qué.

---

## Dos categorías

### A. Forks parcheados — viven dentro de este repositorio

Son copias de proyectos de terceros a las que se han aplicado **parches
imprescindibles**. Sin esos parches el sistema no compila o no funciona. Se
versionan dentro del repositorio a propósito: son, en la práctica, *forks* del
proyecto.

| Carpeta | Proyecto de origen | Presente en |
|---|---|---|
| `src/EasyNavigation/` | [EasyNavigation/EasyNavigation](https://github.com/EasyNavigation) | ambas ramas |
| `src/easynav_plugins/` | EasyNavigation (plugins) | ambas ramas |
| `src/NavMap/` | [EasyNavigation/NavMap](https://github.com/EasyNavigation/NavMap) | ambas ramas |
| `src/diablo_ros2/` | Driver oficial del fabricante del robot Diablo | solo `hardware-integration` |

### B. Dependencias sin modificar — fuera del repositorio

Son copias limpias, sin un solo cambio. No tiene sentido versionarlas aquí: se
descargan con `vcstool` a partir de `dependencies.repos` (ver
[`INSTALLATION.md`](INSTALLATION.md)).

| Dependencia | Origen | Rama |
|---|---|---|
| `webots_ros2` | cyberbotics/webots_ros2 | solo `main` |
| `vision_opencv` | ros-perception/vision_opencv | ambas |
| `perception_pcl` | ros-perception/perception_pcl | ambas |
| `yaets` | fmrico/yaets | ambas |
| `rplidar_ros` | Slamtec/rplidar_ros (rama `ros2`) | solo `hardware-integration` |

> `vision_opencv` y `perception_pcl` se compilan desde fuente —en lugar de
> usar los binarios de apt— porque los precompilados de `cv_bridge` y
> `pcl_conversions` para Humble suelen estar incompletos. Aun así **no están
> parcheados**, por eso pertenecen a esta categoría.

---

## Parches aplicados a EasyNavigation

EasyNav está diseñado para ROS 2 Iron/Jazzy y arquitectura x86. Para que
funcione bajo Humble se aplicaron tres familias de cambios.

### 1. Compatibilidad de API

La función `get_fully_qualified_name()`, usada en numerosos paquetes, no existe
en Humble. Se sustituyó por su equivalente `get_name()` mediante un reemplazo
masivo sobre todo el workspace:

```bash
grep -rl "get_fully_qualified_name" src/ | \
  xargs sed -i 's/get_fully_qualified_name/get_name/g'
```

En `easynav_system/src/system_main.cpp`, el constructor de
`tf2_ros::TransformListener` en Humble espera el nodo directamente, no una
referencia desreferenciada:

```cpp
// Incorrecto en Humble:
new tf2_ros::TransformListener(buffer, *node);
// Correcto:
new tf2_ros::TransformListener(buffer, node);
```

### 2. Configuración de compilación (CMakeLists)

Los `CMakeLists.txt` originales asumen rutas estándar del sistema que dejan de
ser válidas al compilar dependencias dentro del propio workspace. Se editaron
para indicar de forma explícita dónde están las cabeceras y las bibliotecas, y
para declarar dependencias que faltaban. El caso principal:
`easynav_common/CMakeLists.txt`, ajustado para localizar las cabeceras de
`cv_bridge`.

### 3. Tratamiento de los tiempos

Tras compilar, el sistema fallaba al arrancar con una excepción de comparación
de tiempos entre fuentes de reloj distintas. Se modificó el tratamiento de las
marcas de tiempo en varios nodos de EasyNav. El razonamiento completo está en
[`ARCHITECTURE.md`](ARCHITECTURE.md), apartado «Puente de tiempo».

---

## Parches aplicados a NavMap

`navmap_ros/CMakeLists.txt` presentaba los mismos problemas de rutas que
EasyNav. Se editó para:

- Declarar dependencias que faltaban (`message_filters`, `pcl_msgs`).
- Apuntar los *includes* al código fuente de las dependencias compiladas en el
  workspace, en lugar de a rutas de instalación inexistentes.
- Eliminar el enlace contra `pcl_conversions` como biblioteca compilada, ya que
  en esta configuración es *header-only*.

---

## Parches aplicados a easynav_plugins

El repositorio de plugins de EasyNav incluye complementos experimentales (por
ejemplo, los basados en `bonxai`) que dependen de bibliotecas externas no
disponibles en el sistema y que bloqueaban la compilación del conjunto. Se
descartaron, conservando únicamente los plugins efectivamente usados por el
sistema de navegación.

---

## Parches aplicados a diablo_ros2

> Solo en la rama `hardware-integration`.

El driver oficial del fabricante del robot Diablo recibió ajustes para
funcionar de forma estable en este proyecto. Entre ellos: la corrección del pin
del puerto serie en el nodo de control y la conversión de varios publicadores de
*lazy publishers* a publicadores activos, para evitar que el nodo dejara de
publicar telemetría cuando arrancaba sin suscriptores.

---

## Cómo mantener esto al día

Si en el futuro alguien aplica un parche nuevo a cualquiera de los forks de la
categoría A, **debe añadir aquí una entrada describiéndolo**. La utilidad de
estos forks depende por completo de que quede registrado qué se cambió respecto
al proyecto original.
