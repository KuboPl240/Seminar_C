#include "pole.h"


using namespace std;
void pole::napln() {
	for (int i = 0; i < pocet; i++)p[i] = rand() % 100;
}

void pole::vypis() {
	for (int i = 0; i < pocet; i++){
		cout << p[i] << ", ";
	}
	cout << "\n";
}

void pole::pricitaj(pole *B) {
	for (int i = 0; i < pocet; i++)p[i] = p[i] + B->p[i];
}

void scitaj(pole *A, pole *B, pole *C){
	for (int i = 0; (i < A->pocet) && (i < B->pocet); i++) {
		C->p[i] = A->p[i] + B->p[i];
	}
}

