/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/mainwindow.h"
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
    QByteArrayData data[84];
    char stringdata[1907];
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
QT_MOC_LITERAL(3, 37, 15), // "initDAQInThread"
QT_MOC_LITERAL(4, 53, 8), // "daq_stop"
QT_MOC_LITERAL(5, 62, 16), // "autopatcher_stop"
QT_MOC_LITERAL(6, 79, 11), // "filler_stop"
QT_MOC_LITERAL(7, 91, 19), // "headstageClamp_stop"
QT_MOC_LITERAL(8, 111, 10), // "scara_stop"
QT_MOC_LITERAL(9, 122, 25), // "on_pushButtonGo1_released"
QT_MOC_LITERAL(10, 148, 25), // "on_pushButtonGo3_released"
QT_MOC_LITERAL(11, 174, 19), // "rawMemTestDataReady"
QT_MOC_LITERAL(12, 194, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 210, 6), // "buffer"
QT_MOC_LITERAL(14, 217, 11), // "plotResData"
QT_MOC_LITERAL(15, 229, 3), // "res"
QT_MOC_LITERAL(16, 233, 17), // "apSettingsChanged"
QT_MOC_LITERAL(17, 251, 25), // "breakInSettingsChangedZap"
QT_MOC_LITERAL(18, 277, 29), // "breakInSettingsChangedSuction"
QT_MOC_LITERAL(19, 307, 26), // "breakInSettingsChangedRamp"
QT_MOC_LITERAL(20, 334, 17), // "hwSettingsChanged"
QT_MOC_LITERAL(21, 352, 4), // "init"
QT_MOC_LITERAL(22, 357, 17), // "startStateMachine"
QT_MOC_LITERAL(23, 375, 13), // "stateFinished"
QT_MOC_LITERAL(24, 389, 10), // "busy_start"
QT_MOC_LITERAL(25, 400, 3), // "msg"
QT_MOC_LITERAL(26, 404, 9), // "busy_stop"
QT_MOC_LITERAL(27, 414, 15), // "busy_stop_error"
QT_MOC_LITERAL(28, 430, 11), // "busyTimeout"
QT_MOC_LITERAL(29, 442, 19), // "setCurrentPageIndex"
QT_MOC_LITERAL(30, 462, 1), // "i"
QT_MOC_LITERAL(31, 464, 9), // "pgObjName"
QT_MOC_LITERAL(32, 474, 11), // "enablePages"
QT_MOC_LITERAL(33, 486, 4), // "flag"
QT_MOC_LITERAL(34, 491, 13), // "setTextStatus"
QT_MOC_LITERAL(35, 505, 19), // "clearResistancePlot"
QT_MOC_LITERAL(36, 525, 16), // "clearRawDataPlot"
QT_MOC_LITERAL(37, 542, 16), // "clearMemTestPlot"
QT_MOC_LITERAL(38, 559, 23), // "enableActionFillPipette"
QT_MOC_LITERAL(39, 583, 25), // "enableActionResetCarousel"
QT_MOC_LITERAL(40, 609, 24), // "enableActionLoadMicrofil"
QT_MOC_LITERAL(41, 634, 21), // "updateCurrentPosition"
QT_MOC_LITERAL(42, 656, 28), // "on_checkBoxLowV_stateChanged"
QT_MOC_LITERAL(43, 685, 4), // "arg1"
QT_MOC_LITERAL(44, 690, 36), // "on_checkBoxRampOverride_state..."
QT_MOC_LITERAL(45, 727, 33), // "on_checkBoxSkipBreak_stateCha..."
QT_MOC_LITERAL(46, 761, 28), // "on_pushButtonRetract_clicked"
QT_MOC_LITERAL(47, 790, 35), // "on_checkBoxSlowRetract_stateC..."
QT_MOC_LITERAL(48, 826, 37), // "on_checkBoxSwitchControl_stat..."
QT_MOC_LITERAL(49, 864, 25), // "on_pushButtonHALT_clicked"
QT_MOC_LITERAL(50, 890, 39), // "on_actionBreakInSuctionWindow..."
QT_MOC_LITERAL(51, 930, 35), // "on_actionBreakInZapWindow_tri..."
QT_MOC_LITERAL(52, 966, 36), // "on_actionBreakInRampWindow_tr..."
QT_MOC_LITERAL(53, 1003, 39), // "on_actionAutopatcher_Settings..."
QT_MOC_LITERAL(54, 1043, 36), // "on_actionHardware_Settings_tr..."
QT_MOC_LITERAL(55, 1080, 10), // "closeEvent"
QT_MOC_LITERAL(56, 1091, 12), // "QCloseEvent*"
QT_MOC_LITERAL(57, 1104, 1), // "e"
QT_MOC_LITERAL(58, 1106, 38), // "on_checkBoxPauseOnRemoval_sta..."
QT_MOC_LITERAL(59, 1145, 36), // "on_pushButtonSCARACalibrate_r..."
QT_MOC_LITERAL(60, 1182, 35), // "on_pushButtonArm1Clockwise_re..."
QT_MOC_LITERAL(61, 1218, 42), // "on_pushButtonArm1Counterclock..."
QT_MOC_LITERAL(62, 1261, 42), // "on_pushButtonArm2Counterclock..."
QT_MOC_LITERAL(63, 1304, 35), // "on_pushButtonArm2Clockwise_re..."
QT_MOC_LITERAL(64, 1340, 22), // "on_radioButton_toggled"
QT_MOC_LITERAL(65, 1363, 7), // "checked"
QT_MOC_LITERAL(66, 1371, 24), // "on_radioButton_2_toggled"
QT_MOC_LITERAL(67, 1396, 24), // "on_radioButton_3_toggled"
QT_MOC_LITERAL(68, 1421, 24), // "on_radioButton_4_toggled"
QT_MOC_LITERAL(69, 1446, 24), // "on_radioButton_5_toggled"
QT_MOC_LITERAL(70, 1471, 24), // "on_radioButton_6_toggled"
QT_MOC_LITERAL(71, 1496, 42), // "on_pushButtonDispenseLoadPipe..."
QT_MOC_LITERAL(72, 1539, 42), // "on_pushButtonAspirateLoadPipe..."
QT_MOC_LITERAL(73, 1582, 38), // "on_pushButtonNextLoadPipettes..."
QT_MOC_LITERAL(74, 1621, 33), // "on_actionReset_Carousel_trigg..."
QT_MOC_LITERAL(75, 1655, 31), // "on_actionFill_Pipette_triggered"
QT_MOC_LITERAL(76, 1687, 16), // "rawDataReadySlot"
QT_MOC_LITERAL(77, 1704, 24), // "on_radioButton_7_toggled"
QT_MOC_LITERAL(78, 1729, 24), // "on_radioButton_8_toggled"
QT_MOC_LITERAL(79, 1754, 24), // "on_radioButton_9_toggled"
QT_MOC_LITERAL(80, 1779, 25), // "on_radioButton_10_toggled"
QT_MOC_LITERAL(81, 1805, 30), // "on_pushButtonUpAdjust_released"
QT_MOC_LITERAL(82, 1836, 32), // "on_pushButtonDownAdjust_released"
QT_MOC_LITERAL(83, 1869, 37) // "on_actionLoad_microfil_20uL_t..."

    },
    "MainWindow\0pushButtonUpAdjustSignal\0"
    "\0initDAQInThread\0daq_stop\0autopatcher_stop\0"
    "filler_stop\0headstageClamp_stop\0"
    "scara_stop\0on_pushButtonGo1_released\0"
    "on_pushButtonGo3_released\0rawMemTestDataReady\0"
    "QVector<double>\0buffer\0plotResData\0"
    "res\0apSettingsChanged\0breakInSettingsChangedZap\0"
    "breakInSettingsChangedSuction\0"
    "breakInSettingsChangedRamp\0hwSettingsChanged\0"
    "init\0startStateMachine\0stateFinished\0"
    "busy_start\0msg\0busy_stop\0busy_stop_error\0"
    "busyTimeout\0setCurrentPageIndex\0i\0"
    "pgObjName\0enablePages\0flag\0setTextStatus\0"
    "clearResistancePlot\0clearRawDataPlot\0"
    "clearMemTestPlot\0enableActionFillPipette\0"
    "enableActionResetCarousel\0"
    "enableActionLoadMicrofil\0updateCurrentPosition\0"
    "on_checkBoxLowV_stateChanged\0arg1\0"
    "on_checkBoxRampOverride_stateChanged\0"
    "on_checkBoxSkipBreak_stateChanged\0"
    "on_pushButtonRetract_clicked\0"
    "on_checkBoxSlowRetract_stateChanged\0"
    "on_checkBoxSwitchControl_stateChanged\0"
    "on_pushButtonHALT_clicked\0"
    "on_actionBreakInSuctionWindow_triggered\0"
    "on_actionBreakInZapWindow_triggered\0"
    "on_actionBreakInRampWindow_triggered\0"
    "on_actionAutopatcher_Settings_triggered\0"
    "on_actionHardware_Settings_triggered\0"
    "closeEvent\0QCloseEvent*\0e\0"
    "on_checkBoxPauseOnRemoval_stateChanged\0"
    "on_pushButtonSCARACalibrate_released\0"
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
    "on_actionLoad_microfil_20uL_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      72,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  374,    2, 0x06 /* Public */,
       3,    0,  375,    2, 0x06 /* Public */,
       4,    0,  376,    2, 0x06 /* Public */,
       5,    0,  377,    2, 0x06 /* Public */,
       6,    0,  378,    2, 0x06 /* Public */,
       7,    0,  379,    2, 0x06 /* Public */,
       8,    0,  380,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  381,    2, 0x0a /* Public */,
      10,    0,  382,    2, 0x0a /* Public */,
      11,    1,  383,    2, 0x0a /* Public */,
      14,    1,  386,    2, 0x0a /* Public */,
      16,    0,  389,    2, 0x0a /* Public */,
      17,    0,  390,    2, 0x0a /* Public */,
      18,    0,  391,    2, 0x0a /* Public */,
      19,    0,  392,    2, 0x0a /* Public */,
      20,    0,  393,    2, 0x0a /* Public */,
      21,    0,  394,    2, 0x08 /* Private */,
      22,    0,  395,    2, 0x08 /* Private */,
      23,    0,  396,    2, 0x08 /* Private */,
      24,    1,  397,    2, 0x08 /* Private */,
      26,    1,  400,    2, 0x08 /* Private */,
      27,    1,  403,    2, 0x08 /* Private */,
      28,    0,  406,    2, 0x08 /* Private */,
      29,    1,  407,    2, 0x08 /* Private */,
      29,    1,  410,    2, 0x08 /* Private */,
      32,    1,  413,    2, 0x08 /* Private */,
      34,    1,  416,    2, 0x08 /* Private */,
      35,    0,  419,    2, 0x08 /* Private */,
      36,    0,  420,    2, 0x08 /* Private */,
      37,    0,  421,    2, 0x08 /* Private */,
      38,    1,  422,    2, 0x08 /* Private */,
      39,    1,  425,    2, 0x08 /* Private */,
      40,    1,  428,    2, 0x08 /* Private */,
      41,    0,  431,    2, 0x08 /* Private */,
      42,    1,  432,    2, 0x08 /* Private */,
      44,    1,  435,    2, 0x08 /* Private */,
      45,    1,  438,    2, 0x08 /* Private */,
      46,    0,  441,    2, 0x08 /* Private */,
      47,    1,  442,    2, 0x08 /* Private */,
      48,    1,  445,    2, 0x08 /* Private */,
      49,    0,  448,    2, 0x08 /* Private */,
      50,    0,  449,    2, 0x08 /* Private */,
      51,    0,  450,    2, 0x08 /* Private */,
      52,    0,  451,    2, 0x08 /* Private */,
      53,    0,  452,    2, 0x08 /* Private */,
      54,    0,  453,    2, 0x08 /* Private */,
      55,    1,  454,    2, 0x08 /* Private */,
      58,    1,  457,    2, 0x08 /* Private */,
      59,    0,  460,    2, 0x08 /* Private */,
      60,    0,  461,    2, 0x08 /* Private */,
      61,    0,  462,    2, 0x08 /* Private */,
      62,    0,  463,    2, 0x08 /* Private */,
      63,    0,  464,    2, 0x08 /* Private */,
      64,    1,  465,    2, 0x08 /* Private */,
      66,    1,  468,    2, 0x08 /* Private */,
      67,    1,  471,    2, 0x08 /* Private */,
      68,    1,  474,    2, 0x08 /* Private */,
      69,    1,  477,    2, 0x08 /* Private */,
      70,    1,  480,    2, 0x08 /* Private */,
      71,    0,  483,    2, 0x08 /* Private */,
      72,    0,  484,    2, 0x08 /* Private */,
      73,    0,  485,    2, 0x08 /* Private */,
      74,    0,  486,    2, 0x08 /* Private */,
      75,    0,  487,    2, 0x08 /* Private */,
      76,    0,  488,    2, 0x08 /* Private */,
      77,    1,  489,    2, 0x08 /* Private */,
      78,    1,  492,    2, 0x08 /* Private */,
      79,    1,  495,    2, 0x08 /* Private */,
      80,    1,  498,    2, 0x08 /* Private */,
      81,    0,  501,    2, 0x08 /* Private */,
      82,    0,  502,    2, 0x08 /* Private */,
      83,    0,  503,    2, 0x08 /* Private */,

 // signals: parameters
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
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 56,   57,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void, QMetaType::Bool,   65,
    QMetaType::Void,
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
        case 1: _t->initDAQInThread(); break;
        case 2: _t->daq_stop(); break;
        case 3: _t->autopatcher_stop(); break;
        case 4: _t->filler_stop(); break;
        case 5: _t->headstageClamp_stop(); break;
        case 6: _t->scara_stop(); break;
        case 7: _t->on_pushButtonGo1_released(); break;
        case 8: _t->on_pushButtonGo3_released(); break;
        case 9: _t->rawMemTestDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 10: _t->plotResData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->apSettingsChanged(); break;
        case 12: _t->breakInSettingsChangedZap(); break;
        case 13: _t->breakInSettingsChangedSuction(); break;
        case 14: _t->breakInSettingsChangedRamp(); break;
        case 15: _t->hwSettingsChanged(); break;
        case 16: _t->init(); break;
        case 17: _t->startStateMachine(); break;
        case 18: _t->stateFinished(); break;
        case 19: _t->busy_start((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 20: _t->busy_stop((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->busy_stop_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->busyTimeout(); break;
        case 23: _t->setCurrentPageIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setCurrentPageIndex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 25: _t->enablePages((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->setTextStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: _t->clearResistancePlot(); break;
        case 28: _t->clearRawDataPlot(); break;
        case 29: _t->clearMemTestPlot(); break;
        case 30: _t->enableActionFillPipette((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->enableActionResetCarousel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->enableActionLoadMicrofil((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->updateCurrentPosition(); break;
        case 34: _t->on_checkBoxLowV_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_checkBoxRampOverride_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_checkBoxSkipBreak_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_pushButtonRetract_clicked(); break;
        case 38: _t->on_checkBoxSlowRetract_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_checkBoxSwitchControl_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 40: _t->on_pushButtonHALT_clicked(); break;
        case 41: _t->on_actionBreakInSuctionWindow_triggered(); break;
        case 42: _t->on_actionBreakInZapWindow_triggered(); break;
        case 43: _t->on_actionBreakInRampWindow_triggered(); break;
        case 44: _t->on_actionAutopatcher_Settings_triggered(); break;
        case 45: _t->on_actionHardware_Settings_triggered(); break;
        case 46: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 47: _t->on_checkBoxPauseOnRemoval_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_pushButtonSCARACalibrate_released(); break;
        case 49: _t->on_pushButtonArm1Clockwise_released(); break;
        case 50: _t->on_pushButtonArm1Counterclockwise_released(); break;
        case 51: _t->on_pushButtonArm2Counterclockwise_released(); break;
        case 52: _t->on_pushButtonArm2Clockwise_released(); break;
        case 53: _t->on_radioButton_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_radioButton_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->on_radioButton_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 56: _t->on_radioButton_4_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->on_radioButton_5_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 58: _t->on_radioButton_6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 59: _t->on_pushButtonDispenseLoadPipettes_released(); break;
        case 60: _t->on_pushButtonAspirateLoadPipettes_released(); break;
        case 61: _t->on_pushButtonNextLoadPipettes_released(); break;
        case 62: _t->on_actionReset_Carousel_triggered(); break;
        case 63: _t->on_actionFill_Pipette_triggered(); break;
        case 64: _t->rawDataReadySlot(); break;
        case 65: _t->on_radioButton_7_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 66: _t->on_radioButton_8_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 67: _t->on_radioButton_9_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 68: _t->on_radioButton_10_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 69: _t->on_pushButtonUpAdjust_released(); break;
        case 70: _t->on_pushButtonDownAdjust_released(); break;
        case 71: _t->on_actionLoad_microfil_20uL_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::initDAQInThread)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::daq_stop)) {
                *result = 2;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::autopatcher_stop)) {
                *result = 3;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::filler_stop)) {
                *result = 4;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::headstageClamp_stop)) {
                *result = 5;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::scara_stop)) {
                *result = 6;
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
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 72)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 72;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::pushButtonUpAdjustSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MainWindow::initDAQInThread()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::daq_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::autopatcher_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::filler_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MainWindow::headstageClamp_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MainWindow::scara_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
