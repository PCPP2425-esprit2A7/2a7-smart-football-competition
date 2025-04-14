// ReclamationWindow.cpp
#include "reclamationwindow.h"
#include "ui_reclamationwindow.h"
#include <QMessageBox>

ReclamationWindow::ReclamationWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReclamationWindow)
{
    ui->setupUi(this);
}

ReclamationWindow::~ReclamationWindow()
{
    delete ui;
}

void ReclamationWindow::on_pushButton_submitReclamation_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString email = ui->lineEdit_email->text();
    QString reason = ui->textEdit_sreason->toPlainText();

    if (name.isEmpty() || email.isEmpty() || reason.isEmpty()) {
        QMessageBox::warning(this,  "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    emit reclamationSubmitted(name, email, reason);

    accept();
}
