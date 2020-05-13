/****************************************************************************
** Meta object code from reading C++ file 'multiclampworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/workers/multiclampworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiclampworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MulticlampWorker_t {
    QByteArrayData data[25];
    char stringdata[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MulticlampWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MulticlampWorker_t qt_meta_stringdata_MulticlampWorker = {
    {
QT_MOC_LITERAL(0, 0, 16), // "MulticlampWorker"
QT_MOC_LITERAL(1, 17, 9), // "initReady"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "initError"
QT_MOC_LITERAL(4, 38, 12), // "initComplete"
QT_MOC_LITERAL(5, 51, 6), // "zapped"
QT_MOC_LITERAL(6, 58, 14), // "switchPressure"
QT_MOC_LITERAL(7, 73, 3), // "val"
QT_MOC_LITERAL(8, 77, 18), // "autoOffsetComplete"
QT_MOC_LITERAL(9, 96, 4), // "init"
QT_MOC_LITERAL(10, 101, 7), // "numMPCS"
QT_MOC_LITERAL(11, 109, 4), // "path"
QT_MOC_LITERAL(12, 114, 7), // "setMode"
QT_MOC_LITERAL(13, 122, 4), // "mode"
QT_MOC_LITERAL(14, 127, 17), // "setHoldingVoltage"
QT_MOC_LITERAL(15, 145, 4), // "volt"
QT_MOC_LITERAL(16, 150, 17), // "setHoldingCurrent"
QT_MOC_LITERAL(17, 168, 4), // "curr"
QT_MOC_LITERAL(18, 173, 17), // "autoCorrectOffset"
QT_MOC_LITERAL(19, 191, 13), // "selectChannel"
QT_MOC_LITERAL(20, 205, 2), // "id"
QT_MOC_LITERAL(21, 208, 3), // "zap"
QT_MOC_LITERAL(22, 212, 4), // "time"
QT_MOC_LITERAL(23, 217, 24), // "setHoldingVoltageChecked"
QT_MOC_LITERAL(24, 242, 4) // "flag"

    },
    "MulticlampWorker\0initReady\0\0initError\0"
    "initComplete\0zapped\0switchPressure\0"
    "val\0autoOffsetComplete\0init\0numMPCS\0"
    "path\0setMode\0mode\0setHoldingVoltage\0"
    "volt\0setHoldingCurrent\0curr\0"
    "autoCorrectOffset\0selectChannel\0id\0"
    "zap\0time\0setHoldingVoltageChecked\0"
    "flag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MulticlampWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       8,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   92,    2, 0x0a /* Public */,
      12,    1,   97,    2, 0x0a /* Public */,
      14,    1,  100,    2, 0x0a /* Public */,
      16,    1,  103,    2, 0x0a /* Public */,
      18,    0,  106,    2, 0x0a /* Public */,
      19,    1,  107,    2, 0x0a /* Public */,
      21,    1,  110,    2, 0x0a /* Public */,
      23,    1,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Double,   15,
    QMetaType::Void, QMetaType::Double,   17,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Double,   22,
    QMetaType::Void, QMetaType::Bool,   24,

       0        // eod
};

void MulticlampWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MulticlampWorker *_t = static_cast<MulticlampWorker *>(_o);
        switch (_id) {
        case 0: _t->initReady(); break;
        case 1: _t->initError(); break;
        case 2: _t->initComplete(); break;
        case 3: _t->zapped(); break;
        case 4: _t->switchPressure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->autoOffsetComplete(); break;
        case 6: _t->init((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->setMode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setHoldingVoltage((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setHoldingCurrent((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->autoCorrectOffset(); break;
        case 11: _t->selectChannel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->zap((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->setHoldingVoltageChecked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::initReady)) {
                *result = 0;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::initError)) {
                *result = 1;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::initComplete)) {
                *result = 2;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::zapped)) {
                *result = 3;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::switchPressure)) {
                *result = 4;
            }
        }
        {
            typedef void (MulticlampWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MulticlampWorker::autoOffsetComplete)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MulticlampWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MulticlampWorker.data,
      qt_meta_data_MulticlampWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MulticlampWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MulticlampWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MulticlampWorker.stringdata))
        return static_cast<void*>(const_cast< MulticlampWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int MulticlampWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MulticlampWorker::initReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MulticlampWorker::initError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MulticlampWorker::initComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MulticlampWorker::zapped()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MulticlampWorker::switchPressure(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MulticlampWorker::autoOffsetComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
