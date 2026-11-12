#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>
#include <algorithm>
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //butonların listesi
    kartlar = {ui->pushButton , ui->pushButton_10 , ui->pushButton_2  ,ui->pushButton_3 , ui->pushButton_4 ,
                ui->pushButton_5 , ui->pushButton_6 , ui->pushButton_7 , ui->pushButton_8 , ui->pushButton_9 };
    //Resimlerin listesi
    QStringList resimListe {"bomba" , "baykus" ,"kedi" , "zurafa" , "penguen" ,
                            "bomba" , "baykus" ,"kedi" , "zurafa" , "penguen"};
    std::shuffle(resimListe.begin(), resimListe.end(), *QRandomGenerator::global()); //Listeyi karıştırır

    //Resimlerin butonlara dağıtımı
    for(int i = 0; i<kartlar.size() ; i++){
        QPushButton *b = kartlar[i];
        resimler[b] = ":/img/images/" + resimListe[i] + ".png";
        b->setStyleSheet("border-image: url(" + arkaResim + ");");
        connect(b , &QPushButton::clicked , this , &MainWindow::kartTiklandi);//butonların tıklama sinyallerinin bağlanması
    }

    sureSayaci = new QTimer(this);
    connect(sureSayaci , &QTimer::timeout , this , &MainWindow::sureyiGuncelle);
    ui->label_sure_sayac->setText("00:00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::kartTiklandi(){
    QPushButton *b = qobject_cast<QPushButton*>(sender());

    if(!b || bekleme || b==ilkKart || eslesenler.contains(b))
        return;

    if(!sureSayaci->isActive())
        sureSayaci->start(1000);

    b->setStyleSheet("border-image: url(" + resimler[b] + ");");

    if(ilkKart == nullptr){
        ilkKart = b;
        return;
    }

    if(resimler[b] == resimler[ilkKart]){
        eslesenler.insert(ilkKart);
        eslesenler.insert(b);
        ilkKart = nullptr;

        if(bittiMi()){
            sureSayaci->stop();
        }

    }else{
        basarisizSayac++;
        ui->label_sayac->setText(QString::number(basarisizSayac));
        QPushButton *a = ilkKart;
        ilkKart = nullptr;
        bekleme = true;
        QTimer::singleShot(1000 , this , [=](){ //1 sn bekler
            a->setStyleSheet("border-image: url(" + arkaResim + ");");
            b->setStyleSheet("border-image: url(" + arkaResim + ");");
            bekleme = false;
        });
    }
}

void MainWindow::sureyiGuncelle(){
    saniye++;
    int dk = saniye/60;
    int sn = saniye%60;
    ui->label_sure_sayac->setText(QString("%1:%2").arg(dk , 2 , 10 , QChar('0')).arg(sn , 2 , 10 , QChar('0')));
}

bool MainWindow::bittiMi()const{
    return eslesenler.size() == kartlar.size();
}
