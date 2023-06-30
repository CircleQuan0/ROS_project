/***********************************************************************
Copyright 2020 GuYueHome (www.guyuehome.com).
***********************************************************************/

/** //发布请求
 * 该例程将请求/spawn服务，服务数据类型turtlesim::Spawn
 */

#include <ros/ros.h>
#include <turtlesim/Spawn.h> //包含数据类型头文件

int main(int argc, char** argv)
{
    // 初始化ROS节点
	ros::init(argc, argv, "turtle_spawn");

    // 创建节点句柄
	ros::NodeHandle node;

    
	ros::service::waitForService("/spawn");  //查询系统服务，是否存在spawn服务
	ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");
	//        创建客户端                                 数据类型         服务	
	// 发现/spawn服务后，创建一个服务客户端，连接名为/spawn的service	

    // 初始化turtlesim::Spawn的请求数据
	turtlesim::Spawn srv;
	srv.request.x = 2.0;
	srv.request.y = 2.0;
	srv.request.name = "turtle2";

    // 请求服务调用
	ROS_INFO("Call service to spawn turtle[x:%0.6f, y:%0.6f, name:%s]", 
			 srv.request.x, srv.request.y, srv.request.name.c_str());//日志

	add_turtle.call(srv);//调用请求方法    会等待反馈
   
	// 显示服务调用结果
	ROS_INFO("Spawn turtle successfully [name:%s]", srv.response.name.c_str());//反馈名字

	return 0;
}; 
