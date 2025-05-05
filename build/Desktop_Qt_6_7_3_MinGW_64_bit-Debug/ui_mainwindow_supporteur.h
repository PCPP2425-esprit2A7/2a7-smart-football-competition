/********************************************************************************
** Form generated from reading UI file 'mainwindow_supporteur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_SUPPORTEUR_H
#define UI_MAINWINDOW_SUPPORTEUR_H

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

class Ui_MainWindowSupporteur
{
public:
    QWidget *centralwidget;
    QWidget *menu;
    QPushButton *btn_support;
    QPushButton *btn_joueur;
    QPushButton *btn_arbitre;
    QPushButton *btn_equipe;
    QPushButton *btn_match;
    QPushButton *btn_billet_fromsup;
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
    QLineEdit *search_bar;
    QComboBox *tri;
    QTableView *tableView;
    QPushButton *delete_2;
    QPushButton *modify;
    QPushButton *stat;
    QPushButton *pdf;
    QPushButton *light_ilyes;
    QPushButton *dark_ilyes;
    QLabel *label_2;
    QLabel *label;
    QPushButton *home;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowSupporteur)
    {
        if (MainWindowSupporteur->objectName().isEmpty())
            MainWindowSupporteur->setObjectName("MainWindowSupporteur");
        MainWindowSupporteur->resize(1505, 735);
        centralwidget = new QWidget(MainWindowSupporteur);
        centralwidget->setObjectName("centralwidget");
        menu = new QWidget(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(10, 110, 131, 451));
        menu->setStyleSheet(QString::fromUtf8("#menu\n"
"{\n"
"background-color:#218555;\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        btn_support = new QPushButton(menu);
        btn_support->setObjectName("btn_support");
        btn_support->setGeometry(QRect(20, 10, 83, 71));
        btn_support->setStyleSheet(QString::fromUtf8("#btn_support {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/2.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_joueur = new QPushButton(menu);
        btn_joueur->setObjectName("btn_joueur");
        btn_joueur->setGeometry(QRect(20, 90, 83, 61));
        btn_joueur->setStyleSheet(QString::fromUtf8("#btn_joueur {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/joueur-de-football.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_arbitre = new QPushButton(menu);
        btn_arbitre->setObjectName("btn_arbitre");
        btn_arbitre->setGeometry(QRect(20, 160, 83, 71));
        btn_arbitre->setStyleSheet(QString::fromUtf8("#btn_arbitre {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/carte-jaune.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_equipe = new QPushButton(menu);
        btn_equipe->setObjectName("btn_equipe");
        btn_equipe->setGeometry(QRect(20, 230, 83, 61));
        btn_equipe->setStyleSheet(QString::fromUtf8("#btn_equipe {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/4.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_match = new QPushButton(menu);
        btn_match->setObjectName("btn_match");
        btn_match->setGeometry(QRect(20, 298, 83, 71));
        btn_match->setStyleSheet(QString::fromUtf8("#btn_match {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/3.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_billet_fromsup = new QPushButton(menu);
        btn_billet_fromsup->setObjectName("btn_billet_fromsup");
        btn_billet_fromsup->setGeometry(QRect(20, 370, 83, 61));
        btn_billet_fromsup->setStyleSheet(QString::fromUtf8("#btn_billet_fromsup {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/billet.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        form = new QWidget(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(160, 120, 291, 431));
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        id = new QLabel(form);
        id->setObjectName("id");
        id->setGeometry(QRect(10, 30, 81, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        font.setPointSize(10);
        font.setBold(true);
        id->setFont(font);
        id->setStyleSheet(QString::fromUtf8("#label_2{\n"
"color : rgb(0,0,0);\n"
"}"));
        NAME = new QLabel(form);
        NAME->setObjectName("NAME");
        NAME->setGeometry(QRect(10, 80, 63, 20));
        NAME->setFont(font);
        NAME->setStyleSheet(QString::fromUtf8("#label_3{\n"
"color : rgb(0,0,0);\n"
"}"));
        add = new QPushButton(form);
        add->setObjectName("add");
        add->setGeometry(QRect(190, 300, 83, 29));
        add->setFont(font);
        add->setStyleSheet(QString::fromUtf8("#add{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        cancel = new QPushButton(form);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(30, 300, 83, 29));
        cancel->setFont(font);
        cancel->setStyleSheet(QString::fromUtf8("#cancel{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        IdEdit = new QLineEdit(form);
        IdEdit->setObjectName("IdEdit");
        IdEdit->setGeometry(QRect(90, 30, 191, 28));
        IdEdit->setStyleSheet(QString::fromUtf8("#IdEdit\n"
" {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"   border:2px solid #619D90;\n"
"}"));
        NameEdit = new QLineEdit(form);
        NameEdit->setObjectName("NameEdit");
        NameEdit->setGeometry(QRect(90, 80, 191, 28));
        NameEdit->setStyleSheet(QString::fromUtf8("#NameEdit\n"
" {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"   border:2px solid #619D90;\n"
"}"));
        LAST_NAME = new QLabel(form);
        LAST_NAME->setObjectName("LAST_NAME");
        LAST_NAME->setGeometry(QRect(0, 130, 111, 20));
        LAST_NAME->setFont(font);
        LAST_NAME->setStyleSheet(QString::fromUtf8("#label_12{\n"
"color : rgb(0,0,0);\n"
"}"));
        LastnameEdit = new QLineEdit(form);
        LastnameEdit->setObjectName("LastnameEdit");
        LastnameEdit->setGeometry(QRect(100, 120, 181, 28));
        LastnameEdit->setStyleSheet(QString::fromUtf8("#LastnameEdit\n"
" {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"   border:2px solid #619D90;\n"
"}"));
        DATE_NAIS = new QLabel(form);
        DATE_NAIS->setObjectName("DATE_NAIS");
        DATE_NAIS->setGeometry(QRect(0, 180, 91, 20));
        DATE_NAIS->setFont(font);
        DATE_NAIS->setStyleSheet(QString::fromUtf8("#label_13{\n"
"color : rgb(0,0,0);\n"
"}"));
        DateEdit = new QDateEdit(form);
        DateEdit->setObjectName("DateEdit");
        DateEdit->setGeometry(QRect(100, 170, 181, 29));
        DateEdit->setStyleSheet(QString::fromUtf8("#DateEdit\n"
" {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"   border:2px solid #619D90;\n"
"}"));
        GRADE = new QLabel(form);
        GRADE->setObjectName("GRADE");
        GRADE->setGeometry(QRect(10, 250, 81, 20));
        GRADE->setFont(font);
        GRADE->setStyleSheet(QString::fromUtf8("#label_14{\n"
"color : rgb(0,0,0);\n"
"}"));
        GradeEdit = new QLineEdit(form);
        GradeEdit->setObjectName("GradeEdit");
        GradeEdit->setGeometry(QRect(100, 250, 181, 28));
        GradeEdit->setStyleSheet(QString::fromUtf8("#GradeEdit\n"
" {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"   border:2px solid #619D90;\n"
"}"));
        search_bar = new QLineEdit(centralwidget);
        search_bar->setObjectName("search_bar");
        search_bar->setGeometry(QRect(430, 20, 401, 28));
        search_bar->setStyleSheet(QString::fromUtf8("#lineEdit\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        tri = new QComboBox(centralwidget);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1060, 100, 251, 28));
        tri->setStyleSheet(QString::fromUtf8("#tri\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(490, 150, 891, 311));
        tableView->setStyleSheet(QString::fromUtf8("#tableView{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(1160, 490, 83, 29));
        delete_2->setFont(font);
        delete_2->setStyleSheet(QString::fromUtf8("#delete_2{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(1290, 490, 83, 29));
        modify->setFont(font);
        modify->setStyleSheet(QString::fromUtf8("#modify{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(1290, 20, 151, 29));
        stat->setFont(font);
        stat->setStyleSheet(QString::fromUtf8("#stat{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(1330, 90, 31, 41));
        pdf->setFont(font);
        pdf->setStyleSheet(QString::fromUtf8("#pdf{\n"
"	 qproperty-icon:url(:/img/img/1.png);\n"
"  qproperty-iconSize: 30px 30px;\n"
"}"));
        light_ilyes = new QPushButton(centralwidget);
        light_ilyes->setObjectName("light_ilyes");
        light_ilyes->setGeometry(QRect(50, 580, 91, 31));
        QFont font1;
        font1.setBold(true);
        light_ilyes->setFont(font1);
        light_ilyes->setStyleSheet(QString::fromUtf8("#light_ilyes {\n"
"    background-color:transparent; \n"
"    color: #333; \n"
"    border: 2px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 5px 10px; \n"
"}\n"
"\n"
"#light_ilyes:hover {\n"
"    background-color: #e0e0e0;\n"
"    border: 2px solid #bbb;\n"
"}\n"
"\n"
"#light_ilyes:pressed {\n"
"    background-color: #d0d0d0; \n"
"    border: 2px solid #999;\n"
"}"));
        dark_ilyes = new QPushButton(centralwidget);
        dark_ilyes->setObjectName("dark_ilyes");
        dark_ilyes->setGeometry(QRect(160, 580, 83, 29));
        dark_ilyes->setFont(font1);
        dark_ilyes->setStyleSheet(QString::fromUtf8("#dark_ilyes {\n"
"    background-color: #333; /* Dark gray background */\n"
"    color: white; /* White text */\n"
"    border: 2px solid #555; /* Slightly lighter border */\n"
"   border-radius: 10px; /* Rounded corners */\n"
"    padding: 5px 10px; /* Padding for better appearance */\n"
"}\n"
"#dark_ilyes:hover {\n"
"    background-color: #444; /* Slightly lighter on hover */\n"
"    border: 2px solid #777;\n"
"}\n"
"\n"
"#dark_ilyes:pressed {\n"
"    background-color: #222; /* Even darker when pressed */\n"
"    border: 2px solid #999;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 10, 121, 91));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo_yedkom-removebg.png")));
        label_2->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1481, 681));
        label->setStyleSheet(QString::fromUtf8("#label {\n"
"    background-image:url(:/img/img/bg.jpg);\n"
"}\n"
""));
        home = new QPushButton(centralwidget);
        home->setObjectName("home");
        home->setGeometry(QRect(1340, 630, 93, 29));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        home->setFont(font2);
        home->setStyleSheet(QString::fromUtf8("#home\n"
"{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        MainWindowSupporteur->setCentralWidget(centralwidget);
        label->raise();
        menu->raise();
        form->raise();
        search_bar->raise();
        tri->raise();
        tableView->raise();
        delete_2->raise();
        modify->raise();
        stat->raise();
        pdf->raise();
        light_ilyes->raise();
        dark_ilyes->raise();
        label_2->raise();
        home->raise();
        menubar = new QMenuBar(MainWindowSupporteur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1505, 26));
        MainWindowSupporteur->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowSupporteur);
        statusbar->setObjectName("statusbar");
        MainWindowSupporteur->setStatusBar(statusbar);

        retranslateUi(MainWindowSupporteur);

        QMetaObject::connectSlotsByName(MainWindowSupporteur);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowSupporteur)
    {
        MainWindowSupporteur->setWindowTitle(QCoreApplication::translate("MainWindowSupporteur", "MainWindow", nullptr));
        btn_support->setText(QString());
        btn_joueur->setText(QString());
        btn_arbitre->setText(QString());
        btn_equipe->setText(QString());
        btn_match->setText(QString());
        btn_billet_fromsup->setText(QString());
        id->setText(QCoreApplication::translate("MainWindowSupporteur", "id :", nullptr));
        NAME->setText(QCoreApplication::translate("MainWindowSupporteur", "Name :", nullptr));
        add->setText(QCoreApplication::translate("MainWindowSupporteur", "add", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindowSupporteur", "Cancel", nullptr));
        LAST_NAME->setText(QCoreApplication::translate("MainWindowSupporteur", "Last_Name :", nullptr));
        DATE_NAIS->setText(QCoreApplication::translate("MainWindowSupporteur", "Date_Nais :", nullptr));
        GRADE->setText(QCoreApplication::translate("MainWindowSupporteur", "Number :", nullptr));
        search_bar->setPlaceholderText(QCoreApplication::translate("MainWindowSupporteur", "search...", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindowSupporteur", "youngest", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindowSupporteur", "oldest", nullptr));

        delete_2->setText(QCoreApplication::translate("MainWindowSupporteur", "delete", nullptr));
        modify->setText(QCoreApplication::translate("MainWindowSupporteur", "modify", nullptr));
        stat->setText(QCoreApplication::translate("MainWindowSupporteur", "report statistique", nullptr));
        pdf->setText(QString());
        light_ilyes->setText(QCoreApplication::translate("MainWindowSupporteur", "light", nullptr));
        dark_ilyes->setText(QCoreApplication::translate("MainWindowSupporteur", "Dark", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        home->setText(QCoreApplication::translate("MainWindowSupporteur", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowSupporteur: public Ui_MainWindowSupporteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_SUPPORTEUR_H
