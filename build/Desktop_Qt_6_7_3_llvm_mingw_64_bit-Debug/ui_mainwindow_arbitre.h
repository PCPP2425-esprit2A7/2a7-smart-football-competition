/********************************************************************************
** Form generated from reading UI file 'mainwindow_arbitre.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_ARBITRE_H
#define UI_MAINWINDOW_ARBITRE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
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
    QLabel *logo;
    QLabel *menu;
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
    QPushButton *pushButton_statistiques;
    QPushButton *PDF;
    QPushButton *btn_ouvrirEmailDialog;
    QPushButton *pushButton_guess;
    QLabel *label_resultat;
    QPushButton *pushButton_Historique;
    QPushButton *btn_test_voice;
    QPushButton *light;
    QPushButton *dark;
    QPushButton *bouton_supporteur_arbitre;
    QPushButton *bouton_match_arbitre;
    QPushButton *bouton_arbitre_arbitre;
    QPushButton *bouton_joueur_arbitre;
    QPushButton *bouton_billet_arbitre;
    QPushButton *bouton_equipe_arbitre;
    QLabel *bg;
    QWidget *form;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1406, 716);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 0, 161, 91));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        logo->setScaledContents(true);
        menu = new QLabel(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(30, 110, 91, 441));
        menu->setStyleSheet(QString::fromUtf8("/*#menu{\n"
"background-color:#218555;\n"
"border-radius:10px;\n"
" padding:5px;\n"
"}*/\n"
"#menu {\n"
"background-color: #619D80;}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 140, 63, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);
        label->setScaledContents(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 200, 63, 20));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 250, 111, 21));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 300, 63, 20));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(180, 350, 121, 31));
        label_5->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 410, 121, 21));
        label_6->setFont(font);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(180, 460, 121, 21));
        label_7->setFont(font);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(360, 140, 121, 31));
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
        lineEdit_2->setGeometry(QRect(360, 190, 121, 31));
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
        lineEdit_3->setGeometry(QRect(360, 240, 121, 31));
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
        lineEdit_4->setGeometry(QRect(362, 300, 121, 31));
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
        lineEdit_5->setGeometry(QRect(362, 350, 121, 31));
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
        lineEdit_6->setGeometry(QRect(362, 400, 121, 31));
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
        comboBox->setGeometry(QRect(360, 450, 121, 26));
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
        lineEdit_rechercher->setGeometry(QRect(380, 10, 591, 41));
        lineEdit_rechercher->setStyleSheet(QString::fromUtf8("#lineEdit_rechercher { \n"
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
        comboBox_tri->setGeometry(QRect(1180, 60, 151, 31));
        comboBox_tri->setStyleSheet(QString::fromUtf8("#comboBox_tri{ \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
"\n"
""));
        pushButton_ajouter = new QPushButton(centralwidget);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(310, 510, 93, 29));
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
        pushButton_cancel->setGeometry(QRect(200, 510, 93, 29));
        pushButton_cancel->setFont(font1);
        pushButton_cancel->setStyleSheet(QString::fromUtf8("#pushButton_cancel{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        pushButton_modifier = new QPushButton(centralwidget);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(1280, 500, 93, 29));
        pushButton_modifier->setFont(font1);
        pushButton_modifier->setStyleSheet(QString::fromUtf8("#pushButton_modifier{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(1170, 500, 93, 29));
        pushButton_supprimer->setFont(font1);
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("#pushButton_supprimer{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(530, 110, 851, 381));
        tableView->setStyleSheet(QString::fromUtf8("#tableView{\n"
"background:rgba(33,133,85,0.4);\n"
"border-radius:10px;\n"
"padding:5px;\n"
"}"));
        pushButton_statistiques = new QPushButton(centralwidget);
        pushButton_statistiques->setObjectName("pushButton_statistiques");
        pushButton_statistiques->setGeometry(QRect(1280, 20, 111, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(9);
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
        PDF->setGeometry(QRect(1340, 60, 51, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Arial")});
        font3.setPointSize(10);
        font3.setBold(true);
        PDF->setFont(font3);
        PDF->setStyleSheet(QString::fromUtf8("#PDF{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::Printer));
        PDF->setIcon(icon);
        btn_ouvrirEmailDialog = new QPushButton(centralwidget);
        btn_ouvrirEmailDialog->setObjectName("btn_ouvrirEmailDialog");
        btn_ouvrirEmailDialog->setGeometry(QRect(1140, 20, 51, 31));
        btn_ouvrirEmailDialog->setStyleSheet(QString::fromUtf8("#btn_ouvrirEmailDialog{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::MailForward));
        btn_ouvrirEmailDialog->setIcon(icon1);
        pushButton_guess = new QPushButton(centralwidget);
        pushButton_guess->setObjectName("pushButton_guess");
        pushButton_guess->setGeometry(QRect(960, 500, 93, 29));
        pushButton_guess->setFont(font3);
        pushButton_guess->setStyleSheet(QString::fromUtf8("#pushButton_guess{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::GoNext));
        pushButton_guess->setIcon(icon2);
        label_resultat = new QLabel(centralwidget);
        label_resultat->setObjectName("label_resultat");
        label_resultat->setGeometry(QRect(530, 500, 431, 81));
        label_resultat->setStyleSheet(QString::fromUtf8("#label_resultat { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        pushButton_Historique = new QPushButton(centralwidget);
        pushButton_Historique->setObjectName("pushButton_Historique");
        pushButton_Historique->setGeometry(QRect(1180, 20, 91, 31));
        pushButton_Historique->setFont(font2);
        pushButton_Historique->setStyleSheet(QString::fromUtf8("#pushButton_Historique{\n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"\n"
"\n"
"}"));
        btn_test_voice = new QPushButton(centralwidget);
        btn_test_voice->setObjectName("btn_test_voice");
        btn_test_voice->setGeometry(QRect(880, 20, 93, 29));
        btn_test_voice->setStyleSheet(QString::fromUtf8("#btn_test_voice{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::AudioInputMicrophone));
        btn_test_voice->setIcon(icon3);
        light = new QPushButton(centralwidget);
        light->setObjectName("light");
        light->setGeometry(QRect(10, 570, 93, 29));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setBold(true);
        light->setFont(font4);
        light->setStyleSheet(QString::fromUtf8("#light{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        dark = new QPushButton(centralwidget);
        dark->setObjectName("dark");
        dark->setGeometry(QRect(100, 570, 93, 29));
        dark->setFont(font4);
        bouton_supporteur_arbitre = new QPushButton(centralwidget);
        bouton_supporteur_arbitre->setObjectName("bouton_supporteur_arbitre");
        bouton_supporteur_arbitre->setGeometry(QRect(40, 120, 81, 61));
        bouton_supporteur_arbitre->setStyleSheet(QString::fromUtf8("#bouton_supporteur_arbitre {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/supporteur.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/supporteur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        bouton_supporteur_arbitre->setIcon(icon4);
        bouton_supporteur_arbitre->setIconSize(QSize(64, 64));
        bouton_match_arbitre = new QPushButton(centralwidget);
        bouton_match_arbitre->setObjectName("bouton_match_arbitre");
        bouton_match_arbitre->setGeometry(QRect(40, 430, 71, 61));
        bouton_match_arbitre->setStyleSheet(QString::fromUtf8("#bouton_match_arbitre {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/match.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/match.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        bouton_match_arbitre->setIcon(icon5);
        bouton_match_arbitre->setIconSize(QSize(64, 64));
        bouton_arbitre_arbitre = new QPushButton(centralwidget);
        bouton_arbitre_arbitre->setObjectName("bouton_arbitre_arbitre");
        bouton_arbitre_arbitre->setGeometry(QRect(30, 270, 91, 71));
        bouton_arbitre_arbitre->setStyleSheet(QString::fromUtf8("#bouton_arbitre_arbitre {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/arbitre.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/img/arbitre.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        bouton_arbitre_arbitre->setIcon(icon6);
        bouton_arbitre_arbitre->setIconSize(QSize(64, 64));
        bouton_joueur_arbitre = new QPushButton(centralwidget);
        bouton_joueur_arbitre->setObjectName("bouton_joueur_arbitre");
        bouton_joueur_arbitre->setGeometry(QRect(30, 190, 91, 81));
        bouton_joueur_arbitre->setStyleSheet(QString::fromUtf8("#bouton_joueur_arbitre{\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/joueur.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/joueur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        bouton_joueur_arbitre->setIcon(icon7);
        bouton_joueur_arbitre->setIconSize(QSize(64, 64));
        bouton_billet_arbitre = new QPushButton(centralwidget);
        bouton_billet_arbitre->setObjectName("bouton_billet_arbitre");
        bouton_billet_arbitre->setGeometry(QRect(30, 500, 91, 51));
        bouton_billet_arbitre->setStyleSheet(QString::fromUtf8("#bouton_billet_arbitre {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/ticket.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/ticket.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        bouton_billet_arbitre->setIcon(icon8);
        bouton_billet_arbitre->setIconSize(QSize(64, 64));
        bouton_equipe_arbitre = new QPushButton(centralwidget);
        bouton_equipe_arbitre->setObjectName("bouton_equipe_arbitre");
        bouton_equipe_arbitre->setGeometry(QRect(30, 350, 93, 71));
        bouton_equipe_arbitre->setStyleSheet(QString::fromUtf8("#bouton_equipe_arbitre {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/equipe.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/img/equipe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        bouton_equipe_arbitre->setIcon(icon9);
        bouton_equipe_arbitre->setIconSize(QSize(64, 64));
        bg = new QLabel(centralwidget);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(-10, 0, 1421, 721));
        bg->setStyleSheet(QString::fromUtf8("#bg{\n"
"background-image:url(:/img/img/background.jpg);\n"
"}"));
        form = new QWidget(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(160, 120, 331, 431));
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;}"));
        MainWindow->setCentralWidget(centralwidget);
        bg->raise();
        form->raise();
        logo->raise();
        menu->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        lineEdit_4->raise();
        lineEdit_5->raise();
        lineEdit_6->raise();
        comboBox->raise();
        lineEdit_rechercher->raise();
        comboBox_tri->raise();
        pushButton_ajouter->raise();
        pushButton_cancel->raise();
        pushButton_modifier->raise();
        pushButton_supprimer->raise();
        tableView->raise();
        pushButton_statistiques->raise();
        PDF->raise();
        btn_ouvrirEmailDialog->raise();
        pushButton_guess->raise();
        label_resultat->raise();
        pushButton_Historique->raise();
        btn_test_voice->raise();
        light->raise();
        dark->raise();
        bouton_supporteur_arbitre->raise();
        bouton_match_arbitre->raise();
        bouton_arbitre_arbitre->raise();
        bouton_joueur_arbitre->raise();
        bouton_billet_arbitre->raise();
        bouton_equipe_arbitre->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1406, 26));
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
        logo->setText(QString());
        menu->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "last_name", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nb_carton", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nb_match_a", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
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
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        pushButton_statistiques->setText(QCoreApplication::translate("MainWindow", "Report statics", nullptr));
        PDF->setText(QString());
        btn_ouvrirEmailDialog->setText(QString());
        pushButton_guess->setText(QString());
        label_resultat->setText(QString());
        pushButton_Historique->setText(QCoreApplication::translate("MainWindow", "Historique", nullptr));
        btn_test_voice->setText(QString());
        light->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        dark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        bouton_supporteur_arbitre->setText(QString());
        bouton_match_arbitre->setText(QString());
        bouton_arbitre_arbitre->setText(QString());
        bouton_joueur_arbitre->setText(QString());
        bouton_billet_arbitre->setText(QString());
        bouton_equipe_arbitre->setText(QString());
        bg->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_ARBITRE_H
