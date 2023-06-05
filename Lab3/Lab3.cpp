#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;

Mat img = imread("../image1.jpg");

void gauss3(const Mat& imgin, Mat& imgout) {
	imgout = Mat::zeros(imgin.size(), CV_8U);
	float k = 36;
	float Fk[3][3] = { { 1,4,1 },{ 4,16,4 },{ 1,4,1 } };

	for (int i = 1; i < imgin.cols - 1; i++)
		for (int j = 1; j < imgin.rows - 1; j++) {
			float conv = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar blurred = imgin.at<uchar>(j + jj, i + ii);
					conv += Fk[ii + 1][jj + 1] * blurred;
				}
			uchar blurred = conv / k;
			imgout.at<uchar>(j, i) = blurred;
		}
}

void gauss5(const Mat& imgin, Mat& imgout) {
	imgout = Mat::zeros(imgin.size(), CV_8U);
	float k = 256;
	float Fk[5][5] = { { 1,4,6,4,1 },{ 4,16,24,16,4 },{ 6,16,36,24,6 },{ 4,16,24,16,4 },{ 1,4,6,4,1 } };
	for (int i = 2; i < imgin.cols - 2; i++)
		for (int j = 2; j < imgin.rows - 2; j++) {
			float conv = 0;
			for (int ii = -2; ii <= 2; ii++)
				for (int jj = -2; jj <= 2; jj++) {
					uchar blurred = imgin.at<uchar>(j + jj, i + ii);
					conv += Fk[ii + 2][jj + 2] * blurred;
				}
			uchar blurred = conv / k;
			imgout.at<uchar>(j, i) = blurred;
		}
}

void ac3(int S, const Mat& imgin, Mat& imgout) {
	imgout = imgin.clone();
	int X = (100 / S - 1) + 8; // вычисление коэффициента центрального эл-та маски
	float k = X - 8; // коэффициент нормировки
	float Fk[3][3] = { { -1,-1,-1 },{ -1,X,-1 },{ -1,-1,-1 } };

	for (int i = 1; i < imgin.cols - 1; i++)
		for (int j = 1; j < imgin.rows - 1; j++) {
			float conv = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar aced = imgin.at<uchar>(j + jj, i + ii);
					conv += Fk[ii + 1][jj + 1] * aced;
				}
			int aced = conv / k;
			// uchar aced = conv / k;
			if (aced > 255)
				imgout.at<uchar>(j, i) = 255;
			else {
				uchar uaced = aced;
				imgout.at<uchar>(j, i) = uaced;
			}
		}
}

void mos3(const Mat& imgin, Mat& imgout) {
	for (int i = 1; i < imgin.cols - 2; i += 3)
		for (int j = 1; j < imgin.rows - 2; j += 3) {
			// поиск среднего арифметического значения яркости элементов под маской
			double avg = 0;
			for (int ii = 0; ii <= 2; ii++) {
				for (int jj = 0; jj <= 2; jj++) {
					avg = imgin.at<uchar>(j + jj, i + ii) + avg;
				}
			}
			avg = avg / 9;
			for (int ii = 0; ii <= 2; ii++) {
				for (int jj = 0; jj <= 2; jj++) {
					imgout.at<uchar>(j + jj, i + ii) = avg;
				}
			}

		}
}

void med3(const Mat& imgin, Mat& imgout) {
	imgout = Mat::zeros(imgin.size(), CV_8U);
	Mat blurred = Mat::zeros(1, 9, CV_8U);
	Mat blurred1 = Mat::zeros(1, 9, CV_8U);
	for (int i = 1; i < imgin.cols - 1; i++)
		for (int j = 1; j < imgin.rows - 1; j++)
		{
			// далее производим свертку
			float Rez = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++)
				{
					blurred.at<uchar>(0, (ii + 1) * 3 + jj + 1) = imgin.at<uchar>(j + jj, i + ii);
				}
			sort(blurred, blurred1, SORT_EVERY_ROW);
			unsigned char Med = blurred1.at<uchar>(0, 4);
			imgout.at<uchar>(j, i) = Med;
		}
	imshow("Mediana", imgout);
}

void sobel_(const Mat& imgin, Mat& imgout) {
	float k = 20;
	float Gy[3][3] = { { -1,-2,-1 },{ 0,0,0 },{ 1,2,1 } }; // маски оператора Собела (OpenCV docs)
	float Gx[3][3] = { {-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1} };
	double sobeled_max = 0;
	for (int i = 1; i < imgin.cols - 1; i++)
		for (int j = 1; j < imgin.rows - 1; j++) {
			float convy = 0, convx = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar sobeled = imgin.at<uchar>(j + jj, i + ii);
					convy += Gy[ii + 1][jj + 1] * sobeled;
					convx += Gx[ii + 1][jj + 1] * sobeled;
				}
			float sobeledy = convy / k;
			float sobeledx = convx / k;
			uchar sobeled = sqrt(pow(sobeledx, 2) + pow(sobeledy, 2));
			imgout.at<uchar>(j, i) = sobeled;
		}
}


int main() {
	// перевод в ЧБ
	Mat bwimg = Mat::zeros(img.size(), CV_8UC1);
	Mat filtered = Mat::zeros(img.size(), CV_8UC1);
	Mat filtered2 = Mat::zeros(img.size(), CV_8UC1);
	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++) {
			bwimg.at<uchar>(i, j) = 0.11 * img.at<Vec3b>(i, j)[0] + 0.53 * img.at<Vec3b>(i, j)[1] + 0.36 * img.at<Vec3b>(i, j)[2];
		}

	int S = 50; // глубина коррекции
	Mat acimg = Mat::zeros(bwimg.size(), CV_8UC1);
	ac3(S, bwimg, acimg);
	imshow("Apperturnaya correctciya", acimg);
	waitKey();

	Mat medfimg = Mat::zeros(bwimg.size(), CV_8UC1);
	med3(bwimg, medfimg);
	imshow("Madiana", medfimg);
	waitKey();

	destroyAllWindows();
	Mat gaussdiff = Mat::zeros(img.size(), CV_8UC1);
	absdiff(filtered2, filtered, gaussdiff);
	imshow("Gaussian difference", gaussdiff * 3);
	waitKey();

	Mat cannyimg = Mat::zeros(bwimg.size(), CV_8UC1);
	Canny(bwimg, cannyimg, 120, 160);
	imshow("Canny", cannyimg);
	waitKey();

	Mat cont = imread("../image1.jpg");
	Mat bwcont = Mat::zeros(cont.size(), CV_8UC1);
	for (int i = 0; i < cont.rows; i++)
		for (int j = 0; j < cont.cols; j++) {
			bwcont.at<uchar>(i, j) = 0.11 * cont.at<Vec3b>(i, j)[0] + 0.53 * cont.at<Vec3b>(i, j)[1] + 0.36 * cont.at<Vec3b>(i, j)[2];
		}
	Mat sobelimg = Mat::zeros(bwimg.size(), CV_8UC1);
	sobel_(bwimg, sobelimg);
	imshow("Sobel", sobelimg * 3);
	waitKey();

	return 0;
}
