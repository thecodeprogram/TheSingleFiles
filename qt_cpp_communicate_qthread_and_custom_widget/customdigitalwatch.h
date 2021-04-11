/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 11.04.2021
*/

#ifndef CUSTOMDIGITALWATCH_H
#define CUSTOMDIGITALWATCH_H

#include <QWidget>
#include <QThread>

#include <QLabel>
#include <QHBoxLayout>
#include <QFont>
#include <QDebug>
#include <QDateTime>


namespace Ui {
class CustomDigitalWatch;
}


//inherit the public QWidget to add this widget into another layout
class TheWatch : public QWidget
{
    Q_OBJECT

public:
    TheWatch(QWidget *parent = nullptr);

private :
    QLabel *lblWatch;


private slots:
    void writeUpdatedTime(QString timetext);


signals:
    void timeUpdated(QString timetext);

};



class WatchUpdaterThread : public QThread
{
    Q_OBJECT

public:
    WatchUpdaterThread(QWidget *parent);
    void run();

signals:
    void updateTimeFromThread(QString timetext);


};

class CustomDigitalWatch : public QWidget
{
    Q_OBJECT

public:
    explicit CustomDigitalWatch(QWidget *parent = nullptr);
    ~CustomDigitalWatch();

private:
    Ui::CustomDigitalWatch *ui;
    TheWatch *theWatch;
    WatchUpdaterThread *watchUpdaterThread;
};

#endif // CUSTOMDIGITALWATCH_H
