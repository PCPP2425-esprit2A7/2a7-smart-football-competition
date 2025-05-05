#include "welcom_page.h"
#include "ui_welcom_page.h"
#include "mainwindow_supporteur.h"
#include "mainwindow_joueur.h"
#include "mainwindow_arbitre.h"
#include "mainwindow_match.h"
#include "mainwindow_billet.h"
#include "mainwindow_equipe.h"
welcom_page::welcom_page(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::welcom_page)
{
    ui->setupUi(this);
}

welcom_page::~welcom_page()
{
    delete ui;
}

void welcom_page::on_supporteur_clicked()
{
    this->close(); // Cache la fenêtre actuelle (facultatif)
    MainWindowSupporteur *w1 = new MainWindowSupporteur(); // Crée une nouvelle fenêtre
    w1->setAttribute(Qt::WA_DeleteOnClose); // Pour éviter les fuites mémoire
    w1->show(); // Affiche la nouvelle fenêtre
}


void welcom_page::on_joueur_clicked()
{
    this->close(); // Cache la fenêtre actuelle (facultatif)
    MainWindowJoueur *w2 = new MainWindowJoueur(); // Crée une nouvelle fenêtre
    w2->setAttribute(Qt::WA_DeleteOnClose); // Pour éviter les fuites mémoire
    w2->show(); // Affiche la nouvelle fenêtre
}


// void welcom_page::on_equipe_clicked()
// {
//     this->close(); // Cache la fenêtre actuelle (facultatif)
//     Main *w2 = new MainWindowJoueur(); // Crée une nouvelle fenêtre
//     w2->setAttribute(Qt::WA_DeleteOnClose); // Pour éviter les fuites mémoire
//     w2->show(); // Affiche la nouvelle fenêtre
// }


void welcom_page::on_arbitre_clicked()
{
    this->close(); // Cache la fenêtre actuelle (facultatif)
    MainWindowArbitre *w3 = new MainWindowArbitre(); // Crée une nouvelle fenêtre
    w3->setAttribute(Qt::WA_DeleteOnClose); // Pour éviter les fuites mémoire
    w3->show(); // Affiche la nouvelle fenêtre
}


void welcom_page::on_match_clicked()
{
    this->close(); // Cache la fenêtre actuelle (facultatif)
    MainWindowMatch *w4 = new MainWindowMatch(); // Crée une nouvelle fenêtre
    w4->setAttribute(Qt::WA_DeleteOnClose); // Pour éviter les fuites mémoire
    w4->show(); // Affiche la nouvelle fenêtre
}


void welcom_page::on_billet_clicked()
{
    this->close(); // Cache la fenêtre actuelle (facultatif)
    MainWindowBillet *w5 = new MainWindowBillet(); // Crée une nouvelle fenêtre
    w5->setAttribute(Qt::WA_DeleteOnClose); // Pour éviter les fuites mémoire
    w5->show(); // Affiche la nouvelle fenêtre
}


void welcom_page::on_equipe_clicked()
{
    this->close(); // Cache la fenêtre actuelle (facultatif)
    MainWindowEquipe *w6 = new MainWindowEquipe(); // Crée une nouvelle fenêtre
    w6->setAttribute(Qt::WA_DeleteOnClose); // Pour éviter les fuites mémoire
    w6->show(); // Affiche la nouvelle fenêtre
}

