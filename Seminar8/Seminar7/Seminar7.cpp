// Seminar7.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <random>
#include <functional>
#include "LIFO.h"
#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

int main()
{
    LIFO<Osoba> zasobnik(5);
    Osoba osoby[4] = { Osoba(1,"Fero","Hora",123),Osoba(2,"Miso","Gren",234),Osoba(3,"Bob","Smith",455),Osoba(4,"Dorian","White",555) };
    for(int i = 0; i<20; i ++){
        bool operacia = rand() % 2;
        try {
            if (operacia) {
                Osoba os = osoby[rand() % 4 + 0];
                zasobnik.Push(os);
            }
            else {
                cout<<"Zasobnik: "<<zasobnik.Pop()<<"\n";
            }
        }
        catch (const char* chyba) {
           cout << chyba;
        }
        Sleep(100);
    }
}

