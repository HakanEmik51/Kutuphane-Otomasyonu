#include "odunc_teslim_etme.h"
#include "ui_odunc_teslim_etme.h"

odunc_teslim_etme::odunc_teslim_etme(QSqlDatabase db,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::odunc_teslim_etme)
{
    ui->setupUi(this);
sorgu=new QSqlQuery(db);
         listele();
}

odunc_teslim_etme::~odunc_teslim_etme()
{
    delete ui;
}

void odunc_teslim_etme::listele()
{
     sorgu->prepare("select * from odunc_alinan ");
          if(!sorgu->exec()){

              QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
              return;
          }
          model=new QSqlQueryModel();
          model->setQuery(*sorgu);
          ui->table_odunc_alinan->setModel(model);
    sorgu->prepare("select * from odunc_teslim_edilen ");
         if(!sorgu->exec()){

             QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
             return;
         }
         model_2=new QSqlQueryModel();
         model_2->setQuery(*sorgu);
         ui->table_odunc_teslim->setModel(model_2);
}

void odunc_teslim_etme::on_table_odunc_alinan_clicked(const QModelIndex &index)
{    ui->line_uye_no->setText(model->index(index.row(),0).data().toString());
     ui->line_kitap_no->setText(model->index(index.row(),1).data().toString());
      odunc_alma_tarihi=model->index(index.row(),2).data().toString();
    alma_tarih.append(model->index(index.row(),2).data().toString());

}


void odunc_teslim_etme::on_pushButton_clicked()
{      QStringList tarih;
       tarih=alma_tarih[0].split(".");

       int yıl=tarih[2].toInt();
       int ay=tarih[1].toInt();
       int gun=tarih[0].toInt();
       int yıl1=ui->date->date().year();
       int ay1 =ui->date->date().month();
       int gun1=ui->date->date().day();
       QDateTime startdate(QDate(yıl,ay,gun),QTime(0,0,0));
       QDateTime enddate(QDate(yıl1,ay1,gun1),QTime(0,0,0));
          int a=startdate.daysTo(enddate);

    sorgu->prepare("insert into odunc_teslim_edilen(uye_no,kitap_no,alma_tarihi,verme_tarihi,borc) values(?,?,?,?,?)");

      sorgu->addBindValue(ui->line_uye_no->text().toInt());
      sorgu->addBindValue(ui->line_kitap_no->text().toInt());
      sorgu->addBindValue(odunc_alma_tarihi);
      sorgu->addBindValue(ui->date->text());
         if(a>15){
             int c=a-15;
             sorgu->addBindValue(c);
         }
else{
         sorgu->addBindValue(0);
         }

      if(!sorgu->exec()){
          QMessageBox::critical(this,"hata","ödünç verilen  tablosuna ekleme yaparken bir hata ile karşılaşıldı");
          return;
      }
      sorgu->prepare("delete from odunc_alinan where uye_no=? and kitap_no=?");
      sorgu->addBindValue(ui->line_uye_no->text().toInt());
         sorgu->addBindValue(ui->line_kitap_no->text().toInt());
         if(!sorgu->exec()){
             QMessageBox::critical(this,"hata","ödünç verilen  tablosuna ekleme yaparken bir hata ile karşılaşıldı");
             return;
         }
      listele();
}

