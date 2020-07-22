#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

int main(int argc, char **argv){

	ros::init(argc, argv, "ping_pong_node");

	ros::NodeHandle node_obj;
	ros::Publisher node_1 = node_obj.advertise<std_msgs::Int32>("/beyond_ping_pong", 10);
	
	ros::Rate loop_rate(10);


	int ping_pong = 0;
	std_msgs::Int32 msg;

	while(ros::ok()){

		if(ping_pong < 10){
			while(ping_pong<10){
				msg.data=++ping_pong;
				ROS_INFO("%d", msg.data);
				node_1.publish(msg);
				ros::spinOnce();
				loop_rate.sleep();
			}
		}
		else{
			while(ping_pong>0){
				msg.data=--ping_pong;
				ROS_INFO("%d", msg.data);
				node_1.publish(msg);
				ros::spinOnce();
				loop_rate.sleep();
			}
		}


	}

	return 0;
}