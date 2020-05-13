/****************************************************************************
** Meta object code from reading C++ file 'hardwareinit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/states/hardwareinit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hardwareinit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HardwareInit_t {
    QByteArrayData data[20];
    char stringdata[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HardwareInit_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HardwareInit_t qt_meta_stringdata_HardwareInit = {
    {
QT_MOC_LITERAL(0, 0, 12), // "HardwareInit"
QT_MOC_LITERAL(1, 13, 10), // "pauseState"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "resumeState"
QT_MOC_LITERAL(4, 37, 9), // "haltState"
QT_MOC_LITERAL(5, 47, 21), // "autopatcher_initReady"
QT_MOC_LITERAL(6, 69, 21), // "autopatcher_initError"
QT_MOC_LITERAL(7, 91, 24), // "headstageClamp_initReady"
QT_MOC_LITERAL(8, 116, 24), // "headstageClamp_initError"
QT_MOC_LITERAL(9, 141, 15), // "scara_initReady"
QT_MOC_LITERAL(10, 157, 15), // "scara_initError"
QT_MOC_LITERAL(11, 173, 16), // "filler_initReady"
QT_MOC_LITERAL(12, 190, 16), // "filler_initError"
QT_MOC_LITERAL(13, 207, 23), // "thorLabsMotor_initReady"
QT_MOC_LITERAL(14, 231, 23), // "thorLabsMotor_initError"
QT_MOC_LITERAL(15, 255, 20), // "multiclamp_initReady"
QT_MOC_LITERAL(16, 276, 20), // "multiclamp_initError"
QT_MOC_LITERAL(17, 297, 13), // "daq_initReady"
QT_MOC_LITERAL(18, 311, 13), // "daq_initError"
QT_MOC_LITERAL(19, 325, 9) // "checkInit"

    },
    "HardwareInit\0pauseState\0\0resumeState\0"
    "haltState\0autopatcher_initReady\0"
    "autopatcher_initError\0headstageClamp_initReady\0"
    "headstageClamp_initError\0scara_initReady\0"
    "scara_initError\0filler_initReady\0"
    "filler_initError\0thorLabsMotor_initReady\0"
    "thorLabsMotor_initError\0multiclamp_initReady\0"
    "multiclamp_initError\0daq_initReady\0"
    "daq_initError\0checkInit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HardwareInit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HardwareInit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HardwareInit *_t = static_cast<HardwareInit *>(_o);
        switch (_id) {
        case 0: _t->pauseState(); break;
        case 1: _t->resumeState(); break;
        case 2: _t->haltState(); break;
        case 3: _t->autopatcher_initReady(); break;
        case 4: _t->autopatcher_initError(); break;
        case 5: _t->headstageClamp_initReady(); break;
        case 6: _t->headstageClamp_initError(); break;
        case 7: _t->scara_initReady(); break;
        case 8: _t->scara_initError(); break;
        case 9: _t->filler_initReady(); break;
        case 10: _t->filler_initError(); break;
        case 11: _t->thorLabsMotor_initReady(); break;
        case 12: _t->thorLabsMotor_initError(); break;
        case 13: _t->multiclamp_initReady(); break;
        case 14: _t->multiclamp_initError(); break;
        case 15: _t->daq_initReady(); break;
        case 16: _t->daq_initError(); break;
        case 17: _t->checkInit(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HardwareInit::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_HardwareInit.data,
      qt_meta_data_HardwareInit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HardwareInit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HardwareInit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HardwareInit.stringdata))
        return static_cast<void*>(const_cast< HardwareInit*>(this));
    return State::qt_metacast(_clname);
}

int HardwareInit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
