#include "superviser.h"
#include "ui_superviser.h"
#include <QMessageBox>
#include <QThread>
Superviser::Superviser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Superviser)
{
   // ui->setupUi(this);

    int connectionStatus = arduino.connect_arduino();
    if (connectionStatus != 0) {
        showError(connectionStatus == 1 ?
                      "Arduino détecté mais non connecté" :
                      "Aucun Arduino détecté");
    } else {
        // Add a small delay after successful connection
        QThread::msleep(2000);
    }

    connect(arduino.getserial(), &QSerialPort::readyRead,
            this, &Superviser::readSerialData);
}

bool Superviser::checkArduinoConnection()
{
    return arduino.getserial()->isOpen();
}

void Superviser::on_pushButton_envoyer_clicked()
{
    if (!checkArduinoConnection()) {
        showError("Arduino non connecté!");
        return;
    }

    QString data = QString("%1,%2:%3\n")
                       .arg(ui->team1->text())
                       .arg(ui->team2->text())
                       .arg(ui->lineEdit_score->text());

    arduino.write_to_arduino(data.toUtf8());
}
void Superviser::readSerialData()
{
    QByteArray data = arduino.read_from_arduino();
    qDebug() << "Reçu de l'Arduino:" << data;
}

void Superviser::showError(const QString &message)
{
    QMessageBox::critical(this, "Erreur", message);
    qDebug() << "Erreur:" << message;
}

Superviser::~Superviser()
{
    if (arduino.getserial()->isOpen()) {
        arduino.close_arduino();
    }
    delete ui;
}
