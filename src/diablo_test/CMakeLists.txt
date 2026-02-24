cmake_minimum_required(VERSION 3.8)
project(diablo_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2 REQUIRED)


if(NOT DEFINED ENV{WEBOTS_HOME})
  set(ENV{WEBOTS_HOME} "/usr/local/webots")
endif()

include_directories("$ENV{WEBOTS_HOME}/include/controller/cpp")
link_directories("$ENV{WEBOTS_HOME}/lib/controller")



add_executable(diablo_driver src/diablo_driver.cpp)
ament_target_dependencies(diablo_driver rclcpp std_msgs geometry_msgs sensor_msgs nav_msgs tf2 tf2_ros)
target_link_libraries(diablo_driver 
  "$ENV{WEBOTS_HOME}/lib/controller/libController.so"
  "$ENV{WEBOTS_HOME}/lib/controller/libCppController.so"
)



install(TARGETS 
  diablo_driver
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  urdf
  launch
  worlds
  meshes
  textures
  config
  maps
  DESTINATION share/${PROJECT_NAME}
)

# install(PROGRAMS
#   src/scan_bridge.py
#   src/navmap_bridge.py
#   DESTINATION lib/${PROJECT_NAME}
# )


install(
  DIRECTORY src/
  DESTINATION share/${PROJECT_NAME}/src
  FILES_MATCHING PATTERN "*.py"
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
