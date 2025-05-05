#ifndef DIALOG_SUPPORTEUR_H
#define DIALOG_SUPPORTEUR_H

#include <QDialog>

namespace Ui {
class DialogSupporteur;
}

class DialogSupporteur : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSupporteur(QWidget *parent = nullptr);
    ~DialogSupporteur();
    void displayStatisticsByGrade();

private:
    Ui::DialogSupporteur *ui;
};

#endif // DIALOG_SUPPORTEUR_H
