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
    size_t size = matrix.get_number_of_rows();;

    Matrix<RationalNum> lower(size, size);
    Matrix<RationalNum> upper(size, size);

    //Matrix decomposition into upper and
    //lower triangular matricies
    for (int i = 0; i < size; i++) {
        //upper
        for (int j = i; j < size; j++) {
            RationalNum sum(0, 1);
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
                RationalNum sum(0, 1);
                for (int k = 0; k < i; k++) {
                    sum += (lower[j][k] * upper[k][i]);
                }
                lower[j][i] = (matrix[j][i] - sum) / upper[i][i];
            }
        }
    }
    return std::make_pair(lower, upper);
}

//function that inverses matrix using lu-decomposition
Matrix<RationalNum> inverse_matrix_lu_decomposition(Matrix<RationalNum>& matrix) {
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
    Matrix<RationalNum> inverse(size, size);

    std::pair<Matrix<RationalNum>, Matrix<RationalNum>> lu_result = LU_decomposition(matrix);
    Matrix<RationalNum> lower = lu_result.first;
    Matrix<RationalNum> upper = lu_result.second;

    Matrix<RationalNum> identity_matrix(size, size);
    Matrix<RationalNum> lower_inverse_matrix(size, size);
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            identity_matrix[row][col] = (row == col) ? RationalNum(1, 1) : RationalNum(0, 1);
            lower_inverse_matrix[row][col] = RationalNum(0, 1);
        }
    }

    //calculating each entry for inverse lower-triangular matrix
    //lower * lower inverse = identity
    for (int col = 0; col < size; col++) {
        for (int row = 0; row < size; row++) {
            RationalNum sum(0, 1);
            for (int i = 0; i < size; i++) {
                if (i != row) {
                    sum += (lower[row][i] * lower_inverse_matrix[i][col]);
                }
            }
            lower_inverse_matrix[row][col] = identity_matrix[row][col] - sum;
            lower_inverse_matrix[row][col] /= lower[row][row];
        }
    }

    //calculating each entry for inverse matrix
    //upper * inverse = lower inverse
    for (int col = 0; col < size; col++) {
        for (int row = size - 1; row >= 0; row--) {
            RationalNum sum(0, 1);
            for (int i = 0; i < size; i++) {
                if (i != row) {
                    sum += (upper[row][i] * inverse[i][col]);
                }
            }
            inverse[row][col] = lower_inverse_matrix[row][col] - sum;
            inverse[row][col] /= upper[row][row];
        }
    }
    return inverse;
}