/****************************************************************************
** Meta object code from reading C++ file 'preferences.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/ui/preferences.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferences.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Preferences_t {
    QByteArrayData data[11];
    char stringdata[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Preferences_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Preferences_t qt_meta_stringdata_Preferences = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Preferences"
QT_MOC_LITERAL(1, 12, 12), // "windowClosed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 38), // "on_pushButtonBrowseForDataDir..."
QT_MOC_LITERAL(4, 65, 21), // "on_checkBox_2_toggled"
QT_MOC_LITERAL(5, 87, 7), // "checked"
QT_MOC_LITERAL(6, 95, 19), // "on_checkBox_toggled"
QT_MOC_LITERAL(7, 115, 14), // "dataDirChanged"
QT_MOC_LITERAL(8, 130, 3), // "dir"
QT_MOC_LITERAL(9, 134, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(10, 156, 21) // "on_buttonBox_rejected"

    },
    "Preferences\0windowClosed\0\0"
    "on_pushButtonBrowseForDataDir_released\0"
    "on_checkBox_2_toggled\0checked\0"
    "on_checkBox_toggled\0dataDirChanged\0"
    "dir\0on_buttonBox_accepted\0"
    "on_buttonBox_rejected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Preferences[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       9,    0,   60,    2, 0x08 /* Private */,
      10,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Preferences::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Preferences *_t = static_cast<Preferences *>(_o);
        switch (_id) {
        case 0: _t->windowClosed(); break;
        case 1: _t->on_pushButtonBrowseForDataDir_released(); break;
        case 2: _t->on_checkBox_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->dataDirChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_buttonBox_accepted(); break;
        case 6: _t->on_buttonBox_rejected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Preferences::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Preferences::windowClosed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject Preferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Preferences.data,
      qt_meta_data_Preferences,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Preferences::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Preferences::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Preferences.stringdata))
        return static_cast<void*>(const_cast< Preferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int Preferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Preferences::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
