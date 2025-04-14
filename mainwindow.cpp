#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arbitre.h"
#include <QMessageBox>
#include <QPalette>
#include <QRadioButton>
#include <QSqlError>
#include "statistique.h"
#include <QFileDialog>
#include <QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidgetItem>
#include <QSqlQueryModel>
#include <QPageLayout>
#include <QPageSize>
#include "emaildialog.h"
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include "historiqueDialog.h"
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "reclamationwindow.h"
#include <QInputDialog>



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
    connect(ui->radioButton_night, &QRadioButton::clicked, this, &MainWindow::on_radioButton_night_clicked);
    connect(ui->radioButton_light, &QRadioButton::clicked, this, &MainWindow::on_radioButton_light_clicked);
    connect(ui->comboBox_tri, &QComboBox::currentTextChanged, this, &MainWindow::trierArbitres);
    connect(ui->PDF, &QPushButton::clicked, this, &MainWindow::exporterListeArbitresPDF);
    connect(ui->btn_ouvrirEmailDialog, &QPushButton::clicked, this, &MainWindow::on_btn_ouvrirEmailDialog_clicked);
    connect(ui->pushButton_guess, &QPushButton::clicked, this, &MainWindow::on_pushButton_guess_clicked);
    connect(ui->pushButton_Historique, &QPushButton::clicked, this, &MainWindow::on_pushButton_Historique_clicked);
    connect(ui->btn_test_voice, &QPushButton::clicked, this, &MainWindow::on_btn_test_voice_clicked);
    reclamationWindow = new ReclamationWindow(this);
    connect(reclamationWindow, &ReclamationWindow::reclamationSubmitted, this, &MainWindow::onReclamationSubmitted);
    loadReclamations();

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
    arbitre a(0, "", "", 0, 0, "", ""); //
    ui->tableView->setModel(a.rechercher(arg1));


    if (!arg1.isEmpty()) {
        QString logDetail = QString("Recherche d'un arbitre avec le terme : %1").arg(arg1);
        logAction(logDetail);  //
    } else {
        logAction("Recherche d'un arbitre (champ vide)");
    }
}


void MainWindow::on_radioButton_night_clicked() {
    qApp->setStyleSheet(
        "QWidget { background-color: #121212; color: white; }"
        "QPushButton { background-color: #333; color: white; border-radius: 5px; padding: 5px; }"
        "QPushButton:hover { background-color: #444; }"
        "QLineEdit, QComboBox { background-color: #222; color: white; border: 1px solid #555; border-radius: 5px; padding: 3px; }"
        "QTableView { background-color: #1E1E1E; color: white; border: 1px solid #555; }"
        );
}

void MainWindow::on_radioButton_light_clicked() {
    qApp->setStyleSheet(
        "QWidget { background-color: white; color: black; }"
        "QPushButton { background-color: #f0f0f0; color: black; border-radius: 5px; padding: 5px; }"
        "QPushButton:hover { background-color: #e0e0e0; }"
        "QLineEdit, QComboBox { background-color: #fff; color: black; border: 1px solid #ccc; border-radius: 5px; padding: 3px; }"
        "QTableView { background-color: white; color: black; border: 1px solid #ccc; }"
        );
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


void MainWindow::on_pushButton_statistiques_clicked()
{
    Statistique stats;
    stats.exec();
    logAction("Affichage des statistiques d'un arbitre");
}



void MainWindow::exporterListeArbitresPDF()
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

        // نتحقق هل الإيميل موجود في جدول التظلمات
        bool aFaitReclamation = false;
        for (int i = 0; i < ui->tableWidget_reclamations->rowCount(); ++i) {
            QString emailReclamation = ui->tableWidget_reclamations->item(i, 1)->text(); // العمود 1 فيه الإيميل
            if (emailReclamation == email) {
                aFaitReclamation = true;
                break;
            }
        }

        if (!aFaitReclamation) {
            arbitresDisponibles.append(qMakePair(nom, email));
        }
    }

    if (arbitresDisponibles.isEmpty()) {
        ui->label_resultat->setText("Aucun arbitre disponible ! Tous ont réclamé.");
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
void MainWindow::on_btn_test_voice_clicked() {
    QString spokentest = "أرسل إيميل إلى هشام";
    testerCommandeVocale(spokentest);
}

void MainWindow::testerCommandeVocale(QString spokenText)
{
    QString pythonExe = "C:/Users/Hammami Yessmie/AppData/Local/Programs/Python/Python313/python.exe";
    QString scriptPath = "C:/Users/Hammami Yessmie/OneDrive/Desktop/Atelier_Connexion (2)/Atelier_Connexion/voice_command_system/understand_command.py";

    qDebug() << "Spoken Text: " << spokenText;

    QStringList arguments;
    arguments << scriptPath << spokenText;

    QProcess process;
    process.start(pythonExe, arguments);
    process.waitForFinished();

    QString output = process.readAllStandardOutput().trimmed();
    qDebug() << "Python Output: " << output;

    QStringList result = output.split(":");

    QString commandType = result.value(0);
    QString target = result.value(1);
    qDebug() << "Spoken Text: " << spokenText;
    qDebug() << "Python Output: " << output;
    qDebug() << "Command Type: " << commandType;
    qDebug() << "Target: " << target;


    if (commandType == "search") {
        on_lineEdit_rechercher_textChanged(target);
    } else if (commandType == "email") {
        QString email = target + "@example.com";
        envoyerEmail(email, target);
    } else {
        QMessageBox::warning(this, "خطأ", "لم يتم فهم الأمر الصوتي.");
    }
}
void MainWindow::on_pushButton_reclamer_clicked()
{
    ReclamationWindow *reclamationWindow = new ReclamationWindow(this);
    connect(reclamationWindow, &ReclamationWindow::reclamationSubmitted,
            this, &MainWindow::onReclamationSubmitted);
    reclamationWindow->exec();
}




void MainWindow::onReclamationSubmitted(const QString &name, const QString &email, const QString &reason)
{
    ui->tableWidget_reclamations->setColumnCount(5);
    QStringList headers;
    headers << "Nom" << "Email" << "Raison" << "Modifier" << "Supprimer";
    ui->tableWidget_reclamations->setHorizontalHeaderLabels(headers);

    QFile file("reclamations.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << name << "|" << email << "|" << reason << "\n";
        file.close();
    }


    int row = ui->tableWidget_reclamations->rowCount();
    ui->tableWidget_reclamations->insertRow(row);
    ui->tableWidget_reclamations->setItem(row, 0, new QTableWidgetItem(name));
    ui->tableWidget_reclamations->setItem(row, 1, new QTableWidgetItem(email));
    ui->tableWidget_reclamations->setItem(row, 2, new QTableWidgetItem(reason));
    QPushButton *btnModifier = new QPushButton("Modifier");
    connect(btnModifier, &QPushButton::clicked, this, [this, row]() {
        modifierReclamation(row);
    });
    ui->tableWidget_reclamations->setCellWidget(row, 3, btnModifier);

    // الزر "حذف"
    QPushButton *btnSupprimer = new QPushButton("Supprimer");
    connect(btnSupprimer, &QPushButton::clicked, this, [this, row]() {
        supprimerReclamation(row);
    });
    ui->tableWidget_reclamations->setCellWidget(row, 4, btnSupprimer);

}
void MainWindow::supprimerReclamation(int row)
{
    ui->tableWidget_reclamations->removeRow(row);


    enregistrerToutesLesReclamationsDansFichier();
}
void MainWindow::modifierReclamation(int row)
{
    QString nom = ui->tableWidget_reclamations->item(row, 0)->text();
    QString email = ui->tableWidget_reclamations->item(row, 1)->text();
    QString raison = ui->tableWidget_reclamations->item(row, 2)->text();

    // مثال: افتح نافذة إدخال جديدة (أو استعمل QInputDialog)
    bool ok;
    QString nouveauNom = QInputDialog::getText(this, "Modifier", "Nouveau nom :", QLineEdit::Normal, nom, &ok);
    if (!ok || nouveauNom.isEmpty()) return;

    ui->tableWidget_reclamations->item(row, 0)->setText(nouveauNom);




    enregistrerToutesLesReclamationsDansFichier();
}
void MainWindow::enregistrerToutesLesReclamationsDansFichier()
{
    QFile file("reclamations.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    QTextStream out(&file);
    for (int row = 0; row < ui->tableWidget_reclamations->rowCount(); ++row) {
        QString nom = ui->tableWidget_reclamations->item(row, 0)->text();
        QString email = ui->tableWidget_reclamations->item(row, 1)->text();
        QString raison = ui->tableWidget_reclamations->item(row, 2)->text();

        out << nom << ";" << email << ";" << raison << "\n";
    }

    file.close();
}


void MainWindow::loadReclamations()
{
    QFile file("reclamations.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() == 3) {
            int row = ui->tableWidget_reclamations->rowCount();
            ui->tableWidget_reclamations->insertRow(row);
            ui->tableWidget_reclamations->setItem(row, 0, new QTableWidgetItem(parts[0]));
            ui->tableWidget_reclamations->setItem(row, 1, new QTableWidgetItem(parts[1]));
            ui->tableWidget_reclamations->setItem(row, 2, new QTableWidgetItem(parts[2]));
        }
    }
    file.close();
}
