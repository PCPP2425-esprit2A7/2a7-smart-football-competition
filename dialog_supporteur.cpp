#include "dialog_supporteur.h"
#include "ui_dialog_supporteur.h"
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
    displayStatisticsByGrade();
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::displayStatisticsByGrade()

{
    if (!ui->stat) {
        QMessageBox::critical(this, "Erreur", "Le widget de statistiques est introuvable.");
        return;
    }

    // Nettoyer l'ancien contenu
    QLayout *layout = ui->stat->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete layout;
    }

    // Requête pour obtenir le nombre de supporteurs par grade
    QSqlQuery query;
    query.prepare("SELECT GRADE, COUNT(*) FROM SUPPORTEUR GROUP BY GRADE");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur base de données", "Échec de récupération des données : " + query.lastError().text());
        return;
    }

    QList<QColor> colorList = {
        QColor("#218555"),
        QColor("#D3D3D0"),
        QColor("#619D80")
    };
    QMap<QString, QColor> gradeColors;
    QMap<QString, int> gradeData;

    int total = 0;

    while (query.next()) {
        QString grade = query.value(0).toString();
        int count = query.value(1).toInt();
        gradeData[grade] = count;
        total += count;

        if (!gradeColors.contains(grade) && !colorList.isEmpty()) {
            int index = QRandomGenerator::global()->bounded(colorList.size());
            gradeColors[grade] = colorList[index];
            colorList.removeAt(index);
        }
    }

    if (gradeData.isEmpty()) {
        QMessageBox::information(this, "Statistiques", "Aucune donnée à afficher pour les grades.");
        return;
    }

    // Création du graphique type donut avec QChart
    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.4);  // Donut effect

    QFont labelFont("Arial", 10, QFont::Bold);

    for (auto it = gradeData.begin(); it != gradeData.end(); ++it) {
        QString grade = it.key();
        int count = it.value();
        double percentage = (count * 100.0) / total;

        QPieSlice *slice = series->append(grade + QString(": %1%").arg(percentage, 0, 'f', 1), count);
        slice->setBrush(gradeColors.value(grade, Qt::gray));
        slice->setLabelFont(labelFont);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Supporteurs par Grade");
    chart->setTitleFont(QFont("Arial", 16, QFont::Bold));
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setBackgroundBrush(Qt::transparent);
    chart->setPlotAreaBackgroundBrush(Qt::transparent);
    chart->setPlotAreaBackgroundVisible(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background: transparent; border: none;");

    QVBoxLayout *newLayout = new QVBoxLayout(ui->stat);
    newLayout->addWidget(chartView);
    ui->stat->setLayout(newLayout);
    ui->stat->show();
}

