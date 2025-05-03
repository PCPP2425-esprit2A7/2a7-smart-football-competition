/********************************************************************************
** Form generated from reading UI file 'emaildialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILDIALOG_H
#define UI_EMAILDIALOG_H

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
    QLineEdit *lineEdit_email;
    QPushButton *btn_annuler;
    QPushButton *btn_envoyer;
    QTextEdit *textEdit_message;

    void setupUi(QDialog *EmailDialog)
    {
        if (EmailDialog->objectName().isEmpty())
            EmailDialog->setObjectName("EmailDialog");
        EmailDialog->resize(673, 477);
        formLayoutWidget = new QWidget(EmailDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 40, 651, 401));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        dateEdit_dateMatch = new QDateEdit(formLayoutWidget);
        dateEdit_dateMatch->setObjectName("dateEdit_dateMatch");

        formLayout->setWidget(2, QFormLayout::FieldRole, dateEdit_dateMatch);

        lineEdit_email = new QLineEdit(formLayoutWidget);
        lineEdit_email->setObjectName("lineEdit_email");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_email);

        btn_annuler = new QPushButton(formLayoutWidget);
        btn_annuler->setObjectName("btn_annuler");

        formLayout->setWidget(5, QFormLayout::FieldRole, btn_annuler);

        btn_envoyer = new QPushButton(formLayoutWidget);
        btn_envoyer->setObjectName("btn_envoyer");

        formLayout->setWidget(4, QFormLayout::FieldRole, btn_envoyer);

        textEdit_message = new QTextEdit(formLayoutWidget);
        textEdit_message->setObjectName("textEdit_message");

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_message);


        retranslateUi(EmailDialog);

        QMetaObject::connectSlotsByName(EmailDialog);
    } // setupUi

    void retranslateUi(QDialog *EmailDialog)
    {
        EmailDialog->setWindowTitle(QCoreApplication::translate("EmailDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("EmailDialog", "Email de l'arbitre", nullptr));
        label_2->setText(QCoreApplication::translate("EmailDialog", "Message ", nullptr));
        label_3->setText(QCoreApplication::translate("EmailDialog", "Date", nullptr));
        btn_annuler->setText(QCoreApplication::translate("EmailDialog", "annuler", nullptr));
        btn_envoyer->setText(QCoreApplication::translate("EmailDialog", "envoyer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmailDialog: public Ui_EmailDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILDIALOG_H
