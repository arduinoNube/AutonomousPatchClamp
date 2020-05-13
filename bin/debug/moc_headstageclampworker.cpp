/****************************************************************************
** Meta object code from reading C++ file 'headstageclampworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/workers/headstageclampworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'headstageclampworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HeadstageClampWorker_t {
    QByteArrayData data[8];
    char stringdata[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HeadstageClampWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HeadstageClampWorker_t qt_meta_stringdata_HeadstageClampWorker = {
    {
QT_MOC_LITERAL(0, 0, 20), // "HeadstageClampWorker"
QT_MOC_LITERAL(1, 21, 9), // "openClamp"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 9), // "sendEvent"
QT_MOC_LITERAL(4, 42, 9), // "halfClamp"
QT_MOC_LITERAL(5, 52, 10), // "closeClamp"
QT_MOC_LITERAL(6, 63, 10), // "threadWire"
QT_MOC_LITERAL(7, 74, 11) // "retractWire"

    },
    "HeadstageClampWorker\0openClamp\0\0"
    "sendEvent\0halfClamp\0closeClamp\0"
    "threadWire\0retractWire"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HeadstageClampWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,

       0        // eod
};

void HeadstageClampWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HeadstageClampWorker *_t = static_cast<HeadstageClampWorker *>(_o);
        switch (_id) {
        case 0: _t->openClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->halfClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->closeClamp((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->threadWire((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->retractWire((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject HeadstageClampWorker::staticMetaObject = {
    { &SerialWorker::staticMetaObject, qt_meta_stringdata_HeadstageClampWorker.data,
      qt_meta_data_HeadstageClampWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HeadstageClampWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HeadstageClampWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HeadstageClampWorker.stringdata))
        return static_cast<void*>(const_cast< HeadstageClampWorker*>(this));
    return SerialWorker::qt_metacast(_clname);
}

int HeadstageClampWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SerialWorker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
