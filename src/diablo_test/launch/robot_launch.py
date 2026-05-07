import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
from launch.actions import TimerAction, ExecuteProcess
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    
    package_dir = get_package_share_directory('diablo_test')

    # Rutas
    urdf_path = os.path.join(package_dir, 'urdf', 'diablo.urdf')
    easynav_config_path = os.path.join(package_dir, 'config', 'easynav_params.yaml')
    slam_config = os.path.join(package_dir, 'config', 'slam_localization.yaml') 
    mux_config_path = os.path.join(package_dir, 'config', 'mux_params.yaml')


    # 2. Driver
    my_robot_driver = Node(
        package='diablo_test',
        executable='diablo_bridge',
        output='screen',
        parameters=[{'robot_description': urdf_path}, {'use_sim_time': False}])
    

    # Launch driver lidar
    lidar_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('rplidar_ros'), 'launch', 'rplidar_s3_launch.py')
        ),
        launch_arguments={
            'frame_id': 'lidar_link',
            'serial_port': '/dev/ttyUSB0',
            'scan_mode': 'Standard'
        }.items()
    )

    # Publicamos un joint_state estatico para ver el modelo del robot (pendiente de añadir joints dinámicos en el futuro)
    joint_state_publisher_node = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        parameters=[{'robot_description': open(urdf_path).read()}, {'use_sim_time': False}], 
    )

    # Robot State Publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': open(urdf_path).read()}, {'use_sim_time': False}]
    )


    # SLAM Toolbox (Asíncrono, use_sim_time=False en el yaml)
    slam_node = Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        output='screen',
        parameters=[slam_config]
    )

    # EasyNav
    easynav_node = Node(
        package='easynav_system',
        executable='system_main',
        name='system_main',
        output='screen',
        arguments=['--ros-args', '--params-file', easynav_config_path],
        parameters=[
            easynav_config_path,
            {'use_sim_time': False},
            {'maps_manager_node.CostmapMapsManager.publish_frequency': 1.0} 
        ],
        remappings=[('/cmd_vel', '/cmd_vel_nav')]   # Para implementar el twist_mux que permite conmutar entre control manual y navegación autónoma. 
    )

    # Twist Mux 
    twist_mux_node = Node(
        package='twist_mux',
        executable='twist_mux',
        output='screen',
        parameters=[mux_config_path],
        # El mux recibe 'cmd_vel_nav' y 'cmd_vel_key' y saca 'cmd_vel_out'
        # Remapeamos su salida para que vaya directa al Driver (/cmd_vel)
        remappings=[('/cmd_vel_out', '/cmd_vel')]
    )

    # Script para publicar el path real del robot
    real_path_publisher = Node(
        package='auxiliar_pkg',
        executable='path_publisher.py',
        name='real_path_publisher',
        output='screen'
    )

    # Retrasos para asegurar orden de carga
    delay_slam = TimerAction(
        period=15.0, 
        actions=[slam_node]
    )

    delay_all = TimerAction(
        period=6.0, 
        actions=[my_robot_driver, robot_state_publisher, twist_mux_node, joint_state_publisher_node, real_path_publisher]
    )

    delay_easynav = TimerAction(
        period=15.0, 
        actions=[easynav_node]
    )
    
    return LaunchDescription([
        lidar_launch,
        delay_slam,
        delay_easynav,
        delay_all
    ])