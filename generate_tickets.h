#ifndef GENERATE_TICKETS_H
#define GENERATE_TICKETS_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QTableView>

class generate_tickets
{
public:
    generate_tickets();
    void afficher_s(QTableView* tableView);
    void afficher_m(QTableView* tableView);
    void afficher_b(QTableView* tableView);

};

#endif // GENERATE_TICKETS_H
