#pragma once
//Done by Vladyslav Shupliakov
#include "Matrix.h"
#include <utility> 
#include <stdexcept>

//lower–upper (LU) decomposition factors a matrix as the product of a lower triangular matrix and 
//an upper triangular matrix.

//LU Decomposition is done using Doolittle's algorithm.
//const & is used for the better performance
//time complexity for LU-decomposition is O((2/3)n^3)
template<typename T>
std::pair<Matrix<T>, Matrix<T>> LU_decomposition(const Matrix<T>& matrix) {
    //validate the matrix-parameter
    if (matrix == nullptr || (matrix.get_number_of_columns != matrix.get_number_of_rows)) { 
        throw std::invalid_argument("Invalid argument received as a parameter."); 
    }
    size_t size = matrix.get_number_of_rows();

    Matrix<T> lower(size, size);
    Matrix<T> upper(size, size);

    memset(lower, 0, sizeof(lower));
    memset(upper, 0, sizeof(upper));

    //Matrix decomposition into upper and
    //lower triangular matricies
    for (int i = 0; i < n; i++) {
        //upper
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < i; k++) {
                sum += (lower[i][k] * upper[k][j]);
            }
            upper[i][j] = matrix[i][j] - sum;
        }
        //lower
        for (int j = i; j < n; j++) {
            if (i == j) {
                lower[i][i] = 1;
            }
            else {
                int sum = 0;
                for (int k = 0; k < i; k++) {
                    sum += (lower[j][k] * upper[k][i]);
                }
                lower[j][i] = (matrix[j][i] - sum) / upper[i][i];
            }
        }
    }
    return std::make_pair(upper, lower);
}