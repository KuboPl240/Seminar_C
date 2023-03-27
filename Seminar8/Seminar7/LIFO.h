#pragma once
#include <iostream> 
using namespace std;

template<class T> class LIFO {
private:
	T* p;
	int n=0, posledny=0;
public:
	LIFO(int n) {
		this->n = n;
		p = new T[n];
	}
	~LIFO() {
		delete[] p;
	}

	void Push(T& prvok) {
		if (n <= (posledny+1))throw "Zasobnik je plny\n";
	    p[posledny] = prvok;
		posledny++;
	}
	T Pop() {
		if (posledny < 1)throw "Zasobnik je prazdny\n";
		posledny--;
		return p[posledny];
	}
};


class Osoba
{
public:
	int ID = 0;
	string jmeno = "";
	string prijmeni = "";
	long telefon = 0;

	Osoba()
	{
	}
	Osoba(int id)
	{
		this->ID = id;
	}
	Osoba(int id, string jmeno, string prijmeni, long telefon)
	{
		this->ID = id;
		this->jmeno = jmeno;
		this->prijmeni = prijmeni;
		this->telefon = telefon;
	}
	~Osoba()
	{
	}

	void setID(int id) {
		this->ID = id;
	}
	void setJmeno(string jmeno) {
		this->jmeno = jmeno;
	}
	void setPrijmeni(string prijmeni) {
		this->prijmeni = prijmeni;
	}
	void setTelefon(long telefon) {
		this->telefon = telefon;
	}

	friend ostream& operator<<(ostream& out, const Osoba& m);

};
ostream& operator<<(ostream& out, const Osoba& m) {
	out << "[";
	out << m.ID << ",";
	out << m.jmeno << ",";
	out << m.prijmeni << ",";
	out << m.telefon << "]\n";

	return out;
}