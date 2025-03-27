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

	int* columns= new int[column];
	int* sum_of_elemnts = new int[column];
	int size = calculate_sum_of_elements(matrix, row, column, columns, sum_of_elemnts);

	cout << "Columns with negative element on main diagonale: " << array_to_string(columns, size) << endl;
	cout << "Sum of elements in this columns: " << array_to_string(sum_of_elemnts, size) << endl;

	delete_matrix(matrix, row, column);

	return 0;
}