#include "gestion_billet.h"
#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    if (c.createconnect()) // Only create Gbillet if the connection is successful
    {
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful.\n"
                                             "Click OK to continue."), QMessageBox::Ok);

        MainWindow w; // Create main window after confirming the connection
        w.show();

        return a.exec(); // Start event loop
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed.\n"
                                          "Click OK to exit."), QMessageBox::Ok);
        return -1; // Exit the application
    }
}
