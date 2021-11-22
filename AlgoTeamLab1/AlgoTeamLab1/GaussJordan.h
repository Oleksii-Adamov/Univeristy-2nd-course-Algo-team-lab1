#pragma once
#include <iostream>
#include "Matrix.h"
#include "RationalNum.h"
using namespace std;

//Algorithm used for finding determinant of the matrix 
RationalNum FindDet(size_t size, Matrix<RationalNum> matrix)
{
	size_t subi, subj, n = size;
	Matrix<RationalNum> Subm(n, n);
	size = matrix.get_number_of_rows();
	RationalNum det = RationalNum(0, 1);

	if (size == 2)
	{
		return((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	}
	else
	{
		for (size_t c = 0; c < n; c++)
		{
			subi = 0;
			for (size_t i = 1; i < n; i++)
			{
				subj = 0;
				for (size_t j = 0; j < n; j++)
				{
					if (j == c)
					{
						continue;
					}
					Subm[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + RationalNum(pow(-1, c), 1) * matrix[0][c] * FindDet(n - 1, Subm);
		}
	}
	return det;
}



//Gauss - Jordan algorithm for finding inverted matrixes, time complexity is O(n^3)
Matrix<RationalNum> Gaus_Jordan_inverse_matrix(Matrix<RationalNum> Matrix_to_invert) {
	//Checking whether the matrix is square
	if (Matrix_to_invert.get_number_of_columns() != Matrix_to_invert.get_number_of_rows()) {
		cout << "The matrix isn't square";
		exit(0);
	}
	size_t size = Matrix_to_invert.get_number_of_rows();

	//Checking whether the matrix is degenerate
	RationalNum det = FindDet(size, Matrix_to_invert);
	if (det == RationalNum(0, 1))
	{
		cout << "The matrix is degenerate";
		exit(0);
	}

	Matrix_to_invert.expand(size, 2 * size);
	RationalNum ratio;
	// Augmenting Identity Matrix of Order size 
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (i == j)
			{
				Matrix_to_invert[i][j + size] = RationalNum(1, 1);
			}
			else
			{
				Matrix_to_invert[i][j + size] = RationalNum(0, 1);
			}
		}
	}

	// Applying Gauss Jordan Elimination 
	for (size_t i = 0; i < size; i++)
	{
		if (Matrix_to_invert[i][i] == RationalNum(0, 1))
		{
			cout << "Mathematical Error!";
			exit(0);
		}
		for (size_t j = 0; j < size; j++)
		{
			if (i != j)
			{
				ratio = Matrix_to_invert[j][i] / Matrix_to_invert[i][i];
				for (size_t k = 0; k < 2 * size; k++)
				{
					Matrix_to_invert[j][k] = Matrix_to_invert[j][k] - ratio * Matrix_to_invert[i][k];
				}
			}
		}
	}

	// Row Operation to Make Principal Diagonal to 1 
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size; j < 2 * size; j++)
		{
			Matrix_to_invert[i][j] = Matrix_to_invert[i][j] / Matrix_to_invert[i][i];
		}
	}

	// taking result out of right matrix
	Matrix<RationalNum> ret_matrix(size, size);

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = size; j < 2 * size; j++)
		{
			ret_matrix[i][j - size] = Matrix_to_invert[i][j];
		}
	}

	return ret_matrix;

}

