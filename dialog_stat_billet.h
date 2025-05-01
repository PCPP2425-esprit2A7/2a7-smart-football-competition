#ifndef DIALOG_STAT_BILLET_H
#define DIALOG_STAT_BILLET_H

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
    void displayStatistics();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_STAT_BILLET_H
