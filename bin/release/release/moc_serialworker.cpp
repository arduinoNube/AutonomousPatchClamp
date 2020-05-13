/****************************************************************************
** Meta object code from reading C++ file 'serialworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/workers/serialworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SerialWorker_t {
    QByteArrayData data[8];
    char stringdata[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialWorker_t qt_meta_stringdata_SerialWorker = {
    {
QT_MOC_LITERAL(0, 0, 12), // "SerialWorker"
QT_MOC_LITERAL(1, 13, 9), // "initReady"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 9), // "initError"
QT_MOC_LITERAL(4, 34, 15), // "commandFinished"
QT_MOC_LITERAL(5, 50, 4), // "init"
QT_MOC_LITERAL(6, 55, 7), // "comPort"
QT_MOC_LITERAL(7, 63, 20) // "checkCommandFinished"

    },
    "SerialWorker\0initReady\0\0initError\0"
    "commandFinished\0init\0comPort\0"
    "checkCommandFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void SerialWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialWorker *_t = static_cast<SerialWorker *>(_o);
        switch (_id) {
        case 0: _t->initReady(); break;
        case 1: _t->initError(); break;
        case 2: _t->commandFinished(); break;
        case 3: _t->init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->checkCommandFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SerialWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialWorker::initReady)) {
                *result = 0;
            }
        }
        {
            typedef void (SerialWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialWorker::initError)) {
                *result = 1;
            }
        }
        {
            typedef void (SerialWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SerialWorker::commandFinished)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject SerialWorker::staticMetaObject = {
    { &Worker::staticMetaObject, qt_meta_stringdata_SerialWorker.data,
      qt_meta_data_SerialWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SerialWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SerialWorker.stringdata))
        return static_cast<void*>(const_cast< SerialWorker*>(this));
    return Worker::qt_metacast(_clname);
}

int SerialWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void SerialWorker::initReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SerialWorker::initError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SerialWorker::commandFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
