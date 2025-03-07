/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *background;
    QLabel *logo;
    QLabel *menu;
    QLabel *supporteur;
    QLabel *joueur;
    QLabel *arbitre;
    QLabel *match;
    QLabel *equipe;
    QLabel *billet;
    QLabel *form;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QComboBox *comboBox;
    QTableWidget *table;
    QLineEdit *lineEdit_7;
    QComboBox *comboBox_2;
    QLabel *label_8;
    QPushButton *add;
    QPushButton *cancel;
    QPushButton *modify;
    QPushButton *delete_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1318, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 1311, 541));
        background->setPixmap(QPixmap(QString::fromUtf8(":/img/img/background.jpg")));
        background->setScaledContents(true);
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(10, 10, 151, 81));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo.png")));
        logo->setScaledContents(true);
        menu = new QLabel(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(40, 110, 71, 411));
        menu->setStyleSheet(QString::fromUtf8("#menu{\n"
"background-color:#218555;\n"
"border-radius:10px;\n"
" padding:5px;\n"
"}"));
        supporteur = new QLabel(centralwidget);
        supporteur->setObjectName("supporteur");
        supporteur->setGeometry(QRect(60, 130, 31, 41));
        supporteur->setPixmap(QPixmap(QString::fromUtf8(":/img/img/supporteur.png")));
        supporteur->setScaledContents(true);
        joueur = new QLabel(centralwidget);
        joueur->setObjectName("joueur");
        joueur->setGeometry(QRect(50, 190, 51, 51));
        joueur->setPixmap(QPixmap(QString::fromUtf8(":/img/img/joueur.png")));
        joueur->setScaledContents(true);
        arbitre = new QLabel(centralwidget);
        arbitre->setObjectName("arbitre");
        arbitre->setGeometry(QRect(50, 260, 51, 41));
        arbitre->setPixmap(QPixmap(QString::fromUtf8(":/img/img/arbitre.png")));
        arbitre->setScaledContents(true);
        match = new QLabel(centralwidget);
        match->setObjectName("match");
        match->setGeometry(QRect(60, 400, 31, 41));
        match->setPixmap(QPixmap(QString::fromUtf8(":/img/img/match.png")));
        match->setScaledContents(true);
        equipe = new QLabel(centralwidget);
        equipe->setObjectName("equipe");
        equipe->setGeometry(QRect(50, 330, 51, 41));
        equipe->setPixmap(QPixmap(QString::fromUtf8(":/img/img/equipe.png")));
        equipe->setScaledContents(true);
        billet = new QLabel(centralwidget);
        billet->setObjectName("billet");
        billet->setGeometry(QRect(50, 460, 51, 41));
        billet->setPixmap(QPixmap(QString::fromUtf8(":/img/img/ticket.png")));
        billet->setScaledContents(true);
        form = new QLabel(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(152, 119, 221, 401));
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214,215,222,0.4);\n"
"border-radius:10px;\n"
" padding:5px;}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 150, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 190, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 240, 81, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 290, 63, 20));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 340, 63, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(170, 390, 81, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 440, 63, 20));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(250, 150, 113, 26));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(250, 190, 113, 26));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(250, 230, 113, 26));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(250, 290, 113, 26));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(250, 340, 113, 26));
        lineEdit_6 = new QLineEdit(centralwidget);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(250, 390, 113, 26));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(250, 440, 111, 26));
        table = new QTableWidget(centralwidget);
        if (table->columnCount() < 7)
            table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        table->setObjectName("table");
        table->setGeometry(QRect(400, 120, 891, 192));
        table->setStyleSheet(QString::fromUtf8("#table{\n"
"background:rgba(33,133,85,0.4);\n"
"border-radius:10px;\n"
"padding:5px;\n"
"}"));
        lineEdit_7 = new QLineEdit(centralwidget);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(510, 20, 511, 26));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(1105, 70, 121, 26));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(1230, 70, 51, 31));
        label_8->setPixmap(QPixmap(QString::fromUtf8(":/img/img/pdf.png")));
        label_8->setScaledContents(true);
        add = new QPushButton(centralwidget);
        add->setObjectName("add");
        add->setGeometry(QRect(270, 480, 93, 29));
        cancel = new QPushButton(centralwidget);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(160, 480, 93, 29));
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(1190, 340, 93, 29));
        delete_3 = new QPushButton(centralwidget);
        delete_3->setObjectName("delete_3");
        delete_3->setGeometry(QRect(1060, 340, 93, 29));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1318, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        background->setText(QString());
        logo->setText(QString());
        menu->setText(QString());
        supporteur->setText(QString());
        joueur->setText(QString());
        arbitre->setText(QString());
        match->setText(QString());
        equipe->setText(QString());
        billet->setText(QString());
        form->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "LastName", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nbcards", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Mofficated", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "LastName", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Nbcards", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Mofficated", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "category", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Recherche par nom", nullptr));
        comboBox_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Filtrer", nullptr));
        label_8->setText(QString());
        add->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "cancel", nullptr));
        modify->setText(QCoreApplication::translate("MainWindow", "modify", nullptr));
        delete_3->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
