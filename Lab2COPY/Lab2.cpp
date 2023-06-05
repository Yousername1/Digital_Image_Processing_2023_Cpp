#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cmath>

using namespace std;
//using namespace cv;

cv::Mat img = cv::imread("../image1.jpg");
cv::Mat imgblocked = img.clone();
cv::Mat imgblocked2 = imgblocked.clone();
cv::Mat imgblock;
int blockSize = 8;

static void onClick(int event, int x, int y, int, void*) {
	if (event == cv::EVENT_LBUTTONDOWN) {
		// поиск координат блока
		int blockX = 0, blockY = 0;
		for (int row = 0; row < imgblocked.rows; row += blockSize)
			for (int col = 0; col < imgblocked.cols; col += blockSize) {
				if ((y >= row) && (y < row + blockSize) && (x >= col) && (x < col + blockSize)) {
					blockY = row;
					blockX = col;
				}
			}
		cv::Rect block = cv::Rect(blockX, blockY, blockSize, blockSize);
		cv::rectangle(imgblocked, block, cv::Scalar(0, 0, 0));
		cv::Mat imageBlock = img(block);

		// рисуем блок до дкп
		cv::Mat iB = imageBlock.clone();
		resize(iB, iB, cv::Size(iB.rows * 32, iB.cols * 32), 0, 0, cv::INTER_CUBIC);
		cv::imshow("Selected block", iB);

		// наложение сетки поверх оригинального изображения
		cv::imshow("Grid image", imgblocked);
		imgblocked = imgblocked2.clone();
		cv::Mat imageBlock_DCT = imageBlock.clone();
		cv::Mat imageBlock_DCT_b = cv::Mat::zeros(imageBlock.cols, imageBlock.rows, CV_8U);

		// перевод в полутоновое
		for (int i = 0; i < imageBlock_DCT.rows; i++)
			for (int j = 0; j < imageBlock_DCT.cols; j++) {
				uchar b = imageBlock_DCT.at<cv::Vec3b>(i, j)[0];
				uchar g = imageBlock_DCT.at<cv::Vec3b>(i, j)[1];
				uchar r = imageBlock_DCT.at<cv::Vec3b>(i, j)[2];
				imageBlock_DCT_b.at<uchar>(i, j) = 0.11 * b + 0.53 * g + 0.36 * r;
			}
		double N = 8;
		cv::Mat imageBlock64F;
		imageBlock_DCT_b.convertTo(imageBlock64F, CV_64F); // выделенный блок в тип CV_64F

		// базисная матрица
		cv::Mat basisMat = cv::Mat::zeros(blockSize, blockSize, CV_64F);  // создание матрицы для базиса и подсчет коэффициентов
		for (int n = 0; n < basisMat.rows; n++)
			for (int k = 0; k < basisMat.cols; k++) {
				if (n == 0) basisMat.at<double>(n, k) = 1 / sqrt(N);
				else basisMat.at<double>(n, k) = sqrt(2 / N) * cos(3.14 * n * (k + 1 / 2) / N);
			}

		// дкп
		cv::Mat basisMatTransp = basisMat.t(); // транспонирование базисной матрицы
		cv::Mat DCT;
		cv::Mat DCT8U;
		DCT = basisMatTransp * imageBlock64F;
		DCT = DCT * basisMat; // формула 
		DCT.convertTo(DCT8U, CV_8UC1); // перевод в полутоновое
		resize(DCT8U, DCT8U, cv::Size(DCT8U.rows * 32, DCT8U.cols * 32), 0, 0, cv::INTER_CUBIC);
		cv::imshow("DCT", DCT8U);
	}
	return;
}


int main() {
	for (int row = 0; row < img.rows; row += blockSize)
		for (int col = 0; col < img.cols; col += blockSize) {
			cv::Rect block = cv::Rect(col, row, blockSize, blockSize);
			cv::rectangle(imgblocked, block, cv::Scalar(255, 255, 255));
		}
	cv::imshow("Grid image", imgblocked);
	imgblocked2 = imgblocked.clone();
	cv::setMouseCallback("Grid image", onClick); // вызов функции по нажатию на лкм
	cv::waitKey();

	return 0;
}