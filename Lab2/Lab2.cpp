#include "Methods.h"

int main()
{
	Mat imgOrig = imread("../image1.jpg");
	Mat imgGray;
	cvtColor(imgOrig, imgGray, COLOR_BGR2GRAY);

	imshow("blocks", divideImg(imgGray, 8, 8));

	waitKey();
	return 0;
}


