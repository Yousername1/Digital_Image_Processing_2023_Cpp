#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;


//create method
Mat pixelChanger(Mat image) {

    Mat resultImage = Mat::zeros(image.rows, image.cols, CV_8UC1); //empty container with original width and height
    int ch = image.channels() - 1; //Red channel

    for (int i = 0; i <= image.rows - 1; i++) {
        for (int j = 0; j <= image.cols - 1; j++) {
            resultImage.at<uchar>(i, j) = 
                0.36 * image.at<Vec3b>(i, j)[ch] +
                0.53 * image.at<Vec3b>(i, j)[ch - 1] +
                0.11 * image.at<Vec3b>(i, j)[ch - 2];
        }
    }
    return resultImage;
}



int main()
{
    Mat img = imread("../Lab0/image.jpg"); //create container and recording file to it
    imshow("Showtest", img); //show 

    //Mat imageGray; //create new container
    //cvtColor(img, imageGray, COLOR_RGB2GRAY); //8bit image to gray-grades
    //imwrite("../Lab0DIP/savedImage.jpg", imageGray); //recording to the new file

    imshow("pixelChanger", pixelChanger(img));
    waitKey(); //waiting close event

    imwrite("../Lab0/savedImage.jpg", pixelChanger(img));

    return 0;
}





