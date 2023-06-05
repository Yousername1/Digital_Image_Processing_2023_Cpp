#include "Methods.h"

const int BLOCKSIZE = 8;


Mat imgOrig = imread("../image1.jpg");

Mat divideImg(const Mat& img)
{
	Mat workingImg = img.clone();

	for (int r = 0; r < workingImg.rows; r += BLOCKSIZE) {
		for (int c = 0; c < workingImg.cols; c += BLOCKSIZE) {
			Rect block = Rect(c, r, BLOCKSIZE, BLOCKSIZE);
			rectangle(workingImg, block, Scalar(0, 255, 0));
		}
	}

	return workingImg;
}

void onMouce(int event, int x, int y, int, void*)
{
	if (event != EVENT_LBUTTONDOWN) {
		return;
	}

	int blockX = x - x % BLOCKSIZE;
	int blockY = y - y % BLOCKSIZE;

	Rect roi = Rect(blockX, blockY, BLOCKSIZE, BLOCKSIZE);
	rectangle(processed, roi, Scalar(255, 255, 255));
	Mat imRoi = tmp(roi);

}
