import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Twist
from nav_msgs.msg import Odometry
from std_msgs.msg import Float64
import math

class DebugMonitor(Node):
    def __init__(self):
        super().__init__('debug_monitor')
        self.goal = None
        self.last_cmd = Twist()
        
        # Suscriptores
        self.create_subscription(PoseStamped, '/goal_pose', self.goal_cb, 10)
        self.create_subscription(Odometry, '/odom', self.odom_cb, 10)
        self.create_subscription(Twist, '/cmd_vel', self.cmd_cb, 10)
        
        # Publicadores (para PlotJuggler)
        self.pub_dist = self.create_publisher(Float64, '/debug/distance', 10)
        self.pub_angle = self.create_publisher(Float64, '/debug/angle_error', 10)

    def goal_cb(self, msg):
        self.goal = msg.pose.position
        self.get_logger().info("NUEVO OBJETIVO RECIBIDO")

    def cmd_cb(self, msg):
        self.last_cmd = msg

    def odom_cb(self, msg):
        if self.goal is None:
            return
            
        # Posición actual
        curr_x = msg.pose.pose.position.x
        curr_y = msg.pose.pose.position.y
        
        # Orientación actual (Yaw desde cuaternio)
        q = msg.pose.pose.orientation
        siny_cosp = 2 * (q.w * q.z + q.x * q.y)
        cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z)
        curr_yaw = math.atan2(siny_cosp, cosy_cosp)
        
        # Matemáticas del error
        dx = self.goal.x - curr_x
        dy = self.goal.y - curr_y
        dist = math.hypot(dx, dy)
        
        angle_to_goal = math.atan2(dy, dx)
        angle_error = angle_to_goal - curr_yaw
        
        # Normalizar ángulo entre -pi y pi
        angle_error = math.atan2(math.sin(angle_error), math.cos(angle_error))
        
        # Publicar para PlotJuggler
        self.pub_dist.publish(Float64(data=dist))
        self.pub_angle.publish(Float64(data=angle_error))
        
        # Imprimir en consola de forma legible
        print(f"Dist: {dist:.2f}m | Err Ang: {math.degrees(angle_error):.1f}° || Cmd X: {self.last_cmd.linear.x:.2f} m/s | Cmd W: {self.last_cmd.angular.z:.2f} rad/s")

def main(args=None):
    rclpy.init(args=args)
    monitor = DebugMonitor()
    try:
        rclpy.spin(monitor)
    except KeyboardInterrupt:
        pass
    monitor.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()