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

	//double scaleUpX = 1.2;
	//double scaleUpY = 1.2;
	//double scaleDown = 0.6;
	//Mat scaled_f_up, scaled_f_down;
	//resize(histImg, scaled_f_up, Size(), scaleUpX, scaleUpY, INTER_LINEAR);

	bitwise_not(histImg, histImg);

	return histImg;
}

Mat getHistColor(const Mat& image)
{
	return Mat();
}

Mat doQuantization(const Mat& image, int q_level)
{
	Mat resultImage = Mat::zeros(image.rows, image.cols, CV_8UC1);
	int Y = 0;

	//q_level - number of quantization levels (2, 4 ... 64)
	int range = 255 / (q_level - 1);
	
	for (int i = 0; i <= image.rows - 1; i++) {
		for (int j = 0; j <= image.cols - 1; j++) {
			
			Y = image.at<uchar>(i, j);

			for (int level = 0; level <= range; level++) {
				if (Y > range * level && Y <= range * level + range / 2) {
					Y = range * level;
				}
				else if (Y > range * level + range / 2 && Y <= range * (level + 1)) {
					Y = range * (level + 1);
				}
			}

			resultImage.at<uchar>(i, j) = Y;
		}
	}

	imshow("Hist for quanti", getHist(resultImage));
	return resultImage;
}
