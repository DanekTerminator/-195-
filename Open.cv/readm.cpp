#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace cv;
using namespace std;
int main()
{
	int height = 400;
	int width = 800;
	Mat img(height, width, CV_8UC3);
	Point textOrg(100, img.rows / 2);
	int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
	double fontScale = 2;
	Scalar color(200, 100, 50);
	putText(img, "Denis Dyrak", textOrg, fontFace, fontScale, color);
	namedWindow("Hello World", 0);
	imshow("Hello World", img);
	Mat src_gray;
	Mat canny_output;

	cvtColor(img, src_gray, COLOR_RGB2GRAY);
	blur(src_gray, src_gray, Size(10, 10));


	double otsu_thresh_val = threshold(src_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU);
	
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5;
	cout << otsu_thresh_val;
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3);
	

	const char* source_grey_window = "Серое изображение";
	namedWindow(source_grey_window, WINDOW_AUTOSIZE);
	imshow(source_grey_window, canny_output);
	imwrite("canny_output.jpg", canny_output);
	
		RNG rng(12345); 
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0)); 

	vector<Moments>mu(contours.size()); 
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false); 
	}

	vector<Point2f>mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00); 
	}

	for (int i = 0; i < contours.size(); i++)
	{
		printf("Контур № %d: центр масс - x = %.2f y = %.2f; длина - %.2a \n", i, mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00, arcLength(contours[i], true)); 
	}
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3); 

	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)); 
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point()); 
		circle(drawing, mc[i], 4, color, -1, 5, 0); 
	}

	namedWindow("Contours", WINDOW_GUI_EXPANDED);
	imshow("Contours", drawing);


	
	
	waitKey(0);
	return(0);




}
