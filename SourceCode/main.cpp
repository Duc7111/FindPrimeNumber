
#include<iostream>
#include<fstream>
#include<chrono>

#include"Algorithm.h"
#include"DataGenerator.h"

using namespace std;

int main()
{
    //initialization
    int *l = dataGenerator(1000, 9999, 1000), *h = dataGenerator(10000, 99999, 1000);
    chrono::steady_clock::time_point s, e;
    chrono::microseconds d;
    ofstream fout("TestingData.txt", ios_base::trunc);
    fout << "Lower dataset:" << endl;
    for(int i = 0; i < 1000; ++i)
        fout << l[i] << ' ';
    fout << endl << "Higher dataset:" << endl;
    for(int i = 0; i < 1000; ++i)
        fout << h[i] << ' ';
    fout << endl;
    fout.close();
    fout.open("output.txt");

    //lower dataset
    fout << "Lower dataset:" << endl;

    s = chrono::steady_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        bool* arr = Eratosthenes(l[i]);
        delete[] arr;
    }

    e = chrono::high_resolution_clock::now();
    d = chrono::duration_cast<chrono::microseconds>(e - s);
    fout << "Eratosthenes: " << d.count() << " micro seconds" << endl;
    
    
    s = chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        bool* arr = Sundaram(l[i]);
        delete[] arr;
    }

    e = chrono::high_resolution_clock::now();
    d = chrono::duration_cast<chrono::microseconds>(e - s);
    fout << "Sundaram: " << d.count() << " micro seconds" << endl;
    

    s = chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        bool* arr = Atkin(l[i]);
        delete[] arr;
    }

    e = chrono::high_resolution_clock::now();
    d = chrono::duration_cast<chrono::microseconds>(e - s);
    fout << "Atkin: " << d.count() << " micro seconds" << endl;
    
    //higher dataset
    fout << "Higher database:" << endl;

    s = chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        bool* arr = Eratosthenes(h[i]);
        delete[] arr;
    }

    e = chrono::high_resolution_clock::now();
    d = chrono::duration_cast<chrono::microseconds>(e - s);
    fout << "Eratosthenes: " << d.count() << " micro seconds" << endl;
    

    s = chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        bool* arr = Eratosthenes(h[i]);
        delete[] arr;
    }

    e = chrono::high_resolution_clock::now();
    d = chrono::duration_cast<chrono::microseconds>(e - s);
    fout << "Sundaram: " << d.count() << " micro seconds" << endl;
    
    
    s = chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        bool* arr = Atkin(h[i]);
        delete[] arr;
    }

    e = chrono::high_resolution_clock::now();
    d = chrono::duration_cast<chrono::microseconds>(e - s);
    fout << "Atkin: " << d.count() << " micro seconds" << endl;
    
    //clean up
    delete[] l, h;
    fout.close();
    return 0;
}