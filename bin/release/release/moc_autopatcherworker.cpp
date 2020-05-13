/****************************************************************************
** Meta object code from reading C++ file 'autopatcherworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/workers/autopatcherworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autopatcherworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AutopatcherWorker_t {
    QByteArrayData data[29];
    char stringdata[327];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutopatcherWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutopatcherWorker_t qt_meta_stringdata_AutopatcherWorker = {
    {
QT_MOC_LITERAL(0, 0, 17), // "AutopatcherWorker"
QT_MOC_LITERAL(1, 18, 15), // "breakInFinished"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 19), // "breakInRampFinished"
QT_MOC_LITERAL(4, 55, 9), // "switchBNC"
QT_MOC_LITERAL(5, 65, 2), // "on"
QT_MOC_LITERAL(6, 68, 9), // "sendEvent"
QT_MOC_LITERAL(7, 78, 14), // "switchPressure"
QT_MOC_LITERAL(8, 93, 4), // "pres"
QT_MOC_LITERAL(9, 98, 16), // "softwarePressure"
QT_MOC_LITERAL(10, 115, 4), // "flag"
QT_MOC_LITERAL(11, 120, 11), // "setPressure"
QT_MOC_LITERAL(12, 132, 3), // "num"
QT_MOC_LITERAL(13, 136, 3), // "val"
QT_MOC_LITERAL(14, 140, 7), // "breakIn"
QT_MOC_LITERAL(15, 148, 4), // "time"
QT_MOC_LITERAL(16, 153, 13), // "msWaitBetween"
QT_MOC_LITERAL(17, 167, 9), // "numPulses"
QT_MOC_LITERAL(18, 177, 11), // "breakInRamp"
QT_MOC_LITERAL(19, 189, 8), // "pressure"
QT_MOC_LITERAL(20, 198, 19), // "breakInRampFeedback"
QT_MOC_LITERAL(21, 218, 8), // "stopRamp"
QT_MOC_LITERAL(22, 227, 12), // "aboutToClose"
QT_MOC_LITERAL(23, 240, 12), // "initInThread"
QT_MOC_LITERAL(24, 253, 15), // "setHardwareVals"
QT_MOC_LITERAL(25, 269, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(26, 293, 3), // "win"
QT_MOC_LITERAL(27, 297, 14), // "timer1_timeout"
QT_MOC_LITERAL(28, 312, 14) // "moveThreadBack"

    },
    "AutopatcherWorker\0breakInFinished\0\0"
    "breakInRampFinished\0switchBNC\0on\0"
    "sendEvent\0switchPressure\0pres\0"
    "softwarePressure\0flag\0setPressure\0num\0"
    "val\0breakIn\0time\0msWaitBetween\0numPulses\0"
    "breakInRamp\0pressure\0breakInRampFeedback\0"
    "stopRamp\0aboutToClose\0initInThread\0"
    "setHardwareVals\0HardwareSettingsWindow*\0"
    "win\0timer1_timeout\0moveThreadBack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutopatcherWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   91,    2, 0x0a /* Public */,
       7,    2,   96,    2, 0x0a /* Public */,
       9,    2,  101,    2, 0x0a /* Public */,
      11,    3,  106,    2, 0x0a /* Public */,
      14,    3,  113,    2, 0x0a /* Public */,
      18,    2,  120,    2, 0x0a /* Public */,
      20,    1,  125,    2, 0x0a /* Public */,
      21,    0,  128,    2, 0x0a /* Public */,
      22,    0,  129,    2, 0x0a /* Public */,
      23,    0,  130,    2, 0x0a /* Public */,
      24,    1,  131,    2, 0x0a /* Public */,
      27,    0,  134,    2, 0x08 /* Private */,
      28,    0,  135,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    8,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   10,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::Bool,   12,   13,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   15,   16,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   19,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 25,   26,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AutopatcherWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AutopatcherWorker *_t = static_cast<AutopatcherWorker *>(_o);
        switch (_id) {
        case 0: _t->breakInFinished(); break;
        case 1: _t->breakInRampFinished(); break;
        case 2: _t->switchBNC((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->switchPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->softwarePressure((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->setPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->breakIn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->breakInRamp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->breakInRampFeedback((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->stopRamp(); break;
        case 10: _t->aboutToClose(); break;
        case 11: _t->initInThread(); break;
        case 12: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 13: _t->timer1_timeout(); break;
        case 14: _t->moveThreadBack(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< HardwareSettingsWindow* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AutopatcherWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AutopatcherWorker::breakInFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (AutopatcherWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AutopatcherWorker::breakInRampFinished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AutopatcherWorker::staticMetaObject = {
    { &SerialWorker::staticMetaObject, qt_meta_stringdata_AutopatcherWorker.data,
      qt_meta_data_AutopatcherWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutopatcherWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutopatcherWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutopatcherWorker.stringdata))
        return static_cast<void*>(const_cast< AutopatcherWorker*>(this));
    return SerialWorker::qt_metacast(_clname);
}

int AutopatcherWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SerialWorker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void AutopatcherWorker::breakInFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void AutopatcherWorker::breakInRampFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
