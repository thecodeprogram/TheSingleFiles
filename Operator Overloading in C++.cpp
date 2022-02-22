/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 22.02.2022
*/

#include <QCoreApplication>
#include <iostream>
#include <math.h>

using namespace std;

class Square {
private:
    int area;
public:
    Square(double _area = 0)  {area = _area; }
    void printArea() { cout << area << endl; }
    Square operator+(const Square& _s) {
        Square s;
        return s.area = this->area + _s.area;
    }
};


class Circle {
private:
    const double PI = 3.14;
    double radius;
    double area;
    void calculateArea(){
        area = PI * radius * radius;
    }
public:
    Circle(double _radius = 0)  {
        radius = _radius;
        this->calculateArea();
    }
    void printData() {
        cout << "Radius is " << radius << " and Area is :" << area  << endl;
    }
    void operator |=(const double _rad) {
        this->radius = _rad;
        this->calculateArea();
    }
    void operator +=(const double val) {
        this->radius = this->radius + val;
        this->calculateArea();
    }
    void operator %=(const double _area) {
        this->area = _area;
        this->radius = sqrt(this->area / this->PI);
        this->calculateArea();
    }
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    system("title Operator Example Example with QT C++ - Thecodeprogram");
    cout << "Welcome to Operator Example example with QT C++..." << endl << endl;

    //EXAMPLE OPERATION OF SQUARE CLASS
    cout << "OPERATIN OF SQUARE CLASS...... " << endl;
    Square sq1(50), sq2(90);
    cout << "Area of Square 1 is  ";
    sq1.printArea();
    cout << "Area of Square 2 is  ";
    sq2.printArea();

    //Summarize the areas of both Squares
    Square sq3 = sq1 + sq2;
    cout << "Summarized area is ";
    sq3.printArea();
    cout << endl;

    //EXAMPLE OPERATION OF CIRCLE CLASS
     cout << "OPERATIN OF CIRCLE CLASS...... " << endl;
    Circle circle(10);
    circle.printData();
    circle |= 25;
    circle.printData();
    circle += 33.965;
    circle.printData();
    circle %= 314000;
    circle.printData();

    return a.exec();
}
