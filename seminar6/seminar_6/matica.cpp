using namespace std;
#include "matica.h"

void matica::fill(int max) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			pole[i][j] = rand() % max;
		}
	}
}
matica& matica::operator=(const matica& a) {
	pole = new float* [a.y];
	for (int i = 0; i < a.y; ++i) {
		pole[i] = new float[a.x];
	}

	this->x = a.x;
	this->y = a.y;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			pole[i][j] = a.pole[i][j];
		}
	}

	return *this;
}
/*matica matica::operator+(const double cislo) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			pole[i][j] += cislo;
		}
	}

	return *this;
}*/
matica matica::operator*(const matica& a) {
	this->x = a.x;
	this->y = a.y;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			pole[i][j] *= a.pole[i][j];
		}
	}

	return *this;
}
matica matica::operator/(const matica& a) {
	this->x = a.x;
	this->y = a.y;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			pole[i][j] /= a.pole[i][j];
		}
	}

	return *this;
}
matica& operator+(const matica& a, const matica& b) {
	matica c(a.x,a.y);

	for (int i = 0; i < a.y; i++) {
		for (int j = 0; j < a.x; j++) {
			if (a.x == 1)c.pole[i][j] = b.pole[i][j] + a.pole[0][0];
			else if (b.x == 1)c.pole[i][j] = a.pole[i][j] + b.pole[0][0];
			else c.pole[i][j] = a.pole[i][j] + b.pole[i][j];
		}
	}

	return c;
}
matica matica::operator-(const matica& a) {
	this->x = a.x;
	this->y = a.y;

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			pole[i][j] -= a.pole[i][j];
		}
	}
	return *this;
}


matica& matica::operator-() {
	matica A(x, y);
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			A.pole[i][j] = -pole[i][j];
		}
	}
	return A;
}

float* matica::operator[](int i) const {
	return pole[i];
}

ostream& operator<<(ostream& out, const matica& a) {
	for (int i = 0; i < a.y; i++) {
		for (int j = 0; j < a.x; j++) {
			out << a.pole[i][j] << " ";
		}
		out << endl;
	}
	return out;
}