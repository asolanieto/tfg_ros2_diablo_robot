# Control y Simulación del Robot Diablo en ROS 2 y Webots

Este repositorio contiene el paquete de desarrollo para el Trabajo de Fin de Grado (TFG) centrado en la simulación, control y odometría del robot Diablo (robot híbrido con ruedas y patas) utilizando el middleware ROS 2 Humble y el simulador Webots**.

## Descripción del Proyecto

El objetivo es desarrollar un driver completo en C++ que interface la API de Webots con el ecosistema ROS 2, permitiendo la visualización de sensores (LiDAR), el cálculo de odometría diferencial y, posteriormente, la navegación autónoma.

### Características Implementadas
- **Driver C++ (`diablo_driver`):** Nodo de alto rendimiento que comunica directamente con los motores y sensores de Webots.
- **Odometría Diferencial:** Cálculo cinemático (`dead reckoning`) basado en encoders simulados.
- **Sincronización Temporal:** Implementación estricta de `use_sim_time` para sincronizar el reloj de ROS 2 con el paso de simulación de Webots.
- **Gestión de LiDAR:**
  - Publicación de `sensor_msgs/LaserScan`.
  - Inyección de intensidades sintéticas para compatibilidad visual con RViz.
  - Corrección de *Frames* y *Mirroring*.
- **Transformadas (TF2):** Árbol de transformadas completo (`odom` -> `base_link` -> `lidar_link`).

## Requisitos Previos

- **Sistema Operativo:** Ubuntu 22.04 LTS (Jammy Jellyfish).
- **ROS 2:** Distribución Humble Hawksbill.
- **Simulador:** Webots (Versión R2023b o superior).
- **Dependencias de ROS:**
  ```bash
  sudo apt install ros-humble-webots-ros2 ros-humble-xacro ros-humble-tf2-tools
