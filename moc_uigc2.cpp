/****************************************************************************
** Meta object code from reading C++ file 'uigc2.h'
**
** Created: Thu Apr 26 17:27:01 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "uigc2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uigc2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UIGC2[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    7,    6,    6, 0x08,
      42,   40,    6,    6, 0x08,
      75,   73,    6,    6, 0x08,
     108,  106,    6,    6, 0x08,
     141,  139,    6,    6, 0x08,
     172,  170,    6,    6, 0x08,
     203,  201,    6,    6, 0x08,
     238,  232,    6,    6, 0x08,
     266,    6,    6,    6, 0x08,
     290,    6,    6,    6, 0x08,
     313,    6,    6,    6, 0x08,
     338,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UIGC2[] = {
    "UIGC2\0\0a\0on_aLight_valueChanged(double)\0"
    "b\0on_bLight_valueChanged(double)\0g\0"
    "on_gLight_valueChanged(double)\0r\0"
    "on_rLight_valueChanged(double)\0z\0"
    "on_zPos_valueChanged(double)\0y\0"
    "on_yPos_valueChanged(double)\0x\0"
    "on_xPos_valueChanged(double)\0index\0"
    "on_lightList_activated(int)\0"
    "on_paintLight_clicked()\0on_moveLight_clicked()\0"
    "on_deleteLight_clicked()\0on_addLight_clicked()\0"
};

void UIGC2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UIGC2 *_t = static_cast<UIGC2 *>(_o);
        switch (_id) {
        case 0: _t->on_aLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->on_bLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_gLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->on_rLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_zPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_yPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_xPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_lightList_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_paintLight_clicked(); break;
        case 9: _t->on_moveLight_clicked(); break;
        case 10: _t->on_deleteLight_clicked(); break;
        case 11: _t->on_addLight_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UIGC2::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UIGC2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UIGC2,
      qt_meta_data_UIGC2, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UIGC2::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UIGC2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UIGC2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UIGC2))
        return static_cast<void*>(const_cast< UIGC2*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UIGC2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
