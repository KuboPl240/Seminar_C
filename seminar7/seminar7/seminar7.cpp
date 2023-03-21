// seminar7.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
#include <iostream>


using namespace std;

template<class T> class Pole {

public:
	T* pole;
	int PocetPrvkov = 0;

	Pole(int pocetPrvkov) {
		pole = new T[pocetPrvkov];
		this->PocetPrvkov = pocetPrvkov;
	}

	Pole(Pole& a) {
		pole = new T[PocetPrvkov = a.PocetPrvkov];
		for (int i = 0; i < PocetPrvkov; i++)pole[i] = a.pole[i];
	}
	~Pole() {
		if (PocetPrvkov == 0)return;
		delete[] pole;
	}
	T& operator[](int i) {
		return pole[i];
	}

	template<class T>friend ostream& operator<<(ostream& out, const Pole<T>& a);

};
template<class T> ostream& operator<<(ostream& out, const Pole<T>& a) {
	for (int i = 0; i < a.PocetPrvkov; i++) out << a.pole[i] << " ,";
	out << "\n";
	return out;
}

class Osoba
{
public:
	int ID = 0;
	string meno = "";
	string priezvisko = "";
	long telefon = 0;

	Osoba()
	{
	}
	Osoba(int ID, string meno, string priezvisko, long telefon)
	{
		this->ID = ID;
		this->meno = meno;
		this->priezvisko = priezvisko;
		this->telefon = telefon;
	}

	void setID(int ID) {
		this->ID = ID;
	}
	void setMeno(string meno) {
		this->meno = meno;
	}
	void setPriezvisko(string priezvisko) {
		this->priezvisko = priezvisko;
	}
	void setTelefon(long telefon) {
		this->telefon = telefon;
	}

	friend ostream& operator<<(ostream& out, const Osoba& osoba);
};

ostream& operator<<(ostream& out, const Osoba& osoba) {
	out << "ID:";
	out << osoba.ID << ",\n Meno:";
	out << osoba.meno << ",\n Priezvisko:";
	out << osoba.priezvisko << ", \n Telefon:";
	out << osoba.telefon << "\n";
	return out;
}
int main()
{
	Pole<int> A(10);
	Pole<Osoba> B(10);
	string jmena[10] = { "Jan","Michal","Pavel","Jakub","Martin","Tomas","Ota","Radek","Zdenek","Radim" };
	string prijmeni[10] = { "Mikulka","Fiala","Roubla","Dohnal","Friedl","Kriz","Korinek","Sedlacek","Drexler","Dedek" };

    for (int i = 0; i < 10; i++) {
		A[i] = i + 1;

		B[i].setID(i+1);
		B[i].setMeno(jmena[rand() % 10]);
		B[i].setPriezvisko(prijmeni[rand() % 10]);
		B[i].setTelefon(420*10^6 + rand() % 100000);
	}


	cout << A << endl << B<< endl << endl;
	system("pause");
	return 0;
}

