#include "dialog_stat_billet.h"
#include "ui_dialog_stat_billet.h"

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
DialogStat::DialogStat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogStat)
{
    ui->setupUi(this);
    displayStatistics();
}

DialogStat::~DialogStat()
{
    delete ui;
}

void DialogStat::displayStatistics()
{
    if (!ui->statisticsWidget) {
        QMessageBox::critical(this, "Error", "Statistics widget not found.");
        return;
    }

    // Clear previous content
    QLayout *layout = ui->statisticsWidget->layout();
    if (layout) {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete layout;
    }

    QSqlQuery query;
    query.prepare("SELECT type, COUNT(*) FROM BILLET GROUP BY type");

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve data: " + query.lastError().text());
        return;
    }

    //QList<QColor> colorList = {Qt::#218555, Qt::#D3D3D0, Qt::#619D80};
    QList<QColor> colorList = {
        QColor("#218555"),
        QColor("#D3D3D0"),
        QColor("#619D80")
    };
    QMap<QString, QColor> ticketColors;
    QMap<QString, int> ticketData;
    int totalTickets = 0;

    while (query.next()) {
        QString ticketType = query.value(0).toString();
        int count = query.value(1).toInt();
        ticketData[ticketType] = count;
        totalTickets += count;

        if (!ticketColors.contains(ticketType) && !colorList.isEmpty()) {
            int randomIndex = QRandomGenerator::global()->bounded(colorList.size());
            ticketColors[ticketType] = colorList[randomIndex];
            colorList.removeAt(randomIndex);
        }
    }

    if (ticketData.isEmpty()) {
        QMessageBox::information(this, "Statistics", "No data available for statistics.");
        return;
    }

    // Create pie chart series
    QPieSeries *series = new QPieSeries();
    for (auto it = ticketData.begin(); it != ticketData.end(); ++it) {
        series->append(it.key(), it.value());
    }

    // Customize slices
    QFont labelFont("Arial", 10, QFont::Bold);
    int index = 0;
    for (QPieSlice *slice : series->slices()) {
        QString key = ticketData.keys().at(index);
        double percentage = (ticketData[key] * 100.0) / totalTickets;
        QColor color = ticketColors.value(key, Qt::gray);

        slice->setBrush(color);
        slice->setLabel(QString("%1: %2%").arg(key).arg(percentage, 0, 'f', 1));
        slice->setLabelFont(labelFont);
        slice->setLabelVisible(true);
        index++;
    }

    series->setHoleSize(0.4); // donut style

    // Create chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des Billets par Type");
    chart->setTitleFont(QFont("Arial", 16, QFont::Bold));
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setBackgroundBrush(Qt::transparent);
    chart->setPlotAreaBackgroundBrush(Qt::transparent);
    chart->setPlotAreaBackgroundVisible(false);

    // Create chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setStyleSheet("background: transparent; border: none;");

    // Layout
    QVBoxLayout *mainLayout = new QVBoxLayout(ui->statisticsWidget);
    mainLayout->addWidget(chartView);
    ui->statisticsWidget->setLayout(mainLayout);
    ui->statisticsWidget->show();
}
