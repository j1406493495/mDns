/****************************************************************************
** Meta object code from reading C++ file 'DeviceTab.h'
**
** Created: Sun Oct 23 16:36:17 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/DeviceTab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeviceTab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeviceTab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      23,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DeviceTab[] = {
    "DeviceTab\0\0clearList()\0refresh(DEVICE_INFO)\0"
};

void DeviceTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DeviceTab *_t = static_cast<DeviceTab *>(_o);
        switch (_id) {
        case 0: _t->clearList(); break;
        case 1: _t->refresh((*reinterpret_cast< DEVICE_INFO(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DeviceTab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DeviceTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DeviceTab,
      qt_meta_data_DeviceTab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeviceTab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeviceTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeviceTab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceTab))
        return static_cast<void*>(const_cast< DeviceTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int DeviceTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
