/****************************************************************************
** Meta object code from reading C++ file 'InvertedBrim.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../InvertedBrim.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InvertedBrim.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InvertedBrim_t {
    QByteArrayData data[7];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InvertedBrim_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InvertedBrim_t qt_meta_stringdata_InvertedBrim = {
    {
QT_MOC_LITERAL(0, 0, 12), // "InvertedBrim"
QT_MOC_LITERAL(1, 13, 28), // "sendInvertedBrimCoordinatesf"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 13), // "InvertedBrim2"
QT_MOC_LITERAL(4, 57, 6), // "coords"
QT_MOC_LITERAL(5, 64, 18), // "btn_verify_clicked"
QT_MOC_LITERAL(6, 83, 18) // "btn_cancel_clicked"

    },
    "InvertedBrim\0sendInvertedBrimCoordinatesf\0"
    "\0InvertedBrim2\0coords\0btn_verify_clicked\0"
    "btn_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InvertedBrim[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x0a /* Public */,
       6,    0,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void InvertedBrim::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InvertedBrim *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendInvertedBrimCoordinatesf((*reinterpret_cast< const InvertedBrim2(*)>(_a[1]))); break;
        case 1: _t->btn_verify_clicked(); break;
        case 2: _t->btn_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InvertedBrim::*)(const InvertedBrim2 & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InvertedBrim::sendInvertedBrimCoordinatesf)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject InvertedBrim::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_InvertedBrim.data,
    qt_meta_data_InvertedBrim,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InvertedBrim::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InvertedBrim::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InvertedBrim.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int InvertedBrim::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void InvertedBrim::sendInvertedBrimCoordinatesf(const InvertedBrim2 & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
