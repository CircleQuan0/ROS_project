### 任务2：图形化界面显示RGB相机和深度相机数据（openCV库）

学习ROS1中openCV库：

安装资料：https://blog.csdn.net/qq_43706223/article/details/121767101

测试安装：

进入目录：~/opencv/src/opencv/samples/cpp/example_cmake 

键入代码：cmake .             make                  /opencv_example

返回：报错：

![image-20230623180156384](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230623180156384.png)

显然头文件包含错误，但现在还不会使用于是，利用cmake—gui进行链接操作

![image-20230623180310161](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230623180310161.png)

重新执行make 返回：

![image-20230623180349622](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230623180349622.png)

编译成功![image-20230623180404725](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230623180404725.png)

运行测试程序：./opencv_example

返回：![image-20230623180454833](C:\Users\LYQ\AppData\Roaming\Typora\typora-user-images\image-20230623180454833.png)

测试正常   /////////////OpenCV 下载运行成功



