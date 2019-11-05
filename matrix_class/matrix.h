#pragma once
#include <vector>

// ������� ��� ���� ��������� ������
using vector_float = std::vector <std::vector<float>>;

// ����� �������
class Matrix {
	vector_float a; // ��������� ������
	// �������� ������ �� ���������������
	bool check(vector_float a, vector_float b) const;

public:

	// ����������
	enum ERRORS{
		no_access_el = -1,
		no_access_str = -2,
		row_not_equal_col = -3,
		not_equal_matrix = -4,
	};

	// ������������
	Matrix();
	Matrix(unsigned count, unsigned column);

	// ������ � ��������� �������
	float get_el(unsigned i, unsigned j);

	// ������ � ������� �������
	std::vector <float> get_row(unsigned i);

	// ���������� ������� ����� ���������
	void randomize(float num);

	// ���������� ������� ���������� �������
	void randomize(int x, int y);

	// �������� �������� ���� ������
	Matrix operator + (const Matrix& b) const;

	// �������� ��������� ���� ������
	Matrix operator - (const Matrix& b) const;

	// �������� ��������� ������� �� �����
	Matrix operator * (float num) const;

	// �������� ��������� ���� ������
	Matrix operator * (const Matrix& b) const;

	// ���������������� �������
	void transpose();

	// �������� ������������ �������
	void diagonal();

	Matrix& operator += (const Matrix& b);
	Matrix& operator -= (const Matrix& b);
	Matrix& operator *= (const Matrix& b);
	float detMatr3x3(); // ������������ ������� 3 �� 3
};