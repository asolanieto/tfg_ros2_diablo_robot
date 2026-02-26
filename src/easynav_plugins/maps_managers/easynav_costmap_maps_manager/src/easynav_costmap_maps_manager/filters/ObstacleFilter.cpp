// Copyright 2025 Intelligent Robotics Lab
// ... (License header) ...

#include <string>
#include <algorithm>
#include <limits>
#include <vector>

#include "easynav_costmap_common/costmap_2d.hpp"
#include "easynav_common/types/NavState.hpp"
#include "easynav_common/types/PointPerception.hpp"
#include "easynav_costmap_common/cost_values.hpp"
#include "easynav_costmap_maps_manager/filters/ObstacleFilter.hpp"
#include "easynav_common/RTTFBuffer.hpp"

namespace easynav
{

ObstacleFilter::ObstacleFilter()
{
}

void
ObstacleFilter::on_initialize()
{
  if (!parent_node_->has_parameter("CostmapMapsManager.publish_frequency")) {
      try {
        parent_node_->declare_parameter("CostmapMapsManager.publish_frequency", 0.0); 
      } catch (...) {}
  }

  // Suscripción al mapa de SLAM
  auto qos = rclcpp::QoS(rclcpp::KeepLast(1)).transient_local().reliable();
  map_sub_ = parent_node_->create_subscription<nav_msgs::msg::OccupancyGrid>(
    "/map", qos, 
    std::bind(&ObstacleFilter::map_callback, this, std::placeholders::_1));
}

void 
ObstacleFilter::map_callback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
  std::lock_guard<std::mutex> lock(map_mutex_);
  last_map_ = msg;
}

void ObstacleFilter::update(NavState & nav_state)
{
  static bool first_run = true;
  if (first_run) {
    parent_node_->set_parameter(rclcpp::Parameter("CostmapMapsManager.publish_frequency", 1.0));
    first_run = false;
  }

  auto dynamic_map_ptr = nav_state.get_ptr<Costmap2D>("map.dynamic.filtered");
  if (!dynamic_map_ptr) return;
  Costmap2D & dynamic_map = *dynamic_map_ptr;

  nav_msgs::msg::OccupancyGrid::SharedPtr current_map_msg;
  {
    std::lock_guard<std::mutex> lock(map_mutex_);
    current_map_msg = last_map_;
  }

  if (current_map_msg) {
    unsigned int size_x = current_map_msg->info.width;
    unsigned int size_y = current_map_msg->info.height;
    double resolution = current_map_msg->info.resolution;
    double origin_x = current_map_msg->info.origin.position.x;
    double origin_y = current_map_msg->info.origin.position.y;

    // 1. Redimensionar
    if (dynamic_map.getSizeInCellsX() != size_x ||
        dynamic_map.getSizeInCellsY() != size_y ||
        dynamic_map.getResolution() != resolution ||
        dynamic_map.getOriginX() != origin_x ||
        dynamic_map.getOriginY() != origin_y) 
    {
       dynamic_map.resizeMap(size_x, size_y, resolution, origin_x, origin_y);
    }

    // 2. Copia Segura Fila a Fila
    auto& data = current_map_msg->data;
    unsigned int total_cells = size_x * size_y;

    if (data.size() >= total_cells) {
        for (unsigned int y = 0; y < size_y; ++y) {
            for (unsigned int x = 0; x < size_x; ++x) {
                unsigned int idx = x + (y * size_x);
                int value = data[idx];
                unsigned char cost = 0;

                if (value == 100) {
                    cost = 254; // Pared
                } else if (value == -1) {
                    cost = 255; // Desconocido (Transparente en costmap)
                } else if (value > 0) {
                     cost = static_cast<unsigned char>(1 + (252 * (value - 1)) / 98);
                }
                dynamic_map.setCost(x, y, cost);
            }
        }
    }
  }
}


}  // namespace easynav

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(easynav::ObstacleFilter, easynav::CostmapFilter)