#pragma once
#include <vector>

// Синоним для типа двумерный вектор
using vector_int = std::vector <std::vector<int>>;

// Класс Матрица
class Matrix {
	unsigned n, m; // n - число строк, m - число столбцов
	vector_int a; // двумерный массив

public:

	static const short no_access_el = -1;

	// Конструкторы
	Matrix();
	Matrix(unsigned count, unsigned column);

	// Доступ к элементам матрицы
	int get_el(unsigned i, unsigned j);

	// Заполнение матрицы одним значением
	void init_matrix(int num);

	// Заполнение матрицы случайными числами
	void init_matrix();

	// Оператор сложения двух матриц
	Matrix operator + (Matrix& b) const;

	// Оператор вычитания двух матриц
	Matrix operator - (Matrix& b) const;

	// Оператор умножения матрицы на число
	Matrix operator * (int num) const;
};