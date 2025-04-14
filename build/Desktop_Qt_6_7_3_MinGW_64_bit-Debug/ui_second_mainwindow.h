/********************************************************************************
** Form generated from reading UI file 'second_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECOND_MAINWINDOW_H
#define UI_SECOND_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLabel *label;
    QTableView *table_s;
    QTableView *table_m;
    QWidget *widget;
    QWidget *qr;
    QLineEdit *name;
    QLineEdit *last_name;
    QLineEdit *date_m;
    QLineEdit *t1;
    QLineEdit *t2;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(1424, 792);
        label = new QLabel(Form);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1421, 781));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/img/bg.jpeg")));
        label->setScaledContents(true);
        table_s = new QTableView(Form);
        table_s->setObjectName("table_s");
        table_s->setGeometry(QRect(30, 70, 361, 281));
        table_m = new QTableView(Form);
        table_m->setObjectName("table_m");
        table_m->setGeometry(QRect(30, 380, 361, 291));
        widget = new QWidget(Form);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(410, 80, 931, 271));
        qr = new QWidget(widget);
        qr->setObjectName("qr");
        qr->setGeometry(QRect(679, 30, 201, 211));
        name = new QLineEdit(widget);
        name->setObjectName("name");
        name->setGeometry(QRect(30, 40, 113, 26));
        last_name = new QLineEdit(widget);
        last_name->setObjectName("last_name");
        last_name->setGeometry(QRect(30, 100, 113, 26));
        date_m = new QLineEdit(widget);
        date_m->setObjectName("date_m");
        date_m->setGeometry(QRect(50, 210, 261, 26));
        t1 = new QLineEdit(widget);
        t1->setObjectName("t1");
        t1->setGeometry(QRect(220, 100, 113, 26));
        t2 = new QLineEdit(widget);
        t2->setObjectName("t2");
        t2->setGeometry(QRect(480, 100, 113, 26));
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(380, 90, 63, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label_2->setFont(font);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1220, 380, 93, 29));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        pushButton->setFont(font1);

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("Form", "VS", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECOND_MAINWINDOW_H
