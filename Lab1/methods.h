#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#pragma once

using namespace cv;
using namespace std;

Mat getHist(const Mat &image);
Mat getHistColor(const Mat& image);
Mat doQuantization(const Mat& image, int q_level);



