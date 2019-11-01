#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");
	Matrix a(2, 3);
	Matrix b(2, 3);
	Matrix c(2, 3);
	a.init_matrix(7);
	b.init_matrix();

	c = a + b;
	c = a - b;
	c = a * 5;
	float x;
	vector<float> y;
	try {
		x = a.get_el(2, 5);
	}
	catch (short e) {
		if (e == Matrix::no_access_el)
			cout << "Элемент не существует!\n";
	}

	try {
		y = b.get_str(0);
	}
	catch (short e) {
		if (e == Matrix::no_access_str)
			cout << "Нет доступа к строке!\n";
	}

	return 0;
}
