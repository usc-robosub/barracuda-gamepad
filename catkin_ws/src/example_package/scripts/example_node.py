#!/usr/bin/env python3

"""
Example ROS node for the template-repo demonstration.

This node publishes a simple message to demonstrate the ROS setup.
"""

import rospy
from std_msgs.msg import String


def example_node():
    # Initialize the ROS node
    rospy.init_node('example_node', anonymous=True)
    
    # Create a publisher
    pub = rospy.Publisher('example_topic', String, queue_size=10)
    
    # Set the rate (10Hz)
    rate = rospy.Rate(10)
    
    rospy.loginfo("Example node started! Publishing to /example_topic")
    
    while not rospy.is_shutdown():
        # Create and publish a message
        msg = String()
        msg.data = f"Hello from template-repo! Time: {rospy.get_time()}"
        
        pub.publish(msg)
        rospy.loginfo(f"Published: {msg.data}")
        
        rate.sleep()


if __name__ == '__main__':
    try:
        example_node()
    except rospy.ROSInterruptException:
        rospy.loginfo("Example node shutdown")
        pass