/****************************************************************************
** Meta object code from reading C++ file 'daqworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/workers/daqworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'daqworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DAQWorker_t {
    QByteArrayData data[39];
    char stringdata[471];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DAQWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DAQWorker_t qt_meta_stringdata_DAQWorker = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DAQWorker"
QT_MOC_LITERAL(1, 10, 9), // "initReady"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 9), // "initError"
QT_MOC_LITERAL(4, 31, 13), // "initTaskReady"
QT_MOC_LITERAL(5, 45, 13), // "initTaskError"
QT_MOC_LITERAL(6, 59, 12), // "rawDataReady"
QT_MOC_LITERAL(7, 72, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 88, 12), // "resDataReady"
QT_MOC_LITERAL(9, 101, 3), // "res"
QT_MOC_LITERAL(10, 105, 16), // "currInjDataReady"
QT_MOC_LITERAL(11, 122, 16), // "memTestValsReady"
QT_MOC_LITERAL(12, 139, 4), // "vals"
QT_MOC_LITERAL(13, 144, 19), // "bacCurrInjDataReady"
QT_MOC_LITERAL(14, 164, 17), // "updateMemTestVals"
QT_MOC_LITERAL(15, 182, 9), // "mTestVals"
QT_MOC_LITERAL(16, 192, 13), // "taskIsRunning"
QT_MOC_LITERAL(17, 206, 4), // "flag"
QT_MOC_LITERAL(18, 211, 12), // "aboutToClose"
QT_MOC_LITERAL(19, 224, 12), // "initInThread"
QT_MOC_LITERAL(20, 237, 4), // "init"
QT_MOC_LITERAL(21, 242, 7), // "devName"
QT_MOC_LITERAL(22, 250, 10), // "setDevName"
QT_MOC_LITERAL(23, 261, 4), // "name"
QT_MOC_LITERAL(24, 266, 8), // "initTask"
QT_MOC_LITERAL(25, 275, 8), // "taskType"
QT_MOC_LITERAL(26, 284, 9), // "startTask"
QT_MOC_LITERAL(27, 294, 8), // "stopTask"
QT_MOC_LITERAL(28, 303, 7), // "trigger"
QT_MOC_LITERAL(29, 311, 13), // "clearAllTasks"
QT_MOC_LITERAL(30, 325, 14), // "getTaskRunning"
QT_MOC_LITERAL(31, 340, 19), // "setCurrInjAmplitude"
QT_MOC_LITERAL(32, 360, 5), // "value"
QT_MOC_LITERAL(33, 366, 22), // "setBACCurrInjAmplitude"
QT_MOC_LITERAL(34, 389, 22), // "setBACCurrInjFrequency"
QT_MOC_LITERAL(35, 412, 15), // "setHardwareVals"
QT_MOC_LITERAL(36, 428, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(37, 452, 6), // "hw_win"
QT_MOC_LITERAL(38, 459, 11) // "acquireData"

    },
    "DAQWorker\0initReady\0\0initError\0"
    "initTaskReady\0initTaskError\0rawDataReady\0"
    "QVector<double>\0resDataReady\0res\0"
    "currInjDataReady\0memTestValsReady\0"
    "vals\0bacCurrInjDataReady\0updateMemTestVals\0"
    "mTestVals\0taskIsRunning\0flag\0aboutToClose\0"
    "initInThread\0init\0devName\0setDevName\0"
    "name\0initTask\0taskType\0startTask\0"
    "stopTask\0trigger\0clearAllTasks\0"
    "getTaskRunning\0setCurrInjAmplitude\0"
    "value\0setBACCurrInjAmplitude\0"
    "setBACCurrInjFrequency\0setHardwareVals\0"
    "HardwareSettingsWindow*\0hw_win\0"
    "acquireData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DAQWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  149,    2, 0x06 /* Public */,
       3,    0,  150,    2, 0x06 /* Public */,
       4,    0,  151,    2, 0x06 /* Public */,
       5,    0,  152,    2, 0x06 /* Public */,
       6,    0,  153,    2, 0x06 /* Public */,
       6,    1,  154,    2, 0x06 /* Public */,
       8,    1,  157,    2, 0x06 /* Public */,
      10,    1,  160,    2, 0x06 /* Public */,
      11,    1,  163,    2, 0x06 /* Public */,
      13,    1,  166,    2, 0x06 /* Public */,
      14,    1,  169,    2, 0x06 /* Public */,
      16,    1,  172,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    0,  175,    2, 0x0a /* Public */,
      19,    0,  176,    2, 0x0a /* Public */,
      20,    1,  177,    2, 0x0a /* Public */,
      22,    1,  180,    2, 0x0a /* Public */,
      24,    1,  183,    2, 0x0a /* Public */,
      26,    0,  186,    2, 0x0a /* Public */,
      27,    0,  187,    2, 0x0a /* Public */,
      28,    0,  188,    2, 0x0a /* Public */,
      29,    0,  189,    2, 0x0a /* Public */,
      30,    0,  190,    2, 0x0a /* Public */,
      31,    1,  191,    2, 0x0a /* Public */,
      33,    1,  194,    2, 0x0a /* Public */,
      34,    1,  197,    2, 0x0a /* Public */,
      35,    1,  200,    2, 0x0a /* Public */,
      38,    0,  203,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,   12,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,   15,
    QMetaType::Void, QMetaType::Int,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void,

       0        // eod
};

void DAQWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DAQWorker *_t = static_cast<DAQWorker *>(_o);
        switch (_id) {
        case 0: _t->initReady(); break;
        case 1: _t->initError(); break;
        case 2: _t->initTaskReady(); break;
        case 3: _t->initTaskError(); break;
        case 4: _t->rawDataReady(); break;
        case 5: _t->rawDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->currInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 8: _t->memTestValsReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 9: _t->bacCurrInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 10: _t->updateMemTestVals((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 11: _t->taskIsRunning((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->aboutToClose(); break;
        case 13: _t->initInThread(); break;
        case 14: _t->init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->setDevName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->initTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->startTask(); break;
        case 18: _t->stopTask(); break;
        case 19: _t->trigger(); break;
        case 20: _t->clearAllTasks(); break;
        case 21: _t->getTaskRunning(); break;
        case 22: _t->setCurrInjAmplitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->setBACCurrInjAmplitude((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->setBACCurrInjFrequency((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 26: _t->acquireData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 25:
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
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initReady)) {
                *result = 0;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initError)) {
                *result = 1;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initTaskReady)) {
                *result = 2;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initTaskError)) {
                *result = 3;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::rawDataReady)) {
                *result = 4;
            }
        }
        {
            typedef void (DAQWorker::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::rawDataReady)) {
                *result = 5;
            }
        }
        {
            typedef void (DAQWorker::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::resDataReady)) {
                *result = 6;
            }
        }
        {
            typedef void (DAQWorker::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::currInjDataReady)) {
                *result = 7;
            }
        }
        {
            typedef void (DAQWorker::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::memTestValsReady)) {
                *result = 8;
            }
        }
        {
            typedef void (DAQWorker::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::bacCurrInjDataReady)) {
                *result = 9;
            }
        }
        {
            typedef void (DAQWorker::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::updateMemTestVals)) {
                *result = 10;
            }
        }
        {
            typedef void (DAQWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::taskIsRunning)) {
                *result = 11;
            }
        }
    }
}

const QMetaObject DAQWorker::staticMetaObject = {
    { &Worker::staticMetaObject, qt_meta_stringdata_DAQWorker.data,
      qt_meta_data_DAQWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DAQWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DAQWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DAQWorker.stringdata))
        return static_cast<void*>(const_cast< DAQWorker*>(this));
    return Worker::qt_metacast(_clname);
}

int DAQWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void DAQWorker::initReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void DAQWorker::initError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void DAQWorker::initTaskReady()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DAQWorker::initTaskError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DAQWorker::rawDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void DAQWorker::rawDataReady(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DAQWorker::resDataReady(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DAQWorker::currInjDataReady(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DAQWorker::memTestValsReady(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DAQWorker::bacCurrInjDataReady(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void DAQWorker::updateMemTestVals(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void DAQWorker::taskIsRunning(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_END_MOC_NAMESPACE
