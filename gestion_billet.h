#ifndef GESTION_BILLET_H
#define GESTION_BILLET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QTableWidgetItem>

class gestion_billet
{
private:
    int id;
    QString type;
    int price;
    int quantity;
    QString area;
    QDate date_issue;
    QDate date_event;
public:
    gestion_billet();
    gestion_billet(int id, QString type, int price, int quantity, QString area, QDate date_issue, QDate date_event);
    // Getters
    int getid() ;
    QString gettype() ;
    int getprice() ;
    int getquantity() ;
    QString getarea() ;
    QDate getdate_issue() ;
    QDate getdate_event() ;

    // Setters
    void setid(int);
    void settype(QString);
    void setprice(int);
    void setquantity(int);
    void setarea(QString);
    void setdate_issue(QDate);
    void setdate_event(QDate);
    //database operation
    bool add();
    void afficher(QTableWidget* tableWidget);
    bool modify(int id);
};

#endif // GESTION_BILLET_H
