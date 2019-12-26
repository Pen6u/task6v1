#include <iostream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;

void MatrixCreation(int**& matrix, int rows, int columns);
void Input(int**& matrix, int rows, int columns);
int IincreasingRows(int** matrix, int rows);

int main() {
	SetConsoleOutputCP(1251);
	int rows;
	int columns;
	cout << "Введите размерность: ";
	cin >> rows;
	columns = rows;
	int** matrix;
	MatrixCreation(matrix, rows, columns);
	Input(matrix, rows, columns);
	cout << "Колличество отсортированных строк: " << IincreasingRows(matrix, rows) << endl;
	system("PAUSE");
	return 0;
}

void MatrixCreation(int**& matrix, int rows, int columns) {
	matrix = new int* [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
	}
}

void Input(int**& matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << "[" << i + 1 << "]" << "[" << j + 1 << "] ";
			cin >> matrix[i][j];
		}
	}
}

int IincreasingRows(int** matrix, int rows) {
	int amount = 0;
	//int count = 0;
	for (int i = 0; i < rows; i++) {
		int j;	
		for (j = 0; j < rows-1; j++) {
			if (matrix[i][j] >= matrix[i][j+1]) {
				break;
			}
		}
		if (j == rows - 1 ) {
				amount++;
		}
	}
	return amount;
}