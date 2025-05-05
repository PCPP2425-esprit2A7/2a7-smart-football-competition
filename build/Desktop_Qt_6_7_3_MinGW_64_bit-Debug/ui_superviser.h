/********************************************************************************
** Form generated from reading UI file 'superviser.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUPERVISER_H
#define UI_SUPERVISER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Superviser
{
public:
    QPushButton *pushButton_envoyer;
    QLineEdit *team1;
    QLineEdit *team2;
    QLineEdit *lineEdit_score;
    QLabel *label;

    void setupUi(QDialog *Superviser)
    {
        if (Superviser->objectName().isEmpty())
            Superviser->setObjectName("Superviser");
        Superviser->resize(446, 339);
        pushButton_envoyer = new QPushButton(Superviser);
        pushButton_envoyer->setObjectName("pushButton_envoyer");
        pushButton_envoyer->setGeometry(QRect(150, 280, 141, 31));
        team1 = new QLineEdit(Superviser);
        team1->setObjectName("team1");
        team1->setGeometry(QRect(40, 100, 113, 22));
        team2 = new QLineEdit(Superviser);
        team2->setObjectName("team2");
        team2->setGeometry(QRect(260, 110, 113, 22));
        lineEdit_score = new QLineEdit(Superviser);
        lineEdit_score->setObjectName("lineEdit_score");
        lineEdit_score->setGeometry(QRect(180, 170, 113, 22));
        label = new QLabel(Superviser);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 451, 341));
        label->setPixmap(QPixmap(QString::fromUtf8(":/img/img/bg.jpg")));
        label->setScaledContents(true);
        label->raise();
        pushButton_envoyer->raise();
        team1->raise();
        team2->raise();
        lineEdit_score->raise();

        retranslateUi(Superviser);

        QMetaObject::connectSlotsByName(Superviser);
    } // setupUi

    void retranslateUi(QDialog *Superviser)
    {
        Superviser->setWindowTitle(QCoreApplication::translate("Superviser", "Dialog", nullptr));
        pushButton_envoyer->setText(QCoreApplication::translate("Superviser", "envoyer", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Superviser: public Ui_Superviser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUPERVISER_H
