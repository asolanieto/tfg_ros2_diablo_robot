#!/usr/bin/env python3
import math
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import LaserScan
from tf2_ros import Buffer, TransformListener
from geometry_msgs.msg import PointStamped
import tf2_geometry_msgs  # registra el tipo en el buffer
import numpy as np
from tf_transformations import quaternion_matrix

class GroundFilter(Node):
    def __init__(self):
        super().__init__('scan_ground_filter')
        self.declare_parameter('z_threshold', 0.05)
        self.declare_parameter('target_frame', 'base_footprint')
        self.declare_parameter('front_half_fov', 1.5708)  # 90° por defecto (±90° del frente real)

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.sub = self.create_subscription(LaserScan, '/scan', self.cb, 10)
        self.pub = self.create_publisher(LaserScan, '/scan_filtered', 10)
        self._first = True
        self.get_logger().info('scan_ground_filter ready, waiting for scans...')

    def cb(self, msg):
        try:
            z_th = self.get_parameter('z_threshold').value
            target = self.get_parameter('target_frame').value

            try:
                tf = self.tf_buffer.lookup_transform(
                    target, msg.header.frame_id, rclpy.time.Time())
            except Exception as e:
                self.get_logger().warn(f'TF no disponible: {e}', throttle_duration_sec=2.0)
                return

            # Matriz 4x4 de la TF a partir del cuaternión + traslación
            q = tf.transform.rotation
            t = tf.transform.translation
            T = quaternion_matrix([q.x, q.y, q.z, q.w])
            T[0, 3] = t.x
            T[1, 3] = t.y
            T[2, 3] = t.z

            # Array de rangos a numpy
            ranges = np.asarray(msg.ranges, dtype=np.float32)
            n = ranges.size
            angles = msg.angle_min + np.arange(n, dtype=np.float32) * msg.angle_increment

            # Máscara de validez
            valid = np.isfinite(ranges) & (ranges >= msg.range_min) & (ranges <= msg.range_max)

            # Puntos en frame del lidar (z=0 en ese frame)
            xs = ranges * np.cos(angles)
            ys = ranges * np.sin(angles)
            zs = np.zeros(n, dtype=np.float32)
            ones = np.ones(n, dtype=np.float32)
            pts = np.vstack([xs, ys, zs, ones])  # 4xN

            # Transformar de golpe
            pts_t = T @ pts  # 4xN en frame target

            # Marcar inválidos los rayos cuya z proyectada cae por debajo del umbral
            # Filtro de altura (descarta suelo)
            below = pts_t[2, :] < z_th

            # Filtro de FOV: descartar los rayos traseros del LiDAR.
            # El lidar está girado 180° respecto a base_link, así que el "frente físico del robot"
            # corresponde a los ángulos cercanos a ±π del array (no a 0).
            # Conservamos un cono ±front_half_fov alrededor del frente real.
            front_half_fov = self.get_parameter('front_half_fov').value
            ang_abs = np.abs(angles)
            out_of_fov = ang_abs < (math.pi - front_half_fov)

            kill = valid & (below | out_of_fov)
            new_ranges = ranges.copy()
            new_ranges[kill] = float('inf')

            out = LaserScan()
            out.header = msg.header
            out.angle_min = msg.angle_min
            out.angle_max = msg.angle_max
            out.angle_increment = msg.angle_increment
            out.time_increment = msg.time_increment
            out.scan_time = msg.scan_time
            out.range_min = msg.range_min
            out.range_max = msg.range_max
            out.ranges = new_ranges.tolist()
            out.intensities = msg.intensities
            self.pub.publish(out)

            if self._first:
                self.get_logger().info('First scan processed and published.')
                self._first = False
        except Exception as e:
            self.get_logger().error(f'Exception in callback: {e}')

def main():
    rclpy.init()
    node = GroundFilter()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()