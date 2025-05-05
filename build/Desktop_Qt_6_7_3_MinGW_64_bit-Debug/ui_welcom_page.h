/********************************************************************************
** Form generated from reading UI file 'welcom_page.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOM_PAGE_H
#define UI_WELCOM_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcom_page
{
public:
    QLabel *bg;
    QLabel *logo;
    QPushButton *supporteur;
    QPushButton *arbitre;
    QPushButton *joueur;
    QPushButton *equipe;
    QPushButton *match;
    QPushButton *billet;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QWidget *welcom_page)
    {
        if (welcom_page->objectName().isEmpty())
            welcom_page->setObjectName("welcom_page");
        welcom_page->resize(1535, 767);
        bg = new QLabel(welcom_page);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(0, 0, 1551, 761));
        bg->setStyleSheet(QString::fromUtf8("#bg {\n"
"  background-color: #e0f7e9;\n"
"}\n"
""));
        logo = new QLabel(welcom_page);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 0, 681, 381));
        logo->setStyleSheet(QString::fromUtf8(""));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo_yedkom-removebg.png")));
        logo->setScaledContents(true);
        supporteur = new QPushButton(welcom_page);
        supporteur->setObjectName("supporteur");
        supporteur->setGeometry(QRect(230, 350, 121, 141));
        supporteur->setStyleSheet(QString::fromUtf8("#supporteur {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/2.png);\n"
"    qproperty-iconSize: 80px 80px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        arbitre = new QPushButton(welcom_page);
        arbitre->setObjectName("arbitre");
        arbitre->setGeometry(QRect(240, 550, 121, 121));
        arbitre->setStyleSheet(QString::fromUtf8("#arbitre {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/carte-jaune.png);\n"
"    qproperty-iconSize: 80px 80px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        joueur = new QPushButton(welcom_page);
        joueur->setObjectName("joueur");
        joueur->setGeometry(QRect(650, 360, 151, 121));
        joueur->setStyleSheet(QString::fromUtf8("#joueur\n"
" {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/joueur-de-football.png);\n"
"    qproperty-iconSize: 80px 80px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        equipe = new QPushButton(welcom_page);
        equipe->setObjectName("equipe");
        equipe->setGeometry(QRect(1070, 360, 171, 121));
        equipe->setStyleSheet(QString::fromUtf8("#equipe {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/4.png);\n"
"    qproperty-iconSize: 80px 80px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        match = new QPushButton(welcom_page);
        match->setObjectName("match");
        match->setGeometry(QRect(650, 540, 151, 121));
        match->setStyleSheet(QString::fromUtf8("#match {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/3.png);\n"
"    qproperty-iconSize: 80px 80px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        billet = new QPushButton(welcom_page);
        billet->setObjectName("billet");
        billet->setGeometry(QRect(1090, 540, 171, 131));
        billet->setStyleSheet(QString::fromUtf8("#billet {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/billet.png);\n"
"    qproperty-iconSize: 80px 80px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        label = new QLabel(welcom_page);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 490, 81, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        font.setPointSize(19);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(welcom_page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(660, 490, 221, 41));
        label_2->setFont(font);
        label_3 = new QLabel(welcom_page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1110, 490, 221, 41));
        label_3->setFont(font);
        label_4 = new QLabel(welcom_page);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(240, 670, 221, 41));
        label_4->setFont(font);
        label_5 = new QLabel(welcom_page);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(670, 660, 221, 41));
        label_5->setFont(font);
        label_6 = new QLabel(welcom_page);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1110, 660, 131, 41));
        label_6->setFont(font);
        label_7 = new QLabel(welcom_page);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(800, 90, 471, 271));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sylfaen")});
        font1.setPointSize(23);
        label_7->setFont(font1);

        retranslateUi(welcom_page);

        QMetaObject::connectSlotsByName(welcom_page);
    } // setupUi

    void retranslateUi(QWidget *welcom_page)
    {
        welcom_page->setWindowTitle(QCoreApplication::translate("welcom_page", "Form", nullptr));
        bg->setText(QString());
        logo->setText(QString());
        supporteur->setText(QString());
        arbitre->setText(QString());
        joueur->setText(QString());
        equipe->setText(QString());
        match->setText(QString());
        billet->setText(QString());
        label->setText(QCoreApplication::translate("welcom_page", "FAN", nullptr));
        label_2->setText(QCoreApplication::translate("welcom_page", "PLAYER", nullptr));
        label_3->setText(QCoreApplication::translate("welcom_page", "TEAM", nullptr));
        label_4->setText(QCoreApplication::translate("welcom_page", "REFEREE", nullptr));
        label_5->setText(QCoreApplication::translate("welcom_page", "MATCH", nullptr));
        label_6->setText(QCoreApplication::translate("welcom_page", "TICKETS", nullptr));
        label_7->setText(QCoreApplication::translate("welcom_page", "WELCOM\n"
"MANAGE YOUR TEAM\n"
"TRACK MATCHES\n"
"DOMINATE THE LEAGUE\n"
"", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcom_page: public Ui_welcom_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOM_PAGE_H
