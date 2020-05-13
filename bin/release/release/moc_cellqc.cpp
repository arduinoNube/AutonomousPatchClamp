/****************************************************************************
** Meta object code from reading C++ file 'cellqc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/states/cellqc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cellqc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CellQC_t {
    QByteArrayData data[22];
    char stringdata[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CellQC_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CellQC_t qt_meta_stringdata_CellQC = {
    {
QT_MOC_LITERAL(0, 0, 6), // "CellQC"
QT_MOC_LITERAL(1, 7, 10), // "pauseState"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "toggled"
QT_MOC_LITERAL(4, 27, 9), // "haltState"
QT_MOC_LITERAL(5, 37, 40), // "multiclamp_setHoldingVoltageS..."
QT_MOC_LITERAL(6, 78, 20), // "daq_memTestValsReady"
QT_MOC_LITERAL(7, 99, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 115, 4), // "vals"
QT_MOC_LITERAL(9, 120, 40), // "multiclamp_setHoldingCurrentS..."
QT_MOC_LITERAL(10, 161, 16), // "daq_rawDataReady"
QT_MOC_LITERAL(11, 178, 4), // "data"
QT_MOC_LITERAL(12, 183, 17), // "daq_initTaskReady"
QT_MOC_LITERAL(13, 201, 17), // "daq_initTaskError"
QT_MOC_LITERAL(14, 219, 1), // "A"
QT_MOC_LITERAL(15, 221, 1), // "B"
QT_MOC_LITERAL(16, 223, 20), // "daq_currInjDataReady"
QT_MOC_LITERAL(17, 244, 7), // "injData"
QT_MOC_LITERAL(18, 252, 14), // "timer1_timeout"
QT_MOC_LITERAL(19, 267, 14), // "timer2_timeout"
QT_MOC_LITERAL(20, 282, 1), // "C"
QT_MOC_LITERAL(21, 284, 7) // "rawData"

    },
    "CellQC\0pauseState\0\0toggled\0haltState\0"
    "multiclamp_setHoldingVoltageSafeComplete\0"
    "daq_memTestValsReady\0QVector<double>\0"
    "vals\0multiclamp_setHoldingCurrentSafeComplete\0"
    "daq_rawDataReady\0data\0daq_initTaskReady\0"
    "daq_initTaskError\0A\0B\0daq_currInjDataReady\0"
    "injData\0timer1_timeout\0timer2_timeout\0"
    "C\0rawData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CellQC[] = {

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
       1,    1,   84,    2, 0x0a /* Public */,
       4,    0,   87,    2, 0x0a /* Public */,
       5,    0,   88,    2, 0x0a /* Public */,
       6,    1,   89,    2, 0x0a /* Public */,
       9,    0,   92,    2, 0x0a /* Public */,
      10,    1,   93,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      18,    0,  103,    2, 0x08 /* Private */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    1,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   21,

       0        // eod
};

void CellQC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CellQC *_t = static_cast<CellQC *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->multiclamp_setHoldingVoltageSafeComplete(); break;
        case 3: _t->daq_memTestValsReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 4: _t->multiclamp_setHoldingCurrentSafeComplete(); break;
        case 5: _t->daq_rawDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->daq_initTaskReady(); break;
        case 7: _t->daq_initTaskError(); break;
        case 8: _t->A(); break;
        case 9: _t->B(); break;
        case 10: _t->daq_currInjDataReady((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 11: _t->timer1_timeout(); break;
        case 12: _t->timer2_timeout(); break;
        case 13: _t->C((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 13:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject CellQC::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_CellQC.data,
      qt_meta_data_CellQC,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CellQC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CellQC::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CellQC.stringdata))
        return static_cast<void*>(const_cast< CellQC*>(this));
    return State::qt_metacast(_clname);
}

int CellQC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
