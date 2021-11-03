#include<fstream>
#include<iostream>
#include "RationalNum.h"
#include "Matrix.h"

int main() {
	// strassen algo input ouput, as I remember need to add time measurment
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
		Matrix<RationalNum> c = a * b;
		out << c;
	}
	catch (const char* e) {
		std::cerr << e << std::endl;
		out << e << "\n";
	}
}