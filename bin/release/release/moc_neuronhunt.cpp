/****************************************************************************
** Meta object code from reading C++ file 'neuronhunt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/neuronhunt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'neuronhunt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NeuronHunt_t {
    QByteArrayData data[12];
    char stringdata[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NeuronHunt_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NeuronHunt_t qt_meta_stringdata_NeuronHunt = {
    {
QT_MOC_LITERAL(0, 0, 10), // "NeuronHunt"
QT_MOC_LITERAL(1, 11, 10), // "pauseState"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 7), // "toggled"
QT_MOC_LITERAL(4, 31, 9), // "haltState"
QT_MOC_LITERAL(5, 41, 16), // "daq_resDataReady"
QT_MOC_LITERAL(6, 58, 3), // "res"
QT_MOC_LITERAL(7, 62, 26), // "thorLabsMotor_moveComplete"
QT_MOC_LITERAL(8, 89, 34), // "thorLabsMotor_currentMotorPos..."
QT_MOC_LITERAL(9, 124, 3), // "pos"
QT_MOC_LITERAL(10, 128, 15), // "daq_taskRunning"
QT_MOC_LITERAL(11, 144, 4) // "flag"

    },
    "NeuronHunt\0pauseState\0\0toggled\0haltState\0"
    "daq_resDataReady\0res\0thorLabsMotor_moveComplete\0"
    "thorLabsMotor_currentMotorPosition\0"
    "pos\0daq_taskRunning\0flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NeuronHunt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    1,   48,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
      10,    1,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void NeuronHunt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NeuronHunt *_t = static_cast<NeuronHunt *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->daq_resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->thorLabsMotor_moveComplete(); break;
        case 4: _t->thorLabsMotor_currentMotorPosition((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 5: _t->daq_taskRunning((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject NeuronHunt::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_NeuronHunt.data,
      qt_meta_data_NeuronHunt,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NeuronHunt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NeuronHunt::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NeuronHunt.stringdata))
        return static_cast<void*>(const_cast< NeuronHunt*>(this));
    return State::qt_metacast(_clname);
}

int NeuronHunt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
