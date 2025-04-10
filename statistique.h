#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>

namespace Ui {
class Statistique;
}

class Statistique : public QDialog
{
    Q_OBJECT

public:
    explicit Statistique(QWidget *parent = nullptr);
    ~Statistique();

private:
    Ui::Statistique *ui;
    void afficherStatistiques(); // Méthode pour afficher les statistiques
};

#endif // STATISTIQUES_H
