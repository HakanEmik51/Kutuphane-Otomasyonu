#ifndef UYE_ISLEMLERI_H
#define UYE_ISLEMLERI_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>

namespace Ui {
class uye_islemleri;
}

class uye_islemleri : public QDialog
{
    Q_OBJECT

public:
    explicit uye_islemleri(QSqlDatabase, QWidget *parent = nullptr);
    ~uye_islemleri();
    void listele();


private slots:
    void on_table_tum_uye_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::uye_islemleri *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;

};

#endif // UYE_ISLEMLERI_H
