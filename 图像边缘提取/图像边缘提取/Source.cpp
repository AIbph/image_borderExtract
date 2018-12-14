#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// ���Ӧ��-ͼ���Ե��ȡ	
	// ��ȡͼƬ
	Mat src = imread("D:/OpenCVProject/day1214/ͼ���Ե��ȡ/ͼ���Ե��ȡ/test.jpg");
	if(!src.data){
		printf("image could not load ");
		return -1;
	}
	imshow("origin image", src);

	// ��˹ģ��ת�Ҷ�ͼ
	Mat gray_src, dst;
	GaussianBlur(src, dst, Size(3, 3), 0);
	//imshow("��˹ģ�����ͼ��", dst);
	cvtColor(dst, gray_src, CV_RGB2GRAY);
	//imshow("ת�ҶȺ��ͼ��", gray_src);

	// Sobel�õ�x������ݶ�ͼ��
	Mat sob_x;
	Sobel(gray_src, sob_x, -1, 1, 0);
	imshow("x������ݶ�ͼ��", sob_x);

	// Sobel�õ�y������ݶ�ͼ��
	Mat sob_y;
	Sobel(gray_src, sob_y, -1, 0, 1);
	imshow("y������ݶ�ͼ��", sob_y);

	Mat test;
	addWeighted(sob_x, 0.5, sob_y, 0.5, 0, test);
	imshow("����ͼ���ݶ�", test);

	waitKey(0);
	return 0;
}