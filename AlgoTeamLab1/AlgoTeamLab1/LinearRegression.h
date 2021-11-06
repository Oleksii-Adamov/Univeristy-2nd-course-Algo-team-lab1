#pragma once
//Done by Maksym Havrilyuk
#include "Matrix.h"
#include "RationalNum.h"
#include "InverseLUDecomposition.h"
#include <vector>

/*
Лінійна регресія використовується для відновлення лінійного
співвідношення між скалярною залежною величиною та вектором незалежних змінних
В матричному вигляді Y = XB + C,
де Y - вектор значень залежних змінних
   Х - матриця значень незалежних змінних
   B - вектор коефіцієнтів
   С - вектор довільних похибок
Мета - відновлення вектора В за заданими У та Х
Використовується метод найменших квадратів:
В = ((X'X)^-1)X'Y
*/
vector<RationalNum> LinearRegression(vector<RationalNum> Y, Matrix<RationalNum> X)
{

}

