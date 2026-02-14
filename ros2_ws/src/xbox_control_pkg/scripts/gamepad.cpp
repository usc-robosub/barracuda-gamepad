#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/joy.hpp"

using namespace std::chrono_literals;

class JoyPublisherNode : public rclcpp::Node
{
public:
    JoyPublisherNode()
    : Node("joy_publisher_node")
    {
        // Publisher to a string topic (similar to your Python example)
        example_pub_ = this->create_publisher<std_msgs::msg::String>("example_topic", 10);

        // Subscriber to joystick topic
        joy_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "/joy",
            10,
            std::bind(&JoyPublisherNode::joy_callback, this, std::placeholders::_1)
        );

        // Timer to periodically publish example messages
        timer_ = this->create_wall_timer(
            100ms, std::bind(&JoyPublisherNode::timer_callback, this)
        );

        RCLCPP_INFO(this->get_logger(), "JoyPublisherNode started!");
    }

private:
    void timer_callback()
    {
        auto msg = std_msgs::msg::String();
        msg.data = "Hello from ROS 2! Time: " + std::to_string(this->now().seconds());
        example_pub_->publish(msg);
        RCLCPP_INFO(this->get_logger(), "Published: '%s'", msg.data.c_str());
    }

    void joy_callback(const sensor_msgs::msg::Joy::SharedPtr joy_msg)
    {
        // Print first joystick axis and button as a demo
        if (!joy_msg->axes.empty() && !joy_msg->buttons.empty())
        {
            RCLCPP_INFO(this->get_logger(),
                        "Joy axes[0]: %f, buttons[0]: %d",
                        joy_msg->axes[0], joy_msg->buttons[0]);
        }
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr example_pub_;
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JoyPublisherNode>());
    rclcpp::shutdown();
    return 0;
}
