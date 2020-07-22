#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Bool.h"
#include <iostream>


void boolCallback(const std_msgs::Int32::ConstPtr& msg){
	std_msgs::Bool boolMsg;
	if(msg->data<5){
		boolMsg.data = true;
		ROS_INFO("Bool is %d", boolMsg.data);
	}
	else{
		boolMsg.data = false;
		ROS_INFO("Bool is %d", boolMsg.data);
	}

}

int main(int argc, char **argv){
	ros::init(argc, argv, "ping_pong_bool");

	ros::NodeHandle node_obj;
	ros::Subscriber nodeSub = node_obj.subscribe("/bool_receiver", 10, boolCallback);

	ros::spin();
	return 0;

}