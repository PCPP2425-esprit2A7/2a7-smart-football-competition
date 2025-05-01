#ifndef ARDUINO_H
#define ARDUINO_H

#include <QObject>
#include <QSerialPort>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

class arduino
{

public:
    arduino();
    int connect_arduino();
    int close_arduino();
    void write_to_arduino(QByteArray);
    QByteArray read_from_arduino();
    QSerialPort* getserial();
    QString getarduino_port_name();
    void write_to_arduino(const QString &command);
    QByteArray get_data() const; // Ajouter un accesseur pour récupérer "data"

private:
    QSerialPort *serial;
    QSerialPort arduino_serial;    // <- AJOUTER CETTE LIGNE
    QString arduino_port_name;
    bool arduino_is_avaible;
    static const quint16 arduino_uno_vendor_id = 9025; // exemple
    static const quint16 arduino_uno_product_id = 67;  // exemple
    QByteArray data;
};

#endif // ARDUINO_H
