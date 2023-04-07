#include "methods.h"

int main()
{
    Mat img = imread("../image.jpg"); 
    imshow("Showtest", img); 

    Mat imageGray; 
    cvtColor(img, imageGray, COLOR_BGR2GRAY); 
    imshow("gray", imageGray); //show grayscale image
    imshow("Hist", getHist(imageGray)); //show histogram for grayscale image


    /*
    * Sequential quantization 
    * by the number of levels 
    * corresponding to powers of two. 
    */
    string level_title;
    Mat imageTemp;
    //cout << "RMS error" << endl; //This subheading can be here if we only want to see the error table (without opening images).
    //cout << "|" << setw(10) << "level" << setw(10) << "|" << setw(10) << "error" << setw(10) << "|" << endl;
    for (int power = 1; power <= 6; power++) {
        int level = pow(2, power);
        level_title = to_string(level);
        imageTemp = doQuantization(imageGray, level);
        imshow(level_title, imageTemp);
        imshow(level_title + "Hist", getHist(imageTemp));
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


