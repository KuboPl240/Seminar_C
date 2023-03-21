#pragma once
#include <iostream>
using namespace std;

class matica {
private:
	float** pole;
	int x, y;
public:
	matica(int x, int y) {
		this->x=x;
		this->y=y;
		pole = new float*[y];
		for (int i = 0; i < y; i++) {
			pole[i] = new float[x];
		}
	}
	matica(const matica& a)
	{
		this->x = a.x;
		this->y = a.y;

		pole = new float* [y];
		for (int i = 0; i < y; ++i) {
			pole[i] = new float[x];
		}

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				pole[i][j] = a.pole[i][j];
			}
		}
	}
	matica(const float &cislo) {
		this->x = 1;
		this->y = 1;

		pole = new float* [1];
		pole[0] = new float[1];
		pole[0][0] = cislo;
	}
	float* operator[](int i) const;
	//matica operator+(const matica& a);
	matica& operator=(const matica& a);
	//matica operator+(const double cislo);
	matica operator*(const matica& a);
	matica operator/(const matica& a);
	matica operator-(const matica& a);
	matica& operator-();

	~matica() {
		for(int i =0; i<y;i++) delete[] pole[i];
		delete[] pole;
	}
	void fill(int max);
	friend ostream& operator<<(ostream& out, const matica& a);
	friend matica& operator+(const matica& a, const matica& b);
};