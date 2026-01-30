import os
import launch
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from webots_ros2_driver.webots_launcher import WebotsLauncher

def generate_launch_description():
    package_dir = get_package_share_directory('diablo_test')
    world_path = os.path.join(package_dir, 'worlds', 'diablo_robot.wbt') 
    urdf_path = os.path.join(package_dir, 'urdf', 'diablo.urdf')

    # 1. Webots
    webots = WebotsLauncher(
        world=world_path,
        mode='realtime'
    )

    # 2. Nodo del driver del robot Diablo
    my_robot_driver = Node(
        package='diablo_test',
        executable='diablo_driver',
        output='screen',
        additional_env={'WEBOTS_CONTROLLER_URL': 'DiabloOriginal'},
        parameters=[
            {'robot_description': urdf_path},
            {'use_sim_time': True} # Tiempo simulado para que funcione RViz
        ]
    )

    # 3. STATIC TF (Para unir base_link con el lidar)
    lidar_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='lidar_tf_publisher',
        arguments=['0', '0', '0.15', '3.1416', '0', '0', 'base_link', 'lidar_link'],
        parameters=[{'use_sim_time': True}]
    )

    # 4. Nodo SLAM Toolbox con parámetros ajustados
    slam_node = Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        output='screen',
        parameters=[
            {'use_sim_time': True},           # Sincronización temporal
            {'base_frame': 'base_link'},      # Nombre del frame
            {'odom_frame': 'odom'},
            {'map_frame': 'map'},
            {'scan_topic': '/scan'},
            {'transform_timeout': 0.5},       # TOLERANCIA: Espera 0.5s si la TF llega tarde
            {'map_update_interval': 1.0},     # Actualiza el mapa cada segundo
            {'max_laser_range': 20.0}         # Rango máximo confiable del láser
        ]
    )

    
    return LaunchDescription([
        webots,
        my_robot_driver, 
        lidar_tf,
        slam_node,
        
        launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=webots,
                on_exit=[launch.actions.EmitEvent(event=launch.events.Shutdown())],
            )
        )
    ])