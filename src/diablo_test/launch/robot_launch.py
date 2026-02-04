import os
import launch
import sys # Para el bridge
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from webots_ros2_driver.webots_launcher import WebotsLauncher
from launch.substitutions import LaunchConfiguration
from launch.actions import TimerAction      # Para retrasar el inicio de EasyNavigation
from launch.actions import ExecuteProcess  # Para ejecutar el bridge

def generate_launch_description():
    
    package_dir = get_package_share_directory('diablo_test')

    # Rutas
    world_path = os.path.join(package_dir, 'worlds', 'diablo_robot.wbt') 
    urdf_path = os.path.join(package_dir, 'urdf', 'diablo.urdf')
    easynav_config_path = os.path.join(package_dir, 'config', 'easynav_params.yaml')


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
            {'use_sim_time': False} # Tiempo simulado para que funcione RViz
        ]
    )

    # 3. STATIC TF (Para unir base_link con el lidar)
    lidar_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='lidar_tf_publisher',
        arguments=['0', '0', '0.15', '3.1416', '0', '0', 'base_link', 'lidar_link'],
        parameters=[{'use_sim_time': False}]
    )
    

    # 4. EasyNavigation Node
    easynav_node = Node(
        package='easynav_system',
        executable='system_main',
        output='screen',
        parameters=[easynav_config_path,
                    {'use_sim_time': False}] 
    )

    # Nodo Puente para visualizar el NavMap en RViz
    navmap_bridge_cmd = ExecuteProcess(
        cmd=['python3', '/home/adri/tfg_ws/src/diablo_test/src/navmap_bridge.py'],
        output='screen'
    )

    # Retrasar el inicio de EasyNavigation para asegurar que Webots y el robot estén listos
    delayed_easynav = TimerAction(
        period=5.0, 
        actions=[easynav_node, lidar_tf]
    )

    
    return LaunchDescription([
        webots,
        my_robot_driver, 
        delayed_easynav,
        navmap_bridge_cmd,
        
        launch.actions.RegisterEventHandler(
            event_handler=launch.event_handlers.OnProcessExit(
                target_action=webots,
                on_exit=[launch.actions.EmitEvent(event=launch.events.Shutdown())],
            )
        )
    ])