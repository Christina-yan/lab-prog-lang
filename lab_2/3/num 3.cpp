//3
//Реализуйте класс Table, который хранит целые числа в двумерной таблице.
//При инициализации Table(rows, cols) экземпляру передаются число строк и столбцов в таблице.
//Строки и столбцы нумеруются с нуля.
// Ячейки таблицы инициализируются нулями.
//Гарантируется, что при работе с вашим классом используются только корректные индексы.

#include <iostream>
#include <vector>
#include "Desk.h"

using namespace std;

int main(){
    Table t(3, 6);

	for (int i = 0; i < t.GetRows(); i++) {
		for (int j = 0; j < t.GetCols(); j++) {
			t[i][j] = i * t.GetCols() + j + 1;
		}
	}
	t.PrintTable();

	t.PrintElement(1, 1);
	t.PrintElement(2, 0);
	t.PrintElement(2, 4);

	cout << "Cols: " << t.GetCols() << endl;
	cout << "Rows: " << t.GetRows() << endl;

	t.Average();
}
