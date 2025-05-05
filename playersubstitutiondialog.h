#ifndef playersubstitutiondialog_H
#define playersubstitutiondialog_H

#include <QDialog>
#include "ui_playersubstitutiondialog.h"  // <-- Ajoute cette ligne !!

class playersubstitutiondialog : public QDialog
{
    Q_OBJECT

public:
    explicit playersubstitutiondialog(int team, QWidget *parent = nullptr);
    ~playersubstitutiondialog();

    QString getFirstSelectedPlayer() const;
    QString getSecondSelectedPlayer() const;

private:
    Ui::playersubstitutiondialog *ui;
    int team;
    void loadPlayers();
};

#endif // playersubstitutiondialog_H
