#!/bin/bash
source /opt/ros/noetic/setup.bash

# Build the catkin workspace
cd /opt/template-repo/catkin_ws
catkin_init_workspace src
catkin_make
source devel/setup.bash

# Source ROS and catkin workspace in bashrc
echo "source /opt/ros/noetic/setup.bash" >> ~/.bashrc
echo "source /opt/template-repo/catkin_ws/devel/setup.bash" >> ~/.bashrc

# Keep the container running with an interactive bash shell
echo "Template repo container is ready!"
echo "ROS Noetic workspace is set up at /opt/template-repo/catkin_ws"
echo ""
echo "Example package is available. Try these commands:"
echo "  rosrun example_package example_node.py"
echo "  roslaunch example_package example.launch"
echo ""
echo "Add your ROS packages to the src/ directory and rebuild with catkin_make"

# Start an interactive bash shell
exec /bin/bash