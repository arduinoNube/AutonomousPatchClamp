/****************************************************************************
** Meta object code from reading C++ file 'autopatcherworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/workers/autopatcherworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autopatcherworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AutopatcherWorker_t {
    QByteArrayData data[19];
    char stringdata[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutopatcherWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutopatcherWorker_t qt_meta_stringdata_AutopatcherWorker = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AutopatcherWorker"
QT_MOC_LITERAL(1, 18, 15), // "breakInFinished"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 9), // "switchBNC"
QT_MOC_LITERAL(4, 45, 2), // "on"
QT_MOC_LITERAL(5, 48, 9), // "sendEvent"
QT_MOC_LITERAL(6, 58, 14), // "switchPressure"
QT_MOC_LITERAL(7, 73, 4), // "pres"
QT_MOC_LITERAL(8, 78, 16), // "softwarePressure"
QT_MOC_LITERAL(9, 95, 4), // "flag"
QT_MOC_LITERAL(10, 100, 11), // "setPressure"
QT_MOC_LITERAL(11, 112, 3), // "num"
QT_MOC_LITERAL(12, 116, 3), // "val"
QT_MOC_LITERAL(13, 120, 7), // "breakIn"
QT_MOC_LITERAL(14, 128, 4), // "time"
QT_MOC_LITERAL(15, 133, 13), // "msWaitBetween"
QT_MOC_LITERAL(16, 147, 9), // "numPulses"
QT_MOC_LITERAL(17, 157, 11), // "breakInRamp"
QT_MOC_LITERAL(18, 169, 8) // "pressure"

    },
    "AutopatcherWorker\0breakInFinished\0\0"
    "switchBNC\0on\0sendEvent\0switchPressure\0"
    "pres\0softwarePressure\0flag\0setPressure\0"
    "num\0val\0breakIn\0time\0msWaitBetween\0"
    "numPulses\0breakInRamp\0pressure"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutopatcherWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   50,    2, 0x0a /* Public */,
       6,    2,   55,    2, 0x0a /* Public */,
       8,    2,   60,    2, 0x0a /* Public */,
      10,    3,   65,    2, 0x0a /* Public */,
      13,    3,   72,    2, 0x0a /* Public */,
      17,    2,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    7,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    9,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Bool,   11,   12,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   14,   18,

       0        // eod
};

void AutopatcherWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AutopatcherWorker *_t = static_cast<AutopatcherWorker *>(_o);
        switch (_id) {
        case 0: _t->breakInFinished(); break;
        case 1: _t->switchBNC((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->switchPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->softwarePressure((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->breakIn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->breakInRamp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AutopatcherWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AutopatcherWorker::breakInFinished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AutopatcherWorker::staticMetaObject = {
    { &SerialWorker::staticMetaObject, qt_meta_stringdata_AutopatcherWorker.data,
      qt_meta_data_AutopatcherWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutopatcherWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutopatcherWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutopatcherWorker.stringdata))
        return static_cast<void*>(const_cast< AutopatcherWorker*>(this));
    return SerialWorker::qt_metacast(_clname);
}

int AutopatcherWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SerialWorker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AutopatcherWorker::breakInFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
