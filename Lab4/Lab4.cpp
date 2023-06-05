#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>
#include "windows.h"

using namespace std;
using namespace cv;

Mat img = imread("../image1.jpg");

void bin_er(const Mat& input_img, Mat& output_img) {
	output_img = input_img.clone();
	for (int i = 1; i < input_img.rows - 1; i++)
		for (int j = 1; j < input_img.cols - 1; j++) {
			int cnt = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					if (input_img.at<uchar>(i - ii, j - jj) == 0)
						cnt++;
				}
			if (cnt > 0)
				output_img.at<uchar>(i, j) = 0;
		}
}

void bin_dil(const Mat& input_img, Mat& output_img) {
	output_img = input_img.clone();
	for (int i = 1; i < input_img.rows - 1; i++)
		for (int j = 1; j < input_img.cols - 1; j++) {
			int cnt = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					if (input_img.at<uchar>(i - ii, j - jj) == 255)
						cnt++;
				}
			if (cnt > 0)
				output_img.at<uchar>(i, j) = 255;
		}
}

void ht_er(const Mat& input_img, Mat& output_img) {
	output_img = Mat::zeros(input_img.size(), CV_8U);
	for (int i = 1; i < input_img.rows - 1; i++)
		for (int j = 1; j < input_img.cols - 1; j++) {
			float min = 255;
			uchar pix_value = input_img.at<uchar>(i, j);
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar Y = input_img.at<uchar>(i - ii, j - jj);
					if (Y < min) min = Y;
				}
			output_img.at<uchar>(i, j) = min;
		}
}

void ht_dil(const Mat& input_img, Mat& output_img) {
	output_img = Mat::zeros(input_img.size(), CV_8U);
	for (int i = 1; i < input_img.rows - 1; i++)
		for (int j = 1; j < input_img.cols - 1; j++) {
			float max = 0;
			uchar pix_value = input_img.at<uchar>(i, j);
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar Y = input_img.at<uchar>(i - ii, j - jj);
					if (Y > max) max = Y;
				}
			output_img.at<uchar>(i, j) = max;
		}
}

void fcontour(const Mat& input_img, Mat& output_img, int n) {
	int cycle = 0;
	output_img = Mat::zeros(input_img.size(), CV_8U);
	Mat prep = input_img.clone();
	while (cycle < n) {
		for (int i = 1; i < prep.rows - 1; i++)
			for (int j = 1; j < prep.cols - 1; j++) {
				float min = 255;
				uchar pix_value = prep.at<uchar>(i, j);
				for (int ii = -1; ii <= 1; ii++)
					for (int jj = -1; jj <= 1; jj++) {
						uchar Y = prep.at<uchar>(i - ii, j - jj);
						if (Y < min) min = Y;
					}
				output_img.at<uchar>(i, j) = min;
			}
		prep = output_img.clone();
		cycle++;
	}
	subtract(input_img, prep, output_img);
}

void fcontoursym(const Mat& input_img, Mat& output_img, int n) {
	int cycle = 0;
	Mat res_1 = Mat::zeros(input_img.size(), CV_8U);
	Mat prep1 = input_img.clone();

	while (cycle < n) {
		for (int i = 1; i < prep1.rows - 1; i++)
			for (int j = 1; j < prep1.cols - 1; j++) {
				float min = 255;
				uchar pix_value = prep1.at<uchar>(i, j);
				for (int ii = -1; ii <= 1; ii++)
					for (int jj = -1; jj <= 1; jj++) {
						uchar Y = prep1.at<uchar>(i - ii, j - jj);
						if (Y < min) min = Y;
					}
				res_1.at<uchar>(i, j) = min;
			}
		prep1 = res_1.clone();
		cycle++;
	}

	cycle = 0;
	Mat res_2 = Mat::zeros(input_img.size(), CV_8U);
	Mat prep2 = input_img.clone();

	while (cycle < n) {
		for (int i = 1; i < prep2.rows - 1; i++)
			for (int j = 1; j < prep2.cols - 1; j++) {
				float max = 0;
				uchar pix_value = prep2.at<uchar>(i, j);
				for (int ii = -1; ii <= 1; ii++)
					for (int jj = -1; jj <= 1; jj++) {
						uchar Y = prep2.at<uchar>(i - ii, j - jj);
						if (Y > max) max = Y;
					}
				res_2.at<uchar>(i, j) = max;
			}
		prep2 = res_2.clone();
		cycle++;
	}

	subtract(prep2, prep1, output_img);
}

void morph(const Mat& input_img, Mat output_img) {
	Mat prep1 = Mat::zeros(input_img.size(), CV_8U);
	for (int i = 1; i < input_img.cols - 1; i++)
		for (int j = 1; j < input_img.rows - 1; j++) {
			float max = 0;
			float min = 255;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar Y_min = input_img.at<uchar>(j + jj, i + ii);
					uchar Y_max = input_img.at<uchar>(j + jj, i + ii);

					if (Y_max > max)
						max = Y_max;

					if (Y_min < min)
						min = Y_min;
				}
			prep1.at<uchar>(j, i) = (max - min);
		}

	Mat prep2 = Mat::zeros(input_img.size(), CV_8U);
	for (int i = 2; i < input_img.cols - 2; i++)
		for (int j = 2; j < input_img.rows - 2; j++) {
			float max = 0;
			float min = 255;
			for (int ii = -2; ii <= 2; ii++)
				for (int jj = -2; jj <= 2; jj++) {
					uchar Y_min = input_img.at<uchar>(j + jj, i + ii);
					uchar Y_max = input_img.at<uchar>(j + jj, i + ii);

					if (Y_max > max)
						max = Y_max;

					if (Y_min < min)
						min = Y_min;
				}
			prep2.at<uchar>(j, i) = (max - min);
		}
	Mat prep21 = Mat::zeros(prep2.size(), CV_8U);
	for (int i = 1; i < prep2.cols - 1; i++)
		for (int j = 1; j < prep2.rows - 1; j++) {
			float min = 255;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar Y = prep2.at<uchar>(j + jj, i + ii);
					if (Y < min)
						min = Y;
				}
			prep21.at<uchar>(j, i) = min;
		}

	Mat prep3 = Mat::zeros(input_img.size(), CV_8U);
	for (int i = 3; i < input_img.cols - 3; i++)
		for (int j = 3; j < input_img.rows - 3; j++) {
			float max = 0;
			float min = 255;
			for (int ii = -3; ii <= 3; ii++)
				for (int jj = -3; jj <= 3; jj++) {
					uchar Y_min = input_img.at<uchar>(j + jj, i + ii);
					uchar Y_max = input_img.at<uchar>(j + jj, i + ii);

					if (Y_max > max)
						max = Y_max;

					if (Y_min < min)
						min = Y_min;
				}
			prep3.at<uchar>(j, i) = (max - min);
		}

	Mat prep31 = Mat::zeros(prep3.size(), CV_8U);
	for (int i = 2; i < prep3.cols - 2; i++)
		for (int j = 2; j < prep3.rows - 2; j++) {
			float min = 255;
			for (int ii = -2; ii <= 2; ii++)
				for (int jj = -2; jj <= 2; jj++) {
					uchar Y = prep3.at<uchar>(j + jj, i + ii);
					if (Y < min)
						min = Y;
				}
			prep31.at<uchar>(j, i) = min;
		}

	Mat prep1f;
	prep1.convertTo(prep1f, CV_64F);
	Mat prep2f;
	prep21.convertTo(prep2f, CV_64F);
	Mat prep3f;
	prep31.convertTo(prep3f, CV_64F);
	Mat SUM;
	SUM = prep1f + prep2f + prep3f;
	SUM = SUM / 3;
	SUM.convertTo(output_img, CV_8U);
}

int main() {
	Mat htimg = Mat::zeros(img.size(), CV_8UC1);
	Mat binimg = Mat::zeros(img.size(), CV_8UC1);

	Mat bineroded = Mat::zeros(img.size(), CV_8UC1);
	Mat bindilated = Mat::zeros(img.size(), CV_8UC1);
	Mat binopened = Mat::zeros(img.size(), CV_8UC1);
	Mat binclosed = Mat::zeros(img.size(), CV_8UC1);

	Mat hteroded = Mat::zeros(img.size(), CV_8UC1);
	Mat htdilated = Mat::zeros(img.size(), CV_8UC1);
	Mat htopened = Mat::zeros(img.size(), CV_8UC1);
	Mat htclosed = Mat::zeros(img.size(), CV_8UC1);
	Mat htcontours = Mat::zeros(img.size(), CV_8UC1);
	Mat htcontourssym = Mat::zeros(img.size(), CV_8UC1);
	Mat htmorphed = Mat::zeros(img.size(), CV_8UC1);

	int N = 3;

	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++) {
			htimg.at<uchar>(i, j) = 0.11 * img.at<Vec3b>(i, j)[0] + 0.53 * img.at<Vec3b>(i, j)[1] + 0.36 * img.at<Vec3b>(i, j)[2];
		}

	imshow("Halftoned img", htimg);

	for (int i = 0; i < binimg.rows; i++)
		for (int j = 0; j < binimg.cols; j++) {
			if (htimg.at<uchar>(i, j) > 125)
				binimg.at<uchar>(i, j) = 255;
			else binimg.at<uchar>(i, j) = 0;
		}

	imshow("Bynary img", binimg);
	waitKey();

	fcontour(htimg, htcontours, N);
	imshow("Find conturs", htcontours);
	waitKey();

	fcontoursym(htimg, htcontourssym, N);
	imshow("Find conturs 2", htcontourssym);
	waitKey();

	morph(htimg, htmorphed);
	imshow("Scale morphological gradient", htmorphed);
	waitKey();

	bin_er(binimg, bineroded);
	imshow("Bynary erosion", bineroded);
	waitKey();

	bin_dil(binimg, bindilated);
	imshow("Bynary dilatation", bindilated);
	waitKey();

	bin_dil(bineroded, binopened);
	imshow("Bynary opening", binopened);
	waitKey();

	bin_er(bindilated, binclosed);
	imshow("Bynary closing", binclosed);
	waitKey();
	destroyAllWindows();

	ht_er(htimg, hteroded);
	imshow("Halftoned erosion", hteroded);
	waitKey();

	ht_dil(htimg, htdilated);
	imshow("Halftoned dilatation", htdilated);
	waitKey();

	ht_dil(hteroded, htopened);
	imshow("Halftoned opening", htopened);
	waitKey();

	ht_er(htdilated, htclosed);
	imshow("Halftoned closing", htclosed);
	waitKey();

	return 0;
}
