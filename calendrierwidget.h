// calendrierwidget.h
#ifndef CALENDRIERWIDGET_H
#define CALENDRIERWIDGET_H

#include <QWidget>
#include <QMap>
#include <QDate>
#include <QRect>
#include <QRectF>

class QTableView;
class QStandardItemModel;
class QCalendarWidget;
class QComboBox;

class CalendrierWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendrierWidget(QWidget *parent = nullptr);
    void chargerMatchs();
    void setReminderForSelectedMatch();
    void exportToPDF();

    //void onSelectionChanged();
protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onMonthChanged(int year, int month);

    void showReminderNotification(int matchId);
    void loadSavedReminders();
    void onSelectionChanged();

private:
    void setupUI();
    void creerModel();
    void afficherMatchsDuMois();
    void afficherDetailsMatch(const QDate &date);

    QCalendarWidget *calendar;
    QTableView *tableView;
    QStandardItemModel *matchModel;
    QComboBox *teamFilterCombo;

    QMap<QDate, QList<QString>> matchsParDate; // Stocke les matchs groupés par date
    QMap<int, QString> equipes; // Stocke les équipes (id, nom)
};

#endif // CALENDRIERWIDGET_H
