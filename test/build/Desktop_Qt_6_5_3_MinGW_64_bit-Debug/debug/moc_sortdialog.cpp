/****************************************************************************
** Meta object code from reading C++ file 'sortdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../sortdialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sortdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSortDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSortDialogENDCLASS = QtMocHelpers::stringData(
    "SortDialog",
    "sortByFinalScoreAsc",
    "",
    "sortByFinalScoreDesc",
    "sortByActualCreditAsc",
    "sortByActualCreditDesc"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSortDialogENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[11];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[22];
    char stringdata5[23];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSortDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSortDialogENDCLASS_t qt_meta_stringdata_CLASSSortDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "SortDialog"
        QT_MOC_LITERAL(11, 19),  // "sortByFinalScoreAsc"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 20),  // "sortByFinalScoreDesc"
        QT_MOC_LITERAL(53, 21),  // "sortByActualCreditAsc"
        QT_MOC_LITERAL(75, 22)   // "sortByActualCreditDesc"
    },
    "SortDialog",
    "sortByFinalScoreAsc",
    "",
    "sortByFinalScoreDesc",
    "sortByActualCreditAsc",
    "sortByActualCreditDesc"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSortDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    0,   40,    2, 0x08,    3 /* Private */,
       5,    0,   41,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SortDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSSortDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSortDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSortDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SortDialog, std::true_type>,
        // method 'sortByFinalScoreAsc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortByFinalScoreDesc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortByActualCreditAsc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sortByActualCreditDesc'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SortDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SortDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sortByFinalScoreAsc(); break;
        case 1: _t->sortByFinalScoreDesc(); break;
        case 2: _t->sortByActualCreditAsc(); break;
        case 3: _t->sortByActualCreditDesc(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *SortDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SortDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSortDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SortDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
