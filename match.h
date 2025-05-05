#ifndef MATCH_H
#define MATCH_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QTime>
#include <QDate>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QString>
#include <QSqlQueryModel>
class Match {
public:
    Match(int id = 0, const QString &date_time = "", const QString &place = "",
          const QString &score = "", const QString &status = "",
          const QString &team1 = "", const QString &team2 = "", int arbitre = 0);

    bool ajouterMatch();
    static QSqlQueryModel* afficherMatch();
    bool rechercherMatch(int id);
    static QSqlQueryModel* rechercherParId(int id);
    bool modifierMatch(int id, const QString &dateTime, const QString &place,
                       const QString &score, const QString &status,
                       int arbitre, const QString &team1, const QString &team2);
    bool supprimerMatch(int id);
    static QSqlQueryModel* trierPar(const QString& field, Qt::SortOrder order);
    void displayScoreChart(const QMap<QString, int> &data, QGraphicsView *view);
    QString getTeam1() const;
    void setTeam1(const QString &newTeam1);
    QString getTeam2() const;
    void setTeam2(const QString &newTeam2);
    int getArbitre() const;
    void setArbitre(int newArbitre);

private:
    int id;
    QString date_time;
    QString place;
    QString score;
    QString status;
    int arbitre;
    QString team1;  // Changed from int to QString
    QString team2;  // Changed from int to QString
};

#endif
