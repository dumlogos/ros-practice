#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>

class PingPongSubscribeAndPublish{
public:
	PingPongSubscribeAndPublish(){
		node2Pub = node_obj.advertise<std_msgs::Int32>("/beyond_3x_scaler", 10);
		node2Sub = node_obj.subscribe("/beyond_ping_pong", 10, &PingPongSubscribeAndPublish::pingPongCallbackOne, this);
	}

	void pingPongCallbackOne(const std_msgs::Int32::ConstPtr& msg) {
		int pingPongScaled3x=msg->data*3;
		std_msgs::Int32 tmpmsg;

		tmpmsg.data = pingPongScaled3x;
		ROS_INFO("Received Node 2 (%d)", tmpmsg.data);

		node2Pub.publish(tmpmsg);
	}    

private:
	ros::NodeHandle node_obj;
	ros::Subscriber node2Sub;
	ros::Publisher node2Pub;
};

int main(int argc, char **argv){

	ros::init(argc, argv, "ping_pong_3x_scaler");
	PingPongSubscribeAndPublish pingPong;

	ros::spin();
	return 0;

}