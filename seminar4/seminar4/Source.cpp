#include "pole.h"
#include <iostream>

using namespace std;
int main() {
	char string[5] = "Test";
	pole poleA = (10), poleB(10,99);
	pole *poleC = new pole(string);
	pole poleD(poleA);
	poleA.napln();
	poleA.vypis();
	poleA.pricitaj(&poleB);
	poleB.vypis();
	poleC->vypis();
	poleD.vypis();
	delete poleC;
	return 0;
}