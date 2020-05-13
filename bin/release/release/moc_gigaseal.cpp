/****************************************************************************
** Meta object code from reading C++ file 'gigaseal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/gigaseal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gigaseal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gigaseal_t {
    QByteArrayData data[17];
    char stringdata[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gigaseal_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gigaseal_t qt_meta_stringdata_Gigaseal = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Gigaseal"
QT_MOC_LITERAL(1, 9, 15), // "daq_taskRunning"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 4), // "flag"
QT_MOC_LITERAL(4, 31, 10), // "pauseState"
QT_MOC_LITERAL(5, 42, 7), // "toggled"
QT_MOC_LITERAL(6, 50, 9), // "haltState"
QT_MOC_LITERAL(7, 60, 16), // "daq_resDataReady"
QT_MOC_LITERAL(8, 77, 3), // "res"
QT_MOC_LITERAL(9, 81, 1), // "A"
QT_MOC_LITERAL(10, 83, 1), // "B"
QT_MOC_LITERAL(11, 85, 1), // "C"
QT_MOC_LITERAL(12, 87, 1), // "D"
QT_MOC_LITERAL(13, 89, 1), // "E"
QT_MOC_LITERAL(14, 91, 1), // "F"
QT_MOC_LITERAL(15, 93, 14), // "timer1_timeout"
QT_MOC_LITERAL(16, 108, 14) // "timer2_timeout"

    },
    "Gigaseal\0daq_taskRunning\0\0flag\0"
    "pauseState\0toggled\0haltState\0"
    "daq_resDataReady\0res\0A\0B\0C\0D\0E\0F\0"
    "timer1_timeout\0timer2_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gigaseal[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       6,    0,   80,    2, 0x0a /* Public */,
       7,    1,   81,    2, 0x0a /* Public */,
       9,    1,   84,    2, 0x0a /* Public */,
      10,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,
      13,    1,   96,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Gigaseal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gigaseal *_t = static_cast<Gigaseal *>(_o);
        switch (_id) {
        case 0: _t->daq_taskRunning((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->haltState(); break;
        case 3: _t->daq_resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->A((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->B((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->C((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->D((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->E((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->F((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->timer1_timeout(); break;
        case 11: _t->timer2_timeout(); break;
        default: ;
        }
    }
}

const QMetaObject Gigaseal::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_Gigaseal.data,
      qt_meta_data_Gigaseal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Gigaseal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gigaseal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Gigaseal.stringdata))
        return static_cast<void*>(const_cast< Gigaseal*>(this));
    return State::qt_metacast(_clname);
}

int Gigaseal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
