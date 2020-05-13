/****************************************************************************
** Meta object code from reading C++ file 'lengthmeasurementcameraworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/workers/lengthmeasurementcameraworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lengthmeasurementcameraworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LengthMeasurementCameraWorker_t {
    QByteArrayData data[12];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LengthMeasurementCameraWorker_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LengthMeasurementCameraWorker_t qt_meta_stringdata_LengthMeasurementCameraWorker = {
    {
QT_MOC_LITERAL(0, 0, 29), // "LengthMeasurementCameraWorker"
QT_MOC_LITERAL(1, 30, 9), // "initReady"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "initError"
QT_MOC_LITERAL(4, 51, 13), // "imagesAquired"
QT_MOC_LITERAL(5, 65, 16), // "measurementReady"
QT_MOC_LITERAL(6, 82, 6), // "length"
QT_MOC_LITERAL(7, 89, 4), // "init"
QT_MOC_LITERAL(8, 94, 13), // "measureLength"
QT_MOC_LITERAL(9, 108, 12), // "aboutToClose"
QT_MOC_LITERAL(10, 121, 15), // "setHardwareVals"
QT_MOC_LITERAL(11, 137, 23) // "HardwareSettingsWindow*"

    },
    "LengthMeasurementCameraWorker\0initReady\0"
    "\0initError\0imagesAquired\0measurementReady\0"
    "length\0init\0measureLength\0aboutToClose\0"
    "setHardwareVals\0HardwareSettingsWindow*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LengthMeasurementCameraWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   60,    2, 0x0a /* Public */,
       8,    0,   61,    2, 0x0a /* Public */,
       9,    0,   62,    2, 0x0a /* Public */,
      10,    1,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    2,

       0        // eod
};

void LengthMeasurementCameraWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LengthMeasurementCameraWorker *_t = static_cast<LengthMeasurementCameraWorker *>(_o);
        switch (_id) {
        case 0: _t->initReady(); break;
        case 1: _t->initError(); break;
        case 2: _t->imagesAquired(); break;
        case 3: _t->measurementReady((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->init(); break;
        case 5: _t->measureLength(); break;
        case 6: _t->aboutToClose(); break;
        case 7: _t->setHardwareVals((*reinterpret_cast< HardwareSettingsWindow*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 7:
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
            typedef void (LengthMeasurementCameraWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LengthMeasurementCameraWorker::initReady)) {
                *result = 0;
            }
        }
        {
            typedef void (LengthMeasurementCameraWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LengthMeasurementCameraWorker::initError)) {
                *result = 1;
            }
        }
        {
            typedef void (LengthMeasurementCameraWorker::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LengthMeasurementCameraWorker::imagesAquired)) {
                *result = 2;
            }
        }
        {
            typedef void (LengthMeasurementCameraWorker::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LengthMeasurementCameraWorker::measurementReady)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject LengthMeasurementCameraWorker::staticMetaObject = {
    { &Worker::staticMetaObject, qt_meta_stringdata_LengthMeasurementCameraWorker.data,
      qt_meta_data_LengthMeasurementCameraWorker,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LengthMeasurementCameraWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LengthMeasurementCameraWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LengthMeasurementCameraWorker.stringdata))
        return static_cast<void*>(const_cast< LengthMeasurementCameraWorker*>(this));
    return Worker::qt_metacast(_clname);
}

int LengthMeasurementCameraWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Worker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void LengthMeasurementCameraWorker::initReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void LengthMeasurementCameraWorker::initError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void LengthMeasurementCameraWorker::imagesAquired()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void LengthMeasurementCameraWorker::measurementReady(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
