#include "logic.h"

int find_columns_with_elements_less_than_n(int** matrix, int row, int column, int n, int* columns)
{
	int columns_id = 0;

	for (int i = 0; i < column; i++)
	{
		bool is_all_elements_less_than_n = true;

		for (int j = 0; j < row; j++)
		{
			if (abs(matrix[j][i]) >= n)
			{
				is_all_elements_less_than_n = false;
				break;
			}
		}
		if (is_all_elements_less_than_n)
		{
			columns[columns_id] = i;
			columns_id++;
		}
	}

	return columns_id;
}

int find_column_with_min_multiply_of_elenents(int** matrix, int row, int column, int n)
{
	int* columns = new int[column];
	int size = find_columns_with_elements_less_than_n(matrix, row, column, n, columns);

	if (size == 0)
	{
		return -1;
	}

	int min_mult = INT_MAX;
	int min_mult_column = 0;

	for (int i = 0; i < size; i++)
	{
		int mult = 1;

		for (int j = 0; j < row; j++)
		{
			mult *= matrix[j][columns[i]];
		}
		if (mult < min_mult)
		{
			min_mult = mult;
			min_mult_column = columns[i];
		}
	}

	return min_mult_column;
}