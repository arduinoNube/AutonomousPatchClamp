/****************************************************************************
** Meta object code from reading C++ file 'visualstimuliworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/workers/visualstimuliworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualstimuliworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VisualStimuliWorker_t {
    QByteArrayData data[22];
    char stringdata[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VisualStimuliWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VisualStimuliWorker_t qt_meta_stringdata_VisualStimuliWorker = {
    {
QT_MOC_LITERAL(0, 0, 19), // "VisualStimuliWorker"
QT_MOC_LITERAL(1, 20, 9), // "initReady"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "initError"
QT_MOC_LITERAL(4, 41, 7), // "started"
QT_MOC_LITERAL(5, 49, 6), // "paused"
QT_MOC_LITERAL(6, 56, 8), // "finished"
QT_MOC_LITERAL(7, 65, 7), // "stopped"
QT_MOC_LITERAL(8, 73, 4), // "init"
QT_MOC_LITERAL(9, 78, 5), // "start"
QT_MOC_LITERAL(10, 84, 9), // "screebNum"
QT_MOC_LITERAL(11, 94, 4), // "stop"
QT_MOC_LITERAL(12, 99, 5), // "pause"
QT_MOC_LITERAL(13, 105, 9), // "continue_"
QT_MOC_LITERAL(14, 115, 15), // "setHardwareVals"
QT_MOC_LITERAL(15, 131, 23), // "HardwareSettingsWindow*"
QT_MOC_LITERAL(16, 155, 6), // "hw_win"
QT_MOC_LITERAL(17, 162, 13), // "sessionOpened"
QT_MOC_LITERAL(18, 176, 12), // "on_readyRead"
QT_MOC_LITERAL(19, 189, 15), // "on_disconnected"
QT_MOC_LITERAL(20, 205, 5), // "write"
QT_MOC_LITERAL(21, 211, 14) // "timer1_timeout"

    },
    "VisualStimuliWorker\0initReady\0\0initError\0"
    "started\0paused\0finished\0stopped\0init\0"
    "start\0screebNum\0stop\0pause\0continue_\0"
    "setHardwareVals\0HardwareSettingsWindow*\0"
    "hw_win\0sessionOpened\0on_readyRead\0"
    "on_disconnected\0write\0timer1_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VisualStimuliWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    0,  103,    2, 0x06 /* Public */,
       7,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    2,  105,    2, 0x0a /* Public */,
       9,    1,  110,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    1,  116,    2, 0x0a /* Public */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,
      20,    1,  122,    2, 0x08 /* Private */,
      21,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void VisualStimuliWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VisualStimuliWorker *_t = static_cast<VisualStimuliWorker *>(_o);
        switch (_id) {
        case 0: _t->initReady(); break;
        case 1: _t->initError(); break;
        case 2: _t->started(); break;
        case 3: _t->paused(); break;
        case 4: _t->finished(); break;
        case 5: _t->stopped(); break;
        case 6: _t->init((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->start((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->stop(); break;
        case 9: _t->pause(); break;
        case 10: _t->continue_(); break;
        case 11: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        case 12: _t->sessionOpened(); break;
        case 13: _t->on_readyRead(); break;
        case 14: _t->on_disconnected(); break;
        case 15: _t->write((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->timer1_timeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
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
            typedef void (VisualStimuliWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualStimuliWorker::initReady)) {
                *result = 0;
            }
        }
        {
            typedef void (VisualStimuliWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualStimuliWorker::initError)) {
                *result = 1;
            }
        }
        {
            typedef void (VisualStimuliWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualStimuliWorker::started)) {
                *result = 2;
            }
        }
        {
            typedef void (VisualStimuliWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualStimuliWorker::paused)) {
                *result = 3;
            }
        }
        {
            typedef void (VisualStimuliWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualStimuliWorker::finished)) {
                *result = 4;
            }
        }
        {
            typedef void (VisualStimuliWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&VisualStimuliWorker::stopped)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject VisualStimuliWorker::staticMetaObject = {
    { &Worker::staticMetaObject, qt_meta_stringdata_VisualStimuliWorker.data,
      qt_meta_data_VisualStimuliWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VisualStimuliWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VisualStimuliWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VisualStimuliWorker.stringdata))
        return static_cast<void*>(const_cast< VisualStimuliWorker*>(this));
    return Worker::qt_metacast(_clname);
}

int VisualStimuliWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void VisualStimuliWorker::initReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void VisualStimuliWorker::initError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void VisualStimuliWorker::started()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void VisualStimuliWorker::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void VisualStimuliWorker::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void VisualStimuliWorker::stopped()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
