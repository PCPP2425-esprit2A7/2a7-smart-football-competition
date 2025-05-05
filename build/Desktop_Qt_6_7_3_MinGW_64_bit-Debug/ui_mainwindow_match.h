/********************************************************************************
** Form generated from reading UI file 'mainwindow_match.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_MATCH_H
#define UI_MAINWINDOW_MATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowMatch
{
public:
    QWidget *centralWidget;
    QWidget *menu;
    QPushButton *supp_btn;
    QPushButton *joueur_btn;
    QPushButton *equipe_btn;
    QPushButton *arbitre_btn;
    QPushButton *match_btn;
    QPushButton *billet_btn;
    QLabel *logo;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_modifier;
    QWidget *tab_2;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_calculer;
    QCalendarWidget *calendarWidget;
    QWidget *tab_3;
    QLabel *labelMap;
    QWidget *mapContainer;
    QLineEdit *lineEdit_recherche;
    QComboBox *tri;
    QPushButton *pushButton_rechercher;
    QLabel *ExporterPDF;
    QPushButton *pushButton_exportPDF;
    QWidget *form;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *id;
    QLineEdit *place;
    QComboBox *status;
    QLineEdit *score;
    QPushButton *pushButton_quitter;
    QDateTimeEdit *date_time;
    QLineEdit *arbitre;
    QLabel *label_8;
    QPushButton *pushButton_ajouter;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *team1;
    QLineEdit *team2;
    QLabel *label_12;
    QPushButton *pushButton_superviser;
    QPushButton *dark;
    QPushButton *light;
    QLabel *label;
    QPushButton *home;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowMatch)
    {
        if (MainWindowMatch->objectName().isEmpty())
            MainWindowMatch->setObjectName("MainWindowMatch");
        MainWindowMatch->resize(1496, 746);
        centralWidget = new QWidget(MainWindowMatch);
        centralWidget->setObjectName("centralWidget");
        menu = new QWidget(centralWidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(20, 70, 101, 471));
        menu->setStyleSheet(QString::fromUtf8("#menu{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        supp_btn = new QPushButton(menu);
        supp_btn->setObjectName("supp_btn");
        supp_btn->setGeometry(QRect(0, 20, 101, 71));
        supp_btn->setStyleSheet(QString::fromUtf8("#supp_btn {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/2.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        joueur_btn = new QPushButton(menu);
        joueur_btn->setObjectName("joueur_btn");
        joueur_btn->setGeometry(QRect(0, 100, 101, 61));
        joueur_btn->setStyleSheet(QString::fromUtf8("#joueur_btn\n"
" {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/joueur-de-football.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        equipe_btn = new QPushButton(menu);
        equipe_btn->setObjectName("equipe_btn");
        equipe_btn->setGeometry(QRect(0, 240, 101, 61));
        equipe_btn->setStyleSheet(QString::fromUtf8("#equipe_btn {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/4.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        arbitre_btn = new QPushButton(menu);
        arbitre_btn->setObjectName("arbitre_btn");
        arbitre_btn->setGeometry(QRect(0, 170, 101, 61));
        arbitre_btn->setStyleSheet(QString::fromUtf8("#arbitre_btn {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/carte-jaune.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        match_btn = new QPushButton(menu);
        match_btn->setObjectName("match_btn");
        match_btn->setGeometry(QRect(0, 310, 101, 61));
        match_btn->setStyleSheet(QString::fromUtf8("#match_btn {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/3.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        billet_btn = new QPushButton(menu);
        billet_btn->setObjectName("billet_btn");
        billet_btn->setGeometry(QRect(0, 390, 101, 61));
        billet_btn->setStyleSheet(QString::fromUtf8("#billet_btn {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/billet.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        logo = new QLabel(centralWidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 0, 131, 81));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo_yedkom-removebg.png")));
        logo->setScaledContents(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(520, 150, 841, 371));
        tabWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/bg.jpg);\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 20, 801, 241));
        tableView->setStyleSheet(QString::fromUtf8("#tableView{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(930, 480, 89, 20));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(830, 480, 89, 20));
        pushButton_supprimer = new QPushButton(tab);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(630, 290, 75, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        font.setPointSize(10);
        font.setBold(true);
        pushButton_supprimer->setFont(font);
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("#pushButton_supprimer{\n"
"color: rgb(0, 0, 0);\n"
"border-radius:10px;\n"
"background:transparent;\n"
"}"));
        pushButton_modifier = new QPushButton(tab);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(730, 290, 75, 31));
        pushButton_modifier->setFont(font);
        pushButton_modifier->setStyleSheet(QString::fromUtf8("#pushButton_modifier{\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
"background:#619D80;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        graphicsView = new QGraphicsView(tab_2);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(20, 30, 381, 251));
        graphicsView->setStyleSheet(QString::fromUtf8(""));
        pushButton_calculer = new QPushButton(tab_2);
        pushButton_calculer->setObjectName("pushButton_calculer");
        pushButton_calculer->setGeometry(QRect(140, 290, 111, 31));
        pushButton_calculer->setStyleSheet(QString::fromUtf8("pushButton_calculer {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        calendarWidget = new QCalendarWidget(tab_2);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(410, 30, 291, 251));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        labelMap = new QLabel(tab_3);
        labelMap->setObjectName("labelMap");
        labelMap->setGeometry(QRect(30, 10, 49, 16));
        mapContainer = new QWidget(tab_3);
        mapContainer->setObjectName("mapContainer");
        mapContainer->setGeometry(QRect(190, 90, 381, 191));
        tabWidget->addTab(tab_3, QString());
        lineEdit_recherche = new QLineEdit(centralWidget);
        lineEdit_recherche->setObjectName("lineEdit_recherche");
        lineEdit_recherche->setGeometry(QRect(440, 10, 381, 31));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        tri = new QComboBox(centralWidget);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1130, 110, 131, 31));
        tri->setFont(font);
        tri->setStyleSheet(QString::fromUtf8("#tri\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        pushButton_rechercher = new QPushButton(centralWidget);
        pushButton_rechercher->setObjectName("pushButton_rechercher");
        pushButton_rechercher->setGeometry(QRect(830, 10, 61, 21));
        pushButton_rechercher->setFont(font);
        pushButton_rechercher->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        ExporterPDF = new QLabel(centralWidget);
        ExporterPDF->setObjectName("ExporterPDF");
        ExporterPDF->setGeometry(QRect(1140, 70, 41, 31));
        ExporterPDF->setPixmap(QPixmap(QString::fromUtf8(":/img/img/476330844_620145677092867_6932507229978630654_n-removebg-preview.png")));
        ExporterPDF->setScaledContents(true);
        pushButton_exportPDF = new QPushButton(centralWidget);
        pushButton_exportPDF->setObjectName("pushButton_exportPDF");
        pushButton_exportPDF->setGeometry(QRect(1300, 90, 61, 51));
        pushButton_exportPDF->setStyleSheet(QString::fromUtf8("#pushButton_exportPDF {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/1.png);\n"
"    qproperty-iconSize: 30px 30px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        form = new QWidget(centralWidget);
        form->setObjectName("form");
        form->setGeometry(QRect(130, 70, 341, 461));
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"}"));
        label_2 = new QLabel(form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 41, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_3 = new QLabel(form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 91, 16));
        label_3->setFont(font1);
        label_5 = new QLabel(form);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 160, 71, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(form);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 220, 101, 16));
        label_6->setFont(font1);
        label_7 = new QLabel(form);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 60, 101, 16));
        label_7->setFont(font1);
        id = new QLineEdit(form);
        id->setObjectName("id");
        id->setGeometry(QRect(140, 10, 171, 31));
        id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        place = new QLineEdit(form);
        place->setObjectName("place");
        place->setGeometry(QRect(130, 110, 181, 31));
        place->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        status = new QComboBox(form);
        status->addItem(QString());
        status->addItem(QString());
        status->addItem(QString());
        status->setObjectName("status");
        status->setGeometry(QRect(130, 210, 181, 31));
        status->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        score = new QLineEdit(form);
        score->setObjectName("score");
        score->setGeometry(QRect(130, 160, 181, 31));
        score->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        pushButton_quitter = new QPushButton(form);
        pushButton_quitter->setObjectName("pushButton_quitter");
        pushButton_quitter->setGeometry(QRect(30, 410, 75, 31));
        pushButton_quitter->setFont(font);
        pushButton_quitter->setStyleSheet(QString::fromUtf8("#pushButton_quitter{\n"
"color: rgb(0, 0, 0);\n"
"border-radius:10px;\n"
"background:transparent;\n"
"}"));
        date_time = new QDateTimeEdit(form);
        date_time->setObjectName("date_time");
        date_time->setGeometry(QRect(133, 50, 171, 31));
        date_time->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        arbitre = new QLineEdit(form);
        arbitre->setObjectName("arbitre");
        arbitre->setGeometry(QRect(130, 260, 181, 31));
        arbitre->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        label_8 = new QLabel(form);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 270, 101, 16));
        label_8->setFont(font1);
        pushButton_ajouter = new QPushButton(form);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(210, 410, 75, 31));
        pushButton_ajouter->setFont(font);
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("#pushButton_ajouter{\n"
"color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"padding: 5px;\n"
"background:#619D80;\n"
"}\n"
""));
        label_10 = new QLabel(form);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 330, 101, 16));
        label_10->setFont(font1);
        label_11 = new QLabel(form);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(210, 330, 101, 16));
        label_11->setFont(font1);
        team1 = new QLineEdit(form);
        team1->setObjectName("team1");
        team1->setGeometry(QRect(20, 360, 111, 31));
        team1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        team2 = new QLineEdit(form);
        team2->setObjectName("team2");
        team2->setGeometry(QRect(200, 360, 121, 31));
        team2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        label_12 = new QLabel(form);
        label_12->setObjectName("label_12");
        label_12->setEnabled(true);
        label_12->setGeometry(QRect(140, 360, 51, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setUnderline(true);
        label_12->setFont(font2);
        pushButton_superviser = new QPushButton(centralWidget);
        pushButton_superviser->setObjectName("pushButton_superviser");
        pushButton_superviser->setGeometry(QRect(1064, 10, 141, 24));
        pushButton_superviser->setFont(font);
        dark = new QPushButton(centralWidget);
        dark->setObjectName("dark");
        dark->setGeometry(QRect(130, 550, 91, 31));
        dark->setFont(font);
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
        light = new QPushButton(centralWidget);
        light->setObjectName("light");
        light->setGeometry(QRect(20, 550, 91, 31));
        light->setFont(font);
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
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1501, 691));
        label->setStyleSheet(QString::fromUtf8("#label {\n"
"    background-image:url(:/img/img/bg.jpg);\n"
"}\n"
""));
        home = new QPushButton(centralWidget);
        home->setObjectName("home");
        home->setGeometry(QRect(1350, 630, 93, 29));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        home->setFont(font3);
        home->setStyleSheet(QString::fromUtf8("#home{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        MainWindowMatch->setCentralWidget(centralWidget);
        label->raise();
        menu->raise();
        logo->raise();
        tabWidget->raise();
        lineEdit_recherche->raise();
        tri->raise();
        pushButton_rechercher->raise();
        ExporterPDF->raise();
        pushButton_exportPDF->raise();
        form->raise();
        pushButton_superviser->raise();
        dark->raise();
        light->raise();
        home->raise();
        menuBar = new QMenuBar(MainWindowMatch);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1496, 26));
        MainWindowMatch->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowMatch);
        mainToolBar->setObjectName("mainToolBar");
        MainWindowMatch->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowMatch);
        statusBar->setObjectName("statusBar");
        MainWindowMatch->setStatusBar(statusBar);

        retranslateUi(MainWindowMatch);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowMatch);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowMatch)
    {
        MainWindowMatch->setWindowTitle(QCoreApplication::translate("MainWindowMatch", "Gestion des Clients", nullptr));
        supp_btn->setText(QString());
        joueur_btn->setText(QString());
        equipe_btn->setText(QString());
        arbitre_btn->setText(QString());
        match_btn->setText(QString());
        billet_btn->setText(QString());
        logo->setText(QString());
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("MainWindowMatch", "<html><head/><body><p><img src=\":/img/img/background.jpg\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        radioButton_2->setText(QCoreApplication::translate("MainWindowMatch", "Night", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindowMatch", "Light", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindowMatch", "Delete", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindowMatch", "Modify", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindowMatch", "Tab 1", nullptr));
#if QT_CONFIG(whatsthis)
        tab_2->setWhatsThis(QCoreApplication::translate("MainWindowMatch", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_calculer->setText(QCoreApplication::translate("MainWindowMatch", "Calculer score", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindowMatch", "Tab 2", nullptr));
        labelMap->setText(QCoreApplication::translate("MainWindowMatch", "MAP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindowMatch", "Page", nullptr));
        lineEdit_recherche->setPlaceholderText(QCoreApplication::translate("MainWindowMatch", "Search...", nullptr));
        tri->setPlaceholderText(QCoreApplication::translate("MainWindowMatch", "Filtrer", nullptr));
        pushButton_rechercher->setText(QCoreApplication::translate("MainWindowMatch", "search", nullptr));
        ExporterPDF->setText(QString());
        pushButton_exportPDF->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindowMatch", "ID:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindowMatch", "Place :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindowMatch", "Score :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindowMatch", "Status :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindowMatch", "Date_time :", nullptr));
        status->setItemText(0, QCoreApplication::translate("MainWindowMatch", "scheduled", nullptr));
        status->setItemText(1, QCoreApplication::translate("MainWindowMatch", "completed", nullptr));
        status->setItemText(2, QCoreApplication::translate("MainWindowMatch", "ongoing", nullptr));

        pushButton_quitter->setText(QCoreApplication::translate("MainWindowMatch", "cancel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindowMatch", "arbitre :", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindowMatch", "add", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindowMatch", "Team1", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindowMatch", "Team2", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindowMatch", "VS", nullptr));
        pushButton_superviser->setText(QCoreApplication::translate("MainWindowMatch", "superviser", nullptr));
        dark->setText(QCoreApplication::translate("MainWindowMatch", "dark", nullptr));
        light->setText(QCoreApplication::translate("MainWindowMatch", "Light", nullptr));
        label->setText(QString());
        home->setText(QCoreApplication::translate("MainWindowMatch", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowMatch: public Ui_MainWindowMatch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_MATCH_H
