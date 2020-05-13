/****************************************************************************
** Meta object code from reading C++ file 'ic_bacfiring.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/ic_bacfiring.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ic_bacfiring.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IC_BACFiring_t {
    QByteArrayData data[11];
    char stringdata[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IC_BACFiring_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IC_BACFiring_t qt_meta_stringdata_IC_BACFiring = {
    {
QT_MOC_LITERAL(0, 0, 12), // "IC_BACFiring"
QT_MOC_LITERAL(1, 13, 10), // "pauseState"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "toggled"
QT_MOC_LITERAL(4, 33, 9), // "haltState"
QT_MOC_LITERAL(5, 43, 40), // "multiclamp_setHoldingCurrentS..."
QT_MOC_LITERAL(6, 84, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(7, 102, 17), // "daq_initTaskError"
QT_MOC_LITERAL(8, 120, 23), // "daq_bacCurrInjDataReady"
QT_MOC_LITERAL(9, 144, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 160, 14) // "timer1_timeout"

    },
    "IC_BACFiring\0pauseState\0\0toggled\0"
    "haltState\0multiclamp_setHoldingCurrentSafeComplete\0"
    "daq_initTaskReady\0daq_initTaskError\0"
    "daq_bacCurrInjDataReady\0QVector<double>\0"
    "timer1_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IC_BACFiring[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    0,   52,    2, 0x0a /* Public */,
       5,    0,   53,    2, 0x0a /* Public */,
       6,    0,   54,    2, 0x0a /* Public */,
       7,    0,   55,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
      10,    0,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void,

       0        // eod
};

void IC_BACFiring::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IC_BACFiring *_t = static_cast<IC_BACFiring *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->multiclamp_setHoldingCurrentSafeComplete(); break;
        case 3: _t->daq_initTaskReady(); break;
        case 4: _t->daq_initTaskError(); break;
        case 5: _t->daq_bacCurrInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->timer1_timeout(); break;
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
        }
    }
}

const QMetaObject IC_BACFiring::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_IC_BACFiring.data,
      qt_meta_data_IC_BACFiring,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IC_BACFiring::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IC_BACFiring::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IC_BACFiring.stringdata))
        return static_cast<void*>(const_cast< IC_BACFiring*>(this));
    return State::qt_metacast(_clname);
}

int IC_BACFiring::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
