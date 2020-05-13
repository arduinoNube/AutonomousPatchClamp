/****************************************************************************
** Meta object code from reading C++ file 'breakinsettingsramp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/ui/breakinsettingsramp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'breakinsettingsramp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BreakInSettingsRamp_t {
    QByteArrayData data[18];
    char stringdata[291];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BreakInSettingsRamp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BreakInSettingsRamp_t qt_meta_stringdata_BreakInSettingsRamp = {
    {
QT_MOC_LITERAL(0, 0, 19), // "BreakInSettingsRamp"
QT_MOC_LITERAL(1, 20, 12), // "windowClosed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 34), // "on_pushButtonAddRowBreakIn_cl..."
QT_MOC_LITERAL(4, 69, 37), // "on_pushButtonDeleteRowBreakIn..."
QT_MOC_LITERAL(5, 107, 11), // "updateTable"
QT_MOC_LITERAL(6, 119, 33), // "on_tableWidgetBreakIn_cellCha..."
QT_MOC_LITERAL(7, 153, 3), // "row"
QT_MOC_LITERAL(8, 157, 6), // "column"
QT_MOC_LITERAL(9, 164, 15), // "keyReleaseEvent"
QT_MOC_LITERAL(10, 180, 10), // "QKeyEvent*"
QT_MOC_LITERAL(11, 191, 1), // "e"
QT_MOC_LITERAL(12, 193, 10), // "closeEvent"
QT_MOC_LITERAL(13, 204, 12), // "QCloseEvent*"
QT_MOC_LITERAL(14, 217, 23), // "on_pushButtonOk_clicked"
QT_MOC_LITERAL(15, 241, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(16, 269, 9), // "showEvent"
QT_MOC_LITERAL(17, 279, 11) // "QShowEvent*"

    },
    "BreakInSettingsRamp\0windowClosed\0\0"
    "on_pushButtonAddRowBreakIn_clicked\0"
    "on_pushButtonDeleteRowBreakIn_clicked\0"
    "updateTable\0on_tableWidgetBreakIn_cellChanged\0"
    "row\0column\0keyReleaseEvent\0QKeyEvent*\0"
    "e\0closeEvent\0QCloseEvent*\0"
    "on_pushButtonOk_clicked\0"
    "on_pushButtonCancel_clicked\0showEvent\0"
    "QShowEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BreakInSettingsRamp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    2,   68,    2, 0x0a /* Public */,
       9,    1,   73,    2, 0x0a /* Public */,
      12,    1,   76,    2, 0x0a /* Public */,
      14,    0,   79,    2, 0x0a /* Public */,
      15,    0,   80,    2, 0x0a /* Public */,
      16,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,   11,

       0        // eod
};

void BreakInSettingsRamp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BreakInSettingsRamp *_t = static_cast<BreakInSettingsRamp *>(_o);
        switch (_id) {
        case 0: _t->windowClosed(); break;
        case 1: _t->on_pushButtonAddRowBreakIn_clicked(); break;
        case 2: _t->on_pushButtonDeleteRowBreakIn_clicked(); break;
        case 3: _t->updateTable(); break;
        case 4: _t->on_tableWidgetBreakIn_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonOk_clicked(); break;
        case 8: _t->on_pushButtonCancel_clicked(); break;
        case 9: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BreakInSettingsRamp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BreakInSettingsRamp::windowClosed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject BreakInSettingsRamp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BreakInSettingsRamp.data,
      qt_meta_data_BreakInSettingsRamp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BreakInSettingsRamp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BreakInSettingsRamp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BreakInSettingsRamp.stringdata))
        return static_cast<void*>(const_cast< BreakInSettingsRamp*>(this));
    return QWidget::qt_metacast(_clname);
}

int BreakInSettingsRamp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void BreakInSettingsRamp::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
