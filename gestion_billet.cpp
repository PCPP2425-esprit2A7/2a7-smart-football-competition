#include "gestion_billet.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
// Default constructor
gestion_billet::gestion_billet() {
    id = "";
    type = "";
    price = 0;
    quantity = 0;
    area = "";
    date_issue = QDate();
    date_event = QDate();
}

// Parameterized constructor
gestion_billet::gestion_billet(QString id, QString type, int price, int quantity, QString area, QDate date_issue, QDate date_event) {
    this->id = id;
    this->type = type;
    this->price = price;
    this->quantity = quantity;
    this->area = area;
    this->date_issue = date_issue;
    this->date_event = date_event;
}

// Getters
QString gestion_billet::getid() { return id; }
QString gestion_billet::gettype() { return type; }
int gestion_billet::getprice() { return price; }
int gestion_billet::getquantity() { return quantity; }
QString gestion_billet::getarea() { return area; }
QDate gestion_billet::getdate_issue() { return date_issue; }
QDate gestion_billet::getdate_event() { return date_event; }

// Setters
void gestion_billet::setid(QString id) { this->id = id; }
void gestion_billet::settype(QString type) { this->type = type; }
void gestion_billet::setprice(int price) { this->price = price; }
void gestion_billet::setquantity(int quantity) { this->quantity = quantity; }
void gestion_billet::setarea(QString area) { this->area = area; }
void gestion_billet::setdate_issue(QDate date_issue) { this->date_issue = date_issue; }
void gestion_billet::setdate_event(QDate date_event) { this->date_event = date_event; }

//controle de saisie
bool gestion_billet::isValid(){
    // Vérification du prix entre 25 et 100
    if (price < 25 || price > 100) {
        qDebug() << "Prix invalide : " << price;
        return false;
    }

    // Quantité doit être ≥ 1
    if (quantity < 1) {
        qDebug() << "Quantité invalide : " << quantity;
        return false;
    }

    // Dates valides et après le 01/01/2025
    QDate minDate(2025, 1, 1);
    if (!date_issue.isValid() || !date_event.isValid()) {
        qDebug() << "Date(s) invalide(s).";
        return false;
    }

    if (date_issue < minDate || date_event < minDate) {
        qDebug() << "Les dates doivent être postérieures au 01/01/2025.";
        return false;
    }

    return true;
}



// Add a new ticket to the database
bool gestion_billet::add() {
    QSqlQuery query;
    if (!isValid()) {
        qDebug() << "add invalid";
        return false;
    }
    // Prepare the SQL query for insertion
    query.prepare("INSERT INTO BILLET (id, type, price, quantity, area, date_issue, date_event) "
                  "VALUES (:ID, :TYPE, :PRICE, :QUANTITY, :AREA, :DATE_ISSUE, :DATE_EVENT)");

    // Bind values to the query
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    query.bindValue(":PRICE", price);
    query.bindValue(":QUANTITY", quantity);
    query.bindValue(":AREA", area);
    query.bindValue(":DATE_ISSUE", date_issue);
    query.bindValue(":DATE_EVENT", date_event);

    // Execute the query and return the result
    if (!query.exec()) {
        qDebug() << "Error adding ticket:" << query.lastError().text();
        return false;
    }
    return true;
}

// Display all tickets
void gestion_billet::afficher(QTableView *tableView) {
    // Create a model for the QTableView
    QSqlQueryModel *model = new QSqlQueryModel();

    // Set the SQL query
    model->setQuery("SELECT id, type, price, quantity, area, date_issue, date_event FROM BILLET");

    // Set column headers (optional but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Area"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Issued"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Event Date"));

    // Set the model to the QTableView
    tableView->setModel(model);

    // Optional: Adjust column sizing
    tableView->resizeColumnsToContents();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

// Modify a ticket
bool gestion_billet::modify(int id)
{
    QSqlQuery query;
    if (!isValid()) {
        qDebug() << "modify invalid";
        return false;
    }
    // Prepare the update query for modifying ticket data
    query.prepare("UPDATE BILLET SET type = :type, price = :price, quantity = :quantity, area = :area, date_issue = :date_issue, date_event = :date_event WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":type", type);
    query.bindValue(":price", price);
    query.bindValue(":quantity", quantity);
    query.bindValue(":area", area);
    query.bindValue(":date_issue", date_issue);
    query.bindValue(":date_event", date_event);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la mise à jour : " << query.lastError().text();
        return false;
    }

    qDebug() << "Modification réussie pour l'ID : " << id;
    return true;
}

// Delete a ticket
bool gestion_billet::delete_2(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM BILLET WHERE id = :ID");
    query.bindValue(":ID", id);

    if (!query.exec()) {
        qDebug() << "Error deleting ticket:" << query.lastError().text();
        return false;
    }

    // Check if any rows were affected by the delete operation
    return query.numRowsAffected() > 0;


}

QSqlQueryModel* gestion_billet::triPrixCroissant() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Requête pour trier par prix croissant
    QString queryStr = "SELECT id, type, price, quantity, area, date_issue, date_event,TICKETS FROM BILLET ORDER BY price ASC";

    model->setQuery(queryStr);

    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date d'émission"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date de l'événement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Ticket Image"));

    return model;
}
QSqlQueryModel* gestion_billet::triPrixDecroissant() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Requête pour trier par prix décroissant
    QString queryStr = "SELECT id, type, price, quantity, area, date_issue, date_event,TICKETS FROM BILLET ORDER BY price DESC";

    model->setQuery(queryStr);

    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date d'émission"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date de l'événement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Ticket Image"));

    return model;
}
QSqlQueryModel* gestion_billet::triid() {
    QSqlQueryModel* model = new QSqlQueryModel();

    // Requête pour trier par prix décroissant
    QString queryStr = "SELECT id, type, price, quantity, area, date_issue, date_event,TICKETS FROM BILLET ORDER BY id";

    model->setQuery(queryStr);

    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Zone"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date d'émission"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date de l'événement"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Ticket Image"));

    return model;
}
