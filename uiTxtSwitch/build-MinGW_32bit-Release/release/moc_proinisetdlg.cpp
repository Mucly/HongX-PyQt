/****************************************************************************
** Meta object code from reading C++ file 'proinisetdlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../proinisetdlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proinisetdlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProIniSetDlg_t {
    QByteArrayData data[8];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProIniSetDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProIniSetDlg_t qt_meta_stringdata_ProIniSetDlg = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ProIniSetDlg"
QT_MOC_LITERAL(1, 13, 20), // "on_btnSetIni_clicked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "on_btnSetUi1_clicked"
QT_MOC_LITERAL(4, 56, 20), // "on_btnSetUi2_clicked"
QT_MOC_LITERAL(5, 77, 16), // "on_btnOK_clicked"
QT_MOC_LITERAL(6, 94, 20), // "on_btnCancle_clicked"
QT_MOC_LITERAL(7, 115, 23) // "on_btnCreateQrc_clicked"

    },
    "ProIniSetDlg\0on_btnSetIni_clicked\0\0"
    "on_btnSetUi1_clicked\0on_btnSetUi2_clicked\0"
    "on_btnOK_clicked\0on_btnCancle_clicked\0"
    "on_btnCreateQrc_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProIniSetDlg[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ProIniSetDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProIniSetDlg *_t = static_cast<ProIniSetDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btnSetIni_clicked(); break;
        case 1: _t->on_btnSetUi1_clicked(); break;
        case 2: _t->on_btnSetUi2_clicked(); break;
        case 3: _t->on_btnOK_clicked(); break;
        case 4: _t->on_btnCancle_clicked(); break;
        case 5: _t->on_btnCreateQrc_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ProIniSetDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ProIniSetDlg.data,
      qt_meta_data_ProIniSetDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProIniSetDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProIniSetDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProIniSetDlg.stringdata0))
        return static_cast<void*>(const_cast< ProIniSetDlg*>(this));
    return QDialog::qt_metacast(_clname);
}

int ProIniSetDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
