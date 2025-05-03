#ifndef MAINWINDOW_ARBITRE_H
#define MAINWINDOW_ARBITRE_H

#include <QMainWindow>
#include "arbitre.h"
#include <QProcess>
#include "dialog_arbitre.h"




namespace Ui {
class MainWindow;
}
class Statistique;
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
    void on_pushButton_cancel_clicked();
    void on_lineEdit_rechercher_textChanged(const QString &arg1);
    void on_dark_clicked();
    void on_light_clicked();

    void filtrerParCategorie(const QString &category);
    void trierArbitres(const QString &colonne);
    void on_pushButton_statistiques_clicked();
    void on_PDF_clicked();
    //void exporterListeArbitresPDF();
    void on_btn_ouvrirEmailDialog_clicked();
    void on_pushButton_guess_clicked();
    void logAction(const QString &action);
    void on_pushButton_Historique_clicked();
    void envoyerEmail(const QString &email, const QString &nom);
    void on_btn_test_voice_clicked() ;
    void testerCommandeVocale(QString spokenText);

    bool chercherEtAfficher(const QString &nom);










private:
    Ui::MainWindow *ui; // Objet UI généré par Qt Designer

    QProcess *voiceProcess;
    //Statistique *stat;
    Dialog *dialog_window;


};

#endif // MAINWINDOW_ARBITRE_H
