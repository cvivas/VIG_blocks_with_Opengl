/****************************************************************************
** Meta object code from reading C++ file 'materials.h'
**
** Created: Mon Oct 28 14:33:59 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "materials.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'materials.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_materials[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x05,
      35,   11,   10,   10, 0x05,
      55,   11,   10,   10, 0x05,
      81,   78,   10,   10, 0x05,
      95,   10,   10,   10, 0x05,
     106,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     116,   10,   10,   10, 0x0a,
     126,   10,   10,   10, 0x0a,
     134,   10,   10,   10, 0x0a,
     145,   78,   10,   10, 0x0a,
     156,   10,   10,   10, 0x0a,
     165,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_materials[] = {
    "materials\0\0c\0enviarAmbient(QColor)\0"
    "enviarDifus(QColor)\0enviarSpecular(QColor)\0"
    "sh\0enviarSH(int)\0validarM()\0borrarC()\0"
    "ambient()\0difus()\0specular()\0shine(int)\0"
    "valida()\0borrarColores()\0"
};

void materials::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        materials *_t = static_cast<materials *>(_o);
        switch (_id) {
        case 0: _t->enviarAmbient((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 1: _t->enviarDifus((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->enviarSpecular((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 3: _t->enviarSH((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->validarM(); break;
        case 5: _t->borrarC(); break;
        case 6: _t->ambient(); break;
        case 7: _t->difus(); break;
        case 8: _t->specular(); break;
        case 9: _t->shine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->valida(); break;
        case 11: _t->borrarColores(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData materials::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject materials::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_materials,
      qt_meta_data_materials, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &materials::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *materials::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *materials::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_materials))
        return static_cast<void*>(const_cast< materials*>(this));
    return QWidget::qt_metacast(_clname);
}

int materials::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void materials::enviarAmbient(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void materials::enviarDifus(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void materials::enviarSpecular(QColor _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void materials::enviarSH(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void materials::validarM()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void materials::borrarC()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
