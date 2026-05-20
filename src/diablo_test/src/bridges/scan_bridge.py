#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

class AutoScanBridge(Node):
    def __init__(self):
        super().__init__('scan_bridge')
        
        # QoS compatible con simuladores y hardware real (Best Effort)
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        qos_out = QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE)

        # Suscripción al tópico original (Time=Simulación)
        self.sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, qos)
        
        # Publicación al tópico puenteado (Time=Real)
        self.pub = self.create_publisher(LaserScan, '/scan_bridged', qos_out)
        
    def scan_callback(self, msg):
        msg.header.stamp = self.get_clock().now().to_msg()
        
        # Publicamos
        self.pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = AutoScanBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()