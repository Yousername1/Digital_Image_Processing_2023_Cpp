#include "methods.h"

Mat getHist(const Mat &image)
{
	Mat hist = Mat::zeros(1, 256, CV_64FC1);

	for (int i = 0; i < image.cols; i++) {
		for (int j = 0; j < image.rows; j++) {
			int y = image.at<unsigned char>(j, i);
			hist.at<double>(0, y) += 1.0;
		}
	}

	double m = 0, M = 0;
	minMaxLoc(hist, &m, &M); //find global min and max
	hist = hist / M; //height normalization with max

	Mat histImg = Mat::zeros(100, 256, CV_8U);

	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 100; j++) {
			if (hist.at<double>(0, i) * 100 > j) {
				histImg.at<unsigned char>(99 - j, i) = 255;
			}
		}
	}

	bitwise_not(histImg, histImg);

	return histImg;
}
