/****************************************************************************
** Meta object code from reading C++ file 'hardwarecalib.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/states/hardwarecalib.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hardwarecalib.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HardwareCalib_t {
    QByteArrayData data[11];
    char stringdata[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HardwareCalib_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HardwareCalib_t qt_meta_stringdata_HardwareCalib = {
    {
QT_MOC_LITERAL(0, 0, 13), // "HardwareCalib"
QT_MOC_LITERAL(1, 14, 10), // "pauseState"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "resumeState"
QT_MOC_LITERAL(4, 38, 9), // "haltState"
QT_MOC_LITERAL(5, 48, 18), // "gui_calibrateSCARA"
QT_MOC_LITERAL(6, 67, 21), // "scara_commandFinished"
QT_MOC_LITERAL(7, 89, 31), // "thorLabsMotor_calibrateFinished"
QT_MOC_LITERAL(8, 121, 15), // "checkCalibrated"
QT_MOC_LITERAL(9, 137, 1), // "A"
QT_MOC_LITERAL(10, 139, 1) // "B"

    },
    "HardwareCalib\0pauseState\0\0resumeState\0"
    "haltState\0gui_calibrateSCARA\0"
    "scara_commandFinished\0"
    "thorLabsMotor_calibrateFinished\0"
    "checkCalibrated\0A\0B"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HardwareCalib[] = {

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
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void HardwareCalib::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HardwareCalib *_t = static_cast<HardwareCalib *>(_o);
        switch (_id) {
        case 0: _t->pauseState(); break;
        case 1: _t->resumeState(); break;
        case 2: _t->haltState(); break;
        case 3: _t->gui_calibrateSCARA(); break;
        case 4: _t->scara_commandFinished(); break;
        case 5: _t->thorLabsMotor_calibrateFinished(); break;
        case 6: _t->checkCalibrated(); break;
        case 7: _t->A(); break;
        case 8: _t->B(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject HardwareCalib::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_HardwareCalib.data,
      qt_meta_data_HardwareCalib,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HardwareCalib::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HardwareCalib::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HardwareCalib.stringdata))
        return static_cast<void*>(const_cast< HardwareCalib*>(this));
    return State::qt_metacast(_clname);
}

int HardwareCalib::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
