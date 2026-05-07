#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry, Path
from geometry_msgs.msg import PoseStamped

class RealPathPublisher(Node):
    def __init__(self):
        super().__init__('real_path_publisher')
        self.subscription = self.create_subscription(Odometry, '/odom', self.odom_callback, 10)
        self.publisher = self.create_publisher(Path, '/real_path', 10)
        self.path_msg = Path()
        self.path_msg.header.frame_id = 'map' 

    def odom_callback(self, msg):
        pose = PoseStamped()
        pose.header = msg.header
        pose.pose = msg.pose.pose
        
        self.path_msg.poses.append(pose)
        self.path_msg.header.stamp = self.get_clock().now().to_msg()
        
        self.publisher.publish(self.path_msg)

def main(args=None):
    rclpy.init(args=args)
    node = RealPathPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()