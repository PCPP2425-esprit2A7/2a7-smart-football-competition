/********************************************************************************
** Form generated from reading UI file 'reclamationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECLAMATIONWINDOW_H
#define UI_RECLAMATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ReclamationWindow
{
public:
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_email;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_submitReclamation;
    QTextEdit *textEdit_sreason;

    void setupUi(QDialog *ReclamationWindow)
    {
        if (ReclamationWindow->objectName().isEmpty())
            ReclamationWindow->setObjectName("ReclamationWindow");
        ReclamationWindow->resize(502, 289);
        ReclamationWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/img/img/background.jpg);"));
        lineEdit_name = new QLineEdit(ReclamationWindow);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(220, 30, 211, 26));
        lineEdit_name->setStyleSheet(QString::fromUtf8("#lineEdit_name { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        lineEdit_email = new QLineEdit(ReclamationWindow);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(220, 80, 211, 26));
        lineEdit_email->setStyleSheet(QString::fromUtf8("#lineEdit_email { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));
        label = new QLabel(ReclamationWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 111, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(ReclamationWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 90, 101, 20));
        label_2->setFont(font);
        label_3 = new QLabel(ReclamationWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 160, 161, 20));
        label_3->setFont(font);
        pushButton_submitReclamation = new QPushButton(ReclamationWindow);
        pushButton_submitReclamation->setObjectName("pushButton_submitReclamation");
        pushButton_submitReclamation->setGeometry(QRect(40, 250, 151, 29));
        pushButton_submitReclamation->setFont(font);
        pushButton_submitReclamation->setStyleSheet(QString::fromUtf8("#pushButton_submitReclamation{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        textEdit_sreason = new QTextEdit(ReclamationWindow);
        textEdit_sreason->setObjectName("textEdit_sreason");
        textEdit_sreason->setGeometry(QRect(220, 140, 211, 75));
        textEdit_sreason->setStyleSheet(QString::fromUtf8("#textEdit_sreason { \n"
"    color: rgb(0, 0, 0);\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    background: transparent; /* Fond transparent */\n"
"    border: 2px solid #619D80 /* Couleur de bordure */\n"
"}\n"
""));

        retranslateUi(ReclamationWindow);

        QMetaObject::connectSlotsByName(ReclamationWindow);
    } // setupUi

    void retranslateUi(QDialog *ReclamationWindow)
    {
        ReclamationWindow->setWindowTitle(QCoreApplication::translate("ReclamationWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ReclamationWindow", "Non Arbitre", nullptr));
        label_2->setText(QCoreApplication::translate("ReclamationWindow", "Email Arbitre", nullptr));
        label_3->setText(QCoreApplication::translate("ReclamationWindow", "Reclamation", nullptr));
        pushButton_submitReclamation->setText(QCoreApplication::translate("ReclamationWindow", "Reclamer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReclamationWindow: public Ui_ReclamationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECLAMATIONWINDOW_H
