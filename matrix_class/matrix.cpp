#include "matrix.h"
#include <iostream>
#include <ctime>

Matrix::Matrix() {
	n = 3;
	m = 3;
	a.resize(n);
	for (unsigned i = 0; i < a.size(); i++)
	{
		a[i].resize(m);
	}
}

Matrix::Matrix(unsigned count, unsigned column) {
		n = count;
		m = column;
		a.resize(n);
		for (unsigned i = 0; i < a.size(); i++)
		{
			a[i].resize(m);
		}
}

// Доступ к элементам матрицы
int Matrix::get_el(unsigned i, unsigned j) {
	if (i < m && j < n)
		return a[i][j];
	else
		throw Matrix::no_access_el;
}

// Заполнение матрицы одним значением
void Matrix::init_matrix(int num) {
	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			a[i][j] = num;
		}
}

// Заполнение матрицы случайными числами
void Matrix::init_matrix() {
	srand(time(NULL));
	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			a[i][j] = rand() % 50 + 1;
		}
}

// Оператор сложения двух матриц
Matrix Matrix::operator + (Matrix& b) const {
	Matrix result(n, m);

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] + b.a[i][j];
		}
	return result;
}

// Оператор вычитания двух матриц
Matrix Matrix::operator - (Matrix& b) const {
	Matrix result(n, m);

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] - b.a[i][j];
		}
	return result;
}

// Оператор умножения матрицы на число
Matrix Matrix::operator * (int num) const {
	Matrix result(n, m);

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] * num;
		}
	return result;
}