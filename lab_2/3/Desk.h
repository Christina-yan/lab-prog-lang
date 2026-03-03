#ifndef DESK_H
#define DESK_H

#include <iostream>
#include <vector>
using namespace std;

class Table {
private:
	vector<vector<int>> data;
	int rows;
	int cols;
public:
	Table(int r, int c);

	vector<int>& operator[] (int index);
	const vector<int>& operator[] (int index) const;

	int GetRows() const;
	int GetCols() const;

	void PrintTable();
	void PrintElement(int i, int j);
	void Average();
};

#endif
