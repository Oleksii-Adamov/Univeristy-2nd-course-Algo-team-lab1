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
vector<RationalNum> LinearRegression(vector<RationalNum> Y, Matrix<RationalNum> X)
{

}

