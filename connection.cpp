#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect() {
    bool test = false;
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetFoot"); // Assure-toi que la source de données existe
    db.setUserName("hayder10");
    db.setPassword("0000");

    if (db.open()) {
        test = true;
    }
    return test;
}

void Connection::closeConnection() {
    db.close();
}
