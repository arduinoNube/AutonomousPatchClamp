/****************************************************************************
** Meta object code from reading C++ file 'pipetteqc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/states/pipetteqc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pipetteqc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PipetteQC_t {
    QByteArrayData data[12];
    char stringdata[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PipetteQC_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PipetteQC_t qt_meta_stringdata_PipetteQC = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PipetteQC"
QT_MOC_LITERAL(1, 10, 10), // "pauseState"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "resumeState"
QT_MOC_LITERAL(4, 34, 9), // "haltState"
QT_MOC_LITERAL(5, 44, 21), // "daq_initResCheckReady"
QT_MOC_LITERAL(6, 66, 21), // "daq_initResCheckError"
QT_MOC_LITERAL(7, 88, 36), // "multiclamp_autoPipetteOffsetC..."
QT_MOC_LITERAL(8, 125, 16), // "daq_resDataReady"
QT_MOC_LITERAL(9, 142, 3), // "res"
QT_MOC_LITERAL(10, 146, 1), // "A"
QT_MOC_LITERAL(11, 148, 26) // "thorLabsMotor_moveComplete"

    },
    "PipetteQC\0pauseState\0\0resumeState\0"
    "haltState\0daq_initResCheckReady\0"
    "daq_initResCheckError\0"
    "multiclamp_autoPipetteOffsetComplete\0"
    "daq_resDataReady\0res\0A\0"
    "thorLabsMotor_moveComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PipetteQC[] = {

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
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    1,   65,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PipetteQC::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PipetteQC *_t = static_cast<PipetteQC *>(_o);
        switch (_id) {
        case 0: _t->pauseState(); break;
        case 1: _t->resumeState(); break;
        case 2: _t->haltState(); break;
        case 3: _t->daq_initResCheckReady(); break;
        case 4: _t->daq_initResCheckError(); break;
        case 5: _t->multiclamp_autoPipetteOffsetComplete(); break;
        case 6: _t->daq_resDataReady((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->A(); break;
        case 8: _t->thorLabsMotor_moveComplete(); break;
        default: ;
        }
    }
}

const QMetaObject PipetteQC::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_PipetteQC.data,
      qt_meta_data_PipetteQC,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PipetteQC::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PipetteQC::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PipetteQC.stringdata))
        return static_cast<void*>(const_cast< PipetteQC*>(this));
    return State::qt_metacast(_clname);
}

int PipetteQC::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE