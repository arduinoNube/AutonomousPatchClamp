/****************************************************************************
** Meta object code from reading C++ file 'gigaseal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/states/gigaseal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gigaseal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gigaseal_t {
    QByteArrayData data[8];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Gigaseal_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Gigaseal_t qt_meta_stringdata_Gigaseal = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Gigaseal"
QT_MOC_LITERAL(1, 9, 10), // "pauseState"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "resumeState"
QT_MOC_LITERAL(4, 33, 9), // "haltState"
QT_MOC_LITERAL(5, 43, 32), // "gui_onCheckBoxkLowV_stateChanged"
QT_MOC_LITERAL(6, 76, 4), // "arg1"
QT_MOC_LITERAL(7, 81, 39) // "gui_onCheckBoxRampOverride_st..."

    },
    "Gigaseal\0pauseState\0\0resumeState\0"
    "haltState\0gui_onCheckBoxkLowV_stateChanged\0"
    "arg1\0gui_onCheckBoxRampOverride_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gigaseal[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void Gigaseal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gigaseal *_t = static_cast<Gigaseal *>(_o);
        switch (_id) {
        case 0: _t->pauseState(); break;
        case 1: _t->resumeState(); break;
        case 2: _t->haltState(); break;
        case 3: _t->gui_onCheckBoxkLowV_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->gui_onCheckBoxRampOverride_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Gigaseal::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_Gigaseal.data,
      qt_meta_data_Gigaseal,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Gigaseal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gigaseal::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Gigaseal.stringdata))
        return static_cast<void*>(const_cast< Gigaseal*>(this));
    return State::qt_metacast(_clname);
}

int Gigaseal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
