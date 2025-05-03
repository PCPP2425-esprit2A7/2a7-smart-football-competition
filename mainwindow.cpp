#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipe.h"
#include <QMessageBox>
#include<QsqlQueryModel>
#include<QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QSqlQuery>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QPrinter>
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>  //
#include <QFileDialog>
#include <QTextDocument>
#include <QPrinter>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_chercher, &QPushButton::clicked, this, &MainWindow::on_pushButton_chercher_clicked);
    connect(ui->pushButton_trier_asc, &QPushButton::clicked, this, &MainWindow::on_pushButton_trier_asc_clicked);
    connect(ui->pushButton_trier_desc, &QPushButton::clicked, this, &MainWindow::on_pushButton_trier_desc_clicked);
    connect(ui->pushButton_exportPDF, &QPushButton::clicked, this, &MainWindow::exporterPDF);



    afficher();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_chercher_clicked()
{
    QString nom = ui->lineEdit_nomEquipe->text();

    Equipe e;
    QSqlQueryModel* model = e.chercher_par_nom(nom);

    ui->tableView->setModel(model);
}

//new
void MainWindow::afficher()
{
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve ticket data
    model->setQuery("SELECT * FROM EQUIPE");

    // Set column headers (optional, but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("team_name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_creation"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prizes"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("coach"));


    // Assign the model to the QTableView
    ui->tableView->setModel(model);

    // Auto-resize columns for better display
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void MainWindow::on_add_clicked()
{
    // Récupération des valeurs saisies
    int id = ui->idEdit->text().toInt();
    QString team_name = ui->team_nameEdit->text().trimmed();
    QDate creation_date = ui->dateEdit->date();
    int prizes = ui->prizesEdit->text().toInt();
    QString coach = ui->coachEdit->text().trimmed();

    // Vérification des champs vides
    if (team_name.isEmpty() || coach.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Les champs 'Nom de l'équipe' et 'Entraîneur' ne doivent pas être vides.");
        return;
    }

    // Vérification de l'ID (doit être positif)
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID doit être un nombre positif.");
        return;
    }

    // Vérification du nombre de prix (ne peut pas être négatif)
    if (prizes < 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nombre de prix ne peut pas être négatif.");
        return;
    }

    // Vérification de la date (optionnel : s'assurer qu'elle n'est pas dans le futur)
    if (creation_date > QDate::currentDate()) {
        QMessageBox::warning(this, "Erreur de saisie", "La date de création ne peut pas être dans le futur.");
        return;
    }

    // Création de l'objet et ajout à la base de données
    Equipe E(id, team_name, creation_date, prizes, coach);
    bool test = E.ajouter();

    if (test) {
        QMessageBox::information(this, QObject::tr("OK"), QObject::tr("Ajout effectué avec succès."), QMessageBox::Ok);
        afficher();  // Rafraîchir la table après ajout
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"), QObject::tr("Ajout non effectué. Vérifiez la base de données."), QMessageBox::Ok);
    }
}

void MainWindow::on_delete_2_clicked()
{
    // Get the selected row index from the QTableView
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    // Check if no row is selected
    if (selectedRows.isEmpty()) {
        // Show a message box if no row is selected
        QMessageBox::warning(this, "No Row Selected", "Please select a ticket to delete.");
        return;
    }

    // Get the ticket ID from the selected row (assuming it's in the first column)
    int id = selectedRows.first().data(Qt::DisplayRole).toInt();

    // Call the delete_2 function from gestion_billet class
    Equipe e;
    if (e.supprimer(id)) {
        qDebug() << "Ticket with ID" << id << "successfully deleted.";
        afficher(); // Refresh the table view after deletion
    } else {
        qDebug() << "Failed to delete the ticket with ID" << id;
    }
}
void MainWindow::on_modify_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Sélection manquante", "Veuillez sélectionner une ligne avant de modifier.");
        return;
    }

    // Récupération des valeurs saisies
    int id = ui->idEdit->text().toInt();
    QString team_name = ui->team_nameEdit->text().trimmed();
    QDate creation_date = ui->dateEdit->date();
    int prizes = ui->prizesEdit->text().toInt();
    QString coach = ui->coachEdit->text().trimmed();

    //  **Contrôles de saisie**
    if (id <= 0) {
        QMessageBox::warning(this, "ID invalide", "L'ID doit être un nombre positif.");
        return;
    }

    if (team_name.isEmpty()) {
        QMessageBox::warning(this, "Nom d'équipe invalide", "Le nom de l'équipe ne peut pas être vide.");
        return;
    }

    if (prizes < 0) {
        QMessageBox::warning(this, "Nombre de prix invalide", "Le nombre de prix ne peut pas être négatif.");
        return;
    }

    if (coach.isEmpty()) {
        QMessageBox::warning(this, "Nom du coach invalide", "Le nom du coach ne peut pas être vide.");
        return;
    }

    //  **Log pour le débogage**
    qDebug() << "Modification de l'équipe avec ID :" << id;
    qDebug() << "Nouvelles valeurs - Nom :" << team_name << ", Date de création :" << creation_date
             << ", Prix :" << prizes << ", Coach :" << coach;

    //  **Création et modification de l'objet Equipe**
    Equipe e(id, team_name, creation_date, prizes, coach);
    bool test = e.modify(id);

    if (test) {
        afficher(); // Rafraîchir la table
        QMessageBox::information(this, "Succès", "Modification effectuée avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    // Récupérer la ligne sélectionnée
    int row = index.row();

    // Vérifier que la ligne sélectionnée est valide
    if (row < 0) return;

    // Récupérer les valeurs de chaque colonne selon la structure de la table EQUIPE
    int id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt(); // ID
    QString team_name = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString(); // Nom de l'équipe
    QDate creation_date = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toDate(); // Date de création
    int prizes = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toInt(); // Nombre de prix
    QString coach = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toString(); // Entraîneur

    // Affichage des valeurs dans les champs du formulaire
    ui->idEdit->setText(QString::number(id));
    ui->team_nameEdit->setText(team_name);
    ui->dateEdit->setDate(creation_date); // Champ QDateEdit pour la date
    ui->prizesEdit->setText(QString::number(prizes));
    ui->coachEdit->setText(coach);
}
void MainWindow::on_pushButton_trier_asc_clicked()
{
    Equipe e;
    ui->tableView->setModel(e.trier_par_date_asc());
}

void MainWindow::on_pushButton_trier_desc_clicked()
{
    Equipe e;
    ui->tableView->setModel(e.trier_par_date_desc());
}
void MainWindow::exporterPDF()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "*.pdf");
    if (filePath.isEmpty())
        return;
    if (!filePath.endsWith(".pdf"))
        filePath += ".pdf";

    QPrinter printer(QPrinter::PrinterMode::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setPageSize(QPageSize::A4);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    QAbstractItemModel* model = ui->tableView->model();
    if (!model) {
        qDebug() << "Pas de modèle dans le QTableView.";
        return;
    }

    // 📝 Construction du HTML
    QString html;
    html += "<h2 style='text-align: center;'>Liste des Équipes</h2>";
    html += "<table border='1' cellspacing='0' cellpadding='4' width='100%'>";

    // 🔠 En-têtes
    html += "<tr bgcolor='#f0f0f0'>";
    for (int col = 0; col < model->columnCount(); ++col) {
        QString header = model->headerData(col, Qt::Horizontal).toString();
        html += "<th>" + header + "</th>";
    }
    html += "</tr>";

    // 📄 Données
    for (int row = 0; row < model->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < model->columnCount(); ++col) {
            QString data = model->data(model->index(row, col)).toString();
            html += "<td>" + data + "</td>";
        }
        html += "</tr>";
    }

    html += "</table>";

    // 🖨️ Impression du document HTML
    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "Exportation réussie vers :\n" + filePath);
}
void MainWindow::on_btn_statistiques_clicked()
{
    Equipe eq;
    QSqlQueryModel* model = eq.statistiques_par_prix();
    ui->tableView_2->setModel(model);

}
void MainWindow::on_btn_historique_clicked()
{
    // Lire le fichier texte de l'historique
    QFile file("historique.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier historique.txt");
        return;
    }

    QTextStream in(&file);
    QString historiqueText = in.readAll();
    file.close();

    // Demander où sauvegarder le PDF
    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer en PDF", "", "*.pdf");

    if (fileName.isEmpty())
        return;

    if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");

    // Créer un document texte
    QTextDocument document;
    document.setPlainText(historiqueText);

    // Créer une imprimante virtuelle pour générer un PDF
    QPrinter printer(QPrinter::PrinterMode::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    // Imprimer le document
    document.print(&printer);

    QMessageBox::information(this, "Succès", "L'historique a été exporté en PDF !");
}
void MainWindow::on_btn_afficher_historique_clicked()
{
    // Tu peux laisser vide ou afficher un message pour le moment
}
