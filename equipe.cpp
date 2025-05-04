#include "equipe.h"
#include <QSqlError>  // Ajoute cette ligne pour utiliser QSqlError
#include <QSqlQuery>   // Assurez-vous d'avoir aussi cette ligne
#include <QSqlQueryModel>
#include <QTableView>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QCoreApplication>
#include <QStandardPaths>

//constructeur
Equipe::Equipe(int id, QString team_name, QDate creation_date,  int prizes, QString coach)
{
    this->id=id;
    this->team_name=team_name;
    this->creation_date=creation_date;
    this->prizes=prizes;
    this->coach=coach;
}
bool Equipe::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("INSERT INTO EQUIPE (id, team_name, creation_date, prizes, coach) "
                  "VALUES (:id, :team_name, :creation_date, :prizes, :coach)");

    query.bindValue(":id", res);
    query.bindValue(":team_name", team_name);
    query.bindValue(":creation_date", creation_date);
    query.bindValue(":prizes", prizes);
    query.bindValue(":coach", coach);

    bool success = query.exec();
    if (success) {
        QString description = "Ajout de l'équipe : " + team_name;
        ecrireDansFichierHistorique(description);
    }


}

QSqlQueryModel* Equipe::chercher_par_nom(QString nom_equipe)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPE WHERE TEAM_NAME LIKE :nom_equipe");
    query.bindValue(":nom_equipe", "%" + nom_equipe + "%"); // Pour une recherche partielle

    query.exec();
    model->setQuery(std::move(query));


    return model;
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
     QString res = QString::number(id);

     query.prepare("UPDATE EQUIPE SET team_name = :team_name, creation_date = :creation_date, prizes = :prizes, coach = :coach "
                   "WHERE id = :id");

     query.bindValue(":id", res);
     query.bindValue(":team_name", team_name);
     query.bindValue(":creation_date", creation_date);
     query.bindValue(":prizes", prizes);
     query.bindValue(":coach", coach);

     bool success = query.exec();
     if (success) {
         QString description = "Ajout de l'équipe : " + team_name;
         ecrireDansFichierHistorique(description);
     }


 }

 bool Equipe::supprimer(int id)
 {
     QSqlQuery query;
     query.prepare("DELETE FROM EQUIPE WHERE id = :id");
     query.bindValue(":id", id);

     bool success = query.exec();
     if (success) {
         QString description = "Ajout de l'équipe : " + team_name;
         ecrireDansFichierHistorique(description);
     }


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
QSqlQueryModel* Equipe::trier_par_date_asc()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPE ORDER BY CREATION_DATE ASC");
    return model;
}

QSqlQueryModel* Equipe::trier_par_date_desc()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM EQUIPE ORDER BY CREATION_DATE DESC");
    return model;
}

QSqlQueryModel* Equipe::statistiques_par_prix()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT PRIZES, COUNT(*) AS nombre_equipes "
                    "FROM EQUIPE "
                    "GROUP BY PRIZES "
                    "ORDER BY PRIZES");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nombre de prix"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre d'équipes"));

    return model;
}
bool Equipe::ajouter_historique(QString action_type, QString description)
{
    QSqlQuery query;
    query.prepare("INSERT INTO HISTORIQUE (ID, ACTION_TYPE, ACTION_DATE, DESCRIPTION) "
                  "VALUES (seq_historique.NEXTVAL, :action_type, SYSDATE, :description)");
    query.bindValue(":action_type", action_type);
    query.bindValue(":description", description);

    bool success = query.exec();

    if (!success) {
        qDebug() << "Erreur lors de l'ajout dans historique :" << query.lastError().text();
    } else {
        qDebug() << "Ajout dans historique réussi.";
    }

    return success;
}
void Equipe::ajouter_historique_fichier(QString action_type, QString description)
{
    QFile file("historique.txt"); // Le fichier sera créé à côté de ton .exe
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        QString dateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        out << action_type << " | " << dateTime << " | " << description << "\n";
        file.close();
    }
}
void Equipe::ecrireDansFichierHistorique(const QString &texte)
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/historique.txt";

    QFile file(filePath);

    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Erreur ouverture fichier :" << file.errorString();
        return;
    }

    QTextStream out(&file);
    out << texte << " | " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "\n";
    file.close();
}

