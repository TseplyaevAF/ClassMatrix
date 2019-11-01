#pragma once
#include <vector>

// ������� ��� ���� ��������� ������
using vector_float = std::vector <std::vector<float>>;

// ����� �������
class Matrix {
	vector_float a; // ��������� ������

public:

	static const short no_access_el = -1;
	static const short no_access_str = -2;

	// ������������
	Matrix();
	Matrix(unsigned count, unsigned column);

	// ������ � ��������� �������
	float get_el(unsigned i, unsigned j);

	// ������ � ������� �������
	std::vector <float> get_str(unsigned i);

	// ���������� ������� ����� ���������
	void init_matrix(int num);

	// ���������� ������� ���������� �������
	void init_matrix();

	// �������� �������� ���� ������
	Matrix operator + (const Matrix& b) const;

	// �������� ��������� ���� ������
	Matrix operator - (const Matrix& b) const;

	// �������� ��������� ������� �� �����
	Matrix operator * (int num) const;
};