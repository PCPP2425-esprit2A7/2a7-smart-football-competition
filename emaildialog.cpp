#include "emaildialog.h"
#include "ui_emaildialog.h"
#include <QProcess>
#include <QMessageBox>

EmailDialog::EmailDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmailDialog)
{
    ui->setupUi(this);
    ui->dateEdit_dateMatch->setDate(QDate::currentDate());

    connect(ui->btn_annuler, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->btn_envoyer, &QPushButton::clicked, this, &EmailDialog::onEnvoyerClicked);
}

EmailDialog::~EmailDialog()
{
    delete ui;
}

void EmailDialog::onEnvoyerClicked()
{
    QString email = ui->lineEdit_email->text().trimmed();
    QString date = ui->dateEdit_dateMatch->date().toString("dd/MM/yyyy");
    QString message = ui->textEdit_message->toPlainText();


    if (email.isEmpty() || message.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir l'email et le message.");
        return;
    }

    QString contenu = message + "\n\nDate du match : " + date;
    envoyerEmail(email, "Notification de match", contenu);

    QMessageBox::information(this, "Succès", "Email envoyé à " + email);
    this->accept();
}

void EmailDialog::envoyerEmail(QString email, QString sujet, QString message)
{
    QString program = "C:/Users/Hammami Yessmie/AppData/Local/Programs/Python/Python313/python.exe";
    // Remplace ce chemin par celui où Python est installé
      // ou "python" selon ton système
    QString scriptPath = "C:/Users/Hammami Yessmie/Downloads/Atelier_Connexion (2)/Atelier_Connexion/send_email.py";

    QStringList arguments;
    arguments << scriptPath << email << sujet << message;

    // Debug pour vérifier que les bons arguments sont passés
    qDebug() << "Arguments passés au script Python : " << arguments;

    QProcess process;
    process.start(program, arguments);
    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    QString errors = process.readAllStandardError();
    qDebug() << "Email envoyé à :" << email;
    qDebug() << "Sortie standard : " << output;
    qDebug() << "Erreur standard : " << errors;

}
