#include "joueur.h"
#include <QtSql/QSqlError>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>

// Constructeur
Joueur::Joueur(int id, QString name, QString lastName, int age, QString position, int numberj, double note)
{
    this->id = id;
    this->name = name;
    this->lastName = lastName;
    this->age = age;
    this->position = position;
    this->numberj= numberj;
    this->note = note;

}

// Ajouter un joueur
bool Joueur::add()
{
    QSqlQuery query;
    query.prepare("INSERT INTO joueur (id, name, last_name, age, position, numberj, note) "
                  "VALUES (:id, :name, :last_name, :age, :position, :numberj, :note )");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":last_name", lastName);
    query.bindValue(":age", age);
    query.bindValue(":position", position);
    query.bindValue(":numberj", numberj);
    query.bindValue(":note", note);

    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError().text();  // Affiche l'erreur SQL
        return false;
    }

    return true;
}


// Afficher tous les joueurs
void Joueur::afficher(QTableView *tableView) {
    // Create a model for the QTableView
    QSqlQueryModel *model = new QSqlQueryModel();

    // Set the SQL query
    model->setQuery("SELECT id, name, last_name, age, position, numberj, note FROM joueur");

    // Set column headers (optional but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSITION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMBERJ"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOTE"));

    // Set the model to the QTableView
    tableView->setModel(model);

    // Optional: Adjust column sizing
    tableView->resizeColumnsToContents();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

// Supprimer un joueur
bool Joueur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM joueur WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// Modifier un joueur
bool Joueur::modify(int id)
{
    QSqlQuery query;

    query.prepare("UPDATE joueur SET name = :name, last_name = :lastName, age = :age, position = :position, numberj = :numberj, note = :note "
                  "WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":lastName", lastName);
    query.bindValue(":age", age);
    query.bindValue(":position", position);
    query.bindValue(":numberj", numberj);
    query.bindValue(":note", note);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la mise à jour : " << query.lastError().text();
        return false;
    }

    qDebug() << "Modification réussie pour l'ID : " << id;
    return true;
}




QSqlQueryModel* Joueur::trier_par_position()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM joueur ORDER BY "
                    "CASE "
                    "WHEN position+ = 'Goalkeeper' THEN 1 "
                    "WHEN position = 'Defender' THEN 2 "
                    "WHEN position = 'Midfielder' THEN 3 "
                    "WHEN position = 'Striker' THEN 4 "
                    "ELSE 5 END");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL :" << model->lastError().text();
    } else {
        qDebug() << "Tri par position exécuté avec succès.";
    }

    return model;
}



