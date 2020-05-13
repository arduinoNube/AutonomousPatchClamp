/****************************************************************************
** Meta object code from reading C++ file 'setbrainheight.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/setbrainheight.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setbrainheight.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SetBrainHeight_t {
    QByteArrayData data[12];
    char stringdata[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SetBrainHeight_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SetBrainHeight_t qt_meta_stringdata_SetBrainHeight = {
    {
QT_MOC_LITERAL(0, 0, 14), // "SetBrainHeight"
QT_MOC_LITERAL(1, 15, 10), // "pauseState"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "toggled"
QT_MOC_LITERAL(4, 35, 9), // "haltState"
QT_MOC_LITERAL(5, 45, 17), // "gui_downAdjustBtn"
QT_MOC_LITERAL(6, 63, 4), // "dist"
QT_MOC_LITERAL(7, 68, 15), // "gui_upAdjustBtn"
QT_MOC_LITERAL(8, 84, 26), // "thorLabsMotor_moveComplete"
QT_MOC_LITERAL(9, 111, 25), // "gui_pushbuttonGO3Released"
QT_MOC_LITERAL(10, 137, 11), // "ThorWorker*"
QT_MOC_LITERAL(11, 149, 1) // "t"

    },
    "SetBrainHeight\0pauseState\0\0toggled\0"
    "haltState\0gui_downAdjustBtn\0dist\0"
    "gui_upAdjustBtn\0thorLabsMotor_moveComplete\0"
    "gui_pushbuttonGO3Released\0ThorWorker*\0"
    "t"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SetBrainHeight[] = {

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
       7,    1,   51,    2, 0x0a /* Public */,
       8,    0,   54,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void SetBrainHeight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SetBrainHeight *_t = static_cast<SetBrainHeight *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->gui_downAdjustBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->gui_upAdjustBtn((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->thorLabsMotor_moveComplete(); break;
        case 5: _t->gui_pushbuttonGO3Released((*reinterpret_cast< ThorWorker*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ThorWorker* >(); break;
            }
            break;
        }
    }
}

const QMetaObject SetBrainHeight::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_SetBrainHeight.data,
      qt_meta_data_SetBrainHeight,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SetBrainHeight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SetBrainHeight::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SetBrainHeight.stringdata))
        return static_cast<void*>(const_cast< SetBrainHeight*>(this));
    return State::qt_metacast(_clname);
}

int SetBrainHeight::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
