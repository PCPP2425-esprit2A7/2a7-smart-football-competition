#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include "dialog_billet.h"
#include"dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
class generate_tickets;
class Dialog;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    generate_tickets *generate_tickets_window;
    Dialog *dialog_window;

};
#endif // MAINWINDOW_H
