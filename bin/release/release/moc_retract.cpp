/****************************************************************************
** Meta object code from reading C++ file 'retract.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/states/retract.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'retract.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Retract_t {
    QByteArrayData data[6];
    char stringdata[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Retract_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Retract_t qt_meta_stringdata_Retract = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Retract"
QT_MOC_LITERAL(1, 8, 10), // "pauseState"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "toggled"
QT_MOC_LITERAL(4, 28, 9), // "haltState"
QT_MOC_LITERAL(5, 38, 26) // "thorLabsMotor_moveComplete"

    },
    "Retract\0pauseState\0\0toggled\0haltState\0"
    "thorLabsMotor_moveComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Retract[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    0,   32,    2, 0x0a /* Public */,
       5,    0,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Retract::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Retract *_t = static_cast<Retract *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->thorLabsMotor_moveComplete(); break;
        default: ;
        }
    }
}

const QMetaObject Retract::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_Retract.data,
      qt_meta_data_Retract,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Retract::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Retract::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Retract.stringdata))
        return static_cast<void*>(const_cast< Retract*>(this));
    return State::qt_metacast(_clname);
}

int Retract::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
