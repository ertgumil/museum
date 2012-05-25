/****************************************************************************
** Meta object code from reading C++ file 'uigc2.h'
**
** Created: Fri May 25 18:10:00 2012
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
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      36,    6,    6,    6, 0x08,
      65,    6,    6,    6, 0x08,
      98,   92,    6,    6, 0x08,
     134,   92,    6,    6, 0x08,
     166,    6,    6,    6, 0x08,
     198,    6,    6,    6, 0x08,
     231,    6,    6,    6, 0x08,
     268,  266,    6,    6, 0x08,
     301,  299,    6,    6, 0x08,
     334,  332,    6,    6, 0x08,
     367,  365,    6,    6, 0x08,
     400,  398,    6,    6, 0x08,
     431,  429,    6,    6, 0x08,
     462,  460,    6,    6, 0x08,
     497,  491,    6,    6, 0x08,
     525,    6,    6,    6, 0x08,
     549,    6,    6,    6, 0x08,
     572,    6,    6,    6, 0x08,
     597,    6,    6,    6, 0x08,
     624,  619,    6,    6, 0x08,
     673,  619,    6,    6, 0x08,
     714,    6,    6,    6, 0x08,
     744,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UIGC2[] = {
    "UIGC2\0\0on_controlsButton_released()\0"
    "on_visitantButton_released()\0"
    "on_editorButton_released()\0value\0"
    "on_rotationSlider_valueChanged(int)\0"
    "on_sizeSlider_valueChanged(int)\0"
    "on_deleteObjectButton_clicked()\0"
    "on_nameEdit_textChanged(QString)\0"
    "on_createNewObjectButton_clicked()\0a\0"
    "on_aLight_valueChanged(double)\0b\0"
    "on_bLight_valueChanged(double)\0g\0"
    "on_gLight_valueChanged(double)\0r\0"
    "on_rLight_valueChanged(double)\0z\0"
    "on_zPos_valueChanged(double)\0y\0"
    "on_yPos_valueChanged(double)\0x\0"
    "on_xPos_valueChanged(double)\0index\0"
    "on_lightList_activated(int)\0"
    "on_paintLight_clicked()\0on_moveLight_clicked()\0"
    "on_deleteLight_clicked()\0on_addLight_clicked()\0"
    "arg1\0on_comboBoxObjectes_currentIndexChanged(QString)\0"
    "on_comboBoxObjectes_highlighted(QString)\0"
    "on_loadMuseumButton_clicked()\0"
    "on_saveMuseumButton_clicked()\0"
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
        case 0: on_controlsButton_released(); break;
        case 1: on_visitantButton_released(); break;
        case 2: on_editorButton_released(); break;
        case 3: on_rotationSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: on_sizeSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: on_deleteObjectButton_clicked(); break;
        case 6: on_nameEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: on_createNewObjectButton_clicked(); break;
        case 8: on_aLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: on_bLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: on_gLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: on_rLight_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: on_zPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: on_yPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 14: on_xPos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: on_lightList_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: on_paintLight_clicked(); break;
        case 17: on_moveLight_clicked(); break;
        case 18: on_deleteLight_clicked(); break;
        case 19: on_addLight_clicked(); break;
        case 20: on_comboBoxObjectes_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: on_comboBoxObjectes_highlighted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: on_loadMuseumButton_clicked(); break;
        case 23: on_saveMuseumButton_clicked(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
