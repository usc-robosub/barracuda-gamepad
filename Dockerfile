# Use the official ROS Noetic base image
FROM ros:noetic-ros-base-focal

# Install necessary packages
RUN apt-get update \
    && apt-get install -y --no-install-recommends git vim wget \
    ros-noetic-catkin \
    build-essential \
    && rm -rf /var/lib/apt/lists/* 


# Copy the entire project to the container
COPY . /opt/template-repo/


# Set the working directory
WORKDIR /opt

# Set the entrypoint
CMD ["/bin/bash", "/opt/template-repo/entrypoint.sh"]