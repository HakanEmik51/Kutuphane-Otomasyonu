#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include"uye_islemleri.h"
#include"kitap_islemleri.h"
#include"odunc_alma_islemleri.h"
#include "odunc_teslim_etme.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");

    uye_islemleri *uye_islem;
    kitap_islemleri *kitap_islem;
    odunc_alma_islemleri *odunc_al;
    odunc_teslim_etme *odunc_ver;
};
#endif // MAINWINDOW_H
