#include "mainwindow_supporteur.h"
#include "ui_mainwindow_supporteur.h"
#include "supporteur.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QDate>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPrintpreviewDialog>
#include <QCoreApplication>
#include "arduino.h"


MainWindowSupporteur::MainWindowSupporteur(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowSupporteur)
{
    ui->setupUi(this);
    afficher();/*
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug()<<"arduino is avaible and connected to : "<<A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" << A.getarduino_port_name();
        break;
    case(-1): qDebug() << "arduino is not available";
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));*/
    QSerialPort *serial = new QSerialPort(this);
    serial->setPortName("COM5");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    // Try opening the port
    if (serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial port opened successfully!";
    } else {
        qDebug() << "Failed to open serial port!";
        return;  // Exit if the port couldn't be opened
    }

    // Check if the port is writable
    if (serial->isWritable()) {
        qDebug() << "Writing to serial...";
        serial->write("1");
        qDebug() << "Data written!";
    } else {
        qDebug() << "Couldn't write to serial!";
    }


}

MainWindowSupporteur::~MainWindowSupporteur()
{
    delete ui;
}

/*void MainWindow::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, NAME, LAST_NAME, DATE_NAIS, GRADE FROM SUPPORTEUR");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("GRADE"));

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}*/
void MainWindowSupporteur::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, NAME, LAST_NAME, DATE_NAIS, GRADE FROM SUPPORTEUR");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NAME"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("LAST_NAME"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DATE_NAIS"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("GRADE"));

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->resizeColumnsToContents();

    // Connect the search bar
    connect(ui->search_bar, &QLineEdit::textChanged, this, [proxyModel](const QString &text) {
        proxyModel->setFilterKeyColumn(1);  // Column index for NAME
        proxyModel->setFilterRegularExpression(QRegularExpression(text, QRegularExpression::CaseInsensitiveOption));

    });
    // Resize columns and rows dynamically
    ui->tableView->setColumnWidth(5, 70);  // Set column width to fit the image
    ui->tableView->verticalHeader()->setDefaultSectionSize(70);  // Increase row height

    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

}


/*void MainWindow::on_add_clicked() {
    //Validate if fields are not empty
    if (ui->IdEdit->text().isEmpty() || ui->NameEdit->text().isEmpty() ||
        ui->LastnameEdit->text().isEmpty() || !ui->DateEdit->date().isValid() ||
        ui->GradeEdit->text().isEmpty()) {

        QMessageBox::critical(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    int id = ui->IdEdit->text().toInt();
    QString NAME = ui->NameEdit->text();
    QString LAST_NAME = ui->LastnameEdit->text();
    QDate DATE_NAIS = ui->DateEdit->date();
    int GRADE = ui->GradeEdit->text().toInt();

    supporteur s(id, NAME, LAST_NAME, DATE_NAIS, GRADE);

    if (s.ajouter()) {
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
        afficher();
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué. Vérifiez la console pour plus de détails.");
    }
}*/
void MainWindowSupporteur::on_add_clicked() {
    // Validation des champs vides avec des messages d'erreur spécifiques pour chaque champ
    if (ui->IdEdit->text().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "L'ID ne peut pas être vide !");
        return;
    }

    if (ui->NameEdit->text().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Le nom ne peut pas être vide !");
        return;
    }

    if (ui->LastnameEdit->text().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Le prénom ne peut pas être vide !");
        return;
    }

    if (!ui->DateEdit->date().isValid()) {
        QMessageBox::critical(this, "Erreur", "La date de naissance est invalide ou vide !");
        return;
    }

    if (ui->GradeEdit->text().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Le grade ne peut pas être vide !");
        return;
    }

    // Conversion des champs en variables appropriées
    int id = ui->IdEdit->text().toInt();
    QString NAME = ui->NameEdit->text();
    QString LAST_NAME = ui->LastnameEdit->text();
    QDate DATE_NAIS = ui->DateEdit->date();
    int GRADE = ui->GradeEdit->text().toInt();

    // Création de l'objet supporteur
    supporteur s(id, NAME, LAST_NAME, DATE_NAIS, GRADE);

    // Tentative d'ajout du supporteur
    if (s.ajouter()) {
        QMessageBox::information(this, "Succès", "Ajout effectué avec succès !");
        afficher();  // Rafraîchir l'affichage après l'ajout
    } else {
        QMessageBox::critical(this, "Erreur", "L'ajout a échoué. Vérifiez la console pour plus de détails.");
    }
}

void MainWindowSupporteur::on_delete_2_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "No Row Selected", "Please select a ticket to delete.");
        return;
    }

    int id = selectedRows.first().data(Qt::DisplayRole).toInt();

    supporteur supporteur;
    if (supporteur.supprimer(id)) {
        qDebug() << "supporteur with id" << id << "successfully deleted.";
        afficher();
    } else {
        qDebug() << "Failed to delete the supporteur with id" << id;
    }
}

/*void MainWindow::on_cancel_clicked()
{
    ui->ID->clear();
    ui->NAME->setCurrentIndex(0);
    ui->LAST_NAME->clear();
    ui->DATE_NAIS->setDate(QDate::currentDate());
    ui->GRADE->setCurrentIndex(0);

    qDebug() << "Form has been reset.";
}*/

void MainWindowSupporteur::on_modify_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Sélection manquante", "Veuillez sélectionner une ligne avant de modifier.");
        return;
    }

    int id = ui->IdEdit->text().toInt();
    QString NAME = ui->NameEdit->text();
    QString LAST_NAME = ui->LastnameEdit->text();
    QDate DATE_NAIS = ui->DateEdit->date();
    int GRADE = ui->GradeEdit->text().toInt();

    supporteur s;
    s.setNAME(NAME);
    s.setLAST_NAME(LAST_NAME);
    s.setDATE_NAIS(DATE_NAIS);
    s.setGRADE(GRADE);

    bool test = s.modifier(id);
    qDebug() << "Modifier function result:" << test;

    if (test) {
        afficher();
        QMessageBox::information(this, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée\nCliquez sur Cancel pour quitter."),
                                 QMessageBox::Cancel);
    } else {
        QMessageBox::critical(this, QObject::tr("Erreur"),
                              QObject::tr("La modification n'a pas pu être effectuée.\nCliquez sur Cancel pour quitter."),
                              QMessageBox::Cancel);
    }
}



void MainWindowSupporteur::on_tableView_clicked(const QModelIndex &index)
{
    int row = index.row();

    int id = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toInt();
    QString NAME = ui->tableView->model()->data(ui->tableView->model()->index(row, 1)).toString();
    QString LAST_NAME = ui->tableView->model()->data(ui->tableView->model()->index(row, 2)).toString();
    QDate DATE_NAIS = ui->tableView->model()->data(ui->tableView->model()->index(row, 3)).toDate();
    int GRADE = ui->tableView->model()->data(ui->tableView->model()->index(row, 4)).toInt();

    ui->IdEdit->setText(QString::number(id));
    ui->NameEdit->setText(NAME);
    ui->LastnameEdit->setText(LAST_NAME);
    ui->DateEdit->setDate(DATE_NAIS);
    ui->GradeEdit->setText(QString::number(GRADE));

    qDebug() << "Row selected with ID:" << id;
}


void MainWindowSupporteur::on_pdf_clicked()
{
    qDebug() << "on_pdf_clicked() called.";

    // Fetch data from the database
    QSqlQuery query;
    query.prepare("SELECT id, NAME, LAST_NAME, DATE_NAIS, GRADE FROM SUPPORTEUR");

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve data: " + query.lastError().text());
        qDebug() << "SQL Error: " << query.lastError().text();
        return;
    }

    int rowCount = 0;
    QString html = "<h2>Tickets List</h2><table border='1' width='100%'>";
    html += "<tr><th>ID</th><th>NAME</th><th>LAST_NAME</th><th>Birth Date</th><th></th>Grade</tr>";

    while (query.next()) {
        rowCount++;
        html += "<tr>";
        html += "<td>" + query.value(0).toString() + "</td>";
        html += "<td>" + query.value(1).toString() + "</td>";
        html += "<td>" + query.value(2).toString() + "</td>";
        html += "<td>" + query.value(3).toString() + "</td>";
        html += "<td>" + query.value(4).toString() + "</td>";
        html += "<td>" + query.value(5).toDate().toString("yyyy-MM-dd") + "</td>";
        html += "<td>" + query.value(6).toDate().toString("yyyy-MM-dd") + "</td>";
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


void MainWindowSupporteur::on_tri_activated(int index)
{
    supporteur s;
    QSqlQueryModel *model = nullptr;

    if (index == 0)
        model = s.tridateNaissanceDesc();  // Youngest first
    else if (index == 1)
        model = s.tridateNaissanceAsc();   // Oldest first
    else
        return;

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);
    proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);

    ui->tableView->setModel(proxyModel);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Search by NAME
    connect(ui->search_bar, &QLineEdit::textChanged, this, [proxyModel](const QString &text) {
        proxyModel->setFilterKeyColumn(1); // 1 = NAME column
        proxyModel->setFilterRegularExpression(QRegularExpression(text, QRegularExpression::CaseInsensitiveOption));
    });
}



void MainWindowSupporteur::on_stat_clicked()
{
    dialog_window = new Dialog(this);
    dialog_window->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup
    dialog_window->show();
}
// void MainWindow::update_arduino_status() {
//     if (A.connect_arduino() != -1) {
//         ui->label_4->setText("ON");
//     } else {
//         ui->label_4->setText("OFF");
//     }
// }
// void MainWindow::update_label()
// {
//     // Code ici : par exemple
//     A.read_from_arduino();
//     ui->label_4->setText("Label mis à jour");
// }

// void MainWindow::on_pushButton_clicked(){
//      qDebug() << "wa 1";
//     A.write_to_arduino(QString("1")); // Send '1' to Arduino (Turn on the servo)
// }

// void MainWindow::on_pushButton_2_clicked(){
//     qDebug() << "wa 1";
//     A.write_to_arduino(QString("0")); // Send '0' to Arduino (Turn off the servo)
// }


// void MainWindow::on_dark_clicked()
// {
//     // Set dark mode styles for the QTableView widget
//     QString darkTableStyle = R"(
//         QTableView {
//             background-color:#A9A9A9;   /* Black background */
//             color: white;                /* White text */
//         }

//         QTableView::item {
//             background-color:#A9A9A9;   /* Black background for table items */
//             color: white;                /* White text for table items */
//         }

//         QHeaderView::section {
//             background-color:#A9A9A9;   /* Dark grey for header */
//             color: white;                /* White text for header */
//             padding: 5px;
//         }
//     )";

//     // Apply the stylesheet to the table widget
//     ui->tableView->setStyleSheet(darkTableStyle);
//     // Set styles for the Form widget (background black, white border)
//     QString formStyle = R"(
//         #form {
//             background-color: #A9A9A9;   /* Black background */
//             border: 2px solid white;     /* White border */
//             border-radius: 10px;         /* Rounded corners */
//         }

//         /* Set QLabel text color to white */
//         #form QLabel {
//             color: white;
//         }

//         /* Set QLineEdit style (black background, white border, white text) */
//         #form QLineEdit {
//             background-color: #121212;   /* Black background */
//             color:  #121212;                /* White text */
//             border: 1px solid white;     /* White border */
//             border-radius: 10px;         /* Rounded corners */
//             padding: 5px;
//         }

//         /* Set QComboBox and QTextEdit style (black background, white border, white text) */
//         #form QComboBox, #form QTextEdit {
//             background-color: #121212;   /* Black background */
//             color: black;                /* White text */
//             border: 1px solid white;     /* White border */
//             border-radius: 10px;         /* Rounded corners */
//             padding: 5px;
//         }
//     )";

//     // Apply the stylesheet to the Form widget
//     ui->form->setStyleSheet(formStyle);
//     // Set common button style (transparent background, white border, white text)
//     QString buttonStyle = R"(
//         QPushButton {
//             background-color: black;  /* Transparent background */
//             color: white;                   /* White text */
//             border: 1px solid white;        /* White border */
//             border-radius: 10px;            /* Rounded corners */
//             padding: 5px 10px;              /* Padding inside buttons */
//         }

//         QPushButton:hover {
//             background-color: rgba(255, 255, 255, 20%);  /* Light hover effect */
//         }

//         QPushButton:pressed {
//             background-color: rgba(255, 255, 255, 40%);  /* Darker effect when pressed */
//         }
//     )";

//     // Apply the button style to all buttons
//     ui->add->setStyleSheet(buttonStyle);
//     ui->cancel->setStyleSheet("#cancel{border-radius: 10px;background: transparent;}");
//     ui->modify->setStyleSheet(buttonStyle);
//     ui->stat->setStyleSheet(buttonStyle);
//     ui->delete_2->setStyleSheet("#delete_2{border-radius: 10px;background: transparent;}");
//     ui->dark_ilyes->setStyleSheet("#dark {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#dark:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
//     ui->light_ilyes->setStyleSheet("#light{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #444;border: 2px solid #777;}#light:pressed {background-color: #222;border: 2px solid #999;}");
//     ui->label->setStyleSheet("#bg{background-color:#F5F5F5;}");
//     ui->menu->setStyleSheet("#menu{background-color:#A9A9A9;border-radius: 10px;padding: 5px;}");


// }




// void MainWindow::on_light_clicked()
// {
//     // Clear only the dark mode custom stylesheet applied earlier
//     qApp->setStyleSheet("");  // Clear the global dark mode stylesheet
//     // reset
//     ui->tableView->setStyleSheet("#tableView{background:rgba(33, 133, 85, 0.4);border-radius: 10px;padding: 5px;}");
//     ui->form->setStyleSheet("#form{background:rgba(214, 215, 222, 0.4);border-radius: 10px;padding: 5px;}");
//     ui->menu->setStyleSheet("#menu{background-color:#218555;border-radius: 10px;padding: 5px;}");
//     ui->add->setStyleSheet("#add{border-radius: 10px;padding: 5px;background: #218555; }");
//     ui->cancel->setStyleSheet("#cancel{border-radius: 10px;background: transparent;}");
//     ui->modify->setStyleSheet("#modify{border-radius: 10px;padding: 5px;background: #218555; }");

//     ui->stat->setStyleSheet("#stat{border-radius: 10px;padding: 5px;background: #218555; }");
//     ui->delete_2->setStyleSheet("#delete_2{border-radius: 10px;background: transparent;}");
//     ui->dark_ilyes->setStyleSheet("#dark{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #444;border: 2px solid #777;}#dark:pressed {background-color: #222;border: 2px solid #999;}");
//     ui->light_ilyes->setStyleSheet("#light {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#light:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
//     ui->label->setStyleSheet("#bg{background-image: url(:/image/img/bg.jpeg);}");

// }


void MainWindowSupporteur::on_dark_ilyes_clicked()
{
    //Set dark mode styles for the QTableView widget
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
    ui->add->setStyleSheet(buttonStyle);
    ui->cancel->setStyleSheet("#cancel{border-radius: 10px;background: transparent;}");
    ui->modify->setStyleSheet(buttonStyle);
    ui->stat->setStyleSheet(buttonStyle);
    ui->delete_2->setStyleSheet("#delete_2{border-radius: 10px;background: transparent;}");
    ui->dark_ilyes->setStyleSheet("#dark {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#dark:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
    ui->light_ilyes->setStyleSheet("#light{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #444;border: 2px solid #777;}#light:pressed {background-color: #222;border: 2px solid #999;}");
    ui->label->setStyleSheet("#bg{background-color:#F5F5F5;}");
    ui->menu->setStyleSheet("#menu{background-color:#A9A9A9;border-radius: 10px;padding: 5px;}");
    ui->IdEdit->setStyleSheet("#IdEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #333;}");
    ui->NameEdit->setStyleSheet("#NameEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #333;}");
    ui->LastnameEdit->setStyleSheet("#LastnameEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #333;}");
    ui->DateEdit->setStyleSheet("#DateEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #333;}");
    ui->GradeEdit->setStyleSheet("#GradeEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #333;}");


}


void MainWindowSupporteur::on_light_ilyes_clicked()
{
    ui->tableView->setStyleSheet("#tableView{background:rgba(33, 133, 85, 0.4);border-radius: 10px;padding: 5px;}");
    ui->form->setStyleSheet("#form{background:rgba(214, 215, 222, 0.4);border-radius: 10px;padding: 5px;}");
    ui->menu->setStyleSheet("#menu{background-color:#218555;border-radius: 10px;padding: 5px;}");
    ui->add->setStyleSheet("#add{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->cancel->setStyleSheet("#cancel{border-radius: 10px;background: transparent;}");
    ui->modify->setStyleSheet("#modify{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->stat->setStyleSheet("#stat{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->delete_2->setStyleSheet("#delete_2{border-radius: 10px;background: transparent;}");
    ui->dark_ilyes->setStyleSheet("#dark{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #444;border: 2px solid #777;}#dark:pressed {background-color: #222;border: 2px solid #999;}");
    ui->light_ilyes->setStyleSheet("#light {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#light:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
    ui->label->setStyleSheet("#label{ background-image:url(:/img/img/bg.jpg);}");
    ui->IdEdit->setStyleSheet("#IdEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #619D80;}");
    ui->NameEdit->setStyleSheet("#NameEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #619D80;}");
    ui->LastnameEdit->setStyleSheet("#LastnameEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #619D80;}");
    ui->DateEdit->setStyleSheet("#DateEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #619D80;}");
    ui->GradeEdit->setStyleSheet("#GradeEdit{border-radius: 10px;padding: 5px;background: white;border: 2px solid #619D80;}");
}

