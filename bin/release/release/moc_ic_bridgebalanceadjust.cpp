/****************************************************************************
** Meta object code from reading C++ file 'ic_bridgebalanceadjust.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/ic_bridgebalanceadjust.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ic_bridgebalanceadjust.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IC_BridgeBalanceAdjust_t {
    QByteArrayData data[17];
    char stringdata[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IC_BridgeBalanceAdjust_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IC_BridgeBalanceAdjust_t qt_meta_stringdata_IC_BridgeBalanceAdjust = {
    {
QT_MOC_LITERAL(0, 0, 22), // "IC_BridgeBalanceAdjust"
QT_MOC_LITERAL(1, 23, 9), // "haltState"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "pauseState"
QT_MOC_LITERAL(4, 45, 15), // "setHardwareVals"
QT_MOC_LITERAL(5, 61, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(6, 85, 6), // "hw_win"
QT_MOC_LITERAL(7, 92, 8), // "firstRun"
QT_MOC_LITERAL(8, 101, 40), // "multiclamp_holdingCurrentChec..."
QT_MOC_LITERAL(9, 142, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(10, 160, 13), // "daq_initError"
QT_MOC_LITERAL(11, 174, 16), // "daq_rawDataReady"
QT_MOC_LITERAL(12, 191, 15), // "QVector<double>"
QT_MOC_LITERAL(13, 207, 4), // "data"
QT_MOC_LITERAL(14, 212, 35), // "multiclamp_setBridgeBalanceCo..."
QT_MOC_LITERAL(15, 248, 35), // "multiclamp_getBridgeBalanceCo..."
QT_MOC_LITERAL(16, 284, 8) // "valMOhms"

    },
    "IC_BridgeBalanceAdjust\0haltState\0\0"
    "pauseState\0setHardwareVals\0"
    "HardwareSettingsWindow*\0hw_win\0firstRun\0"
    "multiclamp_holdingCurrentCheckedComplete\0"
    "daq_initTaskReady\0daq_initError\0"
    "daq_rawDataReady\0QVector<double>\0data\0"
    "multiclamp_setBridgeBalanceComplete\0"
    "multiclamp_getBridgeBalanceComplete\0"
    "valMOhms"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IC_BridgeBalanceAdjust[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x0a /* Public */,
       3,    1,   65,    2, 0x0a /* Public */,
       4,    1,   68,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x0a /* Public */,
       8,    0,   72,    2, 0x0a /* Public */,
       9,    0,   73,    2, 0x0a /* Public */,
      10,    0,   74,    2, 0x0a /* Public */,
      11,    1,   75,    2, 0x0a /* Public */,
      14,    0,   78,    2, 0x0a /* Public */,
      15,    1,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,

       0        // eod
};

void IC_BridgeBalanceAdjust::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IC_BridgeBalanceAdjust *_t = static_cast<IC_BridgeBalanceAdjust *>(_o);
        switch (_id) {
        case 0: _t->haltState(); break;
        case 1: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 3: _t->firstRun(); break;
        case 4: _t->multiclamp_holdingCurrentCheckedComplete(); break;
        case 5: _t->daq_initTaskReady(); break;
        case 6: _t->daq_initError(); break;
        case 7: _t->daq_rawDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 8: _t->multiclamp_setBridgeBalanceComplete(); break;
        case 9: _t->multiclamp_getBridgeBalanceComplete((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HardwareSettingsWindow* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject IC_BridgeBalanceAdjust::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_IC_BridgeBalanceAdjust.data,
      qt_meta_data_IC_BridgeBalanceAdjust,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IC_BridgeBalanceAdjust::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IC_BridgeBalanceAdjust::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IC_BridgeBalanceAdjust.stringdata))
        return static_cast<void*>(const_cast< IC_BridgeBalanceAdjust*>(this));
    return State::qt_metacast(_clname);
}

int IC_BridgeBalanceAdjust::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
