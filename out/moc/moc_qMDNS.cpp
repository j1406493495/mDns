/****************************************************************************
** Meta object code from reading C++ file 'qMDNS.h'
**
** Created: Sun Oct 23 16:36:18 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/qMDNS.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qMDNS.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_qMDNS[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   34,    6,    6, 0x0a,
      54,    6,    6,    6, 0x0a,
      67,    6,   63,    6, 0x0a,
      83,    6,    6,    6, 0x08,
     102,   97,    6,    6, 0x08,
     129,  126,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_qMDNS[] = {
    "qMDNS\0\0refreshSignal(DEVICE_INFO)\0ttl\0"
    "setTTL(quint32)\0lookup()\0int\0"
    "selectNetCard()\0onReadyRead()\0data\0"
    "sendPacket(QByteArray&)\0,,\0"
    "saveDeviceInfo(uint8_t[],QHostAddress,int)\0"
};

void qMDNS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        qMDNS *_t = static_cast<qMDNS *>(_o);
        switch (_id) {
        case 0: _t->refreshSignal((*reinterpret_cast< DEVICE_INFO(*)>(_a[1]))); break;
        case 1: _t->setTTL((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 2: _t->lookup(); break;
        case 3: { int _r = _t->selectNetCard();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 4: _t->onReadyRead(); break;
        case 5: _t->sendPacket((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->saveDeviceInfo((*reinterpret_cast< uint8_t(*)[]>(_a[1])),(*reinterpret_cast< QHostAddress(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData qMDNS::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject qMDNS::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_qMDNS,
      qt_meta_data_qMDNS, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &qMDNS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *qMDNS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *qMDNS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_qMDNS))
        return static_cast<void*>(const_cast< qMDNS*>(this));
    return QObject::qt_metacast(_clname);
}

int qMDNS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void qMDNS::refreshSignal(DEVICE_INFO _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
