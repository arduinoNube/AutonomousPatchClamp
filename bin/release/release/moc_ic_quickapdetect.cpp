/****************************************************************************
** Meta object code from reading C++ file 'ic_quickapdetect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/ic_quickapdetect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ic_quickapdetect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IC_QuickAPDetect_t {
    QByteArrayData data[16];
    char stringdata[248];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IC_QuickAPDetect_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IC_QuickAPDetect_t qt_meta_stringdata_IC_QuickAPDetect = {
    {
QT_MOC_LITERAL(0, 0, 16), // "IC_QuickAPDetect"
QT_MOC_LITERAL(1, 17, 14), // "timer1_timeout"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 10), // "pauseState"
QT_MOC_LITERAL(4, 44, 7), // "toggled"
QT_MOC_LITERAL(5, 52, 9), // "haltState"
QT_MOC_LITERAL(6, 62, 40), // "multiclamp_setHoldingCurrentS..."
QT_MOC_LITERAL(7, 103, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(8, 121, 16), // "daq_rawDataReady"
QT_MOC_LITERAL(9, 138, 15), // "QVector<double>"
QT_MOC_LITERAL(10, 154, 20), // "daq_currInjDataReady"
QT_MOC_LITERAL(11, 175, 7), // "injData"
QT_MOC_LITERAL(12, 183, 17), // "daq_initTaskError"
QT_MOC_LITERAL(13, 201, 15), // "setHardwareVals"
QT_MOC_LITERAL(14, 217, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(15, 241, 6) // "hw_win"

    },
    "IC_QuickAPDetect\0timer1_timeout\0\0"
    "pauseState\0toggled\0haltState\0"
    "multiclamp_setHoldingCurrentSafeComplete\0"
    "daq_initTaskReady\0daq_rawDataReady\0"
    "QVector<double>\0daq_currInjDataReady\0"
    "injData\0daq_initTaskError\0setHardwareVals\0"
    "HardwareSettingsWindow*\0hw_win"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IC_QuickAPDetect[] = {

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
       3,    1,   60,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    1,   66,    2, 0x0a /* Public */,
      10,    1,   69,    2, 0x0a /* Public */,
      12,    0,   72,    2, 0x0a /* Public */,
      13,    1,   73,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 9,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void IC_QuickAPDetect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IC_QuickAPDetect *_t = static_cast<IC_QuickAPDetect *>(_o);
        switch (_id) {
        case 0: _t->timer1_timeout(); break;
        case 1: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->haltState(); break;
        case 3: _t->multiclamp_setHoldingCurrentSafeComplete(); break;
        case 4: _t->daq_initTaskReady(); break;
        case 5: _t->daq_rawDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->daq_currInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 7: _t->daq_initTaskError(); break;
        case 8: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
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
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HardwareSettingsWindow* >(); break;
            }
            break;
        }
    }
}

const QMetaObject IC_QuickAPDetect::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_IC_QuickAPDetect.data,
      qt_meta_data_IC_QuickAPDetect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IC_QuickAPDetect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IC_QuickAPDetect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IC_QuickAPDetect.stringdata))
        return static_cast<void*>(const_cast< IC_QuickAPDetect*>(this));
    if (!strcmp(_clname, "StateHelperFunctions"))
        return static_cast< StateHelperFunctions*>(const_cast< IC_QuickAPDetect*>(this));
    return State::qt_metacast(_clname);
}

int IC_QuickAPDetect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
