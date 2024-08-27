#ifndef KITAP_ISLEMLERI_H
#define KITAP_ISLEMLERI_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>

namespace Ui {
class kitap_islemleri;
}

class kitap_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit kitap_islemleri(QSqlDatabase,QWidget *parent = nullptr);
    ~kitap_islemleri();
     void listele();


private slots:


     void on_pushButton_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();



     void on_table_tum_kitap_clicked(const QModelIndex &index);

private:
    Ui::kitap_islemleri *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
    QSqlQueryModel *model_2;
    QSqlQueryModel *model_3;
};

#endif // KITAP_ISLEMLERI_H
