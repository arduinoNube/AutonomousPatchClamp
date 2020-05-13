/****************************************************************************
** Meta object code from reading C++ file 'breakin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/states/breakin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breakin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BreakIn_t {
    QByteArrayData data[6];
    char stringdata[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BreakIn_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BreakIn_t qt_meta_stringdata_BreakIn = {
    {
QT_MOC_LITERAL(0, 0, 7), // "BreakIn"
QT_MOC_LITERAL(1, 8, 10), // "pauseState"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "resumeState"
QT_MOC_LITERAL(4, 32, 9), // "haltState"
QT_MOC_LITERAL(5, 42, 3) // "zap"

    },
    "BreakIn\0pauseState\0\0resumeState\0"
    "haltState\0zap"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BreakIn[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BreakIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BreakIn *_t = static_cast<BreakIn *>(_o);
        switch (_id) {
        case 0: _t->pauseState(); break;
        case 1: _t->resumeState(); break;
        case 2: _t->haltState(); break;
        case 3: _t->zap(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject BreakIn::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_BreakIn.data,
      qt_meta_data_BreakIn,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BreakIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BreakIn::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BreakIn.stringdata))
        return static_cast<void*>(const_cast< BreakIn*>(this));
    return State::qt_metacast(_clname);
}

int BreakIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
