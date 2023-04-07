#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>
#include <map>
#include <iomanip>

#pragma once

using namespace cv;
using namespace std;

Mat getHist(const Mat &image);
Mat getHistColor(const Mat& image);
Mat doQuantization(const Mat& image, int q_level);
double errorCalculation(double sum, const Mat& image);
map<int, double> makeRMStable(int key, double value);
void getRMStable(map<int, double> RMStable);
double estimationCalculation(int q_level);





