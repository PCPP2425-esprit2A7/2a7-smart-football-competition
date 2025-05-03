#ifndef MAINWINDOW_MATCH_H
#define MAINWINDOW_MATCH_H

#include "match.h"
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QGraphicsView>
#include <QGraphicsScene>

//pdf
#include <QMainWindow>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

#include "calendrierwidget.h"
#include "superviser.h"
#include <QMainWindow>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ajouter_clicked();
    void on_pushButton_modifier_clicked();
    void on_pushButton_supprimer_clicked();
    void on_pushButton_rechercher_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_exportPDF_clicked();
    void on_pushButton_calculer_clicked();
    void on_comboBoxTriDate_currentIndexChanged(int index);
    void chargerDonneesTriees(const QString& order);
    void ouvrirSuperviser();  // Nouveau nom plus clair
    bool teamExists(int teamId) ;
    void on_dark_clicked();
   // void mettreAJourCalendrier();
    void on_light_clicked();
    //void on_calendar_examen_clicked(const QDate &date);

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    void loadMatchData();
    void clear();
    void setupTableView();
    int getSelectedId(); // Nouvelle méthode utilitaire
    QGraphicsScene *mapScene;
    QGraphicsView *mapView;
    QString currentSortField;
    Qt::SortOrder currentSortOrder;


    static const QRegularExpression scoreRegex;

    CalendrierWidget *calendrierWidget;
    QPushButton *btnSuperviser;  // Déclaration du bouton
    Superviser *fenetreSuperviser = nullptr;  // Fenêtre superviser
};

#endif // MAINWINDOW_MATCH_H

