#include "dialog_arbitre.h"
#include "ui_dialog_arbitre.h"

#include <QtCharts>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>
#include <QtMath>   // For trigonometric calculations (cos, sin)
#include <QMessageBox>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    stat();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::stat()
{
    if (!ui->statisticsWidget) {
        QMessageBox::critical(this, "Erreur", "Widget des statistiques introuvable.");
        return;
    }

    // Supprimer contenu précédent
    QLayout *layout = ui->statisticsWidget->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete layout;
    }

    // Statistiques

    int niveau1 = 0, niveau2 = 0, niveau3 = 0;

    QSqlQuery query;

    if (query.exec("SELECT COUNT(*) FROM ARBITRE WHERE nb_match_a >= 1 AND nb_match_a <= 30"))
        if (query.next()) niveau1 = query.value(0).toInt();

    if (query.exec("SELECT COUNT(*) FROM ARBITRE WHERE nb_match_a > 30 AND nb_match_a < 60"))
        if (query.next()) niveau2 = query.value(0).toInt();

    if (query.exec("SELECT COUNT(*) FROM ARBITRE WHERE nb_match_a = 100"))
        if (query.next()) niveau3 = query.value(0).toInt();

    int total = niveau1 + niveau2 + niveau3;
    if (total == 0) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée disponible.");
        return;
    }


    // Série du graphique
    QPieSeries *series = new QPieSeries();
    series->append("1 - 30", niveau1);
    series->append("30 - 60", niveau2);
    series->append("100", niveau3);

    // Appliquer les nouvelles couleurs personnalisées
    QPieSlice *slice1 = series->slices().at(0);
    QPieSlice *slice2 = series->slices().at(1);
    QPieSlice *slice3 = series->slices().at(2);

    slice1->setBrush(QColor("#218555"));
    slice2->setBrush(QColor("#D3D3D0"));
    slice3->setBrush(QColor("#619D80"));

    // Affichage en pourcentage avec texte en gras
    QFont labelFont("Arial", 10, QFont::Bold);
    slice1->setLabel(QString("1 - 30: %1%").arg((niveau1 * 100) / total));
    slice1->setLabelFont(labelFont);

    slice2->setLabel(QString("30 - 60: %1%").arg((niveau2 * 100) / total));
    slice2->setLabelFont(labelFont);

    slice3->setLabel(QString("100: %1%").arg((niveau3 * 100) / total));
    slice3->setLabelFont(labelFont);

    // Donut
    series->setHoleSize(0.4);

    // Création du graphique
    QChart *chart = new QChart();
    chart->addSeries(series);

    // Titre en plus grand et gras
    QFont titleFont("Arial", 16, QFont::Bold);
    chart->setTitle("Répartition des nb_match_a des Arbitres");
    chart->setTitleFont(titleFont);
    chart->legend()->setAlignment(Qt::AlignRight);

    // Fond transparent
    chart->setBackgroundBrush(Qt::transparent);
    chart->setPlotAreaBackgroundBrush(Qt::transparent);
    chart->setPlotAreaBackgroundVisible(false);

    // ChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background: transparent; border: none;");

    // Ajout au layout
    QVBoxLayout *newLayout = new QVBoxLayout(ui->statisticsWidget);
    newLayout->addWidget(chartView);
    ui->statisticsWidget->setLayout(newLayout);
    ui->statisticsWidget->show();
}
