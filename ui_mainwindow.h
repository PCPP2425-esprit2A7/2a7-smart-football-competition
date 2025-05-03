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

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *background;
    QWidget *menu;
    QLabel *arbitres;
    QLabel *match;
    QLabel *billets;
    QLabel *joueurs;
    QLabel *label;
    QLabel *equipes;
    QLabel *logo;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *background_2;
    QTableView *tableView;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_modifier;
    QWidget *tab_2;
    QLabel *background_3;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_calculer;
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
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_place;
    QComboBox *comboBox_status;
    QLineEdit *lineEdit_score;
    QPushButton *pushButton_quitter;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit_arb;
    QLabel *label_8;
    QPushButton *pushButton_ajouter;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *team1;
    QLineEdit *team2;
    QLabel *label_12;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1315, 759);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        background = new QLabel(centralWidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1161, 681));
        background->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        background->setScaledContents(true);
        menu = new QWidget(centralWidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(20, 80, 101, 451));
        menu->setStyleSheet(QString::fromUtf8("#menu{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        arbitres = new QLabel(menu);
        arbitres->setObjectName("arbitres");
        arbitres->setGeometry(QRect(20, 230, 61, 51));
        arbitres->setPixmap(QPixmap(QString::fromUtf8(":/img/img/arbitre - Copie.png")));
        arbitres->setScaledContents(true);
        match = new QLabel(menu);
        match->setObjectName("match");
        match->setGeometry(QRect(20, 90, 61, 41));
        match->setPixmap(QPixmap(QString::fromUtf8(":/img/img/match.png")));
        match->setScaledContents(true);
        billets = new QLabel(menu);
        billets->setObjectName("billets");
        billets->setGeometry(QRect(20, 160, 61, 51));
        billets->setPixmap(QPixmap(QString::fromUtf8(":/img/img/billets - Copie.png")));
        billets->setScaledContents(true);
        joueurs = new QLabel(menu);
        joueurs->setObjectName("joueurs");
        joueurs->setGeometry(QRect(20, 300, 61, 61));
        joueurs->setPixmap(QPixmap(QString::fromUtf8(":/img/img/joueur.png")));
        joueurs->setScaledContents(true);
        label = new QLabel(menu);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 61, 41));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/supporteur.png")));
        label->setScaledContents(true);
        equipes = new QLabel(menu);
        equipes->setObjectName("equipes");
        equipes->setGeometry(QRect(20, 380, 61, 51));
        equipes->setPixmap(QPixmap(QString::fromUtf8(":/img/img/equipe.png")));
        equipes->setScaledContents(true);
        logo = new QLabel(centralWidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 0, 131, 71));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo - Copie.png")));
        logo->setScaledContents(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(420, 100, 731, 521));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab = new QWidget();
        tab->setObjectName("tab");
        background_2 = new QLabel(tab);
        background_2->setObjectName("background_2");
        background_2->setGeometry(QRect(-440, -120, 1201, 671));
        background_2->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        background_2->setScaledContents(true);
        tableView = new QTableView(tab);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 20, 701, 221));
        tableView->setStyleSheet(QString::fromUtf8("#tableView{\n"
"background:rgba(33,133,85,0.4);\n"
"border-radius:10px;\n"
"padding:5px;\n"
"}"));
        radioButton_2 = new QRadioButton(tab);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(930, 480, 89, 20));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(830, 480, 89, 20));
        pushButton_supprimer = new QPushButton(tab);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(580, 250, 75, 31));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("#pushButton_ajouter{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        pushButton_modifier = new QPushButton(tab);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(490, 250, 75, 31));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("#pushButton_ajouter{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        background_3 = new QLabel(tab_2);
        background_3->setObjectName("background_3");
        background_3->setGeometry(QRect(-420, -120, 1161, 671));
        background_3->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        background_3->setScaledContents(true);
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
        lineEdit_recherche->setGeometry(QRect(450, 20, 381, 31));
        lineEdit_recherche->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        tri = new QComboBox(centralWidget);
        tri->setObjectName("comboBoxTriDate");
        tri->setGeometry(QRect(370, 20, 71, 31));
        tri->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: none; /* Pas de bordure */\n"
"    background-color: rgb(77, 106, 121); /* Couleur de fond */\n"
"    border-radius: 15px; /* Coins arrondis */\n"
"    color: white; /* \303\211criture en blanc */\n"
"    font-weight: bold; /* Texte en gras */\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    background-color: rgb(28, 130, 255); /* Couleur de fond au survol */\n"
"    color: white; /* \303\211criture en blanc au survol */\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border: 5px solid rgb(241, 92, 34); /* Bordure lors de la mise au point */\n"
"    background-color: rgb(28, 130, 255); /* Couleur de fond lors de la mise au point */\n"
"    color: white; /* \303\211criture en blanc lors de la mise au point */\n"
"}"));
        pushButton_rechercher = new QPushButton(centralWidget);
        pushButton_rechercher->setObjectName("pushButton_rechercher");
        pushButton_rechercher->setGeometry(QRect(840, 20, 71, 31));
        pushButton_rechercher->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        ExporterPDF = new QLabel(centralWidget);
        ExporterPDF->setObjectName("ExporterPDF");
        ExporterPDF->setGeometry(QRect(1060, 30, 41, 31));
        ExporterPDF->setPixmap(QPixmap(QString::fromUtf8(":/img/img/476330844_620145677092867_6932507229978630654_n-removebg-preview.png")));
        ExporterPDF->setScaledContents(true);
        pushButton_exportPDF = new QPushButton(centralWidget);
        pushButton_exportPDF->setObjectName("pushButton_exportPDF");
        pushButton_exportPDF->setGeometry(QRect(1050, 70, 61, 20));
        pushButton_exportPDF->setStyleSheet(QString::fromUtf8("QPushButton_exportPDF {\n"
"	color: qlineargradient(spread:repeat, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.17 rgba(255, 0, 0, 255), stop:0.18 rgba(255, 255, 255, 255), stop:0.210212 rgba(255, 255, 255, 255), stop:0.220212 rgba(0, 16, 255, 255), stop:0.279897 rgba(0, 16, 255, 255), stop:0.289897 rgba(255, 255, 255, 255), stop:0.32 rgba(255, 255, 255, 255), stop:0.33 rgba(255, 0, 0, 255), stop:1 rgba(255, 0, 0, 255));\n"
"    background-color: #B22222; /* Fond rouge brique */\n"
"}\n"
"\n"
"\n"
""));
        form = new QWidget(centralWidget);
        form->setObjectName("form");
        form->setGeometry(QRect(130, 80, 281, 461));
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"}"));
        label_2 = new QLabel(form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 41, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        label_2->setFont(font);
        label_3 = new QLabel(form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 120, 91, 16));
        label_3->setFont(font);
        label_5 = new QLabel(form);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 160, 71, 31));
        label_5->setFont(font);
        label_6 = new QLabel(form);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 220, 101, 16));
        label_6->setFont(font);
        label_7 = new QLabel(form);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 50, 91, 16));
        label_7->setFont(font);
        lineEdit_id = new QLineEdit(form);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(70, 10, 131, 31));
        lineEdit_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        lineEdit_place = new QLineEdit(form);
        lineEdit_place->setObjectName("lineEdit_place");
        lineEdit_place->setGeometry(QRect(80, 110, 131, 31));
        lineEdit_place->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        comboBox_status = new QComboBox(form);
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->addItem(QString());
        comboBox_status->setObjectName("comboBox_status");
        comboBox_status->setGeometry(QRect(80, 210, 131, 31));
        comboBox_status->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        lineEdit_score = new QLineEdit(form);
        lineEdit_score->setObjectName("lineEdit_score");
        lineEdit_score->setGeometry(QRect(80, 160, 131, 31));
        lineEdit_score->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        pushButton_quitter = new QPushButton(form);
        pushButton_quitter->setObjectName("pushButton_quitter");
        pushButton_quitter->setGeometry(QRect(110, 420, 75, 31));
        pushButton_quitter->setStyleSheet(QString::fromUtf8("#pushButton_quitter{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        dateTimeEdit = new QDateTimeEdit(form);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(30, 70, 194, 31));
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        lineEdit_arb = new QLineEdit(form);
        lineEdit_arb->setObjectName("lineEdit_arb");
        lineEdit_arb->setGeometry(QRect(80, 260, 131, 31));
        lineEdit_arb->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        label_8 = new QLabel(form);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 270, 101, 16));
        label_8->setFont(font);
        pushButton_ajouter = new QPushButton(form);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(190, 420, 75, 31));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("#pushButton_ajouter{\n"
"background-color:#218555;\n"
"border-radius10px;\n"
"padding:5px\n"
"}"));
        label_10 = new QLabel(form);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 340, 101, 16));
        label_10->setFont(font);
        label_11 = new QLabel(form);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(180, 340, 101, 16));
        label_11->setFont(font);
        team1 = new QLineEdit(form);
        team1->setObjectName("team1");
        team1->setGeometry(QRect(0, 360, 111, 31));
        team1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}"));
        team2 = new QLineEdit(form);
        team2->setObjectName("team2");
        team2->setGeometry(QRect(150, 360, 121, 31));
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
        label_12->setGeometry(QRect(120, 346, 21, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setUnderline(true);
        label_12->setFont(font1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1315, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        background->setText(QString());
        arbitres->setText(QString());
        match->setText(QString());
        billets->setText(QString());
        joueurs->setText(QString());
        label->setText(QString());
        equipes->setText(QString());
        logo->setText(QString());
#if QT_CONFIG(tooltip)
        tabWidget->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/img/img/background.jpg\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        background_2->setText(QString());
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Night", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
#if QT_CONFIG(whatsthis)
        tab_2->setWhatsThis(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        background_3->setText(QString());
        pushButton_calculer->setText(QCoreApplication::translate("MainWindow", "Calculer score", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        labelMap->setText(QCoreApplication::translate("MainWindow", "MAP", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Page", nullptr));
        lineEdit_recherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
        tri->setPlaceholderText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        pushButton_rechercher->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        ExporterPDF->setText(QString());
        pushButton_exportPDF->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Place :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Score :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Status :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Date_time :", nullptr));
        comboBox_status->setItemText(0, QCoreApplication::translate("MainWindow", "scheduled", nullptr));
        comboBox_status->setItemText(1, QCoreApplication::translate("MainWindow", "completed", nullptr));
        comboBox_status->setItemText(2, QCoreApplication::translate("MainWindow", "ongoing", nullptr));

        pushButton_quitter->setText(QCoreApplication::translate("MainWindow", "cancel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "arbitre :", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Aad", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Team1", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Team2", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "VS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
