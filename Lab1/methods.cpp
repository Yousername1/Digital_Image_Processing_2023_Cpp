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

Mat getHistColor(const Mat& image)
{
	return Mat();
}

void errorCalculation(int Y, int Y_quanti, int rowS, int colS, int num_level)
{
	double sum = 0;
	for (int r = 0; r <= rowS - 1; r++) {
		for (int c = 0; c <= colS - 1; c++) {
			sum += pow((Y - Y_quanti), 2);
		}
	}
	double error = sqrt((1 / rowS * colS) * sum);
	double error_mid = num_level / sqrt(12);

	string result = to_string(error) + ", " + to_string(error_mid);

	map<int, string> errorsTable;
	errorsTable[num_level] = result;
	map<int, string> ::iterator it = errorsTable.begin();
	for (int i = 0; it != errorsTable.end(); it++) {
		cout << i << " level - " << it->first << " srkv, mid" << it->second << endl;
	}
}

Mat doQuantization(const Mat& image, int q_level)
{
	Mat resultImage = Mat::zeros(image.rows, image.cols, CV_8UC1);
	int Y = 0, Y_quanti = 0;

	//q_level - number of quantization levels (2, 4 ... 64)
	int range = 255 / (q_level - 1);
	
	for (int i = 0; i <= image.rows - 1; i++) {
		for (int j = 0; j <= image.cols - 1; j++) {
			
			Y = image.at<uchar>(i, j);

			for (int level = 0; level <= range; level++) {
				if (Y > range * level && Y <= range * level + range / 2) {
					Y_quanti = range * level;
				}
				else if (Y > range * level + range / 2 && Y <= range * (level + 1)) {
					Y_quanti = range * (level + 1);
				}
			}

			resultImage.at<uchar>(i, j) = Y_quanti;
		}
	}

	string hist_title = to_string(q_level);
	imshow(hist_title, getHist(resultImage));
	//getHist(resultImage);
	//errorCalculation(Y, Y_quanti, resultImage.rows, resultImage.cols, q_level);

	return resultImage;
}

