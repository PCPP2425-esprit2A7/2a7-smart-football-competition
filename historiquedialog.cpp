#include "historiquedialog.h"
#include "ui_historiqueDialog.h"
#include <QFile>
#include <QTextStream>

HistoriqueDialog::HistoriqueDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HistoriqueDialog)
{
    ui->setupUi(this);
    afficherHistorique(); // باش يتعرض وقت تتفتح الفورمة
}

HistoriqueDialog::~HistoriqueDialog()
{
    delete ui;
}

void HistoriqueDialog::afficherHistorique()
{
    QFile file("historique.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    ui->tableWidget_historique->setRowCount(0); // نبدأ بتفريغ الجدول
    int row = 0;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(" | ");

        if (parts.size() >= 2) {
            ui->tableWidget_historique->insertRow(row);

            for (int col = 0; col < parts.size(); ++col) {
                QTableWidgetItem *item = new QTableWidgetItem(parts[col]);
                item->setBackground(QColor(33, 133, 85, 102)); // rgba(33,133,85,0.4)
                item->setForeground(QBrush(Qt::white));
                ui->tableWidget_historique->setItem(row, col, item);
            }
            row++;
        }
    }

    // 🔥 تنظيم الأعمدة بعد ما تعمر الجدول
    ui->tableWidget_historique->resizeColumnsToContents();
    ui->tableWidget_historique->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    file.close();
}
