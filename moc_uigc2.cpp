/****************************************************************************
** Meta object code from reading C++ file 'uigc2.h'
**
** Created: Thu Apr 5 13:33:31 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "uigc2.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uigc2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UIGC2[] = {

 // content:
       4,       // revision
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

const QMetaObject UIGC2::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UIGC2,
      qt_meta_data_UIGC2, 0 }
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
        switch (_id) {
        case 0: on_aLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: on_bLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: on_gLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: on_rLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: on_zPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: on_yPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: on_xPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: on_lightList_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_paintLight_clicked(); break;
        case 9: on_moveLight_clicked(); break;
        case 10: on_deleteLight_clicked(); break;
        case 11: on_addLight_clicked(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
