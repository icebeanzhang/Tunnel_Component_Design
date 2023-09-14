/****************************************************************************
** Meta object code from reading C++ file 'dia2_2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../dia2_2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dia2_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dia2_2_t {
    QByteArrayData data[8];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dia2_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dia2_2_t qt_meta_stringdata_dia2_2 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "dia2_2"
QT_MOC_LITERAL(1, 7, 19), // "par_view_sidegroove"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 25), // "sendsidegrooveCoordinates"
QT_MOC_LITERAL(4, 54, 21), // "sidegrooveCoordinates"
QT_MOC_LITERAL(5, 76, 6), // "coords"
QT_MOC_LITERAL(6, 83, 18), // "btn_verify_clicked"
QT_MOC_LITERAL(7, 102, 18) // "btn_cancel_clicked"

    },
    "dia2_2\0par_view_sidegroove\0\0"
    "sendsidegrooveCoordinates\0"
    "sidegrooveCoordinates\0coords\0"
    "btn_verify_clicked\0btn_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dia2_2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dia2_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dia2_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->par_view_sidegroove(); break;
        case 1: _t->sendsidegrooveCoordinates((*reinterpret_cast< const sidegrooveCoordinates(*)>(_a[1]))); break;
        case 2: _t->btn_verify_clicked(); break;
        case 3: _t->btn_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dia2_2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dia2_2::par_view_sidegroove)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dia2_2::*)(const sidegrooveCoordinates & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dia2_2::sendsidegrooveCoordinates)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dia2_2::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_dia2_2.data,
    qt_meta_data_dia2_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dia2_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dia2_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dia2_2.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dia2_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void dia2_2::par_view_sidegroove()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void dia2_2::sendsidegrooveCoordinates(const sidegrooveCoordinates & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
