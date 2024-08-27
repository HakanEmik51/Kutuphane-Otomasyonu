#include "kitap_islemleri.h"
#include "ui_kitap_islemleri.h"

kitap_islemleri::kitap_islemleri(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kitap_islemleri)
{
    ui->setupUi(this);
    sorgu=new QSqlQuery(db);
    listele();
}

kitap_islemleri::~kitap_islemleri()
{
    delete ui;
}

void kitap_islemleri::listele()
{    sorgu->prepare("select * from kitap ");
     if(!sorgu->exec()){

         QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
         return;
     }
     model=new QSqlQueryModel();
     model->setQuery(*sorgu);
     ui->table_tum_kitap->setModel(model);

}





void kitap_islemleri::on_pushButton_clicked()
{
    sorgu->prepare("insert into kitap(kitap_ad,kitap_sayisi) values(?,?)");
       if(ui->line_kitap_ad->text()=="" || ui->line_stok->text()==""){
           QMessageBox::critical(this,"hata","gerekli alanları doldurunuz");
           return;

       }
       sorgu->addBindValue(ui->line_kitap_ad->text());
       sorgu->addBindValue(ui->line_stok->text().toInt());
       if(!sorgu->exec()){
           QMessageBox::critical(this,"hata","kitap tablosuna ekleme yaparken bir hata ile karşılaşıldı");
           return;
       }
       listele();
}


void kitap_islemleri::on_pushButton_2_clicked()
{
    sorgu->prepare("update kitap set kitap_ad=?,kitap_sayisi=? where kitap_no=?");
    sorgu->addBindValue(ui->line_kitap_ad->text());
    sorgu->addBindValue(ui->line_stok->text().toInt());
    sorgu->addBindValue(ui->line_kitap_no->text().toInt());
    if(!sorgu->exec()){
       QMessageBox::critical(this,"hata","kitap tablosuna guncelleme yaparken bir hata ile karşılaşıldı");
        return;
    }
    listele();
}


void kitap_islemleri::on_pushButton_3_clicked()
{
    sorgu->prepare("select * from odunc_alinan where kitap_no=? ");
    sorgu->addBindValue(ui->line_kitap_no->text().toInt());



    if(!sorgu->exec()){
        QMessageBox::critical(this,"hata","kitap tablosundan veri silerken  bir  bir hata ile karşılaşıldı");
        return;
    }
    int syc=0;
    while(sorgu->next()){

        syc++;
}
    if(syc>0){
         QMessageBox::critical(this,"hata","bu kitap silinemez.bu kitap bir üyeye ödünç verilmiştir");



    }
    else{
        sorgu->prepare("delete from kitap where kitap_no=?");
        sorgu->addBindValue(ui->line_kitap_no->text().toInt());

}
        if(!sorgu->exec()){
           QMessageBox::critical(this,"hata","kitap tablosundan  veri silerken  bir hata ile karşılaşıldı");
            return;
        }

    listele();
}







void kitap_islemleri::on_table_tum_kitap_clicked(const QModelIndex &index)
{     ui->line_kitap_no->setText(model->index(index.row(),0).data().toString());
      ui->line_kitap_ad->setText(model->index(index.row(),1).data().toString());
        ui->line_stok->setText(model->index(index.row(),2).data().toString());
      sorgu->prepare("select * from odunc_alinan where kitap_no=?");
      sorgu->addBindValue(ui->line_kitap_no->text().toInt());
      if(!sorgu->exec()){

          QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
          return;
      }
     model_2=new QSqlQueryModel();
     model_2->setQuery(*sorgu);
     ui->table_odunc_alinan->setModel(model_2);
     sorgu->prepare("select * from odunc_teslim_edilen where kitap_no=?");
     sorgu->addBindValue(ui->line_kitap_no->text().toInt());
     if(!sorgu->exec()){

         QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
         return;
     }
    model_3=new QSqlQueryModel();
    model_3->setQuery(*sorgu);
    ui->table_gecmis_odunc->setModel(model_3);

}

