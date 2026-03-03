#include "Separator.h"
#include <vector>

using namespace std;

void OddEvenSeparator::AddNumber(int num) {
	if (num % 2 == 0) {
		even_numbers.push_back(num);
	}
	else {
		odd_numbers.push_back(num);
	}
}
void OddEvenSeparator::Even() {
	cout << endl << "Even numbers:" << endl;
	for (int v_num : even_numbers) {
		cout << v_num << " ";
	}
}
void OddEvenSeparator::Odd() {
	cout << endl << "Odd numbers:" << endl;
	for (int v_num : odd_numbers) {
		cout << v_num << " ";
	}
}