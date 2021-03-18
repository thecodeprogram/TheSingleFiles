/*
This File Created
By: Burak Hamdi TUFAN
On: https://thecodeprogram.com/
At: 18.03.2021
*/


#include <iostream>
using namespace std;

//auto örneği
void autoSinifi()
{
    cout << "Auto Sınıfı kullanımı " << endl;
 
    auto sayi = 14;
    auto sayi2 = 67.9;
    auto yazi = "Thecodeprogram";
 
    cout << sayi  << " \n";
    cout << sayi2  << " \n";
    cout << yazi << " \n";

    sayi = 123.456;

    cout << sayi  << " \n";
}
 


// extern örneği
int i;
void externSinifi()
{
    cout << "extern sınıfı örneği" << endl;
 
    // değişken extern yapılıyor
    extern int i;
 
    cout << " Extern i : " << i << endl;

    // değer atanıyor
    i = 33;
 
    cout << "Değer atanmış i : "  << i << endl;
}

//Register Örneği
void registerSinifi()
{
    cout << "Register sınıfı örneği" << endl;
 
    register int sayi = 33;
 
    cout << "Tanımlanan değer : " << sayi << endl;
    cout << "Adresi : " << &sayi << endl;
}

//Static örneği
static int degisken = 33;

static int staticMetod()
{
    cout << "Static metod : " << endl;
    
    static int deger = 0;
    return deger;
}
 
//Mutable örneği
class TestSinifi {
public:
    int sayi;
    mutable int mutable_sayi;
 
    TestSinifi()
    {
        sayi = 123;
        mutable_sayi = 33;
    }
};
 

int main()
{
    autoSinifi();
    externSinifi();
    registerSinifi();
    cout << "Static degisken : " << staticMetod() << endl;
    cout << "Static degisken : " << degisken << endl;


    const TestSinifi testSinifi;
 
    
    testSinifi.mutable_sayi = 41;
    cout << "Mutable sayi : " << testSinifi.mutable_sayi << endl;
 
    // aşağıdaki kod bloğu çalışmayacaktır.
    // t1.sayi = 63;
    
    cout << "Mutable olmayan sayi : " << testSinifi.sayi << endl;

    return 0;
}