/********************************************************************************
** Form generated from reading UI file 'emaildialog_arbitre.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILDIALOG_ARBITRE_H
#define UI_EMAILDIALOG_ARBITRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmailDialog
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QDateEdit *dateEdit_dateMatch;
    QPushButton *btn_annuler;
    QPushButton *btn_envoyer;
    QTextEdit *textEdit_message;
    QLineEdit *lineEdit_email;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *EmailDialog)
    {
        if (EmailDialog->objectName().isEmpty())
            EmailDialog->setObjectName("EmailDialog");
        EmailDialog->resize(1281, 468);
        EmailDialog->setStyleSheet(QString::fromUtf8(""));
        formLayoutWidget = new QWidget(EmailDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 30, 1241, 421));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        dateEdit_dateMatch = new QDateEdit(formLayoutWidget);
        dateEdit_dateMatch->setObjectName("dateEdit_dateMatch");

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit_dateMatch);

        btn_annuler = new QPushButton(formLayoutWidget);
        btn_annuler->setObjectName("btn_annuler");
        btn_annuler->setFont(font);
        btn_annuler->setStyleSheet(QString::fromUtf8("#btn_annuler{\n"
"background:rgba(33,133,85,0.4);\n"
"border-radius:10px;\n"
"padding:5px;\n"
"}"));

        formLayout->setWidget(5, QFormLayout::FieldRole, btn_annuler);

        btn_envoyer = new QPushButton(formLayoutWidget);
        btn_envoyer->setObjectName("btn_envoyer");
        btn_envoyer->setFont(font);
        btn_envoyer->setStyleSheet(QString::fromUtf8("#btn_envoyer{\n"
"background:rgba(33,133,85,0.4);\n"
"border-radius:10px;\n"
"padding:5px;\n"
"}"));

        formLayout->setWidget(4, QFormLayout::FieldRole, btn_envoyer);

        textEdit_message = new QTextEdit(formLayoutWidget);
        textEdit_message->setObjectName("textEdit_message");

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_message);

        lineEdit_email = new QLineEdit(formLayoutWidget);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setStyleSheet(QString::fromUtf8(""));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_email);

        label_4 = new QLabel(EmailDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 390, 63, 20));
        label_4->setStyleSheet(QString::fromUtf8("#label_4 {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/bg.jpg);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        label_5 = new QLabel(EmailDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 1281, 461));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label_5->setScaledContents(true);
        label_5->raise();
        formLayoutWidget->raise();
        label_4->raise();

        retranslateUi(EmailDialog);

        QMetaObject::connectSlotsByName(EmailDialog);
    } // setupUi

    void retranslateUi(QDialog *EmailDialog)
    {
        EmailDialog->setWindowTitle(QCoreApplication::translate("EmailDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EmailDialog", "Email de l'arbitre", nullptr));
        label_2->setText(QCoreApplication::translate("EmailDialog", "Message ", nullptr));
        label_3->setText(QCoreApplication::translate("EmailDialog", "Date", nullptr));
        btn_annuler->setText(QCoreApplication::translate("EmailDialog", "Annuler", nullptr));
        btn_envoyer->setText(QCoreApplication::translate("EmailDialog", "Envoyer", nullptr));
        label_4->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EmailDialog: public Ui_EmailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILDIALOG_ARBITRE_H
