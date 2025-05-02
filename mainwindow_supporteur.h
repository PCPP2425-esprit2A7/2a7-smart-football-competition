#ifndef MAINWINDOW_SUPPORTEUR_H
#define MAINWINDOW_SUPPORTEUR_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include "dialog_supporteur.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowSupporteur;
}
class Dialog;
class arduino;
QT_END_NAMESPACE

class MainWindowSupporteur : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowSupporteur(QWidget *parent = nullptr);
    ~MainWindowSupporteur();

private slots:
    void on_add_clicked();
    void afficher();
    void on_modify_clicked();
    void on_delete_2_clicked();
    // void update_label();  // ✅ Uniquement ici
    // void on_pushButton_clicked();
    // void on_pushButton_2_clicked();

    //void update_arduino_status();

    void on_tableView_clicked(const QModelIndex &index);
    void on_pdf_clicked();
    void on_tri_activated(int index);
    void on_stat_clicked();


    void on_dark_ilyes_clicked();

    void on_light_ilyes_clicked();


    void on_btn_billet_fromsup_clicked();

private:
    Ui::MainWindowSupporteur *ui;
    Dialog *dialog_window;
    QByteArray data;
    arduino A;
    QSerialPort *serial;
};

#endif // MAINWINDOW_SUPPORTEUR_H
