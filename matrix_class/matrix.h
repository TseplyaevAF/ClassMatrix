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

	static const short no_access_el = -1;
	static const short no_access_str = -2;
	static const short row_not_equal_col = -3;
	static const short not_equal_matrix = -4;

	// ������������
	Matrix();
	Matrix(unsigned count, unsigned column);

	// ������ � ��������� �������
	float get_el(unsigned i, unsigned j);

	// ������ � ������� �������
	std::vector <float> get_str(unsigned i);

	// ���������� ������� ����� ���������
	void init_matrix(float num);

	// ���������� ������� ���������� �������
	void init_matrix(int x, int y);

	// �������� �������� ���� ������
	Matrix operator + (const Matrix& b) const;

	// �������� ��������� ���� ������
	Matrix operator - (const Matrix& b) const;

	// �������� ��������� ������� �� �����
	Matrix operator * (int num) const;

	// �������� ��������� ���� ������
	Matrix operator * (const Matrix& b) const;

	// ���������������� �������
	void transpose();

	// �������� ������������ �������
	void diagonal();

	Matrix& operator += (const Matrix& b);
	Matrix& operator -= (const Matrix& b);
	Matrix& operator *= (const Matrix& b);
};