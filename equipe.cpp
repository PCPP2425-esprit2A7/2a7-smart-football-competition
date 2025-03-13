#include "equipe.h"
#include <QSqlError>  // Ajoute cette ligne pour utiliser QSqlError
#include <QSqlQuery>   // Assurez-vous d'avoir aussi cette ligne
#include <QSqlQueryModel>
#include <QTableView>

//new
Equipe::Equipe(int id, QString team_name, QDate creation_date,  int prizes, QString coach)
{
    this->id=id;
    this->team_name=team_name;
    this->creation_date=creation_date;
    this->prizes=prizes;
    this->coach=coach;
}
bool Equipe::ajouter() {

    QSqlQuery query;


    QString res = QString::number(id );


    query.prepare("INSERT INTO EQUIPE (id,team_name,creation_date,prizes,coach) "
                  "VALUES (:id, :team_name, :creation_date, :prizes, :coach)");


    query.bindValue(":id", res);
    query.bindValue(":team_name", team_name);
    query.bindValue(":creation_date", creation_date);
    query.bindValue(":prizes", prizes);
    query.bindValue(":coach", coach);
    // Exécution de la requête et retour du résultat
    return query.exec(); // Renvoie true si l'insertion a réussi, false sinon

}
void Equipe::afficher(QTableView *tableView)
 {
    // Create a new query model
    QSqlQueryModel* model = new QSqlQueryModel();

    // Set the SQL query to select all columns from the "client" table
    model->setQuery("SELECT * FROM EQUIPE");

    // Set the headers for each column in the model
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("team_name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("creation_date"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prizes"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("coach"));
    tableView->setModel(model);

    // Optional: Adjust column sizing
    tableView->resizeColumnsToContents();
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
bool Equipe::modify(int id)
{
    QSqlQuery query;

    // Prepare the update query for modifying ticket data
    query.prepare("UPDATE EQUIPE SET  id = :id, team_name = :team_name,  creation_date = :creation_date, prizes = :prizes, coach = :coach WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":team_name", team_name);
    query.bindValue(":creation_date", creation_date);
    query.bindValue(":prizes", prizes);
    query.bindValue(":coach", coach);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la mise à jour : " << query.lastError().text();
        return false;
    }

    qDebug() << "Modification réussie pour l'ID : " << id;
    return true;
}
bool Equipe::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPE WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        return false; // Query execution failed
    }

    // Check if any rows were affected by the delete operation
    return query.numRowsAffected() > 0;
}



//new
// Constructeurs
Equipe::Equipe() : id(0), team_name(""), creation_date(QDate::currentDate()), prizes(0), coach("") {}


//Equipe::Equipe(int id, QString team_name, QDate creation_date,  int prizes, QString coach)
//: id(id), team_name(team_name), creation_date(creation_date), prizes(prizes), coach(coach) {}

// Getters
int Equipe::getid() const {
    return id;
}

QString Equipe::getteam_name() const {
    return team_name;
}

QDate Equipe::getcreation_date() const {
    return creation_date;
}

int Equipe::getprizes() const {
    return prizes;
}
QString Equipe::getcoach() const{
    return coach;
}
// Setters
void Equipe::setid(int id) {
    this->id = id;
}

void Equipe::setteam_name(QString team_name) {
    this->team_name = team_name;
}

void Equipe::setcreation_date(QDate creation_date) {
    this->creation_date = creation_date;
}

void Equipe::setprizes(int prizes) {
    this->prizes = prizes;
}
void Equipe::setcoach(QString coach){
    this->coach=coach;
}
