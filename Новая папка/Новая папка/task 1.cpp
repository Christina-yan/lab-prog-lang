#include <iostream>



template<typename T>
bool contains(T num, T* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num)
            return 1;
    }
    return 0;
}

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

    string* s_array = new string[]{
        "1", "2", "3", "4", "lalala"
    };

    delete[] a_array;

    
   




}
