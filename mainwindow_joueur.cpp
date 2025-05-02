#include "mainwindow_joueur.h"
#include "ui_mainwindow_joueur.h"
#include "joueur.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QDebug>
#include <QTableView>
#include <QSqlQueryModel>
#include <QRegularExpressionValidator>

#include <QSqlError>
#include <QAbstractItemModel>

#include <QSortFilterProxyModel>

#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QPrintPreviewDialog>


#include <QSqlQuery>
#include <QProcess>
#include <cstdlib>

#include <QSerialPort>
#include <QVBoxLayout>
#include "playersubstitutiondialog.h"
//#include "arduino.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialisation et ouverture de la connexion série Arduino
     arduino = new QSerialPort(this);
     arduino->setPortName("com9"); // exemple : "COM9"
     if (arduino->open(QIODevice::ReadWrite)) {
         arduino->setBaudRate(QSerialPort::Baud9600); // Ou ton baudrate Arduino
         arduino->setDataBits(QSerialPort::Data8);
         arduino->setParity(QSerialPort::NoParity);
         arduino->setStopBits(QSerialPort::OneStop);
         arduino->setFlowControl(QSerialPort::NoFlowControl);
         qDebug() << "Arduino connecté avec succès !";
     } else {
         qDebug() << "Impossible d'ouvrir le port Arduino.";
     }



    connect(arduino, &QSerialPort::readyRead, this, &MainWindow::readSerial);


    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<<"arduino is avaible and connected to : "<<A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" << A.getarduino_port_name();
        break;
    case(-1): qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


    openAIClient = new OpenAIClient(this);
    connect(openAIClient, &OpenAIClient::reponseRecue, this, [](const QString &reponse) {
        qDebug() << "Réponse du chatbot : " << reponse;
    });
    connect(ui->btnEnvoyer, &QPushButton::clicked, this, [=]() {
        QString question = ui->lineEditQuestion->text();
        openAIClient->envoyerRequete(question);
    });
    connect(openAIClient, &OpenAIClient::reponseRecue, this, [=](const QString &reponse) {
        ui->textBrowserReponse->append("Chatbot : " + reponse);
    });


    // Autres connexions de ton interface
    connect(ui->tri, SIGNAL(currentIndexChanged(int)), this, SLOT(on_tri_changed(int)));
    connect(ui->searchEdit, SIGNAL(returnPressed()), this, SLOT(onSearch()));
    connect(ui->pdfButton, &QPushButton::clicked, this, &MainWindow::on_pdfButton_clicked);

    afficher();

    ui->idEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+"), this));
    ui->ageEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{1,2}"), this));
    ui->numberEdit->setValidator(new QRegularExpressionValidator (QRegularExpression("[0-9]+"), this));
    ui->noteEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+(\\.[0-9]+)?"), this));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearForm()
{
    ui->idEdit->clear();
    ui->nameEdit->clear();
    ui->lastNameEdit->clear();
    ui->ageEdit->clear();
    ui->positCB->setCurrentIndex(0);
    ui->numberEdit->clear();
    ui->noteEdit->clear();

}

void MainWindow::on_cancel_clicked()
{
    clearForm();  // Effacer le formulaire
}



// Vérifier si les entrées sont valides
bool MainWindow::validateInput()
{
    if (ui->idEdit->text().isEmpty() ||
        ui->nameEdit->text().isEmpty() ||
        ui->lastNameEdit->text().isEmpty() ||
        ui->ageEdit->text().isEmpty() ||
        ui->positCB->currentIndex() == -1 ||
        ui->numberEdit->text().isEmpty() ||
        ui->noteEdit->text().isEmpty()
        )
    {
        QMessageBox::warning(this, "Champs obligatoires", "Veuillez remplir tous les champs.");
        return false;
    }

    int age = ui->ageEdit->text().toInt();
    if (age <= 0 || age > 100) {
        QMessageBox::warning(this, "Âge invalide", "L'âge doit être compris entre 1 et 100.");
        return false;
    }

    int numberj = ui->numberEdit->text().toInt();
    if (numberj <= 0) {
        QMessageBox::warning(this, "Numéro invalide", "Le numéro de maillot doit être un nombre positif.");
        return false;
    }

    double note = ui->noteEdit->text().toDouble();
    if (note < 0 || note > 10) {
        QMessageBox::warning(this, "Note invalide", "La note doit être comprise entre 0 et 10.");
        return false;
    }

    return true;
}

void MainWindow::on_add_clicked()
{
    if (!validateInput()) return;  // Vérifie si les entrées sont valides

    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    QString lastName = ui->lastNameEdit->text();
    int age = ui->ageEdit->text().toInt();
    QString position = ui->positCB->currentText();
    int numberj = ui->numberEdit->text().toInt();
    double note = ui->noteEdit->text().toDouble();


    Joueur j(id, name, lastName, age, position, numberj, note );
    if (j.add()) {
        QMessageBox::information(this, "Succès", "Joueur ajouté avec succès !");
        afficher();
        clearForm();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du joueur.");
    }
}

void MainWindow::on_supprimer_clicked()
{
    // Get the selected row index from the QTableView
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    // Check if no row is selected
    if (selectedRows.isEmpty()) {
        // Show a message box if no row is selected
        QMessageBox::warning(this, "No Row Selected", "Please select a ticket to delete.");
        return;
    }

    // Get the joueur ID from the selected row (assuming it's in the first column)
    int id = selectedRows.first().data(Qt::DisplayRole).toInt();

    // Call the supprimer function from gestion_joueur class
    Joueur j;
    if (j.supprimer(id)) {
        qDebug() << "joueur with ID" << id << "successfully deleted.";
        afficher(); // Refresh the table view after deletion
    } else {
        qDebug() << "Failed to delete the joueur with ID" << id;
    }
}



void MainWindow::on_modify_clicked()
{
    if (!validateInput()) return;  // Vérifie si les entrées sont valides

    int id = ui->idEdit->text().toInt();
    QString name = ui->nameEdit->text();
    QString lastName = ui->lastNameEdit->text();
    int age = ui->ageEdit->text().toInt();
    QString position = ui->positCB->currentText();
    int numberj = ui->numberEdit->text().toInt();
    double note = ui->noteEdit->text().toDouble();


    Joueur j(id, name, lastName, age, position, numberj, note );

    if (j.modify(id)) {
        afficher();
        QMessageBox::information(this, "Succès", "Joueur modifié avec succès !");
        clearForm();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification du joueur.");
    }
}


void MainWindow::afficher()
{
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve ticket data
    model->setQuery("SELECT id, name, last_name, age, position, numberj, note FROM joueur");

    // Set column headers (optional, but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSITION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMBERJ"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOTE"));

    // Assign the model to the QTableView
    ui->tableView->setModel(model);

    // Auto-resize columns for better display
    // Make the table fill the available space
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers); // Disable editing
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection); // Allow selecting only one row
}



void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    // Récupérer la ligne sélectionnée
    int row = index.row();

    // Récupérer les valeurs de chaque colonne
    int id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt(); // ID
    QString name = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString(); // Nom
    QString lastName = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString(); // Prénom
    int age = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toInt(); // Âge
    QString position = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toString(); // Poste
    int numberj = ui->tableView->model()->data(ui->tableView->model()->index(row, 5)).toInt(); // Numéro de maillot
    double note = ui->tableView->model()->data(ui->tableView->model()->index(row, 6)).toDouble(); // Note

    // Affichage des valeurs dans les champs du formulaire
    ui->idEdit->setText(QString::number(id));
    ui->nameEdit->setText(name);
    ui->lastNameEdit->setText(lastName);
    ui->ageEdit->setText(QString::number(age));
    ui->positCB->setCurrentText(position); // ComboBox pour la position
    ui->numberEdit->setText(QString::number(numberj));
    ui->noteEdit->setText(QString::number(note));

}


/*void MainWindow::on_pdfButton_clicked()
{
    exporterPDF();  // Appel de la fonction d'exportation PDF
}*/

void MainWindow::on_pdfButton_clicked() {
    qDebug() << "on_pdf_clicked() called.";

    // Fetch data from the database
    QSqlQuery query;
    query.prepare("SELECT id, name, last_name, age, position, numberj, note FROM joueur");

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve data: " + query.lastError().text());
        qDebug() << "SQL Error: " << query.lastError().text();
        return;
    }

    int rowCount = 0;
    QString html = "<h2>Players List</h2><table border='1' width='100%'>";
    html += "<tr><th>ID</th><th>Name</th><th>last_name</th><th>Age</th><th>Position</th><th>Number</th><th>Note</th></tr>";

    while (query.next()) {
        rowCount++;
        html += "<tr>";
        html += "<td>" + query.value(0).toString() + "</td>";
        html += "<td>" + query.value(1).toString() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString() + "</td>";
        html += "<td>" + query.value(4).toString() + "</td>";
        html += "<td>" + query.value(5).toString() + "</td>";
        html += "<td>" + query.value(6).toString() + "</td>";
        html += "</tr>";
        qDebug() << "Row retrieved: " << query.value(0).toString();
    }

    html += "</table>";

    if (rowCount == 0) {
        QMessageBox::warning(this, "No Data", "No tickets found in the database.");
        qDebug() << "No tickets found!";
        return;
    }

    // Create a QTextDocument for preview
    QTextDocument doc;
    doc.setHtml(html);

    // Create a QPrintPreviewDialog to allow preview of the document
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog previewDialog(&printer, this);

    connect(&previewDialog, &QPrintPreviewDialog::paintRequested, [&doc](QPrinter *printer) {
        doc.print(printer);  // Print the document to the printer selected
    });

    // Show the print preview dialog
    previewDialog.exec();

    // If the user decides to save, ask for the file path
    if (printer.outputFileName().isEmpty()) {
        QString pdfPath = QFileDialog::getSaveFileName(this, "Save PDF", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/tickets_list.pdf", "PDF Files (*.pdf)");

        if (pdfPath.isEmpty()) {
            return;  // User canceled the save dialog
        }

        // Set the output file name to save the PDF
        printer.setOutputFileName(pdfPath);

        // Print the document (this time to the file)
        doc.print(&printer);

        qDebug() << "PDF saved at: " << pdfPath;
        QMessageBox::information(this, "PDF Export", "The PDF has been saved successfully.");

        // Optionally, open the PDF file in the default PDF viewer
        QDesktopServices::openUrl(QUrl::fromLocalFile(pdfPath));
    }
}



void MainWindow::onSearch()
{
    // Récupérer le texte de recherche
    QString searchText = ui->searchEdit->text();

    // Créer un modèle pour le QTableView
    QSqlQueryModel *model = new QSqlQueryModel();

    // Requête SQL pour récupérer les joueurs filtrés par nom
    QString queryStr = "SELECT id, name, last_name, age, position, numberj, note FROM joueur WHERE name LIKE '%" + searchText + "%'";

    model->setQuery(queryStr);

    // Vérifier si la requête a réussi
    if (model->lastError().isValid()) {
        QMessageBox::warning(this, "Erreur de recherche", "Erreur lors de la récupération des données.");
        return;
    }

    // Définir les en-têtes des colonnes
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("POSITION"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("NUMBERJ"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("NOTE"));

    // Appliquer le modèle au QTableView
    ui->tableView->setModel(model);

    // Ajuster la taille des colonnes pour un affichage optimal
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::on_tri_changed(int index)
{
    QString position = ui->tri->currentText();  // Récupérer la position sélectionnée dans le QComboBox

    // Créer un modèle pour afficher les joueurs
    QSqlQueryModel *model = new QSqlQueryModel();

    // Si l'option "Toutes les positions" est choisie, afficher tous les joueurs
    if (position == "All positions") {
        model->setQuery("SELECT id, name, last_name, age, position, numberj, note FROM joueur");
    }
    // Sinon, filtrer selon la position sélectionnée
    else if (position == "Defender" || position == "Goalkeeper" || position == "Midfielder" || position == "Striker") {
        model->setQuery("SELECT id, name, last_name, age, position, numberj, note FROM joueur WHERE position = '" + position + "'");
    }

    // Assigner le modèle au QTableView
    ui->tableView->setModel(model);

    // Redimensionner les colonnes pour mieux afficher les données
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}


void MainWindow::on_stat_clicked()
{
    dialog_window = new Dialog(this);
    dialog_window->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup
    dialog_window->show();

}

void MainWindow::RechercheVocale() {
    QMessageBox::information(this, "Recherche vocale", "🎤 Début de l'écoute du micro...");

    QString nomJoueurReconnu = demarrerReconnaissanceVocale();
    if (!nomJoueurReconnu.isEmpty()) {
        ui->searchEdit->setText(nomJoueurReconnu);
        rechercherJoueurParNom(nomJoueurReconnu);
    } else {
        QMessageBox::warning(this, "Échec", "Aucun nom reconnu.");
    }
}

QString MainWindow::demarrerReconnaissanceVocale() {
    QProcess process;
    // Commande PocketSphinx pour un fichier audio avec modèle et dictionnaire spécifiés
    process.start("pocketsphinx_continuous", QStringList()
                                                 << "-hmm" << "/path/to/your/model"
                                                 << "-lm" << "/path/to/your/language/model"
                                                 << "-dict" << "/path/to/your/dictionary"
                                                 << "-infile" << "test_converted.wav");

    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    QString errorOutput = process.readAllStandardError();

    qDebug() << "Reconnaissance vocale : " << output;
    qDebug() << "Erreur : " << errorOutput;

    return output;  // Retourne le texte reconnu
}

void MainWindow::rechercherJoueurParNom(const QString &name) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM JOUEUR WHERE NAME LIKE :name");
    query.bindValue(":name", "%" + name + "%");
    query.exec();
    model->setQuery(query);
    ui->tableView->setModel(model);
}



//remplacement



// Imagine this function is called when Arduino sends Team 1 button
void MainWindow::onTeam1ButtonPressed()
{
    playersubstitutiondialog dialog(1, this);
    if (dialog.exec() == QDialog::Accepted) {
        QString playerOut = dialog.getFirstSelectedPlayer();
        QString playerIn = dialog.getSecondSelectedPlayer();

        qDebug() << "Substitution for Team 1: " << playerOut << " --> " << playerIn;

        // 1. Send message to Arduino
        QString message = "Team1 substitution: " + playerOut + " -> " + playerIn + "\n";
        arduino->write(message.toUtf8());

        // 2. Show confirmation to user
        QMessageBox::information(this, "Succès", "Le remplacement a été envoyé à Arduino !");
    }
}

void MainWindow::onTeam2ButtonPressed()
{
    playersubstitutiondialog dialog(2, this);
    if (dialog.exec() == QDialog::Accepted) {
        QString playerOut = dialog.getFirstSelectedPlayer();
        QString playerIn = dialog.getSecondSelectedPlayer();

        qDebug() << "Substitution for Team 2: " << playerOut << " --> " << playerIn;

        // 1. Send message to Arduino
        QString message = "Team2 substitution: " + playerOut + " -> " + playerIn + "\n";
        arduino->write(message.toUtf8());

        // 2. Show confirmation to user
        QMessageBox::information(this, "Succès", "Le remplacement a été envoyé à Arduino !");
    }
}


void MainWindow::readSerial()
{
    QByteArray data = arduino->readAll();
    QString receivedData = QString::fromUtf8(data).trimmed();

    if (receivedData == "button1_pressed") {
        onTeam1ButtonPressed();
    } else if (receivedData == "button2_pressed") {
        onTeam2ButtonPressed();
    }
}


// void MainWindow::readSerial()
// {
//     QByteArray data = arduino->readAll();
//     QString message = QString::fromUtf8(data).trimmed();

//     if (message == "BUTTON1_PRESSED") {
//         playersubstitutiondialog dialog(1, this);  // équipe 1 par exemple
//         dialog.exec();
//     } else if (message == "BUTTON2_PRESSED") {
//         playersubstitutiondialog dialog(2, this);  // équipe 2 par exemple
//         dialog.exec();
//     }
// }



void MainWindow::update_label() {
    // Ce que tu veux faire quand tu reçois des données d'Arduino
    QByteArray data = arduino->readAll();
    qDebug() << "Données reçues de l'Arduino : " << data;
    //ui->label->setText(data); // exemple si tu veux afficher sur un QLabel
}




void MainWindow::on_dark_clicked()
{
    // Set dark mode styles for the QTableView widget
    QString darkTableStyle = R"(
        QTableView {
            background-color:#A9A9A9;   /* Black background */
            color: white;                /* White text */
        }

        QTableView::item {
            background-color:#A9A9A9;   /* Black background for table items */
            color: white;                /* White text for table items */
        }

        QHeaderView::section {
            background-color:#A9A9A9;   /* Dark grey for header */
            color: white;                /* White text for header */
            padding: 5px;
        }
    )";

    // Apply the stylesheet to the table widget
    ui->tableView->setStyleSheet(darkTableStyle);
    // Set styles for the Form widget (background black, white border)
    QString formStyle = R"(
        #form {
            background-color: #A9A9A9;   /* Black background */
            border: 2px solid white;     /* White border */
            border-radius: 10px;         /* Rounded corners */
        }

        /* Set QLabel text color to white */
        #form QLabel {
            color: white;
        }

        /* Set QLineEdit style (black background, white border, white text) */
        #form QLineEdit {
            background-color: #121212;   /* Black background */
            color:  #121212;                /* White text */
            border: 1px solid white;     /* White border */
            border-radius: 10px;         /* Rounded corners */
            padding: 5px;
        }

        /* Set QComboBox and QTextEdit style (black background, white border, white text) */
        #form QComboBox, #form QTextEdit {
            background-color: #121212;   /* Black background */
            color: black;                /* White text */
            border: 1px solid white;     /* White border */
            border-radius: 10px;         /* Rounded corners */
            padding: 5px;
        }
    )";

    // Apply the stylesheet to the Form widget
    ui->box->setStyleSheet(formStyle);
    // Set common button style (transparent background, white border, white text)
    QString buttonStyle = R"(
        QPushButton {
            background-color: black;  /* Transparent background */
            color: white;                   /* White text */
            border: 1px solid white;        /* White border */
            border-radius: 10px;            /* Rounded corners */
            padding: 5px 10px;              /* Padding inside buttons */
        }

        QPushButton:hover {
            background-color: rgba(255, 255, 255, 20%);  /* Light hover effect */
        }

        QPushButton:pressed {
            background-color: rgba(255, 255, 255, 40%);  /* Darker effect when pressed */
        }
    )";

    // Apply the button style to all buttons
    ui->add->setStyleSheet(buttonStyle);
    ui->cancel->setStyleSheet("#cancel{border-radius: 10px;background: transparent;color: #333;}");
    ui->modify->setStyleSheet(buttonStyle);
    ui->btnEnvoyer->setStyleSheet(buttonStyle);
    ui->stat->setStyleSheet(buttonStyle);
    ui->box->setStyleSheet("#box{background:#A9A9A9;border-radius: 10px;padding: 5px;}");
    ui->supprimer->setStyleSheet("#supprimer{border-radius: 10px;background: transparent;}");
    ui->dark->setStyleSheet("#dark {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#dark:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
    ui->light->setStyleSheet("#light{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #444;border: 2px solid #777;}#light:pressed {background-color: #222;border: 2px solid #999;}");
    ui->bg->setStyleSheet("#bg{background-color:#F5F5F5;}");
    ui->leftmenu->setStyleSheet("#leftmenu{background-color:#A9A9A9;border-radius: 10px;padding: 5px;}");
    ui->idEdit->setStyleSheet("#idEdit { background-color: white;border: 2px solid #333; }");
    ui->nameEdit->setStyleSheet("#nameEdit { background-color: white;border: 2px solid #333; }");
    ui->lastNameEdit->setStyleSheet("#lastNameEdit { background-color: white;border: 2px solid #333; }");
    ui->ageEdit->setStyleSheet("#ageEdit { background-color: white;border: 2px solid #333; }");
    ui->numberEdit->setStyleSheet("#numberEdit { background-color: white;border: 2px solid #333; }");
    ui->noteEdit->setStyleSheet("#noteEdit { background-color: white;border: 2px solid #333; }");
    ui->positCB->setStyleSheet("#positCB { background-color: white;border: 2px solid #333; }");
    ui->lineEditQuestion->setStyleSheet("#positCB { background-color: white;border: 2px solid #333; }");


}




void MainWindow::on_light_clicked()
{
    // Clear only the dark mode custom stylesheet applied earlier
    qApp->setStyleSheet("");  // Clear the global dark mode stylesheet
    // reset
    ui->tableView->setStyleSheet("#tableView{background:rgba(33, 133, 85, 0.4);border-radius: 10px;padding: 5px;}");
    ui->box->setStyleSheet("#box{background:rgba(214, 215, 222, 0.4);border-radius: 10px;padding: 5px;}");
    ui->leftmenu->setStyleSheet("#leftmenu{background-color:#218555;border-radius: 10px;padding: 5px;}");
    ui->add->setStyleSheet("#add{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->cancel->setStyleSheet("#cancel{border-radius: 10px;background: transparent;}");
    ui->modify->setStyleSheet("#modify{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->btnEnvoyer->setStyleSheet("#btnEnvoyer{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->stat->setStyleSheet("#stat{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->supprimer->setStyleSheet("#supprimer{border-radius: 10px;background: transparent;}");
    ui->dark->setStyleSheet("#dark{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #444;border: 2px solid #777;}#dark:pressed {background-color: #222;border: 2px solid #999;}");
    ui->light->setStyleSheet("#light {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#light:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
    ui->bg->setStyleSheet("#bg{ background-image: url(:/res/img/background.png);}");
    ui->idEdit->setStyleSheet("#idEdit { background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px; }");
    ui->nameEdit->setStyleSheet("#nameEdit {  background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px;}");
    ui->lastNameEdit->setStyleSheet("#lastNameEdit {  background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px;}");
    ui->ageEdit->setStyleSheet("#ageEdit { background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px; }");
    ui->numberEdit->setStyleSheet("#numberEdit { background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px; }");
    ui->noteEdit->setStyleSheet("#noteEdit { background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px; }");
    ui->positCB->setStyleSheet("#positCB { background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px; }");
    ui->lineEditQuestion->setStyleSheet("#positCB {  background-color: white; color: black; border: 2px solid #619D80; border-radius: 5px; padding: 5px; }");

}


