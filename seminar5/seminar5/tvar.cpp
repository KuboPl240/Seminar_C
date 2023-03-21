#include "tvar.h"

double Trojuholnik::Obvod() {
	return pole[0] + pole[1] + pole[2];
}

double Trojuholnik::Obsah() {
	double vyska = (pole[0] + pole[1] + pole[2]) / 2;
	return sqrt(vyska * (vyska - pole[0]) * (vyska - pole[1]) * (vyska - pole[2]));
}

void Trojuholnik::Vykreslenie() {
	cout << "Pocet stran:" << pocetStran << "\n" << "Obvod:" << Obvod() << "\n" << "Obsah:" << Obsah() << "\n";
}

double Kruh::Obvod() {
	return 2 * PI * pole[0];
}

double Kruh::Obsah() {
	return PI*pole[0]*pole[0];
}

void Kruh::Vykreslenie() {
	cout << "Pocet stran:" << pocetStran << "\n" << "Polomer:" << pole[0] << "\n" << "Obvod:" << Obvod() << "\n" << "Obsah:" << Obsah() << "\n";
}

double Obdlznik::Obvod() {
	return 2 *(pole[0]+pole[1]);
}

double Obdlznik::Obsah() {
	return pole[0]*pole[1];
}

void Obdlznik::Vykreslenie() {
	cout << "Pocet stran:" << pocetStran << "\n" << "Polomer:" << pole[0] << "\n" << "Obvod:" << Obvod() << "\n" << "Obsah:" << Obsah() << "\n";
}

void Farebny_Obdlznik::Vykreslenie() {
		cout <<"Pocet stran:" << pocetStran << "\n" << "Obvod:" << Obvod() << "\n" << "Obsah:" << Obsah() << "\n" <<"Farba:" << farba << "\n";
}

void random(Tvar* tvary[]) {
	for (int i = 0; i < 20; i++) {
		switch (rand() % 4) {
		case 0:
			tvary[i] = new Trojuholnik(rand()%10,rand()%10,rand()%10);
			break;
		case 1:
			tvary[i] = new Kruh(rand() % 10);
			break;
		case 2:
			tvary[i] = new Obdlznik(rand() % 10,rand() % 10);
			break;
		default:
			string farba[3] = {"Cervena","Zelena","Modra"};
			tvary[i] = new Farebny_Obdlznik(rand() % 10,rand() % 10, farba[rand()%3]);
			break;
		}
	}
}

void tried(Tvar* tvary[]) {
	bool zoradene = false;
	while (!zoradene) {
		zoradene = true;
		for (int i = 1; i < 20; i++) {
			if (tvary[i]->Obvod() > tvary[i - 1]->Obvod()) {
				swap(tvary[i], tvary[i - 1]);
				zoradene = false;
			}

		}
	}
}
void vypis(Tvar* tvary[]) {
	for (int i = 0; i < 20; i++) {
		if (typeid (*tvary[i]) == typeid(Trojuholnik))cout << "\nTyp: Trojuhlonik, \n";
		if (typeid (*tvary[i]) == typeid(Obdlznik))cout << "\nTyp: Obdlznik, \n";
		if (typeid (*tvary[i]) == typeid(Kruh))cout << "\nTyp: Kruh, \n";
		if (typeid (*tvary[i]) == typeid(Farebny_Obdlznik))cout << "\nTyp: Farebny_Obdzlnik, \n";
		tvary[i]->Vykreslenie();
	}
}