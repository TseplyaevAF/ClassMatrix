#pragma once
#include <vector>

// Синоним для типа двумерный вектор
using vector_float = std::vector <std::vector<float>>;

// Класс Матрица
class Matrix {
	vector_float a; // двумерный массив

public:

	static const short no_access_el = -1;
	static const short no_access_str = -2;

	// Конструкторы
	Matrix();
	Matrix(unsigned count, unsigned column);

	// Доступ к элементам матрицы
	float get_el(unsigned i, unsigned j);

	// Доступ к строкам матрицы
	std::vector <float> get_str(unsigned i);

	// Заполнение матрицы одним значением
	void init_matrix(int num);

	// Заполнение матрицы случайными числами
	void init_matrix();

	// Оператор сложения двух матриц
	Matrix operator + (const Matrix& b) const;

	// Оператор вычитания двух матриц
	Matrix operator - (const Matrix& b) const;

	// Оператор умножения матрицы на число
	Matrix operator * (int num) const;
};