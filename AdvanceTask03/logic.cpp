#include "logic.h"

int count_similar_elements(int* row_elements, int column)
{
	int max_similar_elements = 1;
	int similar_elements = 1;

	for (int i = 1; i < column; i++)
	{
		if (row_elements[i] == row_elements[i - 1])
		{
			similar_elements++;

			if (similar_elements > max_similar_elements)
			{
				max_similar_elements = similar_elements;
			}
		}
		else
		{
			similar_elements = 1;
		}
	}

	return max_similar_elements;
}

int calculate_similar_elements_in_rows(int** matrix, int row, int column, int* similar_elements_in_rows)
{
	int max_similar_element = 0;
	
	for (int i = 0; i < row; i++)
	{
		int similar_elements_count = count_similar_elements(matrix[i], column);
		similar_elements_in_rows[i] = similar_elements_count;

		if (similar_elements_count > max_similar_element)
		{
			max_similar_element = similar_elements_count;
		}
	}

	return max_similar_element;
}

int find_rows_with_max_similar_elements(int** matrix, int row, int column, int* rows_with_max_similar_elements)
{
	int* similar_elements_in_rows = new int[row];
	int max_similar_element = calculate_similar_elements_in_rows(matrix, row, column, similar_elements_in_rows);
	int rows_with_max_similar_elements_count = 0;

	for (int i = 0; i < row; i++)
	{
		if (similar_elements_in_rows[i] == max_similar_element)
		{
			rows_with_max_similar_elements[rows_with_max_similar_elements_count] = i;
			rows_with_max_similar_elements_count++;
		}
	}

	delete[] similar_elements_in_rows;

	return rows_with_max_similar_elements_count;
}