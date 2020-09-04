/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 05.09.2020
*/



#include <QCoreApplication>

#include <iostream>
using namespace std;
//Some QT libraries
#include <QString>
#include <QTextStream>
#include <QStringList>


//Here first we are in need of a product which may contain
//many different types of sub components like an aircraft
class Aircraft{
    public:
    QStringList partlist;
    void ListAircraftParts() const{
        for(int i = 0; i<partlist.size(); i++){
            cout << partlist.at(i).toStdString() << endl;
        }
    }
};


//Then we need a builder  class interface. This interface will derive the class
//to produce the products sub components according to user requests.
class Builder{
    public:
    virtual ~Builder(){}
    virtual void ProduceEngines() const =0;
    virtual void ProduceSeats() const =0;
    virtual void ProduceIFE() const =0;
};



//This class also known as ConcreteBuilder class.
//Product implementations are going to be realised through this Productor class.
//I will use only one Productor class but if you want you can use
//several types of Productor classes.
class AircratProductor : public Builder{

private:
    Aircraft* aircraft;

public:
    //We are initializing the product at constructor
    AircratProductor(){
        this->aircraft= new Aircraft();
    }

    ~AircratProductor(){
        delete aircraft;
    }

    //All producing steps will be defined here and they are all
    //will be called according to user request.
    void ProduceEngines()const override{
        this->aircraft->partlist.append("Engines");
    }

    void ProduceSeats()const override{
        this->aircraft->partlist.append("Passenger Seats");
    }

    void ProduceIFE()const override{
        this->aircraft->partlist.append("In Flight Entertainment System");
    }

    //Returns the built producted aircraft.
    Aircraft* GetAircraftBuiltAircraft() {
        Aircraft* res= this->aircraft;
        //Reset the productor for a new production with initial configurations
        this->aircraft= new Aircraft();
        return res;
    }
};



//Here our manager class. This class is responsible for managing the production.
//This class is capable of working with different builders,
//As I mentioned above there can be more builder classes and we should manage them
//through just one manager class.
class Manager{

private:
    Builder* builder;

public:

    //We can work with different type of builders
    //So we have to set it before we start to production.
    //I decided to set it at constructor
    Manager(Builder* _builder)
    {
        this->builder=_builder;
    }

    ~Manager()
    {
        delete builder;
    }

    //We are going to set the production configuration through
    //Manager class. We will tell the manager what we need and it will produce.
    void BuildLowCost(){
        this->builder->ProduceEngines();
    }

    void BuildMediumCost(){
        this->builder->ProduceEngines();
        this->builder->ProduceSeats();
    }

    void BuildFullandFull(){
        this->builder->ProduceEngines();
        this->builder->ProduceSeats();
        this->builder->ProduceIFE();
    }
};



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    system("title Factory Design Pattern Example - Thecodeprogram");
    cout << "Welcome Builder Design Pattern Example in QT C++" << endl << endl;

    program_init:

    //First we have to initialize the productor and our manager with this productor
    AircratProductor *productor = new AircratProductor();
    Manager *manager = new Manager(productor);

    //Program will ask the user the requested type of aircraft
    // and produce according to user input
    std::cout << "Enter your Requested Aircraft type : ";
    QString Request;
    QTextStream cin(stdin);
    Request = cin.readLine();

    if(Request == "low")
    {
        manager->BuildLowCost();
    }
    else if(Request == "medium")
    {
        manager->BuildMediumCost();
    }
    else if(Request == "full")
    {
        manager->BuildFullandFull();
    }
    else if(Request == "exit")
    {
        return 0;
    }


    cout << "Part list of Selected Aircraft type" << endl;

    //Show the selected aircraft properties
    Aircraft *producedAircraft = productor->GetAircraftBuiltAircraft();
    producedAircraft->ListAircraftParts();
    //and delete the garbage when we do not need to prevent memory leaks.
    delete producedAircraft;

    cout << "-------------------------" << endl;

    goto program_init;

    return a.exec();
}
