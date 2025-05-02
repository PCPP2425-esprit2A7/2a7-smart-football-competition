/********************************************************************************
** Form generated from reading UI file 'dialog_billet.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_BILLET_H
#define UI_DIALOG_BILLET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_generate_tickets
{
public:
    QLabel *label;
    QTableView *table_s;
    QWidget *ticket;
    QWidget *qr;
    QLabel *qr_label;
    QLineEdit *name;
    QLineEdit *last_name;
    QLineEdit *date_m;
    QLabel *label_12;
    QLineEdit *t1;
    QLineEdit *t2;
    QLineEdit *price;
    QLineEdit *area;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *qr_code_widget;
    QLineEdit *place;
    QLineEdit *id_qr;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *delete_qr;
    QPushButton *generate_qr;
    QLineEdit *date_issue;
    QLabel *label_11;
    QLabel *label_6;
    QPushButton *save;
    QTableView *table_b;
    QLabel *label_10;
    QTableView *table_m;
    QPushButton *delete_ticket;

    void setupUi(QDialog *generate_tickets)
    {
        if (generate_tickets->objectName().isEmpty())
            generate_tickets->setObjectName("generate_tickets");
        generate_tickets->resize(1368, 761);
        label = new QLabel(generate_tickets);
        label->setObjectName("label");
        label->setGeometry(QRect(-140, 0, 1501, 761));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->setScaledContents(true);
        table_s = new QTableView(generate_tickets);
        table_s->setObjectName("table_s");
        table_s->setGeometry(QRect(10, 470, 431, 281));
        table_s->setStyleSheet(QString::fromUtf8("#table_s\n"
"{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        ticket = new QWidget(generate_tickets);
        ticket->setObjectName("ticket");
        ticket->setGeometry(QRect(10, 110, 1031, 251));
        ticket->setStyleSheet(QString::fromUtf8("#ticket {\n"
"    background: rgba(0, 102, 51, 0.65); /* Deep Green */\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    color: #FFD700; /* Gold text */\n"
"}\n"
""));
        qr = new QWidget(ticket);
        qr->setObjectName("qr");
        qr->setGeometry(QRect(800, 30, 181, 191));
        qr->setStyleSheet(QString::fromUtf8("#qr{\n"
"background:transparent;\n"
"border:transparent;}"));
        qr_label = new QLabel(qr);
        qr_label->setObjectName("qr_label");
        qr_label->setGeometry(QRect(0, 0, 181, 191));
        qr_label->setStyleSheet(QString::fromUtf8("#qr_label{\n"
"background:transparent;\n"
"border:transparent;}"));
        name = new QLineEdit(ticket);
        name->setObjectName("name");
        name->setGeometry(QRect(30, 10, 231, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        font.setPointSize(15);
        font.setBold(true);
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8("#name{\n"
"background:transparent;\n"
"border:transparent;}"));
        last_name = new QLineEdit(ticket);
        last_name->setObjectName("last_name");
        last_name->setGeometry(QRect(30, 70, 231, 51));
        last_name->setFont(font);
        last_name->setStyleSheet(QString::fromUtf8("#last_name\n"
"{\n"
"background:transparent;\n"
"border:transparent;}"));
        date_m = new QLineEdit(ticket);
        date_m->setObjectName("date_m");
        date_m->setGeometry(QRect(430, 10, 351, 51));
        date_m->setFont(font);
        date_m->setStyleSheet(QString::fromUtf8("#date_m{\n"
"background:transparent;\n"
"border:transparent;}"));
        label_12 = new QLabel(ticket);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(470, 110, 63, 51));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sylfaen")});
        font1.setPointSize(25);
        font1.setBold(true);
        label_12->setFont(font1);
        t1 = new QLineEdit(ticket);
        t1->setObjectName("t1");
        t1->setGeometry(QRect(320, 100, 121, 71));
        t1->setFont(font1);
        t1->setStyleSheet(QString::fromUtf8("#t1{\n"
"background:transparent;\n"
"border:transparent;}"));
        t2 = new QLineEdit(ticket);
        t2->setObjectName("t2");
        t2->setGeometry(QRect(580, 100, 121, 71));
        t2->setFont(font1);
        t2->setStyleSheet(QString::fromUtf8("#t2{\n"
"background:transparent;\n"
"border:transparent;}"));
        price = new QLineEdit(ticket);
        price->setObjectName("price");
        price->setGeometry(QRect(30, 130, 231, 51));
        price->setFont(font);
        price->setStyleSheet(QString::fromUtf8("#price{\n"
"background:transparent;\n"
"border:transparent;}"));
        area = new QLineEdit(ticket);
        area->setObjectName("area");
        area->setGeometry(QRect(30, 190, 231, 51));
        area->setFont(font);
        area->setStyleSheet(QString::fromUtf8("#area{\n"
"background:transparent;\n"
"border:transparent;}"));
        label_2 = new QLabel(generate_tickets);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1250, 0, 111, 101));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/img/logo-removebg-preview.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(generate_tickets);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 410, 261, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sylfaen")});
        font2.setPointSize(20);
        font2.setBold(true);
        label_3->setFont(font2);
        label_4 = new QLabel(generate_tickets);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1080, 410, 181, 51));
        label_4->setFont(font2);
        label_5 = new QLabel(generate_tickets);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 50, 261, 51));
        label_5->setFont(font2);
        qr_code_widget = new QWidget(generate_tickets);
        qr_code_widget->setObjectName("qr_code_widget");
        qr_code_widget->setGeometry(QRect(1060, 110, 291, 251));
        qr_code_widget->setStyleSheet(QString::fromUtf8("#qr_code_widget\n"
"{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));
        place = new QLineEdit(qr_code_widget);
        place->setObjectName("place");
        place->setGeometry(QRect(20, 170, 251, 26));
        id_qr = new QLineEdit(qr_code_widget);
        id_qr->setObjectName("id_qr");
        id_qr->setGeometry(QRect(20, 40, 251, 26));
        label_7 = new QLabel(qr_code_widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 10, 63, 20));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sylfaen")});
        font3.setPointSize(14);
        font3.setBold(true);
        label_7->setFont(font3);
        label_8 = new QLabel(qr_code_widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 140, 71, 20));
        label_8->setFont(font3);
        delete_qr = new QPushButton(qr_code_widget);
        delete_qr->setObjectName("delete_qr");
        delete_qr->setGeometry(QRect(40, 210, 93, 29));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        delete_qr->setFont(font4);
        delete_qr->setStyleSheet(QString::fromUtf8("#delete_qr{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        generate_qr = new QPushButton(qr_code_widget);
        generate_qr->setObjectName("generate_qr");
        generate_qr->setGeometry(QRect(170, 210, 93, 29));
        generate_qr->setFont(font4);
        generate_qr->setStyleSheet(QString::fromUtf8("#generate_qr{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        date_issue = new QLineEdit(qr_code_widget);
        date_issue->setObjectName("date_issue");
        date_issue->setGeometry(QRect(20, 100, 251, 26));
        label_11 = new QLabel(qr_code_widget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 70, 131, 20));
        label_11->setFont(font3);
        label_6 = new QLabel(generate_tickets);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1070, 50, 151, 51));
        label_6->setFont(font2);
        save = new QPushButton(generate_tickets);
        save->setObjectName("save");
        save->setGeometry(QRect(940, 370, 93, 29));
        save->setFont(font4);
        save->setStyleSheet(QString::fromUtf8("#save\n"
"{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        table_b = new QTableView(generate_tickets);
        table_b->setObjectName("table_b");
        table_b->setGeometry(QRect(460, 470, 441, 281));
        table_b->setStyleSheet(QString::fromUtf8("#table_b\n"
"{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        label_10 = new QLabel(generate_tickets);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(600, 410, 181, 51));
        label_10->setFont(font2);
        table_m = new QTableView(generate_tickets);
        table_m->setObjectName("table_m");
        table_m->setGeometry(QRect(920, 470, 431, 281));
        table_m->setStyleSheet(QString::fromUtf8("#table_m{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        delete_ticket = new QPushButton(generate_tickets);
        delete_ticket->setObjectName("delete_ticket");
        delete_ticket->setGeometry(QRect(830, 370, 93, 29));
        delete_ticket->setFont(font4);
        delete_ticket->setStyleSheet(QString::fromUtf8("#delete_ticket{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));

        retranslateUi(generate_tickets);

        QMetaObject::connectSlotsByName(generate_tickets);
    } // setupUi

    void retranslateUi(QDialog *generate_tickets)
    {
        generate_tickets->setWindowTitle(QCoreApplication::translate("generate_tickets", "Dialog", nullptr));
        label->setText(QString());
        qr_label->setText(QString());
        label_12->setText(QCoreApplication::translate("generate_tickets", "VS", nullptr));
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("generate_tickets", "supporters table", nullptr));
        label_4->setText(QCoreApplication::translate("generate_tickets", "match table", nullptr));
        label_5->setText(QCoreApplication::translate("generate_tickets", "Ticket ", nullptr));
        label_7->setText(QCoreApplication::translate("generate_tickets", "ID", nullptr));
        label_8->setText(QCoreApplication::translate("generate_tickets", "Place", nullptr));
        delete_qr->setText(QCoreApplication::translate("generate_tickets", "Delete", nullptr));
        generate_qr->setText(QCoreApplication::translate("generate_tickets", "Generate", nullptr));
        label_11->setText(QCoreApplication::translate("generate_tickets", "Date Issue", nullptr));
        label_6->setText(QCoreApplication::translate("generate_tickets", "QR Code", nullptr));
        save->setText(QCoreApplication::translate("generate_tickets", "Save", nullptr));
        label_10->setText(QCoreApplication::translate("generate_tickets", "tickets table", nullptr));
        delete_ticket->setText(QCoreApplication::translate("generate_tickets", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class generate_tickets: public Ui_generate_tickets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_BILLET_H
