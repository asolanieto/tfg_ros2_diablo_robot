import os
from launch import LaunchDescription
from launch.actions import TimerAction, ExecuteProcess
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
from webots_ros2_driver.webots_launcher import WebotsLauncher

def generate_launch_description():
    
    package_dir = get_package_share_directory('diablo_test')

    # Paths
    world_path = os.path.join(package_dir, 'worlds', 'diablo_robot.wbt') 
    urdf_path = os.path.join(package_dir, 'urdf', 'diablo.urdf')
    easynav_config_path = os.path.join(package_dir, 'config', 'easynav_params.yaml')
    slam_config = os.path.join(package_dir, 'config', 'slam_localization.yaml') 
    mux_config_path = os.path.join(package_dir, 'config', 'mux_params.yaml')

    # Webots
    webots = WebotsLauncher(
        world=world_path,
        mode='realtime'
    )

    # Driver
    my_robot_driver = Node(
        package='diablo_test',
        executable='diablo_driver',
        output='screen',
        additional_env={'WEBOTS_CONTROLLER_URL': 'DiabloOriginal'},
        parameters=[{'robot_description': urdf_path}, {'use_sim_time': False}],
        remappings=[('/joint_states', '/joint_states_webots'), 
                    ('/tf', '/tf_garbage')] 
    )

    # Robot State Publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[{'robot_description': open(urdf_path).read()}, {'use_sim_time': False}]
    )

    # Bridges
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

    # SLAM Toolbox
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
            {'maps_manager_node.CostmapMapsManager.publish_frequency': 1.0} 
        ],
        remappings=[('/cmd_vel', '/cmd_vel_nav')] 
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

    # Retrasos para asegurar orden de carga
    delayed_nodes = TimerAction(
        period=5.0, 
        actions=[slam_node, easynav_node]
    )
    
    return LaunchDescription([
        webots,
        my_robot_driver,
        robot_state_publisher,
        scan_bridge_cmd,
        odom_bridge_cmd,
        joint_bridge_cmd, 
        delayed_nodes,
        twist_mux_node
    ])