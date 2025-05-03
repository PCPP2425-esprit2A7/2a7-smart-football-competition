/********************************************************************************
** Form generated from reading UI file 'dialog_arbitre.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ARBITRE_H
#define UI_DIALOG_ARBITRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QWidget *statisticsWidget;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(961, 517);
        Dialog->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        Dialog->setAcceptDrops(false);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(12, 9, 941, 501));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        label->setScaledContents(true);
        statisticsWidget = new QWidget(Dialog);
        statisticsWidget->setObjectName("statisticsWidget");
        statisticsWidget->setGeometry(QRect(29, 29, 901, 461));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ARBITRE_H
