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

class Ui_DialogArbitre
{
public:
    QLabel *label;
    QWidget *statisticsWidget;

    void setupUi(QDialog *DialogArbitre)
    {
        if (DialogArbitre->objectName().isEmpty())
            DialogArbitre->setObjectName("DialogArbitre");
        DialogArbitre->resize(961, 517);
        DialogArbitre->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        DialogArbitre->setAcceptDrops(false);
        label = new QLabel(DialogArbitre);
        label->setObjectName("label");
        label->setGeometry(QRect(12, 9, 941, 501));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        label->setScaledContents(true);
        statisticsWidget = new QWidget(DialogArbitre);
        statisticsWidget->setObjectName("statisticsWidget");
        statisticsWidget->setGeometry(QRect(29, 29, 901, 461));

        retranslateUi(DialogArbitre);

        QMetaObject::connectSlotsByName(DialogArbitre);
    } // setupUi

    void retranslateUi(QDialog *DialogArbitre)
    {
        DialogArbitre->setWindowTitle(QCoreApplication::translate("DialogArbitre", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogArbitre: public Ui_DialogArbitre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ARBITRE_H
