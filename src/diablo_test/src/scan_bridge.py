#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from tf2_ros import Buffer, TransformListener
from rclpy.time import Time
from rclpy.duration import Duration
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy

class AutoScanBridge(Node):
    def __init__(self):
        super().__init__('scan_bridge')
        
        # Configuramos QoS para que no se pierdan mensajes
        qos = QoSProfile(depth=10, reliability=ReliabilityPolicy.BEST_EFFORT)
        qos_out = QoSProfile(depth=10, reliability=ReliabilityPolicy.RELIABLE)

        # 1. Herramientas para leer el TF (Espiar al Driver)
        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # 2. Suscripción y Publicación
        self.sub = self.create_subscription(LaserScan, '/scan', self.scan_callback, qos)
        self.pub = self.create_publisher(LaserScan, '/scan_bridged', qos_out)
        
        self.get_logger().info("Auto-Bridge: Sincronizando Láser con la última Odometría disponible...")

    def scan_callback(self, msg):
        try:
            # 3. Preguntamos: ¿Cuál es la última transformación odom->base_link que existe?
            # Usamos Time() vacío para pedir "la más reciente"
            if self.tf_buffer.can_transform('odom', 'base_link', Time()):
                
                # Obtenemos el dato real del driver
                latest_tf = self.tf_buffer.lookup_transform('odom', 'base_link', Time())
                
                # 4. EL TRUCO MAESTRO:
                # Copiamos la fecha exacta del Driver al Láser.
                # Si el driver dice que son las 12:00:01, el láser será de las 12:00:01.
                # RViz ya no puede quejarse.
                msg.header.stamp = latest_tf.header.stamp
                
                self.pub.publish(msg)
            else:
                # Si el driver aun no ha arrancado, esperamos sin publicar basura
                pass
                
        except Exception as e:
            # Es normal ver esto los primeros 2 segundos hasta que el buffer se llena
            pass

def main(args=None):
    rclpy.init(args=args)
    node = AutoScanBridge()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()