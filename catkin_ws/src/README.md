# Template Repo Source Directory

This directory is where you should place your ROS packages.

## Adding a new package

1. Create your ROS package in this directory:
   ```bash
   cd /opt/template-repo/catkin_ws/src
   catkin_create_pkg your_package_name rospy roscpp std_msgs
   ```

2. Rebuild the workspace:
   ```bash
   cd /opt/template-repo/catkin_ws
   catkin_make
   source devel/setup.bash
   ```

3. Your package will now be available in the ROS environment.

## Example structure

```
src/
├── your_package_name/
│   ├── CMakeLists.txt
│   ├── package.xml
│   ├── src/
│   ├── scripts/
│   └── launch/
└── README.md (this file)
```