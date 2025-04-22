#include <time.h>
#include "logic.h"
#include "utils.h"

int main()
{
	srand(time(0));

	int row, column;

	cout << "Enter size of matrix (rows columns): ";
	cin >> row >> column;

	int min_number, max_number;

	cout << "Enter min and max numbers: ";
	cin >> min_number >> max_number;

	int** matrix = new int* [row];

	init_matrix(matrix, row, column, min_number, max_number);

	cout << matrix_to_string(matrix, row, column) << endl;

	int* rows_with_max_similar_elements = new int[row];
	int rows_with_max_similar_elements_count = find_rows_with_max_similar_elements(matrix, row, column, rows_with_max_similar_elements);

	cout << "Rows with max count of similar elements: " << array_to_string(rows_with_max_similar_elements, rows_with_max_similar_elements_count) << endl;

	delete[] rows_with_max_similar_elements;

	delete_matrix(matrix, row, column);

	return 0;
}