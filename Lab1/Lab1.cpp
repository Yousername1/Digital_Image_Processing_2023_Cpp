#include "methods.h"

int main()
{
    Mat img = imread("../image.jpg"); //create container and recording file to it
    imshow("Showtest", img); //show 

    Mat imageGray; //create new container
    cvtColor(img, imageGray, COLOR_RGB2GRAY); //8bit image to gray-grades
    imshow("gray", imageGray);

    imshow("Hist", getHist(imageGray));

    imshow("Quantization", doQuantization(imageGray, 16));

    waitKey();

    return 0;
}


