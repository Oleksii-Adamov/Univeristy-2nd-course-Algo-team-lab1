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
<<<<<<< HEAD
where Y is the vector of values ​​of dependent variables
   X is a matrix of values ​​of independent variables
   B is the vector of coefficients
   C is the vector of arbitrary errors
=======
where Y is the vector of dependent variables
      X is a matrix of independent variables
      B is the vector of coefficients
      C is the vector of arbitrary errors
>>>>>>> 1d8e8be239fa06e32e4adf4d3b9aaf11ade2da57
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
    //make matrix that starts by [1, ... 1] colum
    Matrix<RationalNum> X_plus(X.get_number_of_rows(), X.get_number_of_columns() + 1);
    for (int i = 0; i < X.get_number_of_rows(); i++)
    {
        X_plus[i][0] = RationalNum(1, 1);
    }

    for (int i = 0; i < X_plus.get_number_of_rows(); i++)
        for (int j = 0; j < X.get_number_of_columns(); j++)
            X_plus[i][j + 1] = X[i][j];


    Matrix<RationalNum> B(X_plus.get_number_of_rows(), X_plus.get_number_of_columns());
    B = X_plus.transpose() * X_plus;
    B = inverse_matrix_lu_decomposition(B);
    B = B * X_plus.transpose();
    B = B * Y;
    return B;
}
