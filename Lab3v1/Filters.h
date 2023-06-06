#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
//#include <iomanip>

#pragma once

using namespace cv;
using namespace std;

class Filters
{
	public:
		Mat sourceImg;
		Mat workingImg;
		Mat biImg;
		Mat outputImg;

		void setImg(Mat sourceImg);
		Mat getImg();

		Mat gauss3(const Mat& inputImg);
		Mat gauss5(const Mat& inputImg);
		Mat ac(int depth, const Mat& inputImg);


	private:
		Mat makeBiImg(Mat inputImg);
};

