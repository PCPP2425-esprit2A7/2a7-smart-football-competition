#include "playersubstitutiondialog.h"
#include "ui_playersubstitutiondialog.h"

#include <QDialogButtonBox>
#include <QSqlQuery>
#include <QSqlError>


playersubstitutiondialog::playersubstitutiondialog(int team, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::playersubstitutiondialog),
    team(team)
{
    ui->setupUi(this);

    connect(ui->ButtonBox, &QPushButton::clicked, this, &playersubstitutiondialog::accept);
    connect(ui->ButtonBox_2, &QPushButton::clicked, this, &playersubstitutiondialog::reject);

    if (team == 1) {
        ui->team1_player1->setEnabled(true);
        ui->team1_player2->setEnabled(true);
        ui->team2_player1->setEnabled(false);
        ui->team2_player2->setEnabled(false);
    } else {
        ui->team1_player1->setEnabled(false);
        ui->team1_player2->setEnabled(false);
        ui->team2_player1->setEnabled(true);
        ui->team2_player2->setEnabled(true);
    }

    loadPlayers();
}

playersubstitutiondialog::~playersubstitutiondialog()
{
    delete ui;
}

// void playersubstitutiondialog::loadPlayers()
// {
//     QStringList players = {"Player A", "Player B", "Player C", "Player D"};

//     foreach (const QString &name, players) {
//         ui->team1_player1->addItem(name);
//         ui->team1_player2->addItem(name);
//         ui->team2_player1->addItem(name);
//         ui->team2_player2->addItem(name);
//     }
// }


void playersubstitutiondialog::loadPlayers()
{
    QSqlQuery query;

    // Load all team names from the "equipe" table
    query.prepare("SELECT team_name FROM equipe");

    if (query.exec()) {
        while (query.next()) {
            QString teamName = query.value(0).toString();

            // Load players for the current team
            QSqlQuery playerQuery;
            playerQuery.prepare("SELECT j.numberj FROM joueur j "
                                "JOIN equipe e ON j.team = e.team_name "
                                "WHERE e.team_name = :teamName");
            playerQuery.bindValue(":teamName", teamName);

            if (playerQuery.exec()) {
                while (playerQuery.next()) {
                    QString playerName = playerQuery.value(0).toString();

                    // Depending on the team, add players to the corresponding list
                    if (teamName == "FCB") {
                        ui->team1_player1->addItem(playerName);
                        ui->team1_player2->addItem(playerName);
                    } else if (teamName == "RMD") {
                        ui->team2_player1->addItem(playerName);
                        ui->team2_player2->addItem(playerName);
                    }
                    // Add more conditions if you have more teams
                }
            } else {
                qDebug() << "Erreur chargement des joueurs pour l'équipe " << teamName << ":" << playerQuery.lastError().text();
            }
        }
    } else {
        qDebug() << "Erreur chargement des équipes:" << query.lastError().text();
    }
}


QString playersubstitutiondialog::getFirstSelectedPlayer() const
{
    if (team == 1)
        return ui->team1_player1->currentText();
    else
        return ui->team2_player1->currentText();
}

QString playersubstitutiondialog::getSecondSelectedPlayer() const
{
    if (team == 1)
        return ui->team1_player2->currentText();
    else
        return ui->team2_player2->currentText();
}
