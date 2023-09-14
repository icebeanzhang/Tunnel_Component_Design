/****************************************************************************
** Meta object code from reading C++ file 'dia4_1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dia4_1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dia4_1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dia4_1_t {
    QByteArrayData data[8];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dia4_1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dia4_1_t qt_meta_stringdata_dia4_1 = {
    {
QT_MOC_LITERAL(0, 0, 6), // "dia4_1"
QT_MOC_LITERAL(1, 7, 9), // "par_view1"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 22), // "sendSquareCoordinatesf"
QT_MOC_LITERAL(4, 41, 18), // "SquareCoordinates2"
QT_MOC_LITERAL(5, 60, 6), // "coords"
QT_MOC_LITERAL(6, 67, 18), // "btn_verify_clicked"
QT_MOC_LITERAL(7, 86, 18) // "btn_cancel_clicked"

    },
    "dia4_1\0par_view1\0\0sendSquareCoordinatesf\0"
    "SquareCoordinates2\0coords\0btn_verify_clicked\0"
    "btn_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dia4_1[] = {

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

void dia4_1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dia4_1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->par_view1(); break;
        case 1: _t->sendSquareCoordinatesf((*reinterpret_cast< const SquareCoordinates2(*)>(_a[1]))); break;
        case 2: _t->btn_verify_clicked(); break;
        case 3: _t->btn_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dia4_1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dia4_1::par_view1)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dia4_1::*)(const SquareCoordinates2 & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dia4_1::sendSquareCoordinatesf)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dia4_1::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_dia4_1.data,
    qt_meta_data_dia4_1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dia4_1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dia4_1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dia4_1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dia4_1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void dia4_1::par_view1()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void dia4_1::sendSquareCoordinatesf(const SquareCoordinates2 & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
