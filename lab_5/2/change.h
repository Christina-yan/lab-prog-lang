#define CHANGE_H
#ifdef CHANGE_H

#include <iostream>

using namespace std;


template<typename T>
int index(T num, T* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num)
            return i;
    }
    return -1;
}
template<typename T>
bool contains(T num, T* array, int size) {
    if (index(num, array, size) != -1)
        return 1;
    else
        return 0;
}
template<typename T>
bool change(T first, T second, T* array, int size) {
    if (contains(first, array, size) && contains(second, array, size)) {
        swap(array[index(first, array, size)], array[index(second, array, size)]);
        cout << "completted successfully" << endl;
        return 1;
    }
    else {
        cout << "ERROR! items or item is not found" << endl;
        return 0;
    }
}
template<typename T>
void to_string(const T* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

#endif // CHANGE_H