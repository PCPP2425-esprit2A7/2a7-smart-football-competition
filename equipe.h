#ifndef EQUIPE_H
#define EQUIPE_H
#include <QDate>

//new
#include<QSqlQuery>
#include<QsqlQueryModel>
#include<QTableView>
//new
#include <QString>

class Equipe {
private:
    int id;
    QString team_name;
    QDate creation_date;
    int prizes;
    QString coach;

public:
    // Constructeurs
    Equipe();
    Equipe(int id, QString team_name, QDate creation_date, int prizes, QString coach);
    bool ajouter();
    bool supprimer(int id);
     bool modify(int id);
    void afficher(QTableView *tableView);
    // Getters
    int getid() const;
    QString getteam_name() const;
    QDate getcreation_date() const;
    int getprizes() const;
    QString getcoach() const;
    // Setters
    void setid(int id);
    void setteam_name(QString team_name);
    void setcreation_date(QDate creation_date);
    void setprizes(int prizes);
    void setcoach(QString coach);
    //new

    //new

};

#endif // EQUIPE_H
