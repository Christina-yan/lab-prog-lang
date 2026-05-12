#include <iostream>
#include <vector>

using namespace std;

template <typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) {
        return last;
    }

    Iter result = first;
    ++first;

    while (first != last) {
        if (*result != *first) {
            ++result;
            *result = *first;
        }
        ++first;
    }

    return ++result;
}

int main() {
    vector<int> v = { 1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 5 };

    auto new_end = Unique(v.begin(), v.end());

    for (auto it = v.begin(); it != new_end; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}