#include "methods.h"

int main()
{
    Mat img = imread("../image.jpg"); //create container and recording file to it
    //imshow("Showtest", img); //show 

    Mat imageGray; //create new container
    cvtColor(img, imageGray, COLOR_RGB2GRAY); //8bit image to gray-grades
    //imshow("gray", imageGray);

    //imshow("Hist", getHist(imageGray));

    Mat imageTemp = doQuantization(imageGray, 2);
    imshow("2", imageTemp);
    imshow("2", getHist(imageTemp));  



    //string i_title;
    //Mat imageTemp;
    //for (int power = 1; power <= 6; power++) {
    //    int i = pow(2, power);
    //    i_title = to_string(i);
    //    imshow(i_title, doQuantization(imageGray, i));
    //}
    
    //imshow("8", doQuantization(imageGray, 8));

    waitKey();

    return 0;
}


