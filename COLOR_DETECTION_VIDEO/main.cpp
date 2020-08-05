//This is the same color extraction tutorial but with a video
//We will be detecting and extracting red color from some smaple ironman videos

#include <opencv2/opencv.hpp>
using namespace cv;
Mat filter_red( Mat src)
{

    Mat redOnly,mask1,mask2;
    cvtColor(src,redOnly,CV_BGR2HSV);
    //getting hsv range for red color
    inRange(redOnly, Scalar(0, 120, 70), Scalar(10, 255, 255), mask1);
    inRange(redOnly, Scalar(170, 120, 70), Scalar(180, 255, 255), mask2);
    redOnly=mask1+mask2;
    return redOnly;
}
int main(int argc, char *argv[])
{
    //Capturing video object from file
    //inorder to use webcam simply put 0 as a parameter
    VideoCapture cap("sample4.mp4");
    //setting a standard size for our window
    Size size(650,450);
    while(true)
    {

     Mat frame;
     Mat gray;
     cap>>frame;
     resize(frame,frame,size);
     //for video adjusting video contrast and brightness
     // removing excess brightness
     frame=frame*0.5+30;
     //for cam settings
     //frame=frame*0.5-15;
     gray=filter_red(frame);
     Mat red;
     //adding main video frame with gray mask to get only red color
     frame.copyTo(red,gray);
     //displaying everything for clear understanding
     imshow("VIDEO",frame);
     imshow("RED_MASK_VIDEO",gray);
     imshow("RED_ONLY",red);
     //setting esc to exit
     if(waitKey(50)==27)
      break;
    }
    //releasing video object
    cap.release();
    //destroying all windows
    destroyAllWindows();

    return 0;
}



