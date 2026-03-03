//Напишите класс OddEvenSeparator, в который можно добавлять числа, получая потом отдельно чётные и нечётные.
//Числа добавляются в объект с помощью метода add_number.
//Методы even и odd должны печатать на экране списки чётных и нечётных чисел соответственно.
//Числа должны идти в том же порядке, что и при добавлении в объект.



#include "Separator.h"
#include <iostream>

using namespace std;

int main(){
	OddEvenSeparator os;

	os.AddNumber(45);
	os.AddNumber(23);
	os.AddNumber(2);
	os.AddNumber(5);
	os.AddNumber(3);
	os.AddNumber(56);
	os.AddNumber(100);

	os.Even();
	os.Odd();
}
