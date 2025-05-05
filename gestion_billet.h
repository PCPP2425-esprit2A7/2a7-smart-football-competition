#ifndef GESTION_BILLET_H
#define GESTION_BILLET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QTableView>

class gestion_billet
{
private:
    QString id;
    QString type;
    int price;
    int quantity;
    QString area;
    QDate date_issue;
    QDate date_event;
public:
    gestion_billet();
    gestion_billet(QString id, QString type, int price, int quantity, QString area, QDate date_issue, QDate date_event);
    // Getters
    QString getid() ;
    QString gettype() ;
    int getprice() ;
    int getquantity() ;
    QString getarea() ;
    QDate getdate_issue() ;
    QDate getdate_event() ;

    // Setters
    void setid(QString);
    void settype(QString);
    void setprice(int);
    void setquantity(int);
    void setarea(QString);
    void setdate_issue(QDate);
    void setdate_event(QDate);
    //database operation
    bool add();
    void afficher(QTableView* tableView);
    bool modify(QString id);
    bool delete_2(QString id);
    QSqlQueryModel* triPrixCroissant();
    QSqlQueryModel* triPrixDecroissant();
    QSqlQueryModel* triid();
    bool isValid();


};

#endif // GESTION_BILLET_H
