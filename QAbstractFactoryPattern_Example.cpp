/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 04.09.2020
*/


#include <QCoreApplication>

#include <iostream>
using namespace std;


//First we have to create the base class
//all components are going to derive from this base class.
//So this class has to accomodate all requirements
//of needed classes.
class Vehicle
{
 public:
  virtual ~Vehicle(){}; // New Line added, no failure.
  virtual void START_ENGINE() = 0;
  virtual void GET_READY() = 0;
};


//Then we create for classes and two of them are same type
//the other two are the same type vehicles.
class Aircraft : public Vehicle
{
 public:
  void START_ENGINE() { cout << "Aircraft Engine Started" << endl; }
  void GET_READY() { cout << "Aircraft is ready for operation" << endl; }
};

class Drone : public Vehicle
{
 public:
    void START_ENGINE() { cout << "Drone Engine Started" << endl; }
    void GET_READY() { cout << "Drone is ready for operation" << endl; }
};

class Car : public Vehicle
{
 public:
    void START_ENGINE() { cout << "Car Engine Started" << endl; }
    void GET_READY() { cout << "Car is ready for operation" << endl; }
};

class Truck : public Vehicle
{
 public:
    void START_ENGINE() { cout << "Truck Engine Started" << endl; }
    void GET_READY() { cout << "Truck is ready for operation" << endl; }
};


//And then we create our abstract factory class to declare
//vehicle type classes. Abstract factory class will derive the
//Type classes with same methods.
class Factory
{
 public:
 virtual ~Factory(){}
  virtual Vehicle *create_small_vehicle() = 0;
  virtual Vehicle *create_big_vehicle() = 0;
};

//And here our concrete factory classes. These classes are going to
//create our vehicles according to user request.
class FliyngTypeFactory : public Factory
{
 public:
  Vehicle *create_big_vehicle()
  {
    return new Aircraft;
  }
  Vehicle *create_small_vehicle()
  {
    return new Drone;
  }
};

class GroundTypeFactory : public Factory
{
 public:
  Vehicle *create_small_vehicle()
  {
    return new Car;
  }
  Vehicle *create_big_vehicle()
  {
    return new Truck;
  }
};

//In main method the user will see all vehicles are started and ready.
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    system("title Factory Design Pattern Example - Thecodeprogram");
    cout << "Welcome Factory Design Pattern Example in QT C++" << endl << endl;

    Factory *factory;
    Vehicle * vec;

    factory = new FliyngTypeFactory;

    vec = factory->create_big_vehicle();
    vec->START_ENGINE();
    vec->GET_READY();

    cout << "--------------------------------------------------------------------------" << endl;

    vec = factory->create_small_vehicle();
    vec->START_ENGINE();
    vec->GET_READY();

    cout << "--------------------------------------------------------------------------" << endl;

    factory = new GroundTypeFactory;

    vec = factory->create_big_vehicle();
    vec->START_ENGINE();
    vec->GET_READY();

    cout << "--------------------------------------------------------------------------" << endl;

    vec = factory->create_small_vehicle();
    vec->START_ENGINE();
    vec->GET_READY();

    cout << "--------------------------------------------------------------------------" << endl;

    return a.exec();
}
