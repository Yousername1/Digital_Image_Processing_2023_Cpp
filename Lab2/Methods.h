#pragma once

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat divideImg(const Mat& img, const int blockWidth, const int blockHeight);
void onMouce(int event, int x, int y, int, void*);
