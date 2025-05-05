#ifndef MAINWINDOW_EQUIPE_H
#define MAINWINDOW_EQUIPE_H
#include "equipe.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowEquipe;
}
QT_END_NAMESPACE

class MainWindowEquipe : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowEquipe(QWidget *parent = nullptr);
    ~MainWindowEquipe();


private slots:
    void on_add_clicked();
    void afficher();
    void on_modify_clicked();

    void on_delete_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_chercher_clicked();
    void on_pushButton_trier_asc_clicked();
    void on_pushButton_trier_desc_clicked();
    void exporterPDF();

    void on_btn_statistiques_clicked();

private slots:
    void on_btn_historique_clicked();


    void on_btn_supporteur_khaled_clicked();

    void on_btn_joueur_khaled_clicked();

    void on_btn_arbitre_khaled_clicked();


    void on_btn_match_khaled_clicked();

    void on_btn_billet_khaled_clicked();

    void on_home_clicked();

    void on_dark_clicked();

    void on_light_clicked();

private:
    Ui::MainWindowEquipe *ui;
};
#endif // MAINWINDOW_EQUIPE_H
