#include <iostream>
#include "ros/ros.h"
#include "nav_msgs/Odometry.h"

void callback(const nav_msgs::Odometry::ConstPtr& ptr)
{
    std::cout << "   num: " << ptr->header.seq << std::endl;
    std::cout << "    time: " << ptr->header.stamp << std::endl;
    std::cout << "    坐标系: " << ptr->header.frame_id << std::endl;
    std::cout << "  子坐标系: " << ptr->child_frame_id << std::endl;
    std::cout <<  std::endl;
    std::cout << " 位置" << std::endl;
    std::cout << "   x: " << ptr->pose.pose.position.x << std::endl;
    std::cout << "   y: " << ptr->pose.pose.position.y << std::endl;
    std::cout << "   z: " << ptr->pose.pose.position.z << std::endl;
    std::cout << " 方向" << std::endl;
    std::cout << "   x: " << ptr->pose.pose.orientation.x << std::endl;
    std::cout << "   y: " << ptr->pose.pose.orientation.y << std::endl;
    std::cout << "   z: " << ptr->pose.pose.orientation.z << std::endl;
    std::cout << "   w: " << ptr->pose.pose.orientation.w << std::endl;
    std::cout << std::endl;
    std::cout << "        ";
    for (int i = 0; i < 36; ++i) {
        std::cout << ptr->pose.covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << " 速度" << std::endl;
    std::cout << "  线速度" << std::endl;
    std::cout << "   x: " << ptr->twist.twist.linear.x << std::endl;
    std::cout << "   y: " << ptr->twist.twist.linear.y << std::endl;
    std::cout << "   z: " << ptr->twist.twist.linear.z << std::endl;
    std::cout << "  角速度" << std::endl;
    std::cout << "   x: " << ptr->twist.twist.angular.x << std::endl;
    std::cout << "   y: " << ptr->twist.twist.angular.y << std::endl;
    std::cout << "   z: " << ptr->twist.twist.angular.z << std::endl;
    std::cout << " 协方差" << std::endl;
    std::cout << "        ";
    for (int i = 0; i < 36; ++i) {
        std::cout << ptr->twist.covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "show_odometry");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("/odom", 1000, callback);
    ros::spin();
    return 0;
}
