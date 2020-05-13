/****************************************************************************
** Meta object code from reading C++ file 'daqworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/workers/daqworker.h"
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
    QByteArrayData data[38];
    char stringdata[448];
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
QT_MOC_LITERAL(4, 31, 17), // "initResCheckReady"
QT_MOC_LITERAL(5, 49, 17), // "initResCheckError"
QT_MOC_LITERAL(6, 67, 16), // "initMemTestReady"
QT_MOC_LITERAL(7, 84, 16), // "initMemTestError"
QT_MOC_LITERAL(8, 101, 12), // "rawDataReady"
QT_MOC_LITERAL(9, 114, 12), // "resDataReady"
QT_MOC_LITERAL(10, 127, 3), // "res"
QT_MOC_LITERAL(11, 131, 19), // "rawMemTestDataReady"
QT_MOC_LITERAL(12, 151, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 167, 6), // "buffer"
QT_MOC_LITERAL(14, 174, 17), // "firstResCheckDone"
QT_MOC_LITERAL(15, 192, 7), // "average"
QT_MOC_LITERAL(16, 200, 5), // "stdev"
QT_MOC_LITERAL(17, 206, 17), // "setHoldingVoltage"
QT_MOC_LITERAL(18, 224, 4), // "volt"
QT_MOC_LITERAL(19, 229, 13), // "rCheckStopped"
QT_MOC_LITERAL(20, 243, 16), // "memTestValsReady"
QT_MOC_LITERAL(21, 260, 4), // "vals"
QT_MOC_LITERAL(22, 265, 24), // "setHoldingVoltageChecked"
QT_MOC_LITERAL(23, 290, 4), // "flag"
QT_MOC_LITERAL(24, 295, 12), // "initResCheck"
QT_MOC_LITERAL(25, 308, 11), // "initMemTest"
QT_MOC_LITERAL(26, 320, 12), // "initInThread"
QT_MOC_LITERAL(27, 333, 4), // "init"
QT_MOC_LITERAL(28, 338, 7), // "devName"
QT_MOC_LITERAL(29, 346, 10), // "triggerRes"
QT_MOC_LITERAL(30, 357, 4), // "stop"
QT_MOC_LITERAL(31, 362, 10), // "setDevName"
QT_MOC_LITERAL(32, 373, 4), // "name"
QT_MOC_LITERAL(33, 378, 13), // "clearAllTasks"
QT_MOC_LITERAL(34, 392, 14), // "startRawAquire"
QT_MOC_LITERAL(35, 407, 13), // "stopRawAquire"
QT_MOC_LITERAL(36, 421, 9), // "aquireRaw"
QT_MOC_LITERAL(37, 431, 16) // "aquireMemTestRaw"

    },
    "DAQWorker\0initReady\0\0initError\0"
    "initResCheckReady\0initResCheckError\0"
    "initMemTestReady\0initMemTestError\0"
    "rawDataReady\0resDataReady\0res\0"
    "rawMemTestDataReady\0QVector<double>\0"
    "buffer\0firstResCheckDone\0average\0stdev\0"
    "setHoldingVoltage\0volt\0rCheckStopped\0"
    "memTestValsReady\0vals\0setHoldingVoltageChecked\0"
    "flag\0initResCheck\0initMemTest\0"
    "initInThread\0init\0devName\0triggerRes\0"
    "stop\0setDevName\0name\0clearAllTasks\0"
    "startRawAquire\0stopRawAquire\0aquireRaw\0"
    "aquireMemTestRaw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DAQWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x06 /* Public */,
       3,    0,  145,    2, 0x06 /* Public */,
       4,    0,  146,    2, 0x06 /* Public */,
       5,    0,  147,    2, 0x06 /* Public */,
       6,    0,  148,    2, 0x06 /* Public */,
       7,    0,  149,    2, 0x06 /* Public */,
       8,    0,  150,    2, 0x06 /* Public */,
       9,    1,  151,    2, 0x06 /* Public */,
      11,    1,  154,    2, 0x06 /* Public */,
      14,    2,  157,    2, 0x06 /* Public */,
      17,    1,  162,    2, 0x06 /* Public */,
      19,    0,  165,    2, 0x06 /* Public */,
      20,    1,  166,    2, 0x06 /* Public */,
      22,    1,  169,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      24,    0,  172,    2, 0x0a /* Public */,
      25,    0,  173,    2, 0x0a /* Public */,
      26,    0,  174,    2, 0x0a /* Public */,
      27,    1,  175,    2, 0x0a /* Public */,
      29,    0,  178,    2, 0x0a /* Public */,
      30,    0,  179,    2, 0x0a /* Public */,
      31,    1,  180,    2, 0x0a /* Public */,
      33,    0,  183,    2, 0x0a /* Public */,
      34,    0,  184,    2, 0x0a /* Public */,
      35,    0,  185,    2, 0x0a /* Public */,
      36,    0,  186,    2, 0x08 /* Private */,
      37,    0,  187,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   15,   16,
    QMetaType::Void, QMetaType::Double,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   21,
    QMetaType::Void, QMetaType::Bool,   23,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 2: _t->initResCheckReady(); break;
        case 3: _t->initResCheckError(); break;
        case 4: _t->initMemTestReady(); break;
        case 5: _t->initMemTestError(); break;
        case 6: _t->rawDataReady(); break;
        case 7: _t->resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->rawMemTestDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 9: _t->firstResCheckDone((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 10: _t->setHoldingVoltage((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->rCheckStopped(); break;
        case 12: _t->memTestValsReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 13: _t->setHoldingVoltageChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->initResCheck(); break;
        case 15: _t->initMemTest(); break;
        case 16: _t->initInThread(); break;
        case 17: _t->init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: _t->triggerRes(); break;
        case 19: _t->stop(); break;
        case 20: _t->setDevName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->clearAllTasks(); break;
        case 22: _t->startRawAquire(); break;
        case 23: _t->stopRawAquire(); break;
        case 24: _t->aquireRaw(); break;
        case 25: _t->aquireMemTestRaw(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 12:
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
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initResCheckReady)) {
                *result = 2;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initResCheckError)) {
                *result = 3;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initMemTestReady)) {
                *result = 4;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::initMemTestError)) {
                *result = 5;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::rawDataReady)) {
                *result = 6;
            }
        }
        {
            typedef void (DAQWorker::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::resDataReady)) {
                *result = 7;
            }
        }
        {
            typedef void (DAQWorker::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::rawMemTestDataReady)) {
                *result = 8;
            }
        }
        {
            typedef void (DAQWorker::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::firstResCheckDone)) {
                *result = 9;
            }
        }
        {
            typedef void (DAQWorker::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::setHoldingVoltage)) {
                *result = 10;
            }
        }
        {
            typedef void (DAQWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::rCheckStopped)) {
                *result = 11;
            }
        }
        {
            typedef void (DAQWorker::*_t)(QVector<double> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::memTestValsReady)) {
                *result = 12;
            }
        }
        {
            typedef void (DAQWorker::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DAQWorker::setHoldingVoltageChecked)) {
                *result = 13;
            }
        }
    }
}

const QMetaObject DAQWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DAQWorker.data,
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
    return QObject::qt_metacast(_clname);
}

int DAQWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
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
void DAQWorker::initResCheckReady()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void DAQWorker::initResCheckError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void DAQWorker::initMemTestReady()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void DAQWorker::initMemTestError()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void DAQWorker::rawDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void DAQWorker::resDataReady(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DAQWorker::rawMemTestDataReady(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void DAQWorker::firstResCheckDone(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void DAQWorker::setHoldingVoltage(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void DAQWorker::rCheckStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void DAQWorker::memTestValsReady(QVector<double> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void DAQWorker::setHoldingVoltageChecked(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}
QT_END_MOC_NAMESPACE
