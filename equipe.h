#ifndef EQUIPE_H
#define EQUIPE_H

#include <QString>

class Equipe {
private:
    int id;
    QString teamName;
    QString creationDate;
    int prizes;

public:
    // Constructeurs
    Equipe();
    Equipe(int id, QString teamName, QString creationDate, int prizes);

    // Getters
    int getId() const;
    QString getTeamName() const;
    QString getCreationDate() const;
    int getPrizes() const;

    // Setters
    void setId(int id);
    void setTeamName(QString teamName);
    void setCreationDate(QString creationDate);
    void setPrizes(int prizes);
};

#endif // EQUIPE_H
