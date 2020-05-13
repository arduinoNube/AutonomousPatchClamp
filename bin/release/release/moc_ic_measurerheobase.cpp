/****************************************************************************
** Meta object code from reading C++ file 'ic_measurerheobase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/ic_measurerheobase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ic_measurerheobase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IC_MeasureRheobase_t {
    QByteArrayData data[15];
    char stringdata[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IC_MeasureRheobase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IC_MeasureRheobase_t qt_meta_stringdata_IC_MeasureRheobase = {
    {
QT_MOC_LITERAL(0, 0, 18), // "IC_MeasureRheobase"
QT_MOC_LITERAL(1, 19, 10), // "pauseState"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "toggled"
QT_MOC_LITERAL(4, 39, 9), // "haltState"
QT_MOC_LITERAL(5, 49, 40), // "multiclamp_setHoldingCurrentS..."
QT_MOC_LITERAL(6, 90, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(7, 108, 17), // "daq_initTaskError"
QT_MOC_LITERAL(8, 126, 20), // "daq_currInjDataReady"
QT_MOC_LITERAL(9, 147, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 163, 7), // "injData"
QT_MOC_LITERAL(11, 171, 15), // "setHardwareVals"
QT_MOC_LITERAL(12, 187, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(13, 211, 6), // "hw_win"
QT_MOC_LITERAL(14, 218, 14) // "timer1_timeout"

    },
    "IC_MeasureRheobase\0pauseState\0\0toggled\0"
    "haltState\0multiclamp_setHoldingCurrentSafeComplete\0"
    "daq_initTaskReady\0daq_initTaskError\0"
    "daq_currInjDataReady\0QVector<double>\0"
    "injData\0setHardwareVals\0HardwareSettingsWindow*\0"
    "hw_win\0timer1_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IC_MeasureRheobase[] = {

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

void IC_MeasureRheobase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IC_MeasureRheobase *_t = static_cast<IC_MeasureRheobase *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->multiclamp_setHoldingCurrentSafeComplete(); break;
        case 3: _t->daq_initTaskReady(); break;
        case 4: _t->daq_initTaskError(); break;
        case 5: _t->daq_currInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 7: _t->timer1_timeout(); break;
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

const QMetaObject IC_MeasureRheobase::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_IC_MeasureRheobase.data,
      qt_meta_data_IC_MeasureRheobase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IC_MeasureRheobase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IC_MeasureRheobase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IC_MeasureRheobase.stringdata))
        return static_cast<void*>(const_cast< IC_MeasureRheobase*>(this));
    if (!strcmp(_clname, "StateHelperFunctions"))
        return static_cast< StateHelperFunctions*>(const_cast< IC_MeasureRheobase*>(this));
    return State::qt_metacast(_clname);
}

int IC_MeasureRheobase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
