#include "generate_tickets.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
void generate_tickets::afficher_s(QTableView *tableView) {
    // Création du modèle pour la QTableView
    QSqlQueryModel *model = new QSqlQueryModel();

    // Exécution de la requête SQL
    model->setQuery("SELECT ID,NAME,LAST_NAME FROM SUPPORTEUR");

    // Définition des noms des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));

    // Associer le modèle au QTableView
    tableView->setModel(model);

    // Ajuster la taille des colonnes
    tableView->resizeColumnsToContents();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
void generate_tickets::afficher_m(QTableView *tableView){
    // Création du modèle pour la QTableView
    QSqlQueryModel *model = new QSqlQueryModel();


    // Exécution de la requête SQL
    model->setQuery("SELECT DATE_TIME,PLACE,TEAM1,TEAM2 FROM MATCH ");

    // Définition des noms des colonnes
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATE_TIME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PLACE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEAM1"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEAM2"));
    // Associer le modèle au QTableView
    tableView->setModel(model);

    // Ajuster la taille des colonnes
    tableView->resizeColumnsToContents();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
void generate_tickets::afficher_b(QTableView *tableView){
    // Création du modèle pour la QTableView
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve ticket data
    model->setQuery("SELECT id, type, price, area, date_issue FROM BILLET");

    // Set column headers (optional, but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Area"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Issue"));


    // Associer le modèle au QTableView
    tableView->setModel(model);

    // Ajuster la taille des colonnes
    tableView->resizeColumnsToContents();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
