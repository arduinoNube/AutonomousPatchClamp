/****************************************************************************
** Meta object code from reading C++ file 'breakinsettingszap.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/ui/breakinsettingszap.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breakinsettingszap.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BreakInSettingsZap_t {
    QByteArrayData data[16];
    char stringdata[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BreakInSettingsZap_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BreakInSettingsZap_t qt_meta_stringdata_BreakInSettingsZap = {
    {
QT_MOC_LITERAL(0, 0, 18), // "BreakInSettingsZap"
QT_MOC_LITERAL(1, 19, 12), // "windowClosed"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 34), // "on_pushButtonAddRowBreakIn_cl..."
QT_MOC_LITERAL(4, 68, 37), // "on_pushButtonDeleteRowBreakIn..."
QT_MOC_LITERAL(5, 106, 11), // "updateTable"
QT_MOC_LITERAL(6, 118, 33), // "on_tableWidgetBreakIn_cellCha..."
QT_MOC_LITERAL(7, 152, 3), // "row"
QT_MOC_LITERAL(8, 156, 6), // "column"
QT_MOC_LITERAL(9, 163, 10), // "closeEvent"
QT_MOC_LITERAL(10, 174, 12), // "QCloseEvent*"
QT_MOC_LITERAL(11, 187, 1), // "e"
QT_MOC_LITERAL(12, 189, 23), // "on_pushButtonOk_clicked"
QT_MOC_LITERAL(13, 213, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(14, 241, 9), // "showEvent"
QT_MOC_LITERAL(15, 251, 11) // "QShowEvent*"

    },
    "BreakInSettingsZap\0windowClosed\0\0"
    "on_pushButtonAddRowBreakIn_clicked\0"
    "on_pushButtonDeleteRowBreakIn_clicked\0"
    "updateTable\0on_tableWidgetBreakIn_cellChanged\0"
    "row\0column\0closeEvent\0QCloseEvent*\0e\0"
    "on_pushButtonOk_clicked\0"
    "on_pushButtonCancel_clicked\0showEvent\0"
    "QShowEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BreakInSettingsZap[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    2,   63,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x0a /* Public */,
      13,    0,   72,    2, 0x0a /* Public */,
      14,    1,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   11,

       0        // eod
};

void BreakInSettingsZap::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BreakInSettingsZap *_t = static_cast<BreakInSettingsZap *>(_o);
        switch (_id) {
        case 0: _t->windowClosed(); break;
        case 1: _t->on_pushButtonAddRowBreakIn_clicked(); break;
        case 2: _t->on_pushButtonDeleteRowBreakIn_clicked(); break;
        case 3: _t->updateTable(); break;
        case 4: _t->on_tableWidgetBreakIn_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 6: _t->on_pushButtonOk_clicked(); break;
        case 7: _t->on_pushButtonCancel_clicked(); break;
        case 8: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BreakInSettingsZap::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BreakInSettingsZap::windowClosed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BreakInSettingsZap::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BreakInSettingsZap.data,
      qt_meta_data_BreakInSettingsZap,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BreakInSettingsZap::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BreakInSettingsZap::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BreakInSettingsZap.stringdata))
        return static_cast<void*>(const_cast< BreakInSettingsZap*>(this));
    return QWidget::qt_metacast(_clname);
}

int BreakInSettingsZap::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void BreakInSettingsZap::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
