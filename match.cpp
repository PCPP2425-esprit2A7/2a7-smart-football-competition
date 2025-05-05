#include "match.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QTime>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QTimer>
#include <QGraphicsDropShadowEffect>

// Updated constructor with QString team1 and team2
Match::Match(int id, const QString &date_time, const QString &place,
             const QString &score, const QString &status, const QString &team1, const QString &team2,
             int arbitre)
    : id(id), date_time(date_time), place(place), score(score),
    status(status), arbitre(arbitre), team1(team1), team2(team2) {}

// Updated getters and setters for team1 and team2
QString Match::getTeam1() const { return team1; }
void Match::setTeam1(const QString &newTeam1) { team1 = newTeam1; }
QString Match::getTeam2() const { return team2; }
void Match::setTeam2(const QString &newTeam2) { team2 = newTeam2; }
int Match::getArbitre() const { return arbitre; }
void Match::setArbitre(int newArbitre) { arbitre = newArbitre; }

bool Match::ajouterMatch() {
    QSqlQuery query;
    query.prepare("INSERT INTO MATCH (STATUS, DATE_TIME, PLACE, SCORE, ARBITRE, TEAM1, TEAM2) "
                  "VALUES (:status, TO_DATE(:date_time, 'DD/MM/YYYY HH24:MI'), :place, :score, :arbitre, :team1, :team2)");
    query.bindValue(":status", status);
    query.bindValue(":date_time", date_time);
    query.bindValue(":place", place);
    query.bindValue(":score", score);
    query.bindValue(":arbitre", arbitre);
    query.bindValue(":team1", team1);  // Now binding QString
    query.bindValue(":team2", team2);  // Now binding QString

    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        qDebug() << "Valeurs:" << status << date_time << place << score << arbitre << team1 << team2;
        return false;
    }
    return true;
}

QSqlQueryModel* Match::afficherMatch() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID, DATE_TIME, PLACE, SCORE, STATUS, ARBITRE, TEAM1, TEAM2 FROM MATCH");

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de l'affichage des matchs :" << query.lastError().text();
    }
    return model;
}

bool Match::modifierMatch(int id, const QString &dateTime, const QString &place,
                          const QString &score, const QString &status,
                          int arbitre, const QString &team1, const QString &team2) {
    QSqlQuery query;
    query.prepare("UPDATE MATCH SET "
                  "DATE_TIME = TO_DATE(:dateTime, 'YYYY-MM-DD HH24:MI:SS'), "
                  "PLACE = :place, "
                  "SCORE = :score, "
                  "STATUS = :status, "
                  "ARBITRE = :arbitre, "
                  "TEAM1 = :team1, "
                  "TEAM2 = :team2 "
                  "WHERE ID = :id");

    query.bindValue(":dateTime", dateTime);
    query.bindValue(":place", place);
    query.bindValue(":score", score);
    query.bindValue(":status", status);
    query.bindValue(":arbitre", arbitre);
    query.bindValue(":team1", team1);  // Now binding QString
    query.bindValue(":team2", team2);  // Now binding QString
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification:" << query.lastError().text();
        qDebug() << "Requête:" << query.lastQuery();
        qDebug() << "Valeurs:" << dateTime << place << score << status << arbitre << team1 << team2 << id;
        return false;
    }
    return query.numRowsAffected() > 0;
}
/*
QSqlQueryModel* Match::rechercherParId(int id) {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT ID, DATE_TIME, PLACE, SCORE, STATUS, ARBITRE FROM MATCH WHERE ID = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors de la recherche du match :" << query.lastError().text();
        delete model;
        return nullptr;
    }

    return model;
}
*/
// Méthode de suppression
bool Match::supprimerMatch(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM MATCH WHERE ID = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression du match :" << query.lastError().text();
        return false;
    }

    return true;
}
QSqlQueryModel* Match::trierPar(const QString& field, Qt::SortOrder order)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString orderStr = (order == Qt::AscendingOrder) ? "ASC" : "DESC";

    // Liste des champs valides pour éviter les injections SQL
    QStringList validFields = {"ID", "DATE_TIME", "PLACE", "SCORE", "STATUS", "ARBITRE"};

    if (!validFields.contains(field.toUpper())) {
        qDebug() << "Champ de tri invalide :" << field;
        delete model;
        return nullptr;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM MATCH ORDER BY " + field + " " + orderStr);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors du tri :" << query.lastError();
        delete model;
        return nullptr;
    }
    return model;
}/*
QSqlQueryModel* Match::trierPar(const QString& field, Qt::SortOrder order)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString orderStr = (order == Qt::AscendingOrder) ? "ASC" : "DESC";

    // Liste des champs valides pour éviter les injections SQL
    QStringList validFields = {"ID", "DATE_TIME", "PLACE", "SCORE", "STATUS", "ARBITRE"};

    if (!validFields.contains(field.toUpper())) {
        qDebug() << "Champ de tri invalide :" << field;
        delete model;
        return nullptr;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM MATCH ORDER BY " + field + " " + orderStr);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors du tri :" << query.lastError();
        delete model;
        return nullptr;
    }
    return model;
}*/
/*QSqlQueryModel* Match::trierParDate(Qt::SortOrder order)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QString orderStr = (order == Qt::AscendingOrder) ? "ASC" : "DESC";

    QSqlQuery query;
    query.prepare("SELECT * FROM MATCH ORDER BY DATE_TIME " + orderStr);

    if (query.exec()) {
        model->setQuery(query);
    } else {
        qDebug() << "Erreur lors du tri :" << query.lastError();
        delete model;
        return nullptr;
    }
    return model; // Retourne les données triées mais ne les affiche pas
}
*/

/*
void Match::displayScoreChart(const QMap<QString, int> &data, QGraphicsView *view)
{

    if (data.isEmpty()) {
        QMessageBox::information(nullptr, "Information", "Aucune donnée de score disponible");
        return;
    }
    // Nettoyer la vue précédente
    if (view->scene()) {
        delete view->scene();
    }

    QGraphicsScene *scene = new QGraphicsScene();
    view->setScene(scene);

    // Configuration du graphique
    int barWidth = 80;
    int spacing = 30;
    int xOffset = 80;
    int yOffset = 400;
    int maxBarHeight = 300;

    // Trouver la valeur maximale pour l'échelle
    int maxValue = 1;
    for (int value : data.values()) {
        if (value > maxValue) {
            maxValue = value;
        }
    }

    // Dessiner les axes
    QPen axisPen(Qt::black, 2);
    scene->addLine(xOffset, yOffset, xOffset + data.size() * (barWidth + spacing), yOffset, axisPen); // Axe X
    scene->addLine(xOffset, yOffset, xOffset, yOffset - maxBarHeight, axisPen); // Axe Y

    // Ajouter les barres et les labels
    int index = 0;
    for (auto it = data.begin(); it != data.end(); ++it) {
        int barHeight = (it.value() * maxBarHeight) / maxValue;

        // Créer la barre
        QGraphicsRectItem *bar = new QGraphicsRectItem(
            xOffset + index * (barWidth + spacing),
            yOffset - barHeight,
            barWidth,
            barHeight);
        bar->setBrush(QColor(70, 130, 180)); // Couleur bleue
        bar->setPen(QPen(Qt::black));
        scene->addItem(bar);

        // Ajouter le label de valeur
        QGraphicsTextItem *valueText = new QGraphicsTextItem(QString::number(it.value()));
        valueText->setPos(
            xOffset + index * (barWidth + spacing) + barWidth/2 - valueText->boundingRect().width()/2,
            yOffset - barHeight - 20);
        scene->addItem(valueText);

        // Ajouter le label de score
        QGraphicsTextItem *scoreText = new QGraphicsTextItem(it.key());
        scoreText->setPos(
            xOffset + index * (barWidth + spacing) + barWidth/2 - scoreText->boundingRect().width()/2,
            yOffset + 10);
        scene->addItem(scoreText);

        index++;
    }

    // Ajouter un titre
    QGraphicsTextItem *title = new QGraphicsTextItem("Statistiques des Scores");
    title->setPos(xOffset + (data.size() * (barWidth + spacing)) / 2 - title->boundingRect().width()/2, yOffset - maxBarHeight - 40);
    title->setFont(QFont("Arial", 12, QFont::Bold));
    scene->addItem(title);

    // Ajuster la vue
    view->setRenderHint(QPainter::Antialiasing);
    view->setSceneRect(scene->itemsBoundingRect());
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
}
*/
void Match::displayScoreChart(const QMap<QString, int>& data, QGraphicsView* view)
{
    if (data.isEmpty()) {
        QMessageBox::information(nullptr, "Information", "Aucune donnée de score disponible");
        return;
    }

    // Nettoyer la vue précédente
    if (view->scene()) {
        delete view->scene();
    }

    QGraphicsScene* scene = new QGraphicsScene();
    view->setScene(scene);

    // Configuration
    const int diameter = 280;
    const int centerX = diameter/2 + 50;
    const int centerY = diameter/2 + 50;
    int total = 0;

    // Calcul du total
    for (int value : data) {
        total += value;
    }

    // Palette de verts spécifique
    QVector<QColor> greenPalette = {
        QColor("#218555"),  // Vert foncé
        QColor("#D3D3D0"),  // Vert olive
        QColor("#619D80"),  // Vert très clair

    };



    // Styles
    QFont titleFont("Arial", 16, QFont::Bold);
    QFont percentFont("Arial", 10, QFont::Bold);
    QFont legendFont("Arial", 9);
    QFont totalFont("Arial", 11, QFont::Bold);

    // Titre
    QGraphicsTextItem* title = new QGraphicsTextItem("RÉPARTITION DES SCORES");
    title->setFont(titleFont);
    title->setDefaultTextColor(QColor("#466c44"));
    title->setPos(centerX - title->boundingRect().width()/2, 15);
    scene->addItem(title);

    // Dessin du diagramme
    int startAngle = 0;
    int colorIndex = 0;
    int legendX = centerX + diameter/2 + 30;
    int legendY = 70;

    for (auto it = data.begin(); it != data.end(); ++it) {
        int angle = (it.value() * 360 * 16) / total;
        int percentage = (it.value() * 100) / total;

        // Segment du camembert
        QGraphicsEllipseItem* segment = new QGraphicsEllipseItem(
            centerX - diameter/2,
            centerY - diameter/2,
            diameter, diameter);

        segment->setStartAngle(startAngle);
        segment->setSpanAngle(angle);
        segment->setBrush(greenPalette[colorIndex % greenPalette.size()]);
        segment->setPen(QPen(Qt::white, 1.5));
        scene->addItem(segment);

        // Pourcentage dans le segment
        if (angle > 15*16) {
            int midAngle = startAngle + angle/2;
            double rad = qDegreesToRadians(midAngle/16.0);
            int textX = centerX + (diameter/3) * cos(rad);
            int textY = centerY + (diameter/3) * sin(rad);

            QGraphicsTextItem* percent = new QGraphicsTextItem(QString("%1%").arg(percentage));
            percent->setFont(percentFont);
            percent->setDefaultTextColor(Qt::white);

            // Contour noir pour meilleure lisibilité
            QGraphicsDropShadowEffect* textEffect = new QGraphicsDropShadowEffect();
            textEffect->setBlurRadius(3);
            textEffect->setColor(Qt::black);
            textEffect->setOffset(1, 1);
            percent->setGraphicsEffect(textEffect);

            percent->setPos(textX - percent->boundingRect().width()/2,
                            textY - percent->boundingRect().height()/2);
            scene->addItem(percent);
        }

        // Légende
        QGraphicsEllipseItem* dot = new QGraphicsEllipseItem(legendX, legendY + 5, 10, 10);
        dot->setBrush(greenPalette[colorIndex % greenPalette.size()]);
        dot->setPen(Qt::NoPen);
        scene->addItem(dot);

        QString legendText = QString("%1 (%2 matchs)")
                                 .arg(it.key())
                                 .arg(it.value());

        QGraphicsTextItem* legendItem = new QGraphicsTextItem(legendText);
        legendItem->setFont(legendFont);
        legendItem->setDefaultTextColor(QColor(80, 80, 80));
        legendItem->setPos(legendX + 15, legendY);
        scene->addItem(legendItem);

        startAngle += angle;
        colorIndex++;
        legendY += 30;
    }

    // Cercle central pour effet donut
    QGraphicsEllipseItem* centerCircle = new QGraphicsEllipseItem(
        centerX - diameter/4,
        centerY - diameter/4,
        diameter/2, diameter/2);
    centerCircle->setBrush(Qt::white);
    centerCircle->setPen(Qt::NoPen);
    scene->addItem(centerCircle);

    // Total au centre
    QGraphicsTextItem* totalText = new QGraphicsTextItem(QString("TOTAL\n%1 matchs").arg(total));
    totalText->setFont(totalFont);
    totalText->setDefaultTextColor(QColor("#466c44"));
    totalText->setTextWidth(diameter/2);
    totalText->setPos(centerX - totalText->boundingRect().width()/2,
                      centerY - totalText->boundingRect().height()/2);
    scene->addItem(totalText);

    // Effet d'ombre pour le diagramme
    QGraphicsDropShadowEffect* shadow = new QGraphicsDropShadowEffect();
    shadow->setBlurRadius(12);
    shadow->setColor(QColor(0, 0, 0, 80));
    shadow->setOffset(4, 4);
    view->setGraphicsEffect(shadow);

    // Configuration finale
    view->setRenderHint(QPainter::Antialiasing, true);
    view->setRenderHint(QPainter::SmoothPixmapTransform, true);
    view->setSceneRect(scene->itemsBoundingRect());
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

}
