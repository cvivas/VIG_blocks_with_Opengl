/****************************************************************************
** Meta object code from reading C++ file 'luces.h'
**
** Created: Mon Oct 28 14:34:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "luces.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'luces.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_luces[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    7,    6,    6, 0x05,
      32,    7,    6,    6, 0x05,
      53,    7,    6,    6, 0x05,
      77,    6,    6,    6, 0x05,
      90,   88,    6,    6, 0x05,
     109,  105,    6,    6, 0x05,
     127,  105,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     145,    6,    6,    6, 0x0a,
     155,    6,    6,    6, 0x0a,
     163,    6,    6,    6, 0x0a,
     174,    6,    6,    6, 0x0a,
     190,    6,    6,    6, 0x0a,
     202,  200,    6,    6, 0x0a,
     225,  219,    6,    6, 0x0a,
     241,  200,    6,    6, 0x0a,
     258,  200,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_luces[] = {
    "luces\0\0c\0enviarAmbientL(QColor)\0"
    "enviarDifusL(QColor)\0enviarSpecularL(QColor)\0"
    "eliminaL()\0i\0cambiaLuz(int)\0i,b\0"
    "activaL(int,bool)\0selectL(int,bool)\0"
    "ambient()\0difus()\0specular()\0"
    "borrarColores()\0borrarL()\0b\0"
    "activarLuz(bool)\0index\0cambiarLuz(int)\0"
    "actPressed(bool)\0selectedL(bool)\0"
};

void luces::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        luces *_t = static_cast<luces *>(_o);
        switch (_id) {
        case 0: _t->enviarAmbientL((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->enviarDifusL((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->enviarSpecularL((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->eliminaL(); break;
        case 4: _t->cambiaLuz((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->activaL((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->selectL((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->ambient(); break;
        case 8: _t->difus(); break;
        case 9: _t->specular(); break;
        case 10: _t->borrarColores(); break;
        case 11: _t->borrarL(); break;
        case 12: _t->activarLuz((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->cambiarLuz((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->actPressed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->selectedL((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData luces::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject luces::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_luces,
      qt_meta_data_luces, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &luces::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *luces::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *luces::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_luces))
        return static_cast<void*>(const_cast< luces*>(this));
    return QWidget::qt_metacast(_clname);
}

int luces::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void luces::enviarAmbientL(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void luces::enviarDifusL(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void luces::enviarSpecularL(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void luces::eliminaL()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void luces::cambiaLuz(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void luces::activaL(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void luces::selectL(int _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
