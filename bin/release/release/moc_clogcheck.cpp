/****************************************************************************
** Meta object code from reading C++ file 'clogcheck.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/clogcheck.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clogcheck.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClogCheck_t {
    QByteArrayData data[14];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClogCheck_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClogCheck_t qt_meta_stringdata_ClogCheck = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ClogCheck"
QT_MOC_LITERAL(1, 10, 14), // "timer1_timeout"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "daq_resDataReady"
QT_MOC_LITERAL(4, 43, 3), // "res"
QT_MOC_LITERAL(5, 47, 1), // "A"
QT_MOC_LITERAL(6, 49, 1), // "B"
QT_MOC_LITERAL(7, 51, 1), // "C"
QT_MOC_LITERAL(8, 53, 10), // "pauseState"
QT_MOC_LITERAL(9, 64, 7), // "toggled"
QT_MOC_LITERAL(10, 72, 9), // "haltState"
QT_MOC_LITERAL(11, 82, 26), // "thorLabsMotor_moveComplete"
QT_MOC_LITERAL(12, 109, 15), // "daq_taskRunning"
QT_MOC_LITERAL(13, 125, 4) // "flag"

    },
    "ClogCheck\0timer1_timeout\0\0daq_resDataReady\0"
    "res\0A\0B\0C\0pauseState\0toggled\0haltState\0"
    "thorLabsMotor_moveComplete\0daq_taskRunning\0"
    "flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClogCheck[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       5,    1,   63,    2, 0x08 /* Private */,
       6,    0,   66,    2, 0x08 /* Private */,
       7,    1,   67,    2, 0x08 /* Private */,
       8,    1,   70,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    0,   74,    2, 0x0a /* Public */,
      12,    1,   75,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,

       0        // eod
};

void ClogCheck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClogCheck *_t = static_cast<ClogCheck *>(_o);
        switch (_id) {
        case 0: _t->timer1_timeout(); break;
        case 1: _t->daq_resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->A((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->B(); break;
        case 4: _t->C((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->haltState(); break;
        case 7: _t->thorLabsMotor_moveComplete(); break;
        case 8: _t->daq_taskRunning((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ClogCheck::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_ClogCheck.data,
      qt_meta_data_ClogCheck,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClogCheck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClogCheck::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClogCheck.stringdata))
        return static_cast<void*>(const_cast< ClogCheck*>(this));
    return State::qt_metacast(_clname);
}

int ClogCheck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
