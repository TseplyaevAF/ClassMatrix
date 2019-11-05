#pragma once
#include <vector>

// Синоним для типа двумерный вектор
using vector_float = std::vector <std::vector<float>>;

// Класс Матрица
class Matrix {
	vector_float a; // двумерный массив
	// проверка матриц на эквивалентность
	bool check(vector_float a, vector_float b) const;

public:

	static const short no_access_el = -1;
	static const short no_access_str = -2;
	static const short row_not_equal_col = -3;
	static const short not_equal_matrix = -4;

	// Конструкторы
	Matrix();
	Matrix(unsigned count, unsigned column);

	// Доступ к элементам матрицы
	float get_el(unsigned i, unsigned j);

	// Доступ к строкам матрицы
	std::vector <float> get_row(unsigned i);

	// Заполнение матрицы одним значением
	void randomize(float num);

	// Заполнение матрицы случайными числами
	void randomize(int x, int y);

	// Оператор сложения двух матриц
	Matrix operator + (const Matrix& b) const;

	// Оператор вычитания двух матриц
	Matrix operator - (const Matrix& b) const;

	// Оператор умножения матрицы на число
	Matrix operator * (float num) const;

	// Оператор умножения двух матриц
	Matrix operator * (const Matrix& b) const;

	// Транспонирование матрицы
	void transpose();

	// Создание диагональной матрицы
	void diagonal();

	Matrix& operator += (const Matrix& b);
	Matrix& operator -= (const Matrix& b);
	Matrix& operator *= (const Matrix& b);
	float detMatr3x3(); // Определитель матрицы 3 на 3
};