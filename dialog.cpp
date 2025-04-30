#include "dialog.h"
#include "ui_dialog.h"

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
    displayStatistics();
}

Dialog::~Dialog()
{
    delete ui;
}
/*void Dialog::displayStatistics()
{
    // Ensure the widget exists
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

    // Fetch statistics from the database
    QSqlQuery query;
    query.prepare("SELECT type, COUNT(*) FROM BILLET GROUP BY type");

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve data: " + query.lastError().text());
        return;
    }

    // Define a list of colors to pick from
    QList<QColor> colorList = {Qt::darkGray, Qt::darkGreen, Qt::lightGray};

    // Map to store ticket types with assigned colors
    QMap<QString, QColor> ticketColors;

    // Prepare data for pie chart
    QMap<QString, int> ticketData;
    int totalTickets = 0;

    while (query.next()) {
        QString ticketType = query.value(0).toString();
        int count = query.value(1).toInt();
        ticketData[ticketType] = count;
        totalTickets += count;

        // Assign a random color if not already assigned
        if (!ticketColors.contains(ticketType) && !colorList.isEmpty()) {
            int randomIndex = QRandomGenerator::global()->bounded(colorList.size());
            ticketColors[ticketType] = colorList[randomIndex];
            colorList.removeAt(randomIndex); // Remove to avoid duplicates
        }
    }

    if (ticketData.isEmpty()) {
        QMessageBox::information(this, "Statistics", "No data available for statistics.");
        return;
    }

    // Create a graphics scene for custom drawing
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setBackgroundBrush(Qt::transparent);  // Transparent background

    QGraphicsView *view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setStyleSheet("background: transparent; border: none;");  // Remove border

    // Define pie chart properties
    QRectF rect(10, 10, 500, 500);
    int startAngle = 0;

    // Draw pie chart slices
    for (auto it = ticketData.begin(); it != ticketData.end(); ++it) {
        int count = it.value();
        double percentage = (count * 100.0) / totalTickets;
        int angleSpan = (percentage * 360.0 / 100.0) * 16; // Qt uses 1/16th of a degree

        QColor color = ticketColors.value(it.key(), Qt::gray); // Default to gray if no color assigned

        QGraphicsEllipseItem *slice = new QGraphicsEllipseItem(rect);
        slice->setStartAngle(startAngle);
        slice->setSpanAngle(angleSpan);
        slice->setBrush(color);
        slice->setPen(Qt::NoPen);  // Remove outline
        scene->addItem(slice);

        // **Fix Label Positioning**
        double midAngle = (startAngle + angleSpan / 2) * M_PI / 2880.0;
        double labelX = rect.center().x() + 70 * cos(midAngle);
        double labelY = rect.center().y() - 70 * sin(midAngle);

        // Add labels with percentage
        QString labelText = it.key() + "\n" + QString::number(percentage, 'f', 1) + "%";
        QGraphicsTextItem *label = new QGraphicsTextItem(labelText);
        label->setDefaultTextColor(Qt::black);
        label->setFont(QFont("Arial", 10));
        label->setPos(labelX, labelY);
        scene->addItem(label);

        startAngle += angleSpan;
    }


    // Add graphics view and button to layout
    QVBoxLayout *newLayout = new QVBoxLayout(ui->statisticsWidget);
    newLayout->addWidget(view);

    ui->statisticsWidget->setLayout(newLayout);
    ui->statisticsWidget->show();  // Ensure the widget is shown
}
*/
void Dialog::displayStatistics()
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
