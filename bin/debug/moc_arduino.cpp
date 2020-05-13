/****************************************************************************
** Meta object code from reading C++ file 'arduino.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/arduino.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'arduino.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Arduino_t {
    QByteArrayData data[24];
    char stringdata[244];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Arduino_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Arduino_t qt_meta_stringdata_Arduino = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 15),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 20),
QT_MOC_LITERAL(4, 46, 16),
QT_MOC_LITERAL(5, 63, 16),
QT_MOC_LITERAL(6, 80, 9),
QT_MOC_LITERAL(7, 90, 2),
QT_MOC_LITERAL(8, 93, 4),
QT_MOC_LITERAL(9, 98, 7),
QT_MOC_LITERAL(10, 106, 14),
QT_MOC_LITERAL(11, 121, 4),
QT_MOC_LITERAL(12, 126, 16),
QT_MOC_LITERAL(13, 143, 4),
QT_MOC_LITERAL(14, 148, 11),
QT_MOC_LITERAL(15, 160, 3),
QT_MOC_LITERAL(16, 164, 3),
QT_MOC_LITERAL(17, 168, 7),
QT_MOC_LITERAL(18, 176, 4),
QT_MOC_LITERAL(19, 181, 13),
QT_MOC_LITERAL(20, 195, 9),
QT_MOC_LITERAL(21, 205, 11),
QT_MOC_LITERAL(22, 217, 8),
QT_MOC_LITERAL(23, 226, 16)
    },
    "Arduino\0breakInFinished\0\0clearPipetteFinished\0"
    "arduinoInitReady\0arduinoInitError\0"
    "switchBNC\0on\0init\0comPort\0switchPressure\0"
    "pres\0softwarePressure\0flag\0setPressure\0"
    "num\0val\0breakIn\0time\0msWaitBetween\0"
    "numPulses\0breakInRamp\0pressure\0"
    "closeArduinoPort\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Arduino[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x05,
       3,    0,   75,    2, 0x05,
       4,    0,   76,    2, 0x05,
       5,    0,   77,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    1,   78,    2, 0x0a,
       8,    1,   81,    2, 0x0a,
      10,    1,   84,    2, 0x0a,
      12,    1,   87,    2, 0x0a,
      14,    2,   90,    2, 0x0a,
      17,    3,   95,    2, 0x0a,
      21,    2,  102,    2, 0x0a,
      23,    0,  107,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   15,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   18,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   18,   22,
    QMetaType::Void,

       0        // eod
};

void Arduino::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Arduino *_t = static_cast<Arduino *>(_o);
        switch (_id) {
        case 0: _t->breakInFinished(); break;
        case 1: _t->clearPipetteFinished(); break;
        case 2: _t->arduinoInitReady(); break;
        case 3: _t->arduinoInitError(); break;
        case 4: _t->switchBNC((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->switchPressure((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->softwarePressure((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setPressure((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 9: _t->breakIn((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 10: _t->breakInRamp((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->closeArduinoPort(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Arduino::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::breakInFinished)) {
                *result = 0;
            }
        }
        {
            typedef void (Arduino::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::clearPipetteFinished)) {
                *result = 1;
            }
        }
        {
            typedef void (Arduino::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::arduinoInitReady)) {
                *result = 2;
            }
        }
        {
            typedef void (Arduino::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Arduino::arduinoInitError)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject Arduino::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Arduino.data,
      qt_meta_data_Arduino,  qt_static_metacall, 0, 0}
};


const QMetaObject *Arduino::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Arduino::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Arduino.stringdata))
        return static_cast<void*>(const_cast< Arduino*>(this));
    return QObject::qt_metacast(_clname);
}

int Arduino::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Arduino::breakInFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Arduino::clearPipetteFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Arduino::arduinoInitReady()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Arduino::arduinoInitError()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
