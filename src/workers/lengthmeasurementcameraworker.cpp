#include "lengthmeasurementcameraworker.h"
#include <QDebug>
#include <QThread>

LengthMeasurementCameraWorker::LengthMeasurementCameraWorker(QObject *parent) : Worker(parent)
{
    workerName = "Length Measurement Worker";
}

LengthMeasurementCameraWorker::~LengthMeasurementCameraWorker()
{
    closeCameras();
}

void LengthMeasurementCameraWorker::setHardwareVals(HardwareSettingsWindow *)
{

}

void LengthMeasurementCameraWorker::init()
{
    if(initCameras())
    {
        emit initReady();
        //qWarning() << "Cameras initialized.";
    }
    else
    {
        emit initError();
        qWarning() << "Camera Error! " << my_cam1.isOpened() << " " << my_cam2.isOpened();
    }
}

void LengthMeasurementCameraWorker::measureLength()
{
    float L = measurePipetteLength();
    emit measurementReady(L);
}

bool LengthMeasurementCameraWorker::initCameras()
{
    // Camera Objects
    tmp1 = VideoCapture(0);
    tmp2 = VideoCapture(1);

    if(tmp1.isOpened() && tmp2.isOpened())
    {
        if(tmp1.get(32)==0 && tmp2.get(32) == 2) // This compares the backlight compensation variable. I use it as a configurable ID, 0 or 1;
        {
            my_cam1 = tmp1;  // Pipette Top
            my_cam2 = tmp2;  // Holder Bottom
        }
        else
        {
            my_cam1 = tmp2;
            my_cam2 = tmp1;
        }

        int    numParams        = 13;
        int    index[]          = {3,  // CV_CAP_PROP_FRAME_WIDTH
                                   4,  // CV_CAP_PROP_FRAME_HEIGHT
                                   5,  // CV_CAP_PROP_FPS
                                   6,  // CV_CAP_PROP_FOURCC
                                   10, // CV_CAP_PROP_BRIGTNESS
                                   11, // CV_CAP_PROP_CONTRAST
                                   12, // CV_CAP_PROP_SATURATION
                                   14, // CV_CAP_PROP_GAIN
                                   15, // CV_CAP_PROP_EXPOSURE
                                   17, // CV_CAP_PROP_WHITE_BALANCE
                                   20, // sharpness
                                   22, // gamma
                                   32};// backlight compensation

        // Pipette Bottom Camera Parameters
        double value1[] =  {(double)width,        // Width
                            (double)height,       // Height
                            0,            // *Frame rate
                            -466162819,   // Codec Chars
                            -9,           // Brightness
                            20,           // Contrast
                            0,            // Saturation
                            32,           // Gain
                            -8,           // Exposure
                            4400,         // White Balance
                            4,            // Sharpness
                            100,          // Gamma
                            0};           // Backlight Compensation (I use it as a configurable ID, 0 or 1)


        // Pipette Tip Camera Parameters
        double value2[] =  {(double)width,        // Width
                            (double)height,       // Height
                            0,            // *Frame rate
                            -466162819,   // Codec Chars
                            -9,           // Brightness
                            20,           // Contrast
                            0,            // Saturation
                            48,           // Gain
                            -8,           // Exposure
                            4527,         // White Balance
                            5,            // Sharpness
                            100,          // Gamma
                            2};           // Backlight Compensation (I use it as a configurable ID, 0,1, or 2)


        waitKey(1000);
        setCameraParameters(my_cam2, index, value2, numParams);
        waitKey(1000);
        setCameraParameters(my_cam1, index, value1, numParams);
        waitKey(1000);

        if(checkCamera(my_cam1) && checkCamera(my_cam2))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
       return 0;
    }
}

void LengthMeasurementCameraWorker::closeCameras()
{
    // VideoCapture releases the cameras automatically when the destructor is called
    //qWarning() << "Closing cameras...";
    //my_cam1.release();
    //my_cam2.release();
    //qWarning() << "Camera's closed";
}

void LengthMeasurementCameraWorker::aboutToClose()
{
    closeCameras();
}


void LengthMeasurementCameraWorker::setCameraParameters(VideoCapture my_cam,int index[], double params[], int numParams)
{
    //qWarning() << "Setting camera parameters.";
    for(int i=0; i<numParams; i++)
    {
        my_cam.set(index[i],params[i]);
        QThread::msleep(600);  // 500 wasn't enough.  Caused whiteouts (the exposure wasn't set correctly)
    }

    Mat img;
    my_cam >> img;
    QThread::msleep(100);
    //qWarning() << "Done.";
}

void LengthMeasurementCameraWorker::getCameraParameters(VideoCapture my_cam,int index[], int numParams)
{
    for(int i=0; i<numParams; i++)
    {
        qWarning() << i << " " << my_cam.get(index[i]);
        QThread::msleep(600);
    }

}

bool LengthMeasurementCameraWorker::checkCamera(VideoCapture my_cam)
{
    Mat img;
    my_cam >> img;
    if(img.size().height > 0 && img.size().width > 0)
    {
        //qWarning() << "Camera opened and initialized.";
        return 1;
    }
    else
    {
        qWarning() << "Camera was opened but failed to aquire image! " << my_cam.isOpened() << " Width: " << img.size().width << " Height: " << img.size().height;
        return 0;
    }
}

float LengthMeasurementCameraWorker::measurePipetteLength()
{
    // Aquiring a couple of images
    Mat img1,img2;
    Mat mean1,mean2;
    Mat sharp1, sharp2;
    Mat edge1, edge2;
    Mat lineImg1, lineImg2;
    int n = 20;
    QThread::msleep(500); // Waiting for pipette to stop moving before taking the picture

    // Clearing the camera internal buffer
    for(int i=0; i<5; i++)
    {
        my_cam1 >> img1;
        my_cam2 >> img2;
    }

    my_cam1 >> img1;
    my_cam2 >> img2;

    mean1 = aquireAndAverage(my_cam1,n);
    mean2 = aquireAndAverage(my_cam2,n);

    emit imagesAquired();

    saveImage(img1,"c1_1original.png");
    saveImage(img2,"c2_1original.png");

    saveImage(mean1,"c1_2averaged.png");
    saveImage(mean2,"c2_2averaged.png");

    sharp1 = sharpenImage(mean1);
    sharp2 = sharpenImage(mean2);

    // Blanking the rightmost 3 columns of pixels (wierd effect from sharpening)
    sharp1 = setColumnValue(sharp1, sharp1.size().width-4, sharp1.size().width-1, 255);
    sharp2 = setColumnValue(sharp2, sharp2.size().width-4, sharp2.size().width-1, 255);

    saveImage(sharp1,"c1_3sharp.png");
    saveImage(sharp2,"c2_3sharp.png");

    edge1 = edgeDetect(sharp1);
    edge2 = edgeDetect(sharp2);

    saveImage(edge1,"c1_4edge.png");
    saveImage(edge2,"c2_4edge.png");

    // Measuring the edge of the base of the pipette
    vector<Vec4i> line1 = baseLineDetect(edge1);
    int ind1(0);
    float x1 = findRightMostVerticalLine(line1,ind1);
    qWarning() << "Rightmost line point base (mm): " << x1/1084 << " " << x1 << " px."; // mm from edge of frame
    lineImg1 = drawRightMostLine(edge1,line1[ind1]);

    // Measuring the position of the tip of the pipette
    vector<Vec4i> line2 = tipLineDetect(edge2);
    int ind2(0);
    float x2 = findRightMostHorizontalLine(line2,ind2);
    qWarning() << "Rightmost line point tip (mm): " << x2/1197 << " " << x2 << " px."; // mm from edge of frame
    lineImg2 = drawRightMostLine(edge2,line2[ind2]);

    saveImage(lineImg1,"c1_5points.png");
    saveImage(lineImg2,"c2_5points.png");

    return (x1/1084+ x2/1197); // mm
}

Mat LengthMeasurementCameraWorker::aquireAndAverage(VideoCapture my_cam, int n)
{
    Mat tmp;
    Mat mean = Mat::zeros(height, width, CV_32FC3);

    //qWarning() << "Averaging " << n << " frames.";

    for(int i=0; i<n; i++)
    {
        tmp = Mat::zeros(height, width,CV_8UC3);
        my_cam >> tmp;
        tmp.convertTo(tmp,CV_32FC3);
        mean += tmp;

    }
    mean = mean/n;
    mean.convertTo(mean,CV_8UC3);
    //qWarning() << "Done.";
    return mean;

}

void LengthMeasurementCameraWorker::saveImage(Mat img, QString filename)
{
    //qWarning() << "Saving image.";
    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    compression_params.push_back(0);
    imwrite(filename.toStdString(),img,compression_params);
    //qWarning() << "Done.";
}

Mat LengthMeasurementCameraWorker::sharpenImage(Mat img)
{
    //qWarning() << "Sharpening image.";
    Mat tmp;
    GaussianBlur(img,tmp,Size(0,0),50);
    addWeighted(img,20,tmp,-19,0,tmp);
    //tmp.convertTo(tmp,CV_8UC3);
    //qWarning() << "Done.";
    return tmp;
}

Mat LengthMeasurementCameraWorker::edgeDetect(Mat img)
{
    //qWarning() << "Doing edge detection";
    cvtColor(img,img,CV_RGB2GRAY);
    Mat edges;
    float thresh(3000);
    Canny(img,edges,thresh,3*thresh,5);
    //qWarning() << "Done.";
    return edges;
}

vector<Vec4i> LengthMeasurementCameraWorker::baseLineDetect(Mat img)
{
    vector<Vec4i> lines;
    //qWarning() << "Doing line detection";
    HoughLinesP(img,lines,0.9,0.05,50,140,200);
    //qWarning() << "Line detection found " << lines.size() << " lines.";
    //qWarning() << "Done.";
    return lines;
}

vector<Vec4i> LengthMeasurementCameraWorker::tipLineDetect(Mat img)
{
    vector<Vec4i> lines;
    //qWarning() << "Doing line detection";
    HoughLinesP(img,lines,0.9,0.05,75,100,60);
    //qWarning() << "Line detection found " << lines.size() << " lines.";
    //qWarning() << "Done.";
    return lines;
}

int LengthMeasurementCameraWorker::findRightMostVerticalLine(vector<Vec4i> lines, int &index)
{
    int x_max(0);
    for(unsigned int i=0; i<lines.size(); i++)
    {
        Vec4i pts = lines[i];

        // Check angle
        float angle = atan2(pts[3] - pts[1], pts[2]-pts[0])*180/CV_PI;

        if((angle > 60) || (angle < -60))
        {
            //count++;
            // Check furthermost right point
            if(pts[2] > x_max){ x_max = pts[2]; index = i;}
            if(pts[0] > x_max){ x_max = pts[0]; index = i;}
        }
    }
    //qWarning() << "xmax: " << x_max;
    return x_max;
}

int LengthMeasurementCameraWorker::findRightMostHorizontalLine(vector<Vec4i> lines, int &index)
{
    int x_max(0);
    for(unsigned int i=0; i<lines.size(); i++)
    {
        Vec4i pts = lines[i];

        // Check angle
        float angle = atan2(pts[3] - pts[1], pts[2]-pts[0])*180/CV_PI;

        if((angle < 15) || (angle < -15))
        {
            //count++;
            // Check furthermost right point
            if(pts[2] > x_max){ x_max = pts[2]; index = i;}
            if(pts[0] > x_max){ x_max = pts[0]; index = i;}
        }


    }
    //qWarning() << "xmax: " << x_max;
    return x_max;
}


Mat LengthMeasurementCameraWorker::setColumnValue(Mat img, int start, int end, uchar val)
{
    for(int i=0; i<img.size().height; i++)
    {
        for(int j=start; j<=end; j++)
        {
            if(img.channels() == 3)
            {
                Vec3b a;
                a[0] = val;
                a[1] = val;
                a[2] = val;
                img.at<Vec3b>(i,j) = a;  // I think the syntax is updated in later versions of OpenCV
            }
            else
            {
                img.at<uchar>(i,j) = val;
            }
        }
    }

    return img;
}

Mat LengthMeasurementCameraWorker::drawRightMostLine(Mat img,Vec4i pts)
{
    Mat tmp = img;
    Point pt1;
    Point pt2;
    pt1.x = pts[0];
    pt1.y = pts[1];
    pt2.x = pts[2];
    pt2.y = pts[3];
    circle(tmp,pt1,7,Scalar(0,0,255),2);
    circle(tmp,pt2,7,Scalar(0,0,255),2);
    line(tmp,pt1,pt2,Scalar(255,0,0),4);

    return tmp;
}
