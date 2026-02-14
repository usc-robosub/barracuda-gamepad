# Example Package

This is an example ROS package to demonstrate the template structure. 

## Usage

This package will be built automatically when the container starts. To use it:

1. Start the container: `docker compose up -d`
2. Access the container: `docker exec -it template-repo bash`
3. The workspace will be pre-built and sourced
4. Run: `rosrun example_package example_node` (when implemented)

## Files

- `package.xml` - Package metadata
- `CMakeLists.txt` - Build configuration
- `src/` - C++ source files
- `scripts/` - Python scripts
- `launch/` - Launch files