/****************************************************************************
** Meta object code from reading C++ file 'blockscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "blockscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blockscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BlockScene_t {
    QByteArrayData data[13];
    char stringdata0[122];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlockScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlockScene_t qt_meta_stringdata_BlockScene = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BlockScene"
QT_MOC_LITERAL(1, 11, 12), // "itemInserted"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 10), // "BlockItem*"
QT_MOC_LITERAL(4, 36, 4), // "item"
QT_MOC_LITERAL(5, 41, 11), // "InputBlock*"
QT_MOC_LITERAL(6, 53, 12), // "OutputBlock*"
QT_MOC_LITERAL(7, 66, 7), // "setMode"
QT_MOC_LITERAL(8, 74, 4), // "Mode"
QT_MOC_LITERAL(9, 79, 4), // "mode"
QT_MOC_LITERAL(10, 84, 11), // "setItemType"
QT_MOC_LITERAL(11, 96, 20), // "BaseBlock::BlockType"
QT_MOC_LITERAL(12, 117, 4) // "type"

    },
    "BlockScene\0itemInserted\0\0BlockItem*\0"
    "item\0InputBlock*\0OutputBlock*\0setMode\0"
    "Mode\0mode\0setItemType\0BaseBlock::BlockType\0"
    "type"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlockScene[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       1,    1,   42,    2, 0x06 /* Public */,
       1,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   48,    2, 0x0a /* Public */,
      10,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    4,
    QMetaType::Void, 0x80000000 | 6,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void BlockScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlockScene *_t = static_cast<BlockScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->itemInserted((*reinterpret_cast< BlockItem*(*)>(_a[1]))); break;
        case 1: _t->itemInserted((*reinterpret_cast< InputBlock*(*)>(_a[1]))); break;
        case 2: _t->itemInserted((*reinterpret_cast< OutputBlock*(*)>(_a[1]))); break;
        case 3: _t->setMode((*reinterpret_cast< Mode(*)>(_a[1]))); break;
        case 4: _t->setItemType((*reinterpret_cast< BaseBlock::BlockType(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BlockScene::*_t)(BlockItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BlockScene::itemInserted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BlockScene::*_t)(InputBlock * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BlockScene::itemInserted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BlockScene::*_t)(OutputBlock * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BlockScene::itemInserted)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject BlockScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_BlockScene.data,
      qt_meta_data_BlockScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BlockScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlockScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BlockScene.stringdata0))
        return static_cast<void*>(const_cast< BlockScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int BlockScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
void BlockScene::itemInserted(BlockItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BlockScene::itemInserted(InputBlock * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BlockScene::itemInserted(OutputBlock * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
