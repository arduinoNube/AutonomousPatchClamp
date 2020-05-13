/****************************************************************************
** Meta object code from reading C++ file 'record.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/states/record.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'record.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Record_t {
    QByteArrayData data[19];
    char stringdata[195];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Record_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Record_t qt_meta_stringdata_Record = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Record"
QT_MOC_LITERAL(1, 7, 10), // "pauseState"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "toggled"
QT_MOC_LITERAL(4, 27, 9), // "haltState"
QT_MOC_LITERAL(5, 37, 1), // "A"
QT_MOC_LITERAL(6, 39, 15), // "QVector<double>"
QT_MOC_LITERAL(7, 55, 7), // "injData"
QT_MOC_LITERAL(8, 63, 2), // "AA"
QT_MOC_LITERAL(9, 66, 14), // "visual_started"
QT_MOC_LITERAL(10, 81, 14), // "visual_stopped"
QT_MOC_LITERAL(11, 96, 1), // "B"
QT_MOC_LITERAL(12, 98, 13), // "visual_paused"
QT_MOC_LITERAL(13, 112, 15), // "visual_finished"
QT_MOC_LITERAL(14, 128, 14), // "timer1_timeout"
QT_MOC_LITERAL(15, 143, 14), // "timer2_timeout"
QT_MOC_LITERAL(16, 158, 11), // "dialogClose"
QT_MOC_LITERAL(17, 170, 11), // "finishState"
QT_MOC_LITERAL(18, 182, 12) // "finishState2"

    },
    "Record\0pauseState\0\0toggled\0haltState\0"
    "A\0QVector<double>\0injData\0AA\0"
    "visual_started\0visual_stopped\0B\0"
    "visual_paused\0visual_finished\0"
    "timer1_timeout\0timer2_timeout\0dialogClose\0"
    "finishState\0finishState2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Record[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x0a /* Public */,
       4,    0,   87,    2, 0x0a /* Public */,
       5,    1,   88,    2, 0x0a /* Public */,
       8,    1,   91,    2, 0x0a /* Public */,
       9,    0,   94,    2, 0x0a /* Public */,
      10,    0,   95,    2, 0x0a /* Public */,
      11,    1,   96,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Record::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Record *_t = static_cast<Record *>(_o);
        switch (_id) {
        case 0: _t->pauseState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->haltState(); break;
        case 2: _t->A((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 3: _t->AA((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 4: _t->visual_started(); break;
        case 5: _t->visual_stopped(); break;
        case 6: _t->B((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 7: _t->visual_paused(); break;
        case 8: _t->visual_finished(); break;
        case 9: _t->timer1_timeout(); break;
        case 10: _t->timer2_timeout(); break;
        case 11: _t->dialogClose(); break;
        case 12: _t->finishState(); break;
        case 13: _t->finishState2(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

const QMetaObject Record::staticMetaObject = {
    { &State::staticMetaObject, qt_meta_stringdata_Record.data,
      qt_meta_data_Record,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Record::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Record::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Record.stringdata))
        return static_cast<void*>(const_cast< Record*>(this));
    return State::qt_metacast(_clname);
}

int Record::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = State::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
