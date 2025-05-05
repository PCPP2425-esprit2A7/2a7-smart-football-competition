/****************************************************************************
** Meta object code from reading C++ file 'mainwindow_joueur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow_joueur.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow_joueur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
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
struct qt_meta_stringdata_CLASSMainWindowJoueurENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowJoueurENDCLASS = QtMocHelpers::stringData(
    "MainWindowJoueur",
    "on_add_clicked",
    "",
    "on_supprimer_clicked",
    "on_modify_clicked",
    "on_cancel_clicked",
    "afficher",
    "on_tableView_clicked",
    "QModelIndex",
    "index",
    "validateInput",
    "on_pdfButton_clicked",
    "onSearch",
    "on_tri_changed",
    "on_stat_clicked",
    "on_dark_clicked",
    "on_light_clicked",
    "RechercheVocale",
    "demarrerReconnaissanceVocale",
    "rechercherJoueurParNom",
    "name",
    "onTeam2ButtonPressed",
    "onTeam1ButtonPressed",
    "readSerial",
    "update_label",
    "on_btn_supp_clicked",
    "on_btn_arb_clicked",
    "on_btn_tickets_clicked",
    "on_btn_match_clicked",
    "on_home_clicked",
    "on_btn_team_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowJoueurENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  170,    2, 0x08,    1 /* Private */,
       3,    0,  171,    2, 0x08,    2 /* Private */,
       4,    0,  172,    2, 0x08,    3 /* Private */,
       5,    0,  173,    2, 0x08,    4 /* Private */,
       6,    0,  174,    2, 0x08,    5 /* Private */,
       7,    1,  175,    2, 0x08,    6 /* Private */,
      10,    0,  178,    2, 0x08,    8 /* Private */,
      11,    0,  179,    2, 0x08,    9 /* Private */,
      12,    0,  180,    2, 0x08,   10 /* Private */,
      13,    1,  181,    2, 0x08,   11 /* Private */,
      14,    0,  184,    2, 0x08,   13 /* Private */,
      15,    0,  185,    2, 0x08,   14 /* Private */,
      16,    0,  186,    2, 0x08,   15 /* Private */,
      17,    0,  187,    2, 0x08,   16 /* Private */,
      18,    0,  188,    2, 0x08,   17 /* Private */,
      19,    1,  189,    2, 0x08,   18 /* Private */,
      21,    0,  192,    2, 0x08,   20 /* Private */,
      22,    0,  193,    2, 0x08,   21 /* Private */,
      23,    0,  194,    2, 0x08,   22 /* Private */,
      24,    0,  195,    2, 0x08,   23 /* Private */,
      25,    0,  196,    2, 0x08,   24 /* Private */,
      26,    0,  197,    2, 0x08,   25 /* Private */,
      27,    0,  198,    2, 0x08,   26 /* Private */,
      28,    0,  199,    2, 0x08,   27 /* Private */,
      29,    0,  200,    2, 0x08,   28 /* Private */,
      30,    0,  201,    2, 0x08,   29 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindowJoueur::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowJoueurENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowJoueurENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowJoueurENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindowJoueur, std::true_type>,
        // method 'on_add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_modify_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficher'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'validateInput'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pdfButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tri_changed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_stat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_dark_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_light_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RechercheVocale'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'demarrerReconnaissanceVocale'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'rechercherJoueurParNom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'onTeam2ButtonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTeam1ButtonPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readSerial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_label'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_supp_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_arb_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_tickets_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_match_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_home_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_team_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindowJoueur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindowJoueur *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_add_clicked(); break;
        case 1: _t->on_supprimer_clicked(); break;
        case 2: _t->on_modify_clicked(); break;
        case 3: _t->on_cancel_clicked(); break;
        case 4: _t->afficher(); break;
        case 5: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 6: { bool _r = _t->validateInput();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->on_pdfButton_clicked(); break;
        case 8: _t->onSearch(); break;
        case 9: _t->on_tri_changed((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_stat_clicked(); break;
        case 11: _t->on_dark_clicked(); break;
        case 12: _t->on_light_clicked(); break;
        case 13: _t->RechercheVocale(); break;
        case 14: { QString _r = _t->demarrerReconnaissanceVocale();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 15: _t->rechercherJoueurParNom((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->onTeam2ButtonPressed(); break;
        case 17: _t->onTeam1ButtonPressed(); break;
        case 18: _t->readSerial(); break;
        case 19: _t->update_label(); break;
        case 20: _t->on_btn_supp_clicked(); break;
        case 21: _t->on_btn_arb_clicked(); break;
        case 22: _t->on_btn_tickets_clicked(); break;
        case 23: _t->on_btn_match_clicked(); break;
        case 24: _t->on_home_clicked(); break;
        case 25: _t->on_btn_team_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindowJoueur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindowJoueur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowJoueurENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindowJoueur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 26;
    }
    return _id;
}
QT_WARNING_POP
