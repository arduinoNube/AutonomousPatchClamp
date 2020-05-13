/****************************************************************************
** Meta object code from reading C++ file 'multiclampworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/workers/multiclampworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiclampworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MulticlampWorker_t {
    QByteArrayData data[59];
    char stringdata[1015];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MulticlampWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MulticlampWorker_t qt_meta_stringdata_MulticlampWorker = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MulticlampWorker"
QT_MOC_LITERAL(1, 17, 9), // "initReady"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "initError"
QT_MOC_LITERAL(4, 38, 12), // "initComplete"
QT_MOC_LITERAL(5, 51, 6), // "zapped"
QT_MOC_LITERAL(6, 58, 14), // "switchPressure"
QT_MOC_LITERAL(7, 73, 3), // "val"
QT_MOC_LITERAL(8, 77, 18), // "autoOffsetComplete"
QT_MOC_LITERAL(9, 96, 27), // "autoFastCapacitanceComplete"
QT_MOC_LITERAL(10, 124, 29), // "setHoldingVoltageSafeComplete"
QT_MOC_LITERAL(11, 154, 29), // "setHoldingCurrentSafeComplete"
QT_MOC_LITERAL(12, 184, 35), // "pipetteCapacitanceCompensatio..."
QT_MOC_LITERAL(13, 220, 29), // "holdingCurrentCheckedComplete"
QT_MOC_LITERAL(14, 250, 24), // "setBridgeBalanceComplete"
QT_MOC_LITERAL(15, 275, 24), // "getBridgeBalanceComplete"
QT_MOC_LITERAL(16, 300, 8), // "resMOhms"
QT_MOC_LITERAL(17, 309, 4), // "init"
QT_MOC_LITERAL(18, 314, 7), // "numMPCS"
QT_MOC_LITERAL(19, 322, 4), // "path"
QT_MOC_LITERAL(20, 327, 7), // "setMode"
QT_MOC_LITERAL(21, 335, 4), // "mode"
QT_MOC_LITERAL(22, 340, 21), // "setHoldingVoltageSafe"
QT_MOC_LITERAL(23, 362, 4), // "volt"
QT_MOC_LITERAL(24, 367, 9), // "sendEvent"
QT_MOC_LITERAL(25, 377, 20), // "setHoldingVoltageRaw"
QT_MOC_LITERAL(26, 398, 21), // "setHoldingCurrentSafe"
QT_MOC_LITERAL(27, 420, 4), // "curr"
QT_MOC_LITERAL(28, 425, 20), // "setHoldingCurrentRaw"
QT_MOC_LITERAL(29, 446, 17), // "autoCorrectOffset"
QT_MOC_LITERAL(30, 464, 13), // "selectChannel"
QT_MOC_LITERAL(31, 478, 2), // "id"
QT_MOC_LITERAL(32, 481, 3), // "zap"
QT_MOC_LITERAL(33, 485, 4), // "time"
QT_MOC_LITERAL(34, 490, 24), // "setHoldingVoltageChecked"
QT_MOC_LITERAL(35, 515, 4), // "flag"
QT_MOC_LITERAL(36, 520, 24), // "setHoldingCurrentChecked"
QT_MOC_LITERAL(37, 545, 19), // "autoSlowCapacitance"
QT_MOC_LITERAL(38, 565, 19), // "autoFastCapacitance"
QT_MOC_LITERAL(39, 585, 23), // "getFastCapacitanceValue"
QT_MOC_LITERAL(40, 609, 36), // "enablePipetteCapacitanceCompe..."
QT_MOC_LITERAL(41, 646, 33), // "setPipetteCapacitanceCompensa..."
QT_MOC_LITERAL(42, 680, 23), // "setFastCapacitanceValue"
QT_MOC_LITERAL(43, 704, 17), // "autoBridgeBalance"
QT_MOC_LITERAL(44, 722, 16), // "setBridgeBalance"
QT_MOC_LITERAL(45, 739, 33), // "getPipetteCapacitanceCompensa..."
QT_MOC_LITERAL(46, 773, 12), // "aboutToClose"
QT_MOC_LITERAL(47, 786, 23), // "injectSlowCurrentEnable"
QT_MOC_LITERAL(48, 810, 32), // "injectSlowCurrentSetTimeConstant"
QT_MOC_LITERAL(49, 843, 27), // "injectSlowCurrentSetVoltage"
QT_MOC_LITERAL(50, 871, 22), // "leakSubtractionChecked"
QT_MOC_LITERAL(51, 894, 7), // "checked"
QT_MOC_LITERAL(52, 902, 15), // "setHardwareVals"
QT_MOC_LITERAL(53, 918, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(54, 942, 16), // "getBridgeBalance"
QT_MOC_LITERAL(55, 959, 19), // "setWholeCellChecked"
QT_MOC_LITERAL(56, 979, 12), // "zapWithDelay"
QT_MOC_LITERAL(57, 992, 10), // "zapTimeSec"
QT_MOC_LITERAL(58, 1003, 11) // "delayTimeMs"

    },
    "MulticlampWorker\0initReady\0\0initError\0"
    "initComplete\0zapped\0switchPressure\0"
    "val\0autoOffsetComplete\0"
    "autoFastCapacitanceComplete\0"
    "setHoldingVoltageSafeComplete\0"
    "setHoldingCurrentSafeComplete\0"
    "pipetteCapacitanceCompensationValue\0"
    "holdingCurrentCheckedComplete\0"
    "setBridgeBalanceComplete\0"
    "getBridgeBalanceComplete\0resMOhms\0"
    "init\0numMPCS\0path\0setMode\0mode\0"
    "setHoldingVoltageSafe\0volt\0sendEvent\0"
    "setHoldingVoltageRaw\0setHoldingCurrentSafe\0"
    "curr\0setHoldingCurrentRaw\0autoCorrectOffset\0"
    "selectChannel\0id\0zap\0time\0"
    "setHoldingVoltageChecked\0flag\0"
    "setHoldingCurrentChecked\0autoSlowCapacitance\0"
    "autoFastCapacitance\0getFastCapacitanceValue\0"
    "enablePipetteCapacitanceCompensation\0"
    "setPipetteCapacitanceCompensation\0"
    "setFastCapacitanceValue\0autoBridgeBalance\0"
    "setBridgeBalance\0getPipetteCapacitanceCompensation\0"
    "aboutToClose\0injectSlowCurrentEnable\0"
    "injectSlowCurrentSetTimeConstant\0"
    "injectSlowCurrentSetVoltage\0"
    "leakSubtractionChecked\0checked\0"
    "setHardwareVals\0HardwareSettingsWindow*\0"
    "getBridgeBalance\0setWholeCellChecked\0"
    "zapWithDelay\0zapTimeSec\0delayTimeMs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MulticlampWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  229,    2, 0x06 /* Public */,
       3,    0,  230,    2, 0x06 /* Public */,
       4,    0,  231,    2, 0x06 /* Public */,
       5,    0,  232,    2, 0x06 /* Public */,
       6,    1,  233,    2, 0x06 /* Public */,
       8,    0,  236,    2, 0x06 /* Public */,
       9,    0,  237,    2, 0x06 /* Public */,
      10,    0,  238,    2, 0x06 /* Public */,
      11,    0,  239,    2, 0x06 /* Public */,
      12,    1,  240,    2, 0x06 /* Public */,
      13,    0,  243,    2, 0x06 /* Public */,
      14,    0,  244,    2, 0x06 /* Public */,
      15,    1,  245,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    2,  248,    2, 0x0a /* Public */,
      20,    1,  253,    2, 0x0a /* Public */,
      22,    2,  256,    2, 0x0a /* Public */,
      25,    1,  261,    2, 0x0a /* Public */,
      26,    2,  264,    2, 0x0a /* Public */,
      28,    1,  269,    2, 0x0a /* Public */,
      29,    0,  272,    2, 0x0a /* Public */,
      30,    1,  273,    2, 0x0a /* Public */,
      32,    1,  276,    2, 0x0a /* Public */,
      34,    1,  279,    2, 0x0a /* Public */,
      36,    2,  282,    2, 0x0a /* Public */,
      36,    1,  287,    2, 0x2a /* Public | MethodCloned */,
      37,    0,  290,    2, 0x0a /* Public */,
      38,    0,  291,    2, 0x0a /* Public */,
      39,    0,  292,    2, 0x0a /* Public */,
      40,    1,  293,    2, 0x0a /* Public */,
      41,    1,  296,    2, 0x0a /* Public */,
      42,    1,  299,    2, 0x0a /* Public */,
      43,    0,  302,    2, 0x0a /* Public */,
      44,    2,  303,    2, 0x0a /* Public */,
      45,    0,  308,    2, 0x0a /* Public */,
      46,    0,  309,    2, 0x0a /* Public */,
      47,    1,  310,    2, 0x0a /* Public */,
      48,    1,  313,    2, 0x0a /* Public */,
      49,    1,  316,    2, 0x0a /* Public */,
      50,    1,  319,    2, 0x0a /* Public */,
      52,    1,  322,    2, 0x0a /* Public */,
      54,    0,  325,    2, 0x0a /* Public */,
      55,    1,  326,    2, 0x0a /* Public */,
      56,    2,  329,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   18,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Double, QMetaType::Bool,   23,   24,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Double, QMetaType::Bool,   27,   24,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   35,   24,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Bool,   16,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Bool,   51,
    QMetaType::Void, 0x80000000 | 53,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, QMetaType::Double, QMetaType::Int,   57,   58,

       0        // eod
};

void MulticlampWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MulticlampWorker *_t = static_cast<MulticlampWorker *>(_o);
        switch (_id) {
        case 0: _t->initReady(); break;
        case 1: _t->initError(); break;
        case 2: _t->initComplete(); break;
        case 3: _t->zapped(); break;
        case 4: _t->switchPressure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->autoOffsetComplete(); break;
        case 6: _t->autoFastCapacitanceComplete(); break;
        case 7: _t->setHoldingVoltageSafeComplete(); break;
        case 8: _t->setHoldingCurrentSafeComplete(); break;
        case 9: _t->pipetteCapacitanceCompensationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->holdingCurrentCheckedComplete(); break;
        case 11: _t->setBridgeBalanceComplete(); break;
        case 12: _t->getBridgeBalanceComplete((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setHoldingVoltageSafe((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->setHoldingVoltageRaw((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->setHoldingCurrentSafe((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 18: _t->setHoldingCurrentRaw((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->autoCorrectOffset(); break;
        case 20: _t->selectChannel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->zap((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->setHoldingVoltageChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->setHoldingCurrentChecked((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 24: _t->setHoldingCurrentChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->autoSlowCapacitance(); break;
        case 26: _t->autoFastCapacitance(); break;
        case 27: { double _r = _t->getFastCapacitanceValue();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 28: _t->enablePipetteCapacitanceCompensation((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->setPipetteCapacitanceCompensation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->setFastCapacitanceValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->autoBridgeBalance(); break;
        case 32: _t->setBridgeBalance((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 33: _t->getPipetteCapacitanceCompensation(); break;
        case 34: _t->aboutToClose(); break;
        case 35: _t->injectSlowCurrentEnable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 36: _t->injectSlowCurrentSetTimeConstant((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 37: _t->injectSlowCurrentSetVoltage((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 38: _t->leakSubtractionChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 40: _t->getBridgeBalance(); break;
        case 41: _t->setWholeCellChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: _t->zapWithDelay((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HardwareSettingsWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::initReady)) {
                *result = 0;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::initError)) {
                *result = 1;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::initComplete)) {
                *result = 2;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::zapped)) {
                *result = 3;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::switchPressure)) {
                *result = 4;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::autoOffsetComplete)) {
                *result = 5;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::autoFastCapacitanceComplete)) {
                *result = 6;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::setHoldingVoltageSafeComplete)) {
                *result = 7;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::setHoldingCurrentSafeComplete)) {
                *result = 8;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::pipetteCapacitanceCompensationValue)) {
                *result = 9;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::holdingCurrentCheckedComplete)) {
                *result = 10;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::setBridgeBalanceComplete)) {
                *result = 11;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::getBridgeBalanceComplete)) {
                *result = 12;
            }
        }
    }
}

const QMetaObject MulticlampWorker::staticMetaObject = {
    { &Worker::staticMetaObject, qt_meta_stringdata_MulticlampWorker.data,
      qt_meta_data_MulticlampWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MulticlampWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MulticlampWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MulticlampWorker.stringdata))
        return static_cast<void*>(const_cast< MulticlampWorker*>(this));
    return Worker::qt_metacast(_clname);
}

int MulticlampWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    }
    return _id;
}

// SIGNAL 0
void MulticlampWorker::initReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MulticlampWorker::initError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MulticlampWorker::initComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MulticlampWorker::zapped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MulticlampWorker::switchPressure(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MulticlampWorker::autoOffsetComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MulticlampWorker::autoFastCapacitanceComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void MulticlampWorker::setHoldingVoltageSafeComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void MulticlampWorker::setHoldingCurrentSafeComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void MulticlampWorker::pipetteCapacitanceCompensationValue(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MulticlampWorker::holdingCurrentCheckedComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void MulticlampWorker::setBridgeBalanceComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void MulticlampWorker::getBridgeBalanceComplete(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}
QT_END_MOC_NAMESPACE
