#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");
	Matrix a(2,1);
	Matrix b;
	Matrix c;
	// заполнение массива одним значением
	a.randomize(1, 8);
	// заполнение массива случайными числами на интервале [a, b]
	b.randomize(-10,10);
	float determinant = b.detMatr3x3();
	b.transpose();
	c = a * 5;

	float x;
	vector<float> y;
	try {
		//a.diagonal();
		//a += b;
		//b -= a;
		a *= b;
		c = a + b;
		c = a - b;
		c = a * b;
		x = a.get_el(1, 2);
		y = b.get_row(0);
	}
	catch (Matrix::ERRORS e) {
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
