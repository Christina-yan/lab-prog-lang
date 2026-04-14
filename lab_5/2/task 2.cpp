#include "change.h"

int main()
{
    int size = 5;

    // int

    int* a_array = new int[size] {
        1, 2, 3, 4, 5
        };

    int num1, num2;
    cout << "enter int numbers" << endl;
    cin >> num1 >> num2;

    change(num1, num2, a_array, size);
    to_string(a_array, size);

    // double

    double* d_array = new double [size] {
        1.5, 2.1, 3, 4.8, 5
        };

    double dnum1, dnum2;
    cout << "enter double numbers" << endl;
    cin >> dnum1 >> dnum2;

    change(dnum1, dnum2, d_array, size);
    to_string(d_array, size);

    // string

    string* s_array = new string[size]{
    "1", "2", "3", "4", "lalala"
    };

    string snum1, snum2;
    cout << "enter string" << endl;
    cin >> snum1 >> snum2;

    change(snum1, snum2, s_array, size);
    to_string(s_array, size);

    delete[] a_array;
    delete[] d_array;
    delete[] s_array;

    return 0;
}



