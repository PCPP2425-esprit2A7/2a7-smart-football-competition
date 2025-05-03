#ifndef DIALOG_ARBITRE_H
#define DIALOG_ARBITRE_H

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

#endif // DIALOG_ARBITRE_H
