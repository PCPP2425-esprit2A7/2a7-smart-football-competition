/********************************************************************************
** Form generated from reading UI file 'playersubstitutiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERSUBSTITUTIONDIALOG_H
#define UI_PLAYERSUBSTITUTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_playersubstitutiondialog
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QComboBox *team1_player1;
    QComboBox *team1_player2;
    QLabel *label_2;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QComboBox *team2_player2;
    QComboBox *team2_player1;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *ButtonBox;
    QPushButton *ButtonBox_2;

    void setupUi(QDialog *playersubstitutiondialog)
    {
        if (playersubstitutiondialog->objectName().isEmpty())
            playersubstitutiondialog->setObjectName("playersubstitutiondialog");
        playersubstitutiondialog->resize(1046, 574);
        label = new QLabel(playersubstitutiondialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1051, 571));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->setScaledContents(true);
        groupBox = new QGroupBox(playersubstitutiondialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(30, 110, 401, 211));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        font.setBold(true);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("#groupBox{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}\n"
"\n"
""));
        team1_player1 = new QComboBox(groupBox);
        team1_player1->setObjectName("team1_player1");
        team1_player1->setGeometry(QRect(190, 50, 201, 31));
        team1_player1->setStyleSheet(QString::fromUtf8("#team1_player1 {\n"
"    background-color: white;   /* White background */\n"
"    color: black;              /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;        /* Rounded edges */\n"
"    padding: 5px;              /* Inner spacing */\n"
"}"));
        team1_player2 = new QComboBox(groupBox);
        team1_player2->setObjectName("team1_player2");
        team1_player2->setGeometry(QRect(190, 130, 201, 31));
        team1_player2->setStyleSheet(QString::fromUtf8("#team1_player2{\n"
"    background-color: white;   /* White background */\n"
"    color: black;              /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;        /* Rounded edges */\n"
"    padding: 5px;              /* Inner spacing */\n"
"}"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 50, 111, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(11);
        font1.setBold(true);
        label_2->setFont(font1);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 130, 131, 21));
        label_3->setFont(font1);
        groupBox_2 = new QGroupBox(playersubstitutiondialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(550, 110, 421, 211));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("#groupBox_2{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}\n"
"\n"
""));
        team2_player2 = new QComboBox(groupBox_2);
        team2_player2->setObjectName("team2_player2");
        team2_player2->setGeometry(QRect(180, 120, 221, 31));
        team2_player2->setStyleSheet(QString::fromUtf8("#team2_player2 {\n"
"    background-color: white;   /* White background */\n"
"    color: black;              /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;        /* Rounded edges */\n"
"    padding: 5px;              /* Inner spacing */\n"
"}"));
        team2_player1 = new QComboBox(groupBox_2);
        team2_player1->setObjectName("team2_player1");
        team2_player1->setGeometry(QRect(180, 50, 221, 31));
        team2_player1->setStyleSheet(QString::fromUtf8("#team2_player1{\n"
"    background-color: white;   /* White background */\n"
"    color: black;              /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;        /* Rounded edges */\n"
"    padding: 5px;              /* Inner spacing */\n"
"}"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 50, 111, 20));
        label_4->setFont(font1);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 120, 91, 21));
        label_5->setFont(font1);
        ButtonBox = new QPushButton(playersubstitutiondialog);
        ButtonBox->setObjectName("ButtonBox");
        ButtonBox->setGeometry(QRect(740, 520, 131, 31));
        ButtonBox->setFont(font1);
        ButtonBox->setStyleSheet(QString::fromUtf8("#ButtonBox{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        ButtonBox_2 = new QPushButton(playersubstitutiondialog);
        ButtonBox_2->setObjectName("ButtonBox_2");
        ButtonBox_2->setGeometry(QRect(880, 520, 121, 31));
        ButtonBox_2->setFont(font1);
        ButtonBox_2->setStyleSheet(QString::fromUtf8("#ButtonBox_2{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));

        retranslateUi(playersubstitutiondialog);

        QMetaObject::connectSlotsByName(playersubstitutiondialog);
    } // setupUi

    void retranslateUi(QDialog *playersubstitutiondialog)
    {
        playersubstitutiondialog->setWindowTitle(QCoreApplication::translate("playersubstitutiondialog", "Dialog", nullptr));
        label->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("playersubstitutiondialog", "Team1", nullptr));
        label_2->setText(QCoreApplication::translate("playersubstitutiondialog", "Player Out:", nullptr));
        label_3->setText(QCoreApplication::translate("playersubstitutiondialog", "Player In:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("playersubstitutiondialog", "Team2", nullptr));
        label_4->setText(QCoreApplication::translate("playersubstitutiondialog", "Player Out:", nullptr));
        label_5->setText(QCoreApplication::translate("playersubstitutiondialog", "Player In:", nullptr));
        ButtonBox->setText(QCoreApplication::translate("playersubstitutiondialog", "Send", nullptr));
        ButtonBox_2->setText(QCoreApplication::translate("playersubstitutiondialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class playersubstitutiondialog: public Ui_playersubstitutiondialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERSUBSTITUTIONDIALOG_H
