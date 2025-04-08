#include "logic.h"

int calculate_sum_of_elements(int** matrix, int row, int column, int* columns, int* sum_of_elemnts)
{
	int columns_id = 0;

	for (int i = 0; i < column; i++)
	{
		if (matrix[i][i] < 0)
		{
			columns[columns_id] = i;

			for (int j = 0; j < row; j++)
			{
				if (j > 0)
				{
					sum_of_elemnts[columns_id] += matrix[j][i];
				}
				else
				{
					sum_of_elemnts[columns_id] = matrix[j][i];
				}
			}

			columns_id++;
		}
	}

	return columns_id;
}