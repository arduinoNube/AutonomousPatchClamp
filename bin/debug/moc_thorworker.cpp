/****************************************************************************
** Meta object code from reading C++ file 'thorworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/workers/thorworker.h"
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
    QByteArrayData data[17];
    char stringdata[171];
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
QT_MOC_LITERAL(6, 64, 4), // "init"
QT_MOC_LITERAL(7, 69, 9), // "serialNum"
QT_MOC_LITERAL(8, 79, 9), // "calibrate"
QT_MOC_LITERAL(9, 89, 17), // "moveMotorAbsolute"
QT_MOC_LITERAL(10, 107, 3), // "pos"
QT_MOC_LITERAL(11, 111, 3), // "vel"
QT_MOC_LITERAL(12, 115, 17), // "moveMotorRelative"
QT_MOC_LITERAL(13, 133, 9), // "haltMotor"
QT_MOC_LITERAL(14, 143, 12), // "homeFinished"
QT_MOC_LITERAL(15, 156, 1), // "i"
QT_MOC_LITERAL(16, 158, 12) // "moveFinished"

    },
    "ThorWorker\0initReady\0\0initError\0"
    "calibFinished\0moveMotorFinished\0init\0"
    "serialNum\0calibrate\0moveMotorAbsolute\0"
    "pos\0vel\0moveMotorRelative\0haltMotor\0"
    "homeFinished\0i\0moveFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThorWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   73,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x0a /* Public */,
       9,    2,   77,    2, 0x0a /* Public */,
      12,    2,   82,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x0a /* Public */,
      14,    1,   88,    2, 0x08 /* Private */,
      16,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   10,   11,
    QMetaType::Void, QMetaType::Float, QMetaType::Float,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,

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
        case 4: _t->init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->calibrate(); break;
        case 6: _t->moveMotorAbsolute((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 7: _t->moveMotorRelative((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 8: _t->haltMotor(); break;
        case 9: _t->homeFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->moveFinished((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
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
    }
}

const QMetaObject ThorWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ThorWorker.data,
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
    return QObject::qt_metacast(_clname);
}

int ThorWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
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
QT_END_MOC_NAMESPACE
