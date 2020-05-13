/****************************************************************************
** Meta object code from reading C++ file 'thorworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/workers/thorworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thorworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ThorWorker_t {
    QByteArrayData data[26];
    char stringdata[305];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThorWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThorWorker_t qt_meta_stringdata_ThorWorker = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ThorWorker"
QT_MOC_LITERAL(1, 11, 9), // "initReady"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "initError"
QT_MOC_LITERAL(4, 32, 13), // "calibFinished"
QT_MOC_LITERAL(5, 46, 17), // "moveMotorFinished"
QT_MOC_LITERAL(6, 64, 20), // "currentMotorPosition"
QT_MOC_LITERAL(7, 85, 8), // "position"
QT_MOC_LITERAL(8, 94, 4), // "init"
QT_MOC_LITERAL(9, 99, 9), // "serialNum"
QT_MOC_LITERAL(10, 109, 9), // "calibrate"
QT_MOC_LITERAL(11, 119, 17), // "moveMotorAbsolute"
QT_MOC_LITERAL(12, 137, 3), // "pos"
QT_MOC_LITERAL(13, 141, 3), // "vel"
QT_MOC_LITERAL(14, 145, 21), // "moveMotorAbsoluteWait"
QT_MOC_LITERAL(15, 167, 17), // "moveMotorRelative"
QT_MOC_LITERAL(16, 185, 11), // "getPosition"
QT_MOC_LITERAL(17, 197, 9), // "sendEvent"
QT_MOC_LITERAL(18, 207, 9), // "haltMotor"
QT_MOC_LITERAL(19, 217, 12), // "aboutToClose"
QT_MOC_LITERAL(20, 230, 15), // "setHardwareVals"
QT_MOC_LITERAL(21, 246, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(22, 270, 6), // "hw_win"
QT_MOC_LITERAL(23, 277, 12), // "homeFinished"
QT_MOC_LITERAL(24, 290, 1), // "i"
QT_MOC_LITERAL(25, 292, 12) // "moveFinished"

    },
    "ThorWorker\0initReady\0\0initError\0"
    "calibFinished\0moveMotorFinished\0"
    "currentMotorPosition\0position\0init\0"
    "serialNum\0calibrate\0moveMotorAbsolute\0"
    "pos\0vel\0moveMotorAbsoluteWait\0"
    "moveMotorRelative\0getPosition\0sendEvent\0"
    "haltMotor\0aboutToClose\0setHardwareVals\0"
    "HardwareSettingsWindow*\0hw_win\0"
    "homeFinished\0i\0moveFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThorWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    1,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  106,    2, 0x0a /* Public */,
      10,    0,  109,    2, 0x0a /* Public */,
      11,    2,  110,    2, 0x0a /* Public */,
      14,    2,  115,    2, 0x0a /* Public */,
      15,    2,  120,    2, 0x0a /* Public */,
      16,    0,  125,    2, 0x0a /* Public */,
      16,    1,  126,    2, 0x0a /* Public */,
      18,    0,  129,    2, 0x0a /* Public */,
      19,    0,  130,    2, 0x0a /* Public */,
      20,    1,  131,    2, 0x0a /* Public */,
      23,    1,  134,    2, 0x08 /* Private */,
      25,    1,  137,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   12,   13,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   12,   13,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   12,   13,
    QMetaType::Float,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::Int,   24,

       0        // eod
};

void ThorWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThorWorker *_t = static_cast<ThorWorker *>(_o);
        switch (_id) {
        case 0: _t->initReady(); break;
        case 1: _t->initError(); break;
        case 2: _t->calibFinished(); break;
        case 3: _t->moveMotorFinished(); break;
        case 4: _t->currentMotorPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->calibrate(); break;
        case 7: _t->moveMotorAbsolute((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->moveMotorAbsoluteWait((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 9: _t->moveMotorRelative((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 10: { float _r = _t->getPosition();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 11: _t->getPosition((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->haltMotor(); break;
        case 13: _t->aboutToClose(); break;
        case 14: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 15: _t->homeFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->moveFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
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
            typedef void (ThorWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThorWorker::initReady)) {
                *result = 0;
            }
        }
        {
            typedef void (ThorWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThorWorker::initError)) {
                *result = 1;
            }
        }
        {
            typedef void (ThorWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThorWorker::calibFinished)) {
                *result = 2;
            }
        }
        {
            typedef void (ThorWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThorWorker::moveMotorFinished)) {
                *result = 3;
            }
        }
        {
            typedef void (ThorWorker::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ThorWorker::currentMotorPosition)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject ThorWorker::staticMetaObject = {
    { &Worker::staticMetaObject, qt_meta_stringdata_ThorWorker.data,
      qt_meta_data_ThorWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ThorWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThorWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ThorWorker.stringdata))
        return static_cast<void*>(const_cast< ThorWorker*>(this));
    return Worker::qt_metacast(_clname);
}

int ThorWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void ThorWorker::initReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ThorWorker::initError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ThorWorker::calibFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ThorWorker::moveMotorFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ThorWorker::currentMotorPosition(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
