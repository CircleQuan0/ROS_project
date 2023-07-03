# 明月软件设计课程ROS数据展示作业

#### ***明月科创实验班  02班  刘又铨 20222349***

## 一.安装及测试ROS

### 1.测试ROS是否安装成功

CTRL+ALT+T打开终端（Termial），输入以下命令，初始化ROS环境：
roscore
rviz (图形化工具界面）
再 打开一个新的终端（Termial），输入以下命令，弹出一个小乌龟窗口：
rosrun turtlesim turtlesim_node
出现一个小乌龟的LOGO后，再 打开一个新的终端（Termial），输入以下命令:
rosrun turtlesim turtle_teleop_key
打开新的Termial，输入以下命令，可以查看ROS节点信息：
rosrun rqt_graph 

### 2.常用命令学习

rosnode  显示节点信息

![image-20230602223813938](图片库\image-20230602223813938.png)

列出节点   rosndoe  list

/rosout 采集日志信息的节点

rosnode info  /turtlesim  显示节点信息

rostopic  话题工具

rostopic  list 打印话题列表

利用某个话题去发布信息，进而传递给订阅者

rostopic  pub  /turtle/cmd_vel geometry_msgs/Txist "linear：

#### 用法

rostopic pub [话题名称] [消息类型] [参数]
Usage: rostopic pub /topic type [[args](https://so.csdn.net/so/search?q=args&spm=1001.2101.3001.7020)...]

#### 示例

rostopic pub -1 /cmd_vel geometry_msgs/Twist -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
每个选项的描述如下：

-1只发布一次消息(实际上只运行一次,但会像以前的结果一样运行3秒)。publishing and latching message for 3.0 seconds.

/cmd_vel 指定的话题名称

geometry_msgs/Twist 要发布的消息类型名称

-- ‘[2.0, 0.0, 0.0]’ ‘[0.0, 0.0, 1.0]’ 按照消息类型组织消息格式，这里是线速度为2.0m/s，角速度为1.0rad/s。-- 与 ''为可选的,可有可无。

查询消息结构
显示话题定义
rosmsg show geometry_msgs/Twist

![image-20230603100010900](图片库\image-20230603100010900.png)

### 3.海龟模拟器使用记录

rosservice  

#两只海龟画圈圈

打开Ros

roscore

打开小海龟

rosrun turtlesim turtlesim_node

打开小海龟键盘控制

rosrun turtlesim turtle_teleop_key

指令发布

#小海龟转圈圈，设置线速度和角速度，r设置每秒发送次数
rostopic pub -r 10 /turtle1/cmd_vel geometry_msgs/Twist "linear:
  x: 1.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 1.0"

创建新的小海龟

rosservice call /spawn "x: 3.0
y: 5.0
theta: 0.0
name: 'hello'"
1
2
3
4
新的小海龟转圈圈

rostopic pub -r 10 /hello/cmd_vel geometry_msgs/Twist "linear:
  x: 1.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 2.0"

可视化系统图

rqt_graph


显示节点列表

rosnode list


显示话题列表

rostopic list


显示话题定义

rosmsg show geometry_msgs/Twist


显示服务列表

记录话题
小海龟转圈

#-a表示 all，-o表示选择记录文件名
rosbag record -a -o cmd_record

-o压缩文件  后跟 文件名

话题复现

rosbag play cmd_record.bag

需打开海龟节点及ros

## 二.ROS基础学习

### （1）工作空间

![image-20230603104700601](图片库\image-20230603104700601.png)

#### 1.创建工作空间

mkdir catkin_ws创建workspace 文件夹

cd catkin_ws 进入

mkdir src 创建代码空间

cd  src 进入

catkin_init_workspace 将当前文件夹初始化为ROS工作空间 ，改变属性

#### 2.编译空工程

需回到根目录

cd.. 回到catkin_ws

pwd 查看当前位置

catkin_make 编译器指令

会产生build devel

install需要再一次

catkin_make install  如此四个文件夹创建完毕

#### 3.创建代码时，需要你同时创建功能包（ROS中放置源码的最小单元）

$catkin_create_pkg<功能包名字>[依赖1]【依赖2】...（这个功能包在编译时会依赖哪些功能包）

cd~/catkin_ws/src 进入源码空间  必须放置在SRC中

catkin_create_pkg  test_pkg std_msgs  rospy roscpp

​									名字     ros定义的标准数据结构   python c++接口

所有功能包内必须有 Cmakelist.txt  package.xml文件

#### 4.编译功能包

回到catkin_workspace

catkin_make

若要运行功能包内某一程序首先需要设置环境变量

source devel/setup.bash 设置

echo $ROS_PACKAGE_PATH 查看环境变量路径

### （2）话题模型

![image-20230603172656539](图片库\image-20230603172656539.png)

![image-20230603152655429](图片库\image-20230603152655429.png)



![image-20230603161033966](图片库\image-20230603161033966.png)



![image-20230603161109564](图片库\image-20230603161109564.png)



![image-20230603161155906](图片库\image-20230603161155906.png)

运行程序

![image-20230603161251067](图片库\image-20230603161251067.png)

位置：catkin_workspace/devel/lib/leaning——topic

#### 订阅者

同样创建程序文件在src中

![image-20230603170518720](图片库\image-20230603170518720.png)



![image-20230603170719540](图片库\image-20230603170719540.png)

如果ROS自带的消息类型，无法满足需求，则可以自己定义消息类型

#### 自定义消息类型

.![image-20230603173033022](图片库\image-20230603173033022.png)



#### 消息定义

创建msg文件   根据定义 去编译不同的语言文件  

设定编译规则

添加功能包依赖 动态生成程序



## （3）服务模型

![image-20230603182154050](图片库\image-20230603182154050.png)

![image-20230603191134953](图片库\image-20230603191134953.png)

![image-20230603191211958](图片库\image-20230603191211958.png)



#### 服务端编程实现

 ![image-20230603192750455](图片库\image-20230603192750455.png)



#### 观察trigger数据类型

![image-20230603194836296](图片库\image-20230603194836296.png)

#### camke完成编译

![image-20230604142147450](图片库\image-20230604142147450.png)

实际运行   rosservice call /turtle_command "{}"补全

#### 服务数据的定义和使用

![image-20230604155436655](图片库\image-20230604155436655.png)



![image-20230604163247969](图片库\image-20230604163247969.png)

![image-20230604163302633](图片库\image-20230604163302633.png)

![image-20230604163332820](图片库\image-20230604163332820.png)





## （4）参数

### 参数模型

![image-20230604164818993](图片库\image-20230604164818993.png)





# 任务1（项目要求）：

### 使用命令行窗口显示小车的IMU数据和里程计数据

学习bag文件数据播放，并显示其节点信息，通过读取节点信息完成数据提取显示。

#### 1.使用rosbag info查看bag文件中具体的topic名称：

运行rosbag play all.bag

显示节点信息rosbag info all.bag

返回：

![image-20230622234817538](图片库\image-20230622234817538.png)

Ctrl + Alt + T 打开一个新的terminal或者在当前的terminal窗口使用Ctrl + Shift + T打开一个新的tab，订阅前述所说的/imu/data_raw，echo该topic的所有输出同时将其记录到一个指定的yaml文件中，以便日后查看。使用命令如下：
rostopic echo /imu/data_raw | tee imu_topic.yaml  

#### 测试:

lyq@lyq-ubuntu-ROS:~$ rostopic echo /imu/data_raw | tee imutopic.yaml

返回：WARNING: topic [/imu/data_raw] does not appear to be published yet   (说明此时该节点信息未创建)

此时播放数据  rosbag play all.bag

重新输入：lyq@lyq-ubuntu-ROS:~$ rostopic echo /imu/data_raw | tee imutopic.yaml

#### 数据开始读取：

![image-20230622234631234](图片库\image-20230622234631234.png)

![image-20230622234651738](图片库\image-20230622234651738.png)

显然成功读取到imu信息



#### 2.读取里程计数据：

rostopic echo /odom | tee odom_topic.yaml  

#### 开始读取：

![image-20230622235315425](图片库\image-20230622235315425.png)

#### 读取到的odom文件：

![image-20230622235405358](图片库\image-20230622235405358.png)

### 使用ROS发布订阅话题模型实现imu 与 里程计数据接收

创建功能包imudata   odom

![image-20230703114906838](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703114906838.png)

![image-20230703114919175](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703114919175.png)

### 编写C++程序imu话题订阅程序

![image-20230703115030802](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115030802.png)

### 在CmakeList中链接库和功能包

![image-20230703115124677](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115124677.png)

![image-20230703115138772](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115138772.png)

### 里程计C++程序编写

![image-20230703115252172](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115252172.png)

### Cmakelist 链接库及源文件

![image-20230703115339691](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115339691.png)

![image-20230703115355547](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115355547.png)

### catkin_make 编译

![image-20230703115503966](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115503966.png)

### 运行功能包

![image-20230703115545380](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115545380.png)

实现数据读取



# 任务2：图形化界面显示RGB相机和深度相机数据openCV

### 1.学习ROS1中openCV库：

安装资料：https://blog.csdn.net/qq_43706223/article/details/121767101

#### 测试安装：

进入目录：~/opencv/src/opencv/samples/cpp/example_cmake 

键入代码：cmake .             make                  /opencv_example

#### 返回：报错：

![image-20230623180156384](H:\Code_data\ROS_project\ros_learning\图片库\image-20230623180156384.png)

显然头文件包含错误，但现在还不会使用于是，利用cmake—gui进行链接操作

![image-20230623180310161](H:\Code_data\ROS_project\ros_learning\图片库\image-20230623180310161.png)

#### 重新执行make 返回：

![image-20230623180349622](H:\Code_data\ROS_project\ros_learning\图片库\image-20230623180349622.png)

#### 编译成功![image-20230623180404725](H:\Code_data\ROS_project\ros_learning\图片库\image-20230623180404725.png)

运行测试程序：./opencv_example

#### 返回：![image-20230623180454833](H:\Code_data\ROS_project\ros_learning\图片库\image-20230623180454833.png)

测试正常   /////////////OpenCV 下载运行成功

## 2.读取深度相机数据

#### 创建功能包

![image-20230703115750565](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115750565.png)

![image-20230703115811636](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115811636.png)

#### 编写RGBcamera的C++程序，订阅话题，同时使用opencv的api进行数据可视化

![image-20230703115922181](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115922181.png)

#### cmakelist

![image-20230703115958078](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703115958078.png)

![image-20230703120008032](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120008032.png)

#### 编译后执行 rosrun RGBcamera RGBcamera

![image-20230703120725216](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120725216.png)

### 2.深度相机C++程序编写

![image-20230703120047401](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120047401.png)

#### cmakelist

![image-20230703120114455](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120114455.png)

![image-20230703120127909](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120127909.png)

#### 编译后运行功能包

![image-20230703120803559](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120803559.png)



为更加直观的观看数据，我通过网络教程将bag包中的数据转完成了mp4文件

![image-20230703120309724](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120309724.png)

#### 视频提取实现方法：

python rosbag2video.py [--fps 25] [--rate 1] [-o outputfile] [-v] [-s] [-t topic] bagfile1 [bagfile2] ...

[–fps] ：设置传递给ffmpeg的帧率，默认为25；
[-h]：显示帮助；
[–ofile]：设置输出文件名；
[–rate]：放慢或加快视频。默认值是1.0，保持原来的速度；
[-s]：显示从rosbag文件提取的每个图像；
[–topic]：仅来自“topic”的图像用于视频输出；
[-v]：显示详细消息；
[–prefix]：设置输出文件名前缀，否则使用“ bagfile1”（如果未设置-o）；
[–start]：可选的开始时间（以秒为单位）；
[–end]：可选结束时间，单位为秒；
原文链接：https://blog.csdn.net/wangmj_hdu/article/details/114130648

运行python rosbag2video.py all.bag

### 实现提取：

![image-20230703120412100](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120412100.png)

![image-20230703120431167](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120431167.png)



# 任务三

###  点云数据提取用图形界面显示激光雷达的点云数据（plc库）

#### 解析.bag文件到.pcd[点云](https://so.csdn.net/so/search?q=点云&spm=1001.2101.3001.7020)数据文件

rosrun pcl_ros bag_to_pcd all.bag /rslidar_points pointcloud_pcd/

#### 执行后成功提取

![image-20230703120538952](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120538952.png)

#### 安装PCD viewer

sudo apt install pcl-tools

显示pcl_viewer pointcloud_pcd/1668162552.727140903.pcd

![image-20230703120620255](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120620255.png)

### 通过话题模型读取

#### 创建功能包

![image-20230703120859040](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120859040.png)

#### 编写C++程序，使用pcl库

![image-20230703120919705](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703120919705.png)

#### cmakelist

![image-20230703121000514](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703121000514.png)

![image-20230703121010643](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703121010643.png)

#### 运行功能包

#### 实现实时点云数据可视

![image-20230703121059328](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230703121059328.png)

#### 





































