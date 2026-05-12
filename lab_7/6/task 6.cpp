#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void Process(const vector<T>& data) {
    vector<T> filtered;

    auto filteredLast = copy_if(
        data.begin(),
        data.end(),
        back_inserter(filtered),  
        [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filtered.end());  
}

template <typename Iter>
void PrintResults(Iter first, Iter last) {
    for (Iter it = first; it != last; ++it) {
        cout << *it << endl;
    }
}