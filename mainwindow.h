#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arbitre.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); // Constructeur
    ~MainWindow(); // Destructeur

private slots:
    void on_pushButton_ajouter_clicked();// Slot pour ajouter un arbitre
    void afficher();
    void on_pushButton_modifier_clicked(); // Slot pour modifier un arbitre
    void selectionnerArbitre();  // Fonction qui remplit les champs quand on sélectionne un arbitre
    void on_pushButton_supprimer_clicked();// Slot pour supprimer un arbitre
    void on_cancel_clicked();
    void on_lineEdit_rechercher_textChanged(const QString &arg1);
    void on_radioButton_night_clicked();
    void on_radioButton_light_clicked();
    void filtrerParCategorie(const QString &category);
    void trierArbitres(const QString &colonne);
    void on_pushButton_statistiques_clicked();
    void exporterListeArbitresPDF();
    void on_btn_ouvrirEmailDialog_clicked();
     void on_pushButton_guess_clicked();






private:
    Ui::MainWindow *ui; // Objet UI généré par Qt Designer
};

#endif // MAINWINDOW_H
