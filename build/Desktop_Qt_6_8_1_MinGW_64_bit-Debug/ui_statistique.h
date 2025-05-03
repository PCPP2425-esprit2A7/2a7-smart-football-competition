/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Statistique
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layoutStatistiques;

    void setupUi(QDialog *Statistique)
    {
        if (Statistique->objectName().isEmpty())
            Statistique->setObjectName("Statistique");
        Statistique->resize(722, 338);
        verticalLayoutWidget = new QWidget(Statistique);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 30, 631, 271));
        layoutStatistiques = new QVBoxLayout(verticalLayoutWidget);
        layoutStatistiques->setObjectName("layoutStatistiques");
        layoutStatistiques->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Statistique);

        QMetaObject::connectSlotsByName(Statistique);
    } // setupUi

    void retranslateUi(QDialog *Statistique)
    {
        Statistique->setWindowTitle(QCoreApplication::translate("Statistique", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Statistique: public Ui_Statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
