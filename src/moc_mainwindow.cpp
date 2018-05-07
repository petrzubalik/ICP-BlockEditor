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
    QByteArrayData data[22];
    char stringdata0[212];
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
QT_MOC_LITERAL(5, 45, 19), // "pointerGroupClicked"
QT_MOC_LITERAL(6, 65, 7), // "compute"
QT_MOC_LITERAL(7, 73, 5), // "debug"
QT_MOC_LITERAL(8, 79, 4), // "step"
QT_MOC_LITERAL(9, 84, 4), // "stop"
QT_MOC_LITERAL(10, 89, 12), // "itemInserted"
QT_MOC_LITERAL(11, 102, 10), // "BlockItem*"
QT_MOC_LITERAL(12, 113, 4), // "item"
QT_MOC_LITERAL(13, 118, 11), // "InputBlock*"
QT_MOC_LITERAL(14, 130, 12), // "OutputBlock*"
QT_MOC_LITERAL(15, 143, 17), // "sceneScaleChanged"
QT_MOC_LITERAL(16, 161, 5), // "scale"
QT_MOC_LITERAL(17, 167, 10), // "saveScheme"
QT_MOC_LITERAL(18, 178, 9), // "file_name"
QT_MOC_LITERAL(19, 188, 4), // "save"
QT_MOC_LITERAL(20, 193, 7), // "save_as"
QT_MOC_LITERAL(21, 201, 10) // "loadScheme"

    },
    "MainWindow\0buttonGroupClicked\0\0id\0"
    "deleteItem\0pointerGroupClicked\0compute\0"
    "debug\0step\0stop\0itemInserted\0BlockItem*\0"
    "item\0InputBlock*\0OutputBlock*\0"
    "sceneScaleChanged\0scale\0saveScheme\0"
    "file_name\0save\0save_as\0loadScheme"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08 /* Private */,
       4,    0,   92,    2, 0x08 /* Private */,
       5,    1,   93,    2, 0x08 /* Private */,
       6,    1,   96,    2, 0x08 /* Private */,
       7,    1,   99,    2, 0x08 /* Private */,
       8,    1,  102,    2, 0x08 /* Private */,
       9,    1,  105,    2, 0x08 /* Private */,
      10,    1,  108,    2, 0x08 /* Private */,
      10,    1,  111,    2, 0x08 /* Private */,
      10,    1,  114,    2, 0x08 /* Private */,
      15,    1,  117,    2, 0x08 /* Private */,
      17,    1,  120,    2, 0x08 /* Private */,
      19,    0,  123,    2, 0x08 /* Private */,
      20,    0,  124,    2, 0x08 /* Private */,
      21,    0,  125,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 13,   12,
    QMetaType::Void, 0x80000000 | 14,   12,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        case 2: _t->pointerGroupClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->compute((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->debug((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->step((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->stop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->itemInserted((*reinterpret_cast< BlockItem*(*)>(_a[1]))); break;
        case 8: _t->itemInserted((*reinterpret_cast< InputBlock*(*)>(_a[1]))); break;
        case 9: _t->itemInserted((*reinterpret_cast< OutputBlock*(*)>(_a[1]))); break;
        case 10: _t->sceneScaleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->saveScheme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->save(); break;
        case 13: _t->save_as(); break;
        case 14: _t->loadScheme(); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
