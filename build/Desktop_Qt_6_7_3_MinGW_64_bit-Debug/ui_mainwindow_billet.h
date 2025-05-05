/********************************************************************************
** Form generated from reading UI file 'mainwindow_billet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_BILLET_H
#define UI_MAINWINDOW_BILLET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
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

class Ui_MainWindowBillet
{
public:
    QWidget *centralwidget;
    QWidget *menu;
    QPushButton *btn_supporteur;
    QPushButton *btn_joueur;
    QPushButton *btn_arbitre;
    QPushButton *btn_equipe;
    QPushButton *btn_match;
    QPushButton *btn_billet;
    QWidget *form;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *id;
    QComboBox *type;
    QComboBox *area;
    QLineEdit *price;
    QLineEdit *quantity;
    QDateEdit *date_issue;
    QDateEdit *date_event;
    QPushButton *add;
    QPushButton *cancel;
    QLineEdit *search_bar;
    QComboBox *tri;
    QPushButton *modify;
    QPushButton *stat;
    QPushButton *generate;
    QPushButton *delete_2;
    QLabel *logo;
    QTableView *table;
    QPushButton *pdf;
    QPushButton *light;
    QPushButton *dark;
    QLabel *bg;
    QLabel *label_rfid;
    QPushButton *home;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowBillet)
    {
        if (MainWindowBillet->objectName().isEmpty())
            MainWindowBillet->setObjectName("MainWindowBillet");
        MainWindowBillet->resize(1530, 801);
        centralwidget = new QWidget(MainWindowBillet);
        centralwidget->setObjectName("centralwidget");
        menu = new QWidget(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(30, 150, 120, 511));
        menu->setStyleSheet(QString::fromUtf8("#menu\n"
"{\n"
"background-color:#218555;\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        btn_supporteur = new QPushButton(menu);
        btn_supporteur->setObjectName("btn_supporteur");
        btn_supporteur->setGeometry(QRect(20, 10, 71, 81));
        btn_supporteur->setStyleSheet(QString::fromUtf8("#btn_supporteur {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/2.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_joueur = new QPushButton(menu);
        btn_joueur->setObjectName("btn_joueur");
        btn_joueur->setGeometry(QRect(20, 90, 71, 81));
        btn_joueur->setStyleSheet(QString::fromUtf8("#btn_joueur {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/joueur-de-football.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_arbitre = new QPushButton(menu);
        btn_arbitre->setObjectName("btn_arbitre");
        btn_arbitre->setGeometry(QRect(20, 170, 71, 81));
        btn_arbitre->setStyleSheet(QString::fromUtf8("#btn_arbitre {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/carte-jaune.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_equipe = new QPushButton(menu);
        btn_equipe->setObjectName("btn_equipe");
        btn_equipe->setGeometry(QRect(20, 260, 71, 81));
        btn_equipe->setStyleSheet(QString::fromUtf8("#btn_equipe {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/4.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_match = new QPushButton(menu);
        btn_match->setObjectName("btn_match");
        btn_match->setGeometry(QRect(20, 340, 71, 81));
        btn_match->setStyleSheet(QString::fromUtf8("#btn_match {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/3.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_billet = new QPushButton(menu);
        btn_billet->setObjectName("btn_billet");
        btn_billet->setGeometry(QRect(20, 420, 71, 81));
        btn_billet->setStyleSheet(QString::fromUtf8("#btn_billet {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/billet.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        form = new QWidget(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(170, 150, 321, 511));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        form->setFont(font);
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));
        label_2 = new QLabel(form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 61, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sylfaen")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_3 = new QLabel(form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 71, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(form);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 150, 71, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(form);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 200, 111, 41));
        label_5->setFont(font1);
        label_6 = new QLabel(form);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 260, 71, 31));
        label_6->setFont(font1);
        label_7 = new QLabel(form);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 310, 121, 41));
        label_7->setFont(font1);
        label_8 = new QLabel(form);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 370, 131, 51));
        label_8->setFont(font1);
        id = new QLineEdit(form);
        id->setObjectName("id");
        id->setGeometry(QRect(150, 50, 151, 31));
        id->setStyleSheet(QString::fromUtf8("#id {\n"
"    border-radius: 10px ;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"	border:2px solid #619D80;\n"
"}\n"
""));
        type = new QComboBox(form);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");
        type->setGeometry(QRect(150, 110, 151, 26));
        type->setStyleSheet(QString::fromUtf8("#type {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"	border:2px solid #619D80;\n"
"}\n"
""));
        area = new QComboBox(form);
        area->addItem(QString());
        area->addItem(QString());
        area->addItem(QString());
        area->setObjectName("area");
        area->setGeometry(QRect(150, 260, 151, 26));
        area->setStyleSheet(QString::fromUtf8("#area {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"	\n"
"	border:2px solid #619D80;\n"
"}\n"
""));
        price = new QLineEdit(form);
        price->setObjectName("price");
        price->setGeometry(QRect(152, 160, 151, 31));
        price->setStyleSheet(QString::fromUtf8("#price {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"	\n"
"	border:2px solid #619D80;\n"
"}\n"
""));
        quantity = new QLineEdit(form);
        quantity->setObjectName("quantity");
        quantity->setGeometry(QRect(152, 210, 151, 31));
        quantity->setStyleSheet(QString::fromUtf8("#quantity {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"	\n"
"	border:2px solid #619D80;\n"
"}\n"
""));
        date_issue = new QDateEdit(form);
        date_issue->setObjectName("date_issue");
        date_issue->setGeometry(QRect(160, 320, 141, 31));
        date_issue->setStyleSheet(QString::fromUtf8("#date_issue {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"\n"
"	border:2px solid #619D80;\n"
"}\n"
""));
        date_event = new QDateEdit(form);
        date_event->setObjectName("date_event");
        date_event->setGeometry(QRect(160, 380, 141, 31));
        date_event->setStyleSheet(QString::fromUtf8("#date_event {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"\n"
"	border:2px solid #619D80;\n"
"}\n"
""));
        add = new QPushButton(form);
        add->setObjectName("add");
        add->setGeometry(QRect(190, 450, 93, 29));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sylfaen")});
        font2.setPointSize(10);
        font2.setBold(true);
        add->setFont(font2);
        add->setStyleSheet(QString::fromUtf8("#add{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        cancel = new QPushButton(form);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(40, 450, 93, 29));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sylfaen")});
        font3.setBold(true);
        cancel->setFont(font3);
        cancel->setStyleSheet(QString::fromUtf8("#cancel{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        search_bar = new QLineEdit(centralwidget);
        search_bar->setObjectName("search_bar");
        search_bar->setGeometry(QRect(520, 20, 501, 31));
        search_bar->setStyleSheet(QString::fromUtf8("#search_bar {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        tri = new QComboBox(centralwidget);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1090, 130, 231, 31));
        tri->setStyleSheet(QString::fromUtf8("#tri\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(1290, 670, 93, 29));
        modify->setFont(font3);
        modify->setStyleSheet(QString::fromUtf8("#modify{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(1272, 20, 131, 29));
        stat->setFont(font3);
        stat->setStyleSheet(QString::fromUtf8("#stat{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        generate = new QPushButton(centralwidget);
        generate->setObjectName("generate");
        generate->setGeometry(QRect(1160, 20, 93, 29));
        generate->setFont(font3);
        generate->setStyleSheet(QString::fromUtf8("#generate{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(1160, 670, 93, 29));
        delete_2->setFont(font3);
        delete_2->setStyleSheet(QString::fromUtf8("#delete_2\n"
"{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(20, 20, 151, 111));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo_yedkom-removebg.png")));
        logo->setScaledContents(true);
        table = new QTableView(centralwidget);
        table->setObjectName("table");
        table->setGeometry(QRect(630, 170, 841, 491));
        table->setStyleSheet(QString::fromUtf8("#table{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        pdf = new QPushButton(centralwidget);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(1360, 130, 71, 31));
        pdf->setStyleSheet(QString::fromUtf8("#pdf {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/1.png);\n"
"    qproperty-iconSize: 30px 30px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/img/pdf.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdf->setIcon(icon);
        light = new QPushButton(centralwidget);
        light->setObjectName("light");
        light->setGeometry(QRect(20, 710, 93, 31));
        light->setFont(font2);
        light->setStyleSheet(QString::fromUtf8("#light {\n"
"    background-color:transparent; \n"
"    color: #333; \n"
"    border: 2px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 5px 10px; \n"
"}\n"
"\n"
"#light:hover {\n"
"    background-color: #e0e0e0;\n"
"    border: 2px solid #bbb;\n"
"}\n"
"\n"
"#light:pressed {\n"
"    background-color: #d0d0d0; \n"
"    border: 2px solid #999;\n"
"}"));
        dark = new QPushButton(centralwidget);
        dark->setObjectName("dark");
        dark->setGeometry(QRect(120, 710, 93, 29));
        dark->setFont(font2);
        dark->setStyleSheet(QString::fromUtf8("#dark {\n"
"    background-color: #333; /* Dark gray background */\n"
"    color: white; /* White text */\n"
"    border: 2px solid #555; /* Slightly lighter border */\n"
"   border-radius: 10px; /* Rounded corners */\n"
"    padding: 5px 10px; /* Padding for better appearance */\n"
"}\n"
"#dark:hover {\n"
"    background-color: #444; /* Slightly lighter on hover */\n"
"    border: 2px solid #777;\n"
"}\n"
"\n"
"#dark:pressed {\n"
"    background-color: #222; /* Even darker when pressed */\n"
"    border: 2px solid #999;\n"
"}"));
        bg = new QLabel(centralwidget);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(0, 0, 1531, 761));
        bg->setStyleSheet(QString::fromUtf8("#bg{\n"
"	background-image: url(:/img/img/bg.jpg);\n"
"}"));
        label_rfid = new QLabel(centralwidget);
        label_rfid->setObjectName("label_rfid");
        label_rfid->setGeometry(QRect(200, 20, 271, 101));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Sylfaen")});
        font4.setPointSize(11);
        font4.setBold(true);
        label_rfid->setFont(font4);
        home = new QPushButton(centralwidget);
        home->setObjectName("home");
        home->setGeometry(QRect(1420, 710, 93, 29));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        home->setFont(font5);
        home->setStyleSheet(QString::fromUtf8("#home{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        MainWindowBillet->setCentralWidget(centralwidget);
        bg->raise();
        menu->raise();
        form->raise();
        search_bar->raise();
        tri->raise();
        modify->raise();
        stat->raise();
        generate->raise();
        delete_2->raise();
        logo->raise();
        table->raise();
        pdf->raise();
        light->raise();
        dark->raise();
        label_rfid->raise();
        home->raise();
        menubar = new QMenuBar(MainWindowBillet);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1530, 26));
        MainWindowBillet->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowBillet);
        statusbar->setObjectName("statusbar");
        MainWindowBillet->setStatusBar(statusbar);

        retranslateUi(MainWindowBillet);

        QMetaObject::connectSlotsByName(MainWindowBillet);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowBillet)
    {
        MainWindowBillet->setWindowTitle(QCoreApplication::translate("MainWindowBillet", "MainWindow", nullptr));
        btn_supporteur->setText(QString());
        btn_joueur->setText(QString());
        btn_arbitre->setText(QString());
        btn_equipe->setText(QString());
        btn_match->setText(QString());
        btn_billet->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindowBillet", "Id :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowBillet", "Type :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindowBillet", "Price :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindowBillet", "Quantity :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindowBillet", "Area :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindowBillet", "Date_issue :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindowBillet", "Date_event :", nullptr));
        id->setPlaceholderText(QCoreApplication::translate("MainWindowBillet", "Enter Id", nullptr));
        type->setItemText(0, QCoreApplication::translate("MainWindowBillet", "Eco", nullptr));
        type->setItemText(1, QCoreApplication::translate("MainWindowBillet", "Standard ", nullptr));
        type->setItemText(2, QCoreApplication::translate("MainWindowBillet", "VIP", nullptr));

        area->setItemText(0, QCoreApplication::translate("MainWindowBillet", "A", nullptr));
        area->setItemText(1, QCoreApplication::translate("MainWindowBillet", "B", nullptr));
        area->setItemText(2, QCoreApplication::translate("MainWindowBillet", "C", nullptr));

        price->setPlaceholderText(QCoreApplication::translate("MainWindowBillet", "Enter Price", nullptr));
        quantity->setPlaceholderText(QCoreApplication::translate("MainWindowBillet", "Enter Quantity", nullptr));
        add->setText(QCoreApplication::translate("MainWindowBillet", "Add", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindowBillet", "Cancel", nullptr));
        search_bar->setPlaceholderText(QCoreApplication::translate("MainWindowBillet", "search...", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindowBillet", "Default", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindowBillet", "Expensive", nullptr));
        tri->setItemText(2, QCoreApplication::translate("MainWindowBillet", "Cheap", nullptr));

        tri->setPlaceholderText(QString());
        modify->setText(QCoreApplication::translate("MainWindowBillet", "Modify", nullptr));
        stat->setText(QCoreApplication::translate("MainWindowBillet", "Report statistics", nullptr));
        generate->setText(QCoreApplication::translate("MainWindowBillet", "Generate", nullptr));
        delete_2->setText(QCoreApplication::translate("MainWindowBillet", "Delete", nullptr));
        logo->setText(QString());
        pdf->setText(QString());
        light->setText(QCoreApplication::translate("MainWindowBillet", "Light", nullptr));
        dark->setText(QCoreApplication::translate("MainWindowBillet", "Dark", nullptr));
        bg->setText(QString());
        label_rfid->setText(QString());
        home->setText(QCoreApplication::translate("MainWindowBillet", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowBillet: public Ui_MainWindowBillet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_BILLET_H
