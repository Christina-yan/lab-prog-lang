#define CONTAINS_H
#ifdef CONTAINS_H

template<typename T>
bool contains(T num, T* array, int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num)
            return 1;
    }
    return 0;
}

#endif // DEBUG

