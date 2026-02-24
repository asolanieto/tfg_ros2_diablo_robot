// Copyright 2025 Intelligent Robotics Lab
// License: GPL v3.0

#include "easynav_simple_localizer/AMCLLocalizer.hpp"
#include "easynav_common/RTTFBuffer.hpp"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"
#include "geometry_msgs/msg/transform_stamped.hpp"
#include "nav_msgs/msg/odometry.hpp"

namespace easynav
{

// Registro el printer por si alguien quiere debuguear NavState
AMCLLocalizer::AMCLLocalizer()
{
  NavState::register_printer<nav_msgs::msg::Odometry>(
    [](const nav_msgs::msg::Odometry & odom) {
      std::ostringstream ret;
      ret << "SLAM Bridge Pose: (" << odom.pose.pose.position.x << ", " 
          << odom.pose.pose.position.y << ")";
      return ret.str();
    });
}

AMCLLocalizer::~AMCLLocalizer()
{
}

void
AMCLLocalizer::on_initialize()
{
  RCLCPP_INFO(get_node()->get_logger(), 
    ">>> AMCLLocalizer REEMPLAZADO: Funcionando como puente TF -> NavState para SLAM <<<");
}


void
AMCLLocalizer::update_rt(NavState & nav_state)
{
  // Llamamos a la lógica principal para mantener NavState fresco
  update(nav_state);
}

// Esta función se llama a la frecuencia del grafo
void
AMCLLocalizer::update(NavState & nav_state)
{
  // 1. Acceder al Buffer de Transformadas (TF)
  auto tf_buffer = RTTFBuffer::getInstance();
  const auto & tf_info = tf_buffer->get_tf_info();

  try {
    // 2. Preguntar a TF dónde está el robot en el mapa
    // SLAM Toolbox + Driver se encargan de mantener esta cadena (map -> odom -> base_link)
    geometry_msgs::msg::TransformStamped t;
    t = tf_buffer->lookupTransform(
        tf_info.map_frame, 
        tf_info.robot_frame, 
        tf2::TimePointZero); // Dame la última conocida

    // 3. Convertir TF a mensaje de Odometría (formato que espera NavState)
    nav_msgs::msg::Odometry robot_pose;
    robot_pose.header = t.header;
    robot_pose.child_frame_id = tf_info.robot_frame;
    
    robot_pose.pose.pose.position.x = t.transform.translation.x;
    robot_pose.pose.pose.position.y = t.transform.translation.y;
    robot_pose.pose.pose.position.z = t.transform.translation.z;
    robot_pose.pose.pose.orientation = t.transform.rotation;

    // Rellenamos covarianzas con 0 (confianza total/desconocida, SLAM ya filtra)
    // Esto evita errores si algún nodo comprueba la matriz.
    for(int i=0; i<36; i++) robot_pose.pose.covariance[i] = 0.0;

    // 4. ESCRIBIR EN NAVSTATE
    nav_state.set("robot_pose", robot_pose);

    // Debug periódico para confirmar vida
    RCLCPP_INFO_THROTTLE(get_node()->get_logger(), *get_node()->get_clock(), 5000,
       "[Localizer Bridge] Robot en X: %.2f, Y: %.2f", 
       robot_pose.pose.pose.position.x, robot_pose.pose.pose.position.y);

  } catch (tf2::TransformException & ex) {
    RCLCPP_WARN_THROTTLE(get_node()->get_logger(), *get_node()->get_clock(), 2000,
       "[Localizer Bridge] Esperando TF de SLAM... Error: %s", ex.what());
  }
}

// --- Funciones muertas (Stubs) para cumplir con la herencia ---
// No hacen nada porque ya no usamos partículas ni odom_callback directo.

void AMCLLocalizer::odom_callback(nav_msgs::msg::Odometry::UniquePtr) {}
void AMCLLocalizer::predict(NavState &) {}
void AMCLLocalizer::correct(NavState &) {}
void AMCLLocalizer::reseed() {}
void AMCLLocalizer::publishTF(const tf2::Transform &) {}
void AMCLLocalizer::publishParticles() {}
void AMCLLocalizer::publishEstimatedPose(const tf2::Transform &) {}

tf2::Transform AMCLLocalizer::getEstimatedPose() const {
  return tf2::Transform::getIdentity();
}

nav_msgs::msg::Odometry AMCLLocalizer::get_pose() {
  return nav_msgs::msg::Odometry();
}

}  // namespace easynav

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(easynav::AMCLLocalizer, easynav::LocalizerMethodBase)