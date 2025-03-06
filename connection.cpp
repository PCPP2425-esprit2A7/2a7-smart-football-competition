#include "connection.h"

connection::connection() {}
bool connection::createconnect() {
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetFoot");
    db.setUserName("hayder10");
    db.setPassword("0000");

    if (db.open())
        test=true;


    return test;
}
