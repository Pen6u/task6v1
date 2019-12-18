#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

int** MatrixCreation(int rows, int columns);
void Input(int** matrix, int rows, int columns);
int IincreasingRows(int** matrix, int rows);

int main() {
	SetConsoleOutputCP(1251);
	int rows;
	int columns;
	cout << "Введите размерность: ";
	cin >> rows;
	columns = rows;
	int** matrix = MatrixCreation(rows, columns);
	Input(matrix, rows, columns);
	cout << "Колличество отортированных строк: " << IincreasingRows(matrix, rows) << endl;
	system("PAUSE");
	return 0;
}

int** MatrixCreation(int rows, int columns) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}
	return matrix;
}

void Input(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "[" << i + 1 << "]" << "[" << j + 1 << "] ";
			cin >> matrix[i][j];
		}
	}
}

int IincreasingRows(int** matrix, int rows) {
	int count = 0;
	for (int i = 0; i < rows - 1; i++) {
		if (matrix[i] < matrix[i + 1]) {
			count++;
		}
	}
	return count;
}