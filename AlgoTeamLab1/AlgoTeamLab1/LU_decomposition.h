#pragma once
//Done by Vladyslav Shupliakov
#include "Matrix.h"
#include "RationalNum.h"
#include <utility> 
#include <stdexcept>

//lower–upper (LU) decomposition factors a matrix as the product of a lower triangular matrix and 
//an upper triangular matrix.

//LU Decomposition is done using Doolittle's algorithm.
//const & is used for the better performance
//time complexity for LU-decomposition is O((2/3)n^3)
std::pair<Matrix<RationalNum>, Matrix<RationalNum>> LU_decomposition(const Matrix<RationalNum>& matrix) {
    size_t rows_num = matrix.get_number_of_rows();
    size_t columns_num = matrix.get_number_of_columns();

    //validate the parameters
    if (rows_num != columns_num) {
        throw std::invalid_argument("Invalid argument received as a parameter.");
    }
    if (rows_num == 0 || columns_num == 0) {
        throw std::invalid_argument("Invalid argument received as a parameter.");
    }
    size_t size = rows_num;

    Matrix<RationalNum> lower(size, size);
    Matrix<RationalNum> upper(size, size);

    //Matrix decomposition into upper and
    //lower triangular matricies
    RationalNum sum(0, 1);
    for (int i = 0; i < size; i++) {
        //upper
        for (int j = i; j < size; j++) {
            for (int k = 0; k < i; k++) {
                sum += (lower[i][k] * upper[k][j]);
            }
            upper[i][j] = matrix[i][j] - sum;
        }
        //lower
        for (int j = i; j < size; j++) {
            if (i == j) {
                lower[i][i] = RationalNum(1, 1);
            }
            else {
                sum = RationalNum(0, 1);
                for (int k = 0; k < i; k++) {
                    sum += (lower[j][k] * upper[k][i]);
                }
                lower[j][i] = (matrix[j][i] - sum) / upper[i][i];
            }
        }
    }
    return std::make_pair(lower, upper);
}