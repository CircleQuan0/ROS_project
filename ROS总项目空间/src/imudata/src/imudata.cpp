#include <iostream>
#include "ros/ros.h"
#include "sensor_msgs/Imu.h"

void callback(const sensor_msgs::Imu::ConstPtr& ptr)
{

    std::cout << "    num: " << ptr->header.seq << std::endl;
    std::cout << "    time: " << ptr->header.stamp << std::endl;
    std::cout << "   坐标系ID: " << ptr->header.frame_id << std::endl;
    std::cout << "方向" << std::endl;
    std::cout << "   x: " << ptr->orientation.x << std::endl;
    std::cout << "   y: " << ptr->orientation.y << std::endl;
    std::cout << "   z: " << ptr->orientation.z << std::endl;
    std::cout << "   w: " << ptr->orientation.w << std::endl;
    std::cout << "方向协方差" << std::endl;
    std::cout << "    ";
    for (int i = 0; i < 9; ++i) {
        std::cout << ptr->orientation_covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "角速度" << std::endl;
    std::cout << "   x: " << ptr->angular_velocity.x << std::endl;
    std::cout << "   y: " << ptr->angular_velocity.y << std::endl;
    std::cout << "   z: " << ptr->angular_velocity.z << std::endl;
    std::cout << "角速度协方差" << std::endl;
    std::cout << "    ";
    for (int i = 0; i < 9; ++i) {
        std::cout << ptr->angular_velocity_covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "线性加速度" << std::endl;
    std::cout << "   x: " << ptr->linear_acceleration.x << std::endl;
    std::cout << "   y: " << ptr->linear_acceleration.y << std::endl;
    std::cout << "   z: " << ptr->linear_acceleration.z << std::endl;
    std::cout << "线性加速度协方差" << std::endl;
    std::cout << "    ";
    for (int i = 0; i < 9; ++i) {
        std::cout << ptr->linear_acceleration_covariance[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "show_imu");
    ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber = nodeHandle.subscribe("/imu/data_raw", 1000, callback);
    ros::spin();
    return 0;
}
