#ifndef WELCOM_PAGE_H
#define WELCOM_PAGE_H

#include <QWidget>

namespace Ui {
class welcom_page;
}

class welcom_page : public QWidget
{
    Q_OBJECT

public:
    explicit welcom_page(QWidget *parent = nullptr);
    ~welcom_page();

private slots:
    void on_supporteur_clicked();

    void on_joueur_clicked();

   // void on_equipe_clicked();

    void on_arbitre_clicked();

    void on_match_clicked();

    void on_billet_clicked();

    void on_equipe_clicked();

private:
    Ui::welcom_page *ui;
};

#endif // WELCOM_PAGE_H
