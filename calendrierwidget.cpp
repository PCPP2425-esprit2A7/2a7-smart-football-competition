#include "calendrierwidget.h"
#include <QSqlQuery>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCalendarWidget>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QPainter>
#include <QSqlError>
#include <QMessageBox>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QPrinter>
#include <QTextCharFormat>
#include <QSplitter>
#include <QFileDialog>
#include <QStandardPaths>
#include <QSystemTrayIcon>
#include <QSettings>
#include <QTimer>

CalendrierWidget::CalendrierWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();
    creerModel();
    chargerMatchs();
    loadSavedReminders();
}

void CalendrierWidget::setupUI()
{
    // Layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Filtres
    QHBoxLayout *filterLayout = new QHBoxLayout();
    teamFilterCombo = new QComboBox(this);
    teamFilterCombo->addItem("Toutes les équipes", 0);
    filterLayout->addWidget(new QLabel("Filtrer par équipe:"));
    filterLayout->addWidget(teamFilterCombo);

    QPushButton *refreshBtn = new QPushButton("Actualiser", this);
    filterLayout->addWidget(refreshBtn);
    filterLayout->addStretch();

    // Boutons d'action
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    QPushButton *reminderBtn = new QPushButton(tr("Programmer un rappel"), this);
    QPushButton *exportBtn = new QPushButton(tr("Exporter en PDF"), this);
    buttonLayout->addWidget(reminderBtn);
    buttonLayout->addWidget(exportBtn);
    buttonLayout->addStretch();

    // Calendrier et tableau
    calendar = new QCalendarWidget(this);
    tableView = new QTableView(this);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    // Splitter
    QSplitter *splitter = new QSplitter(Qt::Vertical, this);
    splitter->addWidget(calendar);
    splitter->addWidget(tableView);

    // Assemblage
    mainLayout->addLayout(filterLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(splitter);

    // Connexions
    connect(calendar, &QCalendarWidget::currentPageChanged, this, &CalendrierWidget::onMonthChanged);
    connect(calendar, &QCalendarWidget::selectionChanged, this, &CalendrierWidget::onSelectionChanged);
    connect(refreshBtn, &QPushButton::clicked, this, &CalendrierWidget::chargerMatchs);
    connect(teamFilterCombo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CalendrierWidget::chargerMatchs);
    connect(reminderBtn, &QPushButton::clicked, this, &CalendrierWidget::setReminderForSelectedMatch);
    connect(exportBtn, &QPushButton::clicked, this, &CalendrierWidget::exportToPDF);

    // Style
    calendar->setStyleSheet(R"(
        QCalendarWidget {
            background-color: white;
            border: 1px solid #d3d3d3;
            border-radius: 5px;
        }
        QCalendarWidget QToolButton {
            height: 30px;
            font-size: 14px;
            color: #333;
            background-color: #f8f8f8;
            border-radius: 3px;
        }
        QCalendarWidget QToolButton:hover {
            background-color: #e0e0e0;
        }
        QCalendarWidget QMenu {
            width: 200px;
            background-color: white;
            border: 1px solid #d3d3d3;
        }
    )");
}

void CalendrierWidget::creerModel()
{
    matchModel = new QStandardItemModel(0, 4, this);
    matchModel->setHeaderData(0, Qt::Horizontal, tr("Heure"));
    matchModel->setHeaderData(1, Qt::Horizontal, tr("Lieu"));
    matchModel->setHeaderData(2, Qt::Horizontal, tr("Score"));
    matchModel->setHeaderData(3, Qt::Horizontal, tr("ID")); // Colonne cachée pour l'ID
    tableView->setModel(matchModel);
    tableView->setColumnHidden(3, true); // Cacher la colonne ID
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void CalendrierWidget::chargerMatchs()
{
    matchModel->removeRows(0, matchModel->rowCount());
    matchsParDate.clear();
    //teamFilterCombo->clear();
    // teamFilterCombo->addItem("Toutes les équipes", 0);

    // Charger les équipes
    QSqlQuery teamQuery("SELECT ID, NOM FROM EQUIPE");
    while (teamQuery.next()) {
        equipes[teamQuery.value(0).toInt()] = teamQuery.value(1).toString();
        teamFilterCombo->addItem(teamQuery.value(1).toString(), teamQuery.value(0).toInt());
    }

    // Requête pour les matchs
    QString queryStr = "SELECT ID, DATE_TIME, PLACE, SCORE FROM MATCH";
    int teamFilter = teamFilterCombo->currentData().toInt();

    if (teamFilter > 0) {
        queryStr += " WHERE TEAM1 = :teamId OR TEAM2 = :teamId";
    }
    queryStr += " ORDER BY DATE_TIME";

    QSqlQuery query;
    query.prepare(queryStr);
    if (teamFilter > 0) {
        query.bindValue(":teamId", teamFilter);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement des matchs: " + query.lastError().text());
        return;
    }

    while (query.next()) {
        QDateTime dateTime = query.value(1).toDateTime();
        QDate date = dateTime.date();
        QString place = query.value(2).toString();
        QString score = query.value(3).toString();
        int matchId = query.value(0).toInt();

        // Ajouter au modèle
        QList<QStandardItem*> items;
        items << new QStandardItem(dateTime.toString("HH:mm"));
        items << new QStandardItem(place);
        items << new QStandardItem(score);
        items << new QStandardItem(QString::number(matchId));
        matchModel->appendRow(items);

        // Ajouter à la structure par date
        matchsParDate[date].append(QString("%1 - %2 - %3").arg(dateTime.toString("HH:mm"), place, score));
    }

    onMonthChanged(calendar->yearShown(), calendar->monthShown());
}

void CalendrierWidget::onMonthChanged(int year, int month)
{
    QDate firstDay(year, month, 1);
    QDate lastDay = firstDay.addMonths(1).addDays(-1);

    // Format pour les jours avec matchs (rouge)
    QTextCharFormat matchFormat;
    matchFormat.setBackground(QColor(255, 200, 200));
    matchFormat.setFontWeight(QFont::Bold);

    calendar->setDateTextFormat(QDate(), QTextCharFormat()); // Réinitialiser

    for (auto it = matchsParDate.constBegin(); it != matchsParDate.constEnd(); ++it) {
        if (it.key() >= firstDay && it.key() <= lastDay && !it.value().isEmpty()) {
            calendar->setDateTextFormat(it.key(), matchFormat);
        }
    }

    afficherMatchsDuMois();
}

void CalendrierWidget::afficherMatchsDuMois()
{
    QDate firstDay(calendar->yearShown(), calendar->monthShown(), 1);
    QDate lastDay = firstDay.addMonths(1).addDays(-1);

    for (int row = 0; row < matchModel->rowCount(); ++row) {
        QDateTime dt = QDateTime::fromString(matchModel->data(matchModel->index(row, 0)).toString(), "HH:mm");
        QDate date = calendar->selectedDate();
        tableView->setRowHidden(row, !(dt.date() >= firstDay && dt.date() <= lastDay));
    }
}
void CalendrierWidget::setReminderForSelectedMatch()
{
    QModelIndexList selected = tableView->selectionModel()->selectedRows();
    if (selected.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un match dans le tableau");
        return;
    }

    int row = selected.first().row();
    int matchId = matchModel->data(matchModel->index(row, 3)).toInt();
    QString timeStr = matchModel->data(matchModel->index(row, 0)).toString();
    QString place = matchModel->data(matchModel->index(row, 1)).toString();

    QDateTime matchTime(calendar->selectedDate(), QTime::fromString(timeStr, "HH:mm"));
    QDateTime reminderTime = matchTime.addSecs(-3600); // 1h avant

    // Stocker le rappel
    QSettings settings;
    settings.beginGroup("MatchReminders");
    settings.setValue(QString::number(matchId), reminderTime);
    settings.endGroup();

    // Programmer le rappel
    int secondsToReminder = QDateTime::currentDateTime().secsTo(reminderTime);
    if (secondsToReminder > 0) {
        QTimer::singleShot(secondsToReminder * 1000, [this, matchId]() {
            QSqlQuery query;
            query.prepare("SELECT DATE_TIME, PLACE FROM MATCH WHERE ID = ?");
            query.addBindValue(matchId);
            if (query.exec() && query.next()) {
                QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
                trayIcon->showMessage(
                    "Rappel Match",
                    QString("Match à %1\nLieu: %2")
                        .arg(query.value(0).toDateTime().toString("HH:mm"))
                        .arg(query.value(1).toString()),
                    QSystemTrayIcon::Information,
                    10000
                    );
            }
        });
    }

    QMessageBox::information(this, "Rappel programmé",
                             QString("Rappel pour le match à %1\nProgrammé pour %2")
                                 .arg(timeStr)
                                 .arg(reminderTime.toString("dd/MM/yyyy HH:mm")));
}

void CalendrierWidget::loadSavedReminders()
{
    QSettings settings;
    settings.beginGroup("MatchReminders");

    foreach (const QString &key, settings.allKeys()) {
        int matchId = key.toInt();
        QDateTime reminderTime = settings.value(key).toDateTime();
        int seconds = QDateTime::currentDateTime().secsTo(reminderTime);

        if (seconds > 0) {
            QTimer::singleShot(seconds * 1000, [this, matchId]() {
                QSqlQuery query;
                query.prepare("SELECT DATE_TIME, PLACE FROM MATCH WHERE ID = ?");
                query.addBindValue(matchId);
                if (query.exec() && query.next()) {
                    QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
                    trayIcon->showMessage(
                        "Rappel Match",
                        QString("Match à %1\nLieu: %2")
                            .arg(query.value(0).toDateTime().toString("HH:mm"))
                            .arg(query.value(1).toString()),
                        QSystemTrayIcon::Information,
                        10000
                        );
                }
            });
        }
    }

    settings.endGroup();

}

void CalendrierWidget::exportToPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF",
                                                    QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/calendrier.pdf",
                                                    "PDF (*.pdf)");

    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QPainter painter(&printer);
    painter.setFont(QFont("Arial", 12));

    // Dessiner le contenu (simplifié)
    painter.drawText(100, 100, "Calendrier des Matchs");

    // ... ajouter le contenu des matchs ...

    painter.end();
    QMessageBox::information(this, "Export réussi", "Le PDF a été généré avec succès");
}

void CalendrierWidget::onSelectionChanged()
{
    QTextCharFormat format;
    format.setBackground(QColor(100, 149, 237)); // Bleu pour la sélection
    calendar->setDateTextFormat(calendar->selectedDate(), format);
    afficherMatchsDuMois();
}
void CalendrierWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event); // Appelle le comportement par défaut (important)
    // Tu peux ajouter un dessin personnalisé ici si besoin
}
void CalendrierWidget::showReminderNotification(int matchId)
{
    QSqlQuery query;
    query.prepare("SELECT DATE_TIME, PLACE FROM MATCH WHERE ID = ?");
    query.addBindValue(matchId);
    if (query.exec() && query.next()) {
        QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
        trayIcon->showMessage(
            "Rappel Match",
            QString("Match à %1\nLieu: %2")
                .arg(query.value(0).toDateTime().toString("HH:mm"))
                .arg(query.value(1).toString()),
            QSystemTrayIcon::Information,
            10000
            );
    }
}
