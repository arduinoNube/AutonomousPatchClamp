/****************************************************************************
** Meta object code from reading C++ file 'vc_pipettecapacitanceneutralization.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/vc_pipettecapacitanceneutralization.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vc_pipettecapacitanceneutralization.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VC_PipetteCapacitanceNeutralization_t {
    QByteArrayData data[14];
    char stringdata[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VC_PipetteCapacitanceNeutralization_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VC_PipetteCapacitanceNeutralization_t qt_meta_stringdata_VC_PipetteCapacitanceNeutralization = {
    {
QT_MOC_LITERAL(0, 0, 35), // "VC_PipetteCapacitanceNeutrali..."
QT_MOC_LITERAL(1, 36, 10), // "pauseState"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 9), // "haltState"
QT_MOC_LITERAL(4, 58, 8), // "firstRun"
QT_MOC_LITERAL(5, 67, 40), // "multiclamp_setHoldingVoltageS..."
QT_MOC_LITERAL(6, 108, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(7, 126, 17), // "daq_initTaskError"
QT_MOC_LITERAL(8, 144, 20), // "daq_memTestValsReady"
QT_MOC_LITERAL(9, 165, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 181, 4), // "vals"
QT_MOC_LITERAL(11, 186, 38), // "multiclamp_autoFastCapacitanc..."
QT_MOC_LITERAL(12, 225, 46), // "multiclamp_pipetteCapacitance..."
QT_MOC_LITERAL(13, 272, 3) // "val"

    },
    "VC_PipetteCapacitanceNeutralization\0"
    "pauseState\0\0haltState\0firstRun\0"
    "multiclamp_setHoldingVoltageSafeComplete\0"
    "daq_initTaskReady\0daq_initTaskError\0"
    "daq_memTestValsReady\0QVector<double>\0"
    "vals\0multiclamp_autoFastCapacitanceComplete\0"
    "multiclamp_pipetteCapacitanceCompensationValue\0"
    "val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VC_PipetteCapacitanceNeutralization[] = {

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
       1,    1,   59,    2, 0x0a /* Public */,
       3,    0,   62,    2, 0x0a /* Public */,
       4,    0,   63,    2, 0x0a /* Public */,
       5,    0,   64,    2, 0x0a /* Public */,
       6,    0,   65,    2, 0x0a /* Public */,
       7,    0,   66,    2, 0x0a /* Public */,
       8,    1,   67,    2, 0x0a /* Public */,
      11,    0,   70,    2, 0x0a /* Public */,
      12,    1,   71,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   13,

       0        // eod
};

void VC_PipetteCapacitanceNeutralization::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VC_PipetteCapacitanceNeutralization *_t = static_cast<VC_PipetteCapacitanceNeutralization *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->firstRun(); break;
        case 3: _t->multiclamp_setHoldingVoltageSafeComplete(); break;
        case 4: _t->daq_initTaskReady(); break;
        case 5: _t->daq_initTaskError(); break;
        case 6: _t->daq_memTestValsReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 7: _t->multiclamp_autoFastCapacitanceComplete(); break;
        case 8: _t->multiclamp_pipetteCapacitanceCompensationValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject VC_PipetteCapacitanceNeutralization::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_VC_PipetteCapacitanceNeutralization.data,
      qt_meta_data_VC_PipetteCapacitanceNeutralization,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VC_PipetteCapacitanceNeutralization::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VC_PipetteCapacitanceNeutralization::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VC_PipetteCapacitanceNeutralization.stringdata))
        return static_cast<void*>(const_cast< VC_PipetteCapacitanceNeutralization*>(this));
    return State::qt_metacast(_clname);
}

int VC_PipetteCapacitanceNeutralization::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
