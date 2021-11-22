#include <fstream>
#include <iostream>
#include <chrono>
#include <utility>
#include "RationalNum.h"
#include "Matrix.h"
#include "InverseLUDecomposition.h"
#include "LinearRegression.h"
#include "GaussJordan.h"

int main() {
	// strassen algo input ouput, with time measurment
	std::ifstream in("strassen_algo_input.txt");
	std::ofstream out("strassen_algo_output.txt");
	try {
		size_t a_number_of_rows, a_number_of_columns;
		in >> a_number_of_rows >> a_number_of_columns;
		Matrix<RationalNum> a(a_number_of_rows, a_number_of_columns);
		in >> a;
		size_t b_number_of_rows, b_number_of_columns;
		in >> b_number_of_rows >> b_number_of_columns;
		Matrix<RationalNum> b(b_number_of_rows, b_number_of_columns);
		in >> b;
		auto start = std::chrono::high_resolution_clock::now();
		Matrix<RationalNum> c = a * b;
		auto end = std::chrono::high_resolution_clock::now();
		out << c;
		out << "Multiplication has been done for " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() * 0.001 << " milliseconds\n";
	}
	catch (const char* e) {
		std::cerr << e << std::endl;
		out << e << "\n";
	}

	//LU-decomposition file input/output
	//microbenchmarking with std::chrono::high_resolution_clock
	std::ifstream lu_decomposition_in("lu_decomposition_input.txt");
	std::ofstream lu_decomposition_out("lu_decomposition_output.txt");
	try {
		size_t input_number_of_rows, input_number_of_columns;
		lu_decomposition_in >> input_number_of_rows >> input_number_of_columns;
		Matrix<RationalNum> input_matrix(input_number_of_rows, input_number_of_columns);
		lu_decomposition_in >> input_matrix;

		auto start = std::chrono::high_resolution_clock::now();
		Matrix<RationalNum> inverse_matrix_lu_result = inverse_matrix_lu_decomposition(input_matrix);
		auto end = std::chrono::high_resolution_clock::now();

		std::pair<Matrix<RationalNum>, Matrix<RationalNum>> decomposed = LU_decomposition(input_matrix);

		lu_decomposition_out << "Lower decomposed: \n" << decomposed.first << '\n';
		lu_decomposition_out << "Upper decomposed: \n" << decomposed.second << '\n';
		lu_decomposition_out << "Inverse matrix: \n" << inverse_matrix_lu_result << '\n';
		lu_decomposition_out << "Benchmark for inversing matrix using LU-decomposition: "
			                 << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() * 0.001
			                 << " milliseconds\n";
	}
	catch (const char* e) {
		std::cerr << e << std::endl;
		lu_decomposition_out << e << "\n";
	}

	//LinearRegression input/otput
	std::ifstream regression_input_Y("linear_regression_input_Y.txt");
    std::ifstream regression_input_X("linear_regression_input_X.txt");
	std::ofstream regression_out("linear_regression_output.txt");
    try
    {
        size_t linear_number_rows, linear_number_colums;
        regression_input_X >> linear_number_rows >> linear_number_colums;
        Matrix<RationalNum> Y(linear_number_rows, 1);
        Matrix<RationalNum> X(linear_number_rows, linear_number_colums);
        Matrix<RationalNum> B(linear_number_rows, 1);
        regression_input_Y >> Y;
        regression_input_X >> X;

        auto start = std::chrono::high_resolution_clock::now();
        B = LinearRegression(Y, X);
        auto end = std::chrono::high_resolution_clock::now();

        for(int i = 0; i < B.get_number_of_rows(); i++){
            regression_out << "b" << i << ": "<< B[i][0] << std::endl;
        }
		regression_out << "y = " << B[0][0];
		for (int i = 1; i < B.get_number_of_rows(); i++) {
			regression_out << " + (" << B[i][0] << ")x" << i;
		}
        regression_out << "\nLinear Regression has been done for " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() * 0.001 << " milliseconds\n";
    }
    catch (const char* e)
    {
        std::cerr << e << std::endl;
        regression_out << e << std::endl;
    }

	std::ifstream GJ_in("gauss_jordan_input.txt");
	std::ofstream GJ_out("gauss_jordan_output.txt");
	try {
		size_t gj_number_of_rows, gj_number_of_columns;
		GJ_in >> gj_number_of_rows >> gj_number_of_columns;
		Matrix<RationalNum> gj(gj_number_of_rows, gj_number_of_columns);
		GJ_in >> gj;
		auto start = std::chrono::high_resolution_clock::now();
		Matrix<RationalNum> inv = Gaus_Jordan_inverse_matrix(gj);
		auto end = std::chrono::high_resolution_clock::now();
		GJ_out << inv;
		GJ_out << "Matrix inverted for " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() * 0.001 << " milliseconds\n";
	}
	catch (const char* e) {
		std::cerr << e << std::endl;
		GJ_out << e << "\n";
	}
}
