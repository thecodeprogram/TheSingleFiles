/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 04.09.2020
*/


#include <QCoreApplication>
#include <QThread>
#include <iostream>
#include "Windows.h"


using namespace std;



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    system("title How to use Windows API's in QT C++ - Thecodeprogram");
    cout << "Welcome How to use Windows API's in QT C++ Example " << endl << endl;

    HWND window = FindWindowW(NULL, L"exampleText.txt - Not Defteri");

    if (window != 0)
    {
        SetForegroundWindow(window);

        QThread::msleep(1000);

        //First we need to specify the text which will be sent
        std::wstring text = L"Burak Hamdi TUFAN\nthecodeprogram.com\n";
        //Then we are going to create a vector which will contain key inputs
        std::vector<INPUT> vec;

        for(auto ch : text)
        {
            INPUT key_input = { 0 };
            //Make configuations of the key input
            //We specify the every character of the text as unicode keyboard_input
            key_input.type = INPUT_KEYBOARD;
            key_input.ki.dwFlags = KEYEVENTF_UNICODE;
            key_input.ki.wScan = ch;
            vec.push_back(key_input);
        }
        //Lastly we send the characters by same order
        SendInput(vec.size(), vec.data(), sizeof(INPUT));
    }

    return a.exec();
}



