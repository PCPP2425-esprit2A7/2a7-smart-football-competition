#ifndef MAINWINDOW_JOUEUR_H
#define MAINWINDOW_JOUEUR_H

#include "joueur.h"
#include <QMainWindow>

#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>

#include <QSortFilterProxyModel>
#include "dialog_stat_joueur.h"

//#include "OPENAICLIENT.h"

#include "arduino.h"

#include <QVBoxLayout>

#include <QSerialPort>
#include <QSerialPortInfo>
#include "openaiclient.h"





QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow; }
class PlayerSubstitutionDialog;
class arduino;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();
    void on_supprimer_clicked();
    void on_modify_clicked();
    void on_cancel_clicked();
    void afficher();

    void on_tableView_clicked(const QModelIndex &index);

    bool validateInput();  // Ajout de la validation des entrées

    void on_pdfButton_clicked(); // slot du bouton PDF

    void onSearch();  // Méthode pour la recherche

    void on_tri_changed(int index);  // Slot pour gérer le changement de position

    void on_stat_clicked();

    void on_dark_clicked();
    void on_light_clicked();
    // void handleResponse(QNetworkReply *reply);  // Fonction pour gérer la réponse du chatbot

    //void on_pushButton_clicked();

    void RechercheVocale();
    QString demarrerReconnaissanceVocale();
    void rechercherJoueurParNom(const QString &name);


    //new
    void onTeam2ButtonPressed();
    void onTeam1ButtonPressed();
    void readSerial();
    void update_label();


private:
    Ui::MainWindow *ui;
    Joueur joueur;  // Déclaration de l'objet Joueur pour gérer les opérations CRUD
    void clearForm();
    void exporterPDF(); // fonction qui crée le PDF

    Dialog *dialog_window;
    QNetworkAccessManager *networkManager;  // Pour envoyer les requêtes API

    arduino A;
    QByteArray data;

    //QSerialPort *serial;  // Port série pour la communication avec Arduino
    QSerialPort *arduino;

    OpenAIClient *openAIClient;  // ✅ Ajoute cette ligne !

};

#endif //MAINWINDOW_JOUEUR_H





