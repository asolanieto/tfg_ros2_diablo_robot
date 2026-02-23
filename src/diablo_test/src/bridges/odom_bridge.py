#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from tf2_ros import TransformBroadcaster

class OdomBridge(Node):
    def __init__(self):
        super().__init__('odom_bridge')
        
        # Suscribirse a la odometría original del driver
        self.sub = self.create_subscription(
            Odometry,
            '/odom', # El topic que publica tu diablo_driver
            self.odom_callback,
            10)
            
        # Herramienta para publicar TFs
        self.tf_broadcaster = TransformBroadcaster(self)
        

    def odom_callback(self, msg):
        # 1. Capturamos la odometría
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        z = msg.pose.pose.position.z
        
        qx = msg.pose.pose.orientation.x
        qy = msg.pose.pose.orientation.y
        qz = msg.pose.pose.orientation.z
        qw = msg.pose.pose.orientation.w

        # 2. Creamos la Transformada (TF) con la HORA ACTUAL DEL SISTEMA
        t = TransformStamped()
        
        # Importante: Usar el reloj del nodo (System Time), no el del mensaje original
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_link'

        # Rellenamos datos
        t.transform.translation.x = x
        t.transform.translation.y = y
        t.transform.translation.z = z
        t.transform.rotation.x = qx
        t.transform.rotation.y = qy
        t.transform.rotation.z = qz
        t.transform.rotation.w = qw

        # 3. Emitimos la TF "rejuvenecida"
        self.tf_broadcaster.sendTransform(t)

def main(args=None):
    rclpy.init(args=args)
    node = OdomBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()