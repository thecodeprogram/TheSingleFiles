/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 11.04.2021
*/

#include "customdigitalwatch.h"
#include "ui_customdigitalwatch.h"



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


