/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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
    QLabel *label;
    QWidget *menu;
    QLabel *user;
    QLabel *joueur;
    QLabel *arbitre;
    QLabel *team;
    QLabel *match;
    QLabel *ticket;
    QWidget *form;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *id;
    QComboBox *type;
    QComboBox *area;
    QLineEdit *price;
    QLineEdit *quantity;
    QDateEdit *date_issue;
    QDateEdit *date_event;
    QPushButton *add;
    QPushButton *cancel;
    QTableWidget *table;
    QLineEdit *search_bar;
    QComboBox *tri;
    QLabel *label_9;
    QPushButton *modify;
    QPushButton *stat;
    QPushButton *generate;
    QPushButton *delete_2;
    QLabel *label_10;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1424, 814);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -10, 1411, 781));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/img/bg.jpeg")));
        label->setScaledContents(true);
        menu = new QWidget(centralwidget);
        menu->setObjectName("menu");
        menu->setGeometry(QRect(30, 150, 120, 511));
        menu->setStyleSheet(QString::fromUtf8("#menu\n"
"{\n"
"background-color:#218555;\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        user = new QLabel(menu);
        user->setObjectName("user");
        user->setGeometry(QRect(30, 20, 60, 60));
        user->setPixmap(QPixmap(QString::fromUtf8(":/image/img/user.png")));
        user->setScaledContents(true);
        joueur = new QLabel(menu);
        joueur->setObjectName("joueur");
        joueur->setGeometry(QRect(20, 100, 70, 70));
        joueur->setPixmap(QPixmap(QString::fromUtf8(":/image/img/soccer-player.png")));
        joueur->setScaledContents(true);
        arbitre = new QLabel(menu);
        arbitre->setObjectName("arbitre");
        arbitre->setGeometry(QRect(30, 190, 70, 70));
        arbitre->setPixmap(QPixmap(QString::fromUtf8(":/image/img/card.png")));
        arbitre->setScaledContents(true);
        team = new QLabel(menu);
        team->setObjectName("team");
        team->setGeometry(QRect(30, 270, 60, 60));
        team->setPixmap(QPixmap(QString::fromUtf8(":/image/img/image.png")));
        team->setScaledContents(true);
        match = new QLabel(menu);
        match->setObjectName("match");
        match->setGeometry(QRect(30, 350, 60, 60));
        match->setPixmap(QPixmap(QString::fromUtf8(":/image/img/soccer-ball 1.png")));
        match->setScaledContents(true);
        ticket = new QLabel(menu);
        ticket->setObjectName("ticket");
        ticket->setGeometry(QRect(30, 430, 71, 70));
        ticket->setPixmap(QPixmap(QString::fromUtf8(":/image/img/image 2.png")));
        ticket->setScaledContents(true);
        ticket->setWordWrap(false);
        form = new QWidget(centralwidget);
        form->setObjectName("form");
        form->setGeometry(QRect(170, 150, 321, 511));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        form->setFont(font);
        form->setStyleSheet(QString::fromUtf8("#form{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));
        label_2 = new QLabel(form);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 61, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sylfaen")});
        font1.setPointSize(12);
        font1.setBold(true);
        label_2->setFont(font1);
        label_3 = new QLabel(form);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 71, 31));
        label_3->setFont(font1);
        label_4 = new QLabel(form);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 150, 71, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(form);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 200, 111, 41));
        label_5->setFont(font1);
        label_6 = new QLabel(form);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 260, 71, 31));
        label_6->setFont(font1);
        label_7 = new QLabel(form);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 310, 121, 41));
        label_7->setFont(font1);
        label_8 = new QLabel(form);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 370, 131, 51));
        label_8->setFont(font1);
        id = new QLineEdit(form);
        id->setObjectName("id");
        id->setGeometry(QRect(150, 50, 151, 26));
        id->setStyleSheet(QString::fromUtf8("#id {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        type = new QComboBox(form);
        type->addItem(QString());
        type->addItem(QString());
        type->addItem(QString());
        type->setObjectName("type");
        type->setGeometry(QRect(150, 110, 151, 26));
        type->setStyleSheet(QString::fromUtf8("#type {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        area = new QComboBox(form);
        area->addItem(QString());
        area->addItem(QString());
        area->addItem(QString());
        area->setObjectName("area");
        area->setGeometry(QRect(150, 260, 151, 26));
        area->setStyleSheet(QString::fromUtf8("#area {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        price = new QLineEdit(form);
        price->setObjectName("price");
        price->setGeometry(QRect(152, 160, 151, 26));
        price->setStyleSheet(QString::fromUtf8("#price {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        quantity = new QLineEdit(form);
        quantity->setObjectName("quantity");
        quantity->setGeometry(QRect(152, 210, 151, 26));
        quantity->setStyleSheet(QString::fromUtf8("#quantity {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        date_issue = new QDateEdit(form);
        date_issue->setObjectName("date_issue");
        date_issue->setGeometry(QRect(160, 320, 141, 26));
        date_issue->setStyleSheet(QString::fromUtf8("#date_issue {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        date_event = new QDateEdit(form);
        date_event->setObjectName("date_event");
        date_event->setGeometry(QRect(160, 380, 141, 26));
        date_event->setStyleSheet(QString::fromUtf8("#date_event {\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        add = new QPushButton(form);
        add->setObjectName("add");
        add->setGeometry(QRect(190, 450, 93, 29));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sylfaen")});
        font2.setPointSize(10);
        font2.setBold(true);
        add->setFont(font2);
        add->setStyleSheet(QString::fromUtf8("#add{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        cancel = new QPushButton(form);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(40, 450, 93, 29));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sylfaen")});
        font3.setBold(true);
        cancel->setFont(font3);
        cancel->setStyleSheet(QString::fromUtf8("#cancel{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        table = new QTableWidget(centralwidget);
        if (table->columnCount() < 7)
            table->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font2);
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font2);
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font2);
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font2);
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font2);
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font2);
        table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        table->setObjectName("table");
        table->setGeometry(QRect(510, 190, 891, 241));
        table->setStyleSheet(QString::fromUtf8("#table{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        search_bar = new QLineEdit(centralwidget);
        search_bar->setObjectName("search_bar");
        search_bar->setGeometry(QRect(520, 20, 501, 31));
        search_bar->setStyleSheet(QString::fromUtf8("#search_bar {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}\n"
""));
        tri = new QComboBox(centralwidget);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1090, 150, 231, 31));
        tri->setStyleSheet(QString::fromUtf8("#tri\n"
" {\n"
"   border: 2px solid gray;       /* Border color and thickness */\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: white; \n"
"}"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(1340, 150, 31, 31));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/image/img/pdf.png")));
        label_9->setScaledContents(true);
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(1300, 460, 93, 29));
        modify->setFont(font3);
        modify->setStyleSheet(QString::fromUtf8("#modify{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(1272, 20, 131, 29));
        stat->setFont(font3);
        stat->setStyleSheet(QString::fromUtf8("#stat{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        generate = new QPushButton(centralwidget);
        generate->setObjectName("generate");
        generate->setGeometry(QRect(1160, 20, 93, 29));
        generate->setFont(font3);
        generate->setStyleSheet(QString::fromUtf8("#generate{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(1180, 460, 93, 29));
        delete_2->setFont(font3);
        delete_2->setStyleSheet(QString::fromUtf8("#delete_2\n"
"{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 10, 181, 141));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/image/img/logo-removebg-preview.png")));
        label_10->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1424, 26));
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
        label->setText(QString());
        user->setText(QString());
        joueur->setText(QString());
        arbitre->setText(QString());
        team->setText(QString());
        match->setText(QString());
        ticket->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Id :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Price :", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Quantity :", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Area :", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Date_issue :", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Date_event :", nullptr));
        type->setItemText(0, QCoreApplication::translate("MainWindow", "Eco", nullptr));
        type->setItemText(1, QCoreApplication::translate("MainWindow", "Standard ", nullptr));
        type->setItemText(2, QCoreApplication::translate("MainWindow", "VIP", nullptr));

        area->setItemText(0, QCoreApplication::translate("MainWindow", "A", nullptr));
        area->setItemText(1, QCoreApplication::translate("MainWindow", "B", nullptr));
        area->setItemText(2, QCoreApplication::translate("MainWindow", "C", nullptr));

        add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindow", "Cancel", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Quantity", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Area", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Date_issue", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Date_event", nullptr));
        search_bar->setPlaceholderText(QCoreApplication::translate("MainWindow", "search...", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindow", "Default", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindow", "Expensive", nullptr));
        tri->setItemText(2, QCoreApplication::translate("MainWindow", "Cheap", nullptr));

        tri->setPlaceholderText(QString());
        label_9->setText(QString());
        modify->setText(QCoreApplication::translate("MainWindow", "Modify", nullptr));
        stat->setText(QCoreApplication::translate("MainWindow", "Report statistics", nullptr));
        generate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
        delete_2->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_10->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
