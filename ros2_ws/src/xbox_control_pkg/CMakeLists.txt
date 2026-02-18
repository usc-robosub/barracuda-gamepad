cmake_minimum_required(VERSION 3.5)
project(barracuda_gamepad)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(gamepad_node scripts/gamepad.cpp)

ament_target_dependencies(gamepad_node
  rclcpp
  sensor_msgs
  std_msgs
)

install(TARGETS
  gamepad_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()