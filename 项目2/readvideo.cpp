#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;



#define interval 4  //修改这里以改变多久保存一帧
int main()
{	
	VideoCapture capture("all_camera_color_image_raw.mp4");
	if (!capture.isOpened()){
		return -1;
	}
	int imgIndex = 0;

	Mat frame;
	capture >> frame;
	while (!frame.empty()) {

		string output = "./video/image/" + std::to_string(imgIndex) + ".jpg";

		if (imgIndex % interval == 0) {			
			//第一个参数是写入的文件名，第二个参数是Mat类型的图像数据。
			imwrite(output, frame);				
		}

		imgIndex++;
		capture >> frame;
	}
		
	return 0;
}