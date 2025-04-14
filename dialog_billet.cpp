#include "dialog_billet.h"
#include "ui_dialog_billet.h"
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlError>
#include<QString>
#include <QImage>
#include<QPainter>
#include <QLabel>
#include"qrcodegen.hpp"
#include <QMessageBox>
#include <QSqlQuery>
#include <QBuffer>
generate_tickets::generate_tickets(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::generate_tickets)
{
    ui->setupUi(this);
    afficher_s();
    afficher_m();
    afficher_b();
}

generate_tickets::~generate_tickets()
{
    delete ui;
}
void generate_tickets::afficher_s() {
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve supporter data
    model->setQuery("SELECT ID, NAME, LAST_NAME FROM SUPPORTEUR");

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("First Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last Name"));

    // Assign the model to the QTableView
    ui->table_s->setModel(model);

    // Make the table fill the available space
    ui->table_s->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_s->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_s->horizontalHeader()->setStretchLastSection(true);

    // Improve selection behavior
    ui->table_s->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_s->setSelectionMode(QAbstractItemView::SingleSelection); // Allow selecting only one row

    // Disable editing to prevent accidental modifications
    ui->table_s->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void generate_tickets::afficher_m() {
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve match data
    model->setQuery("SELECT DATE_TIME, PLACE, TEAM1, TEAM2 FROM MATCH");

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("DATE & TIME"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PLACE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEAM 1"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEAM 2"));

    // Assign the model to the QTableView
    ui->table_m->setModel(model);

    // Make the table fill the available space
    ui->table_m->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_m->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_m->horizontalHeader()->setStretchLastSection(true);

    // Improve selection behavior
    ui->table_m->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_m->setSelectionMode(QAbstractItemView::SingleSelection); // Allow selecting only one row

    // Disable editing to prevent accidental changes
    ui->table_m->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void generate_tickets::afficher_b() {
    // Create a new QSqlQueryModel
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to retrieve ticket data
    model->setQuery("SELECT id, type, price, area, date_issue FROM BILLET");

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Price"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Area"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Issue"));

    // Assign the model to the QTableView
    ui->table_b->setModel(model);

    // Make the table fill the available space
    ui->table_b->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->table_b->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->table_b->horizontalHeader()->setStretchLastSection(true);
    ui->table_b->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->table_b->setEditTriggers(QAbstractItemView::NoEditTriggers); // Disable editing
    ui->table_b->setSelectionMode(QAbstractItemView::SingleSelection); // Allow selecting only one row
}

void generate_tickets::on_table_s_clicked(const QModelIndex &index)
{
    // Get the row number of the clicked cell
    int row = index.row();

    // Extract values from the selected row (assuming columns: ID, NAME, LAST_NAME)
    QString name = ui->table_s->model()->data(ui->table_s->model()->index(row, 1)).toString(); // Column 1: Name
    QString last_name = ui->table_s->model()->data(ui->table_s->model()->index(row, 2)).toString(); // Column 2: Last Name

    // Set values to UI fields
    ui->name->setText(name);
    ui->last_name->setText(last_name);
}


void generate_tickets::on_table_m_clicked(const QModelIndex &index)
{
    // Get the row number of the clicked cell
    int row = index.row();

    // Extract values from the selected row (assuming columns: ID, NAME, LAST_NAME)
    QString place = ui->table_m->model()->data(ui->table_m->model()->index(row, 1)).toString(); // Column 1: date_m
    QString date_m = ui->table_m->model()->data(ui->table_m->model()->index(row, 0)).toString(); // Column 2: place
    QString Team1 = ui->table_m->model()->data(ui->table_m->model()->index(row, 2)).toString(); // Column 0 is ID
    QString Team2 = ui->table_m->model()->data(ui->table_m->model()->index(row, 3)).toString(); // Column 0 is ID


    // Set values to UI fields
    ui->place->setText(place);
    ui->date_m->setText(date_m);
    ui->t1->setText(Team1);
    ui->t2->setText(Team2);
}


void generate_tickets::on_table_b_clicked(const QModelIndex &index)
{
    // Get the row number of the clicked cell
    int row = index.row();

    // Assuming your table has columns: ID, Type, Price, Quantity, Area, Date Issue, Date Event
    int id = ui->table_b->model()->data(ui->table_b->model()->index(row, 0)).toInt(); // Column 0 is ID
    QString date_issue = ui->table_b->model()->data(ui->table_b->model()->index(row, 4)).toString(); //colmun 4 is date_issue
    int price =  ui->table_b->model()->data(ui->table_b->model()->index(row, 2)).toInt(); //colmun 4 is date_issue
    QString area = ui->table_b->model()->data(ui->table_b->model()->index(row, 3)).toString(); //colmun 4 is date_issue

    // Set the values to the form
    ui->id_qr->setText(QString::number(id));
    ui->date_issue->setText(date_issue);
    ui->price->setText("$" + QString::number(price));
    ui->area->setText("Area : "+area);
}

QImage generate_tickets::generateQRCode(const QString &id, const QString &date_issue, const QString &place) {
    // Combine data into a single string
    QString data = "Id :" +id + "," + "Date :" + date_issue + "," + "Place :" + place;

    // Generate QR Code
    qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(data.toUtf8().constData(), qrcodegen::QrCode::Ecc::LOW);
    int size = qr.getSize();

    if (size <= 0) {
        qDebug() << "Error: Failed to generate QR code!";
        return QImage();
    }

    // Define pixel size for better rendering
    const int pixelSize = 8;
    QImage qrImage(size * pixelSize, size * pixelSize, QImage::Format_RGB32);
    qrImage.fill(Qt::white);

    // Draw the QR Code
    QPainter painter(&qrImage);
    painter.setRenderHint(QPainter::Antialiasing);

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (qr.getModule(x, y)) {
                painter.fillRect(x * pixelSize, y * pixelSize, pixelSize, pixelSize, Qt::black);
            }
        }
    }

    return qrImage;
}
void generate_tickets::on_generate_qr_clicked()
{
    QString id = ui->id_qr->text();
    QString date_issue = ui->date_issue->text();
    QString place = ui->place->text();

    // Check if any field is empty
    if (id.isEmpty() || date_issue.isEmpty() || place.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields must be filled before generating the QR code.");
        return;
    }
    // Generate QR code image
    QImage qrImage = generateQRCode(id, date_issue, place);

    if (!qrImage.isNull()) {
        ui->qr_label->setPixmap(QPixmap::fromImage(qrImage).scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    } else {
        qDebug() << "QR Code generation failed!";
    }
}

void generate_tickets::on_delete_qr_clicked()
{

    // Reset the form fields to their initial state
    ui->id_qr->clear();  // Clear the ID field
    ui->date_issue->clear();  // Reset the type combo box to the first index
    ui->place->clear();  // Clear the price field

    // Log a debug message (optional)
    qDebug() << "Form has been reset.";
}



void generate_tickets::on_save_clicked() {
    // Get the ticket ID from the label
    int selectedTicketId = ui->id_qr->text().toInt();

    // Check if the ID is valid
    if (selectedTicketId <= 0) {
        QMessageBox::warning(this, "Warning", "Invalid ticket ID. Please select a valid ticket.");
        return;
    }

    // Debugging: Check the ticket ID
    qDebug() << "Selected ticket ID: " << selectedTicketId;

    // Convert QWidget (ticket) to an image
    QPixmap pixmap(ui->ticket->size());
    ui->ticket->render(&pixmap);

    // Convert the pixmap to a QByteArray
    QByteArray byteArray;
    QBuffer buffer(&byteArray);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");

    // Update the ticket image in the database
    QSqlQuery query;
    query.prepare("UPDATE BILLET SET TICKETS = :blob WHERE ID = :id");
    query.bindValue(":blob", byteArray);
    query.bindValue(":id", selectedTicketId);

    // Debugging: Log the query and check if the database is open
    qDebug() << "Executing query: " << query.lastQuery();
    if (!query.exec()) {
        qDebug() << "Query failed: " << query.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to save ticket: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "Success", "Ticket image saved successfully!");
    }
}

void generate_tickets::on_delete_ticket_clicked()
{
    // Reset the form fields to their initial state
    ui->name->clear();
    ui->last_name->clear();
    ui->price->clear();
    ui->area->clear();
    ui->date_m->clear();
    ui->qr_label->clear();
    ui->t1->clear();
    ui->t2->clear();

    // Log a debug message (optional)
    qDebug() << "Form has been reset.";
}

