#include "Methods.h"

Mat divideImg(const Mat& img, const int blockWidth, const int blockHeight)
{
	Mat workingImg = img.clone();

	for (int r = 0; r < workingImg.rows; r += blockWidth) {
		for (int c = 0; c < workingImg.cols; c += blockHeight) {
			Rect block = Rect(c, r, blockWidth, blockHeight);
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

}
