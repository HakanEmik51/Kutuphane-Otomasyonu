#include "odunc_alma_islemleri.h"
#include "ui_odunc_alma_islemleri.h"

odunc_alma_islemleri::odunc_alma_islemleri(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::odunc_alma_islemleri)
{
    ui->setupUi(this);
sorgu=new QSqlQuery(db);

              listele();

}

odunc_alma_islemleri::~odunc_alma_islemleri()
{
    delete ui;
}

void odunc_alma_islemleri::listele()
{
         sorgu->prepare("select * from üye ");
              if(!sorgu->exec()){

                  QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
                  return;
              }
              model=new QSqlQueryModel();
              model->setQuery(*sorgu);
              ui->table_tum_uye->setModel(model);
              sorgu->prepare("select * from kitap ");
                   if(!sorgu->exec()){

                       QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
                       return;
                   }
                   model_2=new QSqlQueryModel();
                   model_2->setQuery(*sorgu);
                   ui->table_tum_kitap->setModel(model_2);
    sorgu->prepare("select * from odunc_alinan ");
         if(!sorgu->exec()){

             QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
             return;
         }
         model_3=new QSqlQueryModel();
         model_3->setQuery(*sorgu);
         ui->table_odunc_alinan->setModel(model_3);
}



void odunc_alma_islemleri::on_table_tum_uye_clicked(const QModelIndex &index)
{
    ui->line_uye_no->setText(model->index(index.row(),0).data().toString());
}


void odunc_alma_islemleri::on_table_tum_kitap_clicked(const QModelIndex &index)
{
    ui->line_kitap_no->setText(model_2->index(index.row(),0).data().toString());
    stok=model_2->index(index.row(),2).data().toInt();
}


void odunc_alma_islemleri::on_pushButton_clicked()
{    sorgu->prepare("select * from odunc_alinan where kitap_no=? ");
     sorgu->addBindValue(ui->line_kitap_no->text().toInt());



     if(!sorgu->exec()){
         QMessageBox::critical(this,"hata","ödünç alma tablsouna veri eklerken  bir hata ile karşılaşıldı");
         return;
     }
     int syc2=0;
     while(sorgu->next()){

         syc2++;
 }
     if(syc2==stok){
         QMessageBox::critical(this,"hata","bu kitap şuan da stok da yok ödünç verilemez");
        return;
     }
    sorgu->prepare("select * from odunc_alinan where kitap_no=? ");
    sorgu->addBindValue(ui->line_kitap_no->text().toInt());



    if(!sorgu->exec()){
        QMessageBox::critical(this,"hata","ödünç alma tablsouna veri eklerken  bir hata ile karşılaşıldı");
        return;
    }
    int syc=0;
    while(sorgu->next()){

        syc++;
}
    if(syc>0){
        QMessageBox::critical(this,"hata","bu üye bu kitabın bir tanesini şu an ödünç almış tekrar ödünç verilemez");
       return;



    }
    else{
        sorgu->prepare("insert into odunc_alinan(uye_no,kitap_no,odunc_alma_tarihi) values(?,?,?)");
        sorgu->addBindValue(ui->line_uye_no->text().toInt());
        sorgu->addBindValue(ui->line_kitap_no->text().toInt());
        sorgu->addBindValue(ui->date->text());

}
        if(!sorgu->exec()){
           QMessageBox::critical(this,"hata","ödünç alma tablsouna veri eklerken  bir hata ile karşılaşıldı");
            return;
        }

    listele();




}

