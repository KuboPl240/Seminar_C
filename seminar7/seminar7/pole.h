#pragma once
#include "pole.cpp"

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

	template<class T>friend ostream& operator<<(ostream& out, const Pole<T> &a);

};




