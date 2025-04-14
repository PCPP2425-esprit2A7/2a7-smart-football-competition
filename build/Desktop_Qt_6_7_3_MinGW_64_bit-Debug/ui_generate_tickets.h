/********************************************************************************
** Form generated from reading UI file 'generate_tickets.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATE_TICKETS_H
#define UI_GENERATE_TICKETS_H

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
    QTableView *table_m;
    QTableView *table_s;
    QWidget *ticket;
    QWidget *qr;
    QLineEdit *name;
    QLineEdit *last_name;
    QLineEdit *date_m;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *qr_code_widget;
    QLineEdit *lieux_qr;
    QLineEdit *id_qr;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *delete_qr;
    QPushButton *generate_qr;
    QLabel *label_6;
    QPushButton *save;
    QLabel *label_9;

    void setupUi(QDialog *generate_tickets)
    {
        if (generate_tickets->objectName().isEmpty())
            generate_tickets->setObjectName("generate_tickets");
        generate_tickets->resize(1404, 775);
        label = new QLabel(generate_tickets);
        label->setObjectName("label");
        label->setGeometry(QRect(-140, 0, 1541, 771));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/img/bg.jpeg")));
        label->setScaledContents(true);
        table_m = new QTableView(generate_tickets);
        table_m->setObjectName("table_m");
        table_m->setGeometry(QRect(720, 510, 661, 241));
        table_m->setStyleSheet(QString::fromUtf8("#table_m{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        table_s = new QTableView(generate_tickets);
        table_s->setObjectName("table_s");
        table_s->setGeometry(QRect(20, 510, 661, 241));
        table_s->setStyleSheet(QString::fromUtf8("#table_s\n"
"{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}"));
        ticket = new QWidget(generate_tickets);
        ticket->setObjectName("ticket");
        ticket->setGeometry(QRect(20, 160, 1041, 251));
        ticket->setStyleSheet(QString::fromUtf8("#ticket\n"
"{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));
        qr = new QWidget(ticket);
        qr->setObjectName("qr");
        qr->setGeometry(QRect(800, 30, 181, 191));
        qr->setStyleSheet(QString::fromUtf8("#qr{\n"
"background:white;\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));
        name = new QLineEdit(ticket);
        name->setObjectName("name");
        name->setGeometry(QRect(40, 70, 113, 26));
        last_name = new QLineEdit(ticket);
        last_name->setObjectName("last_name");
        last_name->setGeometry(QRect(40, 110, 113, 26));
        date_m = new QLineEdit(ticket);
        date_m->setObjectName("date_m");
        date_m->setGeometry(QRect(90, 200, 341, 26));
        label_2 = new QLabel(generate_tickets);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1290, 0, 111, 101));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/image/img/logo-removebg-preview.png")));
        label_2->setScaledContents(true);
        label_3 = new QLabel(generate_tickets);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(170, 460, 261, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        font.setPointSize(20);
        font.setBold(true);
        label_3->setFont(font);
        label_4 = new QLabel(generate_tickets);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(980, 460, 181, 51));
        label_4->setFont(font);
        label_5 = new QLabel(generate_tickets);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 100, 261, 51));
        label_5->setFont(font);
        qr_code_widget = new QWidget(generate_tickets);
        qr_code_widget->setObjectName("qr_code_widget");
        qr_code_widget->setGeometry(QRect(1080, 200, 291, 251));
        qr_code_widget->setStyleSheet(QString::fromUtf8("#qr_code_widget\n"
"{\n"
"background:rgba(214, 215, 222, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}\n"
"\n"
""));
        lieux_qr = new QLineEdit(qr_code_widget);
        lieux_qr->setObjectName("lieux_qr");
        lieux_qr->setGeometry(QRect(20, 140, 251, 26));
        id_qr = new QLineEdit(qr_code_widget);
        id_qr->setObjectName("id_qr");
        id_qr->setGeometry(QRect(20, 50, 251, 26));
        label_7 = new QLabel(qr_code_widget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 20, 63, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sylfaen")});
        font1.setPointSize(14);
        font1.setBold(true);
        label_7->setFont(font1);
        label_8 = new QLabel(qr_code_widget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 100, 63, 20));
        label_8->setFont(font1);
        delete_qr = new QPushButton(qr_code_widget);
        delete_qr->setObjectName("delete_qr");
        delete_qr->setGeometry(QRect(40, 210, 93, 29));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        delete_qr->setFont(font2);
        delete_qr->setStyleSheet(QString::fromUtf8("#delete_qr{\n"
"border-radius: 10px;         /* Rounded corners */\n"
"                    /* Padding for text */\n"
"    background: transparent; \n"
"}"));
        generate_qr = new QPushButton(qr_code_widget);
        generate_qr->setObjectName("generate_qr");
        generate_qr->setGeometry(QRect(170, 210, 93, 29));
        generate_qr->setFont(font2);
        generate_qr->setStyleSheet(QString::fromUtf8("#generate_qr{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        label_6 = new QLabel(generate_tickets);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1080, 140, 151, 51));
        label_6->setFont(font);
        save = new QPushButton(generate_tickets);
        save->setObjectName("save");
        save->setGeometry(QRect(960, 420, 93, 29));
        save->setFont(font2);
        save->setStyleSheet(QString::fromUtf8("#save\n"
"{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        label_9 = new QLabel(generate_tickets);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(400, 20, 571, 51));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Sylfaen")});
        font3.setPointSize(27);
        font3.setBold(true);
        label_9->setFont(font3);

        retranslateUi(generate_tickets);

        QMetaObject::connectSlotsByName(generate_tickets);
    } // setupUi

    void retranslateUi(QDialog *generate_tickets)
    {
        generate_tickets->setWindowTitle(QCoreApplication::translate("generate_tickets", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QCoreApplication::translate("generate_tickets", "supporters table", nullptr));
        label_4->setText(QCoreApplication::translate("generate_tickets", "match table", nullptr));
        label_5->setText(QCoreApplication::translate("generate_tickets", "Ticket ", nullptr));
        label_7->setText(QCoreApplication::translate("generate_tickets", "ID", nullptr));
        label_8->setText(QCoreApplication::translate("generate_tickets", "Lieux", nullptr));
        delete_qr->setText(QCoreApplication::translate("generate_tickets", "Delete", nullptr));
        generate_qr->setText(QCoreApplication::translate("generate_tickets", "Generate", nullptr));
        label_6->setText(QCoreApplication::translate("generate_tickets", "QR Code", nullptr));
        save->setText(QCoreApplication::translate("generate_tickets", "Save", nullptr));
        label_9->setText(QCoreApplication::translate("generate_tickets", "Welcom you can Book Now!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class generate_tickets: public Ui_generate_tickets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATE_TICKETS_H
