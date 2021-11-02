#pragma once
template <typename T>
class Matrix {
private:
	T** matrix;
	long long m_number_of_rows;
	long long m_number_of_columns;
public:
	long long get_number_of_rows() {
		return m_number_of_rows;
	}
	long long get_number_of_columns() {
		return m_number_of_columns;
	}
	T*& operator[](long long index) {
		if (index >= m_number_of_rows) throw "Matrix: Index out of range!";
		return matrix[index];
	}
	const T*& operator[](long long index) const {
		if (index >= m_number_of_rows) throw "Matrix: Index out of range!";
		return matrix[index];
	}
	Matrix()
		: m_number_of_rows(0), m_number_of_columns(0)
	{

	}
	Matrix(long long number_of_rows, long long number_of_columns)
		: m_number_of_rows(number_of_rows), m_number_of_columns(number_of_columns)
	{
		matrix = new T * [m_number_of_rows];
		for (long long i = 0; i < m_number_of_rows; i++) {
			matrix[i] = new T[m_number_of_columns];
		}
	}
	~Matrix() {
		for (long long i = 0; i < m_number_of_rows; i++) {
			delete[] matrix[i];
		}
		if (m_number_of_rows > 0)
			delete[] matrix;
	}
};