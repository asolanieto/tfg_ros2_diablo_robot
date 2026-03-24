#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from rclpy.qos import QoSProfile, ReliabilityPolicy

class JointBridge(Node):
    def __init__(self):
        super().__init__('joint_bridge')
        
        # QoS para no perder datos
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)

        # 1. Escuchamos el topic "crudo" del simulador
        self.sub = self.create_subscription(
            JointState,
            '/joint_states_webots',
            self.joint_callback,
            qos)
            
        # 2. Publicamos en el topic oficial que escuchan todos (RViz, RSP)
        self.pub = self.create_publisher(JointState, '/joint_states', 10)
        
    def joint_callback(self, msg):
        # Actualizamos la fecha a "Ahora mismo"
        msg.header.stamp = self.get_clock().now().to_msg()
        self.pub.publish(msg)

def main(args=None):
    rclpy.init(args=args)
    node = JointBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()