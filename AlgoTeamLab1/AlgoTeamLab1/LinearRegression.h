#pragma once
//Done by Maksym Havrilyuk
#include "Matrix.h"
#include "RationalNum.h"
#include "InverseLUDecomposition.h"
#include <vector>



/*
Linear regression is used to restore the linear
the relationship between the scalar dependent quantity and the vector of independent variables
In matrix form Y = XB + C,
where Y is the vector of dependent variables
      X is a matrix of independent variables
      B is the vector of coefficients
      C is the vector of arbitrary errors
The goal is to restore the vector B according to the given Y and X
The least squares method is used:
      T   -1   T
B = (X x X) x X  x Y
*/
Matrix<RationalNum> LinearRegression(Matrix<RationalNum>& Y,Matrix<RationalNum>& X)
{
    //check sizes
    if(Y.get_number_of_rows() != X.get_number_of_rows())
    {
        throw "Y and/or X have different size!";
    }
    Matrix<RationalNum> B(X.get_number_of_rows(), X.get_number_of_columns());
    B = X.transpose() * X;
    B = inverse_matrix_lu_decomposition(B);
    B = B * X.transpose();
    B = B * Y;
    return B;
}
