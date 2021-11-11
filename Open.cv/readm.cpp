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

	cvtColor(img, src_gray, COLOR_RGB2GRAY); // перводит изображение в черно-белое
	blur(src_gray, src_gray, Size(10, 10)); //размывает изображение


	double otsu_thresh_val = threshold(src_gray, img, 0, 255, THRESH_BINARY | THRESH_OTSU); //определяет яркость серого изображения
	
	double high_thresh_val = otsu_thresh_val, lower_thresh_val = otsu_thresh_val * 0.5; //определяет максимумы и минимумы
	cout << otsu_thresh_val;
	Canny(src_gray, canny_output, lower_thresh_val, high_thresh_val, 3); // алгоритм для работы трехканальное изображение
	

	const char* source_grey_window = "Серое изображение";
	namedWindow(source_grey_window, WINDOW_AUTOSIZE);
	imshow(source_grey_window, canny_output);
	imwrite("canny_output.jpg", canny_output); //сохраняет и открывает обработанное изображение
	
		RNG rng(12345);  //задает рандомные цвета из диапозона ниже
	vector<vector<Point>>contours;
	vector<Vec4i>hierarchy;

	findContours(canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0)); 

	vector<Moments>mu(contours.size()); //создается вектор моментов, куда передается количество контуров, которое зависит от изображения
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false); //часть вектора передается в столбцы массива mu
	}

	vector<Point2f>mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00); // показывается x y векторы
	}

	for (int i = 0; i < contours.size(); i++)
	{
		printf("Контур № %d: центр масс - x = %.2f y = %.2f; длина - %.2a \n", i, mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00, arcLength(contours[i], true)); 
	}
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3); //CV_8UC3 - изображение без знака с 3 каналами

	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));  //указывает диапозон цвета, откуда будут браться случайные значения
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point()); //передается картинка, hierarchy - возвращает иерархию внешних контуров и отверстий. 
		circle(drawing, mc[i], 4, color, -1, 5, 0); //выбирается изображение, центр масс, 4 - радиус, цвета, толщина
	}

	namedWindow("Contours", WINDOW_GUI_EXPANDED);
	imshow("Contours", drawing);


	
	
	waitKey(0);
	return(0);




}
