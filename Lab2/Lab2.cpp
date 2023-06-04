#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

const int BLOCKSIZE = 8;
const Mat IMGORIG = imread("../image1.jpg");
Mat workingImg = IMGORIG.clone();

Mat divideImg(const Mat& img)
{
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
	rectangle(workingImg, roi, Scalar(255, 255, 255));
	Mat imRoi = workingImg(roi);

}

int main()
{

	//Mat imgGray;
	//cvtColor(imgOrig, imgGray, COLOR_BGR2GRAY);

	imshow("Blocks", divideImg(IMGORIG));

	waitKey();
	return 0;
}


