### 任务1（项目要求）：

##### 使用命令行窗口显示小车的IMU数据和里程计数据

学习bag文件数据播放，并显示其节点信息，通过读取节点信息完成数据提取显示。

使用rosbag info查看bag文件中具体的topic名称：

运行rosbag play all.bag

显示节点信息rosbag info all.bag

返回：

![image-20230622234817538](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230622234817538.png)

Ctrl + Alt + T 打开一个新的terminal或者在当前的terminal窗口使用Ctrl + Shift + T打开一个新的tab，订阅前述所说的/imu/data_raw，echo该topic的所有输出同时将其记录到一个指定的yaml文件中，以便日后查看。使用命令如下：
rostopic echo /imu/data_raw | tee imu_topic.yaml  

测试:

lyq@lyq-ubuntu-ROS:~$ rostopic echo /imu/data_raw | tee imutopic.yaml

返回：WARNING: topic [/imu/data_raw] does not appear to be published yet   (说明此时该节点信息未创建)

此时播放数据  rosbag play all.bag

重新输入：lyq@lyq-ubuntu-ROS:~$ rostopic echo /imu/data_raw | tee imutopic.yaml

数据开始读取：

![image-20230622234631234](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230622234631234.png)

![image-20230622234651738](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230622234651738.png)

显然成功读取到imu信息



此时读取里程计数据：

rostopic echo /odom | tee odom_topic.yaml  

开始读取：

![image-20230622235315425](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230622235315425.png)

读取到的odom文件：

![image-20230622235405358](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230622235405358.png)



为只播放目标topic，加快数据读取使用：

例：rosbag play --immediate demo.bag --topics /topic1 /topic2 /topic3 

rosbag play --immediate all.bag --topics /odom / /imu/data_raw

返回

![image-20230623001809300](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230623001809300.png)



进行保存：

运行：

rostopic echo /imu/data_raw | tee imutopic.yaml

rostopic echo /odom | tee odom_topic.yaml  

返回：

![image-20230623002306081](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230623002306081.png)









