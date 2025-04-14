#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_billet.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSortFilterProxyModel>
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QUrl>
#include<QFileDialog>
#include<QPrintPreviewDialog>
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QWidget>
//dialog
#include"dialog_billet.h"
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

/*void MainWindow::afficher()
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

void MainWindow::afficher()
{
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve ticket data
    model->setQuery("SELECT id, type, price, quantity, area, date_issue, date_event FROM BILLET");

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Area"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Issue"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Event"));

    // Create a QSortFilterProxyModel for filtering
    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    // Assign the model to the QTableView
    ui->table->setModel(proxyModel);

    // Auto-resize columns and rows for better display
    ui->table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table->horizontalHeader()->setStretchLastSection(true);
    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Connect search_bar to filtering function
    connect(ui->search_bar, &QLineEdit::textChanged, [proxyModel](const QString &text) {
        // Check if the text contains only digits (ID filtering)

        bool isNumeric = text.toInt() != 0 || text == "0";  // Check if the text is numeric

        if (isNumeric) {  // Filter by ID
            proxyModel->setFilterKeyColumn(0);  // Column 0 is ID
        } else {  // Filter by Type
            proxyModel->setFilterKeyColumn(1);  // Column 1 is Type
        }

        // Set filter regular expression for the selected column (ID or Type)
        proxyModel->setFilterRegularExpression(QRegularExpression(text, QRegularExpression::CaseInsensitiveOption));
    });
}

*/
void MainWindow::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT id, type, price, quantity, area, date_issue, date_event, TICKETS FROM BILLET");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Quantity"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Area"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date Issue"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Event"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Ticket Image")); // Added TICKETS column

    QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(model);

    ui->table->setModel(proxyModel);

    // Define an inline delegate for displaying images
    class ImageDelegate : public QStyledItemDelegate {
    public:
        using QStyledItemDelegate::QStyledItemDelegate; // Inherit constructor

        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
            if (index.column() == 7) { // Image column
                QByteArray imgData = index.data(Qt::EditRole).toByteArray();
                QPixmap pixmap;
                pixmap.loadFromData(imgData);

                if (!pixmap.isNull()) {
                    QRect rect = option.rect;
                    QSize newSize(150, 150);  // Set image size bigger
                    pixmap = pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                    int x = rect.x() + (rect.width() - pixmap.width()) / 2; // Center horizontally
                    int y = rect.y() + (rect.height() - pixmap.height()) / 2; // Center vertically
                    painter->drawPixmap(x, y, pixmap);
                }
            } else {
                QStyledItemDelegate::paint(painter, option, index);
            }
        }

        QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
            if (index.column() == 7) {
                return QSize(150, 150); // Bigger image size
            }
            return QStyledItemDelegate::sizeHint(option, index);
        }
    };

    // Apply the image delegate
    ui->table->setItemDelegateForColumn(7, new ImageDelegate(this));

    // Resize columns and rows dynamically
    ui->table->setColumnWidth(7, 150);  // Set column width to fit the image
    ui->table->verticalHeader()->setDefaultSectionSize(150);  // Increase row height

    ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->search_bar, &QLineEdit::textChanged, [proxyModel](const QString &text) {
        bool isNumeric = text.toInt() != 0 || text == "0";
        proxyModel->setFilterKeyColumn(isNumeric ? 0 : 1);
        proxyModel->setFilterRegularExpression(QRegularExpression(text, QRegularExpression::CaseInsensitiveOption));
    });
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
    QSqlQueryModel* model = nullptr;

    if (selectedOption == "Expensive") {  // Tri par prix élevé (décroissant)
        model = gb.triPrixDecroissant();
    }
    else if (selectedOption == "Cheap") {  // Tri par prix bas (croissant)
        model = gb.triPrixCroissant();
    }
    else if (selectedOption == "Default") {  // Tri par ID (ordre normal)
        model = gb.triid();  // ou une méthode pour trier par ID
    }

    // Mettre à jour la table avec les données triées
    if (model) {
        // Apply the model
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel(this);
        proxyModel->setSourceModel(model);

        ui->table->setModel(proxyModel);

        // Define and apply the delegate for images (again after setting a new model)
        class ImageDelegate : public QStyledItemDelegate {
        public:
            using QStyledItemDelegate::QStyledItemDelegate; // Inherit constructor

            void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
                if (index.column() == 7) { // Image column
                    QByteArray imgData = index.data(Qt::EditRole).toByteArray();
                    QPixmap pixmap;
                    pixmap.loadFromData(imgData);

                    if (!pixmap.isNull()) {
                        QRect rect = option.rect;
                        QSize newSize(150, 150);  // Set image size bigger
                        pixmap = pixmap.scaled(newSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

                        int x = rect.x() + (rect.width() - pixmap.width()) / 2; // Center horizontally
                        int y = rect.y() + (rect.height() - pixmap.height()) / 2; // Center vertically
                        painter->drawPixmap(x, y, pixmap);
                    }
                } else {
                    QStyledItemDelegate::paint(painter, option, index);
                }
            }

            QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override {
                if (index.column() == 7) {
                    return QSize(150, 150); // Adjusted size for images
                }
                return QStyledItemDelegate::sizeHint(option, index);
            }
        };

        // Apply the image delegate to the table for column 7
        ui->table->setItemDelegateForColumn(7, new ImageDelegate(this));

        // Resize columns and rows dynamically to fit images
        ui->table->setColumnWidth(7, 150);  // Set image column width
        ui->table->verticalHeader()->setDefaultSectionSize(150);  // Set row height to fit image
        // Apply search proxy model again
        connect(ui->search_bar, &QLineEdit::textChanged, [proxyModel](const QString &text) {
            bool isNumeric = text.toInt() != 0 || text == "0";
            proxyModel->setFilterKeyColumn(isNumeric ? 0 : 1);
            proxyModel->setFilterRegularExpression(QRegularExpression(text, QRegularExpression::CaseInsensitiveOption));
        });
    }

}



void MainWindow::on_pdf_clicked() {
    qDebug() << "on_pdf_clicked() called.";

    // Fetch data from the database
    QSqlQuery query;
    query.prepare("SELECT id, type, price, quantity, area, date_issue, date_event FROM BILLET");

    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to retrieve data: " + query.lastError().text());
        qDebug() << "SQL Error: " << query.lastError().text();
        return;
    }

    int rowCount = 0;
    QString html = "<h2>Tickets List</h2><table border='1' width='100%'>";
    html += "<tr><th>ID</th><th>Type</th><th>Price</th><th>Quantity</th><th>Area</th><th>Date Issue</th><th>Date Event</th></tr>";

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

void MainWindow::on_stat_clicked()
{
    dialog_window = new Dialog(this);
    dialog_window->setAttribute(Qt::WA_DeleteOnClose); // Ensure memory cleanup
    dialog_window->show();
}


void MainWindow::on_generate_clicked()
{
    generate_tickets_window = new generate_tickets(this); // Ensure class name is correct
    generate_tickets_window->show();

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
    ui->table->setStyleSheet(darkTableStyle);
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
    ui->generate->setStyleSheet(buttonStyle);
    ui->stat->setStyleSheet(buttonStyle);
    ui->delete_2->setStyleSheet("#delete_2{border-radius: 10px;background: transparent;}");
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
    ui->table->setStyleSheet("#table{background:rgba(33, 133, 85, 0.4);border-radius: 10px;padding: 5px;}");
    ui->form->setStyleSheet("#form{background:rgba(214, 215, 222, 0.4);border-radius: 10px;padding: 5px;}");
    ui->menu->setStyleSheet("#menu{background-color:#218555;border-radius: 10px;padding: 5px;}");
    ui->add->setStyleSheet("#add{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->cancel->setStyleSheet("#cancel{border-radius: 10px;background: transparent;}");
    ui->modify->setStyleSheet("#modify{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->generate->setStyleSheet("#generate{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->stat->setStyleSheet("#stat{border-radius: 10px;padding: 5px;background: #218555; }");
    ui->delete_2->setStyleSheet("#delete_2{border-radius: 10px;background: transparent;}");
    ui->dark->setStyleSheet("#dark{background-color: #333;color: white;border: 2px solid #555;border-radius: 10px;padding: 5px 10px; }#dark:hover {background-color: #444;border: 2px solid #777;}#dark:pressed {background-color: #222;border: 2px solid #999;}");
    ui->light->setStyleSheet("#light {background-color:transparent;color: #333; border: 2px solid #ccc;border-radius: 10px;padding: 5px 10px; }#light:hover {background-color: #e0e0e0;border: 2px solid #bbb;}#light:pressed {background-color: #d0d0d0; border: 2px solid #999;}");
    ui->bg->setStyleSheet("#bg{background-image: url(:/image/img/bg.jpeg);}");

}


