#include "supporteur.h"
#include <QDebug>
#include "connection.h"
#include <QDate>
#include <QString>

supporteur::supporteur() {
    id = 0;
    NAME = "";
    LAST_NAME = "";
    DATE_NAIS = QDate();
    GRADE = 0;
}

supporteur::supporteur(int id, QString NAME, QString LAST_NAME, QDate DATE_NAIS, int GRADE) {
    this->id = id;
    this->NAME = NAME;
    this->LAST_NAME = LAST_NAME;
    this->DATE_NAIS = DATE_NAIS;
    this->GRADE = GRADE;
}

int supporteur::getid() { return id; }
QString supporteur::getNAME() { return NAME; }
QString supporteur::getLAST_NAME() { return LAST_NAME; }
QDate supporteur::getDATE_NAIS() { return DATE_NAIS; }
int supporteur::getGRADE() { return GRADE; }

// Setters
void supporteur::setid(int id) { this->id = id; }
void supporteur::setNAME(QString NAME) { this->NAME = NAME; }
void supporteur::setLAST_NAME(QString LAST_NAME) { this->LAST_NAME = LAST_NAME; }
void supporteur::setDATE_NAIS(QDate DATE_NAIS) { this->DATE_NAIS = DATE_NAIS; }
void supporteur::setGRADE(int GRADE) { this->GRADE = GRADE; }

bool supporteur::ajouter() {
    QSqlQuery query;

    query.prepare("INSERT INTO supporteur (id, NAME, LAST_NAME, DATE_NAIS, GRADE) "
                  "VALUES (:id, :NAME, :LAST_NAME, :DATE_NAIS, :GRADE)");

    query.bindValue(":id", id);
    query.bindValue(":NAME", NAME);
    query.bindValue(":LAST_NAME", LAST_NAME);
    query.bindValue(":DATE_NAIS", DATE_NAIS);
    query.bindValue(":GRADE", GRADE);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout :" << query.lastError().text();
        return false;
    }

    return true;
}



QSqlQueryModel* supporteur::afficher() {
    // Create a new query model
    QSqlQueryModel* model = new QSqlQueryModel();

    // Set the SQL query to select all columns from the "client" table
    model->setQuery("SELECT * FROM SUPPORTEUR");

    // Set the headers for each column in the model
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("GRADE"));
    // Return the created model
    return model;
}



bool supporteur::modifier(int id) {
    QSqlQuery query;

    // Proceed to update the client if changes were made
    query.prepare("UPDATE SUPPORTEUR SET NAME=:NAME, LAST_NAME=:LAST_NAME, DATE_NAIS=:DATE_NAIS, GRADE=:GRADE WHERE id=:id");
    query.bindValue(":id", id);
    query.bindValue(":NAME", NAME);
    query.bindValue(":LAST_NAME", LAST_NAME);
    query.bindValue(":DATE_NAIS", DATE_NAIS);
    query.bindValue(":GRADE", GRADE);


    if (!query.exec()) {
        qDebug() << "Failed to modify supporteur:" << query.lastError().text();
        return false;
    }

    qDebug() << "supporteur with id" << id << "successfully modified.";
    return true;
}



bool supporteur::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM SUPPORTEUR WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        return false; // Query execution failed
    }

    // Check if any rows were affected by the delete operation
    return query.numRowsAffected() > 0;
}


QSqlQueryModel* supporteur::tridateNaissanceAsc()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id, NAME, LAST_NAME, DATE_NAIS, GRADE FROM SUPPORTEUR ORDER BY DATE_NAIS ASC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("GRADE"));

    return model;
}

QSqlQueryModel* supporteur::tridateNaissanceDesc()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT id, NAME, LAST_NAME, DATE_NAIS, GRADE FROM SUPPORTEUR ORDER BY DATE_NAIS DESC");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("GRADE"));

    return model;
}

