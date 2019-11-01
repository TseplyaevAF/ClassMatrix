#include "matrix.h"
#include <iostream>
#include <ctime>

bool Matrix::proverka(vector_float a, vector_float b) const {
	if (a.size() != b.size()) return 0;
	for (unsigned i = 0; i < a.size(); i++) {
		if (a[i].size() != b[i].size()) return 0;
	}
	return 1;
}

Matrix::Matrix() {
	a.resize(3);
	for (unsigned i = 0; i < a.size(); i++)
	{
		a[i].resize(3);
	}
}

Matrix::Matrix(unsigned count, unsigned column) {
		a.resize(count);
		for (unsigned i = 0; i < a.size(); i++)
		{
			a[i].resize(column);
		}
}

// Доступ к элементам матрицы
float Matrix::get_el(unsigned i, unsigned j) {
	if (i < a.size() && j < a[i].size())
		return a[i][j];
	else
		throw no_access_el;
}

std::vector<float> Matrix::get_str(unsigned i) {
	if (i < a.size()) return a[i]; else
		throw no_access_str;
}

// Заполнение матрицы одним значением
void Matrix::init_matrix(float num) {
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
Matrix Matrix::operator + (const Matrix& b) const {
	if (!proverka(a, b.a)) throw not_equal_matrix;

	Matrix result(a.size(), a[0].size());

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] + b.a[i][j];
		}
	return result;
}

// Оператор вычитания двух матриц
Matrix Matrix::operator - (const Matrix& b) const {
	if (!proverka(a, b.a)) throw not_equal_matrix;

	Matrix result(a.size(), a[0].size());

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] - b.a[i][j];
		}
	return result;
}

// Оператор умножения матрицы на число
Matrix Matrix::operator * (int num) const {
	Matrix result(a.size(), a[0].size());

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] * num;
		}
	return result;
}

Matrix Matrix::operator * (const Matrix& b) const {

	if (a[0].size() != b.a.size()) throw row_not_equal_col;

	Matrix result(a.size(), a[0].size());
	for (unsigned i = 0; i < result.a.size(); i++)
		for (unsigned j = 0; j < result.a[i].size(); j++)
			for (unsigned k = 0; k < a[i].size(); k++)
				result.a[i][j] += a[i][k] * b.a[j][k];
	return result;
}