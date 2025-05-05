/********************************************************************************
** Form generated from reading UI file 'dialog_stat_joueur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_STAT_JOUEUR_H
#define UI_DIALOG_STAT_JOUEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogJoueur
{
public:
    QLabel *label;
    QWidget *statisticsWidget;

    void setupUi(QDialog *DialogJoueur)
    {
        if (DialogJoueur->objectName().isEmpty())
            DialogJoueur->setObjectName("DialogJoueur");
        DialogJoueur->resize(721, 462);
        label = new QLabel(DialogJoueur);
        label->setObjectName("label");
        label->setGeometry(QRect(-8, -1, 731, 471));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->setScaledContents(true);
        statisticsWidget = new QWidget(DialogJoueur);
        statisticsWidget->setObjectName("statisticsWidget");
        statisticsWidget->setGeometry(QRect(120, 90, 451, 281));
        statisticsWidget->setStyleSheet(QString::fromUtf8("#statisticsWidget{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}\n"
""));

        retranslateUi(DialogJoueur);

        QMetaObject::connectSlotsByName(DialogJoueur);
    } // setupUi

    void retranslateUi(QDialog *DialogJoueur)
    {
        DialogJoueur->setWindowTitle(QCoreApplication::translate("DialogJoueur", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogJoueur: public Ui_DialogJoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_STAT_JOUEUR_H
