#ifndef ODUNC_TESLIM_ETME_H
#define ODUNC_TESLIM_ETME_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include<QDateTime>
#include<QStringList>

namespace Ui {
class odunc_teslim_etme;
}

class odunc_teslim_etme : public QDialog
{
    Q_OBJECT

public:
    explicit odunc_teslim_etme(QSqlDatabase,QWidget *parent = nullptr);
    ~odunc_teslim_etme();
    void listele();
    QStringList alma_tarih;
    QString odunc_alma_tarihi;

private slots:
    void on_table_odunc_alinan_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::odunc_teslim_etme *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    QSqlQueryModel *model_2;
};

#endif // ODUNC_TESLIM_ETME_H
