#include "arduino.h"
#include <QSerialPortInfo>
#include <QDebug>

const quint16 arduino_uno_vendor_id = 0x2341;  // Vendor ID
const quint16 arduino_uno_product_id = 0x0043; // Product ID

// Constructeur
arduino::arduino()
{
    serial = new QSerialPort; // <- création de l’objet
    arduino_is_avaible = false;
    arduino_port_name = "COM4";
}

// Connexion à l'Arduino
// int arduino::connect_arduino() {
//     foreach(const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
//         if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
//             if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
//                 serial_port_info.productIdentifier() == arduino_uno_product_id) {
//                 arduino_port_name = serial_port_info.portName();
//                 arduino_is_avaible = true;
//             }
//         }
//     }

//     qDebug() << "arduino_port_name is :" << arduino_port_name;

//     if (arduino_is_avaible) {
//         arduino_serial.setPortName(arduino_port_name);
//         arduino_serial.setBaudRate(QSerialPort::Baud9600);
//         arduino_serial.setDataBits(QSerialPort::Data8);
//         arduino_serial.setParity(QSerialPort::NoParity);
//         arduino_serial.setStopBits(QSerialPort::OneStop);
//         arduino_serial.setFlowControl(QSerialPort::NoFlowControl);

//         if (arduino_serial.open(QSerialPort::ReadWrite)) {
//             qDebug() << "Connexion série réussie !";
//             return 1;
//         } else {
//             qDebug() << "Erreur ouverture port série.";
//         }
//     }

//     return 0;

//     return -1; // Arduino non détecté
// }
int arduino::connect_arduino() {
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_product_id) {
                arduino_port_name = serial_port_info.portName();
                arduino_is_avaible = true;
                break; // dès qu'on trouve, on s'arrête
            }
        }
    }

    qDebug() << "arduino_port_name is :" << arduino_port_name;

    if (arduino_is_avaible) {
        arduino_serial.setPortName(arduino_port_name);
        arduino_serial.setBaudRate(QSerialPort::Baud9600);
        arduino_serial.setDataBits(QSerialPort::Data8);
        arduino_serial.setParity(QSerialPort::NoParity);
        arduino_serial.setStopBits(QSerialPort::OneStop);
        arduino_serial.setFlowControl(QSerialPort::NoFlowControl);

        if (arduino_serial.open(QIODevice::ReadWrite)) {
            qDebug() << "Connexion série réussie !";
            return 0; // 0 = OK
        } else {
            qDebug() << "Erreur ouverture port série.";
            return 1; // 1 = trouvé mais pas connecté
        }
    }

    return -1; // -1 = pas trouvé
}


// Fermeture de la connexion
int arduino::close_arduino() {
    if (serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
}

// Lire depuis l'Arduino
QByteArray arduino::read_from_arduino()
{
    QByteArray data;
    if (serial->isOpen() && serial->bytesAvailable() > 0) {
        data = serial->readAll();
    }
    return data;
}



// Écrire vers l'Arduino
void arduino::write_to_arduino(QByteArray d) {
    if (serial->isWritable()) {
        serial->write(d);
    } else {
        qDebug() << "couldn't write to serial!";
    }
}

// Obtenir le port série
QSerialPort* arduino::getserial() {
    return serial;
}

// Obtenir le nom du port
QString arduino::getarduino_port_name() {
    return arduino_port_name;
}
