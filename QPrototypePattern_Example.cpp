/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 09.09.2020
*/


#include <iostream>

using namespace std;

//Some QT Libraries
#include <QString>
#include <QStringList>

// First We have to create a Prototype class to build
// other classes. This class have all common specifications
// Other classes will clone this class and make some addings
class Vehicle
{
private :


public:
    //In constructor og the base class,
    //I have added some specifications which essential
    //for this type of component
    Vehicle(){
        parts.append("Engine");
        parts.append("FuelTanks");
    }
    //Then I have created required other properties
    // and some important methods
    //Also I have declared some override method which must
    //call in the derived classes.
    QString name = "Default" ;
    QStringList parts;
    virtual Vehicle* clone() const = 0;
    virtual void listAllParts() const = 0;
    virtual void setVehicleName(QString name){ this->name = name; }
    virtual void addParts(QString part) { parts.append(part); }

    virtual ~Vehicle() { cout << "Vehicle Class has been destroyed and memory released...\n\n";  }
};


// Here we create our concrete prototype classes
// which derived from above base class.
class Aircraft : public Vehicle
{
public:
    Aircraft(){
        addParts("IFE");
        addParts("Passenger Seats");
    }
    Aircraft*   clone() const { return new Aircraft; }
    void listAllParts() const {
        cout << "Vehicle Type : Aircraft\n";
        cout << "Vehicle Name : " << name.toLocal8Bit().constData() << endl;
        for(int i =0; i< parts.length(); i++){
            cout << "Part: " << parts.at(i).toLocal8Bit().constData() << endl;
        }
        cout << "------------------------------\n";
    }

};


class Car : public Vehicle
{
public:
    Car(){
        addParts("Mirrors");
        addParts("Shift Gear");
    }
    Vehicle* clone() const { return new Car; }
    void listAllParts() const {
        cout << "Vehicle Type : Car\n";
        cout << "Vehicle Name : " << name.toLocal8Bit().constData() << endl;
        for(int i =0; i< parts.length(); i++){
            cout << "Part:" << parts.at(i).toLocal8Bit().constData() << endl;
        }
        cout << "------------------------------\n";
    }
};


// With clone method we are not creating a new structure,
// we are returning the prepared class with a pointer. So
// we are avoiding to use extra memory and preventing memory leaks.


// Below factory class will produce the prototypes from
// above declared classes with specified indexes
class PrototypeFactory {
public:
    ~PrototypeFactory(){ cout << "Prototype Factory Has been destroyed and memory released\n\n"; }

    Vehicle* vehicle_prototypes[2]{
        new Aircraft, new Car
    };

    Vehicle* preparePrototype( int prototypeIndex ){
        return vehicle_prototypes[prototypeIndex]->clone();
    }

};

static int INDEX_AIRCRAFT = 0;
static int INDEX_CAR = 1;


// In main function we are going to create prototypes and use them.
// In here we are going to create prototypes from both different classes
// then call some functions in them and show what do they have inside arrays of them

// At the end of process do not forget the delete variables which are not need
// to prevent the memory leaks.
int main() {

    system("title Prototype Design Pattern Example - Thecodeprogram");
    cout << "Welcome Prototype Design Pattern Example in QT C++" << endl << endl;

    Vehicle *vec;
    PrototypeFactory *pFactory = new PrototypeFactory();
    vec = pFactory->preparePrototype(INDEX_AIRCRAFT);

    vec->setVehicleName("Boeing... ");
    vec->addParts("MCAS");
    vec->addParts("EICAS");
    vec->listAllParts();

    //Created another type of same component
    vec = pFactory->preparePrototype(INDEX_AIRCRAFT);
    vec->setVehicleName("Airbus... ");
    vec->addParts("ECAM");
    vec->listAllParts();

    //Created another type of same component
    vec = pFactory->preparePrototype(INDEX_CAR);
    vec->setVehicleName("MURAT124... ");
    vec->addParts("SALLOW DOG");
    vec->addParts("DISCO BALL");
    vec->addParts("SUBWOOFERS");
    vec->listAllParts();

    delete pFactory;
    delete vec;

    return 0;
}
