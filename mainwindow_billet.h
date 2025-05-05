#ifndef MAINWINDOW_BILLET_H
#define MAINWINDOW_BILLET_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include "dialog_billet.h"
#include"dialog_stat_billet.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowBillet;
}
class generate_tickets;
class DialogStat;
class arduino;

QT_END_NAMESPACE

class MainWindowBillet : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowBillet(QWidget *parent = nullptr);
    ~MainWindowBillet();

public slots:
    void readSerial();
    void verifierUID(const QString& uid);

private slots:
    void on_add_clicked();
    void afficher();
    void on_modify_clicked();
    void on_delete_2_clicked();
    void on_cancel_clicked();
    void on_table_clicked(const QModelIndex &index);
    void on_tri_activated(int index);
    void on_pdf_clicked();
    void on_stat_clicked();

    void on_generate_clicked();

    void on_dark_clicked();

    void on_light_clicked();
    //void on_btn_supporteur_clicked();

    void on_btn_supporteur_clicked();

    void on_btn_arbitre_clicked();

    void on_btn_joueur_clicked();

    void on_btn_match_clicked();

    void on_home_clicked();

    void on_btn_equipe_clicked();

private:
    Ui::MainWindowBillet *ui;
    generate_tickets *generate_tickets_window;
    DialogStat *dialog_window;
    QSerialPort *serial;
    QByteArray data;
    arduino *A;

};
#endif // MAINWINDOW_BILLET_H
