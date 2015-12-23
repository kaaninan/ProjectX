#include "ros/ros.h"
#include "std_msgs/Float64.h"

void callbackSicaklik(const std_msgs::Float64::ConstPtr& msg){
	ROS_INFO("Sicaklik: [%f]", msg->data);
}

int main(int argc, char **argv){
	ros::init(argc, argv, "arduino_sicaklik");
	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("topicArduinoSicaklik", 1000, callbackSicaklik);
	
	ros::spin();
	return 0;
}
