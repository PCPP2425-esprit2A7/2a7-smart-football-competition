#include "equipe.h"

// Constructeurs
Equipe::Equipe() : id(0), teamName(""), creationDate(""), prizes(0) {}

Equipe::Equipe(int id, QString teamName, QString creationDate, int prizes)
    : id(id), teamName(teamName), creationDate(creationDate), prizes(prizes) {}

// Getters
int Equipe::getId() const {
    return id;
}

QString Equipe::getTeamName() const {
    return teamName;
}

QString Equipe::getCreationDate() const {
    return creationDate;
}

int Equipe::getPrizes() const {
    return prizes;
}

// Setters
void Equipe::setId(int id) {
    this->id = id;
}

void Equipe::setTeamName(QString teamName) {
    this->teamName = teamName;
}

void Equipe::setCreationDate(QString creationDate) {
    this->creationDate = creationDate;
}

void Equipe::setPrizes(int prizes) {
    this->prizes = prizes;
}
