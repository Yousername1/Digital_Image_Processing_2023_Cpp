#include "Filters.h"


int main()
{
    Filters image;
    image.setImg(imread("../image1.jpg"));
    
    imshow("gauss3", image.gauss3(image.getImg()));
    imshow("gauss5", image.gauss5(image.getImg()));
    imshow("ac", image.ac(18, image.getImg()));

    waitKey();
    return 0;
}


