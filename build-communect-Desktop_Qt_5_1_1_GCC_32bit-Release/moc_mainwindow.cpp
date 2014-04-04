/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../communect/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[38];
    char stringdata[589];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 13),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 17),
QT_MOC_LITERAL(4, 44, 16),
QT_MOC_LITERAL(5, 61, 10),
QT_MOC_LITERAL(6, 72, 6),
QT_MOC_LITERAL(7, 79, 9),
QT_MOC_LITERAL(8, 89, 10),
QT_MOC_LITERAL(9, 100, 12),
QT_MOC_LITERAL(10, 113, 16),
QT_MOC_LITERAL(11, 130, 16),
QT_MOC_LITERAL(12, 147, 10),
QT_MOC_LITERAL(13, 158, 20),
QT_MOC_LITERAL(14, 179, 17),
QT_MOC_LITERAL(15, 197, 13),
QT_MOC_LITERAL(16, 211, 10),
QT_MOC_LITERAL(17, 222, 12),
QT_MOC_LITERAL(18, 235, 19),
QT_MOC_LITERAL(19, 255, 22),
QT_MOC_LITERAL(20, 278, 20),
QT_MOC_LITERAL(21, 299, 17),
QT_MOC_LITERAL(22, 317, 18),
QT_MOC_LITERAL(23, 336, 16),
QT_MOC_LITERAL(24, 353, 13),
QT_MOC_LITERAL(25, 367, 17),
QT_MOC_LITERAL(26, 385, 10),
QT_MOC_LITERAL(27, 396, 10),
QT_MOC_LITERAL(28, 407, 8),
QT_MOC_LITERAL(29, 416, 13),
QT_MOC_LITERAL(30, 430, 14),
QT_MOC_LITERAL(31, 445, 17),
QT_MOC_LITERAL(32, 463, 13),
QT_MOC_LITERAL(33, 477, 13),
QT_MOC_LITERAL(34, 491, 13),
QT_MOC_LITERAL(35, 505, 22),
QT_MOC_LITERAL(36, 528, 29),
QT_MOC_LITERAL(37, 558, 29)
    },
    "MainWindow\0connect_to_db\0\0connect_to_TMSIdb\0"
    "authenticateUser\0logincheck\0string\0"
    "passcheck\0sha256hash\0resetcounter\0"
    "deleteactiveuser\0insertactiveuser\0"
    "addHistory\0insertnewuseropenbts\0"
    "updateuseropenbts\0getinsertedon\0"
    "userexists\0pseudoupdate\0updateuser_database\0"
    "updateshortcode_actual\0deleteuserpermission\0"
    "adduserpermission\0getshortcodeofuser\0"
    "getnumberofusers\0getStringDate\0"
    "getpasswordofuser\0hasadduser\0hasmodpriv\0"
    "hasrates\0hasshortcodes\0hashistorylogs\0"
    "hasconfigsettings\0hasmodifyuser\0"
    "hassendalerts\0hassurvrecord\0"
    "on_loginbutton_clicked\0"
    "on_passwordline_returnPressed\0"
    "on_usernameline_returnPressed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  189,    2, 0x0a,
       3,    0,  190,    2, 0x0a,
       4,    2,  191,    2, 0x0a,
       5,    1,  196,    2, 0x0a,
       7,    1,  199,    2, 0x0a,
       8,    1,  202,    2, 0x0a,
       9,    1,  205,    2, 0x0a,
      10,    0,  208,    2, 0x0a,
      11,    2,  209,    2, 0x0a,
      12,    1,  214,    2, 0x0a,
      13,    2,  217,    2, 0x0a,
      14,    3,  222,    2, 0x0a,
      15,    1,  229,    2, 0x0a,
      16,    1,  232,    2, 0x0a,
      17,    1,  235,    2, 0x0a,
      18,   15,  238,    2, 0x0a,
      19,    2,  269,    2, 0x0a,
      20,    2,  274,    2, 0x0a,
      21,    2,  279,    2, 0x0a,
      22,    1,  284,    2, 0x0a,
      23,    0,  287,    2, 0x0a,
      24,    1,  288,    2, 0x0a,
      25,    1,  291,    2, 0x0a,
      26,    1,  294,    2, 0x0a,
      27,    1,  297,    2, 0x0a,
      28,    1,  300,    2, 0x0a,
      29,    1,  303,    2, 0x0a,
      30,    1,  306,    2, 0x0a,
      31,    1,  309,    2, 0x0a,
      32,    1,  312,    2, 0x0a,
      33,    1,  315,    2, 0x0a,
      34,    1,  318,    2, 0x0a,
      35,    0,  321,    2, 0x08,
      36,    0,  322,    2, 0x08,
      37,    0,  323,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString, QMetaType::QString,    2,    2,
    QMetaType::Bool, 0x80000000 | 6,    2,
    0x80000000 | 6, 0x80000000 | 6,    2,
    0x80000000 | 6, 0x80000000 | 6,    2,
    QMetaType::Int, 0x80000000 | 6,    2,
    QMetaType::Int,
    QMetaType::Int, QMetaType::Int, 0x80000000 | 6,    2,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Int, 0x80000000 | 6, 0x80000000 | 6,    2,    2,
    QMetaType::Int, 0x80000000 | 6, 0x80000000 | 6, QMetaType::Bool,    2,    2,    2,
    0x80000000 | 6, 0x80000000 | 6,    2,
    QMetaType::Bool, 0x80000000 | 6,    2,
    QMetaType::Int, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Int, 0x80000000 | 6, 0x80000000 | 6,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    0x80000000 | 6, QMetaType::QString,    2,
    QMetaType::Int,
    0x80000000 | 6, 0x80000000 | 6,    2,
    0x80000000 | 6, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Bool, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->connect_to_db(); break;
        case 1: _t->connect_to_TMSIdb(); break;
        case 2: { int _r = _t->authenticateUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->logincheck((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { string _r = _t->passcheck((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        case 5: { string _r = _t->sha256hash((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        case 6: { int _r = _t->resetcounter((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = _t->deleteactiveuser();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = _t->insertactiveuser((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 9: _t->addHistory((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 10: { int _r = _t->insertnewuseropenbts((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->updateuseropenbts((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: { string _r = _t->getinsertedon((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        case 13: { bool _r = _t->userexists((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { int _r = _t->pseudoupdate((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 15: { bool _r = _t->updateuser_database((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9])),(*reinterpret_cast< bool(*)>(_a[10])),(*reinterpret_cast< bool(*)>(_a[11])),(*reinterpret_cast< bool(*)>(_a[12])),(*reinterpret_cast< bool(*)>(_a[13])),(*reinterpret_cast< QString(*)>(_a[14])),(*reinterpret_cast< QString(*)>(_a[15])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { int _r = _t->updateshortcode_actual((*reinterpret_cast< string(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 17: _t->deleteuserpermission((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 18: _t->adduserpermission((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 19: { string _r = _t->getshortcodeofuser((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        case 20: { int _r = _t->getnumberofusers();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 21: { string _r = _t->getStringDate((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        case 22: { string _r = _t->getpasswordofuser((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = _r; }  break;
        case 23: { bool _r = _t->hasadduser((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 24: { bool _r = _t->hasmodpriv((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 25: { bool _r = _t->hasrates((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 26: { bool _r = _t->hasshortcodes((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 27: { bool _r = _t->hashistorylogs((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 28: { bool _r = _t->hasconfigsettings((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 29: { bool _r = _t->hasmodifyuser((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 30: { bool _r = _t->hassendalerts((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 31: { bool _r = _t->hassurvrecord((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 32: _t->on_loginbutton_clicked(); break;
        case 33: _t->on_passwordline_returnPressed(); break;
        case 34: _t->on_usernameline_returnPressed(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
