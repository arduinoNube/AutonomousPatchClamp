/****************************************************************************
** Meta object code from reading C++ file 'autopatchersettingswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Autopatch_5.0 - DEMO/src/ui/autopatchersettingswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autopatchersettingswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AutopatcherSettingsWindow_t {
    QByteArrayData data[10];
    char stringdata[171];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AutopatcherSettingsWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AutopatcherSettingsWindow_t qt_meta_stringdata_AutopatcherSettingsWindow = {
    {
QT_MOC_LITERAL(0, 0, 25), // "AutopatcherSettingsWindow"
QT_MOC_LITERAL(1, 26, 12), // "windowClosed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 23), // "on_pushButtonOk_clicked"
QT_MOC_LITERAL(4, 64, 27), // "on_pushButtonCancel_clicked"
QT_MOC_LITERAL(5, 92, 9), // "showEvent"
QT_MOC_LITERAL(6, 102, 11), // "QShowEvent*"
QT_MOC_LITERAL(7, 114, 1), // "e"
QT_MOC_LITERAL(8, 116, 49), // "on_lineEditNumSampsToWaitRele..."
QT_MOC_LITERAL(9, 166, 4) // "arg1"

    },
    "AutopatcherSettingsWindow\0windowClosed\0"
    "\0on_pushButtonOk_clicked\0"
    "on_pushButtonCancel_clicked\0showEvent\0"
    "QShowEvent*\0e\0"
    "on_lineEditNumSampsToWaitReleasePress_textChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AutopatcherSettingsWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void AutopatcherSettingsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AutopatcherSettingsWindow *_t = static_cast<AutopatcherSettingsWindow *>(_o);
        switch (_id) {
        case 0: _t->windowClosed(); break;
        case 1: _t->on_pushButtonOk_clicked(); break;
        case 2: _t->on_pushButtonCancel_clicked(); break;
        case 3: _t->showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 4: _t->on_lineEditNumSampsToWaitReleasePress_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AutopatcherSettingsWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AutopatcherSettingsWindow::windowClosed)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject AutopatcherSettingsWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AutopatcherSettingsWindow.data,
      qt_meta_data_AutopatcherSettingsWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AutopatcherSettingsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AutopatcherSettingsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AutopatcherSettingsWindow.stringdata))
        return static_cast<void*>(const_cast< AutopatcherSettingsWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int AutopatcherSettingsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void AutopatcherSettingsWindow::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
