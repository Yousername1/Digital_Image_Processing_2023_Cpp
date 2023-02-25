#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


int main()
{
    Mat img = imread("../Lab0DIP/image.jpg"); //create container and recording file to it
    imshow("Showtest", img); //show 

    waitKey(); //waiting close event

    //Mat imageGray; //create new container
    //cvtColor(img, imageGray, COLOR_RGB2GRAY); //8bit image to gray-grades
    //imwrite("../Lab0DIP/savedImage.jpg", imageGray); //recording to the new file

    imshow("pixelChanger", pixelChanger(img));

    return 0;
}

//create method
Mat pixelChanger(Mat image) {

    Mat resultImage = Mat::zeros(image.rows, image.cols, CV_8UC1); //empty container with original width and height
    int k = image.channels() - 1; //channels initizlization
    int Y = 0, Yr = 0, Yg = 0, Yb = 0;

    for (int ch = 0; ch < image.channels() - 1; ch++)
    {
        for (int i = 0; i < image.rows - 1; i++)
        {
            for (int j = 0; j < image.cols - 1; j++)
            {
                switch (ch) {
                case 0: Yb = 0.11 * image.at<Vec3b>(i, j)[ch]; break;
                case 1: Yg = 0.53 * image.at<Vec3b>(i, j)[ch]; break;
                case 2: Yr = 0.36 * image.at<Vec3b>(i, j)[ch]; break;
                }
            }
        }
        resultImage = Yr + Yg + Yb;
    }
    
    return resultImage;
}





