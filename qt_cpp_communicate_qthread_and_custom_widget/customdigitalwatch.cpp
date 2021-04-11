/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 11.04.2021
*/

#include "customdigitalwatch.h"
#include "ui_customdigitalwatch.h"


//1. QT Form class ı olusturuldu. header code dosyaları ve ui oluşmuş oldu
//2. header dosyasının içerisine TheWatch adında bir public QWidget kalıtımı alan bir class oluşturuldu
//3. Thewatch classına Q_OBJECT macrosu eklendi ve bu sayede signal slot kullanılabilir hale geldi.
//4. Header içine olusturulan TheWatch classına public olarak constructor eklendi ve private olarak diğer nesneler tanımladnı
//5. Tanımlanan nesneler ve constructor metod ilgili header dosyasına bağlı c++ dosyasında initialize edildi
//6. TheWatch classının constructorı içerisinde label başlatıldı ve hazırlığı yapıldı. burada QHBoxLayout this anahtar sözcüğü ile çağrılmaya dikkat edilmelidir.
//7. QThread yapısı aynı header içerisine implmente edildi ve Thewatch constructor içerisinde çağrıldı.
//8. Ana class constructor de thread ve TheWatch widget ları signal ve slotlar ile bağlandı. ve thread çalıştırıldı.
//9. Ardından thread başlatıldı ve direk olarak threadın,  custom widgetin signaline bağlanarak güncellemesine izin verildi.



CustomDigitalWatch::CustomDigitalWatch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomDigitalWatch)
{
    ui->setupUi(this);

    theWatch = new TheWatch();
    watchUpdaterThread = new WatchUpdaterThread(this);


    QGridLayout *layout = new QGridLayout;
    layout->setMargin(0);
    layout->addWidget(theWatch);

    ui->widgetWatch->setLayout(layout);



    connect( watchUpdaterThread, SIGNAL(updateTimeFromThread(QString)), theWatch, SLOT(writeUpdatedTime(QString)) );

    watchUpdaterThread->start();

}

CustomDigitalWatch::~CustomDigitalWatch()
{
    delete ui;
    watchUpdaterThread->exit();
    delete watchUpdaterThread;
    delete theWatch;
}




TheWatch::TheWatch(QWidget *parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this); // this keyword is iimportant, we tell the widget the parent withn be showed
    layout->setMargin(0);

   lblWatch = new QLabel(QString("00:00:00"));
   QString strFont = "font: 75 108pt 'Comic Sans MS',";
   lblWatch->setStyleSheet(strFont);
   lblWatch->setAlignment(Qt::AlignCenter);
   lblWatch->setMargin(0); // to stretch the widget

   qDebug() << "TheWatch Constructor";

   layout->addWidget(lblWatch);

}

void TheWatch::writeUpdatedTime(QString timetext)
{
   lblWatch->setText(timetext);
}

WatchUpdaterThread::WatchUpdaterThread(QWidget *parent)
{
}

void WatchUpdaterThread::run()
{
    while(true)
    {
        emit updateTimeFromThread(QDateTime::currentDateTime().toString("hh:mm:ss"));
        qDebug() << QDateTime::currentDateTime().toString("hh:mm:ss");
        QThread::sleep(1);
    }
}


