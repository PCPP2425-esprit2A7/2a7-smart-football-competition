#ifndef DIALOG_SUPPORTEUR_H
#define DIALOG_SUPPORTEUR_H

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
    void displayStatisticsByGrade();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_SUPPORTEUR_H
