#ifndef HISTORIQUEDIALOG_H
#define HISTORIQUEDIALOG_H
#include "ui_historiqueDialog.h"

#include <QDialog>

namespace Ui {
class HistoriqueDialog;
}

class HistoriqueDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoriqueDialog(QWidget *parent = nullptr);
    ~HistoriqueDialog();
    void afficherHistorique();

private:
    Ui::HistoriqueDialog *ui;
};


#endif // HISTORIQUEDIALOG_H
