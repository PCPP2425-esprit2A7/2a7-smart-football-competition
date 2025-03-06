#include "gestion_billet.h"
#include <QDebug>
#include <QSqlQuery>
#include <QTableWidgetItem>
// Default constructor
gestion_billet::gestion_billet() {
    id = 0;
    type = "";
    price = 0;
    quantity = 0;
    area = "";
    date_issue = QDate();
    date_event = QDate();
}

// Parameterized constructor
gestion_billet::gestion_billet(int id, QString type, int price, int quantity, QString area, QDate date_issue, QDate date_event) {
    this->id = id;
    this->type = type;
    this->price = price;
    this->quantity = quantity;
    this->area = area;
    this->date_issue = date_issue;
    this->date_event = date_event;
}

// Getters
int gestion_billet::getid() { return id; }
QString gestion_billet::gettype() { return type; }
int gestion_billet::getprice() { return price; }
int gestion_billet::getquantity() { return quantity; }
QString gestion_billet::getarea() { return area; }
QDate gestion_billet::getdate_issue() { return date_issue; }
QDate gestion_billet::getdate_event() { return date_event; }

// Setters
void gestion_billet::setid(int id) { this->id = id; }
void gestion_billet::settype(QString type) { this->type = type; }
void gestion_billet::setprice(int price) { this->price = price; }
void gestion_billet::setquantity(int quantity) { this->quantity = quantity; }
void gestion_billet::setarea(QString area) { this->area = area; }
void gestion_billet::setdate_issue(QDate date_issue) { this->date_issue = date_issue; }
void gestion_billet::setdate_event(QDate date_event) { this->date_event = date_event; }

// Add a new ticket to the database
bool gestion_billet::add() {
    QSqlQuery query;
    QString res = QString::number(id );
    // Prepare the SQL query for insertion
    query.prepare("INSERT INTO BILLET (id, type, price, quantity, area, date_issue, date_event) "
                  "VALUES (:ID, :TYPE, :PRICE, :QUANTITY, :AREA, :DATE_ISSUE, :DATE_EVENT)");

    // Bind values to the query
    query.bindValue(":ID", res);
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
void gestion_billet::afficher(QTableWidget *tableWidget)
{
    // Execute SQL query to get ticket data
    QSqlQuery query("SELECT id, type, price, quantity, area, date_issue, date_event FROM BILLET");

    // Clear existing rows before updating
    tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        // Insert a new row in the table widget
        tableWidget->insertRow(row);

        // Populate each column with database values
        tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("id").toString()));
        tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("type").toString()));
        tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("price").toString()));
        tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("quantity").toString()));
        tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("area").toString()));
        tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("date_issue").toString()));
        tableWidget->setItem(row, 6, new QTableWidgetItem(query.value("date_event").toString()));

        row++;
    }
}


// Modify a ticket
bool gestion_billet::modify(int id) {
    QSqlQuery query;

    // Check if the ticket exists
    query.prepare("SELECT TYPE, PRICE, QUANTITY, AREA, DATE_ISSUE, DATE_EVENT FROM BILLET WHERE id=:ID");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve existing ticket:" << query.lastError().text();
        return false;
    }

    if (!query.next()) {
        // Ticket with the specified id doesn't exist
        qDebug() << "Ticket with id" << id << "does not exist.";
        return false;
    }

    // Retrieve existing values
    QString currenttype = query.value(0).toString();
    int currentprice = query.value(1).toInt();
    int currentquantity = query.value(2).toInt();
    QString currentarea = query.value(3).toString();
    QDate currentDateEm = query.value(4).toDate();
    QDate currentDateEvent = query.value(5).toDate();

    // Check if new values are the same as existing values
    if (type == currenttype && price == currentprice && quantity == currentquantity &&
        area == currentarea && date_issue == currentDateEm && date_event == currentDateEvent) {
        qDebug() << "No changes detected for ticket with id" << id;
        return false;
    }

    // Proceed to update the ticket if changes were made
    query.prepare("UPDATE BILLET SET type=:TYPE, price=:PRICE, quantity=:QUANTITY, area=:AREA, date_issue=:DATE_ISSUE, date_event=:DATE_EVENT WHERE id=:ID");
    query.bindValue(":ID", id);
    query.bindValue(":TYPE", type);
    query.bindValue(":PRICE", price);
    query.bindValue(":QUANTITY", quantity);
    query.bindValue(":AREA", area);
    query.bindValue(":DATE_ISSUE", date_issue);
    query.bindValue(":DATE_EVENT", date_event);

    if (!query.exec()) {
        qDebug() << "Failed to modify ticket:" << query.lastError().text();
        return false;
    }

    qDebug() << "Ticket with id" << id << "successfully modified.";
    return true;
}
// Delete a ticket
/*bool Gbillet::delete_2(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM BILLET WHERE id = :ID");
    query.bindValue(":ID", id);

    if (!query.exec()) {
        qDebug() << "Error deleting ticket:" << query.lastError().text();
        return false;
    }

    // Check if any rows were affected by the delete operation
    return query.numRowsAffected() > 0;


}*/
