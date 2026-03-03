#ifndef SEPARATOR_H
#define SEPARATOR_H

#include <iostream>
#include <vector>
using namespace std;

class OddEvenSeparator {

private:
	vector<int> even_numbers;
	vector<int> odd_numbers;
public:
	void AddNumber(int num);
	void Even();
	void Odd();
};

#endif