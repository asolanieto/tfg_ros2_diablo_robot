FASE 1: Preparación del Entorno y Dependencias
Aquí solucionamos la falta de librerías del sistema y la ausencia de dependencias de ROS que rosdep no instala bien en esta arquitectura.

1. Instalar librería geográfica y aplicar el "Parche del Nombre": El sistema busca libGeographicLib.so pero Ubuntu instala libGeographic.so.

Bash

sudo apt update
sudo apt install libgeographic-dev
# Crear el enlace simbólico para engañar al linker (ajusta la arquitectura si no es x86_64, ej: aarch64-linux-gnu en Pi)
sudo ln -s /usr/lib/aarch64-linux-gnu/libGeographic.so /usr/lib/aarch64-linux-gnu/libGeographicLib.so
2. Clonar repositorios base necesarios (Source Install): Como los binarios de cv_bridge y pcl están rotos o incompletos en tu entorno, los compilamos desde el código fuente.

Bash

cd ~/tfg_ws/src
# Dependencias base de visión
git clone -b humble https://github.com/ros-perception/vision_opencv.git
git clone -b humble https://github.com/ros-perception/perception_pcl.git

# Dependencia de navegación que faltaba (NavMap)
git clone https://github.com/EasyNavigation/NavMap.git
FASE 2: Parcheo de Código (Compatibilidad Humble & Rutas)
EasyNav está escrito para versiones modernas (Iron/Jazzy). Hay que "bajarlo" a Humble y arreglar las rutas de inclusión manualmente.

A. Arreglar easynav_common (El Núcleo)
Problema: No encuentra cv_bridge_export.h ni el binario .so, y usa .hpp en lugar de .h.

Editar CMakeLists.txt: src/EasyNavigation/easynav_common/CMakeLists.txt

Añadir rutas absolutas a include_directories y target_link_libraries.

Acción: Apuntar a install/cv_bridge/include y install/cv_bridge/lib/libcv_bridge.so.

Editar C++ (.cpp y .hpp): En ImagePerception y DetectionsPerception.

Cambio: #include "cv_bridge/cv_bridge.hpp" ➔ #include "cv_bridge/cv_bridge.h"

B. Arreglar Plugins (Bonxai, Costmap, NavMap, Planners)
Problema: La función get_fully_qualified_name() no existe en Humble.

Archivos afectados:

easynav_bonxai_maps_manager/src/.../BonxaiMapsManager.cpp

easynav_costmap_maps_manager/src/.../CostmapMapsManager.cpp

easynav_costmap_planner/src/.../CostmapPlanner.cpp

Cualquier archivo .cpp dentro de src/NavMap que use esa función.

Acción: Buscar y reemplazar TODAS las apariciones:

node->get_fully_qualified_name() ➔ node->get_name()

C. Arreglar easynav_system (Main Node)
Problema: Error de puntero en tf2_ros::TransformListener.

Archivo: src/EasyNavigation/easynav_system/src/system_main.cpp (aprox línea 129).

Acción: Quitar el asterisco o ampersand sobrante en el constructor:

new tf2_ros::TransformListener(..., *node) ➔ new tf2_ros::TransformListener(..., node)

D. Arreglar navmap_ros
Problema: Busca un .so de pcl_conversions que no existe y le falta message_filters.

Editar CMakeLists.txt: src/NavMap/navmap_ros/CMakeLists.txt

Añadir find_package(message_filters REQUIRED).

Añadir ${message_filters_INCLUDE_DIRS} a los includes.

Añadir ruta manual a includes: /home/adri/tfg_ws/install/pcl_conversions/include.

CRÍTICO: Borrar cualquier referencia a libpcl_conversions.so o pcl_conversions::pcl_conversions en target_link_libraries.

FASE 3: Compilación Quirúrgica
No uses un colcon build genérico. Necesitamos un orden específico y banderas para evitar que la Raspberry se congele y para permitir sobreescribir los paquetes del sistema.

1. Limpieza preventiva (solo si hay residuos):

Bash

cd ~/tfg_ws
rm -rf build/image_geometry install/image_geometry build/cv_bridge install/cv_bridge
2. El Comando Maestro:

Bash

colcon build \
  --symlink-install \
  --cmake-args -DBUILD_TESTING=OFF \
  --parallel-workers 1 \
  --allow-overriding cv_bridge pcl_conversions image_geometry
--parallel-workers 1: Vital para que la RAM de la Pi no explote.

--allow-overriding: Obligatorio para usar nuestras versiones parcheadas de cv_bridge y pcl.
