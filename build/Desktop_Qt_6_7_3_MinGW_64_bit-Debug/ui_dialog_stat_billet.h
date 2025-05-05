/********************************************************************************
** Form generated from reading UI file 'dialog_stat_billet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_STAT_BILLET_H
#define UI_DIALOG_STAT_BILLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogStat
{
public:
    QLabel *label;
    QWidget *statisticsWidget;

    void setupUi(QDialog *DialogStat)
    {
        if (DialogStat->objectName().isEmpty())
            DialogStat->setObjectName("DialogStat");
        DialogStat->resize(957, 642);
        label = new QLabel(DialogStat);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 961, 641));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->setScaledContents(true);
        statisticsWidget = new QWidget(DialogStat);
        statisticsWidget->setObjectName("statisticsWidget");
        statisticsWidget->setGeometry(QRect(90, 70, 701, 511));
        statisticsWidget->setStyleSheet(QString::fromUtf8("#statisticsWidget{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}"));

        retranslateUi(DialogStat);

        QMetaObject::connectSlotsByName(DialogStat);
    } // setupUi

    void retranslateUi(QDialog *DialogStat)
    {
        DialogStat->setWindowTitle(QCoreApplication::translate("DialogStat", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogStat: public Ui_DialogStat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_STAT_BILLET_H
