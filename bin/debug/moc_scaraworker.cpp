/****************************************************************************
** Meta object code from reading C++ file 'scaraworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/workers/scaraworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scaraworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SCARAWorker_t {
    QByteArrayData data[23];
    char stringdata[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SCARAWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SCARAWorker_t qt_meta_stringdata_SCARAWorker = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SCARAWorker"
QT_MOC_LITERAL(1, 12, 13), // "calibFinished"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "rotateArm"
QT_MOC_LITERAL(4, 37, 9), // "armNumber"
QT_MOC_LITERAL(5, 47, 9), // "direction"
QT_MOC_LITERAL(6, 57, 8), // "numSteps"
QT_MOC_LITERAL(7, 66, 9), // "calibrate"
QT_MOC_LITERAL(8, 76, 17), // "enableEndEffector"
QT_MOC_LITERAL(9, 94, 6), // "enable"
QT_MOC_LITERAL(10, 101, 9), // "sendEvent"
QT_MOC_LITERAL(11, 111, 15), // "openEndEffector"
QT_MOC_LITERAL(12, 127, 23), // "partialCloseEndEffector"
QT_MOC_LITERAL(13, 151, 16), // "closeEndEffector"
QT_MOC_LITERAL(14, 168, 8), // "moveNext"
QT_MOC_LITERAL(15, 177, 5), // "fill1"
QT_MOC_LITERAL(16, 183, 5), // "fill2"
QT_MOC_LITERAL(17, 189, 5), // "fill3"
QT_MOC_LITERAL(18, 195, 20), // "dispenseHighPressure"
QT_MOC_LITERAL(19, 216, 4), // "msec"
QT_MOC_LITERAL(20, 221, 13), // "resetCarousel"
QT_MOC_LITERAL(21, 235, 19), // "carouselNextPipette"
QT_MOC_LITERAL(22, 255, 9) // "powerDown"

    },
    "SCARAWorker\0calibFinished\0\0rotateArm\0"
    "armNumber\0direction\0numSteps\0calibrate\0"
    "enableEndEffector\0enable\0sendEvent\0"
    "openEndEffector\0partialCloseEndEffector\0"
    "closeEndEffector\0moveNext\0fill1\0fill2\0"
    "fill3\0dispenseHighPressure\0msec\0"
    "resetCarousel\0carouselNextPipette\0"
    "powerDown"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SCARAWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   90,    2, 0x0a /* Public */,
       7,    0,   97,    2, 0x0a /* Public */,
       8,    2,   98,    2, 0x0a /* Public */,
      11,    1,  103,    2, 0x0a /* Public */,
      12,    1,  106,    2, 0x0a /* Public */,
      13,    1,  109,    2, 0x0a /* Public */,
      14,    1,  112,    2, 0x0a /* Public */,
      15,    1,  115,    2, 0x0a /* Public */,
      16,    1,  118,    2, 0x0a /* Public */,
      17,    1,  121,    2, 0x0a /* Public */,
      18,    2,  124,    2, 0x0a /* Public */,
      20,    0,  129,    2, 0x0a /* Public */,
      21,    1,  130,    2, 0x0a /* Public */,
      22,    0,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    9,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   19,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,

       0        // eod
};

void SCARAWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SCARAWorker *_t = static_cast<SCARAWorker *>(_o);
        switch (_id) {
        case 0: _t->calibFinished(); break;
        case 1: _t->rotateArm((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->calibrate(); break;
        case 3: _t->enableEndEffector((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->openEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->partialCloseEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->closeEndEffector((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->moveNext((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->fill1((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->fill2((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->fill3((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->dispenseHighPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 12: _t->resetCarousel(); break;
        case 13: _t->carouselNextPipette((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->powerDown(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SCARAWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SCARAWorker::calibFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SCARAWorker::staticMetaObject = {
    { &SerialWorker::staticMetaObject, qt_meta_stringdata_SCARAWorker.data,
      qt_meta_data_SCARAWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SCARAWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SCARAWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SCARAWorker.stringdata))
        return static_cast<void*>(const_cast< SCARAWorker*>(this));
    return SerialWorker::qt_metacast(_clname);
}

int SCARAWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SerialWorker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SCARAWorker::calibFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
