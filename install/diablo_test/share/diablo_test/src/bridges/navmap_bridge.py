#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, DurabilityPolicy, ReliabilityPolicy
from navmap_ros_interfaces.msg import NavMap

class NavMapBridge(Node):
    def __init__(self):
        super().__init__('navmap_bridge')

        # 1. Configuración QoS para leer el mapa original (Transient Local)
        qos_in = QoSProfile(
            depth=1,
            durability=DurabilityPolicy.TRANSIENT_LOCAL,
            reliability=ReliabilityPolicy.RELIABLE
        )

        # 2. Suscripción al mapa original de EasyNav
        self.sub = self.create_subscription(
            NavMap,
            '/maps_manager_node/NavMapMapsManager/map',
            self.map_callback,
            qos_in
        )

        # 3. Publicador para RViz (en un topic nuevo)
        self.pub = self.create_publisher(
            NavMap,
            '/navmap_viz_3d',
            qos_in
        )

        self.last_map = None
        
        # 4. Timer para republicar constantemente
        # Republicamos cada 10s con la hora ACTUAL para que RViz nunca lo rechace
        self.timer = self.create_timer(10.0, self.timer_callback)
        

    def map_callback(self, msg):
        self.last_map = msg

    def timer_callback(self):
        if self.last_map is not None:
            # ACTUALIZAMOS LA HORA AL PRESENTE
            self.last_map.header.stamp = self.get_clock().now().to_msg()
            self.pub.publish(self.last_map)

def main(args=None):
    rclpy.init(args=args)
    node = NavMapBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()