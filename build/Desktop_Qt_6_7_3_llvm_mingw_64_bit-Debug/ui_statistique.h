/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistique
{
public:
    QLabel *label;
    QWidget *statisticsWidget;

    void setupUi(QDialog *Statistique)
    {
        if (Statistique->objectName().isEmpty())
            Statistique->setObjectName("Statistique");
        Statistique->resize(961, 517);
        Statistique->setContextMenuPolicy(Qt::ContextMenuPolicy::NoContextMenu);
        Statistique->setAcceptDrops(false);
        label = new QLabel(Statistique);
        label->setObjectName("label");
        label->setGeometry(QRect(12, 9, 941, 501));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        label->setScaledContents(true);
        statisticsWidget = new QWidget(Statistique);
        statisticsWidget->setObjectName("statisticsWidget");
        statisticsWidget->setGeometry(QRect(29, 29, 901, 461));

        retranslateUi(Statistique);

        QMetaObject::connectSlotsByName(Statistique);
    } // setupUi

    void retranslateUi(QDialog *Statistique)
    {
        Statistique->setWindowTitle(QCoreApplication::translate("Statistique", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Statistique: public Ui_Statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
