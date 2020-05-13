/****************************************************************************
** Meta object code from reading C++ file 'state.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/state.h"
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
    QByteArrayData data[232];
    char stringdata[4598];
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
QT_MOC_LITERAL(16, 215, 17), // "gui_enableActions"
QT_MOC_LITERAL(17, 233, 6), // "enable"
QT_MOC_LITERAL(18, 240, 23), // "gui_enablePushButtonGO1"
QT_MOC_LITERAL(19, 264, 21), // "gui_pauseButtonEnable"
QT_MOC_LITERAL(20, 286, 22), // "gui_pauseButtonVisible"
QT_MOC_LITERAL(21, 309, 28), // "gui_enablePushButtonUpAdjust"
QT_MOC_LITERAL(22, 338, 30), // "gui_enablePushButtonDownAdjust"
QT_MOC_LITERAL(23, 369, 23), // "gui_enablePushButtonGO3"
QT_MOC_LITERAL(24, 393, 29), // "gui_enablePushButtonCalibrate"
QT_MOC_LITERAL(25, 423, 24), // "gui_incrementTrialNumber"
QT_MOC_LITERAL(26, 448, 27), // "gui_checkedBrainHeightReset"
QT_MOC_LITERAL(27, 476, 7), // "checked"
QT_MOC_LITERAL(28, 484, 25), // "gui_updateCurrentPosition"
QT_MOC_LITERAL(29, 510, 30), // "gui_updateCurrentBrainPosition"
QT_MOC_LITERAL(30, 541, 5), // "depth"
QT_MOC_LITERAL(31, 547, 15), // "gui_plotResData"
QT_MOC_LITERAL(32, 563, 3), // "res"
QT_MOC_LITERAL(33, 567, 28), // "gui_updateMembraneTestValues"
QT_MOC_LITERAL(34, 596, 15), // "QVector<double>"
QT_MOC_LITERAL(35, 612, 4), // "vals"
QT_MOC_LITERAL(36, 617, 16), // "autopatcher_init"
QT_MOC_LITERAL(37, 634, 4), // "port"
QT_MOC_LITERAL(38, 639, 21), // "autopatcher_switchBNC"
QT_MOC_LITERAL(39, 661, 9), // "sendEvent"
QT_MOC_LITERAL(40, 671, 28), // "autopatcher_softwarePressure"
QT_MOC_LITERAL(41, 700, 26), // "autopatcher_switchPressure"
QT_MOC_LITERAL(42, 727, 23), // "autopatcher_setPressure"
QT_MOC_LITERAL(43, 751, 3), // "num"
QT_MOC_LITERAL(44, 755, 3), // "val"
QT_MOC_LITERAL(45, 759, 19), // "autopatcher_breakIn"
QT_MOC_LITERAL(46, 779, 4), // "time"
QT_MOC_LITERAL(47, 784, 13), // "msWatiBetween"
QT_MOC_LITERAL(48, 798, 9), // "numPulses"
QT_MOC_LITERAL(49, 808, 23), // "autopatcher_breakInRamp"
QT_MOC_LITERAL(50, 832, 8), // "pressure"
QT_MOC_LITERAL(51, 841, 31), // "autopatcher_breakInRampFeedback"
QT_MOC_LITERAL(52, 873, 20), // "autopatcher_stopRamp"
QT_MOC_LITERAL(53, 894, 19), // "headstageClamp_init"
QT_MOC_LITERAL(54, 914, 26), // "headstageClamp_retractWire"
QT_MOC_LITERAL(55, 941, 25), // "headstageClamp_threadWire"
QT_MOC_LITERAL(56, 967, 24), // "headstageClamp_openClamp"
QT_MOC_LITERAL(57, 992, 25), // "headstageClamp_closeClamp"
QT_MOC_LITERAL(58, 1018, 24), // "headstageClamp_halfClamp"
QT_MOC_LITERAL(59, 1043, 10), // "scara_init"
QT_MOC_LITERAL(60, 1054, 24), // "scara_rotateCarouselNext"
QT_MOC_LITERAL(61, 1079, 23), // "scara_enableEndEffector"
QT_MOC_LITERAL(62, 1103, 21), // "scara_openEndEffector"
QT_MOC_LITERAL(63, 1125, 29), // "scara_partialCloseEndEffector"
QT_MOC_LITERAL(64, 1155, 22), // "scara_closeEndEffector"
QT_MOC_LITERAL(65, 1178, 14), // "scara_moveNext"
QT_MOC_LITERAL(66, 1193, 11), // "scara_fill1"
QT_MOC_LITERAL(67, 1205, 11), // "scara_fill2"
QT_MOC_LITERAL(68, 1217, 11), // "scara_fill3"
QT_MOC_LITERAL(69, 1229, 26), // "scara_dispenseHighPressure"
QT_MOC_LITERAL(70, 1256, 4), // "msec"
QT_MOC_LITERAL(71, 1261, 15), // "scara_closePort"
QT_MOC_LITERAL(72, 1277, 15), // "scara_calibrate"
QT_MOC_LITERAL(73, 1293, 23), // "scara_calibrateCarousel"
QT_MOC_LITERAL(74, 1317, 15), // "scara_rotateArm"
QT_MOC_LITERAL(75, 1333, 15), // "scara_powerDown"
QT_MOC_LITERAL(76, 1349, 13), // "scara_powerUp"
QT_MOC_LITERAL(77, 1363, 13), // "scara_peltier"
QT_MOC_LITERAL(78, 1377, 2), // "on"
QT_MOC_LITERAL(79, 1380, 9), // "scara_fan"
QT_MOC_LITERAL(80, 1390, 11), // "filler_init"
QT_MOC_LITERAL(81, 1402, 16), // "filler_closePort"
QT_MOC_LITERAL(82, 1419, 21), // "filler_aspirateVolume"
QT_MOC_LITERAL(83, 1441, 6), // "volume"
QT_MOC_LITERAL(84, 1448, 21), // "filler_dispenseVolume"
QT_MOC_LITERAL(85, 1470, 28), // "filler_enablePressureControl"
QT_MOC_LITERAL(86, 1499, 7), // "enabled"
QT_MOC_LITERAL(87, 1507, 14), // "filler_valveOn"
QT_MOC_LITERAL(88, 1522, 18), // "thorLabsMotor_init"
QT_MOC_LITERAL(89, 1541, 6), // "serial"
QT_MOC_LITERAL(90, 1548, 23), // "thorLabsMotor_calibrate"
QT_MOC_LITERAL(91, 1572, 20), // "thorLabsMotor_enable"
QT_MOC_LITERAL(92, 1593, 21), // "thorLabsMotor_disable"
QT_MOC_LITERAL(93, 1615, 28), // "thorLabsMotor_moveToAbsolute"
QT_MOC_LITERAL(94, 1644, 3), // "pos"
QT_MOC_LITERAL(95, 1648, 3), // "vel"
QT_MOC_LITERAL(96, 1652, 28), // "thorLabsMotor_moveByRelative"
QT_MOC_LITERAL(97, 1681, 4), // "dist"
QT_MOC_LITERAL(98, 1686, 23), // "thorLabsMotor_haltMotor"
QT_MOC_LITERAL(99, 1710, 25), // "thorLabsMotor_getPosition"
QT_MOC_LITERAL(100, 1736, 15), // "multiclamp_init"
QT_MOC_LITERAL(101, 1752, 4), // "path"
QT_MOC_LITERAL(102, 1757, 24), // "multiclamp_selectChannel"
QT_MOC_LITERAL(103, 1782, 28), // "multiclamp_autoPipetteOffset"
QT_MOC_LITERAL(104, 1811, 30), // "multiclamp_autoFastCapacitance"
QT_MOC_LITERAL(105, 1842, 30), // "multiclamp_autoSlowCapacitance"
QT_MOC_LITERAL(106, 1873, 34), // "multiclamp_getFastCapacitance..."
QT_MOC_LITERAL(107, 1908, 44), // "multiclamp_getPipetteCapacita..."
QT_MOC_LITERAL(108, 1953, 47), // "multiclamp_enablePipetteCapac..."
QT_MOC_LITERAL(109, 2001, 44), // "multiclamp_setPipetteCapacita..."
QT_MOC_LITERAL(110, 2046, 34), // "multiclamp_setFastCapacitance..."
QT_MOC_LITERAL(111, 2081, 30), // "multiclamp_setWholeCellChecked"
QT_MOC_LITERAL(112, 2112, 28), // "multiclamp_autoBridgeBalance"
QT_MOC_LITERAL(113, 2141, 27), // "multiclamp_setBridgeBalance"
QT_MOC_LITERAL(114, 2169, 8), // "resMOhms"
QT_MOC_LITERAL(115, 2178, 34), // "multiclamp_injectSlowCurrentE..."
QT_MOC_LITERAL(116, 2213, 43), // "multiclamp_injectSlowCurrentS..."
QT_MOC_LITERAL(117, 2257, 38), // "multiclamp_injectSlowCurrentS..."
QT_MOC_LITERAL(118, 2296, 4), // "volt"
QT_MOC_LITERAL(119, 2301, 33), // "multiclamp_leakSubtractionChe..."
QT_MOC_LITERAL(120, 2335, 18), // "multiclamp_setMode"
QT_MOC_LITERAL(121, 2354, 1), // "s"
QT_MOC_LITERAL(122, 2356, 26), // "multiclamp_setHoldingVSafe"
QT_MOC_LITERAL(123, 2383, 5), // "volts"
QT_MOC_LITERAL(124, 2389, 26), // "multiclamp_setHoldingISafe"
QT_MOC_LITERAL(125, 2416, 4), // "amps"
QT_MOC_LITERAL(126, 2421, 25), // "multiclamp_setHoldingVRaw"
QT_MOC_LITERAL(127, 2447, 25), // "multiclamp_setHoldingIRaw"
QT_MOC_LITERAL(128, 2473, 29), // "multiclamp_setHoldingVChecked"
QT_MOC_LITERAL(129, 2503, 29), // "multiclamp_setHoldingIChecked"
QT_MOC_LITERAL(130, 2533, 14), // "multiclamp_zap"
QT_MOC_LITERAL(131, 2548, 10), // "zapTimeSec"
QT_MOC_LITERAL(132, 2559, 23), // "multiclamp_zapWithDelay"
QT_MOC_LITERAL(133, 2583, 11), // "delayTimeMs"
QT_MOC_LITERAL(134, 2595, 27), // "multiclamp_getBridgeBalance"
QT_MOC_LITERAL(135, 2623, 8), // "daq_init"
QT_MOC_LITERAL(136, 2632, 7), // "devName"
QT_MOC_LITERAL(137, 2640, 12), // "daq_initTask"
QT_MOC_LITERAL(138, 2653, 13), // "daq_startTask"
QT_MOC_LITERAL(139, 2667, 12), // "daq_stopTask"
QT_MOC_LITERAL(140, 2680, 18), // "daq_getTaskRunning"
QT_MOC_LITERAL(141, 2699, 11), // "daq_trigger"
QT_MOC_LITERAL(142, 2711, 24), // "daq_guiUpdateMemTestVals"
QT_MOC_LITERAL(143, 2736, 26), // "daq_setCurrentInjAmplitude"
QT_MOC_LITERAL(144, 2763, 10), // "currrentPA"
QT_MOC_LITERAL(145, 2774, 29), // "daq_setBACCurrentInjAmplitude"
QT_MOC_LITERAL(146, 2804, 9), // "currentPA"
QT_MOC_LITERAL(147, 2814, 29), // "daq_setBACCurrentInjFrequency"
QT_MOC_LITERAL(148, 2844, 4), // "freq"
QT_MOC_LITERAL(149, 2849, 11), // "visual_init"
QT_MOC_LITERAL(150, 2861, 9), // "ipAddress"
QT_MOC_LITERAL(151, 2871, 12), // "visual_start"
QT_MOC_LITERAL(152, 2884, 12), // "screenNumber"
QT_MOC_LITERAL(153, 2897, 11), // "visual_stop"
QT_MOC_LITERAL(154, 2909, 12), // "visual_pause"
QT_MOC_LITERAL(155, 2922, 15), // "visual_continue"
QT_MOC_LITERAL(156, 2938, 11), // "length_init"
QT_MOC_LITERAL(157, 2950, 14), // "length_measure"
QT_MOC_LITERAL(158, 2965, 19), // "length_aboutToClose"
QT_MOC_LITERAL(159, 2985, 10), // "pauseState"
QT_MOC_LITERAL(160, 2996, 7), // "toggled"
QT_MOC_LITERAL(161, 3004, 9), // "haltState"
QT_MOC_LITERAL(162, 3014, 15), // "gui_upAdjustBtn"
QT_MOC_LITERAL(163, 3030, 17), // "gui_downAdjustBtn"
QT_MOC_LITERAL(164, 3048, 32), // "gui_onCheckBoxkLowV_stateChanged"
QT_MOC_LITERAL(165, 3081, 4), // "arg1"
QT_MOC_LITERAL(166, 3086, 39), // "gui_onCheckBoxRampOverride_st..."
QT_MOC_LITERAL(167, 3126, 15), // "gui_rotateSCARA"
QT_MOC_LITERAL(168, 3142, 9), // "armNumber"
QT_MOC_LITERAL(169, 3152, 9), // "direction"
QT_MOC_LITERAL(170, 3162, 8), // "numSteps"
QT_MOC_LITERAL(171, 3171, 38), // "gui_pushbuttonNextLoadPipette..."
QT_MOC_LITERAL(172, 3210, 24), // "gui_dispenseVolumeFiller"
QT_MOC_LITERAL(173, 3235, 24), // "gui_aspirateVolumeFiller"
QT_MOC_LITERAL(174, 3260, 22), // "gui_Load20uLInMicrofil"
QT_MOC_LITERAL(175, 3283, 13), // "vStim_stopped"
QT_MOC_LITERAL(176, 3297, 13), // "vStim_started"
QT_MOC_LITERAL(177, 3311, 12), // "vStim_paused"
QT_MOC_LITERAL(178, 3324, 21), // "autopatcher_initReady"
QT_MOC_LITERAL(179, 3346, 21), // "autopatcher_initError"
QT_MOC_LITERAL(180, 3368, 27), // "autopatcher_breakInComplete"
QT_MOC_LITERAL(181, 3396, 31), // "autopatcher_breakInRampFinished"
QT_MOC_LITERAL(182, 3428, 24), // "headstageClamp_initReady"
QT_MOC_LITERAL(183, 3453, 24), // "headstageClamp_initError"
QT_MOC_LITERAL(184, 3478, 30), // "headstageClamp_commandFinished"
QT_MOC_LITERAL(185, 3509, 15), // "scara_initReady"
QT_MOC_LITERAL(186, 3525, 15), // "scara_initError"
QT_MOC_LITERAL(187, 3541, 23), // "scara_calibrateFinished"
QT_MOC_LITERAL(188, 3565, 21), // "scara_commandFinished"
QT_MOC_LITERAL(189, 3587, 16), // "filler_initReady"
QT_MOC_LITERAL(190, 3604, 16), // "filler_initError"
QT_MOC_LITERAL(191, 3621, 22), // "filler_commandFinished"
QT_MOC_LITERAL(192, 3644, 23), // "thorLabsMotor_initReady"
QT_MOC_LITERAL(193, 3668, 23), // "thorLabsMotor_initError"
QT_MOC_LITERAL(194, 3692, 31), // "thorLabsMotor_calibrateFinished"
QT_MOC_LITERAL(195, 3724, 26), // "thorLabsMotor_moveComplete"
QT_MOC_LITERAL(196, 3751, 21), // "thorLabsMotor_enabled"
QT_MOC_LITERAL(197, 3773, 22), // "throLabsMotor_disabled"
QT_MOC_LITERAL(198, 3796, 34), // "thorLabsMotor_currentMotorPos..."
QT_MOC_LITERAL(199, 3831, 20), // "multiclamp_initReady"
QT_MOC_LITERAL(200, 3852, 20), // "multiclamp_initError"
QT_MOC_LITERAL(201, 3873, 36), // "multiclamp_autoPipetteOffsetC..."
QT_MOC_LITERAL(202, 3910, 38), // "multiclamp_autoFastCapacitanc..."
QT_MOC_LITERAL(203, 3949, 22), // "multiclamp_zapComplete"
QT_MOC_LITERAL(204, 3972, 40), // "multiclamp_setHoldingVoltageS..."
QT_MOC_LITERAL(205, 4013, 40), // "multiclamp_setHoldingCurrentS..."
QT_MOC_LITERAL(206, 4054, 46), // "multiclamp_pipetteCapacitance..."
QT_MOC_LITERAL(207, 4101, 40), // "multiclamp_holdingCurrentChec..."
QT_MOC_LITERAL(208, 4142, 35), // "multiclamp_setBridgeBalanceCo..."
QT_MOC_LITERAL(209, 4178, 35), // "multiclamp_getBridgeBalanceCo..."
QT_MOC_LITERAL(210, 4214, 13), // "daq_initReady"
QT_MOC_LITERAL(211, 4228, 13), // "daq_initError"
QT_MOC_LITERAL(212, 4242, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(213, 4260, 17), // "daq_initTaskError"
QT_MOC_LITERAL(214, 4278, 16), // "daq_resDataReady"
QT_MOC_LITERAL(215, 4295, 16), // "daq_rawDataReady"
QT_MOC_LITERAL(216, 4312, 20), // "daq_memTestValsReady"
QT_MOC_LITERAL(217, 4333, 23), // "daq_rawMemTestDataReady"
QT_MOC_LITERAL(218, 4357, 15), // "daq_taskRunning"
QT_MOC_LITERAL(219, 4373, 20), // "daq_currInjDataReady"
QT_MOC_LITERAL(220, 4394, 23), // "daq_bacCurrInjDataReady"
QT_MOC_LITERAL(221, 4418, 16), // "visual_initReady"
QT_MOC_LITERAL(222, 4435, 16), // "visual_initError"
QT_MOC_LITERAL(223, 4452, 14), // "visual_started"
QT_MOC_LITERAL(224, 4467, 13), // "visual_paused"
QT_MOC_LITERAL(225, 4481, 15), // "visual_finished"
QT_MOC_LITERAL(226, 4497, 14), // "visual_stopped"
QT_MOC_LITERAL(227, 4512, 16), // "length_initReady"
QT_MOC_LITERAL(228, 4529, 16), // "length_initError"
QT_MOC_LITERAL(229, 4546, 20), // "length_imagesAquired"
QT_MOC_LITERAL(230, 4567, 23), // "length_measurementReady"
QT_MOC_LITERAL(231, 4591, 6) // "length"

    },
    "State\0stateFinished\0\0gui_busy_start\0"
    "msg\0gui_busy_stop\0gui_busy_stop_error\0"
    "gui_setCurrentPageIndex\0i\0pgObjName\0"
    "gui_enablePages\0flag\0gui_setTextStatus\0"
    "gui_clearResistancePlot\0gui_clearRawDataPlot\0"
    "gui_clearMemTestPlot\0gui_enableActions\0"
    "enable\0gui_enablePushButtonGO1\0"
    "gui_pauseButtonEnable\0gui_pauseButtonVisible\0"
    "gui_enablePushButtonUpAdjust\0"
    "gui_enablePushButtonDownAdjust\0"
    "gui_enablePushButtonGO3\0"
    "gui_enablePushButtonCalibrate\0"
    "gui_incrementTrialNumber\0"
    "gui_checkedBrainHeightReset\0checked\0"
    "gui_updateCurrentPosition\0"
    "gui_updateCurrentBrainPosition\0depth\0"
    "gui_plotResData\0res\0gui_updateMembraneTestValues\0"
    "QVector<double>\0vals\0autopatcher_init\0"
    "port\0autopatcher_switchBNC\0sendEvent\0"
    "autopatcher_softwarePressure\0"
    "autopatcher_switchPressure\0"
    "autopatcher_setPressure\0num\0val\0"
    "autopatcher_breakIn\0time\0msWatiBetween\0"
    "numPulses\0autopatcher_breakInRamp\0"
    "pressure\0autopatcher_breakInRampFeedback\0"
    "autopatcher_stopRamp\0headstageClamp_init\0"
    "headstageClamp_retractWire\0"
    "headstageClamp_threadWire\0"
    "headstageClamp_openClamp\0"
    "headstageClamp_closeClamp\0"
    "headstageClamp_halfClamp\0scara_init\0"
    "scara_rotateCarouselNext\0"
    "scara_enableEndEffector\0scara_openEndEffector\0"
    "scara_partialCloseEndEffector\0"
    "scara_closeEndEffector\0scara_moveNext\0"
    "scara_fill1\0scara_fill2\0scara_fill3\0"
    "scara_dispenseHighPressure\0msec\0"
    "scara_closePort\0scara_calibrate\0"
    "scara_calibrateCarousel\0scara_rotateArm\0"
    "scara_powerDown\0scara_powerUp\0"
    "scara_peltier\0on\0scara_fan\0filler_init\0"
    "filler_closePort\0filler_aspirateVolume\0"
    "volume\0filler_dispenseVolume\0"
    "filler_enablePressureControl\0enabled\0"
    "filler_valveOn\0thorLabsMotor_init\0"
    "serial\0thorLabsMotor_calibrate\0"
    "thorLabsMotor_enable\0thorLabsMotor_disable\0"
    "thorLabsMotor_moveToAbsolute\0pos\0vel\0"
    "thorLabsMotor_moveByRelative\0dist\0"
    "thorLabsMotor_haltMotor\0"
    "thorLabsMotor_getPosition\0multiclamp_init\0"
    "path\0multiclamp_selectChannel\0"
    "multiclamp_autoPipetteOffset\0"
    "multiclamp_autoFastCapacitance\0"
    "multiclamp_autoSlowCapacitance\0"
    "multiclamp_getFastCapacitanceValue\0"
    "multiclamp_getPipetteCapacitanceCompensation\0"
    "multiclamp_enablePipetteCapacitanceCompensation\0"
    "multiclamp_setPipetteCapacitanceCompensation\0"
    "multiclamp_setFastCapacitanceValue\0"
    "multiclamp_setWholeCellChecked\0"
    "multiclamp_autoBridgeBalance\0"
    "multiclamp_setBridgeBalance\0resMOhms\0"
    "multiclamp_injectSlowCurrentEnable\0"
    "multiclamp_injectSlowCurrentSetTimeConstant\0"
    "multiclamp_injectSlowCurrentSetVoltage\0"
    "volt\0multiclamp_leakSubtractionChecked\0"
    "multiclamp_setMode\0s\0multiclamp_setHoldingVSafe\0"
    "volts\0multiclamp_setHoldingISafe\0amps\0"
    "multiclamp_setHoldingVRaw\0"
    "multiclamp_setHoldingIRaw\0"
    "multiclamp_setHoldingVChecked\0"
    "multiclamp_setHoldingIChecked\0"
    "multiclamp_zap\0zapTimeSec\0"
    "multiclamp_zapWithDelay\0delayTimeMs\0"
    "multiclamp_getBridgeBalance\0daq_init\0"
    "devName\0daq_initTask\0daq_startTask\0"
    "daq_stopTask\0daq_getTaskRunning\0"
    "daq_trigger\0daq_guiUpdateMemTestVals\0"
    "daq_setCurrentInjAmplitude\0currrentPA\0"
    "daq_setBACCurrentInjAmplitude\0currentPA\0"
    "daq_setBACCurrentInjFrequency\0freq\0"
    "visual_init\0ipAddress\0visual_start\0"
    "screenNumber\0visual_stop\0visual_pause\0"
    "visual_continue\0length_init\0length_measure\0"
    "length_aboutToClose\0pauseState\0toggled\0"
    "haltState\0gui_upAdjustBtn\0gui_downAdjustBtn\0"
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
    "autopatcher_breakInRampFinished\0"
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
    "thorLabsMotor_currentMotorPosition\0"
    "multiclamp_initReady\0multiclamp_initError\0"
    "multiclamp_autoPipetteOffsetComplete\0"
    "multiclamp_autoFastCapacitanceComplete\0"
    "multiclamp_zapComplete\0"
    "multiclamp_setHoldingVoltageSafeComplete\0"
    "multiclamp_setHoldingCurrentSafeComplete\0"
    "multiclamp_pipetteCapacitanceCompensationValue\0"
    "multiclamp_holdingCurrentCheckedComplete\0"
    "multiclamp_setBridgeBalanceComplete\0"
    "multiclamp_getBridgeBalanceComplete\0"
    "daq_initReady\0daq_initError\0"
    "daq_initTaskReady\0daq_initTaskError\0"
    "daq_resDataReady\0daq_rawDataReady\0"
    "daq_memTestValsReady\0daq_rawMemTestDataReady\0"
    "daq_taskRunning\0daq_currInjDataReady\0"
    "daq_bacCurrInjDataReady\0visual_initReady\0"
    "visual_initError\0visual_started\0"
    "visual_paused\0visual_finished\0"
    "visual_stopped\0length_initReady\0"
    "length_initError\0length_imagesAquired\0"
    "length_measurementReady\0length"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_State[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     210,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
     142,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0, 1064,    2, 0x06 /* Public */,
       3,    1, 1065,    2, 0x06 /* Public */,
       5,    1, 1068,    2, 0x06 /* Public */,
       6,    1, 1071,    2, 0x06 /* Public */,
       7,    1, 1074,    2, 0x06 /* Public */,
       7,    1, 1077,    2, 0x06 /* Public */,
      10,    1, 1080,    2, 0x06 /* Public */,
      12,    1, 1083,    2, 0x06 /* Public */,
      13,    0, 1086,    2, 0x06 /* Public */,
      14,    0, 1087,    2, 0x06 /* Public */,
      15,    0, 1088,    2, 0x06 /* Public */,
      16,    1, 1089,    2, 0x06 /* Public */,
      18,    1, 1092,    2, 0x06 /* Public */,
      19,    1, 1095,    2, 0x06 /* Public */,
      20,    1, 1098,    2, 0x06 /* Public */,
      21,    1, 1101,    2, 0x06 /* Public */,
      22,    1, 1104,    2, 0x06 /* Public */,
      23,    1, 1107,    2, 0x06 /* Public */,
      24,    1, 1110,    2, 0x06 /* Public */,
      25,    0, 1113,    2, 0x06 /* Public */,
      26,    1, 1114,    2, 0x06 /* Public */,
      28,    0, 1117,    2, 0x06 /* Public */,
      29,    1, 1118,    2, 0x06 /* Public */,
      31,    1, 1121,    2, 0x06 /* Public */,
      33,    1, 1124,    2, 0x06 /* Public */,
      36,    1, 1127,    2, 0x06 /* Public */,
      38,    2, 1130,    2, 0x06 /* Public */,
      38,    1, 1135,    2, 0x26 /* Public | MethodCloned */,
      40,    2, 1138,    2, 0x06 /* Public */,
      40,    1, 1143,    2, 0x26 /* Public | MethodCloned */,
      41,    2, 1146,    2, 0x06 /* Public */,
      41,    1, 1151,    2, 0x26 /* Public | MethodCloned */,
      42,    3, 1154,    2, 0x06 /* Public */,
      42,    2, 1161,    2, 0x26 /* Public | MethodCloned */,
      45,    3, 1166,    2, 0x06 /* Public */,
      49,    2, 1173,    2, 0x06 /* Public */,
      51,    1, 1178,    2, 0x06 /* Public */,
      52,    0, 1181,    2, 0x06 /* Public */,
      53,    1, 1182,    2, 0x06 /* Public */,
      54,    1, 1185,    2, 0x06 /* Public */,
      54,    0, 1188,    2, 0x26 /* Public | MethodCloned */,
      55,    1, 1189,    2, 0x06 /* Public */,
      55,    0, 1192,    2, 0x26 /* Public | MethodCloned */,
      56,    1, 1193,    2, 0x06 /* Public */,
      56,    0, 1196,    2, 0x26 /* Public | MethodCloned */,
      57,    1, 1197,    2, 0x06 /* Public */,
      57,    0, 1200,    2, 0x26 /* Public | MethodCloned */,
      58,    1, 1201,    2, 0x06 /* Public */,
      58,    0, 1204,    2, 0x26 /* Public | MethodCloned */,
      59,    1, 1205,    2, 0x06 /* Public */,
      60,    1, 1208,    2, 0x06 /* Public */,
      61,    2, 1211,    2, 0x06 /* Public */,
      61,    1, 1216,    2, 0x26 /* Public | MethodCloned */,
      62,    1, 1219,    2, 0x06 /* Public */,
      63,    1, 1222,    2, 0x06 /* Public */,
      63,    0, 1225,    2, 0x26 /* Public | MethodCloned */,
      64,    1, 1226,    2, 0x06 /* Public */,
      64,    0, 1229,    2, 0x26 /* Public | MethodCloned */,
      65,    1, 1230,    2, 0x06 /* Public */,
      65,    0, 1233,    2, 0x26 /* Public | MethodCloned */,
      66,    1, 1234,    2, 0x06 /* Public */,
      66,    0, 1237,    2, 0x26 /* Public | MethodCloned */,
      67,    1, 1238,    2, 0x06 /* Public */,
      67,    0, 1241,    2, 0x26 /* Public | MethodCloned */,
      68,    1, 1242,    2, 0x06 /* Public */,
      68,    0, 1245,    2, 0x26 /* Public | MethodCloned */,
      69,    2, 1246,    2, 0x06 /* Public */,
      69,    1, 1251,    2, 0x26 /* Public | MethodCloned */,
      71,    0, 1254,    2, 0x06 /* Public */,
      72,    0, 1255,    2, 0x06 /* Public */,
      73,    1, 1256,    2, 0x06 /* Public */,
      74,    3, 1259,    2, 0x06 /* Public */,
      75,    0, 1266,    2, 0x06 /* Public */,
      76,    0, 1267,    2, 0x06 /* Public */,
      77,    1, 1268,    2, 0x06 /* Public */,
      79,    1, 1271,    2, 0x06 /* Public */,
      80,    1, 1274,    2, 0x06 /* Public */,
      81,    0, 1277,    2, 0x06 /* Public */,
      82,    2, 1278,    2, 0x06 /* Public */,
      82,    1, 1283,    2, 0x26 /* Public | MethodCloned */,
      84,    2, 1286,    2, 0x06 /* Public */,
      84,    1, 1291,    2, 0x26 /* Public | MethodCloned */,
      85,    2, 1294,    2, 0x06 /* Public */,
      85,    1, 1299,    2, 0x26 /* Public | MethodCloned */,
      87,    1, 1302,    2, 0x06 /* Public */,
      88,    1, 1305,    2, 0x06 /* Public */,
      90,    0, 1308,    2, 0x06 /* Public */,
      91,    0, 1309,    2, 0x06 /* Public */,
      92,    0, 1310,    2, 0x06 /* Public */,
      93,    2, 1311,    2, 0x06 /* Public */,
      96,    2, 1316,    2, 0x06 /* Public */,
      98,    0, 1321,    2, 0x06 /* Public */,
      99,    1, 1322,    2, 0x06 /* Public */,
     100,    2, 1325,    2, 0x06 /* Public */,
     102,    1, 1330,    2, 0x06 /* Public */,
     103,    0, 1333,    2, 0x06 /* Public */,
     104,    0, 1334,    2, 0x06 /* Public */,
     105,    0, 1335,    2, 0x06 /* Public */,
     106,    0, 1336,    2, 0x06 /* Public */,
     107,    0, 1337,    2, 0x06 /* Public */,
     108,    1, 1338,    2, 0x06 /* Public */,
     109,    1, 1341,    2, 0x06 /* Public */,
     110,    1, 1344,    2, 0x06 /* Public */,
     111,    1, 1347,    2, 0x06 /* Public */,
     112,    0, 1350,    2, 0x06 /* Public */,
     113,    2, 1351,    2, 0x06 /* Public */,
     113,    1, 1356,    2, 0x26 /* Public | MethodCloned */,
     115,    1, 1359,    2, 0x06 /* Public */,
     116,    1, 1362,    2, 0x06 /* Public */,
     117,    1, 1365,    2, 0x06 /* Public */,
     119,    1, 1368,    2, 0x06 /* Public */,
     120,    1, 1371,    2, 0x06 /* Public */,
     122,    2, 1374,    2, 0x06 /* Public */,
     122,    1, 1379,    2, 0x26 /* Public | MethodCloned */,
     124,    2, 1382,    2, 0x06 /* Public */,
     124,    1, 1387,    2, 0x26 /* Public | MethodCloned */,
     126,    1, 1390,    2, 0x06 /* Public */,
     127,    1, 1393,    2, 0x06 /* Public */,
     128,    1, 1396,    2, 0x06 /* Public */,
     129,    2, 1399,    2, 0x06 /* Public */,
     129,    1, 1404,    2, 0x26 /* Public | MethodCloned */,
     130,    1, 1407,    2, 0x06 /* Public */,
     132,    2, 1410,    2, 0x06 /* Public */,
     134,    0, 1415,    2, 0x06 /* Public */,
     135,    1, 1416,    2, 0x06 /* Public */,
     137,    1, 1419,    2, 0x06 /* Public */,
     138,    0, 1422,    2, 0x06 /* Public */,
     139,    0, 1423,    2, 0x06 /* Public */,
     140,    0, 1424,    2, 0x06 /* Public */,
     141,    0, 1425,    2, 0x06 /* Public */,
     142,    1, 1426,    2, 0x06 /* Public */,
     143,    1, 1429,    2, 0x06 /* Public */,
     145,    1, 1432,    2, 0x06 /* Public */,
     147,    1, 1435,    2, 0x06 /* Public */,
     149,    2, 1438,    2, 0x06 /* Public */,
     151,    1, 1443,    2, 0x06 /* Public */,
     153,    0, 1446,    2, 0x06 /* Public */,
     154,    0, 1447,    2, 0x06 /* Public */,
     155,    0, 1448,    2, 0x06 /* Public */,
     156,    0, 1449,    2, 0x06 /* Public */,
     157,    0, 1450,    2, 0x06 /* Public */,
     158,    0, 1451,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
     159,    1, 1452,    2, 0x0a /* Public */,
     161,    0, 1455,    2, 0x0a /* Public */,
     162,    1, 1456,    2, 0x0a /* Public */,
     163,    1, 1459,    2, 0x0a /* Public */,
     164,    1, 1462,    2, 0x0a /* Public */,
     166,    1, 1465,    2, 0x0a /* Public */,
     167,    3, 1468,    2, 0x0a /* Public */,
     171,    0, 1475,    2, 0x0a /* Public */,
     172,    2, 1476,    2, 0x0a /* Public */,
     173,    2, 1481,    2, 0x0a /* Public */,
     174,    1, 1486,    2, 0x0a /* Public */,
     175,    0, 1489,    2, 0x0a /* Public */,
     176,    0, 1490,    2, 0x0a /* Public */,
     177,    0, 1491,    2, 0x0a /* Public */,
     178,    0, 1492,    2, 0x0a /* Public */,
     179,    0, 1493,    2, 0x0a /* Public */,
     180,    0, 1494,    2, 0x0a /* Public */,
     181,    0, 1495,    2, 0x0a /* Public */,
     182,    0, 1496,    2, 0x0a /* Public */,
     183,    0, 1497,    2, 0x0a /* Public */,
     184,    0, 1498,    2, 0x0a /* Public */,
     185,    0, 1499,    2, 0x0a /* Public */,
     186,    0, 1500,    2, 0x0a /* Public */,
     187,    0, 1501,    2, 0x0a /* Public */,
     188,    0, 1502,    2, 0x0a /* Public */,
     189,    0, 1503,    2, 0x0a /* Public */,
     190,    0, 1504,    2, 0x0a /* Public */,
     191,    0, 1505,    2, 0x0a /* Public */,
     192,    0, 1506,    2, 0x0a /* Public */,
     193,    0, 1507,    2, 0x0a /* Public */,
     194,    0, 1508,    2, 0x0a /* Public */,
     195,    0, 1509,    2, 0x0a /* Public */,
     196,    0, 1510,    2, 0x0a /* Public */,
     197,    0, 1511,    2, 0x0a /* Public */,
     198,    1, 1512,    2, 0x0a /* Public */,
     199,    0, 1515,    2, 0x0a /* Public */,
     200,    0, 1516,    2, 0x0a /* Public */,
     201,    0, 1517,    2, 0x0a /* Public */,
     202,    0, 1518,    2, 0x0a /* Public */,
     203,    0, 1519,    2, 0x0a /* Public */,
     204,    0, 1520,    2, 0x0a /* Public */,
     205,    0, 1521,    2, 0x0a /* Public */,
     206,    1, 1522,    2, 0x0a /* Public */,
     207,    0, 1525,    2, 0x0a /* Public */,
     208,    0, 1526,    2, 0x0a /* Public */,
     209,    1, 1527,    2, 0x0a /* Public */,
     210,    0, 1530,    2, 0x0a /* Public */,
     211,    0, 1531,    2, 0x0a /* Public */,
     212,    0, 1532,    2, 0x0a /* Public */,
     213,    0, 1533,    2, 0x0a /* Public */,
     214,    1, 1534,    2, 0x0a /* Public */,
     215,    0, 1537,    2, 0x0a /* Public */,
     215,    1, 1538,    2, 0x0a /* Public */,
     216,    1, 1541,    2, 0x0a /* Public */,
     217,    0, 1544,    2, 0x0a /* Public */,
     218,    1, 1545,    2, 0x0a /* Public */,
     219,    1, 1548,    2, 0x0a /* Public */,
     220,    1, 1551,    2, 0x0a /* Public */,
     221,    0, 1554,    2, 0x0a /* Public */,
     222,    0, 1555,    2, 0x0a /* Public */,
     223,    0, 1556,    2, 0x0a /* Public */,
     224,    0, 1557,    2, 0x0a /* Public */,
     225,    0, 1558,    2, 0x0a /* Public */,
     226,    0, 1559,    2, 0x0a /* Public */,
     227,    0, 1560,    2, 0x0a /* Public */,
     228,    0, 1561,    2, 0x0a /* Public */,
     229,    0, 1562,    2, 0x0a /* Public */,
     230,    1, 1563,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   30,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   11,   39,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   11,   39,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   11,   39,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Bool,   43,   44,   39,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   43,   44,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   46,   47,   48,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   46,   50,
    QMetaType::Void, QMetaType::Int,   46,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   17,   39,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   70,   39,
    QMetaType::Void, QMetaType::Int,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   78,
    QMetaType::Void, QMetaType::Bool,   78,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Bool,   83,   39,
    QMetaType::Void, QMetaType::Float,   83,
    QMetaType::Void, QMetaType::Float, QMetaType::Bool,   83,   39,
    QMetaType::Void, QMetaType::Float,   83,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   86,   39,
    QMetaType::Void, QMetaType::Bool,   86,
    QMetaType::Void, QMetaType::Bool,   78,
    QMetaType::Void, QMetaType::Int,   89,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   94,   95,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   97,   95,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   43,  101,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   86,
    QMetaType::Void, QMetaType::Double,   44,
    QMetaType::Void, QMetaType::Double,   44,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Bool,  114,   39,
    QMetaType::Void, QMetaType::Double,  114,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void, QMetaType::Double,   46,
    QMetaType::Void, QMetaType::Double,  118,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Int,  121,
    QMetaType::Void, QMetaType::Double, QMetaType::Bool,  123,   39,
    QMetaType::Void, QMetaType::Double,  123,
    QMetaType::Void, QMetaType::Double, QMetaType::Bool,  125,   39,
    QMetaType::Void, QMetaType::Double,  125,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    2,   39,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Double,  131,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,  131,  133,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  136,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void, QMetaType::Double,  144,
    QMetaType::Void, QMetaType::Double,  146,
    QMetaType::Void, QMetaType::Double,  148,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  150,   37,
    QMetaType::Void, QMetaType::Int,  152,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,  160,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   97,
    QMetaType::Void, QMetaType::Int,   97,
    QMetaType::Void, QMetaType::Int,  165,
    QMetaType::Void, QMetaType::Int,  165,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int,  168,  169,  170,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   83,   39,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   83,   39,
    QMetaType::Void, QMetaType::Bool,   39,
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
    QMetaType::Void, QMetaType::Float,    2,
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
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void, 0x80000000 | 34,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,  231,

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
        case 11: _t->gui_enableActions((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->gui_enablePushButtonGO1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->gui_pauseButtonEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->gui_pauseButtonVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->gui_enablePushButtonUpAdjust((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->gui_enablePushButtonDownAdjust((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->gui_enablePushButtonGO3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->gui_enablePushButtonCalibrate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->gui_incrementTrialNumber(); break;
        case 20: _t->gui_checkedBrainHeightReset((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->gui_updateCurrentPosition(); break;
        case 22: _t->gui_updateCurrentBrainPosition((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->gui_plotResData((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->gui_updateMembraneTestValues((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 25: _t->autopatcher_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: _t->autopatcher_switchBNC((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 27: _t->autopatcher_switchBNC((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->autopatcher_softwarePressure((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 29: _t->autopatcher_softwarePressure((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->autopatcher_switchPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 31: _t->autopatcher_switchPressure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->autopatcher_setPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 33: _t->autopatcher_setPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 34: _t->autopatcher_breakIn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 35: _t->autopatcher_breakInRamp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->autopatcher_breakInRampFeedback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->autopatcher_stopRamp(); break;
        case 38: _t->headstageClamp_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 39: _t->headstageClamp_retractWire((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 40: _t->headstageClamp_retractWire(); break;
        case 41: _t->headstageClamp_threadWire((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->headstageClamp_threadWire(); break;
        case 43: _t->headstageClamp_openClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 44: _t->headstageClamp_openClamp(); break;
        case 45: _t->headstageClamp_closeClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->headstageClamp_closeClamp(); break;
        case 47: _t->headstageClamp_halfClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 48: _t->headstageClamp_halfClamp(); break;
        case 49: _t->scara_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 50: _t->scara_rotateCarouselNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 51: _t->scara_enableEndEffector((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 52: _t->scara_enableEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 53: _t->scara_openEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->scara_partialCloseEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->scara_partialCloseEndEffector(); break;
        case 56: _t->scara_closeEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 57: _t->scara_closeEndEffector(); break;
        case 58: _t->scara_moveNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 59: _t->scara_moveNext(); break;
        case 60: _t->scara_fill1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 61: _t->scara_fill1(); break;
        case 62: _t->scara_fill2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 63: _t->scara_fill2(); break;
        case 64: _t->scara_fill3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 65: _t->scara_fill3(); break;
        case 66: _t->scara_dispenseHighPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 67: _t->scara_dispenseHighPressure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 68: _t->scara_closePort(); break;
        case 69: _t->scara_calibrate(); break;
        case 70: _t->scara_calibrateCarousel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 71: _t->scara_rotateArm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 72: _t->scara_powerDown(); break;
        case 73: _t->scara_powerUp(); break;
        case 74: _t->scara_peltier((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 75: _t->scara_fan((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 76: _t->filler_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 77: _t->filler_closePort(); break;
        case 78: _t->filler_aspirateVolume((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 79: _t->filler_aspirateVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 80: _t->filler_dispenseVolume((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 81: _t->filler_dispenseVolume((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 82: _t->filler_enablePressureControl((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 83: _t->filler_enablePressureControl((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 84: _t->filler_valveOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 85: _t->thorLabsMotor_init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 86: _t->thorLabsMotor_calibrate(); break;
        case 87: _t->thorLabsMotor_enable(); break;
        case 88: _t->thorLabsMotor_disable(); break;
        case 89: _t->thorLabsMotor_moveToAbsolute((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 90: _t->thorLabsMotor_moveByRelative((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 91: _t->thorLabsMotor_haltMotor(); break;
        case 92: _t->thorLabsMotor_getPosition((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 93: _t->multiclamp_init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 94: _t->multiclamp_selectChannel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 95: _t->multiclamp_autoPipetteOffset(); break;
        case 96: _t->multiclamp_autoFastCapacitance(); break;
        case 97: _t->multiclamp_autoSlowCapacitance(); break;
        case 98: _t->multiclamp_getFastCapacitanceValue(); break;
        case 99: _t->multiclamp_getPipetteCapacitanceCompensation(); break;
        case 100: _t->multiclamp_enablePipetteCapacitanceCompensation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 101: _t->multiclamp_setPipetteCapacitanceCompensation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 102: _t->multiclamp_setFastCapacitanceValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 103: _t->multiclamp_setWholeCellChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 104: _t->multiclamp_autoBridgeBalance(); break;
        case 105: _t->multiclamp_setBridgeBalance((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 106: _t->multiclamp_setBridgeBalance((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 107: _t->multiclamp_injectSlowCurrentEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 108: _t->multiclamp_injectSlowCurrentSetTimeConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 109: _t->multiclamp_injectSlowCurrentSetVoltage((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 110: _t->multiclamp_leakSubtractionChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 111: _t->multiclamp_setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 112: _t->multiclamp_setHoldingVSafe((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 113: _t->multiclamp_setHoldingVSafe((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 114: _t->multiclamp_setHoldingISafe((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 115: _t->multiclamp_setHoldingISafe((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 116: _t->multiclamp_setHoldingVRaw((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 117: _t->multiclamp_setHoldingIRaw((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 118: _t->multiclamp_setHoldingVChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 119: _t->multiclamp_setHoldingIChecked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 120: _t->multiclamp_setHoldingIChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 121: _t->multiclamp_zap((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 122: _t->multiclamp_zapWithDelay((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 123: _t->multiclamp_getBridgeBalance(); break;
        case 124: _t->daq_init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 125: _t->daq_initTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 126: _t->daq_startTask(); break;
        case 127: _t->daq_stopTask(); break;
        case 128: _t->daq_getTaskRunning(); break;
        case 129: _t->daq_trigger(); break;
        case 130: _t->daq_guiUpdateMemTestVals((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 131: _t->daq_setCurrentInjAmplitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 132: _t->daq_setBACCurrentInjAmplitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 133: _t->daq_setBACCurrentInjFrequency((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 134: _t->visual_init((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 135: _t->visual_start((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 136: _t->visual_stop(); break;
        case 137: _t->visual_pause(); break;
        case 138: _t->visual_continue(); break;
        case 139: _t->length_init(); break;
        case 140: _t->length_measure(); break;
        case 141: _t->length_aboutToClose(); break;
        case 142: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 143: _t->haltState(); break;
        case 144: _t->gui_upAdjustBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 145: _t->gui_downAdjustBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 146: _t->gui_onCheckBoxkLowV_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 147: _t->gui_onCheckBoxRampOverride_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 148: _t->gui_rotateSCARA((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 149: _t->gui_pushbuttonNextLoadPipettesReleased(); break;
        case 150: _t->gui_dispenseVolumeFiller((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 151: _t->gui_aspirateVolumeFiller((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 152: _t->gui_Load20uLInMicrofil((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 153: _t->vStim_stopped(); break;
        case 154: _t->vStim_started(); break;
        case 155: _t->vStim_paused(); break;
        case 156: _t->autopatcher_initReady(); break;
        case 157: _t->autopatcher_initError(); break;
        case 158: _t->autopatcher_breakInComplete(); break;
        case 159: _t->autopatcher_breakInRampFinished(); break;
        case 160: _t->headstageClamp_initReady(); break;
        case 161: _t->headstageClamp_initError(); break;
        case 162: _t->headstageClamp_commandFinished(); break;
        case 163: _t->scara_initReady(); break;
        case 164: _t->scara_initError(); break;
        case 165: _t->scara_calibrateFinished(); break;
        case 166: _t->scara_commandFinished(); break;
        case 167: _t->filler_initReady(); break;
        case 168: _t->filler_initError(); break;
        case 169: _t->filler_commandFinished(); break;
        case 170: _t->thorLabsMotor_initReady(); break;
        case 171: _t->thorLabsMotor_initError(); break;
        case 172: _t->thorLabsMotor_calibrateFinished(); break;
        case 173: _t->thorLabsMotor_moveComplete(); break;
        case 174: _t->thorLabsMotor_enabled(); break;
        case 175: _t->throLabsMotor_disabled(); break;
        case 176: _t->thorLabsMotor_currentMotorPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 177: _t->multiclamp_initReady(); break;
        case 178: _t->multiclamp_initError(); break;
        case 179: _t->multiclamp_autoPipetteOffsetComplete(); break;
        case 180: _t->multiclamp_autoFastCapacitanceComplete(); break;
        case 181: _t->multiclamp_zapComplete(); break;
        case 182: _t->multiclamp_setHoldingVoltageSafeComplete(); break;
        case 183: _t->multiclamp_setHoldingCurrentSafeComplete(); break;
        case 184: _t->multiclamp_pipetteCapacitanceCompensationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 185: _t->multiclamp_holdingCurrentCheckedComplete(); break;
        case 186: _t->multiclamp_setBridgeBalanceComplete(); break;
        case 187: _t->multiclamp_getBridgeBalanceComplete((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 188: _t->daq_initReady(); break;
        case 189: _t->daq_initError(); break;
        case 190: _t->daq_initTaskReady(); break;
        case 191: _t->daq_initTaskError(); break;
        case 192: _t->daq_resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 193: _t->daq_rawDataReady(); break;
        case 194: _t->daq_rawDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 195: _t->daq_memTestValsReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 196: _t->daq_rawMemTestDataReady(); break;
        case 197: _t->daq_taskRunning((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 198: _t->daq_currInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 199: _t->daq_bacCurrInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 200: _t->visual_initReady(); break;
        case 201: _t->visual_initError(); break;
        case 202: _t->visual_started(); break;
        case 203: _t->visual_paused(); break;
        case 204: _t->visual_finished(); break;
        case 205: _t->visual_stopped(); break;
        case 206: _t->length_initReady(); break;
        case 207: _t->length_initError(); break;
        case 208: _t->length_imagesAquired(); break;
        case 209: _t->length_measurementReady((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 24:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 130:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 194:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 195:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 198:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 199:
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enableActions)) {
                *result = 11;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enablePushButtonGO1)) {
                *result = 12;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_pauseButtonEnable)) {
                *result = 13;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_pauseButtonVisible)) {
                *result = 14;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enablePushButtonUpAdjust)) {
                *result = 15;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enablePushButtonDownAdjust)) {
                *result = 16;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enablePushButtonGO3)) {
                *result = 17;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_enablePushButtonCalibrate)) {
                *result = 18;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_incrementTrialNumber)) {
                *result = 19;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_checkedBrainHeightReset)) {
                *result = 20;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_updateCurrentPosition)) {
                *result = 21;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_updateCurrentBrainPosition)) {
                *result = 22;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_plotResData)) {
                *result = 23;
            }
        }
        {
            typedef void (State::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::gui_updateMembraneTestValues)) {
                *result = 24;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_init)) {
                *result = 25;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_switchBNC)) {
                *result = 26;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_softwarePressure)) {
                *result = 28;
            }
        }
        {
            typedef void (State::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_switchPressure)) {
                *result = 30;
            }
        }
        {
            typedef void (State::*_t)(int , double , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_setPressure)) {
                *result = 32;
            }
        }
        {
            typedef void (State::*_t)(int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_breakIn)) {
                *result = 34;
            }
        }
        {
            typedef void (State::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_breakInRamp)) {
                *result = 35;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_breakInRampFeedback)) {
                *result = 36;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::autopatcher_stopRamp)) {
                *result = 37;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_init)) {
                *result = 38;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_retractWire)) {
                *result = 39;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_threadWire)) {
                *result = 41;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_openClamp)) {
                *result = 43;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_closeClamp)) {
                *result = 45;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::headstageClamp_halfClamp)) {
                *result = 47;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_init)) {
                *result = 49;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_rotateCarouselNext)) {
                *result = 50;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_enableEndEffector)) {
                *result = 51;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_openEndEffector)) {
                *result = 53;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_partialCloseEndEffector)) {
                *result = 54;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_closeEndEffector)) {
                *result = 56;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_moveNext)) {
                *result = 58;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_fill1)) {
                *result = 60;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_fill2)) {
                *result = 62;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_fill3)) {
                *result = 64;
            }
        }
        {
            typedef void (State::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_dispenseHighPressure)) {
                *result = 66;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_closePort)) {
                *result = 68;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_calibrate)) {
                *result = 69;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_calibrateCarousel)) {
                *result = 70;
            }
        }
        {
            typedef void (State::*_t)(int , bool , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_rotateArm)) {
                *result = 71;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_powerDown)) {
                *result = 72;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_powerUp)) {
                *result = 73;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_peltier)) {
                *result = 74;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::scara_fan)) {
                *result = 75;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_init)) {
                *result = 76;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_closePort)) {
                *result = 77;
            }
        }
        {
            typedef void (State::*_t)(float , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_aspirateVolume)) {
                *result = 78;
            }
        }
        {
            typedef void (State::*_t)(float , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_dispenseVolume)) {
                *result = 80;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_enablePressureControl)) {
                *result = 82;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::filler_valveOn)) {
                *result = 84;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_init)) {
                *result = 85;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_calibrate)) {
                *result = 86;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_enable)) {
                *result = 87;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_disable)) {
                *result = 88;
            }
        }
        {
            typedef void (State::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_moveToAbsolute)) {
                *result = 89;
            }
        }
        {
            typedef void (State::*_t)(float , float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_moveByRelative)) {
                *result = 90;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_haltMotor)) {
                *result = 91;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::thorLabsMotor_getPosition)) {
                *result = 92;
            }
        }
        {
            typedef void (State::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_init)) {
                *result = 93;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_selectChannel)) {
                *result = 94;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_autoPipetteOffset)) {
                *result = 95;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_autoFastCapacitance)) {
                *result = 96;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_autoSlowCapacitance)) {
                *result = 97;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_getFastCapacitanceValue)) {
                *result = 98;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_getPipetteCapacitanceCompensation)) {
                *result = 99;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_enablePipetteCapacitanceCompensation)) {
                *result = 100;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setPipetteCapacitanceCompensation)) {
                *result = 101;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setFastCapacitanceValue)) {
                *result = 102;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setWholeCellChecked)) {
                *result = 103;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_autoBridgeBalance)) {
                *result = 104;
            }
        }
        {
            typedef void (State::*_t)(double , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setBridgeBalance)) {
                *result = 105;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_injectSlowCurrentEnable)) {
                *result = 107;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_injectSlowCurrentSetTimeConstant)) {
                *result = 108;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_injectSlowCurrentSetVoltage)) {
                *result = 109;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_leakSubtractionChecked)) {
                *result = 110;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setMode)) {
                *result = 111;
            }
        }
        {
            typedef void (State::*_t)(double , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingVSafe)) {
                *result = 112;
            }
        }
        {
            typedef void (State::*_t)(double , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingISafe)) {
                *result = 114;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingVRaw)) {
                *result = 116;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingIRaw)) {
                *result = 117;
            }
        }
        {
            typedef void (State::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingVChecked)) {
                *result = 118;
            }
        }
        {
            typedef void (State::*_t)(bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_setHoldingIChecked)) {
                *result = 119;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_zap)) {
                *result = 121;
            }
        }
        {
            typedef void (State::*_t)(double , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_zapWithDelay)) {
                *result = 122;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::multiclamp_getBridgeBalance)) {
                *result = 123;
            }
        }
        {
            typedef void (State::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_init)) {
                *result = 124;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_initTask)) {
                *result = 125;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_startTask)) {
                *result = 126;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_stopTask)) {
                *result = 127;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_getTaskRunning)) {
                *result = 128;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_trigger)) {
                *result = 129;
            }
        }
        {
            typedef void (State::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_guiUpdateMemTestVals)) {
                *result = 130;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_setCurrentInjAmplitude)) {
                *result = 131;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_setBACCurrentInjAmplitude)) {
                *result = 132;
            }
        }
        {
            typedef void (State::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::daq_setBACCurrentInjFrequency)) {
                *result = 133;
            }
        }
        {
            typedef void (State::*_t)(QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::visual_init)) {
                *result = 134;
            }
        }
        {
            typedef void (State::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::visual_start)) {
                *result = 135;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::visual_stop)) {
                *result = 136;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::visual_pause)) {
                *result = 137;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::visual_continue)) {
                *result = 138;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::length_init)) {
                *result = 139;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::length_measure)) {
                *result = 140;
            }
        }
        {
            typedef void (State::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State::length_aboutToClose)) {
                *result = 141;
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
        if (_id < 210)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 210;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 210)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 210;
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
void State::gui_enableActions(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void State::gui_enablePushButtonGO1(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void State::gui_pauseButtonEnable(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void State::gui_pauseButtonVisible(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void State::gui_enablePushButtonUpAdjust(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void State::gui_enablePushButtonDownAdjust(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void State::gui_enablePushButtonGO3(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void State::gui_enablePushButtonCalibrate(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void State::gui_incrementTrialNumber()
{
    QMetaObject::activate(this, &staticMetaObject, 19, Q_NULLPTR);
}

// SIGNAL 20
void State::gui_checkedBrainHeightReset(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void State::gui_updateCurrentPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 21, Q_NULLPTR);
}

// SIGNAL 22
void State::gui_updateCurrentBrainPosition(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void State::gui_plotResData(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}

// SIGNAL 24
void State::gui_updateMembraneTestValues(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 24, _a);
}

// SIGNAL 25
void State::autopatcher_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void State::autopatcher_switchBNC(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 28
void State::autopatcher_softwarePressure(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 30
void State::autopatcher_switchPressure(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 32
void State::autopatcher_setPressure(int _t1, double _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 32, _a);
}

// SIGNAL 34
void State::autopatcher_breakIn(int _t1, int _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 34, _a);
}

// SIGNAL 35
void State::autopatcher_breakInRamp(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 35, _a);
}

// SIGNAL 36
void State::autopatcher_breakInRampFeedback(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 36, _a);
}

// SIGNAL 37
void State::autopatcher_stopRamp()
{
    QMetaObject::activate(this, &staticMetaObject, 37, Q_NULLPTR);
}

// SIGNAL 38
void State::headstageClamp_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 38, _a);
}

// SIGNAL 39
void State::headstageClamp_retractWire(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 39, _a);
}

// SIGNAL 41
void State::headstageClamp_threadWire(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 41, _a);
}

// SIGNAL 43
void State::headstageClamp_openClamp(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 43, _a);
}

// SIGNAL 45
void State::headstageClamp_closeClamp(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 45, _a);
}

// SIGNAL 47
void State::headstageClamp_halfClamp(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 47, _a);
}

// SIGNAL 49
void State::scara_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 49, _a);
}

// SIGNAL 50
void State::scara_rotateCarouselNext(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 50, _a);
}

// SIGNAL 51
void State::scara_enableEndEffector(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 51, _a);
}

// SIGNAL 53
void State::scara_openEndEffector(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 53, _a);
}

// SIGNAL 54
void State::scara_partialCloseEndEffector(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 54, _a);
}

// SIGNAL 56
void State::scara_closeEndEffector(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 56, _a);
}

// SIGNAL 58
void State::scara_moveNext(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 58, _a);
}

// SIGNAL 60
void State::scara_fill1(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 60, _a);
}

// SIGNAL 62
void State::scara_fill2(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 62, _a);
}

// SIGNAL 64
void State::scara_fill3(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 64, _a);
}

// SIGNAL 66
void State::scara_dispenseHighPressure(int _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 66, _a);
}

// SIGNAL 68
void State::scara_closePort()
{
    QMetaObject::activate(this, &staticMetaObject, 68, Q_NULLPTR);
}

// SIGNAL 69
void State::scara_calibrate()
{
    QMetaObject::activate(this, &staticMetaObject, 69, Q_NULLPTR);
}

// SIGNAL 70
void State::scara_calibrateCarousel(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 70, _a);
}

// SIGNAL 71
void State::scara_rotateArm(int _t1, bool _t2, int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 71, _a);
}

// SIGNAL 72
void State::scara_powerDown()
{
    QMetaObject::activate(this, &staticMetaObject, 72, Q_NULLPTR);
}

// SIGNAL 73
void State::scara_powerUp()
{
    QMetaObject::activate(this, &staticMetaObject, 73, Q_NULLPTR);
}

// SIGNAL 74
void State::scara_peltier(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 74, _a);
}

// SIGNAL 75
void State::scara_fan(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 75, _a);
}

// SIGNAL 76
void State::filler_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 76, _a);
}

// SIGNAL 77
void State::filler_closePort()
{
    QMetaObject::activate(this, &staticMetaObject, 77, Q_NULLPTR);
}

// SIGNAL 78
void State::filler_aspirateVolume(float _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 78, _a);
}

// SIGNAL 80
void State::filler_dispenseVolume(float _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 80, _a);
}

// SIGNAL 82
void State::filler_enablePressureControl(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 82, _a);
}

// SIGNAL 84
void State::filler_valveOn(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 84, _a);
}

// SIGNAL 85
void State::thorLabsMotor_init(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 85, _a);
}

// SIGNAL 86
void State::thorLabsMotor_calibrate()
{
    QMetaObject::activate(this, &staticMetaObject, 86, Q_NULLPTR);
}

// SIGNAL 87
void State::thorLabsMotor_enable()
{
    QMetaObject::activate(this, &staticMetaObject, 87, Q_NULLPTR);
}

// SIGNAL 88
void State::thorLabsMotor_disable()
{
    QMetaObject::activate(this, &staticMetaObject, 88, Q_NULLPTR);
}

// SIGNAL 89
void State::thorLabsMotor_moveToAbsolute(float _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 89, _a);
}

// SIGNAL 90
void State::thorLabsMotor_moveByRelative(float _t1, float _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 90, _a);
}

// SIGNAL 91
void State::thorLabsMotor_haltMotor()
{
    QMetaObject::activate(this, &staticMetaObject, 91, Q_NULLPTR);
}

// SIGNAL 92
void State::thorLabsMotor_getPosition(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 92, _a);
}

// SIGNAL 93
void State::multiclamp_init(int _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 93, _a);
}

// SIGNAL 94
void State::multiclamp_selectChannel(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 94, _a);
}

// SIGNAL 95
void State::multiclamp_autoPipetteOffset()
{
    QMetaObject::activate(this, &staticMetaObject, 95, Q_NULLPTR);
}

// SIGNAL 96
void State::multiclamp_autoFastCapacitance()
{
    QMetaObject::activate(this, &staticMetaObject, 96, Q_NULLPTR);
}

// SIGNAL 97
void State::multiclamp_autoSlowCapacitance()
{
    QMetaObject::activate(this, &staticMetaObject, 97, Q_NULLPTR);
}

// SIGNAL 98
void State::multiclamp_getFastCapacitanceValue()
{
    QMetaObject::activate(this, &staticMetaObject, 98, Q_NULLPTR);
}

// SIGNAL 99
void State::multiclamp_getPipetteCapacitanceCompensation()
{
    QMetaObject::activate(this, &staticMetaObject, 99, Q_NULLPTR);
}

// SIGNAL 100
void State::multiclamp_enablePipetteCapacitanceCompensation(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 100, _a);
}

// SIGNAL 101
void State::multiclamp_setPipetteCapacitanceCompensation(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 101, _a);
}

// SIGNAL 102
void State::multiclamp_setFastCapacitanceValue(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 102, _a);
}

// SIGNAL 103
void State::multiclamp_setWholeCellChecked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 103, _a);
}

// SIGNAL 104
void State::multiclamp_autoBridgeBalance()
{
    QMetaObject::activate(this, &staticMetaObject, 104, Q_NULLPTR);
}

// SIGNAL 105
void State::multiclamp_setBridgeBalance(double _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 105, _a);
}

// SIGNAL 107
void State::multiclamp_injectSlowCurrentEnable(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 107, _a);
}

// SIGNAL 108
void State::multiclamp_injectSlowCurrentSetTimeConstant(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 108, _a);
}

// SIGNAL 109
void State::multiclamp_injectSlowCurrentSetVoltage(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 109, _a);
}

// SIGNAL 110
void State::multiclamp_leakSubtractionChecked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 110, _a);
}

// SIGNAL 111
void State::multiclamp_setMode(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 111, _a);
}

// SIGNAL 112
void State::multiclamp_setHoldingVSafe(double _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 112, _a);
}

// SIGNAL 114
void State::multiclamp_setHoldingISafe(double _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 114, _a);
}

// SIGNAL 116
void State::multiclamp_setHoldingVRaw(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 116, _a);
}

// SIGNAL 117
void State::multiclamp_setHoldingIRaw(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 117, _a);
}

// SIGNAL 118
void State::multiclamp_setHoldingVChecked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 118, _a);
}

// SIGNAL 119
void State::multiclamp_setHoldingIChecked(bool _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 119, _a);
}

// SIGNAL 121
void State::multiclamp_zap(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 121, _a);
}

// SIGNAL 122
void State::multiclamp_zapWithDelay(double _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 122, _a);
}

// SIGNAL 123
void State::multiclamp_getBridgeBalance()
{
    QMetaObject::activate(this, &staticMetaObject, 123, Q_NULLPTR);
}

// SIGNAL 124
void State::daq_init(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 124, _a);
}

// SIGNAL 125
void State::daq_initTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 125, _a);
}

// SIGNAL 126
void State::daq_startTask()
{
    QMetaObject::activate(this, &staticMetaObject, 126, Q_NULLPTR);
}

// SIGNAL 127
void State::daq_stopTask()
{
    QMetaObject::activate(this, &staticMetaObject, 127, Q_NULLPTR);
}

// SIGNAL 128
void State::daq_getTaskRunning()
{
    QMetaObject::activate(this, &staticMetaObject, 128, Q_NULLPTR);
}

// SIGNAL 129
void State::daq_trigger()
{
    QMetaObject::activate(this, &staticMetaObject, 129, Q_NULLPTR);
}

// SIGNAL 130
void State::daq_guiUpdateMemTestVals(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 130, _a);
}

// SIGNAL 131
void State::daq_setCurrentInjAmplitude(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 131, _a);
}

// SIGNAL 132
void State::daq_setBACCurrentInjAmplitude(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 132, _a);
}

// SIGNAL 133
void State::daq_setBACCurrentInjFrequency(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 133, _a);
}

// SIGNAL 134
void State::visual_init(QString _t1, QString _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 134, _a);
}

// SIGNAL 135
void State::visual_start(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 135, _a);
}

// SIGNAL 136
void State::visual_stop()
{
    QMetaObject::activate(this, &staticMetaObject, 136, Q_NULLPTR);
}

// SIGNAL 137
void State::visual_pause()
{
    QMetaObject::activate(this, &staticMetaObject, 137, Q_NULLPTR);
}

// SIGNAL 138
void State::visual_continue()
{
    QMetaObject::activate(this, &staticMetaObject, 138, Q_NULLPTR);
}

// SIGNAL 139
void State::length_init()
{
    QMetaObject::activate(this, &staticMetaObject, 139, Q_NULLPTR);
}

// SIGNAL 140
void State::length_measure()
{
    QMetaObject::activate(this, &staticMetaObject, 140, Q_NULLPTR);
}

// SIGNAL 141
void State::length_aboutToClose()
{
    QMetaObject::activate(this, &staticMetaObject, 141, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
