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


double estimationCalculation(int q_level) {

	return (255.0 / (q_level - 1)) / sqrt(12);

}

double errorCalculation(double sum, const Mat& image)
{
	return sqrt(sum / (image.rows * image.cols));
}


map<int, double> makeRMStable(int key, double value) {
	map<int, double> RMStable;
	RMStable.insert({key, value});
	return RMStable;
}

void getRMStable(map<int, double> RMStable) {
	map <int, double> ::iterator it = RMStable.begin();
	cout << "RMS error" << endl;
	for (it; it != RMStable.end(); it++) {
		cout << "level: " << it->first << "  error: " << it->second << endl;
	}
}



Mat doQuantization(const Mat& image, int q_level)
{
	Mat resultImage = Mat::zeros(image.rows, image.cols, CV_8UC1);
	Mat ret = image.clone();
	int Y = 0, Y_quanti = 0;
	double sum = 0; 
	double RMS = 0;

	//q_level - number of quantization levels (2, 4 ... 64)
	int range = 255 / (q_level - 1);
	
	for (int i = 0; i <= image.rows - 1; i++) {
		for (int j = 0; j <= image.cols - 1; j++) {
			
			Y = image.at<uchar>(i, j);

			//if (Y > 255) {
			//	Y = 255;
			//	ret.at<uchar>(i, j) = Y;
			//}

			for (int level = 0; level <= q_level; level++) {
				if (Y > range * level && Y <= range * level + range / 2) {
					Y_quanti = range * level;
				}
				else if (Y > range * level + range / 2 && Y <= range * (level + 1)) {
					Y_quanti = range * (level + 1);
				}
			}

			//Y_quanti = image.at<uchar>(i, j);

			if (Y_quanti > 255)
				Y_quanti = 255;

			resultImage.at<uchar>(i, j) = Y_quanti;
		}
		sum += pow(Y - Y_quanti, 2);
	}

	//while(q_level <= q_level)
	//{
	//	cout << "|" << setw(10) << to_string(q_level) << setw(10) << "|" << setw(10) << errorCalculation(sum, image) << setw(10) << "|" << endl;
	//	break;
	//}


	map<int, double> RMStable;
	RMStable = makeRMStable(q_level, errorCalculation(sum, image));
	getRMStable(RMStable);
	//while (q_level <= q_level) {
	//	emptyTable = setRMStable(q_level, errorCalculation(sum, image));
	//	break;
	//}

	//string hist_title = to_string(q_level);
	//imshow(hist_title + "Hist", getHist(resultImage));


	return resultImage;
}

