/****************************************************************************
** Meta object code from reading C++ file 'trialinit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/states/trialinit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trialinit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TrialInit_t {
    QByteArrayData data[7];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrialInit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrialInit_t qt_meta_stringdata_TrialInit = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TrialInit"
QT_MOC_LITERAL(1, 10, 5), // "ready"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 10), // "pauseState"
QT_MOC_LITERAL(4, 28, 11), // "resumeState"
QT_MOC_LITERAL(5, 40, 9), // "haltState"
QT_MOC_LITERAL(6, 50, 26) // "thorLabsMotor_moveComplete"

    },
    "TrialInit\0ready\0\0pauseState\0resumeState\0"
    "haltState\0thorLabsMotor_moveComplete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrialInit[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TrialInit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrialInit *_t = static_cast<TrialInit *>(_o);
        switch (_id) {
        case 0: _t->ready(); break;
        case 1: _t->pauseState(); break;
        case 2: _t->resumeState(); break;
        case 3: _t->haltState(); break;
        case 4: _t->thorLabsMotor_moveComplete(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TrialInit::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_TrialInit.data,
      qt_meta_data_TrialInit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TrialInit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrialInit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TrialInit.stringdata))
        return static_cast<void*>(const_cast< TrialInit*>(this));
    return State::qt_metacast(_clname);
}

int TrialInit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
