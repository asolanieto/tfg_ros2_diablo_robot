import os
from launch import LaunchDescription
from launch.actions import TimerAction, ExecuteProcess
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from webots_ros2_driver.webots_launcher import WebotsLauncher

def generate_launch_description():
    
    package_dir = get_package_share_directory('diablo_test')

    # Rutas
    world_path = os.path.join(package_dir, 'worlds', 'diablo_robot.wbt') 
    urdf_path = os.path.join(package_dir, 'urdf', 'diablo.urdf')
    easynav_config_path = os.path.join(package_dir, 'config', 'easynav_params.yaml')
    slam_config = os.path.join(package_dir, 'config', 'slam_localization.yaml') 
    mux_config_path = os.path.join(package_dir, 'config', 'mux_params.yaml')

    # 1. Webots
    webots = WebotsLauncher(
        world=world_path,
        mode='realtime'
    )

    # 2. Driver
    my_robot_driver = Node(
        package='diablo_test',
        executable='diablo_driver',
        output='screen',
        additional_env={'WEBOTS_CONTROLLER_URL': 'DiabloOriginal'},
        parameters=[{'robot_description': urdf_path}, {'use_sim_time': False}],
        remappings=[('/joint_states', '/joint_states_webots'), # Hacemos que publique en un topic "intermedio" para que el bridge lo sincronice a tiempo real
                    ('/tf', '/tf_garbage')]  # Evitamos que publique TFs "caducados" que confunden a RViz y SLAM. El bridge se encargará de publicar TFs frescos en el topic correcto (/tf
    )

    # 3. STATIC TF (Para unir base_link con el lidar)
    lidar_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='lidar_tf_publisher',
        arguments=['0', '0', '0.15', '3.1416', '0', '0', 'base_link', 'lidar_link'],
        parameters=[{'use_sim_time': False}]
    )

    # 4. Robot State Publisher (use_sim_time FALSE)
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': open(urdf_path).read()}, {'use_sim_time': False}]
    )

    # 5. BRIDGES
    scan_bridge_cmd = ExecuteProcess(
        cmd=['python3', os.path.join(package_dir, 'src/bridges', 'scan_bridge.py')],
        output='screen'
    )

    odom_bridge_cmd = ExecuteProcess(
        cmd=['python3', os.path.join(package_dir, 'src/bridges', 'odom_bridge.py')],
        output='screen'
    )

    joint_bridge_cmd = ExecuteProcess(
        cmd=['python3', os.path.join(package_dir, 'src/bridges', 'joint_bridge.py')],
        output='screen'
    )

    # 6. SLAM Toolbox (Asíncrono, use_sim_time=False en el yaml)
    slam_node = Node(
        package='slam_toolbox',
        executable='async_slam_toolbox_node',
        name='slam_toolbox',
        output='screen',
        parameters=[slam_config]
    )

    # 7. EasyNav (use_sim_time=False en el yaml)
    easynav_node = Node(
        package='easynav_system',
        executable='system_main',
        name='system_main',
        output='screen',
        arguments=['--ros-args', '--params-file', easynav_config_path],
        parameters=[
            easynav_config_path,
            {'maps_manager_node.CostmapMapsManager.publish_frequency': 1.0} 
        ],
        remappings=[('/cmd_vel', '/cmd_vel_nav')]   # Para implementar el twist_mux que permite conmutar entre control manual y navegación autónoma. 
    )

    # 8. Twist Mux 
    twist_mux_node = Node(
        package='twist_mux',
        executable='twist_mux',
        output='screen',
        parameters=[mux_config_path],
        # El mux recibe 'cmd_vel_nav' y 'cmd_vel_key' y saca 'cmd_vel_out'
        # Remapeamos su salida para que vaya directa al Driver (/cmd_vel)
        remappings=[('/cmd_vel_out', '/cmd_vel')]
    )

    # Retrasos para asegurar orden de carga
    delayed_nodes = TimerAction(
        period=5.0, 
        actions=[slam_node, easynav_node]
    )
    
    return LaunchDescription([
        webots,
        my_robot_driver,
        lidar_tf,
        robot_state_publisher,
        scan_bridge_cmd,
        odom_bridge_cmd,
        joint_bridge_cmd, 
        delayed_nodes,
        twist_mux_node
    ])