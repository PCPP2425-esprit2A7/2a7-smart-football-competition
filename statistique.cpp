#include "statistique.h"
#include "ui_statistique.h"
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarCategoryAxis>  // Ajout de l'inclusion nécessaire
#include <QSqlQuery>
#include <QPainter>
#include <QSqlError>
#include <QMessageBox>

Statistique::Statistique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Statistique)
{
    ui->setupUi(this);
    afficherStatistiques();  // Appel de la méthode pour afficher les statistiques
}

Statistique::~Statistique()
{
    delete ui;
}

void Statistique::afficherStatistiques()
{
    // Créer un ensemble de barres
    QBarSet *set0 = new QBarSet("Matchs Arbitrés");

    // Créer un modèle de catégories (noms des arbitres)
    QStringList categories;

    // Récupérer les données de la base de données
    QSqlQuery query;
    query.prepare("SELECT name, nb_match_a FROM arbitre WHERE nb_match_a >= 1");

    if (query.exec()) {
        while (query.next()) {
            QString name = query.value(0).toString();
            int nb_match_a = query.value(1).toInt();

            *set0 << nb_match_a;  // Ajouter le nombre de matchs arbitrés à l'ensemble de barres
            categories << name;  // Ajouter le nom de l'arbitre à la liste des catégories
        }
    } else {
        // Gérer l'erreur si la requête échoue
        QMessageBox::critical(this, "Erreur SQL", "Erreur lors de la récupération des données.");
        return;
    }
    QColor barColor("#619D80");  // Utilisation de la couleur hexadécimale

    set0->setColor(barColor);

    // Créer une série de barres et ajouter l'ensemble de barres
    QBarSeries *series = new QBarSeries();
    series->append(set0);

    // Créer un graphique
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des Matchs Arbitrés");

    // Définir les axes X et Y
    chart->createDefaultAxes();

    // Configuration de l'axe X (noms des arbitres)
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);  // Utiliser les noms des arbitres comme catégories sur l'axe X
    chart->setAxisX(axisX, series);

    // Configuration de l'axe Y (nombre de matchs arbitrés)
    chart->axes(Qt::Vertical).first()->setTitleText("Nombre de Matchs");

    // Créer une vue du graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);  // Pour un rendu plus fluide

    // Ajouter le graphique au layout
    ui->layoutStatistiques->addWidget(chartView);  // Ajouter le graphique au QVBoxLayout 'layoutStatistiques'
}
