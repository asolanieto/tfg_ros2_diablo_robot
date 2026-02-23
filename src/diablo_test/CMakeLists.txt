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
find_package(motion_msgs REQUIRED)



add_executable(diablo_bridge src/diablo_bridge.cpp)
ament_target_dependencies(diablo_bridge
  rclcpp
  geometry_msgs
  nav_msgs
  tf2
  tf2_ros
  motion_msgs
)

install(TARGETS
  diablo_bridge
  DESTINATION lib/${PROJECT_NAME}
)


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
#   src/bridges/scan_bridge.py
#   src/bridges/navmap_bridge.py
#   src/bridges/joint_bridge.py
#   src/bridges/odom_bridge.py
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
