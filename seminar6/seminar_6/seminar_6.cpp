// seminar_6.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include "matica.h"


using namespace std;

int main()
{
    matica A(3, 4), B(3, 4), C(3, 4);
    A.fill(20);
    B.fill(20);
    C.fill(20);

    C = -A+B; //3;// +B[1][2];
    cout << A << endl << B << endl << C << endl;
}

