/****************************************************************************
** Meta object code from reading C++ file 'ic_restingvoltage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/ic_restingvoltage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ic_restingvoltage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IC_RestingVoltage_t {
    QByteArrayData data[15];
    char stringdata[225];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IC_RestingVoltage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IC_RestingVoltage_t qt_meta_stringdata_IC_RestingVoltage = {
    {
QT_MOC_LITERAL(0, 0, 17), // "IC_RestingVoltage"
QT_MOC_LITERAL(1, 18, 10), // "pauseState"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 7), // "toggled"
QT_MOC_LITERAL(4, 38, 9), // "haltState"
QT_MOC_LITERAL(5, 48, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(6, 66, 17), // "daq_initTaskError"
QT_MOC_LITERAL(7, 84, 40), // "multiclamp_setHoldingCurrentS..."
QT_MOC_LITERAL(8, 125, 16), // "daq_rawDataReady"
QT_MOC_LITERAL(9, 142, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 158, 7), // "rawData"
QT_MOC_LITERAL(11, 166, 15), // "setHardwareVals"
QT_MOC_LITERAL(12, 182, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(13, 206, 6), // "hw_win"
QT_MOC_LITERAL(14, 213, 11) // "dialogClose"

    },
    "IC_RestingVoltage\0pauseState\0\0toggled\0"
    "haltState\0daq_initTaskReady\0"
    "daq_initTaskError\0"
    "multiclamp_setHoldingCurrentSafeComplete\0"
    "daq_rawDataReady\0QVector<double>\0"
    "rawData\0setHardwareVals\0HardwareSettingsWindow*\0"
    "hw_win\0dialogClose"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IC_RestingVoltage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
      11,    1,   64,    2, 0x0a /* Public */,
      14,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,

       0        // eod
};

void IC_RestingVoltage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IC_RestingVoltage *_t = static_cast<IC_RestingVoltage *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->daq_initTaskReady(); break;
        case 3: _t->daq_initTaskError(); break;
        case 4: _t->multiclamp_setHoldingCurrentSafeComplete(); break;
        case 5: _t->daq_rawDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 7: _t->dialogClose(); break;
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
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HardwareSettingsWindow* >(); break;
            }
            break;
        }
    }
}

const QMetaObject IC_RestingVoltage::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_IC_RestingVoltage.data,
      qt_meta_data_IC_RestingVoltage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IC_RestingVoltage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IC_RestingVoltage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IC_RestingVoltage.stringdata))
        return static_cast<void*>(const_cast< IC_RestingVoltage*>(this));
    return State::qt_metacast(_clname);
}

int IC_RestingVoltage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
