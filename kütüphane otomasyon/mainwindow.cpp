#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uye_islemleri.h"
#include"kitap_islemleri.h"
#include"odunc_alma_islemleri.h"
#include"odunc_teslim_etme.h"

//veri tabanının yolunu verdim.
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setDatabaseName("kutuphane.db");
    if(!db.open()){
    ui->statusbar->showMessage("veri tabanına bağlanılmadı");
    }
    else{
    ui->statusbar->showMessage("veri tabanına bağlanıldı");
    }






    }


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{uye_islem=new uye_islemleri(db);
uye_islem->show();


}


void MainWindow::on_pushButton_2_clicked()
{kitap_islem=new kitap_islemleri(db);
    kitap_islem->show();

}


void MainWindow::on_pushButton_3_clicked()
{odunc_al=new odunc_alma_islemleri(db);
    odunc_al->show();
}


void MainWindow::on_pushButton_4_clicked()
{odunc_ver=new odunc_teslim_etme(db);
    odunc_ver->show();
}

