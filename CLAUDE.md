# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Critical Constraints

**Do not write, modify, or delete any file without first proposing the change and receiving explicit confirmation from the user.** Your role here is educational: explain the system, propose snippets, and describe the logic. Only apply changes when the user explicitly approves.

---

## Build and Run

```bash
# Source ROS 2 Humble
source /opt/ros/humble/setup.bash

# Build entire workspace
cd /home/adri/tfg_ws && colcon build

# Source the workspace
source install/setup.bash

# Launch the full simulation stack
ros2 launch diablo_test robot_launch.py

# Build only the custom package (faster iteration)
colcon build --packages-select diablo_test
```

There is no test suite. Verification is done by launching the simulation and observing behavior in RViz2 and PlotJuggler via the `debug_monitor.py` utility.

```bash
# Manual teleop (priority 100 in twist_mux)
ros2 run teleop_twist_keyboard teleop_twist_keyboard --ros-args -r /cmd_vel:=/cmd_vel_key

# Send a navigation goal via CLI
ros2 action send_goal /navigate_to_pose easynav_interfaces/action/NavigateToPose \
  "{pose: {header: {frame_id: 'map'}, pose: {position: {x: 1.0, y: 0.5, z: 0.0}}}}"

# Monitor goal tracking errors for tuning
python3 /home/adri/tfg_ws/debug_monitor.py
```

---

## Architecture

```
Webots Simulator
    │
    ▼
diablo_driver (C++ node)
    │  Publishes: /scan (LaserScan), /odom, TF on /tf_garbage, /joint_states_webots
    │  Subscribes: /cmd_vel
    │
    ▼ (timestamps replaced with system clock — see "Time Bridge" below)
Bridges (Python, run as ExecuteProcess)
    ├── scan_bridge.py   → /scan_bridged (re-stamps to now())
    ├── odom_bridge.py   → TF odom→base_link (fresh stamps)
    └── joint_bridge.py  → /joint_states (fresh stamps)
    │
    ▼
SLAM Toolbox (async_slam_toolbox_node)
    │  Consumes /scan_bridged, publishes map→odom TF
    │
    ▼
EasyNav system_main
    │  Planner: CostmapPlanner (A* on 2D costmap)
    │  Controller: MPCController (5-step horizon)
    │  Maps Manager: CostmapMapsManager (obstacle + inflation filters)
    │  Localizer: AMCLLocalizer
    │  Publishes: /cmd_vel_nav
    │
    ▼
twist_mux
    │  /cmd_vel_key  (priority 100 — keyboard)
    │  /cmd_vel_nav  (priority 10  — EasyNav)
    └─→ /cmd_vel → diablo_driver
```

### Why `use_sim_time: false` everywhere

The Webots clock runs faster or slower than wall time during simulation. Setting `use_sim_time: false` in all nodes and using real (`rclcpp::Clock(RCL_SYSTEM_TIME)`) timestamps inside the bridges prevents SLAM Toolbox and EasyNav from rejecting messages as "stale" (their default tolerance is ~0.2–2 s). The driver publishes TFs on `/tf_garbage` (remapped in the launch file) specifically to suppress stale transform trees; the bridges republish fresh copies on the real `/tf`.

### Costmap configuration (`easynav_params.yaml`)

- **`robot_radius: 0.5 m`** — conservative footprint for costmap planning.
- **`inflation_radius: 0.7 m`, `inscribed_radius: 0.35 m`** — tune these when the robot hugs walls or refuses narrow passages.
- **`cost_scaling_factor: 8.0`** — higher = obstacles appear thinner; lower = wider safety bubble.
- **`CostmapMapsManager.topic: /map`** — costmap is built from the SLAM-generated occupancy grid, not raw sensor data.

### MPC controller (`easynav_params.yaml`)

- `horizon_steps: 5`, `dt: 0.1 s` → 0.5 s prediction window.
- `max_linear_velocity: 0.5 m/s`, `max_angular_velocity: 1.0 rad/s` — hard limits sent to twist_mux.
- `fallback_goal_pos_tol: 0.20 m`, `fallback_goal_yaw_tol: 0.50 rad` — when MPC fails, fallback P-controller uses these tolerances.

### Odometry

Differential drive: left/right wheel encoders (`left_j3_sensor`, `right_j3_sensor`).  
Constants in `diablo_driver.cpp`: `WHEEL_RADIUS = 0.10 m`, `TRACK_WIDTH = 0.5805 m` (tuned empirically against the Webots model — not the datasheet value).

### Static TF: `base_link → lidar_link`

The LiDAR is mounted 0.15 m above `base_link` and rotated 180° around Z (`3.1416 rad`) to align its scan direction with the robot forward axis. This is declared as a static publisher in the launch file.

---

## Key Files

| File | Purpose |
|---|---|
| `src/diablo_test/src/diablo_driver.cpp` | Core C++ Webots↔ROS2 interface |
| `src/diablo_test/src/bridges/scan_bridge.py` | Timestamp re-stamping for `/scan` |
| `src/diablo_test/src/bridges/odom_bridge.py` | Timestamp re-stamping for odometry TF |
| `src/diablo_test/launch/robot_launch.py` | Full stack launch orchestration |
| `src/diablo_test/config/easynav_params.yaml` | All navigation tuning parameters |
| `src/diablo_test/config/slam_localization.yaml` | SLAM Toolbox configuration |
| `src/diablo_test/config/mux_params.yaml` | twist_mux topic priorities |
| `src/diablo_test/worlds/diablo_robot.wbt` | Webots scene |
| `debug_monitor.py` | Goal error monitor for PlotJuggler |
| `cyclonedds_pc.xml` | DDS peer discovery (set `CYCLONEDDS_URI` env var to use) |

---

## Sim-to-Real Considerations

- **CPU/RAM on Raspberry Pi**: SLAM Toolbox and EasyNav together are heavy. On real hardware the SLAM node is replaced by a pre-built map + AMCL localization to reduce load.
- **Autobalancing**: The real Diablo manages balance internally at firmware level. In Webots there is no internal balance controller, so leg joints (`left_j1`, `left_j4`, `right_j1`, `right_j4`) are locked at zero position in the driver.
- **Husarnet P2P**: For remote deployment, `cyclonedds_pc.xml` configures DDS peer discovery over the Husarnet VPN. Set `export CYCLONEDDS_URI=file:///home/adri/tfg_ws/cyclonedds_pc.xml` before sourcing the workspace on both machines.
- **Unstructured environments**: The costmap pipeline assumes a static occupancy grid. In featureless or dynamic areas AMCL diverges — consider raising `transform_tolerance` and reducing `update_frequency` when operating outdoors.
