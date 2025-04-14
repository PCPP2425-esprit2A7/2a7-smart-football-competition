#ifndef DIALOG_BILLET_H
#define DIALOG_BILLET_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QTableView>

namespace Ui {
class generate_tickets;
}

class generate_tickets : public QDialog
{
    Q_OBJECT

public:
    explicit generate_tickets(QWidget *parent = nullptr);
    ~generate_tickets();
    void afficher_s();
    void afficher_m();
    void afficher_b();

private slots:
    void on_table_s_clicked(const QModelIndex &index);

    void on_table_m_clicked(const QModelIndex &index);

    void on_table_b_clicked(const QModelIndex &index);

    void on_generate_qr_clicked();

    void on_delete_qr_clicked();

    void on_save_clicked();

    void on_delete_ticket_clicked();

private:
    Ui::generate_tickets *ui;
    QImage generateQRCode(const QString &id, const QString &date_issue, const QString &place);
};

#endif // DIALOG_BILLET_H
