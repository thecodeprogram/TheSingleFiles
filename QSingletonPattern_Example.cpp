
/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 27.10.2020
*/


#include <QCoreApplication>
#include <iostream>
#include <QString>

using namespace std;

//We create a class with public property
class Configurations{
    public :
        int volume;
        bool notification;
};

//Now create the singleton class
class Singleton {
   static Singleton *instance;
   Configurations *config;

   // initialize the related configuration class at constructor
   Singleton() {
      config = new Configurations();
   }

   //First initialize the instance. All classes will access via this instance
   public:
   static Singleton *getInstance() {
      if (!instance) instance = new Singleton;
      return instance;
   }

   //Getters and setters of related functions of realted configurations
   void setVolume(int vol) { this->config->volume = vol; }
   int getVolume() { return this->config->volume; }

   void setNotification(bool notify) { this->config->notification = notify; }
   bool getNotification() { return this->config->notification; }
};

//Initialize singleton instance pointer with zero value
Singleton *Singleton::instance = 0;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    system("title Singleton Design Pattern Example - Thecodeprogram");
    cout << "Welcome Singleton Design Pattern Example in QT C++" << endl << endl;

    Singleton *s = s->getInstance();
    s->setVolume(50);
    cout << "Volume level is : " << s->getVolume() << endl;
    s->setNotification(true);
    cout << "Notification sending config is : " << s->getNotification() << endl;

    return a.exec();
}
