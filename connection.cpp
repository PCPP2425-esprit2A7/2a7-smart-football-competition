#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>

#include "connection.h"
#include <QDebug>

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










/*
Connection::Connection() {}
bool Connection::createconnect() {
     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");


   //feffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
       // QSqlDatabase db = QSqlDatabase::addDatabase("QOCI"); // Pour Oracle
        db.setHostName("localhost"); // Ou l'adresse de votre serveur Oracle
        db.setDatabaseName("ProjetFoot"); // Nom du service Oracle
        db.setUserName("hayder10");
        db.setPassword("0000");
    if (!db.open()) {
        qDebug() << "Erreur connexion :" << db.lastError().text();
        return false;
    }
    if (!QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("ProjetFoot");
    } else {
        QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
    }

    // Créer la table MATCH si inexistante
   QSqlQuery query;
    QString createTable =
        "CREATE TABLE IF NOT EXISTS MATCH ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "DATE_TIME TEXT NOT NULL, "
        "PLACE TEXT NOT NULL, "
        "SCORE TEXT NOT NULL, "
        "STATUS TEXT NOT NULL, "
        "TEAM1 INTEGER, "
        "TEAM2 INTEGER, "
        "ARBITRE TEXT, "
        "FOREIGN KEY(TEAM1) REFERENCES EQUIPE(ID), "
        "FOREIGN KEY(TEAM2) REFERENCES EQUIPE(ID))";
//if (!query.exec(createTable)) {
       // qDebug() << "Erreur création table :" << query.lastError().text();
      //  return false;
   // }

    return true;
}*/
/*
    bool Connection::createconnect() {
        QSqlDatabase db = QSqlDatabase::addDatabase("QOCI"); // Pour Oracle
        db.setHostName("localhost"); // Ou l'adresse de votre serveur Oracle
        db.setDatabaseName("HAYDER10"); // Nom du service Oracle
        db.setUserName("ProjetFoot");
        db.setPassword("0000");

        if (!db.open()) {
            qDebug() << "Erreur connexion Oracle:" << db.lastError().text();
            return false;
        }

        // Vérification que la table MATCH existe avec la bonne structure
        QSqlQuery checkTable("SELECT * FROM HAYDER10.MATCH WHERE ROWNUM = 1");
        if(checkTable.lastError().isValid()) {
            qDebug() << "Structure table MATCH incorrecte:" << checkTable.lastError().text();
            return false;
        }

        return true;
    }
*/
