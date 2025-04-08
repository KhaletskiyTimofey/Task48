#include "logic.h"

int count_columns_without_zero_elements(int** matrix, int row, int column)
{
	int column_count = 0;

	for (int i = 0; i < column; i++)
	{
		bool is_no_zero_elements = true;

		for (int j = 0; j < row; j++)
		{
			if (matrix[j][i] == 0)
			{
				is_no_zero_elements = false;
				break;
			}
		}
		if (is_no_zero_elements)
		{
			column_count++;
		}
	}

	return column_count;
}