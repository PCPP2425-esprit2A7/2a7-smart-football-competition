#ifndef JOUEUR_H
#define JOUEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

class Joueur
{
private:
    int id;
    QString name;
    QString lastName;
    int age;
    QString position;
    int numberj;
    double note;

public:
    // Constructeurs
    Joueur() {}
    Joueur(int id, QString name, QString lastName, int age, QString position, int numberj, double note);

    // Getters & Setters
    int getId() const { return id; }
    QString getName() const { return name; }
    QString getLastName() const { return lastName; }
    int getAge() const { return age; }
    QString getPosition() const { return position; }
    int getNumberj() const { return numberj; }
    double getNote() const { return note; }

    void setId(int id) { this->id = id; }
    void setName(QString name) { this->name = name; }
    void setLastName(QString lastName) { this->lastName = lastName; }
    void setAge(int age) { this->age = age; }
    void setPosition(QString position) { this->position = position; }
    void setnumber(int numberj) { this->numberj = numberj; }
    void setNote(double note) { this->note = note; }


    // CRUD
    bool add();
    void afficher(QTableView *tableView);
    bool supprimer(int id);
    bool modify(int id);

    QSqlQueryModel* trier_par_position(); // Déclaration du tri par position
};

#endif // JOUEUR_H
