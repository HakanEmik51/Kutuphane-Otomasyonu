#include "uye_islemleri.h"
#include "ui_uye_islemleri.h"



uye_islemleri::uye_islemleri(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::uye_islemleri)
{
    ui->setupUi(this);
    sorgu=new QSqlQuery(db);
    listele();

}
uye_islemleri::~uye_islemleri()
{
    delete ui;
}

void uye_islemleri::listele()
{
    sorgu->prepare("select * from üye ");
    if(!sorgu->exec()){

        QMessageBox::critical(this,"hata","bir hata ile karşılaşıldı");
        return;
    }
    model=new QSqlQueryModel();
    model->setQuery(*sorgu);
    ui->table_tum_uye->setModel(model);
}



void uye_islemleri::on_table_tum_uye_clicked(const QModelIndex &index)
{
    ui->lineuyeno->setText(model->index(index.row(),0).data().toString());
    ui->line_uyead->setText(model->index(index.row(),1).data().toString());
    ui->line_uyesoyad->setText(model->index(index.row(),2).data().toString());
}


void uye_islemleri::on_pushButton_clicked()
{   sorgu->prepare("insert into üye(uye_ad,uye_soyad) values(?,?)");
    if(ui->line_uyead->text()=="" || ui->line_uyesoyad->text()==""){
        QMessageBox::critical(this,"hata","gerekli alanları doldurunuz");
        return;

    }
    sorgu->addBindValue(ui->line_uyead->text());
    sorgu->addBindValue(ui->line_uyesoyad->text());
    if(!sorgu->exec()){
        QMessageBox::critical(this,"hata","üye tablosuna ekleme yaparken bir hata ile karşılaşıldı");
        return;
    }
    listele();

}


void uye_islemleri::on_pushButton_2_clicked()
{
    sorgu->prepare("update üye set uye_ad=?,uye_soyad=? where uye_no=?");
    sorgu->addBindValue(ui->line_uyead->text());
    sorgu->addBindValue(ui->line_uyesoyad->text());
    sorgu->addBindValue(ui->lineuyeno->text().toInt());
    if(!sorgu->exec()){
       QMessageBox::critical(this,"hata","üye tablosuna guncelleme yaparken bir hata ile karşılaşıldı");
        return;
    }
    listele();


}


void uye_islemleri::on_pushButton_3_clicked()
{
    sorgu->prepare("select * from odunc_alinan where uye_no=? ");
    sorgu->addBindValue(ui->lineuyeno->text().toInt());
    //sorgu->prepare("select * from odunc_teslim_edilen where uye_no=? ");
   // sorgu->addBindValue(ui->lineuyeno->text().toInt());


    if(!sorgu->exec()){
        QMessageBox::critical(this,"hata","üye tablosundan veri silerken  bir  bir hata ile karşılaşıldı");
        return;
    }
    int syc=0;
    while(sorgu->next()){

        syc++;

    }

    if(syc>0){

QMessageBox::critical(this,"hata","bu üye silinemez.Üyenin henüz teslim etmediği kitaplar vardır.");


    }
    else{
        sorgu->prepare("delete from üye where uye_no=?");
        sorgu->addBindValue(ui->lineuyeno->text().toInt());


        if(!sorgu->exec()){
           QMessageBox::critical(this,"hata","üye tablosundan  veri silerken  bir hata ile karşılaşıldı");
            return;
        }
    }
    listele();

}


