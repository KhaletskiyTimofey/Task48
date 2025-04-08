#include "utils.h"

void init_matrix(int** matrix, int row, int column, int start, int end)
{
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[column];

		for (int j = 0; j < column; j++)
		{
			matrix[i][j] = rand() % (end - start + 1) + start;
		}
	}
}

string matrix_to_string(int** matrix, int row, int column)
{
	string matrix_string = "";

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix_string += to_string(matrix[i][j]) + " ";
		}

		matrix_string += "\n";
	}

	return matrix_string;
}

void delete_matrix(int** matrix, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}