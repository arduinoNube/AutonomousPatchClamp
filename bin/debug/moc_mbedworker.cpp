/****************************************************************************
** Meta object code from reading C++ file 'mbedworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/mbedworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mbedworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MbedWorker_t {
    QByteArrayData data[17];
    char stringdata[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MbedWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MbedWorker_t qt_meta_stringdata_MbedWorker = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 9),
QT_MOC_LITERAL(2, 21, 0),
QT_MOC_LITERAL(3, 22, 13),
QT_MOC_LITERAL(4, 36, 16),
QT_MOC_LITERAL(5, 53, 9),
QT_MOC_LITERAL(6, 63, 6),
QT_MOC_LITERAL(7, 70, 9),
QT_MOC_LITERAL(8, 80, 16),
QT_MOC_LITERAL(9, 97, 9),
QT_MOC_LITERAL(10, 107, 18),
QT_MOC_LITERAL(11, 126, 17),
QT_MOC_LITERAL(12, 144, 10),
QT_MOC_LITERAL(13, 155, 11),
QT_MOC_LITERAL(14, 167, 3),
QT_MOC_LITERAL(15, 171, 11),
QT_MOC_LITERAL(16, 183, 11)
    },
    "MbedWorker\0mbedReady\0\0mbedInitError\0"
    "rotationFinished\0initMbed1\0comStr\0"
    "initMbed2\0calibrateCarosel\0lockHoriz\0"
    "retractPipetteWire\0extendPipetteWire\0"
    "unlockHorz\0goToPipette\0num\0nextPipette\0"
    "closeSerial\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MbedWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x05,
       3,    0,   80,    2, 0x05,
       4,    0,   81,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    1,   82,    2, 0x0a,
       7,    0,   85,    2, 0x0a,
       8,    0,   86,    2, 0x0a,
       9,    0,   87,    2, 0x0a,
      10,    0,   88,    2, 0x0a,
      11,    0,   89,    2, 0x0a,
      12,    0,   90,    2, 0x0a,
      13,    1,   91,    2, 0x0a,
      15,    0,   94,    2, 0x0a,
      16,    0,   95,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MbedWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MbedWorker *_t = static_cast<MbedWorker *>(_o);
        switch (_id) {
        case 0: _t->mbedReady(); break;
        case 1: _t->mbedInitError(); break;
        case 2: _t->rotationFinished(); break;
        case 3: _t->initMbed1((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->initMbed2(); break;
        case 5: _t->calibrateCarosel(); break;
        case 6: _t->lockHoriz(); break;
        case 7: _t->retractPipetteWire(); break;
        case 8: _t->extendPipetteWire(); break;
        case 9: _t->unlockHorz(); break;
        case 10: _t->goToPipette((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->nextPipette(); break;
        case 12: _t->closeSerial(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MbedWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MbedWorker::mbedReady)) {
                *result = 0;
            }
        }
        {
            typedef void (MbedWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MbedWorker::mbedInitError)) {
                *result = 1;
            }
        }
        {
            typedef void (MbedWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MbedWorker::rotationFinished)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MbedWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MbedWorker.data,
      qt_meta_data_MbedWorker,  qt_static_metacall, 0, 0}
};


const QMetaObject *MbedWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MbedWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MbedWorker.stringdata))
        return static_cast<void*>(const_cast< MbedWorker*>(this));
    return QObject::qt_metacast(_clname);
}

int MbedWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MbedWorker::mbedReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void MbedWorker::mbedInitError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MbedWorker::rotationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
