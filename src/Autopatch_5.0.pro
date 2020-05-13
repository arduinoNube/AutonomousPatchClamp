#-------------------------------------------------
#
# Project created by QtCreator 2014-01-03T10:23:58
#
#-------------------------------------------------

QT       += core gui axcontainer serialport opengl network

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = RoboClamp
TEMPLATE = app

RC_FILE = resources.rc

SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot/qcustomplot.cpp \
    state.cpp \
    workers/multiclampworker.cpp \
    states/hardwareinit.cpp \
    workers/autopatcherworker.cpp \
    workers/headstageclampworker.cpp \
    workers/scaraworker.cpp \
    workers/fillerworker.cpp \
    workers/thorworker.cpp \
    workers/daqworker.cpp \
    states/getpipette.cpp \
    states/pipetteqc.cpp \
    states/clogcheck.cpp \
    states/neuronhunt.cpp \
    states/gigaseal.cpp \
    states/breakin.cpp \
    states/retract.cpp \
    states/retractslowly.cpp \
    states/removepipette.cpp \
    states/setbrainheight.cpp \
    states/trialinit.cpp \
    states/error.cpp \
    ui/autopatchersettings.cpp \
    ui/autopatchersettingswindow.cpp \
    ui/breakinsettingsramp.cpp \
    ui/breakinsettingssuction.cpp \
    ui/breakinsettingszap.cpp \    
    ui/hardwaresettingswindow.cpp \
    states/hardwarecalib.cpp \
    states/loadpipettes.cpp \
    workers/serialworker.cpp \
    ui/preferences.cpp \
    workers/visualstimuliworker.cpp \
    workers/lengthmeasurementcameraworker.cpp \
    states/examplestate.cpp \
    states/wait.cpp \
    states/ic_quickapdetect.cpp \
    states/ic_measurerheobase.cpp \
    states/ic_restingvoltage.cpp \
    states/ic_currentsteps.cpp \
    states/vc_membranetest.cpp \
    states/ic_recordvisualstimulation.cpp \
    states/waitandsetvars.cpp \
    states/ic_bacfiring.cpp \
    states/vc_pipettecapacitanceneutralization.cpp \
    worker.cpp \
    states/statehelperfunctions.cpp \
    states/ic_bridgebalanceadjust.cpp

HEADERS  += mainwindow.h \
    qcustomplot/qcustomplot.h \
    state.h \
    workers/multiclampworker.h \
    states/hardwareinit.h \
    workers/autopatcherworker.h \
    workers/headstageclampworker.h \
    workers/scaraworker.h \
    workers/fillerworker.h \
    workers/thorworker.h \
    workers/daqworker.h \
    states/getpipette.h \
    states/pipetteqc.h \
    states/clogcheck.h \
    states/neuronhunt.h \
    states/gigaseal.h \
    states/breakin.h \
    states/retract.h \
    states/retractslowly.h \
    states/removepipette.h \
    states/setbrainheight.h \
    states/trialinit.h \
    states/error.h \
    ui/autopatchersettings.h \
    ui/autopatchersettingswindow.h \
    ui/breakinsettingsramp.h \
    ui/breakinsettingssuction.h \
    ui/breakinsettingszap.h \
    MyValidator.h \
    ui/hardwaresettingswindow.h \
    states/hardwarecalib.h \
    states/loadpipettes.h \
    workers/serialworker.h \
    ui/preferences.h \
    workers/visualstimuliworker.h \
    workers/lengthmeasurementcameraworker.h \
    states/examplestate.h \
    states/wait.h \
    states/ic_quickapdetect.h \
    states/ic_measurerheobase.h \
    states/ic_restingvoltage.h \
    states/ic_currentsteps.h \
    states/vc_membranetest.h \
    states/ic_recordvisualstimulation.h \
    states/waitandsetvars.h \
    states/ic_bacfiring.h \
    states/vc_pipettecapacitanceneutralization.h \
    worker.h \
    states/statehelperfunctions.h \
    states/ic_bridgebalanceadjust.h

FORMS    += mainwindow.ui \
    ui/autopatchersettingswindow.ui \
    ui/breakinsettingsramp.ui \
    ui/breakinsettingssuction.ui \
    ui/breakinsettingszap.ui \
    ui/hardwaresettingswindow.ui \
    ui/preferences.ui

win32: LIBS += -L$$PWD/ -ldaqmx_libs/NIDAQmx
win32: PRE_TARGETDEPS += $$PWD/daqmx_libs/NIDAQmx.lib
win32: LIBS += -L"C:\Program Files (x86)\Molecular Devices\MultiClamp 700B Commander\3rd Party Support\AxMultiClampMsg" -lAxMultiClampMsg
INCLUDEPATH += $$PWD/ C:/ProgramsGreg/OpenCV/opencv_bin/install/include
LIBS += C:/ProgramsGreg/OpenCV/opencv_bin/install/bin/*.dll
INCLUDEPATH += $$PWD/ qcustomplot

DEPENDPATH += $$PWD/

OTHER_FILES += \
    ../img/Logo icon.png \
    resources.rc \
    ../img/LED_on.png \
    ../img/LED_off.png \
    ../bin/command_file2.txt \
    ../bin/command_file.txt \
    ../img/Logo2.png
    ../img/scara_adjust_view.PNG

INCLUDEPATH += "C:\Program Files (x86)\Molecular Devices\MultiClamp 700B Commander\3rd Party Support\AxMultiClampMsg"
DEPENDPATH += "C:\Program Files (x86)\Molecular Devices\MultiClamp 700B Commander\3rd Party Support\AxMultiClampMsg"

RESOURCES += \
    imgs.qrc

DISTFILES += \
    todo.txt \
    astyle_configuration.astylerc
