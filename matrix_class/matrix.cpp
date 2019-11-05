#include "matrix.h"
#include <iostream>
#include <ctime>

bool Matrix::check(vector_float a, vector_float b) const {
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

// ������ � ��������� �������
float Matrix::get_el(unsigned i, unsigned j) {
	if (i < a.size() && j < a[i].size())
		return a[i][j];
	else
		throw no_access_el;
}

// ������ � ������� �������
std::vector<float> Matrix::get_row(unsigned i) {
	if (i < a.size()) return a[i]; else
		throw no_access_str;
}

// ���������� ������� ����� ���������
void Matrix::randomize(float num) {
	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			a[i][j] = num;
		}
}

// ���������� ������� ���������� �������
// � ��������� [x, y]
void Matrix::randomize(int x, int y) {
	srand(time(NULL));
	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			a[i][j] = rand() % (y - x + 1) + x;

		}
}

// �������� �������� ���� ������
Matrix Matrix::operator + (const Matrix& b) const {
	if (!check(a, b.a)) throw not_equal_matrix;

	Matrix result(a.size(), a[0].size());

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] + b.a[i][j];
		}
	return result;
}

// �������� ��������� ���� ������
Matrix Matrix::operator - (const Matrix& b) const {
	if (!check(a, b.a)) throw not_equal_matrix;

	Matrix result(a.size(), a[0].size());

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] - b.a[i][j];
		}
	return result;
}

// �������� ��������� ������� �� �����
Matrix Matrix::operator * (float num) const {
	Matrix result(a.size(), a[0].size());

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			result.a[i][j] = a[i][j] * num;
		}
	return result;
}

// �������� ��������� ���� ������
Matrix Matrix::operator * (const Matrix& b) const {

	if (a[0].size() != b.a.size()) throw row_not_equal_col;

	Matrix result(a.size(), a[0].size());
	for (unsigned i = 0; i < result.a.size(); i++)
		for (unsigned j = 0; j < result.a[i].size(); j++)
			for (unsigned k = 0; k < a[i].size(); k++)
				result.a[i][j] += a[i][k] * b.a[k][j];
	return result;
}

// ���������������� �������
void Matrix::transpose() {
	float s;
	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = i; j < a[i].size(); j++) {
			s = a[i][j];
			a[i][j] = a[j][i]; //������ => �������
			a[j][i] = s; // ������� => ������
		}
}

// �������� ������������ �������
void Matrix::diagonal() {
	if (a.size() != a[0].size()) throw row_not_equal_col;
	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
			if (i != j) a[i][j] = 0;
}

Matrix& Matrix:: operator += (const Matrix& b) {
	if (!check(a, b.a)) throw not_equal_matrix;

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			a[i][j] += b.a[i][j];
		}
	return *this;
}

Matrix& Matrix::operator -= (const Matrix& b) {
	if (!check(a, b.a)) throw not_equal_matrix;

	for (unsigned i = 0; i < a.size(); i++)
		for (unsigned j = 0; j < a[i].size(); j++)
		{
			a[i][j] -= b.a[i][j];
		}
	return *this;
}

Matrix& Matrix::operator *= (const Matrix& b) {
	if (a[0].size() != b.a.size()) throw row_not_equal_col;

	std::vector<float> y;

	float S, buf;
	for (unsigned i = 0; i < a.size(); i++) {
		y = get_row(i);
		for (unsigned j = 0; j < a[i].size(); j++) {
			S = 0;
			for (unsigned k = 0; k < a[i].size(); k++) {
				S += y[k] * b.a[k][j];
			}
			a[i][j] = S;
		}
	}
	return *this;
}

// ������ ������������ ������� ����������� 3x3
float Matrix::detMatr3x3() {
	float res;

	res = ((a[0][0]*a[1][1]*a[2][2] + a[0][1]*a[1][2]*a[2][0] + a[2][1]*a[1][0]*a[0][2]) //����� � ������
		- (a[2][0]*a[1][1]*a[0][2] + a[1][0]*a[0][1]*a[2][2] + a[2][1]*a[1][2]*a[0][0])); //����� � ������� 
	return res;
}