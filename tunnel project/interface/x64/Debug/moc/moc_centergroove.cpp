/****************************************************************************
** Meta object code from reading C++ file 'CenterGroove.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CenterGroove.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CenterGroove.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CenterGroove_t {
    QByteArrayData data[8];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CenterGroove_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CenterGroove_t qt_meta_stringdata_CenterGroove = {
    {
QT_MOC_LITERAL(0, 0, 12), // "CenterGroove"
QT_MOC_LITERAL(1, 13, 21), // "par_view_CenterGroove"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 27), // "sendCenterGrooveCoordinates"
QT_MOC_LITERAL(4, 64, 23), // "CenterGrooveCoordinates"
QT_MOC_LITERAL(5, 88, 6), // "coords"
QT_MOC_LITERAL(6, 95, 18), // "btn_verify_clicked"
QT_MOC_LITERAL(7, 114, 18) // "btn_cancel_clicked"

    },
    "CenterGroove\0par_view_CenterGroove\0\0"
    "sendCenterGrooveCoordinates\0"
    "CenterGrooveCoordinates\0coords\0"
    "btn_verify_clicked\0btn_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CenterGroove[] = {

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

void CenterGroove::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CenterGroove *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->par_view_CenterGroove(); break;
        case 1: _t->sendCenterGrooveCoordinates((*reinterpret_cast< const CenterGrooveCoordinates(*)>(_a[1]))); break;
        case 2: _t->btn_verify_clicked(); break;
        case 3: _t->btn_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CenterGroove::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CenterGroove::par_view_CenterGroove)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CenterGroove::*)(const CenterGrooveCoordinates & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CenterGroove::sendCenterGrooveCoordinates)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CenterGroove::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CenterGroove.data,
    qt_meta_data_CenterGroove,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CenterGroove::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CenterGroove::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CenterGroove.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CenterGroove::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CenterGroove::par_view_CenterGroove()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CenterGroove::sendCenterGrooveCoordinates(const CenterGrooveCoordinates & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
