#include <iostream>
#include "contains.h"


using namespace std;

int main()
{
    int* a_array = new int[] {
        1, 2, 3, 4, 5
        };

    int num;
    cout << "enter int number" << endl;
    cin >> num;
    cout << contains(num, a_array, 5) << endl;

    double* d_array = new double []{
        1.5, 2.1, 3, 4.8, 5
        };

    double numd;
    cout << "enter double number" << endl;
    cin >> numd;
    cout << contains(numd, d_array, 5) << endl;

    string* s_array = new string[]{
        "1", "2", "3", "4", "lalala"
    };

    string str;
    cout << "enter string" << endl;
    cin >> str;
    cout << contains(str, s_array, 5) << endl;

    delete[] a_array;
    delete[] d_array;
    delete[] s_array;
}
