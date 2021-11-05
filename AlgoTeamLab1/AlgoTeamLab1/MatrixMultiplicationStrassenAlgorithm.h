#pragma once
// Done by Oleksii Adamov
#include "Matrix.h"
#include <cmath>
#include <algorithm>
// next power of two using std::log2 and std::pow
size_t next_pow_of_two(size_t n) {
	size_t exp = (size_t) std::ceil(std::log2(n));
	return (size_t) std::pow(2, exp);
}

// Strassen algorithm for square matricies that have dimensions equal to power of 2 (for performane using const &) O(n^2.8)
template<typename T>
Matrix<T> multiply_Strassen_algo_square_power_of_two(const Matrix<T>& left, const Matrix<T>& right) {
	size_t size = left.get_number_of_rows();
	Matrix<T> ret(size, size);
	if (size == 1) {
		ret[0][0] = left[0][0] * right[0][0];
	}
	else {
		size_t half_size = size / 2;
		Matrix<T> left_1_1(half_size, half_size), left_1_2(half_size, half_size), left_2_1(half_size, half_size), left_2_2(half_size, half_size),
			right_1_1(half_size, half_size), right_1_2(half_size, half_size), right_2_1(half_size, half_size), right_2_2(half_size, half_size),
			result1_1(half_size, half_size), result1_2(half_size, half_size), result2_1(half_size, half_size), result2_2(half_size, half_size);
		// dividing left matrix
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				if (i < half_size && j < half_size) {
					left_1_1[i][j] = left[i][j];
				}
				if (i < half_size && j >= half_size) {
					left_1_2[i][j - half_size] = left[i][j];
				}
				if (i >= half_size && j < half_size) {
					left_2_1[i - half_size][j] = left[i][j];
				}
				if (i >= half_size && j >= half_size) {
					left_2_2[i - half_size][j - half_size] = left[i][j];
				}
			}
		}
		// dividing right matrix
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				if (i < half_size && j < half_size) {
					right_1_1[i][j] = right[i][j];
				}
				if (i < half_size && j >= half_size) {
					right_1_2[i][j - half_size] = right[i][j];
				}
				if (i >= half_size && j < half_size) {
					right_2_1[i - half_size][j] = right[i][j];
				}
				if (i >= half_size && j >= half_size) {
					right_2_2[i - half_size][j - half_size] = right[i][j];
				}
			}
		}

		// 7 multiplications according to algorithm
		Matrix<T> M1 = multiply_Strassen_algo_square_power_of_two<T>(left_1_1 + left_2_2, right_1_1 + right_2_2);
		Matrix<T> M2 = multiply_Strassen_algo_square_power_of_two<T>(left_2_1 + left_2_2, right_1_1);
		Matrix<T> M3 = multiply_Strassen_algo_square_power_of_two<T>(left_1_1, right_1_2 - right_2_2);
		Matrix<T> M4 = multiply_Strassen_algo_square_power_of_two<T>(left_2_2, right_2_1 - right_1_1);
		Matrix<T> M5 = multiply_Strassen_algo_square_power_of_two<T>(left_1_1 + left_1_2, right_2_2);
		Matrix<T> M6 = multiply_Strassen_algo_square_power_of_two<T>(left_2_1 - left_1_1, right_1_1 + right_1_2);
		Matrix<T> M7 = multiply_Strassen_algo_square_power_of_two<T>(left_1_2 - left_2_2, right_2_1 + right_2_2);

		// assigning parts of result according to algorithm
		result1_1 = M1 + M4 - M5 + M7;
		result1_2 = M3 + M5;
		result2_1 = M2 + M4;
		result2_2 = M1 - M2 + M3 + M6;

		// composing result
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size; j++) {
				if (i < half_size && j < half_size) {
					ret[i][j] = result1_1[i][j];
				}
				if (i < half_size && j >= half_size) {
					ret[i][j] = result1_2[i][j - half_size];
				}
				if (i >= half_size && j < half_size) {
					ret[i][j] = result2_1[i - half_size][j];
				}
				if (i >= half_size && j >= half_size) {
					ret[i][j] = result2_2[i - half_size][j - half_size];
				}
			}
		}
	}
	return ret;
}
// Matrix multiplication using Strassen algorithm O(n^2.8)
// checking non-square matricies and matricies that have demensions not equal to power of 2 (using copies to modify if necessary,
// it won't radicly affect performance, because this function will be called once)
template<typename T>
Matrix<T> multiply_Strassen_algo(Matrix<T> left, Matrix<T> right) {
	// check if possible
	if (left.get_number_of_columns() != right.get_number_of_rows()) 
		throw "Matrix multiplication: number of columns of the left matrix is not equal to the number of rows of the right matrix";
	size_t ret_number_of_rows = left.get_number_of_rows(), ret_number_of_columns = right.get_number_of_columns();
	Matrix<T> ret(ret_number_of_rows, ret_number_of_columns);
	// if not square
	if (left.get_number_of_rows() != left.get_number_of_columns()) {
		size_t new_size = std::max(std::max(left.get_number_of_rows(), left.get_number_of_columns()), right.get_number_of_columns());
		left.expand(new_size, new_size);
		right.expand(new_size, new_size);
	}
	
	size_t size = left.get_number_of_rows();
	if (size == 0) {
		return ret;
	}
	// if not power of two
	if ((size & (size - 1)) != 0) {
		size = next_pow_of_two(size);
		left.expand(size, size);
		right.expand(size, size);
	}

	// execute algo for square, power of two matricies
	Matrix<T> raw_ret = multiply_Strassen_algo_square_power_of_two<T>(left, right);

	// copying in ret data - excluding added dimensions
	for (size_t i = 0; i < ret_number_of_rows; i++) {
		for (size_t j = 0; j < ret_number_of_columns; j++) {
			ret[i][j] = raw_ret[i][j];
		}
	}
	return ret;
}