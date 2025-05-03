/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *background;
    QLabel *logo;
    QLabel *menu;
    QLabel *supporteur;
    QLabel *joueur;
    QLabel *arbitre;
    QLabel *match;
    QLabel *equipe;
    QLabel *billet;
    QLabel *form;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QComboBox *comboBox;
    QLineEdit *lineEdit_rechercher;
    QComboBox *comboBox_tri;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_modifier;
    QPushButton *pushButton_supprimer;
    QTableView *tableView;
    QLabel *label_9;
    QRadioButton *radioButton_night;
    QRadioButton *radioButton_light;
    QPushButton *pushButton_statistiques;
    QPushButton *PDF;
    QPushButton *btn_ouvrirEmailDialog;
    QPushButton *pushButton_guess;
    QLabel *label_resultat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1318, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1311, 541));
        background->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        background->setScaledContents(true);
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 20, 161, 81));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        logo->setScaledContents(true);
        menu = new QLabel(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(40, 110, 71, 411));
        menu->setStyleSheet(QString::fromUtf8("#menu{\n"
"background-color:#218555;\n"
"border-radius:10px;\n"
" padding:5px;\n"
"}"));
        supporteur = new QLabel(centralwidget);
        supporteur->setObjectName("supporteur");
        supporteur->setGeometry(QRect(60, 130, 31, 41));
        supporteur->setPixmap(QPixmap(QString::fromUtf8(":/img/img/supporteur.png")));
        supporteur->setScaledContents(true);
        joueur = new QLabel(centralwidget);
        joueur->setObjectName("joueur");
        joueur->setGeometry(QRect(50, 190, 51, 51));
        joueur->setPixmap(QPixmap(QString::fromUtf8(":/img/img/joueur.png")));
        joueur->setScaledContents(true);
        arbitre = new QLabel(centralwidget);
        arbitre->setObjectName("arbitre");
        arbitre->setGeometry(QRect(50, 260, 51, 41));
        arbitre->setPixmap(QPixmap(QString::fromUtf8(":/img/img/arbitre.png")));
        arbitre->setScaledContents(true);
        match = new QLabel(centralwidget);
        match->setObjectName("match");
        match->setGeometry(QRect(60, 400, 31, 41));
        match->setPixmap(QPixmap(QString::fromUtf8(":/img/img/match.png")));
        match->setScaledContents(true);
        equipe = new QLabel(centralwidget);
        equipe->setObjectName("equipe");
        equipe->setGeometry(QRect(50, 330, 51, 41));
        equipe->setPixmap(QPixmap(QString::fromUtf8(":/img/img/equipe.png")));
        equipe->setScaledContents(true);
        billet = new QLabel(centralwidget);
        billet->setObjectName("billet");
        billet->setGeometry(QRect(50, 460, 51, 41));
        billet->setPixmap(QPixmap(QString::fromUtf8(":/img/img/ticket.png")));
        billet->setScaledContents(true);
        form = new QLabel(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(152, 119, 271, 401));
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214,215,222,0.4);\n"
"border-radius:10px;\n"
" padding:5px;}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 150, 63, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setScaledContents(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 190, 63, 20));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 240, 111, 21));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 290, 63, 20));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 330, 121, 31));
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(170, 390, 121, 21));
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 440, 121, 21));
        label_7->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(300, 150, 111, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(300, 190, 111, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("#lineEdit_2 { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(300, 240, 111, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("#lineEdit_3 { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(300, 290, 113, 31));
        lineEdit_4->setStyleSheet(QString::fromUtf8("#lineEdit_4 { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(300, 340, 113, 31));
        lineEdit_5->setStyleSheet(QString::fromUtf8("#lineEdit_5 { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(300, 380, 113, 31));
        lineEdit_6->setStyleSheet(QString::fromUtf8("#lineEdit_6 { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(300, 430, 111, 26));
        comboBox->setStyleSheet(QString::fromUtf8("#comboBox { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        lineEdit_rechercher = new QLineEdit(centralwidget);
        lineEdit_rechercher->setObjectName("lineEdit_rechercher");
        lineEdit_rechercher->setGeometry(QRect(510, 20, 511, 41));
        lineEdit_rechercher->setStyleSheet(QString::fromUtf8("#lineEdit_7 { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        comboBox_tri = new QComboBox(centralwidget);
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(1150, 70, 121, 26));
        comboBox_tri->setStyleSheet(QString::fromUtf8("#lineEdit { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(320, 480, 93, 29));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(11);
        font1.setBold(true);
        pushButton_ajouter->setFont(font1);
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("#pushButton_ajouter{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(210, 480, 93, 29));
        pushButton_cancel->setFont(font1);
        pushButton_cancel->setStyleSheet(QString::fromUtf8("#cancel{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        pushButton_modifier = new QPushButton(centralwidget);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(1180, 330, 93, 29));
        pushButton_modifier->setFont(font1);
        pushButton_modifier->setStyleSheet(QString::fromUtf8("#pushButton_modifier{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(1070, 330, 93, 29));
        pushButton_supprimer->setFont(font1);
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("#pushButton_supprimer{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(480, 120, 791, 192));
        tableView->setStyleSheet(QString::fromUtf8("#tableView{\n"
"background:rgba(33,133,85,0.4);\n"
"border-radius:10px;\n"
"padding:5px;\n"
"}"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(980, 30, 21, 21));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/img/img/icons8-search-50.png")));
        label_9->setScaledContents(true);
        radioButton_night = new QRadioButton(centralwidget);
        radioButton_night->setObjectName("radioButton_night");
        radioButton_night->setGeometry(QRect(1160, 500, 110, 24));
        radioButton_night->setFont(font1);
        radioButton_light = new QRadioButton(centralwidget);
        radioButton_light->setObjectName("radioButton_light");
        radioButton_light->setGeometry(QRect(1020, 500, 110, 24));
        radioButton_light->setFont(font1);
        radioButton_light->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        pushButton_statistiques = new QPushButton(centralwidget);
        pushButton_statistiques->setObjectName("pushButton_statistiques");
        pushButton_statistiques->setGeometry(QRect(1080, 380, 191, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(10);
        font2.setBold(true);
        pushButton_statistiques->setFont(font2);
        pushButton_statistiques->setStyleSheet(QString::fromUtf8("#pushButton_statistiques{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        PDF = new QPushButton(centralwidget);
        PDF->setObjectName("PDF");
        PDF->setGeometry(QRect(1150, 20, 51, 31));
        PDF->setFont(font2);
        PDF->setStyleSheet(QString::fromUtf8("#PDF{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        btn_ouvrirEmailDialog = new QPushButton(centralwidget);
        btn_ouvrirEmailDialog->setObjectName("btn_ouvrirEmailDialog");
        btn_ouvrirEmailDialog->setGeometry(QRect(1200, 20, 93, 29));
        pushButton_guess = new QPushButton(centralwidget);
        pushButton_guess->setObjectName("pushButton_guess");
        pushButton_guess->setGeometry(QRect(480, 480, 93, 29));
        pushButton_guess->setFont(font2);
        pushButton_guess->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        label_resultat = new QLabel(centralwidget);
        label_resultat->setObjectName("label_resultat");
        label_resultat->setGeometry(QRect(490, 379, 271, 101));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1318, 26));
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
        background->setText(QString());
        logo->setText(QString());
        menu->setText(QString());
        supporteur->setText(QString());
        joueur->setText(QString());
        arbitre->setText(QString());
        match->setText(QString());
        equipe->setText(QString());
        billet->setText(QString());
        form->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "id", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "last_name", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "nb_carton", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "nb_match_a", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "category", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "a.touch", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "a.principale", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "a.changement", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "a.var", nullptr));

        lineEdit_rechercher->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recherche par nom", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainWindow", "a.principale", nullptr));
        comboBox_tri->setItemText(1, QCoreApplication::translate("MainWindow", "a.changement", nullptr));
        comboBox_tri->setItemText(2, QCoreApplication::translate("MainWindow", "a.var", nullptr));
        comboBox_tri->setItemText(3, QCoreApplication::translate("MainWindow", "a.touch", nullptr));

        comboBox_tri->setPlaceholderText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "cancel", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "modify", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        label_9->setText(QString());
        radioButton_night->setText(QCoreApplication::translate("MainWindow", "Night", nullptr));
        radioButton_light->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        pushButton_statistiques->setText(QCoreApplication::translate("MainWindow", "Voir les statistiques", nullptr));
        PDF->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        btn_ouvrirEmailDialog->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        pushButton_guess->setText(QCoreApplication::translate("MainWindow", "Guess", nullptr));
        label_resultat->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
