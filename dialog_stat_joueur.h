#ifndef DIALOG_STAT_JOUEUR_H
#define DIALOG_STAT_JOUEUR_H

#include <QDialog>

namespace Ui {
class DialogJoueur;
}

class DialogJoueur : public QDialog
{
    Q_OBJECT

public:
    explicit DialogJoueur(QWidget *parent = nullptr);
    ~DialogJoueur();
    void stat();

private:
    Ui::DialogJoueur *ui;
};

#endif // DIALOG_STAT_JOUEUR_H
