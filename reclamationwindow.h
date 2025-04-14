#ifndef RECLAMATIONWINDOW_H
#define RECLAMATIONWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class ReclamationWindow;
}

class ReclamationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ReclamationWindow(QWidget *parent = nullptr);
    ~ReclamationWindow();

signals:
    void reclamationSubmitted(const QString& name, const QString& email, const QString& reason);

private slots:
    void on_pushButton_submitReclamation_clicked();

private:
    Ui::ReclamationWindow *ui;
};

#endif // RECLAMATIONWINDOW_H
