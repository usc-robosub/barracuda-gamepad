# template-repo
Template repository to quickly create new Docker-based ROS repositories for USC RoboSub

This template provides a standardized Docker setup for ROS Noetic projects following USC RoboSub conventions.

## Features

- 🐳 **Docker containerization** with ROS Noetic base
- 🚀 **Docker Compose** for easy container management
- 🔧 **Pre-configured catkin workspace** ready for ROS packages
- 📦 **GitHub Actions** for automated Docker image publishing
- 🎯 **ARM64 support** for Jetson platforms
- 🔒 **SSH and Git integration** for private repositories

## Quick Start

### Prerequisites

- Docker and Docker Compose installed
- Git configured on your host machine

### Using this template

1. **Create a new repository** from this template on GitHub
2. **Clone your new repository**:
   ```bash
   git clone https://github.com/usc-robosub/your-repo-name.git
   cd your-repo-name
   ```

3. **Customize the template**:
   - Replace `template-repo` with your project name in:
     - `Dockerfile`
     - `docker-compose.yml`
     - `entrypoint.sh`
     - `.github/workflows/docker-publish.yml`

4. **Build and run**:
   ```bash
   docker-compose up --build
   ```

### Development Workflow

1. **Start the container**:
   ```bash
   docker-compose up -d
   ```

2. **Access the container**:
   ```bash
   docker exec -it template-repo bash
   ```

3. **Add your ROS packages** to `catkin_ws/src/`

4. **Build your workspace**:
   ```bash
   cd /opt/template-repo/catkin_ws
   catkin_make
   source devel/setup.bash
   ```

5. **Test with the example package**:
   ```bash
   # In one terminal (inside container):
   roscore
   
   # In another terminal (inside container):
   rosrun example_package example_node.py
   
   # Or use the launch file:
   roslaunch example_package example.launch
   ```

### Container Structure

```
/opt/template-repo/
├── catkin_ws/          # ROS workspace
│   ├── src/            # Your ROS packages go here
│   │   └── example_package/  # Example package (remove for actual projects)
│   ├── build/          # Build artifacts (gitignored)
│   └── devel/          # Development space (gitignored)
├── entrypoint.sh       # Container startup script
└── ...                 # Other project files
```

### Customization

When using this template for a new project:

1. **Update project name** in all configuration files
2. **Modify Dockerfile** to add project-specific dependencies
3. **Update entrypoint.sh** for custom initialization
4. **Configure docker-compose.yml** volumes and environment as needed

### GitHub Actions

The included workflow automatically builds and publishes Docker images to GitHub Container Registry when changes are pushed to the main branch. Images are built for ARM64 architecture (Jetson compatibility).

## Contributing

Follow USC RoboSub coding standards and ensure all changes are tested in the Docker environment before submitting pull requests.
