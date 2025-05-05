#include "mainwindow_supporteur.h"
#include "mainwindow_arbitre.h"
#include "mainwindow_billet.h"
#include "mainwindow_match.h"
#include "mainwindow_joueur.h"
#include "mainwindow_equipe.h"
#include "welcom_page.h"

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

        welcom_page w;
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
