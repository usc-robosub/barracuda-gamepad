cmake_minimum_required(VERSION 3.5)
project(barracuda-gamepad)

# Find dependencies
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(joy REQUIRED)
find_package(ament_cmake REQUIRED)

# Add executable
add_executable(joy_node src/joy/joy_linux_node.cpp)

ament_target_dependencies(joy rclcpp sensor_msgs std_msgs joy_node)

# Install
install(TARGETS joy_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()