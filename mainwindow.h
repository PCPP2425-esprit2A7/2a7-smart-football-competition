#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "equipe.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
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

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
