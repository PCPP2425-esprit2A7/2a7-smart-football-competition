/********************************************************************************
** Form generated from reading UI file 'dialog_supporteur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SUPPORTEUR_H
#define UI_DIALOG_SUPPORTEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSupporteur
{
public:
    QLabel *label;
    QWidget *stat;

    void setupUi(QDialog *DialogSupporteur)
    {
        if (DialogSupporteur->objectName().isEmpty())
            DialogSupporteur->setObjectName("DialogSupporteur");
        DialogSupporteur->resize(988, 617);
        label = new QLabel(DialogSupporteur);
        label->setObjectName("label");
        label->setGeometry(QRect(-20, 0, 1011, 641));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->setScaledContents(true);
        stat = new QWidget(DialogSupporteur);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(130, 70, 731, 451));
        stat->setStyleSheet(QString::fromUtf8("#stat{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}"));

        retranslateUi(DialogSupporteur);

        QMetaObject::connectSlotsByName(DialogSupporteur);
    } // setupUi

    void retranslateUi(QDialog *DialogSupporteur)
    {
        DialogSupporteur->setWindowTitle(QCoreApplication::translate("DialogSupporteur", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogSupporteur: public Ui_DialogSupporteur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SUPPORTEUR_H
