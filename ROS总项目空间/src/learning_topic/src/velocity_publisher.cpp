/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/**
 * 该例程将发布turtle1/cmd_vel话题，消息类型geometry_msgs::Twist
 */
 
#include <ros/ros.h> //包含ROS的相关功能函数及API接口
#include <geometry_msgs/Twist.h> //消息定义的头文件

int main(int argc, char **argv)
{
	// ROS节点初始化
	ros::init(argc, argv, "velocity_publisher");//必须完成初始化  第三个参数为节点的名称

	// 创建节点句柄
	ros::NodeHandle n; //管理API资源

	// 创建一个Publisher，发布名为/turtle1/cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10
	ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
	//定义一个发布者  				消息类型           被发布消息的话题名

	// 设置循环的频率
	ros::Rate loop_rate(10);   //类似 ——r 

	int count = 0;
	while (ros::ok())
	{
	    // 初始化geometry_msgs::Twist类型的消息
		geometry_msgs::Twist vel_msg; //创建对象
		vel_msg.linear.x = 0.5; //线速度
		vel_msg.angular.z = 0.2;//角速度

	    // 发布消息
		turtle_vel_pub.publish(vel_msg);//发布，方法，速度参数
		ROS_INFO("Publsh turtle velocity command[%0.2f m/s, %0.2f rad/s]",  //类似printf作为日志输出
				vel_msg.linear.x, vel_msg.angular.z);

	    // 按照循环频率延时
	    loop_rate.sleep();
	}

	return 0;
}
