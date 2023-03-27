#include "methods.h"

int main()
{
    Mat img = imread("../image.jpg"); //create container and recording file to it
    //imshow("Showtest", img); //show original image

    Mat imageGray; //create new container
    cvtColor(img, imageGray, COLOR_RGB2GRAY); //8bit image to grayscale
    //imshow("gray", imageGray); //show grayscale image
    //imshow("Hist", getHist(imageGray)); //show histogram for grayscale image

    /*
    * Sequential quantization 
    * by the number of levels 
    * corresponding to powers of two. 
    */
    string level_title;
    for (int power = 1; power <= 6; power++) {
        int level = pow(2, power);
        level_title = to_string(level);
        imshow(level_title, doQuantization(imageGray, level));
    }


    cout << "Estimation of RMS error" << endl;
    cout << "|" << setw(10) << "level" << setw(10) << "|" << setw(10) << "estimation" << setw(10) << "|" << endl;
    for (int power = 1; power <= 6; power++) {
        int level = pow(2, power);
        level_title = to_string(level);
        cout << "|" << setw(10) << level_title << setw(10) << "|" << setw(10) << estimationCalculation(level) << setw(10) << "|" << endl;
    }


    waitKey();

    return 0;
}


