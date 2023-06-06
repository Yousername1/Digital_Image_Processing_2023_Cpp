#include "Filters.h"

void Filters::setImg(Mat sourceImg)
{
	Filters::sourceImg = sourceImg;
	Filters::workingImg = sourceImg.clone();
}


Mat Filters::getImg() const
{
	return Filters::workingImg;
}

Mat Filters::biImg()
{
	Mat imgGray;
	cvtColor(getImg(), imgGray, COLOR_BGR2GRAY);
	return imgGray;
}

Mat Filters::gauss3(const Mat& inputImg)
{
	Filters::outputImg = Mat::zeros(getImg().size(), CV_8UC1);
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
	Filters::outputImg = Mat::zeros(getImg().size(), CV_8UC1);
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


