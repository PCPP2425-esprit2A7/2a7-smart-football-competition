#ifndef DIALOG_STAT_JOUEUR_H
#define DIALOG_STAT_JOUEUR_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void stat();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_STAT_JOUEUR_H
