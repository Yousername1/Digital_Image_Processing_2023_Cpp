#include "Filters.h"


int main()
{
    Filters image;
    image.setImg(imread("../image1.jpg"));
    
    imwrite("../outputImages/gauss3.jpg", image.gauss3(image.getImg()));
    imwrite("../outputImages/gauss5.jpg", image.gauss5(image.getImg()));
    imwrite("../outputImages/Mosaika.jpg", image.mosaika(10, image.getImg()));
    imwrite("../outputImages/ac.jpg", image.ac(18, image.getImg()));
    imwrite("../outputImages/mediana.jpg", image.mediana(image.getImg()));

    //imshow("DoG", image.DoG(image.getImg()));
    
    Mat cannyImg = Mat::zeros(image.getImg().size(), CV_8U);
    Canny(image.getImg(), cannyImg, 30, 250);
    imwrite("../outputImages/Canny.jpg", cannyImg);

    imwrite("../outputImages/Sobel.jpg", image.sobel(image.getImg()));


    waitKey();
    return 0;
}


