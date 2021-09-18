/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 18.09.2021
*/

#include <QCoreApplication>

#include <QStack>

#include <iostream>
#include <QDebug>
#include <QList>

using namespace std;



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    system("title QSettings Example with QT C++ - Thecodeprogram");
    cout << "Welcome to QSettings example with QT C++..." << endl << endl;

    QStack<QString> stack;
    stack.push("The");
    stack.push("Code");
    stack.push("Program");
    while (!stack.isEmpty())
        cout << stack.pop().toLatin1().constData() << endl;

    cout << endl;

    QStack<int> stack1;
    QStack<int> stack2;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack2.push(4);
    stack2.push(5);
    stack2.push(6);

    stack1.swap(stack2);

    cout << "After Stack1" << endl;
    while (!stack1.isEmpty())
        cout << stack1.pop() << endl;

    cout << "After Stack2" << endl;
    while (!stack2.isEmpty())
        cout << stack2.pop() << endl;

    cout << endl;

    QStack<QString> s;
    s.push("Burak");
    s.push("Hamdi");
    s.push("Tufan");

    cout << "Number of elements : " << s.size() << endl;
    cout << "Is Empty : " << s.isEmpty() << endl;
    cout << "Is Stack contains -> Burak : " << s.contains("Burak") << endl;
    cout << "Is Stack contains -> The : " << s.contains("The") << endl;
    cout << "Front element : " << s.front().toLatin1().constData() << endl;

    s.clear();
    cout << endl;
    cout << "After clean : " << endl;
    cout << "Number of elements : " << s.size() << endl;
    cout << "Is Empty : " << s.isEmpty() << endl;


    return a.exec();
}
