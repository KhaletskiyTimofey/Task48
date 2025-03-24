#include "logic.h"

int* find_columns_with_all_even_elements(int** matrix, int row, int column, int& even_columns_count)
{
	even_columns_count = 0;
	int* even_columns = new int[column];
	
	for (int i = 0; i < column; i++)
	{
		bool is_all_elements_even = true;

		for (int j = 0; j < row; j++)
		{
			if (matrix[j][i] % 2 == 1)
			{
				is_all_elements_even = false;
				break;
			}
		}
		if (is_all_elements_even)
		{
			even_columns[even_columns_count] = i + 1;
			even_columns_count++;
		}
	}

	return even_columns;
}