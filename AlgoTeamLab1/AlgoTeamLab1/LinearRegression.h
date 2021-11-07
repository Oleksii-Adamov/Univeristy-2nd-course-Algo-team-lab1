#pragma once
//Done by Maksym Havrilyuk
#include "Matrix.h"
#include "RationalNum.h"
#include "InverseLUDecomposition.h"
#include <vector>

/*
˳���� ������� ��������������� ��� ���������� �������
������������ �� ��������� �������� ��������� �� �������� ���������� ������
� ���������� ������ Y = XB + C,
�� Y - ������ ������� �������� ������
   � - ������� ������� ���������� ������
   B - ������ �����������
   � - ������ �������� �������
���� - ���������� ������� � �� �������� � �� �
��������������� ����� ��������� ��������:
� = ((X'X)^-1)X'Y
*/
vector<RationalNum> LinearRegression(vector<RationalNum> Y, Matrix<RationalNum> X)
{

}

