#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

class Node3PubSub{
public:

	Node3PubSub(){
		node1Sub = node_obj.subscribe("/beyond_ping_pong", 10, &Node3PubSub::node1Callback, this);
		node2Sub = node_obj.subscribe("/beyond_3x_scaler", 10, &Node3PubSub::node2Callback, this);
		nodePub = node_obj.advertise<std_msgs::Int32>("/bool_receiver", 10);
	}

	void node1Callback(const std_msgs::Int32::ConstPtr& msg){
		msgFrom.data = 5*msg->data;
	}

	void node2Callback(const std_msgs::Int32::ConstPtr& msg){
		msgFrom.data -= msg->data/3;
		ROS_INFO("Received Node 3 (%d)", msgFrom.data);
		nodePub.publish(msgFrom);
	}

private:
	ros::NodeHandle node_obj;
	ros::Subscriber node1Sub;
	ros::Subscriber node2Sub;
	ros::Publisher nodePub;
	std_msgs::Int32 msgFrom;
};

int main(int argc, char **argv){

	ros::init(argc, argv, "x5_substract_by_node2");

	Node3PubSub node3PubSub;


	ros::spin();
	return 0;

}