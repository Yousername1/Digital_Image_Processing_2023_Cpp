#include "Filters.h"

void Filters::setImg(Mat sourceImg)
{
	Filters::sourceImg = sourceImg;
	Filters::workingImg = sourceImg.clone();
}

Mat Filters::makeBiImg(Mat inputImg)
{
	cvtColor(inputImg, Filters::biImg, COLOR_BGR2GRAY);
	return biImg;
}

Mat Filters::getImg() 
{
	return makeBiImg(workingImg);
}

Mat Filters::gauss3(const Mat& inputImg)
{
	Filters::outputImg = Mat::zeros(inputImg.size(), CV_8UC1);
	int k = 36;
	int Fk[3][3] = { {1,4,1},
					 {4,16,4},
					 {1,4,1} };
	for (int i = 1; i < inputImg.cols - 1; i++)
		for (int j = 1; j < inputImg.rows - 1; j++) {
			uchar pix_value = inputImg.at<uchar>(j, i);

			int Rez = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar blurred = inputImg.at<uchar>(j + jj, i + ii);
					Rez += Fk[ii + 1][jj + 1] * blurred;
				}
			uchar blurred = Rez / k;
			outputImg.at<uchar>(j, i) = blurred;
		}
	return outputImg;
}

Mat Filters::gauss5(const Mat& inputImg)
{
	Filters::outputImg = Mat::zeros(inputImg.size(), CV_8UC1);
	int k = 256;
	int Fk[5][5] = { {1, 4, 6, 4, 1},
					{4, 16, 24, 16, 4},
					{6, 24, 36, 24, 6},
					{4, 16, 24, 16, 4},
					{1, 4, 6, 4, 1} };
	for (int i = 2; i < inputImg.cols - 2; i++)
		for (int j = 2; j < inputImg.rows - 2; j++) {
			uchar pix_value = inputImg.at<uchar>(j, i);

			int Rez = 0;
			for (int ii = -2; ii <= 2; ii++)
				for (int jj = -2; jj <= 2; jj++) {
					uchar blurred = inputImg.at<uchar>(j + jj, i + ii);
					Rez += Fk[ii + 2][jj + 2] * blurred;
				}
			uchar blurred = Rez / k;
			outputImg.at<uchar>(j, i) = blurred;
		}
	return outputImg;
}

Mat Filters::ac(int depth, const Mat& inputImg)
{
	Filters::outputImg = Mat::zeros(inputImg.size(), CV_8UC1);

	float X = ceil((100 / depth - 1) + 8); //?????????? ? ???????

	float k = X - 8; // ??????????? ??????????
	float Fk[3][3] = { { -1,-1,-1 },{ -1,X,-1 },{ -1,-1,-1 } };

	for (int i = 1; i < inputImg.cols - 1; i++)
		for (int j = 1; j < inputImg.rows - 1; j++) {
			float conv = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++) {
					uchar aced = inputImg.at<uchar>(j + jj, i + ii);
					conv += Fk[ii + 1][jj + 1] * aced;
				}
			int aced = conv / k;
			if (aced > 255)
				outputImg.at<uchar>(j, i) = 255;
			else {
				uchar uaced = aced;
				outputImg.at<uchar>(j, i) = uaced;
			}
		}
	return outputImg;
}

Mat Filters::mediana(const Mat& inputImg)
{
	Filters::outputImg = Mat::zeros(inputImg.size(), CV_8UC1);
	Mat blurred = Mat::zeros(1, 9, CV_8U);
	Mat blurred1 = Mat::zeros(1, 9, CV_8U);
	for (int i = 1; i < inputImg.cols - 1; i++)
		for (int j = 1; j < inputImg.rows - 1; j++)
		{
			// ????? ?????????? ???????
			float Rez = 0;
			for (int ii = -1; ii <= 1; ii++)
				for (int jj = -1; jj <= 1; jj++)
				{
					blurred.at<uchar>(0, (ii + 1) * 3 + jj + 1) = inputImg.at<uchar>(j + jj, i + ii);
				}
			cv::sort(blurred, blurred1, SORT_EVERY_ROW);
			unsigned char Med = blurred1.at<uchar>(0, 4);
			outputImg.at<uchar>(j, i) = Med;
		}
	return outputImg;
}


