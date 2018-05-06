/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "buttonGroupClicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 2), // "id"
QT_MOC_LITERAL(4, 34, 10), // "deleteItem"
QT_MOC_LITERAL(5, 45, 10), // "saveScheme"
QT_MOC_LITERAL(6, 56, 19), // "pointerGroupClicked"
QT_MOC_LITERAL(7, 76, 7), // "compute"
QT_MOC_LITERAL(8, 84, 5), // "debug"
QT_MOC_LITERAL(9, 90, 4), // "step"
QT_MOC_LITERAL(10, 95, 4), // "stop"
QT_MOC_LITERAL(11, 100, 12), // "itemInserted"
QT_MOC_LITERAL(12, 113, 10), // "BlockItem*"
QT_MOC_LITERAL(13, 124, 4), // "item"
QT_MOC_LITERAL(14, 129, 11), // "InputBlock*"
QT_MOC_LITERAL(15, 141, 12), // "OutputBlock*"
QT_MOC_LITERAL(16, 154, 17), // "sceneScaleChanged"
QT_MOC_LITERAL(17, 172, 5) // "scale"

    },
    "MainWindow\0buttonGroupClicked\0\0id\0"
    "deleteItem\0saveScheme\0pointerGroupClicked\0"
    "compute\0debug\0step\0stop\0itemInserted\0"
    "BlockItem*\0item\0InputBlock*\0OutputBlock*\0"
    "sceneScaleChanged\0scale"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    0,   77,    2, 0x08 /* Private */,
       5,    0,   78,    2, 0x08 /* Private */,
       6,    1,   79,    2, 0x08 /* Private */,
       7,    1,   82,    2, 0x08 /* Private */,
       8,    1,   85,    2, 0x08 /* Private */,
       9,    1,   88,    2, 0x08 /* Private */,
      10,    1,   91,    2, 0x08 /* Private */,
      11,    1,   94,    2, 0x08 /* Private */,
      11,    1,   97,    2, 0x08 /* Private */,
      11,    1,  100,    2, 0x08 /* Private */,
      16,    1,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 14,   13,
    QMetaType::Void, 0x80000000 | 15,   13,
    QMetaType::Void, QMetaType::QString,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->buttonGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->deleteItem(); break;
        case 2: _t->saveScheme(); break;
        case 3: _t->pointerGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->compute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->debug((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->step((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->stop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->itemInserted((*reinterpret_cast< BlockItem*(*)>(_a[1]))); break;
        case 9: _t->itemInserted((*reinterpret_cast< InputBlock*(*)>(_a[1]))); break;
        case 10: _t->itemInserted((*reinterpret_cast< OutputBlock*(*)>(_a[1]))); break;
        case 11: _t->sceneScaleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
