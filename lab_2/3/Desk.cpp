#include <iostream>
#include <vector>
#include "Desk.h"

using namespace std;

Table::Table(int r, int c) : rows(r), cols(c) {
	data.resize(rows);
	
	for (int i = 0; i < rows; i++) {
		data[i].resize(cols);
	}
}

vector<int>& Table::operator[] (int index) {
	return data[index];
}
const vector<int>& Table::operator[] (int index) const {
	return data[index];
}

int Table::GetRows() const{
	return rows;
}
int Table::GetCols() const {
	return cols;
}

void Table::PrintTable() {
	cout << endl << "Table: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << data[i][j] << ' ';
		}
		cout << endl;
	}
}
void Table::PrintElement(int i, int j) {
	cout << "Element [" << i << "] [" << j << "]: " << data[i][j]<< endl;
}
void Table::Average() {
	float sum = 0.0;
	int quantity = rows * cols;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sum += data[i][j];
		}
	}
	float result = sum / quantity;
	cout << "Average: " << result << endl;
}