#ifndef SUPPORTEUR_H
#define SUPPORTEUR_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QString>
#include <QDate>

class supporteur {
    int id;
    QString NAME;
    QString LAST_NAME;
    QDate DATE_NAIS;
    int GRADE;


public:
    // Constructors
    supporteur();
    supporteur(int id, QString NAME, QString LAST_NAME, QDate DATE_NAIS, int GRADE);

    // Getters
    int getid();
    QString getNAME();
    QString getLAST_NAME();
    QDate getDATE_NAIS();
    int getGRADE();

    // Setters
    void setid(int id);
    void setNAME(QString NAME);
    void setLAST_NAME(QString LAST_NAME);
    void setDATE_NAIS(QDate DATE_NAIS);
    void setGRADE(int GRADE);


    // CRUD functionalities
    bool ajouter();
    QSqlQueryModel* tridateNaissanceAsc();
    QSqlQueryModel* tridateNaissanceDesc();
    QSqlQueryModel* tri();
    QSqlQueryModel* afficher();
    bool modifier(int ID);
    bool supprimer(int ID);
};

#endif // SUPPORTEUR_H
