/****************************************************************************
** Meta object code from reading C++ file 'ic_recordvisualstimulation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/ic_recordvisualstimulation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ic_recordvisualstimulation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IC_RecordVisualStimulation_t {
    QByteArrayData data[8];
    char stringdata[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_IC_RecordVisualStimulation_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_IC_RecordVisualStimulation_t qt_meta_stringdata_IC_RecordVisualStimulation = {
    {
QT_MOC_LITERAL(0, 0, 26), // "IC_RecordVisualStimulation"
QT_MOC_LITERAL(1, 27, 10), // "pauseState"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 7), // "toggled"
QT_MOC_LITERAL(4, 47, 9), // "haltState"
QT_MOC_LITERAL(5, 57, 13), // "visual_paused"
QT_MOC_LITERAL(6, 71, 15), // "visual_finished"
QT_MOC_LITERAL(7, 87, 14) // "timer1_timeout"

    },
    "IC_RecordVisualStimulation\0pauseState\0"
    "\0toggled\0haltState\0visual_paused\0"
    "visual_finished\0timer1_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IC_RecordVisualStimulation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       4,    0,   42,    2, 0x0a /* Public */,
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void IC_RecordVisualStimulation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        IC_RecordVisualStimulation *_t = static_cast<IC_RecordVisualStimulation *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->visual_paused(); break;
        case 3: _t->visual_finished(); break;
        case 4: _t->timer1_timeout(); break;
        default: ;
        }
    }
}

const QMetaObject IC_RecordVisualStimulation::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_IC_RecordVisualStimulation.data,
      qt_meta_data_IC_RecordVisualStimulation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *IC_RecordVisualStimulation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IC_RecordVisualStimulation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_IC_RecordVisualStimulation.stringdata))
        return static_cast<void*>(const_cast< IC_RecordVisualStimulation*>(this));
    return State::qt_metacast(_clname);
}

int IC_RecordVisualStimulation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
