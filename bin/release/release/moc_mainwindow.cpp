/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[100];
    char stringdata[2351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "pushButtonUpAdjustSignal"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "closeWorkers"
QT_MOC_LITERAL(4, 50, 15), // "initDAQInThread"
QT_MOC_LITERAL(5, 66, 23), // "initAutopatcherInThread"
QT_MOC_LITERAL(6, 90, 12), // "daq_stopTask"
QT_MOC_LITERAL(7, 103, 16), // "autopatcher_stop"
QT_MOC_LITERAL(8, 120, 11), // "filler_stop"
QT_MOC_LITERAL(9, 132, 19), // "headstageClamp_stop"
QT_MOC_LITERAL(10, 152, 10), // "scara_stop"
QT_MOC_LITERAL(11, 163, 15), // "scara_powerDown"
QT_MOC_LITERAL(12, 179, 11), // "visual_stop"
QT_MOC_LITERAL(13, 191, 25), // "on_pushButtonGo1_released"
QT_MOC_LITERAL(14, 217, 25), // "on_pushButtonGo3_released"
QT_MOC_LITERAL(15, 243, 19), // "rawMemTestDataReady"
QT_MOC_LITERAL(16, 263, 15), // "QVector<double>"
QT_MOC_LITERAL(17, 279, 6), // "buffer"
QT_MOC_LITERAL(18, 286, 11), // "plotResData"
QT_MOC_LITERAL(19, 298, 3), // "res"
QT_MOC_LITERAL(20, 302, 17), // "apSettingsChanged"
QT_MOC_LITERAL(21, 320, 25), // "breakInSettingsChangedZap"
QT_MOC_LITERAL(22, 346, 29), // "breakInSettingsChangedSuction"
QT_MOC_LITERAL(23, 376, 26), // "breakInSettingsChangedRamp"
QT_MOC_LITERAL(24, 403, 17), // "hwSettingsChanged"
QT_MOC_LITERAL(25, 421, 23), // "preferencesWindowClosed"
QT_MOC_LITERAL(26, 445, 17), // "updateMemTestVals"
QT_MOC_LITERAL(27, 463, 4), // "vals"
QT_MOC_LITERAL(28, 468, 26), // "updateCurrentBrainPosition"
QT_MOC_LITERAL(29, 495, 5), // "depth"
QT_MOC_LITERAL(30, 501, 4), // "init"
QT_MOC_LITERAL(31, 506, 17), // "startStateMachine"
QT_MOC_LITERAL(32, 524, 13), // "stateFinished"
QT_MOC_LITERAL(33, 538, 10), // "busy_start"
QT_MOC_LITERAL(34, 549, 3), // "msg"
QT_MOC_LITERAL(35, 553, 9), // "busy_stop"
QT_MOC_LITERAL(36, 563, 15), // "busy_stop_error"
QT_MOC_LITERAL(37, 579, 11), // "busyTimeout"
QT_MOC_LITERAL(38, 591, 19), // "setCurrentPageIndex"
QT_MOC_LITERAL(39, 611, 1), // "i"
QT_MOC_LITERAL(40, 613, 9), // "pgObjName"
QT_MOC_LITERAL(41, 623, 11), // "enablePages"
QT_MOC_LITERAL(42, 635, 4), // "flag"
QT_MOC_LITERAL(43, 640, 13), // "setTextStatus"
QT_MOC_LITERAL(44, 654, 19), // "clearResistancePlot"
QT_MOC_LITERAL(45, 674, 16), // "clearRawDataPlot"
QT_MOC_LITERAL(46, 691, 16), // "clearMemTestPlot"
QT_MOC_LITERAL(47, 708, 23), // "enableActionFillPipette"
QT_MOC_LITERAL(48, 732, 25), // "enableActionResetCarousel"
QT_MOC_LITERAL(49, 758, 24), // "enableActionLoadMicrofil"
QT_MOC_LITERAL(50, 783, 21), // "updateCurrentPosition"
QT_MOC_LITERAL(51, 805, 25), // "on_pushButtonHALT_clicked"
QT_MOC_LITERAL(52, 831, 39), // "on_actionBreakInSuctionWindow..."
QT_MOC_LITERAL(53, 871, 35), // "on_actionBreakInZapWindow_tri..."
QT_MOC_LITERAL(54, 907, 36), // "on_actionBreakInRampWindow_tr..."
QT_MOC_LITERAL(55, 944, 39), // "on_actionAutopatcher_Settings..."
QT_MOC_LITERAL(56, 984, 36), // "on_actionHardware_Settings_tr..."
QT_MOC_LITERAL(57, 1021, 10), // "closeEvent"
QT_MOC_LITERAL(58, 1032, 12), // "QCloseEvent*"
QT_MOC_LITERAL(59, 1045, 1), // "e"
QT_MOC_LITERAL(60, 1047, 38), // "on_checkBoxPauseOnRemoval_sta..."
QT_MOC_LITERAL(61, 1086, 4), // "arg1"
QT_MOC_LITERAL(62, 1091, 36), // "on_pushButtonSCARACalibrate_r..."
QT_MOC_LITERAL(63, 1128, 35), // "on_pushButtonArm1Clockwise_re..."
QT_MOC_LITERAL(64, 1164, 42), // "on_pushButtonArm1Counterclock..."
QT_MOC_LITERAL(65, 1207, 42), // "on_pushButtonArm2Counterclock..."
QT_MOC_LITERAL(66, 1250, 35), // "on_pushButtonArm2Clockwise_re..."
QT_MOC_LITERAL(67, 1286, 22), // "on_radioButton_toggled"
QT_MOC_LITERAL(68, 1309, 7), // "checked"
QT_MOC_LITERAL(69, 1317, 24), // "on_radioButton_2_toggled"
QT_MOC_LITERAL(70, 1342, 24), // "on_radioButton_3_toggled"
QT_MOC_LITERAL(71, 1367, 24), // "on_radioButton_4_toggled"
QT_MOC_LITERAL(72, 1392, 24), // "on_radioButton_5_toggled"
QT_MOC_LITERAL(73, 1417, 24), // "on_radioButton_6_toggled"
QT_MOC_LITERAL(74, 1442, 42), // "on_pushButtonDispenseLoadPipe..."
QT_MOC_LITERAL(75, 1485, 42), // "on_pushButtonAspirateLoadPipe..."
QT_MOC_LITERAL(76, 1528, 38), // "on_pushButtonNextLoadPipettes..."
QT_MOC_LITERAL(77, 1567, 33), // "on_actionReset_Carousel_trigg..."
QT_MOC_LITERAL(78, 1601, 31), // "on_actionFill_Pipette_triggered"
QT_MOC_LITERAL(79, 1633, 16), // "rawDataReadySlot"
QT_MOC_LITERAL(80, 1650, 24), // "on_radioButton_7_toggled"
QT_MOC_LITERAL(81, 1675, 24), // "on_radioButton_8_toggled"
QT_MOC_LITERAL(82, 1700, 24), // "on_radioButton_9_toggled"
QT_MOC_LITERAL(83, 1725, 25), // "on_radioButton_10_toggled"
QT_MOC_LITERAL(84, 1751, 30), // "on_pushButtonUpAdjust_released"
QT_MOC_LITERAL(85, 1782, 32), // "on_pushButtonDownAdjust_released"
QT_MOC_LITERAL(86, 1815, 37), // "on_actionLoad_microfil_20uL_t..."
QT_MOC_LITERAL(87, 1853, 38), // "on_actionHome_Thorlabs_Motor_..."
QT_MOC_LITERAL(88, 1892, 39), // "on_actionOpen_Headstage_Clamp..."
QT_MOC_LITERAL(89, 1932, 41), // "on_actionRetract_Headstage_Wi..."
QT_MOC_LITERAL(90, 1974, 26), // "on_pushButtonPause_toggled"
QT_MOC_LITERAL(91, 2001, 30), // "on_actionPreferences_triggered"
QT_MOC_LITERAL(92, 2032, 20), // "incrementTrialNumber"
QT_MOC_LITERAL(93, 2053, 40), // "on_actionClose_Headstage_Clam..."
QT_MOC_LITERAL(94, 2094, 40), // "on_actionInsert_Headstage_Wir..."
QT_MOC_LITERAL(95, 2135, 40), // "on_actionFinish_Visual_Stimul..."
QT_MOC_LITERAL(96, 2176, 52), // "on_actionReset_Brain_Height_O..."
QT_MOC_LITERAL(97, 2229, 50), // "on_actionReset_Brain_Height_O..."
QT_MOC_LITERAL(98, 2280, 34), // "on_actionFiller_Valve_On_trig..."
QT_MOC_LITERAL(99, 2315, 35) // "on_actionFiller_Valve_Off_tri..."

    },
    "MainWindow\0pushButtonUpAdjustSignal\0"
    "\0closeWorkers\0initDAQInThread\0"
    "initAutopatcherInThread\0daq_stopTask\0"
    "autopatcher_stop\0filler_stop\0"
    "headstageClamp_stop\0scara_stop\0"
    "scara_powerDown\0visual_stop\0"
    "on_pushButtonGo1_released\0"
    "on_pushButtonGo3_released\0rawMemTestDataReady\0"
    "QVector<double>\0buffer\0plotResData\0"
    "res\0apSettingsChanged\0breakInSettingsChangedZap\0"
    "breakInSettingsChangedSuction\0"
    "breakInSettingsChangedRamp\0hwSettingsChanged\0"
    "preferencesWindowClosed\0updateMemTestVals\0"
    "vals\0updateCurrentBrainPosition\0depth\0"
    "init\0startStateMachine\0stateFinished\0"
    "busy_start\0msg\0busy_stop\0busy_stop_error\0"
    "busyTimeout\0setCurrentPageIndex\0i\0"
    "pgObjName\0enablePages\0flag\0setTextStatus\0"
    "clearResistancePlot\0clearRawDataPlot\0"
    "clearMemTestPlot\0enableActionFillPipette\0"
    "enableActionResetCarousel\0"
    "enableActionLoadMicrofil\0updateCurrentPosition\0"
    "on_pushButtonHALT_clicked\0"
    "on_actionBreakInSuctionWindow_triggered\0"
    "on_actionBreakInZapWindow_triggered\0"
    "on_actionBreakInRampWindow_triggered\0"
    "on_actionAutopatcher_Settings_triggered\0"
    "on_actionHardware_Settings_triggered\0"
    "closeEvent\0QCloseEvent*\0e\0"
    "on_checkBoxPauseOnRemoval_stateChanged\0"
    "arg1\0on_pushButtonSCARACalibrate_released\0"
    "on_pushButtonArm1Clockwise_released\0"
    "on_pushButtonArm1Counterclockwise_released\0"
    "on_pushButtonArm2Counterclockwise_released\0"
    "on_pushButtonArm2Clockwise_released\0"
    "on_radioButton_toggled\0checked\0"
    "on_radioButton_2_toggled\0"
    "on_radioButton_3_toggled\0"
    "on_radioButton_4_toggled\0"
    "on_radioButton_5_toggled\0"
    "on_radioButton_6_toggled\0"
    "on_pushButtonDispenseLoadPipettes_released\0"
    "on_pushButtonAspirateLoadPipettes_released\0"
    "on_pushButtonNextLoadPipettes_released\0"
    "on_actionReset_Carousel_triggered\0"
    "on_actionFill_Pipette_triggered\0"
    "rawDataReadySlot\0on_radioButton_7_toggled\0"
    "on_radioButton_8_toggled\0"
    "on_radioButton_9_toggled\0"
    "on_radioButton_10_toggled\0"
    "on_pushButtonUpAdjust_released\0"
    "on_pushButtonDownAdjust_released\0"
    "on_actionLoad_microfil_20uL_triggered\0"
    "on_actionHome_Thorlabs_Motor_triggered\0"
    "on_actionOpen_Headstage_Clamp_triggered\0"
    "on_actionRetract_Headstage_Wire_triggered\0"
    "on_pushButtonPause_toggled\0"
    "on_actionPreferences_triggered\0"
    "incrementTrialNumber\0"
    "on_actionClose_Headstage_Clamp_triggered\0"
    "on_actionInsert_Headstage_Wire_triggered\0"
    "on_actionFinish_Visual_Stimuli_triggered\0"
    "on_actionReset_Brain_Height_On_New_Pipette_triggered\0"
    "on_actionReset_Brain_Height_On_New_Pipette_toggled\0"
    "on_actionFiller_Valve_On_triggered\0"
    "on_actionFiller_Valve_Off_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      86,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  444,    2, 0x06 /* Public */,
       3,    0,  445,    2, 0x06 /* Public */,
       4,    0,  446,    2, 0x06 /* Public */,
       5,    0,  447,    2, 0x06 /* Public */,
       6,    0,  448,    2, 0x06 /* Public */,
       7,    0,  449,    2, 0x06 /* Public */,
       8,    0,  450,    2, 0x06 /* Public */,
       9,    0,  451,    2, 0x06 /* Public */,
      10,    0,  452,    2, 0x06 /* Public */,
      11,    0,  453,    2, 0x06 /* Public */,
      12,    0,  454,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  455,    2, 0x0a /* Public */,
      14,    0,  456,    2, 0x0a /* Public */,
      15,    1,  457,    2, 0x0a /* Public */,
      18,    1,  460,    2, 0x0a /* Public */,
      20,    0,  463,    2, 0x0a /* Public */,
      21,    0,  464,    2, 0x0a /* Public */,
      22,    0,  465,    2, 0x0a /* Public */,
      23,    0,  466,    2, 0x0a /* Public */,
      24,    0,  467,    2, 0x0a /* Public */,
      25,    0,  468,    2, 0x0a /* Public */,
      26,    1,  469,    2, 0x0a /* Public */,
      28,    1,  472,    2, 0x0a /* Public */,
      30,    0,  475,    2, 0x08 /* Private */,
      31,    0,  476,    2, 0x08 /* Private */,
      32,    0,  477,    2, 0x08 /* Private */,
      33,    1,  478,    2, 0x08 /* Private */,
      35,    1,  481,    2, 0x08 /* Private */,
      36,    1,  484,    2, 0x08 /* Private */,
      37,    0,  487,    2, 0x08 /* Private */,
      38,    1,  488,    2, 0x08 /* Private */,
      38,    1,  491,    2, 0x08 /* Private */,
      41,    1,  494,    2, 0x08 /* Private */,
      43,    1,  497,    2, 0x08 /* Private */,
      44,    0,  500,    2, 0x08 /* Private */,
      45,    0,  501,    2, 0x08 /* Private */,
      46,    0,  502,    2, 0x08 /* Private */,
      47,    1,  503,    2, 0x08 /* Private */,
      48,    1,  506,    2, 0x08 /* Private */,
      49,    1,  509,    2, 0x08 /* Private */,
      50,    0,  512,    2, 0x08 /* Private */,
      51,    0,  513,    2, 0x08 /* Private */,
      52,    0,  514,    2, 0x08 /* Private */,
      53,    0,  515,    2, 0x08 /* Private */,
      54,    0,  516,    2, 0x08 /* Private */,
      55,    0,  517,    2, 0x08 /* Private */,
      56,    0,  518,    2, 0x08 /* Private */,
      57,    1,  519,    2, 0x08 /* Private */,
      60,    1,  522,    2, 0x08 /* Private */,
      62,    0,  525,    2, 0x08 /* Private */,
      63,    0,  526,    2, 0x08 /* Private */,
      64,    0,  527,    2, 0x08 /* Private */,
      65,    0,  528,    2, 0x08 /* Private */,
      66,    0,  529,    2, 0x08 /* Private */,
      67,    1,  530,    2, 0x08 /* Private */,
      69,    1,  533,    2, 0x08 /* Private */,
      70,    1,  536,    2, 0x08 /* Private */,
      71,    1,  539,    2, 0x08 /* Private */,
      72,    1,  542,    2, 0x08 /* Private */,
      73,    1,  545,    2, 0x08 /* Private */,
      74,    0,  548,    2, 0x08 /* Private */,
      75,    0,  549,    2, 0x08 /* Private */,
      76,    0,  550,    2, 0x08 /* Private */,
      77,    0,  551,    2, 0x08 /* Private */,
      78,    0,  552,    2, 0x08 /* Private */,
      79,    0,  553,    2, 0x08 /* Private */,
      80,    1,  554,    2, 0x08 /* Private */,
      81,    1,  557,    2, 0x08 /* Private */,
      82,    1,  560,    2, 0x08 /* Private */,
      83,    1,  563,    2, 0x08 /* Private */,
      84,    0,  566,    2, 0x08 /* Private */,
      85,    0,  567,    2, 0x08 /* Private */,
      86,    0,  568,    2, 0x08 /* Private */,
      87,    0,  569,    2, 0x08 /* Private */,
      88,    0,  570,    2, 0x08 /* Private */,
      89,    0,  571,    2, 0x08 /* Private */,
      90,    1,  572,    2, 0x08 /* Private */,
      91,    0,  575,    2, 0x08 /* Private */,
      92,    0,  576,    2, 0x08 /* Private */,
      93,    0,  577,    2, 0x08 /* Private */,
      94,    0,  578,    2, 0x08 /* Private */,
      95,    0,  579,    2, 0x08 /* Private */,
      96,    0,  580,    2, 0x08 /* Private */,
      97,    1,  581,    2, 0x08 /* Private */,
      98,    0,  584,    2, 0x08 /* Private */,
      99,    0,  585,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Double,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   27,
    QMetaType::Void, QMetaType::Double,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   39,
    QMetaType::Void, QMetaType::QString,   40,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::QString,   34,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 58,   59,
    QMetaType::Void, QMetaType::Int,   61,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   68,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   61,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->pushButtonUpAdjustSignal(); break;
        case 1: _t->closeWorkers(); break;
        case 2: _t->initDAQInThread(); break;
        case 3: _t->initAutopatcherInThread(); break;
        case 4: _t->daq_stopTask(); break;
        case 5: _t->autopatcher_stop(); break;
        case 6: _t->filler_stop(); break;
        case 7: _t->headstageClamp_stop(); break;
        case 8: _t->scara_stop(); break;
        case 9: _t->scara_powerDown(); break;
        case 10: _t->visual_stop(); break;
        case 11: _t->on_pushButtonGo1_released(); break;
        case 12: _t->on_pushButtonGo3_released(); break;
        case 13: _t->rawMemTestDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 14: _t->plotResData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->apSettingsChanged(); break;
        case 16: _t->breakInSettingsChangedZap(); break;
        case 17: _t->breakInSettingsChangedSuction(); break;
        case 18: _t->breakInSettingsChangedRamp(); break;
        case 19: _t->hwSettingsChanged(); break;
        case 20: _t->preferencesWindowClosed(); break;
        case 21: _t->updateMemTestVals((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 22: _t->updateCurrentBrainPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->init(); break;
        case 24: _t->startStateMachine(); break;
        case 25: _t->stateFinished(); break;
        case 26: _t->busy_start((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->busy_stop((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->busy_stop_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 29: _t->busyTimeout(); break;
        case 30: _t->setCurrentPageIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->setCurrentPageIndex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 32: _t->enablePages((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->setTextStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 34: _t->clearResistancePlot(); break;
        case 35: _t->clearRawDataPlot(); break;
        case 36: _t->clearMemTestPlot(); break;
        case 37: _t->enableActionFillPipette((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->enableActionResetCarousel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->enableActionLoadMicrofil((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->updateCurrentPosition(); break;
        case 41: _t->on_pushButtonHALT_clicked(); break;
        case 42: _t->on_actionBreakInSuctionWindow_triggered(); break;
        case 43: _t->on_actionBreakInZapWindow_triggered(); break;
        case 44: _t->on_actionBreakInRampWindow_triggered(); break;
        case 45: _t->on_actionAutopatcher_Settings_triggered(); break;
        case 46: _t->on_actionHardware_Settings_triggered(); break;
        case 47: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 48: _t->on_checkBoxPauseOnRemoval_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->on_pushButtonSCARACalibrate_released(); break;
        case 50: _t->on_pushButtonArm1Clockwise_released(); break;
        case 51: _t->on_pushButtonArm1Counterclockwise_released(); break;
        case 52: _t->on_pushButtonArm2Counterclockwise_released(); break;
        case 53: _t->on_pushButtonArm2Clockwise_released(); break;
        case 54: _t->on_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->on_radioButton_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->on_radioButton_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->on_radioButton_4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 58: _t->on_radioButton_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 59: _t->on_radioButton_6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 60: _t->on_pushButtonDispenseLoadPipettes_released(); break;
        case 61: _t->on_pushButtonAspirateLoadPipettes_released(); break;
        case 62: _t->on_pushButtonNextLoadPipettes_released(); break;
        case 63: _t->on_actionReset_Carousel_triggered(); break;
        case 64: _t->on_actionFill_Pipette_triggered(); break;
        case 65: _t->rawDataReadySlot(); break;
        case 66: _t->on_radioButton_7_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 67: _t->on_radioButton_8_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 68: _t->on_radioButton_9_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 69: _t->on_radioButton_10_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 70: _t->on_pushButtonUpAdjust_released(); break;
        case 71: _t->on_pushButtonDownAdjust_released(); break;
        case 72: _t->on_actionLoad_microfil_20uL_triggered(); break;
        case 73: _t->on_actionHome_Thorlabs_Motor_triggered(); break;
        case 74: _t->on_actionOpen_Headstage_Clamp_triggered(); break;
        case 75: _t->on_actionRetract_Headstage_Wire_triggered(); break;
        case 76: _t->on_pushButtonPause_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 77: _t->on_actionPreferences_triggered(); break;
        case 78: _t->incrementTrialNumber(); break;
        case 79: _t->on_actionClose_Headstage_Clamp_triggered(); break;
        case 80: _t->on_actionInsert_Headstage_Wire_triggered(); break;
        case 81: _t->on_actionFinish_Visual_Stimuli_triggered(); break;
        case 82: _t->on_actionReset_Brain_Height_On_New_Pipette_triggered(); break;
        case 83: _t->on_actionReset_Brain_Height_On_New_Pipette_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 84: _t->on_actionFiller_Valve_On_triggered(); break;
        case 85: _t->on_actionFiller_Valve_Off_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::pushButtonUpAdjustSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::closeWorkers)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::initDAQInThread)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::initAutopatcherInThread)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::daq_stopTask)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::autopatcher_stop)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::filler_stop)) {
                *result = 6;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::headstageClamp_stop)) {
                *result = 7;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::scara_stop)) {
                *result = 8;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::scara_powerDown)) {
                *result = 9;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::visual_stop)) {
                *result = 10;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 86)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 86;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 86)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 86;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::pushButtonUpAdjustSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::closeWorkers()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::initDAQInThread()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::initAutopatcherInThread()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::daq_stopTask()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::autopatcher_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MainWindow::filler_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MainWindow::headstageClamp_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MainWindow::scara_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void MainWindow::scara_powerDown()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void MainWindow::visual_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
