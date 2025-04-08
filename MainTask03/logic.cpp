#include "logic.h"

int find_rows_with_all_odd_elements(int** matrix, int row, int column, int* rows_with_all_odd_elements)
{
	int rows_id = 0;

	for (int i = 0; i < row; i++)
	{
		bool isAllElementsOdd = true;

		for (int j = 0; j < column; j++)
		{
			if (matrix[i][j] % 2 == 0)
			{
				isAllElementsOdd = false;
				break;
			}
		}
		if (isAllElementsOdd)
		{
			rows_with_all_odd_elements[rows_id] = i;
			rows_id++;
		}
	}

	return rows_id;
}

int find_row_with_max_sum(int** matrix, int row, int column)
{
	int* rows_with_all_odd_elements = new int[row];
	int size = find_rows_with_all_odd_elements(matrix, row, column, rows_with_all_odd_elements);

	if (size == 0)
	{
		return -1;
	}

	int max_sum = 0;
	int max_sum_row = 0;

	for (int i = 0; i < size; i++)
	{
		int sum = 0;

		for (int j = 0; j < column; j++)
		{
			sum += abs(matrix[rows_with_all_odd_elements[i]][j]);
		}
		if (sum > max_sum)
		{
			max_sum = sum;
			max_sum_row = rows_with_all_odd_elements[i];
		}
	}

	delete[] rows_with_all_odd_elements;

	return max_sum_row;
}