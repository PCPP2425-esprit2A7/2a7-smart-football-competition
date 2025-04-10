#ifndef ARBITRE_H
#define ARBITRE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QComboBox>


class arbitre {
public:
    arbitre() {};
    arbitre(int id, QString name, QString last_name, int nb_carton, int nb_match_a, QString category, QString email);
    bool ajouter();
    void afficher(QTableView *tableView);
    bool modifier(int id, QString name, QString last_name, int nb_carton, int nb_match_a, QString category, QString email);
    bool supprimer(int id);
    QSqlQueryModel* rechercher(QString name);
    void filtrerArbitres(QComboBox *comboBox, QTableView *tableView);
    void setupUI(QComboBox *comboBox, QTableView *tableView);




private:
    QSqlQueryModel *model;
    int id;
    QString name;
    QString last_name;
    int nb_carton;
    int nb_match_a;
    QString category;
    QString email;
};

#endif // ARBITRE_H
