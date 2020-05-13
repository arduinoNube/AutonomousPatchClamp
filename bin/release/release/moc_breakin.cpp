/****************************************************************************
** Meta object code from reading C++ file 'breakin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/breakin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breakin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BreakIn_t {
    QByteArrayData data[19];
    char stringdata[322];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BreakIn_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BreakIn_t qt_meta_stringdata_BreakIn = {
    {
QT_MOC_LITERAL(0, 0, 7), // "BreakIn"
QT_MOC_LITERAL(1, 8, 14), // "timer1_timeout"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 16), // "daq_resDataReady"
QT_MOC_LITERAL(4, 41, 3), // "res"
QT_MOC_LITERAL(5, 45, 10), // "pauseState"
QT_MOC_LITERAL(6, 56, 7), // "toggled"
QT_MOC_LITERAL(7, 64, 9), // "haltState"
QT_MOC_LITERAL(8, 74, 3), // "zap"
QT_MOC_LITERAL(9, 78, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(10, 96, 17), // "daq_initTaskError"
QT_MOC_LITERAL(11, 114, 20), // "daq_resDataReadyAlg0"
QT_MOC_LITERAL(12, 135, 20), // "daq_resDataReadyAlg1"
QT_MOC_LITERAL(13, 156, 20), // "daq_resDataReadyAlg2"
QT_MOC_LITERAL(14, 177, 20), // "daq_resDataReadyAlg3"
QT_MOC_LITERAL(15, 198, 40), // "multiclamp_setHoldingVoltageS..."
QT_MOC_LITERAL(16, 239, 31), // "autopatcher_breakInRampFinished"
QT_MOC_LITERAL(17, 271, 46), // "multiclamp_pipetteCapacitance..."
QT_MOC_LITERAL(18, 318, 3) // "val"

    },
    "BreakIn\0timer1_timeout\0\0daq_resDataReady\0"
    "res\0pauseState\0toggled\0haltState\0zap\0"
    "daq_initTaskReady\0daq_initTaskError\0"
    "daq_resDataReadyAlg0\0daq_resDataReadyAlg1\0"
    "daq_resDataReadyAlg2\0daq_resDataReadyAlg3\0"
    "multiclamp_setHoldingVoltageSafeComplete\0"
    "autopatcher_breakInRampFinished\0"
    "multiclamp_pipetteCapacitanceCompensationValue\0"
    "val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BreakIn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x0a /* Public */,
       5,    1,   88,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x0a /* Public */,
      13,    1,  101,    2, 0x0a /* Public */,
      14,    1,  104,    2, 0x0a /* Public */,
      15,    0,  107,    2, 0x0a /* Public */,
      16,    0,  108,    2, 0x0a /* Public */,
      17,    1,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   18,

       0        // eod
};

void BreakIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BreakIn *_t = static_cast<BreakIn *>(_o);
        switch (_id) {
        case 0: _t->timer1_timeout(); break;
        case 1: _t->daq_resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->haltState(); break;
        case 4: _t->zap(); break;
        case 5: _t->daq_initTaskReady(); break;
        case 6: _t->daq_initTaskError(); break;
        case 7: _t->daq_resDataReadyAlg0((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->daq_resDataReadyAlg1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->daq_resDataReadyAlg2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->daq_resDataReadyAlg3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->multiclamp_setHoldingVoltageSafeComplete(); break;
        case 12: _t->autopatcher_breakInRampFinished(); break;
        case 13: _t->multiclamp_pipetteCapacitanceCompensationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject BreakIn::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_BreakIn.data,
      qt_meta_data_BreakIn,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BreakIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BreakIn::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BreakIn.stringdata))
        return static_cast<void*>(const_cast< BreakIn*>(this));
    return State::qt_metacast(_clname);
}

int BreakIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
