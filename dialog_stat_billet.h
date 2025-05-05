#ifndef DIALOG_STAT_BILLET_H
#define DIALOG_STAT_BILLET_H

#include <QDialog>

namespace Ui {
class DialogStat;
}

class DialogStat : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStat(QWidget *parent = nullptr);
    ~DialogStat();
    void displayStatistics();
private:
    Ui::DialogStat  *ui;
};

#endif // DIALOG_STAT_BILLET_H
