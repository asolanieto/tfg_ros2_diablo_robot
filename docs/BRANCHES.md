# Estrategia de ramas

Este repositorio tiene dos ramas principales, y **es importante entender que
están divergidas a propósito**: no se trata de una rama "buena" y otra
"desactualizada".

## Las dos ramas

| Rama | Escenario | Plataforma de ejecución |
|---|---|---|
| `main` | Simulación | PC de escritorio con Webots |
| `hardware-integration` | Robot físico | Raspberry Pi 4 a bordo del Diablo |

## Por qué están separadas

El sistema de navegación (SLAM + EasyNav + twist_mux) es conceptualmente el
mismo en ambos casos, pero la **capa de planta** —la parte que habla con el
robot— es radicalmente distinta:

- En `main`, el robot es un modelo virtual de Webots gobernado por un driver C++
  propio. El repositorio necesita el simulador, el modelo `.wbt`, las mallas 3D
  y la librería de control de Webots.
- En `hardware-integration`, el robot es la controladora física, a la que se
  accede mediante el driver del fabricante y un nodo puente propio. Aquí no hay
  ni simulador ni modelo.

La razón de fondo para mantenerlas separadas en lugar de unificarlas es de
**recursos**: la rama de hardware se ejecuta en una Raspberry Pi 4, una
plataforma muy limitada en CPU y memoria. Hacer que esa Pi cargue con todo el
peso de Webots, las mallas de simulación y dependencias que nunca va a usar
sería contraproducente. La rama `hardware-integration` se mantiene deliberadamente
ligera, con solo lo mínimo necesario para que el sistema funcione sobre el robot.

## Diferencias principales

Lo que cambia de una rama a otra, además de la documentación:

- **Capa de planta**: `diablo_driver` (Webots) frente a `diablo_bridge` +
  driver del fabricante `diablo_ros2`.
- **Bridges de tiempo**: la rama `main` incluye *bridges* en Python que
  re-sellan las marcas de tiempo para reconciliar el reloj de Webots con el
  tiempo real. La rama de hardware no los necesita.
- **LiDAR**: la rama de hardware integra el driver real del LiDAR Slamtec
  (`rplidar_ros`); la de simulación usa el LiDAR virtual de Webots.
- **Paquetes exclusivos de hardware**: `auxiliar_pkg` (monitor de batería) y el
  fork `diablo_ros2` del driver del fabricante solo existen en
  `hardware-integration`.
- **Ajuste de parámetros**: los `.yaml` de configuración están calibrados de
  forma independiente para cada escenario.

## Trabajar con las ramas

Si un cambio afecta a la **lógica común de navegación** (un ajuste en EasyNav, un
arreglo en un plugin), conviene aplicarlo en una rama y portarlo a la otra con
`git cherry-pick` para evitar que diverjan más de lo necesario.

Si un cambio afecta solo a la **capa de planta** (driver, puente, modelo), vive
únicamente en su rama y no debe portarse.
