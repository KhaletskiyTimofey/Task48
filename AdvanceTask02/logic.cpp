#include "logic.h"

bool is_element_non_single(int** matrix, int row, int column, int element_i, int element_j)
{
	int element = matrix[element_i][element_j];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if ((element_i != i || element_j != j) && matrix[i][j] == element)
			{
				return true;
			}
		}
	}

	return false;
}

bool is_element_not_in_array(int* non_single_elements, int non_single_elements_count, int element)
{
	for (int i = 0; i < non_single_elements_count; i++)
	{
		if (non_single_elements[i] == element)
		{
			return false;
		}
	}

	return true;
}

int find_non_single_elements(int** matrix, int row, int column, int* non_single_elements)
{
	int non_single_elements_count = 0;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (is_element_not_in_array(non_single_elements, non_single_elements_count, matrix[i][j]) 
				&& is_element_non_single(matrix, row, column, i, j))
			{
				non_single_elements[non_single_elements_count] = matrix[i][j];
				non_single_elements_count++;
			}
		}
	}

	return non_single_elements_count;
}

int find_max_non_single_element(int** matrix, int row, int column)
{
	int* non_single_elements = new int[row * column / 2];
	int non_single_elements_count = find_non_single_elements(matrix, row, column, non_single_elements);
	int max;

	if (non_single_elements_count > 0)
	{
		max = non_single_elements[0];

		for (int i = 1; i < non_single_elements_count; i++)
		{
			if (non_single_elements[i] > max)
			{
				max = non_single_elements[i];
			}
		}
	}
	else
	{
		max = 0;
	}

	delete[] non_single_elements;

	return max;
}