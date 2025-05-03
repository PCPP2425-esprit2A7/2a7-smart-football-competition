#include "mainwindow_arbitre.h"
#include "ui_mainwindow_arbitre.h"
#include "arbitre.h"
#include <QMessageBox>
#include <QPalette>
#include <QRadioButton>
#include <QSqlError>
#include "dialog_arbitre.h"
#include <QFileDialog>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidgetItem>
#include <QSqlQueryModel>
#include <QPageLayout>
#include <QPageSize>
#include "emaildialog_arbitre.h"
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "historiqueDialog.h"
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QInputDialog>
#include<QPrintPreviewDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Vérifier la connexion à la base de données
    /*if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données a échoué.");
        return;
    }*/

    afficher();  // Charge les arbitres dès le lancement



    // Connecte les boutons aux méthodes correspondantes
    connect(ui->pushButton_ajouter, SIGNAL(clicked()), this, SLOT(on_pushButton_ajouter_clicked()));
    connect(ui->pushButton_modifier, &QPushButton::clicked, this, &MainWindow::on_pushButton_modifier_clicked);
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::selectionnerArbitre);
    connect(ui->pushButton_cancel, &QPushButton::clicked, this, &MainWindow::on_pushButton_cancel_clicked);
    connect(ui->lineEdit_rechercher, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_rechercher_textChanged);
    connect(ui->dark, &QPushButton::clicked, this, &MainWindow::on_dark_clicked);
    connect(ui->light, &QPushButton::clicked, this, &MainWindow::on_light_clicked);

    connect(ui->comboBox_tri, &QComboBox::currentTextChanged, this, &MainWindow::trierArbitres);
    connect(ui->PDF, &QPushButton::clicked, this, &MainWindow::on_PDF_clicked);
    connect(ui->btn_ouvrirEmailDialog, &QPushButton::clicked, this, &MainWindow::on_btn_ouvrirEmailDialog_clicked);
    connect(ui->pushButton_guess, &QPushButton::clicked, this, &MainWindow::on_pushButton_guess_clicked);
    connect(ui->pushButton_Historique, &QPushButton::clicked, this, &MainWindow::on_pushButton_Historique_clicked);
    connect(ui->btn_test_voice, &QPushButton::clicked, this, &MainWindow::on_btn_test_voice_clicked);
    // Inside your MainWindow constructor or setup function
    //connect(ui->btn_test_voice, &QPushButton::clicked, this, &MainWindow::onTestVoiceClicked);
   // reclamationWindow = new ReclamationWindow(this);
    //connect(reclamationWindow, &ReclamationWindow::reclamationSubmitted, this, &MainWindow::onReclamationSubmitted);
    //loadReclamations();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_cancel_clicked()
{
    // Nettoyer les champs de saisie
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->comboBox->setCurrentIndex(0);
    ui->tableView->clearSelection(); // Réinitialiser la sélection
    logAction("cancel d'un arbitre");
}
void MainWindow::on_pushButton_ajouter_clicked() {
    qDebug() << "Ajout bouton cliqué";
    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() ||
        ui->lineEdit_3->text().isEmpty() || ui->lineEdit_4->text().isEmpty() ||
        ui->lineEdit_5->text().isEmpty() || ui->lineEdit_6->text().isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis !");
        return;
    }
    int id = ui->lineEdit->text().toInt();
    QString name = ui->lineEdit_2->text();
    QString last_name = ui->lineEdit_3->text();
    int nb_carton = ui->lineEdit_5->text().toInt();
    int nb_match_a = ui->lineEdit_6->text().toInt();
    QString category = ui->comboBox->currentText();
    QString email = ui->lineEdit_4->text();
    QRegularExpression regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    if (!regex.match(email).hasMatch()) {
        QMessageBox::critical(this, "Erreur", "L'email n'est pas valide !");
        return;
    }


    // Vérifier que les champs essentiels ne sont pas vides
    if (name.isEmpty() || last_name.isEmpty() || email.isEmpty() || category.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Tous les champs doivent être remplis.");
        afficher();

        return;
    }

    // Vérifier que nb_carton et nb_match_a sont des nombres
    bool ok_carton, ok_match;
    nb_carton = ui->lineEdit_5->text().toInt(&ok_carton);
    nb_match_a = ui->lineEdit_6->text().toInt(&ok_match);

    if (!ok_carton || !ok_match) {
        QMessageBox::critical(this, "Erreur", "Le nombre de cartons et le nombre de matchs doivent être des nombres.");
        return;
    }


    arbitre a(id, name, last_name, nb_carton, nb_match_a, category, email );
    bool test = a.ajouter();

    if (test) {
        QMessageBox::information(this, "Succès", "Arbitre ajouté avec succès!");
        afficher();
    } else {
        qDebug() << "Test a échoué malgré ajout réussi.";
        //QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'arbitre.");
    }
    if (test) {
        QMessageBox::information(this, "Succès", "Arbitre ajouté avec succès!");
        afficher();

        QString logDetail = QString("Ajout arbitre : ID=%1, Nom=%2, Prénom=%3, Email=%4, Catégorie=%5, Matchs=%6, Cartons=%7")
                                .arg(id)
                                .arg(name)
                                .arg(last_name)
                                .arg(email)
                                .arg(category)
                                .arg(nb_match_a)
                                .arg(nb_carton);

        logAction(logDetail);  // Log uniquement cette ligne avec tous les détails
    } else {
        qDebug() << "Test a échoué malgré ajout réussi.";
    }

}
void MainWindow::afficher()
{
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve ticket data
    model->setQuery("SELECT id, name, last_name, nb_carton, nb_match_a, category, email FROM arbitre");
    // Vérifier si la requête a échoué
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL : " << model->lastError().text();
        return;  // Si une erreur SQL survient, quitter la méthode.
    }
    // Set column headers (optional, but recommended)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NB_CARTON"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("NB_MATCH_A"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("CATEGORY"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("EMAIL"));

    // Assign the model to the QTableView
    ui->tableView->setModel(model);
    ui->tableView->reset();
    ui->tableView->update();
    ui->tableView->show();



    // Auto-resize columns for better display
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
void MainWindow::on_pushButton_modifier_clicked() {
    QModelIndex index = ui->tableView->currentIndex(); // Vérifie si une ligne est sélectionnée
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un arbitre à modifier !");
        return;
    }
    int id = ui->lineEdit->text().toInt();  // ID caché
    QString name = ui->lineEdit_2->text();
    QString last_name = ui->lineEdit_3->text();
    int nb_carton = ui->lineEdit_5->text().toInt();
    int nb_match_a = ui->lineEdit_6->text().toInt();
    QString category = ui->comboBox->currentText();
    QString email = ui->lineEdit_4->text();

    QSqlQuery query;
    query.prepare("UPDATE arbitre SET name = :name, last_name = :last_name, nb_carton = :nb_carton, "
                  "nb_match_a = :nb_match_a, category = :category, email = :email WHERE id = :id");

    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":last_name", last_name);
    query.bindValue(":nb_carton", nb_carton);
    query.bindValue(":nb_match_a", nb_match_a);
    query.bindValue(":category", category);
    query.bindValue(":email", email);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Arbitre modifié avec succès!");
        afficher();
        QString logDetail = QString("Modification arbitre : ID=%1, Nouveau Nom=%2, Nouveau Prénom=%3, Nouveau Email=%4")
                                .arg(id)
                                .arg(name)
                                .arg(last_name)
                                .arg(email);
        logAction(logDetail);
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification.");
    }



    /*Mettre à jour les statistiques après l'ajout
    Statistique *stat = new Statistique(this);  // Passer 'this' comme parent pour éviter la fuite mémoire
    stat->exec();  // Afficher les statistiques de manière modale*/
    //logAction("modification d'un arbitre");
}

void MainWindow::selectionnerArbitre() {
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) return;

    int row = index.row();
    int id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();

    QSqlQuery query;
    query.prepare("SELECT * FROM arbitre WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        ui->lineEdit->setText(QString::number(id));  // On stocke l'ID dans un champ invisible
        ui->lineEdit_2->setText(query.value("name").toString());
        ui->lineEdit_3->setText(query.value("last_name").toString());
        ui->lineEdit_5->setText(query.value("nb_carton").toString());
        ui->lineEdit_6->setText(query.value("nb_match_a").toString());
        ui->comboBox->setCurrentText(query.value("category").toString());
        ui->lineEdit_4->setText(query.value("email").toString());
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les informations.");
    }
}




void MainWindow::on_pushButton_supprimer_clicked() {
    int id = ui->lineEdit->text().toInt();  // Récupérer l'ID depuis le champ de saisie

    if (id == 0) {
        QMessageBox::warning(this, "Suppression", "Veuillez sélectionner un arbitre à supprimer !");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cet arbitre ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        arbitre a(id, "", "", 0, 0, "", ""); // On crée un objet arbitre temporaire
        if (a.supprimer(id)) {  // Appel de la méthode supprimer
            QMessageBox::information(this, "Succès", "Arbitre supprimé avec succès !");
            afficher();
            QString logDetail = QString("Suppression arbitre : ID=%1")
                                    .arg(id);
            logAction(logDetail);
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression.");
        }

    }
    /* Mettre à jour les statistiques après l'ajout
    Statistique *stat = new Statistique(this);  // Passer 'this' comme parent pour éviter la fuite mémoire
    stat->exec();  // Afficher les statistiques de manière modale*/
    logAction("supprision d'un arbitre");
}
void MainWindow::on_lineEdit_rechercher_textChanged(const QString &arg1) {
    arbitre a(0, "", "", 0, 0, "", "");
    QAbstractItemModel* model = a.rechercher(arg1);
    ui->tableView->setModel(model);

    if (!arg1.isEmpty()) {
        QString logDetail = QString("Recherche d'un arbitre avec le terme : %1").arg(arg1);
        logAction(logDetail);

        // afficher message si résultat trouvé
        if (model->rowCount() > 0) {
            QMessageBox::information(this, "Résultat", QString("Trouvé %1 résultat(s) pour '%2'.")
                                                           .arg(model->rowCount())
                                                           .arg(arg1));
        } else {
            QMessageBox::warning(this, "Résultat", QString("Aucun résultat trouvé pour '%1'.").arg(arg1));
        }

    } else {
        logAction("Recherche d'un arbitre (champ vide)");
    }
}

/*void MainWindow::on_lineEdit_rechercher_textChanged(const QString &arg1) {
    QSqlQueryModel *model = new QSqlQueryModel();

    QSqlQuery query;
    query.prepare("SELECT * FROM arbitre WHERE LOWER(NOM) LIKE LOWER(:searchTerm)");
    query.bindValue(":searchTerm", "%" + arg1 + "%");

    if (query.exec()) {
        model->setQuery(query);
        ui->tableView->setModel(model);
    } else {
        qDebug() << "Erreur dans la recherche :" << query.lastError().text();
    }

    if (!arg1.isEmpty()) {
        QString logDetail = QString("Recherche d'un arbitre avec le terme : %1").arg(arg1);
        logAction(logDetail);
    } else {
        logAction("Recherche d'un arbitre (champ vide)");
    }
}*/


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
    ui->form->setStyleSheet(formStyle);
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
    ui->pushButton_ajouter->setStyleSheet(buttonStyle);
    ui->pushButton_cancel->setStyleSheet("#pushButton_cancel{border-radius: 10px;background: transparent;}");
    ui->pushButton_modifier->setStyleSheet(buttonStyle);

    ui->PDF->setStyleSheet(buttonStyle);
    ui->tableView->setStyleSheet(buttonStyle);
    ui->form->setStyleSheet(buttonStyle);
    ui->pushButton_supprimer->setStyleSheet("#pushButton_supprimer{border-radius: 10px;background: transparent;}");
    ui->pushButton_statistiques->setStyleSheet(buttonStyle);
    ui->dark->setStyleSheet("#dark {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#dark:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
    ui->light->setStyleSheet("#light{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #444;border: 2px solid #777;}#light:pressed {background-color: #222;border: 2px solid #999;}");
    ui->bg->setStyleSheet("#bg{background-color:#F5F5F5;}");
    ui->menu->setStyleSheet("#menu{background-color:#A9A9A9;border-radius: 10px;padding: 5px;}");


}




void MainWindow::on_light_clicked()
{
    // Clear only the dark mode custom stylesheet applied earlier
    qApp->setStyleSheet("");  // Clear the global dark mode stylesheet
    // reset
    ui->tableView->setStyleSheet("#tableView{background:rgba(33, 133, 85, 0.4);border-radius: 10px;padding: 5px;}");
    ui->form->setStyleSheet("#form{background:rgba(214, 215, 222, 0.4);border-radius: 10px;padding: 5px;}");
    ui->menu->setStyleSheet("#menu{background-color:#218555;border-radius: 10px;padding: 5px;}");
    ui->pushButton_ajouter->setStyleSheet("#pushButton_ajouter{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->pushButton_cancel->setStyleSheet("#pushButton_cancell{border-radius: 10px;background: transparent;}");
    ui->pushButton_modifier->setStyleSheet("#pushButton_modifier{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->pushButton_statistiques->setStyleSheet("#pushButton_statistiques{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->PDF->setStyleSheet("#PDF{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->pushButton_supprimer->setStyleSheet("#pushButton_supprimer{border-radius: 10px;background: transparent;}");
    ui->dark->setStyleSheet("#dark{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #444;border: 2px solid #777;}#dark:pressed {background-color: #222;border: 2px solid #999;}");
    ui->light->setStyleSheet("#light {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#light:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
    ui->bg->setStyleSheet("#bg{background-image: url(:/img/img/background.jpg);}");

}


void MainWindow::filtrerParCategorie(const QString &category)
{
    // Vérifier si une catégorie est sélectionnée
    if (category.isEmpty()) {
        return;
    }

    // Créer un modèle pour stocker les résultats
    QSqlQueryModel *model = new QSqlQueryModel();

    // Construire la requête SQL pour filtrer par catégorie
    QString queryStr = "SELECT id, name, last_name, nb_carton, nb_match_a, category, email FROM arbitre WHERE category = ?";
    QSqlQuery query;
    query.prepare(queryStr);
    query.addBindValue(category);

    query.exec();
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", query.lastError().text());
        return;
    }


    // Appliquer la requête au modèle
    model->setQuery(query);

    // Vérifier s'il y a une erreur
    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du filtrage des arbitres.");
        return;
    }

    // Afficher le résultat dans le QTableView
    ui->tableView->setModel(model);
}


void MainWindow::trierArbitres(const QString &colonne)
{
    // Créer un modèle pour afficher les résultats
    QSqlQueryModel *model = new QSqlQueryModel();

    // Créer la requête SQL de tri, avec la colonne sélectionnée
    QString queryStr = "SELECT id, name, last_name, nb_carton, nb_match_a, category, email FROM arbitre WHERE category = '" + colonne + "' ORDER BY id";

    // Appliquer la requête à ce modèle
    model->setQuery(queryStr);



    // Vérifier s'il y a une erreur dans la requête
    if (model->lastError().isValid()) {
        qDebug() << "Erreur SQL:" << model->lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors du tri des arbitres.");
        return;
    }


    // Appliquer le modèle au QTableView pour afficher les données triées
    ui->tableView->setModel(model);
     logAction("Tri des arbitres par catégorie: " + colonne);
}


/*void MainWindow::on_pushButton_statistiques_clicked()
{
    Statistique stats;
    stats.exec();
    logAction("Affichage des statistiques d'un arbitre");

}*/

// Assuming you have a QPushButton named 'showStatistiqueButton'
/*void MainWindow::on_pushButton_statistiques_clicked()
{
    dialog_window = new Dialog(this);
    dialog_window->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup
    dialog_window->show();
}*/

void MainWindow::on_pushButton_statistiques_clicked()
{
    dialog_window = new Dialog(this);
    dialog_window->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup
    dialog_window->show();
}



/*void MainWindow::exporterListeArbitresPDF()
{
    // 1. Demander où enregistrer le fichier PDF
    QString fileName = QFileDialog::getSaveFileName(this, tr("Exporter en PDF"), "", tr("Fichiers PDF (*.pdf)"));
    if (fileName.isEmpty())
        return;

    // 2. Configurer l'impression en PDF
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    QPageSize pageSize(QPageSize::A4);
    QPageLayout layout(pageSize, QPageLayout::Portrait, QMarginsF(10, 10, 10, 10));

    printer.setPageLayout(layout);

    printer.setOutputFileName(fileName);

    QPainter painter;
    if (!painter.begin(&printer)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier PDF");
        return;
    }

    // 3. Configuration de la police (plus petite pour s’adapter)
    QFont font("Arial", 8);
    painter.setFont(font);

    // 4. Titre du document (centré et en plus grand)
    QFont titleFont("Arial", 20, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(QRect(50, 500, 500, 30), Qt::AlignCenter, "Liste des Arbitres");

    // 5. Récupérer les données du QTableView
    QAbstractItemModel *model = ui->tableView->model();
    if (!model || model->rowCount() == 0) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à exporter !");
        return;
    }

    // 6. Définition des dimensions du tableau
    int startX = 50;
    int startY = 10;
    int rowHeight = 500;  // Hauteur réduite pour que le tableau reste lisible
    int columnWidth = 900;  // Largeur augmentée pour plus d’espace
    int numCols = model->columnCount();
    int numRows = model->rowCount();

    // Définition de la couleur des bordures
    QPen pen(Qt::black);
    pen.setWidth(1); // Épaisseur plus fine
    painter.setPen(pen);

    // 6.1 En-têtes des colonnes (avec un fond gris clair)
    QStringList headers = {"ID", "Nom", "Prénom", "Cartons", "Matchs Arbitrés", "Catégorie", "Email"};
    painter.setFont(QFont("Arial", 9, QFont::Bold)); // Police plus lisible pour les en-têtes

    // Dessiner l’en-tête
    painter.fillRect(QRect(startX, startY, columnWidth * headers.size(), rowHeight), QColor(220, 220, 220));
    for (int col = 0; col < headers.size(); ++col) {
        QRect cellRect(startX + col * columnWidth, startY, columnWidth, rowHeight);
        painter.drawRect(cellRect);
        painter.drawText(cellRect, Qt::AlignCenter, headers[col]);
    }

    // 6.2 Remplir le tableau avec les données
    startY += rowHeight; // Déplacer sous l'en-tête
    painter.setFont(QFont("Arial", 8)); // Texte des données plus petit

    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            QString data = model->data(model->index(row, col)).toString();
            QRect cellRect(startX + col * columnWidth, startY + row * rowHeight, columnWidth, rowHeight);

            // Appliquer un fond alterné (gris clair pour les lignes paires)
            if (row % 2 == 0) {
                painter.fillRect(cellRect, QColor(245, 245, 245));
            }

            // Dessiner la bordure
            painter.drawRect(cellRect);

            // Dessiner le texte centré verticalement et à gauche
            painter.drawText(cellRect.adjusted(5, 0, -5, 0), Qt::AlignVCenter | Qt::AlignLeft, data);
        }
    }

    // 7. Fin de l'écriture et message de succès
    painter.end();
    QMessageBox::information(this, "Succès", "L'exportation a été effectuée avec succès !");
    logAction("export d'un pdf d'un arbitre");
}
*/



void MainWindow::on_btn_ouvrirEmailDialog_clicked()
{
    EmailDialog dialog(this);
    dialog.exec(); // Affiche la fenêtre modale
    logAction("email envoyer a un arbitre");
}
void MainWindow::on_pushButton_guess_clicked()
{
    QSqlQuery query("SELECT NAME, EMAIL FROM ARBITRE");

    QVector<QPair<QString, QString>> arbitresDisponibles;

    while (query.next()) {
        QString nom = query.value(0).toString();
        QString email = query.value(1).toString();
        arbitresDisponibles.append(qMakePair(nom, email));
    }

    if (arbitresDisponibles.isEmpty()) {
        ui->label_resultat->setText("Aucun arbitre disponible !");
        return;
    }

    int index = QRandomGenerator::global()->bounded(arbitresDisponibles.size());
    QPair<QString, QString> arbitreChoisi = arbitresDisponibles[index];

    QString message = QString("🎉 Chanceux ! Tu vas arbitrer le prochain match !\n\n")
                      + QString("Nom : %1\nEmail : %2")
                            .arg(arbitreChoisi.first)
                            .arg(arbitreChoisi.second);

    ui->label_resultat->setStyleSheet("font-family: Arial; font-weight: bold; font-size: 10pt;");
    ui->label_resultat->setText(message);

    envoyerEmail(arbitreChoisi.second, arbitreChoisi.first);

    QMessageBox::information(this, "Succès", "L'email a été envoyé avec succès au juge sélectionné!");
}


void MainWindow::envoyerEmail(const QString &email, const QString &nom)
{
    QString pythonScript = "C:/scripts/envoyer_email.py";  // Assure-toi que le chemin est correct
    QString pythonExe = "C:/Users/Hammami Yessmie/AppData/Local/Programs/Python/Python313/python.exe";  // Vérifie que Python est installé à ce chemin

    QProcess process;
    QStringList arguments;
    arguments << pythonScript << email << nom;  // On passe les arguments nécessaires (email et nom)

    process.start(pythonExe, arguments);  // Lance le script Python avec les arguments
    process.waitForFinished();

    // Lire la sortie du script Python
    QString output = process.readAllStandardOutput();
    QString errorOutput = process.readAllStandardError();

    qDebug() << "Python Output:" << output;
    qDebug() << "Python Error:" << errorOutput;

    // Vérification de l'envoi de l'email
    if (output.contains("Email envoyé avec succès")) {
        QMessageBox::information(this, "Succès", "📬 L'email a été envoyé avec succès !");
        logAction(QString("Email envoyé à %1 (%2)").arg(nom, email));
    } /*else {
        QMessageBox::warning(this, "Erreur", "❌ Problème lors de l'envoi de l'email.\n" + errorOutput);
    }*/
}



void MainWindow::logAction(const QString &actionDetails)
{
    QFile file("historique.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        QString timestamp = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
        out << timestamp << " | " << actionDetails << "\n";
    }
}





    // Dans mainwindow.cpp
void MainWindow::on_pushButton_Historique_clicked()
{
    HistoriqueDialog h(this);
    h.exec();
}
void MainWindow::on_btn_test_voice_clicked()
{
    QMessageBox::information(this, "🎤 voice", "chercher...");

    QString pythonExe = "C:/Users/Hammami Yessmie/AppData/Local/Programs/Python/Python313/python.exe";
    QString scriptPath = "C:/Users/Hammami Yessmie/OneDrive/Desktop/Atelier_Connexion (2)/Atelier_Connexion/voice_command_system/understand_command.py";

    QProcess process;
    process.start(pythonExe, QStringList() << scriptPath);

    // ننتظر 10 ثواني، وبعدها نقتل البروسيس إذا ما كملش
    if (!process.waitForFinished(10000)) {
        if (process.state() != QProcess::NotRunning) {
            process.kill();
            process.waitForFinished();
        }
        QMessageBox::critical(this, "Erreur", "انتهت المهلة ولم ينته السكريبت.");
        return;
    }

    QString sortie = process.readAllStandardOutput().trimmed();
    QString erreur = process.readAllStandardError().trimmed();

    qDebug() << "Sortie Python :" << sortie;
    qDebug() << "Erreur Python :" << erreur;

    if (!erreur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Une erreur s'est produite : " + erreur);
        return;
    }

    QStringList lignes = sortie.split(QRegularExpression("[\r\n]+"), Qt::SkipEmptyParts);
    for (const QString &line : lignes) {
        qDebug() << "🔹 ligne:" << line;
    }

    QString derniereLigne = lignes.last().trimmed();

    QStringList resultat = derniereLigne.split(":");
    if (resultat.size() < 2) {
        QMessageBox::warning(this, "Erreur", "Commande invalide.");
        return;
    }

    QString typeCommande = resultat.value(0).trimmed();
    QString cible = resultat.value(1).trimmed();

    if (typeCommande == "search") {
        on_lineEdit_rechercher_textChanged(cible);
    } else {
        QMessageBox::warning(this, "Erreur", "Commande non reconnue.");
    }
}



void MainWindow::testerCommandeVocale(QString spokenText)
{
    QString pythonExe = "C:/Users/Hammami Yessmie/AppData/Local/Programs/Python/Python313/python.exe";
    QString scriptPath = "C:/Users/Hammami Yessmie/OneDrive/Desktop/Atelier_Connexion (2)/Atelier_Connexion/voice_command_system/understand_command.py";

    qDebug() << "Spoken Text: " << spokenText;

    QStringList arguments;
    arguments << scriptPath << spokenText;

    QProcess* process = new QProcess(this);
    process->start(pythonExe, arguments);
    process->waitForFinished();

    QString output = process->readAllStandardOutput().trimmed();
    delete process;

    qDebug() << "Python Output: " << output;

    if (output.startsWith("search:")) {
        QString nomRecherche = output.section(":", 1).trimmed();
        chercherEtAfficher(nomRecherche);
    } else if (output == "unknown:commande") {
        QMessageBox::information(this, "Commande inconnue", "لم يتم التعرف على الأمر الصوتي.");
    } else {
        QMessageBox::warning(this, "خطأ", "لم يتم فهم الأمر الصوتي.");
    }
}


bool MainWindow::chercherEtAfficher(const QString &nomRecherche)
{
    // تأكد من أن لديك `tableView` و `model()`
    for (int row = 0; row < ui->tableView->model()->rowCount(); ++row) {
        QString nomTable = ui->tableView->model()->index(row, 0).data().toString().trimmed().toLower();

        // إذا كان اسم الـ "Table" يحتوي على النص المُدخل
        if (nomTable.contains(nomRecherche.toLower())) {
            // مثال لعرض النتيجة في جدول جديد أو شيء آخر
            qDebug() << "Found: " << nomTable;
            // فعل شيء حسب النتيجة (مثلاً: التحديد في الـ QTableView)
        }
    }
}

void MainWindow::on_PDF_clicked()
{
        qDebug() << "on_pdf_clicked() called.";

        // Fetch data from the database
        QSqlQuery query;
        query.prepare("SELECT id, name, last_name, nb_carton, nb_match_a, category, email FROM ARBITRE");

        if (!query.exec()) {
            QMessageBox::critical(this, "Database Error", "Failed to retrieve data: " + query.lastError().text());
            qDebug() << "SQL Error: " << query.lastError().text();
            return;
        }

        int rowCount = 0;
        QString html = "<h2>Arbitres List</h2><table border='1' width='100%'>";
        html += "<tr><th>ID</th><th>Name</th><th>Last_name</th><th>Nb_carton</th><th>Nb_match_a</th><th>Category</th><th>Email</th></tr>";

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
            QMessageBox::warning(this, "No Data", "No Arbitre found in the database.");
            qDebug() << "No Arbitre found!";
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


