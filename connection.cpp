#include "connection.h"

Connection::Connection() {
    // Initialisation de la connexion avec ODBC
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("ProjetFoot"); // Le DSN défini dans ODBC
    db.setUserName("hayder10");        // Nom d'utilisateur Oracle
    db.setPassword("0000"); // Mot de passe Oracle
}

bool Connection::createconnect() {
    if (!db.open()) {
        qDebug() << "Erreur de connexion à la base de données : " << db.lastError().text();
        return false;
    }
    qDebug() << "Connexion réussie à Oracle via ODBC !";
    return true;
}

void Connection::closeConnection() {
    db.close();
    qDebug() << "Connexion Oracle fermée.";
}
