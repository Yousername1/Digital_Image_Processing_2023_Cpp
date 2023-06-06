#include "Filters.h"


int main()
{
    Filters image;
    image.setImg(imread("../image1.jpg"));

    
    imwrite("../outputimages/gauss3.jpg", image.gauss3(image.getImg()));
    imwrite("../outputimages/gauss5.jpg", image.gauss5(image.getImg()));
    imwrite("../outputimages/mosaika.jpg", image.mosaika(10, image.getImg()));
    imwrite("../outputimages/ac.jpg", image.ac(18, image.getImg()));
    imwrite("../outputimages/mediana.jpg", image.mediana(image.getImg()));

    imwrite("../outputImages/difference.jpg", image.DoG(image.getImg()));
    
    Mat cannyImg = Mat::zeros(image.getImg().size(), CV_8U);
    Canny(image.getImg(), cannyImg, 50, 290);
    imwrite("../outputImages/Canny.jpg", cannyImg);


    imwrite("../outputImages/Sobel.jpg", image.sobel(image.getImg()));


    waitKey();
    return 0;
}


