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
    QLabel *background;
    QLabel *logo;
    QLabel *menu;
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
    QPushButton *pushButton_statistiques;
    QPushButton *PDF;
    QPushButton *btn_ouvrirEmailDialog;
    QPushButton *pushButton_guess;
    QLabel *label_resultat;
    QPushButton *pushButton_Historique;
    QPushButton *btn_test_voice;
    QPushButton *light;
    QPushButton *dark;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1406, 716);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1641, 821));
        background->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        background->setScaledContents(true);
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
        form = new QLabel(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(140, 110, 361, 441));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(9);
        font.setBold(true);
        form->setFont(font);
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214,215,222,0.4);\n"
"border-radius:10px;\n"
" padding:5px;}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 140, 63, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        label->setFont(font1);
        label->setScaledContents(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 200, 63, 20));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 250, 111, 21));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 300, 63, 20));
        label_4->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(180, 350, 121, 31));
        label_5->setFont(font1);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(180, 410, 121, 21));
        label_6->setFont(font1);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(180, 460, 121, 21));
        label_7->setFont(font1);
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
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(11);
        font2.setBold(true);
        pushButton_ajouter->setFont(font2);
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("#pushButton_ajouter{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setGeometry(QRect(200, 510, 93, 29));
        pushButton_cancel->setFont(font2);
        pushButton_cancel->setStyleSheet(QString::fromUtf8("#pushButton_cancel{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        pushButton_modifier = new QPushButton(centralwidget);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(1280, 500, 93, 29));
        pushButton_modifier->setFont(font2);
        pushButton_modifier->setStyleSheet(QString::fromUtf8("#pushButton_modifier{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        pushButton_supprimer = new QPushButton(centralwidget);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(1170, 500, 93, 29));
        pushButton_supprimer->setFont(font2);
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
        pushButton_statistiques->setFont(font);
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
        pushButton_Historique->setFont(font);
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
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 120, 81, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("#pushButton_3{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/supporteur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_3->setIcon(icon4);
        pushButton_3->setIconSize(QSize(50, 200));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(40, 200, 71, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("#pushButton_4{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/match.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon5);
        pushButton_4->setIconSize(QSize(50, 200));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(30, 350, 91, 71));
        pushButton_5->setStyleSheet(QString::fromUtf8("#pushButton_5{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/img/arbitre.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon6);
        pushButton_5->setIconSize(QSize(60, 200));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(30, 410, 91, 81));
        pushButton_6->setStyleSheet(QString::fromUtf8("#pushButton_6{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/joueur.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon7);
        pushButton_6->setIconSize(QSize(50, 200));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(30, 500, 93, 29));
        pushButton_7->setStyleSheet(QString::fromUtf8("#pushButton_7{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/ticket.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_7->setIcon(icon8);
        pushButton_7->setIconSize(QSize(50, 200));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(30, 270, 93, 71));
        pushButton_8->setStyleSheet(QString::fromUtf8("#pushButton_8{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/img/equipe.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_8->setIcon(icon9);
        pushButton_8->setIconSize(QSize(50, 200));
        MainWindow->setCentralWidget(centralwidget);
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
        background->setText(QString());
        logo->setText(QString());
        menu->setText(QString());
        form->setText(QString());
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
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_7->setText(QString());
        pushButton_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
