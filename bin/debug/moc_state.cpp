/****************************************************************************
** Meta object code from reading C++ file 'state.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/state.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'state.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_State_t {
    QByteArrayData data[159];
    char stringdata[2881];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_State_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_State_t qt_meta_stringdata_State = {
    {
QT_MOC_LITERAL(0, 0, 5), // "State"
QT_MOC_LITERAL(1, 6, 13), // "stateFinished"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 14), // "gui_busy_start"
QT_MOC_LITERAL(4, 36, 3), // "msg"
QT_MOC_LITERAL(5, 40, 13), // "gui_busy_stop"
QT_MOC_LITERAL(6, 54, 19), // "gui_busy_stop_error"
QT_MOC_LITERAL(7, 74, 23), // "gui_setCurrentPageIndex"
QT_MOC_LITERAL(8, 98, 1), // "i"
QT_MOC_LITERAL(9, 100, 9), // "pgObjName"
QT_MOC_LITERAL(10, 110, 15), // "gui_enablePages"
QT_MOC_LITERAL(11, 126, 4), // "flag"
QT_MOC_LITERAL(12, 131, 17), // "gui_setTextStatus"
QT_MOC_LITERAL(13, 149, 23), // "gui_clearResistancePlot"
QT_MOC_LITERAL(14, 173, 20), // "gui_clearRawDataPlot"
QT_MOC_LITERAL(15, 194, 20), // "gui_clearMemTestPlot"
QT_MOC_LITERAL(16, 215, 27), // "gui_enableActionFillPipette"
QT_MOC_LITERAL(17, 243, 6), // "enable"
QT_MOC_LITERAL(18, 250, 29), // "gui_enableActionResetCarousel"
QT_MOC_LITERAL(19, 280, 28), // "gui_enableActionLoadMicrofil"
QT_MOC_LITERAL(20, 309, 25), // "gui_updateCurrentPosition"
QT_MOC_LITERAL(21, 335, 15), // "gui_plotResData"
QT_MOC_LITERAL(22, 351, 3), // "res"
QT_MOC_LITERAL(23, 355, 16), // "autopatcher_init"
QT_MOC_LITERAL(24, 372, 4), // "port"
QT_MOC_LITERAL(25, 377, 21), // "autopatcher_switchBNC"
QT_MOC_LITERAL(26, 399, 9), // "sendEvent"
QT_MOC_LITERAL(27, 409, 28), // "autopatcher_softwarePressure"
QT_MOC_LITERAL(28, 438, 26), // "autopatcher_switchPressure"
QT_MOC_LITERAL(29, 465, 23), // "autopatcher_setPressure"
QT_MOC_LITERAL(30, 489, 3), // "num"
QT_MOC_LITERAL(31, 493, 3), // "val"
QT_MOC_LITERAL(32, 497, 19), // "autopatcher_breakIn"
QT_MOC_LITERAL(33, 517, 4), // "time"
QT_MOC_LITERAL(34, 522, 13), // "msWatiBetween"
QT_MOC_LITERAL(35, 536, 9), // "numPulses"
QT_MOC_LITERAL(36, 546, 23), // "autopatcher_breakInRamp"
QT_MOC_LITERAL(37, 570, 8), // "pressure"
QT_MOC_LITERAL(38, 579, 19), // "headstageClamp_init"
QT_MOC_LITERAL(39, 599, 26), // "headstageClamp_retractWire"
QT_MOC_LITERAL(40, 626, 25), // "headstageClamp_threadWire"
QT_MOC_LITERAL(41, 652, 24), // "headstageClamp_openClamp"
QT_MOC_LITERAL(42, 677, 25), // "headstageClamp_closeClamp"
QT_MOC_LITERAL(43, 703, 24), // "headstageClamp_halfClamp"
QT_MOC_LITERAL(44, 728, 10), // "scara_init"
QT_MOC_LITERAL(45, 739, 24), // "scara_rotateCarouselNext"
QT_MOC_LITERAL(46, 764, 23), // "scara_enableEndEffector"
QT_MOC_LITERAL(47, 788, 21), // "scara_openEndEffector"
QT_MOC_LITERAL(48, 810, 29), // "scara_partialCloseEndEffector"
QT_MOC_LITERAL(49, 840, 22), // "scara_closeEndEffector"
QT_MOC_LITERAL(50, 863, 14), // "scara_moveNext"
QT_MOC_LITERAL(51, 878, 10), // "sendEventl"
QT_MOC_LITERAL(52, 889, 11), // "scara_fill1"
QT_MOC_LITERAL(53, 901, 11), // "scara_fill2"
QT_MOC_LITERAL(54, 913, 11), // "scara_fill3"
QT_MOC_LITERAL(55, 925, 26), // "scara_dispenseHighPressure"
QT_MOC_LITERAL(56, 952, 4), // "msec"
QT_MOC_LITERAL(57, 957, 15), // "scara_closePort"
QT_MOC_LITERAL(58, 973, 15), // "scara_calibrate"
QT_MOC_LITERAL(59, 989, 15), // "scara_rotateArm"
QT_MOC_LITERAL(60, 1005, 15), // "scara_powerDown"
QT_MOC_LITERAL(61, 1021, 11), // "filler_init"
QT_MOC_LITERAL(62, 1033, 16), // "filler_closePort"
QT_MOC_LITERAL(63, 1050, 21), // "filler_aspirateVolume"
QT_MOC_LITERAL(64, 1072, 6), // "volume"
QT_MOC_LITERAL(65, 1079, 21), // "filler_dispenseVolume"
QT_MOC_LITERAL(66, 1101, 28), // "filler_enablePressureControl"
QT_MOC_LITERAL(67, 1130, 7), // "enabled"
QT_MOC_LITERAL(68, 1138, 18), // "thorLabsMotor_init"
QT_MOC_LITERAL(69, 1157, 6), // "serial"
QT_MOC_LITERAL(70, 1164, 23), // "thorLabsMotor_calibrate"
QT_MOC_LITERAL(71, 1188, 20), // "thorLabsMotor_enable"
QT_MOC_LITERAL(72, 1209, 21), // "thorLabsMotor_disable"
QT_MOC_LITERAL(73, 1231, 28), // "thorLabsMotor_moveToAbsolute"
QT_MOC_LITERAL(74, 1260, 3), // "pos"
QT_MOC_LITERAL(75, 1264, 3), // "vel"
QT_MOC_LITERAL(76, 1268, 28), // "thorLabsMotor_moveByRelative"
QT_MOC_LITERAL(77, 1297, 4), // "dist"
QT_MOC_LITERAL(78, 1302, 23), // "thorLabsMotor_haltMotor"
QT_MOC_LITERAL(79, 1326, 15), // "multiclamp_init"
QT_MOC_LITERAL(80, 1342, 4), // "path"
QT_MOC_LITERAL(81, 1347, 24), // "multiclamp_selectChannel"
QT_MOC_LITERAL(82, 1372, 28), // "multiclamp_autoPipetteOffset"
QT_MOC_LITERAL(83, 1401, 18), // "multiclamp_setMode"
QT_MOC_LITERAL(84, 1420, 1), // "s"
QT_MOC_LITERAL(85, 1422, 22), // "multiclamp_setHoldingV"
QT_MOC_LITERAL(86, 1445, 22), // "multiclamp_setHoldingI"
QT_MOC_LITERAL(87, 1468, 26), // "multiclamp_holdingVChecked"
QT_MOC_LITERAL(88, 1495, 26), // "multiclamp_holdingIchecked"
QT_MOC_LITERAL(89, 1522, 14), // "multiclamp_zap"
QT_MOC_LITERAL(90, 1537, 8), // "daq_init"
QT_MOC_LITERAL(91, 1546, 7), // "devName"
QT_MOC_LITERAL(92, 1554, 16), // "daq_initResCheck"
QT_MOC_LITERAL(93, 1571, 14), // "daq_triggerRes"
QT_MOC_LITERAL(94, 1586, 17), // "daq_initRawAquire"
QT_MOC_LITERAL(95, 1604, 17), // "daq_stopRawAquire"
QT_MOC_LITERAL(96, 1622, 18), // "daq_startRawAquire"
QT_MOC_LITERAL(97, 1641, 14), // "daq_startVRamp"
QT_MOC_LITERAL(98, 1656, 13), // "daq_stopVRamp"
QT_MOC_LITERAL(99, 1670, 15), // "daq_initMemTest"
QT_MOC_LITERAL(100, 1686, 16), // "daq_startMemTest"
QT_MOC_LITERAL(101, 1703, 15), // "daq_stopMemTest"
QT_MOC_LITERAL(102, 1719, 24), // "daq_guiUpdateMemTestVals"
QT_MOC_LITERAL(103, 1744, 15), // "QVector<double>"
QT_MOC_LITERAL(104, 1760, 4), // "vals"
QT_MOC_LITERAL(105, 1765, 17), // "daq_clearAllTasks"
QT_MOC_LITERAL(106, 1783, 10), // "pauseState"
QT_MOC_LITERAL(107, 1794, 11), // "resumeState"
QT_MOC_LITERAL(108, 1806, 9), // "haltState"
QT_MOC_LITERAL(109, 1816, 15), // "gui_upAdjustBtn"
QT_MOC_LITERAL(110, 1832, 17), // "gui_downAdjustBtn"
QT_MOC_LITERAL(111, 1850, 32), // "gui_onCheckBoxkLowV_stateChanged"
QT_MOC_LITERAL(112, 1883, 4), // "arg1"
QT_MOC_LITERAL(113, 1888, 39), // "gui_onCheckBoxRampOverride_st..."
QT_MOC_LITERAL(114, 1928, 15), // "gui_rotateSCARA"
QT_MOC_LITERAL(115, 1944, 9), // "armNumber"
QT_MOC_LITERAL(116, 1954, 9), // "direction"
QT_MOC_LITERAL(117, 1964, 8), // "numSteps"
QT_MOC_LITERAL(118, 1973, 38), // "gui_pushbuttonNextLoadPipette..."
QT_MOC_LITERAL(119, 2012, 24), // "gui_dispenseVolumeFiller"
QT_MOC_LITERAL(120, 2037, 24), // "gui_aspirateVolumeFiller"
QT_MOC_LITERAL(121, 2062, 22), // "gui_Load20uLInMicrofil"
QT_MOC_LITERAL(122, 2085, 13), // "vStim_stopped"
QT_MOC_LITERAL(123, 2099, 13), // "vStim_started"
QT_MOC_LITERAL(124, 2113, 12), // "vStim_paused"
QT_MOC_LITERAL(125, 2126, 21), // "autopatcher_initReady"
QT_MOC_LITERAL(126, 2148, 21), // "autopatcher_initError"
QT_MOC_LITERAL(127, 2170, 27), // "autopatcher_breakInComplete"
QT_MOC_LITERAL(128, 2198, 24), // "headstageClamp_initReady"
QT_MOC_LITERAL(129, 2223, 24), // "headstageClamp_initError"
QT_MOC_LITERAL(130, 2248, 30), // "headstageClamp_commandFinished"
QT_MOC_LITERAL(131, 2279, 15), // "scara_initReady"
QT_MOC_LITERAL(132, 2295, 15), // "scara_initError"
QT_MOC_LITERAL(133, 2311, 23), // "scara_calibrateFinished"
QT_MOC_LITERAL(134, 2335, 21), // "scara_commandFinished"
QT_MOC_LITERAL(135, 2357, 16), // "filler_initReady"
QT_MOC_LITERAL(136, 2374, 16), // "filler_initError"
QT_MOC_LITERAL(137, 2391, 22), // "filler_commandFinished"
QT_MOC_LITERAL(138, 2414, 23), // "thorLabsMotor_initReady"
QT_MOC_LITERAL(139, 2438, 23), // "thorLabsMotor_initError"
QT_MOC_LITERAL(140, 2462, 31), // "thorLabsMotor_calibrateFinished"
QT_MOC_LITERAL(141, 2494, 26), // "thorLabsMotor_moveComplete"
QT_MOC_LITERAL(142, 2521, 21), // "thorLabsMotor_enabled"
QT_MOC_LITERAL(143, 2543, 22), // "throLabsMotor_disabled"
QT_MOC_LITERAL(144, 2566, 20), // "multiclamp_initReady"
QT_MOC_LITERAL(145, 2587, 20), // "multiclamp_initError"
QT_MOC_LITERAL(146, 2608, 36), // "multiclamp_autoPipetteOffsetC..."
QT_MOC_LITERAL(147, 2645, 22), // "multiclamp_zapComplete"
QT_MOC_LITERAL(148, 2668, 13), // "daq_initReady"
QT_MOC_LITERAL(149, 2682, 13), // "daq_initError"
QT_MOC_LITERAL(150, 2696, 21), // "daq_initResCheckReady"
QT_MOC_LITERAL(151, 2718, 21), // "daq_initResCheckError"
QT_MOC_LITERAL(152, 2740, 19), // "daq_resCheckStopped"
QT_MOC_LITERAL(153, 2760, 16), // "daq_resDataReady"
QT_MOC_LITERAL(154, 2777, 16), // "daq_rawDataReady"
QT_MOC_LITERAL(155, 2794, 20), // "daq_memTestInitReady"
QT_MOC_LITERAL(156, 2815, 20), // "daq_memTestInitError"
QT_MOC_LITERAL(157, 2836, 20), // "daq_memTestValsReady"
QT_MOC_LITERAL(158, 2857, 23) // "daq_rawMemTestDataReady"

    },
    "State\0stateFinished\0\0gui_busy_start\0"
    "msg\0gui_busy_stop\0gui_busy_stop_error\0"
    "gui_setCurrentPageIndex\0i\0pgObjName\0"
    "gui_enablePages\0flag\0gui_setTextStatus\0"
    "gui_clearResistancePlot\0gui_clearRawDataPlot\0"
    "gui_clearMemTestPlot\0gui_enableActionFillPipette\0"
    "enable\0gui_enableActionResetCarousel\0"
    "gui_enableActionLoadMicrofil\0"
    "gui_updateCurrentPosition\0gui_plotResData\0"
    "res\0autopatcher_init\0port\0"
    "autopatcher_switchBNC\0sendEvent\0"
    "autopatcher_softwarePressure\0"
    "autopatcher_switchPressure\0"
    "autopatcher_setPressure\0num\0val\0"
    "autopatcher_breakIn\0time\0msWatiBetween\0"
    "numPulses\0autopatcher_breakInRamp\0"
    "pressure\0headstageClamp_init\0"
    "headstageClamp_retractWire\0"
    "headstageClamp_threadWire\0"
    "headstageClamp_openClamp\0"
    "headstageClamp_closeClamp\0"
    "headstageClamp_halfClamp\0scara_init\0"
    "scara_rotateCarouselNext\0"
    "scara_enableEndEffector\0scara_openEndEffector\0"
    "scara_partialCloseEndEffector\0"
    "scara_closeEndEffector\0scara_moveNext\0"
    "sendEventl\0scara_fill1\0scara_fill2\0"
    "scara_fill3\0scara_dispenseHighPressure\0"
    "msec\0scara_closePort\0scara_calibrate\0"
    "scara_rotateArm\0scara_powerDown\0"
    "filler_init\0filler_closePort\0"
    "filler_aspirateVolume\0volume\0"
    "filler_dispenseVolume\0"
    "filler_enablePressureControl\0enabled\0"
    "thorLabsMotor_init\0serial\0"
    "thorLabsMotor_calibrate\0thorLabsMotor_enable\0"
    "thorLabsMotor_disable\0"
    "thorLabsMotor_moveToAbsolute\0pos\0vel\0"
    "thorLabsMotor_moveByRelative\0dist\0"
    "thorLabsMotor_haltMotor\0multiclamp_init\0"
    "path\0multiclamp_selectChannel\0"
    "multiclamp_autoPipetteOffset\0"
    "multiclamp_setMode\0s\0multiclamp_setHoldingV\0"
    "multiclamp_setHoldingI\0"
    "multiclamp_holdingVChecked\0"
    "multiclamp_holdingIchecked\0multiclamp_zap\0"
    "daq_init\0devName\0daq_initResCheck\0"
    "daq_triggerRes\0daq_initRawAquire\0"
    "daq_stopRawAquire\0daq_startRawAquire\0"
    "daq_startVRamp\0daq_stopVRamp\0"
    "daq_initMemTest\0daq_startMemTest\0"
    "daq_stopMemTest\0daq_guiUpdateMemTestVals\0"
    "QVector<double>\0vals\0daq_clearAllTasks\0"
    "pauseState\0resumeState\0haltState\0"
    "gui_upAdjustBtn\0gui_downAdjustBtn\0"
    "gui_onCheckBoxkLowV_stateChanged\0arg1\0"
    "gui_onCheckBoxRampOverride_stateChanged\0"
    "gui_rotateSCARA\0armNumber\0direction\0"
    "numSteps\0gui_pushbuttonNextLoadPipettesReleased\0"
    "gui_dispenseVolumeFiller\0"
    "gui_aspirateVolumeFiller\0"
    "gui_Load20uLInMicrofil\0vStim_stopped\0"
    "vStim_started\0vStim_paused\0"
    "autopatcher_initReady\0autopatcher_initError\0"
    "autopatcher_breakInComplete\0"
    "headstageClamp_initReady\0"
    "headstageClamp_initError\0"
    "headstageClamp_commandFinished\0"
    "scara_initReady\0scara_initError\0"
    "scara_calibrateFinished\0scara_commandFinished\0"
    "filler_initReady\0filler_initError\0"
    "filler_commandFinished\0thorLabsMotor_initReady\0"
    "thorLabsMotor_initError\0"
    "thorLabsMotor_calibrateFinished\0"
    "thorLabsMotor_moveComplete\0"
    "thorLabsMotor_enabled\0throLabsMotor_disabled\0"
    "multiclamp_initReady\0multiclamp_initError\0"
    "multiclamp_autoPipetteOffsetComplete\0"
    "multiclamp_zapComplete\0daq_initReady\0"
    "daq_initError\0daq_initResCheckReady\0"
    "daq_initResCheckError\0daq_resCheckStopped\0"
    "daq_resDataReady\0daq_rawDataReady\0"
    "daq_memTestInitReady\0daq_memTestInitError\0"
    "daq_memTestValsReady\0daq_rawMemTestDataReady"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_State[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     127,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      78,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  649,    2, 0x06 /* Public */,
       3,    1,  650,    2, 0x06 /* Public */,
       5,    1,  653,    2, 0x06 /* Public */,
       6,    1,  656,    2, 0x06 /* Public */,
       7,    1,  659,    2, 0x06 /* Public */,
       7,    1,  662,    2, 0x06 /* Public */,
      10,    1,  665,    2, 0x06 /* Public */,
      12,    1,  668,    2, 0x06 /* Public */,
      13,    0,  671,    2, 0x06 /* Public */,
      14,    0,  672,    2, 0x06 /* Public */,
      15,    0,  673,    2, 0x06 /* Public */,
      16,    1,  674,    2, 0x06 /* Public */,
      18,    1,  677,    2, 0x06 /* Public */,
      19,    1,  680,    2, 0x06 /* Public */,
      20,    0,  683,    2, 0x06 /* Public */,
      21,    1,  684,    2, 0x06 /* Public */,
      23,    1,  687,    2, 0x06 /* Public */,
      25,    2,  690,    2, 0x06 /* Public */,
      27,    2,  695,    2, 0x06 /* Public */,
      28,    2,  700,    2, 0x06 /* Public */,
      29,    3,  705,    2, 0x06 /* Public */,
      32,    3,  712,    2, 0x06 /* Public */,
      36,    2,  719,    2, 0x06 /* Public */,
      38,    1,  724,    2, 0x06 /* Public */,
      39,    1,  727,    2, 0x06 /* Public */,
      40,    1,  730,    2, 0x06 /* Public */,
      41,    1,  733,    2, 0x06 /* Public */,
      42,    1,  736,    2, 0x06 /* Public */,
      43,    1,  739,    2, 0x06 /* Public */,
      44,    1,  742,    2, 0x06 /* Public */,
      45,    1,  745,    2, 0x06 /* Public */,
      46,    2,  748,    2, 0x06 /* Public */,
      47,    1,  753,    2, 0x06 /* Public */,
      48,    1,  756,    2, 0x06 /* Public */,
      49,    1,  759,    2, 0x06 /* Public */,
      50,    1,  762,    2, 0x06 /* Public */,
      52,    1,  765,    2, 0x06 /* Public */,
      53,    1,  768,    2, 0x06 /* Public */,
      54,    1,  771,    2, 0x06 /* Public */,
      55,    2,  774,    2, 0x06 /* Public */,
      57,    0,  779,    2, 0x06 /* Public */,
      58,    0,  780,    2, 0x06 /* Public */,
      59,    3,  781,    2, 0x06 /* Public */,
      60,    0,  788,    2, 0x06 /* Public */,
      61,    1,  789,    2, 0x06 /* Public */,
      62,    0,  792,    2, 0x06 /* Public */,
      63,    2,  793,    2, 0x06 /* Public */,
      65,    2,  798,    2, 0x06 /* Public */,
      66,    2,  803,    2, 0x06 /* Public */,
      68,    1,  808,    2, 0x06 /* Public */,
      70,    0,  811,    2, 0x06 /* Public */,
      71,    0,  812,    2, 0x06 /* Public */,
      72,    0,  813,    2, 0x06 /* Public */,
      73,    2,  814,    2, 0x06 /* Public */,
      76,    2,  819,    2, 0x06 /* Public */,
      78,    0,  824,    2, 0x06 /* Public */,
      79,    2,  825,    2, 0x06 /* Public */,
      81,    1,  830,    2, 0x06 /* Public */,
      82,    0,  833,    2, 0x06 /* Public */,
      83,    1,  834,    2, 0x06 /* Public */,
      85,    1,  837,    2, 0x06 /* Public */,
      86,    1,  840,    2, 0x06 /* Public */,
      87,    1,  843,    2, 0x06 /* Public */,
      88,    1,  846,    2, 0x06 /* Public */,
      89,    1,  849,    2, 0x06 /* Public */,
      90,    1,  852,    2, 0x06 /* Public */,
      92,    0,  855,    2, 0x06 /* Public */,
      93,    0,  856,    2, 0x06 /* Public */,
      94,    0,  857,    2, 0x06 /* Public */,
      95,    0,  858,    2, 0x06 /* Public */,
      96,    0,  859,    2, 0x06 /* Public */,
      97,    0,  860,    2, 0x06 /* Public */,
      98,    0,  861,    2, 0x06 /* Public */,
      99,    0,  862,    2, 0x06 /* Public */,
     100,    0,  863,    2, 0x06 /* Public */,
     101,    0,  864,    2, 0x06 /* Public */,
     102,    1,  865,    2, 0x06 /* Public */,
     105,    0,  868,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
     106,    0,  869,    2, 0x0a /* Public */,
     107,    0,  870,    2, 0x0a /* Public */,
     108,    0,  871,    2, 0x0a /* Public */,
     109,    1,  872,    2, 0x0a /* Public */,
     110,    1,  875,    2, 0x0a /* Public */,
     111,    1,  878,    2, 0x0a /* Public */,
     113,    1,  881,    2, 0x0a /* Public */,
     114,    3,  884,    2, 0x0a /* Public */,
     118,    0,  891,    2, 0x0a /* Public */,
     119,    2,  892,    2, 0x0a /* Public */,
     120,    2,  897,    2, 0x0a /* Public */,
     121,    1,  902,    2, 0x0a /* Public */,
     122,    0,  905,    2, 0x0a /* Public */,
     123,    0,  906,    2, 0x0a /* Public */,
     124,    0,  907,    2, 0x0a /* Public */,
     125,    0,  908,    2, 0x0a /* Public */,
     126,    0,  909,    2, 0x0a /* Public */,
     127,    0,  910,    2, 0x0a /* Public */,
     128,    0,  911,    2, 0x0a /* Public */,
     129,    0,  912,    2, 0x0a /* Public */,
     130,    0,  913,    2, 0x0a /* Public */,
     131,    0,  914,    2, 0x0a /* Public */,
     132,    0,  915,    2, 0x0a /* Public */,
     133,    0,  916,    2, 0x0a /* Public */,
     134,    0,  917,    2, 0x0a /* Public */,
     135,    0,  918,    2, 0x0a /* Public */,
     136,    0,  919,    2, 0x0a /* Public */,
     137,    0,  920,    2, 0x0a /* Public */,
     138,    0,  921,    2, 0x0a /* Public */,
     139,    0,  922,    2, 0x0a /* Public */,
     140,    0,  923,    2, 0x0a /* Public */,
     141,    0,  924,    2, 0x0a /* Public */,
     142,    0,  925,    2, 0x0a /* Public */,
     143,    0,  926,    2, 0x0a /* Public */,
     144,    0,  927,    2, 0x0a /* Public */,
     145,    0,  928,    2, 0x0a /* Public */,
     146,    0,  929,    2, 0x0a /* Public */,
     147,    0,  930,    2, 0x0a /* Public */,
     148,    0,  931,    2, 0x0a /* Public */,
     149,    0,  932,    2, 0x0a /* Public */,
     150,    0,  933,    2, 0x0a /* Public */,
     151,    0,  934,    2, 0x0a /* Public */,
     152,    0,  935,    2, 0x0a /* Public */,
     153,    1,  936,    2, 0x0a /* Public */,
     154,    0,  939,    2, 0x0a /* Public */,
     155,    0,  940,    2, 0x0a /* Public */,
     156,    0,  941,    2, 0x0a /* Public */,
     157,    1,  942,    2, 0x0a /* Public */,
     158,    0,  945,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   11,   26,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   11,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Bool,   30,   31,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   33,   34,   35,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   33,   37,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   17,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Bool,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   56,   26,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Bool,   64,   26,
    QMetaType::Void, QMetaType::Float, QMetaType::Bool,   64,   26,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   67,   26,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   74,   75,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   77,   75,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   30,   80,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   84,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::QString,   91,
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
    QMetaType::Void, 0x80000000 | 103,  104,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   77,
    QMetaType::Void, QMetaType::Int,   77,
    QMetaType::Void, QMetaType::Int,  112,
    QMetaType::Void, QMetaType::Int,  112,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int,  115,  116,  117,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   64,   26,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   64,   26,
    QMetaType::Void, QMetaType::Bool,   26,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 103,    2,
    QMetaType::Void,

       0        // eod
};

void State::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        State *_t = static_cast<State *>(_o);
        switch (_id) {
        case 0: _t->stateFinished(); break;
        case 1: _t->gui_busy_start((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->gui_busy_stop((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->gui_busy_stop_error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->gui_setCurrentPageIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->gui_setCurrentPageIndex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->gui_enablePages((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->gui_setTextStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->gui_clearResistancePlot(); break;
        case 9: _t->gui_clearRawDataPlot(); break;
        case 10: _t->gui_clearMemTestPlot(); break;
        case 11: _t->gui_enableActionFillPipette((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->gui_enableActionResetCarousel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->gui_enableActionLoadMicrofil((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->gui_updateCurrentPosition(); break;
        case 15: _t->gui_plotResData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->autopatcher_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->autopatcher_switchBNC((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->autopatcher_softwarePressure((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 19: _t->autopatcher_switchPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 20: _t->autopatcher_setPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 21: _t->autopatcher_breakIn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 22: _t->autopatcher_breakInRamp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 23: _t->headstageClamp_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->headstageClamp_retractWire((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->headstageClamp_threadWire((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->headstageClamp_openClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->headstageClamp_closeClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->headstageClamp_halfClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->scara_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->scara_rotateCarouselNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->scara_enableEndEffector((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 32: _t->scara_openEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->scara_partialCloseEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->scara_closeEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->scara_moveNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->scara_fill1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 37: _t->scara_fill2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->scara_fill3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->scara_dispenseHighPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 40: _t->scara_closePort(); break;
        case 41: _t->scara_calibrate(); break;
        case 42: _t->scara_rotateArm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 43: _t->scara_powerDown(); break;
        case 44: _t->filler_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 45: _t->filler_closePort(); break;
        case 46: _t->filler_aspirateVolume((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 47: _t->filler_dispenseVolume((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 48: _t->filler_enablePressureControl((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 49: _t->thorLabsMotor_init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->thorLabsMotor_calibrate(); break;
        case 51: _t->thorLabsMotor_enable(); break;
        case 52: _t->thorLabsMotor_disable(); break;
        case 53: _t->thorLabsMotor_moveToAbsolute((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 54: _t->thorLabsMotor_moveByRelative((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 55: _t->thorLabsMotor_haltMotor(); break;
        case 56: _t->multiclamp_init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 57: _t->multiclamp_selectChannel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 58: _t->multiclamp_autoPipetteOffset(); break;
        case 59: _t->multiclamp_setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->multiclamp_setHoldingV((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 61: _t->multiclamp_setHoldingI((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 62: _t->multiclamp_holdingVChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 63: _t->multiclamp_holdingIchecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 64: _t->multiclamp_zap((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 65: _t->daq_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 66: _t->daq_initResCheck(); break;
        case 67: _t->daq_triggerRes(); break;
        case 68: _t->daq_initRawAquire(); break;
        case 69: _t->daq_stopRawAquire(); break;
        case 70: _t->daq_startRawAquire(); break;
        case 71: _t->daq_startVRamp(); break;
        case 72: _t->daq_stopVRamp(); break;
        case 73: _t->daq_initMemTest(); break;
        case 74: _t->daq_startMemTest(); break;
        case 75: _t->daq_stopMemTest(); break;
        case 76: _t->daq_guiUpdateMemTestVals((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 77: _t->daq_clearAllTasks(); break;
        case 78: _t->pauseState(); break;
        case 79: _t->resumeState(); break;
        case 80: _t->haltState(); break;
        case 81: _t->gui_upAdjustBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 82: _t->gui_downAdjustBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 83: _t->gui_onCheckBoxkLowV_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 84: _t->gui_onCheckBoxRampOverride_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 85: _t->gui_rotateSCARA((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 86: _t->gui_pushbuttonNextLoadPipettesReleased(); break;
        case 87: _t->gui_dispenseVolumeFiller((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 88: _t->gui_aspirateVolumeFiller((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 89: _t->gui_Load20uLInMicrofil((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 90: _t->vStim_stopped(); break;
        case 91: _t->vStim_started(); break;
        case 92: _t->vStim_paused(); break;
        case 93: _t->autopatcher_initReady(); break;
        case 94: _t->autopatcher_initError(); break;
        case 95: _t->autopatcher_breakInComplete(); break;
        case 96: _t->headstageClamp_initReady(); break;
        case 97: _t->headstageClamp_initError(); break;
        case 98: _t->headstageClamp_commandFinished(); break;
        case 99: _t->scara_initReady(); break;
        case 100: _t->scara_initError(); break;
        case 101: _t->scara_calibrateFinished(); break;
        case 102: _t->scara_commandFinished(); break;
        case 103: _t->filler_initReady(); break;
        case 104: _t->filler_initError(); break;
        case 105: _t->filler_commandFinished(); break;
        case 106: _t->thorLabsMotor_initReady(); break;
        case 107: _t->thorLabsMotor_initError(); break;
        case 108: _t->thorLabsMotor_calibrateFinished(); break;
        case 109: _t->thorLabsMotor_moveComplete(); break;
        case 110: _t->thorLabsMotor_enabled(); break;
        case 111: _t->throLabsMotor_disabled(); break;
        case 112: _t->multiclamp_initReady(); break;
        case 113: _t->multiclamp_initError(); break;
        case 114: _t->multiclamp_autoPipetteOffsetComplete(); break;
        case 115: _t->multiclamp_zapComplete(); break;
        case 116: _t->daq_initReady(); break;
        case 117: _t->daq_initError(); break;
        case 118: _t->daq_initResCheckReady(); break;
        case 119: _t->daq_initResCheckError(); break;
        case 120: _t->daq_resCheckStopped(); break;
        case 121: _t->daq_resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 122: _t->daq_rawDataReady(); break;
        case 123: _t->daq_memTestInitReady(); break;
        case 124: _t->daq_memTestInitError(); break;
        case 125: _t->daq_memTestValsReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 126: _t->daq_rawMemTestDataReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 76:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 125:
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
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::stateFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_busy_start)) {
                *result = 1;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_busy_stop)) {
                *result = 2;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_busy_stop_error)) {
                *result = 3;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_setCurrentPageIndex)) {
                *result = 4;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_setCurrentPageIndex)) {
                *result = 5;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enablePages)) {
                *result = 6;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_setTextStatus)) {
                *result = 7;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_clearResistancePlot)) {
                *result = 8;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_clearRawDataPlot)) {
                *result = 9;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_clearMemTestPlot)) {
                *result = 10;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enableActionFillPipette)) {
                *result = 11;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enableActionResetCarousel)) {
                *result = 12;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enableActionLoadMicrofil)) {
                *result = 13;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_updateCurrentPosition)) {
                *result = 14;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_plotResData)) {
                *result = 15;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_init)) {
                *result = 16;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_switchBNC)) {
                *result = 17;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_softwarePressure)) {
                *result = 18;
            }
        }
        {
            typedef void (State::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_switchPressure)) {
                *result = 19;
            }
        }
        {
            typedef void (State::*_t)(int , double , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_setPressure)) {
                *result = 20;
            }
        }
        {
            typedef void (State::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_breakIn)) {
                *result = 21;
            }
        }
        {
            typedef void (State::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_breakInRamp)) {
                *result = 22;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_init)) {
                *result = 23;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_retractWire)) {
                *result = 24;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_threadWire)) {
                *result = 25;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_openClamp)) {
                *result = 26;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_closeClamp)) {
                *result = 27;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_halfClamp)) {
                *result = 28;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_init)) {
                *result = 29;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_rotateCarouselNext)) {
                *result = 30;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_enableEndEffector)) {
                *result = 31;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_openEndEffector)) {
                *result = 32;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_partialCloseEndEffector)) {
                *result = 33;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_closeEndEffector)) {
                *result = 34;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_moveNext)) {
                *result = 35;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_fill1)) {
                *result = 36;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_fill2)) {
                *result = 37;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_fill3)) {
                *result = 38;
            }
        }
        {
            typedef void (State::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_dispenseHighPressure)) {
                *result = 39;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_closePort)) {
                *result = 40;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_calibrate)) {
                *result = 41;
            }
        }
        {
            typedef void (State::*_t)(int , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_rotateArm)) {
                *result = 42;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_powerDown)) {
                *result = 43;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_init)) {
                *result = 44;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_closePort)) {
                *result = 45;
            }
        }
        {
            typedef void (State::*_t)(float , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_aspirateVolume)) {
                *result = 46;
            }
        }
        {
            typedef void (State::*_t)(float , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_dispenseVolume)) {
                *result = 47;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_enablePressureControl)) {
                *result = 48;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_init)) {
                *result = 49;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_calibrate)) {
                *result = 50;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_enable)) {
                *result = 51;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_disable)) {
                *result = 52;
            }
        }
        {
            typedef void (State::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_moveToAbsolute)) {
                *result = 53;
            }
        }
        {
            typedef void (State::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_moveByRelative)) {
                *result = 54;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_haltMotor)) {
                *result = 55;
            }
        }
        {
            typedef void (State::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_init)) {
                *result = 56;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_selectChannel)) {
                *result = 57;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_autoPipetteOffset)) {
                *result = 58;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setMode)) {
                *result = 59;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingV)) {
                *result = 60;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingI)) {
                *result = 61;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_holdingVChecked)) {
                *result = 62;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_holdingIchecked)) {
                *result = 63;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_zap)) {
                *result = 64;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_init)) {
                *result = 65;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_initResCheck)) {
                *result = 66;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_triggerRes)) {
                *result = 67;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_initRawAquire)) {
                *result = 68;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_stopRawAquire)) {
                *result = 69;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_startRawAquire)) {
                *result = 70;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_startVRamp)) {
                *result = 71;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_stopVRamp)) {
                *result = 72;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_initMemTest)) {
                *result = 73;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_startMemTest)) {
                *result = 74;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_stopMemTest)) {
                *result = 75;
            }
        }
        {
            typedef void (State::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_guiUpdateMemTestVals)) {
                *result = 76;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_clearAllTasks)) {
                *result = 77;
            }
        }
    }
}

const QMetaObject State::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_State.data,
      qt_meta_data_State,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *State::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *State::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_State.stringdata))
        return static_cast<void*>(const_cast< State*>(this));
    return QObject::qt_metacast(_clname);
}

int State::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 127)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 127;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 127)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 127;
    }
    return _id;
}

// SIGNAL 0
void State::stateFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void State::gui_busy_start(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void State::gui_busy_stop(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void State::gui_busy_stop_error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void State::gui_setCurrentPageIndex(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void State::gui_setCurrentPageIndex(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void State::gui_enablePages(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void State::gui_setTextStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void State::gui_clearResistancePlot()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void State::gui_clearRawDataPlot()
{
    QMetaObject::activate(this, &staticMetaObject, 9, Q_NULLPTR);
}

// SIGNAL 10
void State::gui_clearMemTestPlot()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void State::gui_enableActionFillPipette(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void State::gui_enableActionResetCarousel(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void State::gui_enableActionLoadMicrofil(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void State::gui_updateCurrentPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 14, Q_NULLPTR);
}

// SIGNAL 15
void State::gui_plotResData(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void State::autopatcher_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void State::autopatcher_switchBNC(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void State::autopatcher_softwarePressure(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void State::autopatcher_switchPressure(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void State::autopatcher_setPressure(int _t1, double _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void State::autopatcher_breakIn(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void State::autopatcher_breakInRamp(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void State::headstageClamp_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void State::headstageClamp_retractWire(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void State::headstageClamp_threadWire(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void State::headstageClamp_openClamp(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void State::headstageClamp_closeClamp(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void State::headstageClamp_halfClamp(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void State::scara_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 29, _a);
}

// SIGNAL 30
void State::scara_rotateCarouselNext(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void State::scara_enableEndEffector(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 31, _a);
}

// SIGNAL 32
void State::scara_openEndEffector(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 33
void State::scara_partialCloseEndEffector(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 33, _a);
}

// SIGNAL 34
void State::scara_closeEndEffector(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void State::scara_moveNext(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void State::scara_fill1(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void State::scara_fill2(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 37, _a);
}

// SIGNAL 38
void State::scara_fill3(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void State::scara_dispenseHighPressure(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 40
void State::scara_closePort()
{
    QMetaObject::activate(this, &staticMetaObject, 40, Q_NULLPTR);
}

// SIGNAL 41
void State::scara_calibrate()
{
    QMetaObject::activate(this, &staticMetaObject, 41, Q_NULLPTR);
}

// SIGNAL 42
void State::scara_rotateArm(int _t1, bool _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 42, _a);
}

// SIGNAL 43
void State::scara_powerDown()
{
    QMetaObject::activate(this, &staticMetaObject, 43, Q_NULLPTR);
}

// SIGNAL 44
void State::filler_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 44, _a);
}

// SIGNAL 45
void State::filler_closePort()
{
    QMetaObject::activate(this, &staticMetaObject, 45, Q_NULLPTR);
}

// SIGNAL 46
void State::filler_aspirateVolume(float _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 46, _a);
}

// SIGNAL 47
void State::filler_dispenseVolume(float _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 47, _a);
}

// SIGNAL 48
void State::filler_enablePressureControl(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 48, _a);
}

// SIGNAL 49
void State::thorLabsMotor_init(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 49, _a);
}

// SIGNAL 50
void State::thorLabsMotor_calibrate()
{
    QMetaObject::activate(this, &staticMetaObject, 50, Q_NULLPTR);
}

// SIGNAL 51
void State::thorLabsMotor_enable()
{
    QMetaObject::activate(this, &staticMetaObject, 51, Q_NULLPTR);
}

// SIGNAL 52
void State::thorLabsMotor_disable()
{
    QMetaObject::activate(this, &staticMetaObject, 52, Q_NULLPTR);
}

// SIGNAL 53
void State::thorLabsMotor_moveToAbsolute(float _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 53, _a);
}

// SIGNAL 54
void State::thorLabsMotor_moveByRelative(float _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 54, _a);
}

// SIGNAL 55
void State::thorLabsMotor_haltMotor()
{
    QMetaObject::activate(this, &staticMetaObject, 55, Q_NULLPTR);
}

// SIGNAL 56
void State::multiclamp_init(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 56, _a);
}

// SIGNAL 57
void State::multiclamp_selectChannel(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 57, _a);
}

// SIGNAL 58
void State::multiclamp_autoPipetteOffset()
{
    QMetaObject::activate(this, &staticMetaObject, 58, Q_NULLPTR);
}

// SIGNAL 59
void State::multiclamp_setMode(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 59, _a);
}

// SIGNAL 60
void State::multiclamp_setHoldingV(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 60, _a);
}

// SIGNAL 61
void State::multiclamp_setHoldingI(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 61, _a);
}

// SIGNAL 62
void State::multiclamp_holdingVChecked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 62, _a);
}

// SIGNAL 63
void State::multiclamp_holdingIchecked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 63, _a);
}

// SIGNAL 64
void State::multiclamp_zap(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 64, _a);
}

// SIGNAL 65
void State::daq_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 65, _a);
}

// SIGNAL 66
void State::daq_initResCheck()
{
    QMetaObject::activate(this, &staticMetaObject, 66, Q_NULLPTR);
}

// SIGNAL 67
void State::daq_triggerRes()
{
    QMetaObject::activate(this, &staticMetaObject, 67, Q_NULLPTR);
}

// SIGNAL 68
void State::daq_initRawAquire()
{
    QMetaObject::activate(this, &staticMetaObject, 68, Q_NULLPTR);
}

// SIGNAL 69
void State::daq_stopRawAquire()
{
    QMetaObject::activate(this, &staticMetaObject, 69, Q_NULLPTR);
}

// SIGNAL 70
void State::daq_startRawAquire()
{
    QMetaObject::activate(this, &staticMetaObject, 70, Q_NULLPTR);
}

// SIGNAL 71
void State::daq_startVRamp()
{
    QMetaObject::activate(this, &staticMetaObject, 71, Q_NULLPTR);
}

// SIGNAL 72
void State::daq_stopVRamp()
{
    QMetaObject::activate(this, &staticMetaObject, 72, Q_NULLPTR);
}

// SIGNAL 73
void State::daq_initMemTest()
{
    QMetaObject::activate(this, &staticMetaObject, 73, Q_NULLPTR);
}

// SIGNAL 74
void State::daq_startMemTest()
{
    QMetaObject::activate(this, &staticMetaObject, 74, Q_NULLPTR);
}

// SIGNAL 75
void State::daq_stopMemTest()
{
    QMetaObject::activate(this, &staticMetaObject, 75, Q_NULLPTR);
}

// SIGNAL 76
void State::daq_guiUpdateMemTestVals(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 76, _a);
}

// SIGNAL 77
void State::daq_clearAllTasks()
{
    QMetaObject::activate(this, &staticMetaObject, 77, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
