#pragma once
using namespace std;
#include <iostream>
#include <math.h>
# define PI 3.14159265358979323846
class Tvar
{

protected:
	double* pole;
	int pocetStran = 0;

public:
	Tvar(int pocetRozmerov)
	{
		this->pocetStran = pocetRozmerov;
		pole = new double[pocetRozmerov];
	}
	~Tvar()
	{
		delete[] pole;
	}
	virtual void Vykreslenie(void) = 0;
	virtual double Obvod(void) = 0;
	virtual double Obsah(void) = 0;

};

class Obdlznik : public Tvar
{
public:
	Obdlznik(double a, double b) : Tvar(2)
	{
		pole[0] = a;
		pole[1] = b;
	}

	virtual double Obvod();
	virtual double Obsah();
	void Vykreslenie();

};

class Trojuholnik : public Tvar
{
public:
	Trojuholnik(double s1, double s2, double s3) : Tvar(3)
	{
		pole[0] = s1;
		pole[1] = s2;
		pole[2] = s3;
	}

	virtual double Obvod();
	virtual double Obsah();
	virtual void Vykreslenie();

};

class Kruh : public Tvar
{
public:
	Kruh(double r) : Tvar(1)
	{
		pole[0] = r;
	}

	virtual double Obvod();
	virtual double Obsah();
	void Vykreslenie();

};

class Farebny_Obdlznik : public Obdlznik
{

protected:
	string farba = "";
public:
	Farebny_Obdlznik(double a, double b, string farba) : Obdlznik(a, b) {
		this->farba = farba;
	}
	virtual void Vykreslenie();

};

void random(Tvar* tvary[]);
void tried(Tvar* tvary[]);
void vypis(Tvar* tvary[]);
