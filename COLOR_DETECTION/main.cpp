#include <opencv2/opencv.hpp>
using namespace cv;
Mat filter_red( Mat src)
{

    Mat redOnly,mask1,mask2;
    cvtColor(src,redOnly,CV_BGR2HSV);
    //inRange(redOnly, Scalar(0,0,0), Scalar(255,10,10), redOnly);
    //getting hsv range for red color
    inRange(redOnly, Scalar(0, 120, 70), Scalar(10, 255, 255), mask1);
    inRange(redOnly, Scalar(170, 120, 70), Scalar(180, 255, 255), mask2);
    redOnly=mask1+mask2;
    return redOnly;
}
int main(int argc, char *argv[])
{
    Mat img=imread("sample1.jpg",1);
    Size size(500,350);
    resize(img,img,size);
    //filtering out red color
    Mat red=filter_red(img);
    //red now shows the area of image having red color
    resize(red,red,size) ;
    //imshow("FILTER_IMAGE_RED_EXTRACTED",red);
    Mat result;
    //putting red color to the extracted area
    img.copyTo(result,red);
    //putting images together
    hconcat(img,result,result);
    imshow("Extracted red color",result);
    imwrite("result1.png",result);
    waitKey(0);
    return 0;
}



