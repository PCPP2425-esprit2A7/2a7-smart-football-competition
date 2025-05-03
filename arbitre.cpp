#include "arbitre.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>



arbitre::arbitre(int id, QString name, QString last_name ,int nb_carton, int nb_match_a, QString category, QString email ) {
    this->id = id;
    this->name = name;
    this->last_name = last_name;
    this->nb_carton = nb_carton;
    this->nb_match_a = nb_match_a;
    this->category = category;
    this->email = email;

    model = new QSqlQueryModel();

}



void arbitre::afficher(QTableView *tableView) {
    // Create a model for the QTableView
    if (!model) model = new QSqlQueryModel();
    model->clear();


    // Set the SQL query
    model->setQuery("SELECT id, name, last_name, nb_carton, nb_match_a, category, email FROM arbitre");
    // Vérifier si la requête a échoué
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL : " << model->lastError().text();
        return;
    }

    // Set column headers (optional but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_CARTON"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NB_MATCH_A"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CATEGORY"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));


    // Set the model to the QTableView
    tableView->setModel(model);

    // Optional: Adjust column sizing
    tableView->resizeColumnsToContents();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Check if the model has data
    if (model->rowCount() == 0) {
        qDebug() << "No data found for arbitres!";
    } else {
        qDebug() << "Found " << model->rowCount() << " arbitres!";
    }
}
bool arbitre::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO arbitre (id, name, last_name, nb_carton, nb_match_a, category,  email) "
                  "VALUES (:id, :name, :last_name, :nb_carton, :nb_match_a, :category  , :email)");

    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":last_name", last_name);
    query.bindValue(":nb_carton", nb_carton);
    query.bindValue(":nb_match_a", nb_match_a);
    query.bindValue(":category", category);
    query.bindValue(":email", email);


    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur d'ajout arbitre: " << query.lastError();
        return false;
    }

}
bool arbitre::modifier(int id, QString name, QString last_name, int nb_carton, int nb_match_a, QString category, QString email) {
    QSqlQuery query;
    query.prepare("UPDATE arbitre SET name = :name, last_name = :last_name, nb_carton = :nb_carton, "
                  "nb_match_a = :nb_match_a, category = :category, email = :email WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":last_name", last_name);
    query.bindValue(":nb_carton", nb_carton);
    query.bindValue(":nb_match_a", nb_match_a);
    query.bindValue(":category", category);
    query.bindValue(":email", email);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la modification de l'arbitre: " << query.lastError();
        return false;
    }
}

bool arbitre::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM arbitre WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        qDebug() << "Arbitre supprimé avec succès.";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression de l'arbitre: " << query.lastError();
        return false;
    }
}
QSqlQueryModel* arbitre::rechercher(QString name) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM arbitre WHERE name LIKE :name");
    query.bindValue(":name", "%" + name + "%"); // Recherche partielle
    query.exec();
    model->setQuery(query);

    // Définir les en-têtes de colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_CARTON"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NB_MATCH_A"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CATEGORY"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));

    return model;
}
// Définition de la fonction filtrerArbitres
void arbitre::filtrerArbitres(QComboBox *comboBox, QTableView *tableView) {
    if (!comboBox || !tableView) {
        qDebug() << "Erreur : ComboBox ou TableView est nul !";
        return;
    }

    QString categorieSelectionnee = comboBox->currentText();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM arbitre WHERE categorie = :categorie");
    query.bindValue(":categorie", categorieSelectionnee);

    if (!query.exec()) {
        qDebug() << "Erreur SQL : " << query.lastError().text();
        return;
    }

    model->setQuery(query);
    tableView->setModel(model);
}

// Configuration UI et connexion des signaux
void arbitre::setupUI(QComboBox *comboBox, QTableView *tableView) {
    comboBox->addItem("National");
    comboBox->addItem("International");
    comboBox->addItem("Fédéral");
    comboBox->addItem("Local");

    //connect(comboBox, &QComboBox::currentTextChanged, this, [this, comboBox, tableView]() { this->filtrerArbitres(comboBox, tableView);});


}
