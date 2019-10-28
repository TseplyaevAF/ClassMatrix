#pragma once
#include <vector>

// ������� ��� ���� ��������� ������
using vector_int = std::vector <std::vector<int>>;

// ����� �������
class Matrix {
	unsigned n, m; // n - ����� �����, m - ����� ��������
	vector_int a; // ��������� ������

public:

	static const short no_access_el = -1;

	// ������������
	Matrix();
	Matrix(unsigned count, unsigned column);

	// ������ � ��������� �������
	int get_el(unsigned i, unsigned j);

	// ���������� ������� ����� ���������
	void init_matrix(int num);

	// ���������� ������� ���������� �������
	void init_matrix();

	// �������� �������� ���� ������
	Matrix operator + (Matrix& b) const;

	// �������� ��������� ���� ������
	Matrix operator - (Matrix& b) const;

	// �������� ��������� ������� �� �����
	Matrix operator * (int num) const;
};