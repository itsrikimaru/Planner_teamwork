/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../planner_teamwork/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
<<<<<<< Updated upstream
    QByteArrayData data[6];
    char stringdata0[86];
=======
    QByteArrayData data[9];
    char stringdata0[127];
>>>>>>> Stashed changes
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
<<<<<<< Updated upstream
QT_MOC_LITERAL(1, 11, 20), // "on_actiona_triggered"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "on_actionb_triggered"
QT_MOC_LITERAL(4, 54, 13), // "on_ok_clicked"
QT_MOC_LITERAL(5, 68, 17) // "on_cansle_clicked"

    },
    "MainWindow\0on_actiona_triggered\0\0"
    "on_actionb_triggered\0on_ok_clicked\0"
=======
QT_MOC_LITERAL(1, 11, 8), // "appStart"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 20), // "on_actiona_triggered"
QT_MOC_LITERAL(4, 42, 20), // "on_actionb_triggered"
QT_MOC_LITERAL(5, 63, 13), // "on_ok_clicked"
QT_MOC_LITERAL(6, 77, 15), // "QueryUserData_1"
QT_MOC_LITERAL(7, 93, 15), // "QueryUserData_2"
QT_MOC_LITERAL(8, 109, 17) // "on_cansle_clicked"

    },
    "MainWindow\0appStart\0\0on_actiona_triggered\0"
    "on_actionb_triggered\0on_ok_clicked\0"
    "QueryUserData_1\0QueryUserData_2\0"
>>>>>>> Stashed changes
    "on_cansle_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< Updated upstream
       4,   14, // methods
=======
       7,   14, // methods
>>>>>>> Stashed changes
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
<<<<<<< Updated upstream
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,
=======
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
>>>>>>> Stashed changes

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
<<<<<<< Updated upstream
=======
    QMetaType::Bool,
    QMetaType::Bool,
>>>>>>> Stashed changes
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
<<<<<<< Updated upstream
        case 0: _t->on_actiona_triggered(); break;
        case 1: _t->on_actionb_triggered(); break;
        case 2: _t->on_ok_clicked(); break;
        case 3: _t->on_cansle_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
=======
        case 0: _t->appStart(); break;
        case 1: _t->on_actiona_triggered(); break;
        case 2: _t->on_actionb_triggered(); break;
        case 3: _t->on_ok_clicked(); break;
        case 4: { bool _r = _t->QueryUserData_1();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->QueryUserData_2();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->on_cansle_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::appStart)) {
                *result = 0;
                return;
            }
        }
    }
>>>>>>> Stashed changes
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< Updated upstream
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
=======
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::appStart()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
>>>>>>> Stashed changes
QT_WARNING_POP
QT_END_MOC_NAMESPACE
