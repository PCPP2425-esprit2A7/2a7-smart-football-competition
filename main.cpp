#include "mainwindow_supporteur.h"
#include "mainwindow_billet.h"

#include "connection.h"
#include <QMessageBox>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    if (c.createconnect())
    {
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful.\n"
                                             "Click OK to continue."), QMessageBox::Ok);

        MainWindowBillet w;
        w.show();

        return a.exec();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection"),
                              QObject::tr("Connection failed.\n"
                                          "Click OK to exit."), QMessageBox::Ok);
        return -1;
    }
}
