#ifndef SUPERVISER_H
#define SUPERVISER_H

#include <QWidget>
#include "arduino.h"

namespace Ui {
class Superviser;
}

class Superviser : public QWidget
{
    Q_OBJECT

public:
    explicit Superviser(QWidget *parent = nullptr);
    ~Superviser();
    bool checkArduinoConnection();

private slots:
    void on_pushButton_envoyer_clicked();
    void readSerialData();

private:
    Ui::Superviser *ui;
    arduino arduino;
    void showError(const QString &message);
};

#endif // SUPERVISER_H
