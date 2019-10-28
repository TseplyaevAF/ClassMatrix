#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	setlocale(0, "RUS");
	Matrix a(2, 3);
	Matrix b(2, 3);
	Matrix c(2, 3);
	a.init_matrix(5);
	b.init_matrix(5);

	c = a + b;
	c = a - b;
	c = a * 5;

	try {
		a.get_el(2, 3);
	}
	catch (short e) {
		if (e == Matrix::no_access_el)
			cout << "Элемент не существует!\n";
	}

	return 0;
}
