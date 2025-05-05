/********************************************************************************
** Form generated from reading UI file 'historiquedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIQUEDIALOG_H
#define UI_HISTORIQUEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_HistoriqueDialog
{
public:
    QTableWidget *tableWidget_historique;
    QLabel *label;

    void setupUi(QDialog *HistoriqueDialog)
    {
        if (HistoriqueDialog->objectName().isEmpty())
            HistoriqueDialog->setObjectName("HistoriqueDialog");
        HistoriqueDialog->resize(1304, 498);
        HistoriqueDialog->setStyleSheet(QString::fromUtf8(""));
        tableWidget_historique = new QTableWidget(HistoriqueDialog);
        if (tableWidget_historique->columnCount() < 2)
            tableWidget_historique->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_historique->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_historique->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_historique->setObjectName("tableWidget_historique");
        tableWidget_historique->setGeometry(QRect(20, 30, 1221, 421));
        tableWidget_historique->setMaximumSize(QSize(1221, 16777215));
        label = new QLabel(HistoriqueDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1301, 501));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->raise();
        tableWidget_historique->raise();

        retranslateUi(HistoriqueDialog);

        QMetaObject::connectSlotsByName(HistoriqueDialog);
    } // setupUi

    void retranslateUi(QDialog *HistoriqueDialog)
    {
        HistoriqueDialog->setWindowTitle(QCoreApplication::translate("HistoriqueDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_historique->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("HistoriqueDialog", "Date/Heure", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_historique->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("HistoriqueDialog", "Action", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HistoriqueDialog: public Ui_HistoriqueDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIQUEDIALOG_H
