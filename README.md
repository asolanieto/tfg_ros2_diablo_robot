Control y Simulación del Robot Diablo en ROS 2 y Webots

Este repositorio contiene el paquete de desarrollo para el Trabajo de Fin de Grado (TFG) centrado en la simulación, control y odometría del robot Diablo (robot híbrido con ruedas y patas) utilizando el middleware ROS 2 Humble y el simulador Webots**.

- Descripción del Proyecto

El objetivo es desarrollar un driver completo en C++ que interface la API de Webots con el ecosistema ROS 2, permitiendo la visualización de sensores (LiDAR), el cálculo de odometría diferencial y, posteriormente, la navegación autónoma mediante Nav2/EasyNav.

Características Implementadas
- Driver C++ (diablo_driver): Nodo que comunica directamente con los motores y sensores de Webots.
- Odometría Diferencial: Cálculo cinemático basado en encoders simulados.
- Gestión de LiDAR:
  - Publicación de sensor_msgs/LaserScan.
- Transformadas (TF2): Árbol de transformadas completo (odom -> base_link -> lidar_link).

Requisitos Previos

- Sistema Operativo: Ubuntu 22.04 LTS (Jammy Jellyfish).
- ROS 2: Distribución Humble Hawksbill.
- Simulador: Webots (Versión R2023b o superior).
