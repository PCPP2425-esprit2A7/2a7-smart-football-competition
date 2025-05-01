/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *menu;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *form;
    QLabel *id;
    QLabel *NAME;
    QPushButton *add;
    QPushButton *cancel;
    QLineEdit *IdEdit;
    QLineEdit *NameEdit;
    QLabel *LAST_NAME;
    QLineEdit *LastnameEdit;
    QLabel *DATE_NAIS;
    QDateEdit *DateEdit;
    QLabel *GRADE;
    QLineEdit *GradeEdit;
    QLabel *label_10;
    QLineEdit *lineEdit;
    QComboBox *tri;
    QLabel *label_11;
    QTableView *tableView;
    QPushButton *delete_2;
    QPushButton *modify;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1088, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1121, 551));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->setScaledContents(true);
        menu = new QWidget(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(20, 120, 120, 431));
        menu->setStyleSheet(QString::fromUtf8("#menu\n"
"{\n"
"background-color:#218555;\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        label_4 = new QLabel(menu);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 19, 63, 31));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/img/img/2.png")));
        label_4->setScaledContents(true);
        label_5 = new QLabel(menu);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 80, 63, 51));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/img/joueur-de-football.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(menu);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(30, 160, 63, 41));
        label_6->setPixmap(QPixmap(QString::fromUtf8(":/img/img/carte-jaune.png")));
        label_6->setScaledContents(true);
        label_7 = new QLabel(menu);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 230, 63, 51));
        label_7->setPixmap(QPixmap(QString::fromUtf8(":/img/img/4.png")));
        label_7->setScaledContents(true);
        label_8 = new QLabel(menu);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 300, 63, 41));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/img/img/3.png")));
        label_8->setScaledContents(true);
        label_9 = new QLabel(menu);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 370, 63, 51));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/img/img/billet.png")));
        label_9->setScaledContents(true);
        form = new QWidget(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(160, 120, 211, 431));
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        id = new QLabel(form);
        id->setObjectName("id");
        id->setGeometry(QRect(10, 30, 81, 20));
        id->setStyleSheet(QString::fromUtf8("#label_2{\n"
"color : rgb(0,0,0);\n"
"}"));
        NAME = new QLabel(form);
        NAME->setObjectName("NAME");
        NAME->setGeometry(QRect(10, 80, 63, 20));
        NAME->setStyleSheet(QString::fromUtf8("#label_3{\n"
"color : rgb(0,0,0);\n"
"}"));
        add = new QPushButton(form);
        add->setObjectName("add");
        add->setGeometry(QRect(100, 380, 83, 29));
        add->setStyleSheet(QString::fromUtf8("#add{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        cancel = new QPushButton(form);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(0, 380, 83, 29));
        cancel->setStyleSheet(QString::fromUtf8("#cancel{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"color:rgb(0,0,0);\n"
"}"));
        IdEdit = new QLineEdit(form);
        IdEdit->setObjectName("IdEdit");
        IdEdit->setGeometry(QRect(70, 30, 113, 28));
        IdEdit->setStyleSheet(QString::fromUtf8("#id\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        NameEdit = new QLineEdit(form);
        NameEdit->setObjectName("NameEdit");
        NameEdit->setGeometry(QRect(70, 80, 113, 28));
        NameEdit->setStyleSheet(QString::fromUtf8("#Name\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        LAST_NAME = new QLabel(form);
        LAST_NAME->setObjectName("LAST_NAME");
        LAST_NAME->setGeometry(QRect(0, 130, 81, 20));
        LAST_NAME->setStyleSheet(QString::fromUtf8("#label_12{\n"
"color : rgb(0,0,0);\n"
"}"));
        LastnameEdit = new QLineEdit(form);
        LastnameEdit->setObjectName("LastnameEdit");
        LastnameEdit->setGeometry(QRect(80, 130, 113, 28));
        LastnameEdit->setStyleSheet(QString::fromUtf8("#last\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        DATE_NAIS = new QLabel(form);
        DATE_NAIS->setObjectName("DATE_NAIS");
        DATE_NAIS->setGeometry(QRect(0, 180, 91, 20));
        DATE_NAIS->setStyleSheet(QString::fromUtf8("#label_13{\n"
"color : rgb(0,0,0);\n"
"}"));
        DateEdit = new QDateEdit(form);
        DateEdit->setObjectName("DateEdit");
        DateEdit->setGeometry(QRect(80, 180, 110, 29));
        DateEdit->setStyleSheet(QString::fromUtf8("#dateEdit\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        GRADE = new QLabel(form);
        GRADE->setObjectName("GRADE");
        GRADE->setGeometry(QRect(10, 250, 63, 20));
        GRADE->setStyleSheet(QString::fromUtf8("#label_14{\n"
"color : rgb(0,0,0);\n"
"}"));
        GradeEdit = new QLineEdit(form);
        GradeEdit->setObjectName("GradeEdit");
        GradeEdit->setGeometry(QRect(80, 250, 113, 28));
        GradeEdit->setStyleSheet(QString::fromUtf8("#number\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 20, 141, 81));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.jpeg")));
        label_10->setScaledContents(true);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(370, 20, 401, 28));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        tri = new QComboBox(centralwidget);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(701, 100, 251, 28));
        tri->setStyleSheet(QString::fromUtf8("#tri\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(970, 100, 31, 31));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/img/img/1.png")));
        label_11->setScaledContents(true);
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(470, 160, 541, 192));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(790, 400, 83, 29));
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(900, 400, 83, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1088, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        id->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        NAME->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        LAST_NAME->setText(QCoreApplication::translate("MainWindow", "Last_Name", nullptr));
        DATE_NAIS->setText(QCoreApplication::translate("MainWindow", "Date_Nais", nullptr));
        GRADE->setText(QCoreApplication::translate("MainWindow", "Number", nullptr));
        label_10->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "search...", nullptr));
        label_11->setText(QString());
        delete_2->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        modify->setText(QCoreApplication::translate("MainWindow", "modify", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
