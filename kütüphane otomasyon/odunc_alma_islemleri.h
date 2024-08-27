#ifndef ODUNC_ALMA_ISLEMLERI_H
#define ODUNC_ALMA_ISLEMLERI_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>

namespace Ui {
class odunc_alma_islemleri;
}

class odunc_alma_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit odunc_alma_islemleri(QSqlDatabase, QWidget *parent = nullptr);
    ~odunc_alma_islemleri();
    void listele();
    int stok;

private slots:
    void on_table_tum_uye_clicked(const QModelIndex &index);

    void on_table_tum_kitap_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::odunc_alma_islemleri *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    QSqlQueryModel *model_2;
    QSqlQueryModel *model_3;
};

#endif // ODUNC_ALMA_ISLEMLERI_H
