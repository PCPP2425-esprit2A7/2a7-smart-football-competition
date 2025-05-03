#include "mainwindow_match.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "connection.h"
#include <QDebug>
#include "superviser.h"


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
        Superviser S;
        // w.resize(400, 300); // Taille minimale garanties
       // btnSuperviser->show();
      //  container->show();
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

