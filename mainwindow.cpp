#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_billet.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSortFilterProxyModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    afficher();  // Charger les billets dès l'ouverture de l'application
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::afficher()
{
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve ticket data
    model->setQuery("SELECT id, type, price, quantity, area, date_issue, date_event FROM BILLET");

    // Set column headers (optional, but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Area"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Issue"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Event"));

    // Assign the model to the QTableView
    ui->table->setModel(model);

    // Auto-resize columns for better display
    ui->table->resizeColumnsToContents();
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
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
        QMessageBox::information(this, "Succès", "Addition completed successfully !");
        afficher();
    } else {
        QMessageBox::critical(this, "Erreur", "Adding failed !");
    }

}

void MainWindow::on_delete_2_clicked()
{
    // Get the selected row index from the QTableView
    QModelIndexList selectedRows = ui->table->selectionModel()->selectedRows();

    // Check if no row is selected
    if (selectedRows.isEmpty()) {
        // Show a message box if no row is selected
        QMessageBox::warning(this, "No Row Selected", "Please select a ticket to delete.");
        return;
    }

    // Get the ticket ID from the selected row (assuming it's in the first column)
    int id = selectedRows.first().data(Qt::DisplayRole).toInt();

    // Call the delete_2 function from gestion_billet class
    gestion_billet billet;
    if (billet.delete_2(id)) {
        qDebug() << "Ticket with ID" << id << "successfully deleted.";
        afficher(); // Refresh the table view after deletion
    } else {
        qDebug() << "Failed to delete the ticket with ID" << id;
    }
}

void MainWindow::on_cancel_clicked()
{
    // Reset the form fields to their initial state
    ui->id->clear();  // Clear the ID field
    ui->type->setCurrentIndex(0);  // Reset the type combo box to the first index
    ui->price->clear();  // Clear the price field
    ui->quantity->clear();  // Clear the quantity field
    ui->area->setCurrentIndex(0);  // Reset the area combo box to the first index
    ui->date_issue->setDate(QDate::currentDate());  // Reset the date of issue to current date
    ui->date_event->setDate(QDate::currentDate());  // Reset the date of event to current date

    // Log a debug message (optional)
    qDebug() << "Form has been reset.";
}

void MainWindow::on_modify_clicked()
{
    QModelIndexList selectedIndexes = ui->table->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        // If no row is selected, show a message
        QMessageBox::warning(this, "Sélection manquante", "Please select a line before editing.");
        return; // Exit the function if no row is selected
    }
    // Retrieve the input values from the form
    int id = ui->id->text().toInt();
    QString type = ui->type->currentText();
    int price = ui->price->text().toInt();
    int quantity = ui->quantity->text().toInt();
    QString area = ui->area->currentText();
    QDate date_issue = ui->date_issue->date();
    QDate date_event = ui->date_event->date();

    // Log input values for debugging
    qDebug() << "Attempting modification with ID:" << id;
    qDebug() << "New values - Type:" << type << ", Price:" << price
             << ", Quantity:" << quantity << ", Area:" << area
             << ", Date Issue:" << date_issue << ", Date Event:" << date_event;

    // Create a gestion_billet object with the updated information
    gestion_billet billet;
    billet.settype(type);
    billet.setprice(price);
    billet.setquantity(quantity);
    billet.setarea(area);
    billet.setdate_issue(date_issue);
    billet.setdate_event(date_event);

    // Attempt to modify the ticket record and log the result
    bool test = billet.modify(id);
    qDebug() << "Modifier function result:" << test;

    // Display message based on the success of the modification
    if (test) {
        // Refresh the table view to reflect changes
        afficher(); // This function should refresh the table view with the updated data

        // Show success message
        QMessageBox::information(this, QObject::tr("OK"),
                                 QObject::tr("Change made\nClick Cancel to exit."),
                                 QMessageBox::Cancel);
    } else {
        // Show error message if modification fails
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("The change could not be made.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
    }
}

void MainWindow::on_table_clicked(const QModelIndex &index)
{
    // Get the row number of the clicked cell
    int row = index.row();

    // Assuming your table has columns: ID, Type, Price, Quantity, Area, Date Issue, Date Event
    int id = ui->table->model()->data(ui->table->model()->index(row, 0)).toInt(); // Column 0 is ID
    QString type = ui->table->model()->data(ui->table->model()->index(row, 1)).toString(); // Column 1 is Type
    int price = ui->table->model()->data(ui->table->model()->index(row, 2)).toInt(); // Column 2 is Price
    int quantity = ui->table->model()->data(ui->table->model()->index(row, 3)).toInt(); // Column 3 is Quantity
    QString area = ui->table->model()->data(ui->table->model()->index(row, 4)).toString(); // Column 4 is Area
    QDate date_issue = ui->table->model()->data(ui->table->model()->index(row, 5)).toDate(); // Column 5 is Date Issue
    QDate date_event = ui->table->model()->data(ui->table->model()->index(row, 6)).toDate(); // Column 6 is Date Event

    // Set the values to the form
    ui->id->setText(QString::number(id));
    ui->type->setCurrentText(type);
    ui->price->setText(QString::number(price));
    ui->quantity->setText(QString::number(quantity));
    ui->area->setCurrentText(area);
    ui->date_issue->setDate(date_issue);
    ui->date_event->setDate(date_event);
}


void MainWindow::on_tri_activated(int index)
{
    // Créer un objet gestion_billet
    gestion_billet gb;

    // Récupérer le texte de l'élément sélectionné dans le QComboBox
    QString selectedOption = ui->tri->itemText(index);

    // Selon l'option sélectionnée, déterminer le type de tri
    if (selectedOption == "Expensive") {  // Tri par prix élevé (décroissant)
        QSqlQueryModel* modelDesc = gb.triPrixDecroissant();
        ui->table->setModel(modelDesc);  // Mettre à jour la table avec les données triées
    }
    else if (selectedOption == "Cheap") {  // Tri par prix bas (croissant)
        QSqlQueryModel* modelAsc = gb.triPrixCroissant();
        ui->table->setModel(modelAsc);  // Mettre à jour la table avec les données triées
    }
    else if (selectedOption == "Default") {  // Tri par ID (ordre normal)
        QSqlQueryModel* modelDefault = gb.triid();  // ou une méthode pour trier par ID
        ui->table->setModel(modelDefault);  // Mettre à jour la table avec les données triées par ID
    }
}


