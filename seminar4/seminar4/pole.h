#pragma once
#include <iostream>

class pole {
	int *p, pocet;

public:
	//konstruktor
	pole(int pocet) {
		p = new int[this->pocet = pocet];
	}

	//konstruktor pre naplnenie pola hodnotou
	pole(int pocet, int data) {
		p = new int[this->pocet = pocet];
		for (int i = 0; i < pocet; i++)p[i] = data;
	}
	 
	//konstruktor priradenie ASCII znakov
	pole(char* string) {
		p = new int[pocet = strlen(string)];
		for (int i = 0;i<pocet ; i++) {
			pocet = i + 1;
			p[i] = (int)string[i];
		}
	}

	//kopirovaci konstruktor
	pole(pole &druhePole) {
		p = new int[pocet = druhePole.pocet];
		for (int i = 0; i < druhePole.pocet; i++)p[i]=druhePole.p[i];
	}

	//destruktor
	~pole() {
		delete[] p;
	}
	//napln random cislami
	void napln();

	//vypis na konzolu
	void vypis();

	//pricitaj druhe pole
	void pricitaj(pole *B);

	//scitaj dve polia
	friend void scitaj(pole *A, pole *B, pole *C);
};
