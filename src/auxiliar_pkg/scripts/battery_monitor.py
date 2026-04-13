#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import BatteryState
import subprocess
import time

class BatteryMonitor(Node):
    def __init__(self):
        super().__init__('battery_monitor')
        self.subscription = self.create_subscription(
            BatteryState,
            '/diablo/sensor/Battery',
            self.battery_callback,
            10)
        self.last_alert_time = 0
        self.alert_interval = 60 # Segundos entre cada aviso para no saturar la terminal

    def battery_callback(self, msg):
        if msg.percentage < 15.0:
            current_time = time.time()
            if current_time - self.last_alert_time > self.alert_interval:
                alert_msg = f"¡ALERTA CRITICA! Batería del robot Diablo al {msg.percentage}%"
                self.get_logger().warn(alert_msg)
                
                # Envia el mensaje a todas las terminales SSH conectadas
                subprocess.run(f"for tty in /dev/pts/*; do echo '\n{alert_msg}\n' > $tty 2>/dev/null; done", shell=True)
                
                self.last_alert_time = current_time

def main(args=None):
    rclpy.init(args=args)
    node = BatteryMonitor()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()