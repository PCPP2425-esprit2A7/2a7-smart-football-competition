/********************************************************************************
** Form generated from reading UI file 'mainwindow_joueur.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_JOUEUR_H
#define UI_MAINWINDOW_JOUEUR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowJoueur
{
public:
    QWidget *centralwidget;
    QWidget *leftmenu;
    QPushButton *btn_supp;
    QPushButton *btn_joueur;
    QPushButton *btn_arb;
    QPushButton *btn_team;
    QPushButton *btn_match;
    QPushButton *btn_tickets;
    QWidget *box;
    QLabel *id;
    QLabel *name;
    QLabel *lastname;
    QLabel *age;
    QLabel *position;
    QLabel *note;
    QLineEdit *idEdit;
    QLineEdit *nameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *ageEdit;
    QComboBox *positCB;
    QLineEdit *noteEdit;
    QPushButton *cancel;
    QPushButton *add;
    QLabel *numberj;
    QLineEdit *numberEdit;
    QPushButton *modify;
    QLineEdit *searchEdit;
    QComboBox *tri;
    QLabel *logo;
    QPushButton *stat;
    QPushButton *supprimer;
    QTableView *tableView;
    QPushButton *pdfButton;
    QPushButton *voiceS;
    QLineEdit *lineEditQuestion;
    QPushButton *btnEnvoyer;
    QTextBrowser *textBrowserReponse;
    QPushButton *dark;
    QPushButton *light;
    QLabel *bg;
    QPushButton *home;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowJoueur)
    {
        if (MainWindowJoueur->objectName().isEmpty())
            MainWindowJoueur->setObjectName("MainWindowJoueur");
        MainWindowJoueur->resize(1527, 719);
        centralwidget = new QWidget(MainWindowJoueur);
        centralwidget->setObjectName("centralwidget");
        leftmenu = new QWidget(centralwidget);
        leftmenu->setObjectName("leftmenu");
        leftmenu->setGeometry(QRect(10, 100, 101, 481));
        leftmenu->setStyleSheet(QString::fromUtf8("#leftmenu {\n"
"background-color: #218555;} \n"
""));
        btn_supp = new QPushButton(leftmenu);
        btn_supp->setObjectName("btn_supp");
        btn_supp->setGeometry(QRect(20, 10, 61, 71));
        btn_supp->setStyleSheet(QString::fromUtf8("#btn_supp{\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/2.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}"));
        btn_joueur = new QPushButton(leftmenu);
        btn_joueur->setObjectName("btn_joueur");
        btn_joueur->setGeometry(QRect(0, 90, 93, 71));
        btn_joueur->setStyleSheet(QString::fromUtf8("\n"
"#btn_joueur {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/joueur-de-football.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}"));
        btn_arb = new QPushButton(leftmenu);
        btn_arb->setObjectName("btn_arb");
        btn_arb->setGeometry(QRect(0, 170, 93, 71));
        btn_arb->setStyleSheet(QString::fromUtf8("#btn_arb {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/carte-jaune.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}"));
        btn_team = new QPushButton(leftmenu);
        btn_team->setObjectName("btn_team");
        btn_team->setGeometry(QRect(0, 250, 93, 71));
        btn_team->setStyleSheet(QString::fromUtf8("#btn_team {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/4.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}"));
        btn_match = new QPushButton(leftmenu);
        btn_match->setObjectName("btn_match");
        btn_match->setGeometry(QRect(0, 330, 93, 71));
        btn_match->setStyleSheet(QString::fromUtf8("#btn_match {\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/3.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}"));
        btn_tickets = new QPushButton(leftmenu);
        btn_tickets->setObjectName("btn_tickets");
        btn_tickets->setGeometry(QRect(0, 420, 93, 61));
        btn_tickets->setStyleSheet(QString::fromUtf8("#btn_tickets {\n"
"    border: none;\n"
"    qproperty-icon:url(:/img/img/billet.png);\n"
"    qproperty-iconSize: 64px 64px; /* Ajuste la taille selon ton bouton */\n"
"}"));
        box = new QWidget(centralwidget);
        box->setObjectName("box");
        box->setGeometry(QRect(120, 100, 351, 481));
        box->setStyleSheet(QString::fromUtf8("#box{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}\n"
"\n"
""));
        id = new QLabel(box);
        id->setObjectName("id");
        id->setGeometry(QRect(20, 40, 63, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sylfaen")});
        font.setPointSize(12);
        font.setBold(true);
        id->setFont(font);
        id->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        name = new QLabel(box);
        name->setObjectName("name");
        name->setGeometry(QRect(20, 80, 71, 20));
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lastname = new QLabel(box);
        lastname->setObjectName("lastname");
        lastname->setGeometry(QRect(20, 120, 111, 20));
        lastname->setFont(font);
        lastname->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        age = new QLabel(box);
        age->setObjectName("age");
        age->setGeometry(QRect(20, 170, 71, 31));
        age->setFont(font);
        age->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        position = new QLabel(box);
        position->setObjectName("position");
        position->setGeometry(QRect(20, 210, 111, 20));
        position->setFont(font);
        position->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        note = new QLabel(box);
        note->setObjectName("note");
        note->setGeometry(QRect(20, 310, 63, 20));
        note->setFont(font);
        note->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        idEdit = new QLineEdit(box);
        idEdit->setObjectName("idEdit");
        idEdit->setGeometry(QRect(140, 40, 181, 31));
        idEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        nameEdit = new QLineEdit(box);
        nameEdit->setObjectName("nameEdit");
        nameEdit->setGeometry(QRect(140, 80, 181, 31));
        nameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        lastNameEdit = new QLineEdit(box);
        lastNameEdit->setObjectName("lastNameEdit");
        lastNameEdit->setGeometry(QRect(140, 120, 181, 31));
        lastNameEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        ageEdit = new QLineEdit(box);
        ageEdit->setObjectName("ageEdit");
        ageEdit->setGeometry(QRect(140, 160, 181, 31));
        ageEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        positCB = new QComboBox(box);
        positCB->addItem(QString());
        positCB->addItem(QString());
        positCB->addItem(QString());
        positCB->addItem(QString());
        positCB->setObjectName("positCB");
        positCB->setGeometry(QRect(140, 207, 181, 31));
        positCB->setStyleSheet(QString::fromUtf8("#pos {\n"
"    background-color: white;   /* White background */\n"
"    color: black;              /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;        /* Rounded edges */\n"
"    padding: 5px;              /* Inner spacing */\n"
"}"));
        positCB->setDuplicatesEnabled(true);
        noteEdit = new QLineEdit(box);
        noteEdit->setObjectName("noteEdit");
        noteEdit->setGeometry(QRect(140, 300, 181, 31));
        noteEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        cancel = new QPushButton(box);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(80, 390, 83, 29));
        cancel->setFont(font);
        cancel->setStyleSheet(QString::fromUtf8("#cancel{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        add = new QPushButton(box);
        add->setObjectName("add");
        add->setGeometry(QRect(180, 390, 83, 29));
        add->setFont(font);
        add->setStyleSheet(QString::fromUtf8("#add{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;\n"
"}"));
        numberj = new QLabel(box);
        numberj->setObjectName("numberj");
        numberj->setGeometry(QRect(20, 260, 111, 20));
        numberj->setFont(font);
        numberj->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        numberEdit = new QLineEdit(box);
        numberEdit->setObjectName("numberEdit");
        numberEdit->setGeometry(QRect(140, 257, 181, 31));
        numberEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        modify = new QPushButton(centralwidget);
        modify->setObjectName("modify");
        modify->setGeometry(QRect(1240, 340, 101, 29));
        modify->setFont(font);
        modify->setStyleSheet(QString::fromUtf8("#modify{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;\n"
"}"));
        searchEdit = new QLineEdit(centralwidget);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setGeometry(QRect(460, 17, 461, 31));
        searchEdit->setStyleSheet(QString::fromUtf8("#search{\n"
"border-radius:10px;\n"
"padding:5px;\n"
"background:white;\n"
"}\n"
"search{\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"   border: 2px solid #619D80; /* Green border */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        tri = new QComboBox(centralwidget);
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->addItem(QString());
        tri->setObjectName("tri");
        tri->setGeometry(QRect(1140, 90, 161, 28));
        tri->setStyleSheet(QString::fromUtf8("#comboBox_2{\n"
"border-radius:10px;\n"
"background:white;\n"
"}"));
        logo = new QLabel(centralwidget);
        logo->setObjectName("logo");
        logo->setGeometry(QRect(0, 0, 151, 101));
        logo->setPixmap(QPixmap(QString::fromUtf8(":/img/img/logo_yedkom-removebg.png")));
        logo->setScaledContents(true);
        stat = new QPushButton(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(1210, 10, 131, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sylfaen")});
        font1.setPointSize(12);
        stat->setFont(font1);
        stat->setStyleSheet(QString::fromUtf8("#stat{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#218555;\n"
"}"));
        supprimer = new QPushButton(centralwidget);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(1140, 340, 93, 29));
        supprimer->setFont(font);
        supprimer->setStyleSheet(QString::fromUtf8("#supprimer{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius:10px;\n"
"background:transparent;\n"
"}"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(650, 130, 701, 201));
        tableView->setStyleSheet(QString::fromUtf8("#tableView{\n"
"background:rgba(33, 133, 85, 0.4);\n"
" border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;\n"
"}\n"
""));
        pdfButton = new QPushButton(centralwidget);
        pdfButton->setObjectName("pdfButton");
        pdfButton->setGeometry(QRect(1300, 70, 61, 61));
        pdfButton->setStyleSheet(QString::fromUtf8("#pdfButton{\n"
"	\n"
"    border: none;\n"
"    qproperty-icon: url(:/img/img/1.png);\n"
"    qproperty-iconSize: 30px 30px; /* Ajuste la taille selon ton bouton */\n"
"}\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/img/pdf.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pdfButton->setIcon(icon);
        pdfButton->setFlat(true);
        voiceS = new QPushButton(centralwidget);
        voiceS->setObjectName("voiceS");
        voiceS->setGeometry(QRect(940, 20, 51, 29));
        lineEditQuestion = new QLineEdit(centralwidget);
        lineEditQuestion->setObjectName("lineEditQuestion");
        lineEditQuestion->setGeometry(QRect(830, 540, 211, 31));
        lineEditQuestion->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;  /* White background */\n"
"    color: black;             /* Black text */\n"
"    border: 2px solid #619D80; /* Green border */\n"
"    border-radius: 5px;       /* Slightly rounded edges */\n"
"    padding: 5px;             /* Spacing inside */\n"
"}\n"
""));
        btnEnvoyer = new QPushButton(centralwidget);
        btnEnvoyer->setObjectName("btnEnvoyer");
        btnEnvoyer->setGeometry(QRect(1050, 540, 61, 31));
        btnEnvoyer->setStyleSheet(QString::fromUtf8("#pushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	border-radius: 10px;\n"
"	padding: 5px;\n"
"	background:#619D80;\n"
"}"));
        textBrowserReponse = new QTextBrowser(centralwidget);
        textBrowserReponse->setObjectName("textBrowserReponse");
        textBrowserReponse->setGeometry(QRect(825, 340, 291, 192));
        textBrowserReponse->setStyleSheet(QString::fromUtf8("#textBrowserReponse{\n"
"    background-color: rgba(214, 215, 222, 0.4);\n"
"    border-radius: 20px;\n"
"\n"
"}\n"
"\n"
""));
        dark = new QPushButton(centralwidget);
        dark->setObjectName("dark");
        dark->setGeometry(QRect(120, 600, 93, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Sylfaen")});
        font2.setPointSize(12);
        font2.setBold(false);
        dark->setFont(font2);
        dark->setStyleSheet(QString::fromUtf8("#dark {\n"
"    background-color: #333; /* Dark gray background */\n"
"    color: white; /* White text */\n"
"    border: 2px solid #555; /* Slightly lighter border */\n"
"   border-radius: 10px; /* Rounded corners */\n"
"    padding: 5px 10px; /* Padding for better appearance */\n"
"}\n"
"#dark:hover {\n"
"    background-color: #444; /* Slightly lighter on hover */\n"
"    border: 2px solid #777;\n"
"}\n"
"\n"
"#dark:pressed {\n"
"    background-color: #222; /* Even darker when pressed */\n"
"    border: 2px solid #999;\n"
"}"));
        light = new QPushButton(centralwidget);
        light->setObjectName("light");
        light->setGeometry(QRect(20, 600, 93, 41));
        light->setFont(font2);
        light->setStyleSheet(QString::fromUtf8("#light {\n"
"    background-color:transparent; \n"
"    color: #333; \n"
"    border: 2px solid #ccc;\n"
"    border-radius: 10px;\n"
"    padding: 5px 10px; \n"
"}\n"
"\n"
"#light:hover {\n"
"    background-color: #e0e0e0;\n"
"    border: 2px solid #bbb;\n"
"}\n"
"\n"
"#light:pressed {\n"
"    background-color: #d0d0d0; \n"
"    border: 2px solid #999;\n"
"}"));
        bg = new QLabel(centralwidget);
        bg->setObjectName("bg");
        bg->setGeometry(QRect(0, -70, 1521, 741));
        bg->setStyleSheet(QString::fromUtf8("#bg {\n"
"    background-image: url(:/img/img/bg.jpg);\n"
"}\n"
""));
        bg->setScaledContents(false);
        home = new QPushButton(centralwidget);
        home->setObjectName("home");
        home->setGeometry(QRect(1290, 620, 93, 29));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        home->setFont(font3);
        home->setStyleSheet(QString::fromUtf8("#home{\n"
"\n"
"    border-radius: 10px;         /* Rounded corners */\n"
"    padding: 5px;                /* Padding for text */\n"
"    background: #218555\n"
"; }"));
        MainWindowJoueur->setCentralWidget(centralwidget);
        bg->raise();
        leftmenu->raise();
        box->raise();
        modify->raise();
        searchEdit->raise();
        tri->raise();
        logo->raise();
        stat->raise();
        supprimer->raise();
        tableView->raise();
        pdfButton->raise();
        voiceS->raise();
        lineEditQuestion->raise();
        btnEnvoyer->raise();
        textBrowserReponse->raise();
        dark->raise();
        light->raise();
        home->raise();
        menubar = new QMenuBar(MainWindowJoueur);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1527, 26));
        MainWindowJoueur->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowJoueur);
        statusbar->setObjectName("statusbar");
        MainWindowJoueur->setStatusBar(statusbar);

        retranslateUi(MainWindowJoueur);

        positCB->setCurrentIndex(-1);
        tri->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindowJoueur);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowJoueur)
    {
        MainWindowJoueur->setWindowTitle(QCoreApplication::translate("MainWindowJoueur", "MainWindow", nullptr));
        btn_supp->setText(QString());
        btn_joueur->setText(QString());
        btn_arb->setText(QString());
        btn_team->setText(QString());
        btn_match->setText(QString());
        btn_tickets->setText(QString());
        id->setText(QCoreApplication::translate("MainWindowJoueur", "Id :", nullptr));
        name->setText(QCoreApplication::translate("MainWindowJoueur", "Name :", nullptr));
        lastname->setText(QCoreApplication::translate("MainWindowJoueur", "Last Name:", nullptr));
        age->setText(QCoreApplication::translate("MainWindowJoueur", " Age :", nullptr));
        position->setText(QCoreApplication::translate("MainWindowJoueur", "Position :", nullptr));
        note->setText(QCoreApplication::translate("MainWindowJoueur", "Note :", nullptr));
        idEdit->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Enter id", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Name", nullptr));
        lastNameEdit->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Last Name", nullptr));
        ageEdit->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Age", nullptr));
        positCB->setItemText(0, QCoreApplication::translate("MainWindowJoueur", "Goalkeeper", nullptr));
        positCB->setItemText(1, QCoreApplication::translate("MainWindowJoueur", "Defender", nullptr));
        positCB->setItemText(2, QCoreApplication::translate("MainWindowJoueur", "Midfielder", nullptr));
        positCB->setItemText(3, QCoreApplication::translate("MainWindowJoueur", "Striker", nullptr));

        positCB->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Position", nullptr));
        noteEdit->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Note", nullptr));
        cancel->setText(QCoreApplication::translate("MainWindowJoueur", "Cancel", nullptr));
        add->setText(QCoreApplication::translate("MainWindowJoueur", "Add", nullptr));
        numberj->setText(QCoreApplication::translate("MainWindowJoueur", "Number :", nullptr));
        numberEdit->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Number", nullptr));
        modify->setText(QCoreApplication::translate("MainWindowJoueur", "Modify", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Search...", nullptr));
        tri->setItemText(0, QCoreApplication::translate("MainWindowJoueur", "All positions", nullptr));
        tri->setItemText(1, QCoreApplication::translate("MainWindowJoueur", "Goalkeeper", nullptr));
        tri->setItemText(2, QCoreApplication::translate("MainWindowJoueur", "Defender", nullptr));
        tri->setItemText(3, QCoreApplication::translate("MainWindowJoueur", "Midfielder", nullptr));
        tri->setItemText(4, QCoreApplication::translate("MainWindowJoueur", "Striker", nullptr));

        tri->setPlaceholderText(QCoreApplication::translate("MainWindowJoueur", "Filtre..", nullptr));
        logo->setText(QString());
        stat->setText(QCoreApplication::translate("MainWindowJoueur", "Report statics", nullptr));
        supprimer->setText(QCoreApplication::translate("MainWindowJoueur", "Delete", nullptr));
        pdfButton->setText(QString());
        voiceS->setText(QCoreApplication::translate("MainWindowJoueur", "voice", nullptr));
        btnEnvoyer->setText(QCoreApplication::translate("MainWindowJoueur", "Send", nullptr));
        dark->setText(QCoreApplication::translate("MainWindowJoueur", "Dark", nullptr));
        light->setText(QCoreApplication::translate("MainWindowJoueur", "Light", nullptr));
        bg->setText(QString());
        home->setText(QCoreApplication::translate("MainWindowJoueur", "Home", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowJoueur: public Ui_MainWindowJoueur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_JOUEUR_H
