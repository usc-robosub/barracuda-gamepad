# # Use the official ROS Noetic base image
# FROM ros:noetic-ros-base-focal

# # Install necessary packages
# RUN apt-get update \
#     && apt-get install -y --no-install-recommends git vim wget \
#     ros-noetic-catkin \
#     build-essential \
#     && rm -rf /var/lib/apt/lists/* 


# # Copy the entire project to the container
# COPY . /opt/template-repo/


# # Set the working directory
# WORKDIR /opt

# # Set the entrypoint
# CMD ["/bin/bash", "/opt/template-repo/entrypoint.sh"]


# Use official ROS 2 base image
FROM osrf/ros:humble-desktop

# Install development tools
RUN apt-get update && apt-get install -y \
    # git \
    vim \
    wget \
    # python3-colcon-common-extensions \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Create workspace
WORKDIR /ros2_ws

# Copy your project into workspace src folder
COPY . /ros2_ws/src/

# Build workspace
RUN /bin/bash -c "source /opt/ros/humble/setup.bash && colcon build"

# Source ROS 2 automatically when container starts
CMD ["bash", "-c", "source /opt/ros/humble/setup.bash && source /ros2_ws/install/setup.bash && bash"]