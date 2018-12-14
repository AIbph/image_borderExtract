#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// 卷积应用-图像边缘提取	
	// 读取图片
	Mat src = imread("D:/OpenCVProject/day1214/图像边缘提取/图像边缘提取/test.jpg");
	if(!src.data){
		printf("image could not load ");
		return -1;
	}
	imshow("origin image", src);

	// 高斯模糊转灰度图
	Mat gray_src, dst;
	GaussianBlur(src, dst, Size(3, 3), 0);
	//imshow("高斯模糊后的图像", dst);
	cvtColor(dst, gray_src, CV_RGB2GRAY);
	//imshow("转灰度后的图像", gray_src);

	// Sobel得到x方向的梯度图像
	Mat sob_x;
	Sobel(gray_src, sob_x, -1, 1, 0);
	imshow("x方向的梯度图像", sob_x);

	// Sobel得到y方向的梯度图像
	Mat sob_y;
	Sobel(gray_src, sob_y, -1, 0, 1);
	imshow("y方向的梯度图像", sob_y);

	Mat test;
	addWeighted(sob_x, 0.5, sob_y, 0.5, 0, test);
	imshow("最终图像梯度", test);

	waitKey(0);
	return 0;
}