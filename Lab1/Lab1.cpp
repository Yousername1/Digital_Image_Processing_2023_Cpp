#include "methods.h"

int main()
{
    Mat img = imread("../image.jpg"); //create container and recording file to it
    imshow("Showtest", img); //show 

    Mat imageGray; //create new container
    cvtColor(img, imageGray, COLOR_RGB2GRAY); //8bit image to gray-grades
    imshow("gray", imageGray);

    imshow("Hist", getHist(imageGray));

    int i = 2;
    string i_title;
	//int power = 1;
	//while (power <= 6) {
	//	imshow("Quantization" + i, doQuantization(imageGray, i));
	//	i = pow(i, power + 1);
	//}

    for (int power = 1; power <= 6; power++) {
        i = pow(2, power);
        i_title = to_string(i);
        imshow(i_title, doQuantization(imageGray, i));
    }
    
    //imshow("Quantization", doQuantization(imageGray, 16));

    waitKey();

    return 0;
}


