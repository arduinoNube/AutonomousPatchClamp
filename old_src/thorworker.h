#ifndef THORWORKER_H
#define THORWORKER_H

#include <QThread>
#include <QObject>
#include <QAxWidget>
#include <QDebug>
#include <vector>
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <QTimer>
#include <QTime>
#include <mycamera.h>


using namespace std;

class ThorWorker : public QObject
{
    Q_OBJECT

    int mode;
    QAxWidget* hMotor, *stageMotor, *caroselMotor;
    int hMotorInit, stageMotorInit, caroselMotorInit;
    QVariant serialNum;
    QVariant pos1;
    QVariant pos2;
    QVariant velMax;
    QVariant velMin;
    QVariant accel;
    QVariant der;
    QVariant derT;
    QVariant chanID;
    QVariant flag;

    // Serial Number storage
    int hMotorSnum,stageMotorSnum,caroselMotorSnum;


    // Thor motor position storage variables
    // Motor Position Variables
    double stageMotorCurrentPosition;
    double hMotorCurrentPosition;
    double caroselMotorCurrentPosition;


    // Autoswapping variables
    double stageClearancePosition;
    double caroselDockPosition;
    double caroselReleasePosition;
    double hMotorDockPosition;
    double stageDockPosition;
    double hMotorCameraPosition;
    double stageCameraPosition;
    double hMotorMousePosition;
    bool err;
    double distToBrain;
    double cameraPipetteHeight;


    // Aquire Pipette
    int step2FlagA;
    int aquirePipetteChainMode;
    int hasPipette;

    // Change the Pipette
    int step2FlagG;
    int changePipetteChainMode;
    bool relativeMoveLock;
    QTimer *retryChangePipetteTimer;

    // Pipette height adjustment
    float calib;
    bool adjustPipetteHeight();

    // Privage Member Functions
    QTime initTimeStart;
    QTimer* initCheckTimer;    

    void hMotorToDock();
    void hMotorToCamera();
    void hMotorToMouse();
    void caroselMotorToDock();
    void caroselMotorToRelease();
    void stageMotorToDock();
    void stageMotorToClearance();
    void stageMotorToCamera();
    void stageMotorToBrainSlow();
    void stageMotorToBrainFast();
    void stageMotorToDepth();

    MyCamera cam;

private slots:

    void    initCheck();


public:
    ThorWorker();
    ~ThorWorker();
    void returnPipette();
    void close();


    void setVelocityMax  (double num);
    void setVelocityMin  (double num);
    void setAccel        (double num);

    void setCaroselDockPosition         (double num){caroselDockPosition = num;}
    void setCaroselReleasePosition      (double num){caroselReleasePosition = num;}
    void setStageMotorClearancePosition (double num){stageClearancePosition = num;}

    void setHMotorMousePosition         (double num){hMotorMousePosition = num;}
    void setHMotorCameraPosition        (double num){hMotorCameraPosition = num;}
    void setstageCameraPosition    (double num){stageCameraPosition = num;}
    void setHMotorDockPosition          (double num){hMotorDockPosition = num;}
    void setstageDockPosition      (double num){stageDockPosition = num;}

    double getStageMotorCurrentPosition   (){return stageMotorCurrentPosition;}
    double getHMotorCurrentPosition       (){return hMotorCurrentPosition;}
    double getCaroselMotorCurrentPosition (){return caroselMotorCurrentPosition;}


    // Aquire 1st pipette
    void aquirePipetteChain(int snum);

    // Changing the pipette if it currently has one in the brain
    void changePipetteChain(int snum);


signals:

    void motorsReady();
    void motorInitError();
    void pipetteAquired();
    void pipetteChanged();
    void retractWire();
    void rotateToNextPipette();
    void insertWire();
    void lockHoriz();
    void unlockHorz();
    void switchPressure(int pres);
    void atDepth();
    void atDepth2();
    void stageMotorOn();
    void stageMotorOff();
    void incrementPipetteNumber();
    
public slots:
    Q_INVOKABLE void init();
    Q_INVOKABLE void homeMotors();
    Q_INVOKABLE void setInitialSettings(vector<double> args);
    void aquirePipette();
    void changePipette();
    void stageMotorRelativeMoveSlow(double dist);
    void stageMotorRelativeMoveFast(double dist);
    void descendToDepth(float depth);
    void stageMotorToDepth(float depth);
    void setBrainHeight();

    void homeComplete();
    void moveCompleteSlot();
    void disableStage();
    void enableStage();
    
};

#endif // THORWORKER_H
