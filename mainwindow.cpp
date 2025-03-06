#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_billet.h"
#include <QMessageBox>
#include <QSqlRecord>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Définir le nombre de colonnes et les en-têtes du QTableWidget
    ui->table->setColumnCount(7);
    QStringList headers = {"ID", "Type", "Price", "Quantity", "Area", "Date Issue", "Date Event"};
    ui->table->setHorizontalHeaderLabels(headers);

    afficher();  // Charger les billets dès l'ouverture de l'application
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficher()
{
    // Exécuter la requête SQL pour récupérer les billets
    QSqlQuery query("SELECT id, type, price, quantity, area, date_issue, date_event FROM BILLET");

    // Effacer le tableau avant de le remplir à nouveau
    ui->table->setRowCount(0);

    int row = 0;
    while (query.next()) {
        // Ajouter une nouvelle ligne
        ui->table->insertRow(row);

        // Remplir les colonnes avec les valeurs de la base de données
        ui->table->setItem(row, 0, new QTableWidgetItem(query.value("id").toString()));
        ui->table->setItem(row, 1, new QTableWidgetItem(query.value("type").toString()));
        ui->table->setItem(row, 2, new QTableWidgetItem(query.value("price").toString()));
        ui->table->setItem(row, 3, new QTableWidgetItem(query.value("quantity").toString()));
        ui->table->setItem(row, 4, new QTableWidgetItem(query.value("area").toString()));
        ui->table->setItem(row, 5, new QTableWidgetItem(query.value("date_issue").toString()));
        ui->table->setItem(row, 6, new QTableWidgetItem(query.value("date_event").toString()));

        row++;
    }
}

void MainWindow::on_add_clicked()
{
    // Vérifier l'existence des champs avant d'y accéder
    if (!ui->id || !ui->type || !ui->price || !ui->quantity || !ui->area || !ui->date_issue || !ui->date_event) {
        QMessageBox::critical(this, "Erreur", "Certains champs n'existent pas !");
        return;
    }

    // Récupération des valeurs des champs
    int id = ui->id->text().toInt();
    QString type = ui->type->currentText();
    int price = ui->price->text().toInt();
    int quantity = ui->quantity->text().toInt();
    QString area = ui->area->currentText();
    QDate date_issue = ui->date_issue->date();
    QDate date_event = ui->date_event->date();

    // Création d'un objet Gbillet
    gestion_billet gb(id, type, price, quantity, area, date_issue, date_event);

    // Ajout dans la base de données
    if (gb.add()) {
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
        afficher();
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué !");
    }

}

void MainWindow::on_modify_clicked()
{

}
