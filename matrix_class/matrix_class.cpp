#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");
	Matrix a;
	Matrix b;
	Matrix c;
	a.init_matrix(2);
	b.init_matrix();

	c = a * 5;

	float x;
	vector<float> y;
	try {
		c = a + b;
		c = a - b;
		c = a * b;
		x = a.get_el(1, 2);
		y = b.get_str(0);
	}
	catch (short e) {
		if (e == Matrix::no_access_el)
			cout << "Элемент не существует!\n";
		if (e == Matrix::no_access_str)
			cout << "Нет доступа к строке!\n";
		if (e == Matrix::row_not_equal_col)
			cout << "Длина строки не равна длине стобцов!\n";
		if (e == Matrix::not_equal_matrix)
			cout << "Матрицы не эквивалентны!\n";
	}

	return 0;
}
