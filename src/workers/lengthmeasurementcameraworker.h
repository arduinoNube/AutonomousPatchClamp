#ifndef LENGTHMEASUREMENTCAMERAWORKER_H
#define LENGTHMEASUREMENTCAMERAWORKER_H

#include <QObject>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "worker.h"

using namespace cv;

class LengthMeasurementCameraWorker : public Worker
{
    Q_OBJECT

    VideoCapture my_cam1,tmp1;
    VideoCapture my_cam2,tmp2;
    const int height = 2048;
    const int width  = 2560;

public:
    explicit LengthMeasurementCameraWorker(QObject *parent = 0);
    ~LengthMeasurementCameraWorker();
    QString workerName;

private:
    bool initCameras();
    void closeCameras();
    void setCameraParameters(VideoCapture my_cam,int index[], double params[], int numParams);
    void getCameraParameters(VideoCapture my_cam,int index[], int numParams);
    bool checkCamera(VideoCapture my_cam);
    float measurePipetteLength();
    Mat aquireAndAverage(VideoCapture my_cam,int n);
    void saveImage(Mat img, QString filename);
    Mat sharpenImage(Mat img);
    Mat edgeDetect(Mat img);
    vector<Vec4i> baseLineDetect(Mat img);
    vector<Vec4i> tipLineDetect(Mat img);
    int findRightMostVerticalLine(vector<Vec4i> lines, int& index);
    int findRightMostHorizontalLine(vector<Vec4i> lines, int& index);
    Mat setColumnValue(Mat sharp1, int start, int end, uchar val);
    Mat drawRightMostLine(Mat img,Vec4i pts);

signals:
    void initReady();
    void initError();
    void imagesAquired();
    void measurementReady(float length);

public slots:
    void init();
    void measureLength();
    void aboutToClose();

    void setHardwareVals(HardwareSettingsWindow *);
};

#endif // LENGTHMEASUREMENTCAMERAWORKER_H
