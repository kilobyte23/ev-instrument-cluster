/****************************************************************************
** Meta object code from reading C++ file 'bmsinterface.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/bmsinterface.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bmsinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN12BMSInterfaceE_t {};
} // unnamed namespace

template <> constexpr inline auto BMSInterface::qt_create_metaobjectdata<qt_meta_tag_ZN12BMSInterfaceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BMSInterface",
        "bmsDataChanged",
        "",
        "criticalFault",
        "code",
        "updateFromCAN",
        "payload",
        "cellVoltageMin",
        "cellVoltageMax",
        "packVoltage",
        "packCurrent",
        "stateOfHealth"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'bmsDataChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'criticalFault'
        QtMocHelpers::SignalData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'updateFromCAN'
        QtMocHelpers::SlotData<void(const QByteArray &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QByteArray, 6 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'cellVoltageMin'
        QtMocHelpers::PropertyData<float>(7, QMetaType::Float, QMC::DefaultPropertyFlags, 0),
        // property 'cellVoltageMax'
        QtMocHelpers::PropertyData<float>(8, QMetaType::Float, QMC::DefaultPropertyFlags, 0),
        // property 'packVoltage'
        QtMocHelpers::PropertyData<float>(9, QMetaType::Float, QMC::DefaultPropertyFlags, 0),
        // property 'packCurrent'
        QtMocHelpers::PropertyData<float>(10, QMetaType::Float, QMC::DefaultPropertyFlags, 0),
        // property 'stateOfHealth'
        QtMocHelpers::PropertyData<float>(11, QMetaType::Float, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BMSInterface, qt_meta_tag_ZN12BMSInterfaceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject BMSInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12BMSInterfaceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12BMSInterfaceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN12BMSInterfaceE_t>.metaTypes,
    nullptr
} };

void BMSInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BMSInterface *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->bmsDataChanged(); break;
        case 1: _t->criticalFault((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->updateFromCAN((*reinterpret_cast<std::add_pointer_t<QByteArray>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BMSInterface::*)()>(_a, &BMSInterface::bmsDataChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BMSInterface::*)(const QString & )>(_a, &BMSInterface::criticalFault, 1))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<float*>(_v) = _t->cellVoltageMin(); break;
        case 1: *reinterpret_cast<float*>(_v) = _t->cellVoltageMax(); break;
        case 2: *reinterpret_cast<float*>(_v) = _t->packVoltage(); break;
        case 3: *reinterpret_cast<float*>(_v) = _t->packCurrent(); break;
        case 4: *reinterpret_cast<float*>(_v) = _t->stateOfHealth(); break;
        default: break;
        }
    }
}

const QMetaObject *BMSInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BMSInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN12BMSInterfaceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BMSInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void BMSInterface::bmsDataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BMSInterface::criticalFault(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
