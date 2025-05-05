#ifndef DIALOG_ARBITRE_H
#define DIALOG_ARBITRE_H

#include <QDialog>

namespace Ui {
class DialogArbitre;
}

class DialogArbitre : public QDialog
{
    Q_OBJECT

public:
    explicit DialogArbitre(QWidget *parent = nullptr);
    ~DialogArbitre();
    void stat();

private:
    Ui::DialogArbitre *ui;
};

#endif // DIALOG_ARBITRE_H
