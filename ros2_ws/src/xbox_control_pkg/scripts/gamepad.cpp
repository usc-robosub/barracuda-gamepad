#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"

using std::placeholders::_1;

class Gamepad : public rclcpp::Node
{
public:
    Gamepad()
    : Node("gamepad_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "/joy", 10, std::bind(&Gamepad::joy_callback, this, _1));
    }

private:
    void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
    {
        std::string pressed;
        for (size_t i = 0; i < msg->buttons.size(); ++i) {
            if (msg->buttons[i] == 1) pressed += std::to_string(i) + " ";
        }
        RCLCPP_INFO(this->get_logger(), "Buttons pressed: [%s]", pressed.c_str());
        
        std::string axes_str;
        for (size_t i = 0; i < msg->axes.size(); ++i) {
            axes_str += std::to_string(msg->axes[i]) + " ";
        }
        RCLCPP_INFO(this->get_logger(), "Axes: [%s]", axes_str.c_str());
    }

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Gamepad>());
    rclcpp::shutdown();
    return 0;
}
