/********************************************************************************
** Form generated from reading UI file 'mainwindow_equipe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_EQUIPE_H
#define UI_MAINWINDOW_EQUIPE_H

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

class Ui_MainWindowEquipe
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *menu;
    QPushButton *btn_supporteur_khaled;
    QPushButton *btn_joueur_khaled;
    QPushButton *btn_arbitre_khaled;
    QPushButton *btn_equipe_khaled;
    QPushButton *btn_match_khaled;
    QPushButton *btn_billet_khaled;
    QWidget *form;
    QLabel *id;
    QLabel *team_name;
    QLabel *creation_date;
    QLabel *prizes;
    QLineEdit *idEdit;
    QLineEdit *team_nameEdit;
    QLineEdit *prizesEdit;
    QPushButton *add;
    QPushButton *cancel;
    QDateEdit *dateEdit;
    QLineEdit *coachEdit;
    QLabel *coach;
    QPushButton *modify;
    QPushButton *delete_2;
    QComboBox *comboBox;
    QLineEdit *lineEdit_nomEquipe;
    QTableView *tableView;
    QPushButton *stat;
    QPushButton *pushButton_chercher;
    QPushButton *pushButton_trier_asc;
    QPushButton *pushButton_trier_desc;
    QPushButton *pushButton_exportPDF;
    QPushButton *btn_statistiques;
    QTableView *tableView_2;
    QPushButton *btn_historique;
    QPushButton *dark;
    QPushButton *light;
    QPushButton *home;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowEquipe)
    {
        if (MainWindowEquipe->objectName().isEmpty())
            MainWindowEquipe->setObjectName("MainWindowEquipe");
        MainWindowEquipe->resize(1417, 752);
        centralwidget = new QWidget(MainWindowEquipe);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-90, 0, 1511, 731));
        label->setStyleSheet(QString::fromUtf8("#label{\n"
"background-image:url(:/img/img/bg.jpg);\n"
"}"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/0059fdc0-f636-4fbb-a241-8234ae243df9.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-10, 0, 181, 101));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo_yedkom-removebg.png")));
        label_2->setScaledContents(true);
        menu = new QWidget(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(10, 100, 121, 451));
        menu->setStyleSheet(QString::fromUtf8("#menu {\n"
"background-color: #218555;}"));
        btn_supporteur_khaled = new QPushButton(menu);
        btn_supporteur_khaled->setObjectName("btn_supporteur_khaled");
        btn_supporteur_khaled->setGeometry(QRect(10, 10, 93, 61));
        btn_supporteur_khaled->setStyleSheet(QString::fromUtf8("#btn_supporteur_khaled {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/2.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_joueur_khaled = new QPushButton(menu);
        btn_joueur_khaled->setObjectName("btn_joueur_khaled");
        btn_joueur_khaled->setGeometry(QRect(10, 80, 93, 61));
        btn_joueur_khaled->setStyleSheet(QString::fromUtf8("#btn_joueur_khaled {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/joueur-de-football.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_arbitre_khaled = new QPushButton(menu);
        btn_arbitre_khaled->setObjectName("btn_arbitre_khaled");
        btn_arbitre_khaled->setGeometry(QRect(10, 150, 93, 71));
        btn_arbitre_khaled->setStyleSheet(QString::fromUtf8("#btn_arbitre_khaled\n"
" {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/carte-jaune.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_equipe_khaled = new QPushButton(menu);
        btn_equipe_khaled->setObjectName("btn_equipe_khaled");
        btn_equipe_khaled->setGeometry(QRect(10, 230, 93, 61));
        btn_equipe_khaled->setStyleSheet(QString::fromUtf8("#btn_equipe_khaled {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/4.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_match_khaled = new QPushButton(menu);
        btn_match_khaled->setObjectName("btn_match_khaled");
        btn_match_khaled->setGeometry(QRect(10, 300, 93, 71));
        btn_match_khaled->setStyleSheet(QString::fromUtf8("#btn_match_khaled\n"
" {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/3.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        btn_billet_khaled = new QPushButton(menu);
        btn_billet_khaled->setObjectName("btn_billet_khaled");
        btn_billet_khaled->setGeometry(QRect(10, 380, 93, 61));
        btn_billet_khaled->setStyleSheet(QString::fromUtf8("#btn_billet_khaled {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/billet.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        form = new QWidget(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(140, 100, 361, 451));
        form->setStyleSheet(QString::fromUtf8("#form\n"
"{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}"));
        id = new QLabel(form);
        id->setObjectName("id");
        id->setGeometry(QRect(20, 40, 63, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        font.setPointSize(14);
        font.setBold(false);
        id->setFont(font);
        team_name = new QLabel(form);
        team_name->setObjectName("team_name");
        team_name->setGeometry(QRect(20, 100, 141, 20));
        team_name->setFont(font);
        creation_date = new QLabel(form);
        creation_date->setObjectName("creation_date");
        creation_date->setGeometry(QRect(20, 160, 161, 20));
        creation_date->setFont(font);
        prizes = new QLabel(form);
        prizes->setObjectName("prizes");
        prizes->setGeometry(QRect(20, 220, 63, 20));
        prizes->setFont(font);
        idEdit = new QLineEdit(form);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(190, 30, 161, 31));
        idEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        team_nameEdit = new QLineEdit(form);
        team_nameEdit->setObjectName("team_nameEdit");
        team_nameEdit->setGeometry(QRect(190, 90, 161, 31));
        team_nameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        prizesEdit = new QLineEdit(form);
        prizesEdit->setObjectName("prizesEdit");
        prizesEdit->setGeometry(QRect(190, 210, 161, 31));
        prizesEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        add = new QPushButton(form);
        add->setObjectName("add");
        add->setGeometry(QRect(220, 380, 93, 29));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sylfaen")});
        font1.setPointSize(14);
        font1.setBold(true);
        add->setFont(font1);
        add->setStyleSheet(QString::fromUtf8("#add{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;\n"
"}"));
        cancel = new QPushButton(form);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(30, 380, 93, 29));
        cancel->setFont(font1);
        cancel->setStyleSheet(QString::fromUtf8("#cancel{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        dateEdit = new QDateEdit(form);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(190, 150, 161, 31));
        coachEdit = new QLineEdit(form);
        coachEdit->setObjectName("coachEdit");
        coachEdit->setGeometry(QRect(190, 270, 161, 31));
        coachEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        coach = new QLabel(form);
        coach->setObjectName("coach");
        coach->setGeometry(QRect(20, 280, 81, 20));
        coach->setFont(font);
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(1290, 350, 101, 31));
        modify->setFont(font);
        modify->setStyleSheet(QString::fromUtf8("#modify{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;\n"
"}"));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(1150, 350, 93, 29));
        delete_2->setFont(font);
        delete_2->setStyleSheet(QString::fromUtf8("#delete_2{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;}"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(1120, 100, 171, 26));
        lineEdit_nomEquipe = new QLineEdit(centralwidget);
        lineEdit_nomEquipe->setObjectName("lineEdit_nomEquipe");
        lineEdit_nomEquipe->setGeometry(QRect(360, 10, 561, 26));
        lineEdit_nomEquipe->setStyleSheet(QString::fromUtf8("#search{\n"
"border-radius:10px;\n"
"padding:5px;\n"
"background:white;\n"
"}\n"
"search{\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"   border: 2px solid #619D80; /* Green border */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(660, 140, 731, 192));
        tableView->setStyleSheet(QString::fromUtf8("#tableView{\n"
"   background-color: rgba(97, 157, 128, 0.4); /* Adjusted RGBA version of #619D80 */\n"
"   border-radius: 10px;\n"
"   padding:5px;\n"
"\n"
"}"));
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(1250, 20, 141, 29));
        stat->setStyleSheet(QString::fromUtf8("#stat{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;\n"
"}"));
        pushButton_chercher = new QPushButton(centralwidget);
        pushButton_chercher->setObjectName("pushButton_chercher");
        pushButton_chercher->setGeometry(QRect(930, 10, 141, 29));
        pushButton_chercher->setFont(font);
        pushButton_chercher->setStyleSheet(QString::fromUtf8("\n"
"\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background-color: #218555;"));
        pushButton_trier_asc = new QPushButton(centralwidget);
        pushButton_trier_asc->setObjectName("pushButton_trier_asc");
        pushButton_trier_asc->setGeometry(QRect(650, 410, 93, 29));
        pushButton_trier_asc->setFont(font);
        pushButton_trier_asc->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;"));
        pushButton_trier_desc = new QPushButton(centralwidget);
        pushButton_trier_desc->setObjectName("pushButton_trier_desc");
        pushButton_trier_desc->setGeometry(QRect(860, 410, 93, 29));
        pushButton_trier_desc->setFont(font);
        pushButton_trier_desc->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;"));
        pushButton_exportPDF = new QPushButton(centralwidget);
        pushButton_exportPDF->setObjectName("pushButton_exportPDF");
        pushButton_exportPDF->setGeometry(QRect(1310, 90, 71, 41));
        pushButton_exportPDF->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/462570095_921252616280712_7517074504935030371_n.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_exportPDF->setIcon(icon);
        btn_statistiques = new QPushButton(centralwidget);
        btn_statistiques->setObjectName("btn_statistiques");
        btn_statistiques->setGeometry(QRect(1260, 410, 131, 29));
        btn_statistiques->setFont(font);
        btn_statistiques->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;"));
        tableView_2 = new QTableView(centralwidget);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(650, 460, 751, 192));
        tableView_2->setStyleSheet(QString::fromUtf8("background-color: rgba(97, 157, 128, 0.4); /* Adjusted RGBA version of #619D80 */\n"
"   border-radius: 10px;\n"
"   padding:5px;\n"
""));
        btn_historique = new QPushButton(centralwidget);
        btn_historique->setObjectName("btn_historique");
        btn_historique->setGeometry(QRect(1030, 410, 131, 29));
        btn_historique->setFont(font);
        btn_historique->setStyleSheet(QString::fromUtf8("\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;"));
        dark = new QPushButton(centralwidget);
        dark->setObjectName("dark");
        dark->setGeometry(QRect(150, 640, 93, 29));
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
        light = new QPushButton(centralwidget);
        light->setObjectName("light");
        light->setGeometry(QRect(40, 640, 93, 31));
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
        home = new QPushButton(centralwidget);
        home->setObjectName("home");
        home->setGeometry(QRect(1300, 670, 93, 29));
        QFont font2;
        font2.setBold(true);
        home->setFont(font2);
        home->setStyleSheet(QString::fromUtf8("#home\n"
"{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;\n"
"}"));
        MainWindowEquipe->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowEquipe);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1417, 26));
        MainWindowEquipe->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowEquipe);
        statusbar->setObjectName("statusbar");
        MainWindowEquipe->setStatusBar(statusbar);

        retranslateUi(MainWindowEquipe);

        QMetaObject::connectSlotsByName(MainWindowEquipe);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowEquipe)
    {
        MainWindowEquipe->setWindowTitle(QCoreApplication::translate("MainWindowEquipe", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        btn_supporteur_khaled->setText(QString());
        btn_joueur_khaled->setText(QString());
        btn_arbitre_khaled->setText(QString());
        btn_equipe_khaled->setText(QString());
        btn_match_khaled->setText(QString());
        btn_billet_khaled->setText(QString());
        id->setText(QCoreApplication::translate("MainWindowEquipe", "ID:", nullptr));
        team_name->setText(QCoreApplication::translate("MainWindowEquipe", "Team_Name:", nullptr));
        creation_date->setText(QCoreApplication::translate("MainWindowEquipe", "Creation_Date:", nullptr));
        prizes->setText(QCoreApplication::translate("MainWindowEquipe", "Prizes:", nullptr));
        add->setText(QCoreApplication::translate("MainWindowEquipe", "Add", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindowEquipe", "Cancel", nullptr));
        coach->setText(QCoreApplication::translate("MainWindowEquipe", "Coach:", nullptr));
        modify->setText(QCoreApplication::translate("MainWindowEquipe", "Modify", nullptr));
        delete_2->setText(QCoreApplication::translate("MainWindowEquipe", "Delete", nullptr));
        comboBox->setPlaceholderText(QCoreApplication::translate("MainWindowEquipe", "Filtre..", nullptr));
        lineEdit_nomEquipe->setPlaceholderText(QCoreApplication::translate("MainWindowEquipe", "Search..", nullptr));
        stat->setText(QCoreApplication::translate("MainWindowEquipe", "Report statics", nullptr));
        pushButton_chercher->setText(QCoreApplication::translate("MainWindowEquipe", "CHERCHER", nullptr));
        pushButton_trier_asc->setText(QCoreApplication::translate("MainWindowEquipe", "tri asc", nullptr));
        pushButton_trier_desc->setText(QCoreApplication::translate("MainWindowEquipe", "tri dsc", nullptr));
        pushButton_exportPDF->setText(QCoreApplication::translate("MainWindowEquipe", "PDF", nullptr));
        btn_statistiques->setText(QCoreApplication::translate("MainWindowEquipe", "statistique", nullptr));
        btn_historique->setText(QCoreApplication::translate("MainWindowEquipe", "historique", nullptr));
        dark->setText(QCoreApplication::translate("MainWindowEquipe", "dark", nullptr));
        light->setText(QCoreApplication::translate("MainWindowEquipe", "light", nullptr));
        home->setText(QCoreApplication::translate("MainWindowEquipe", "home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowEquipe: public Ui_MainWindowEquipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_EQUIPE_H
