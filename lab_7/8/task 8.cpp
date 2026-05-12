#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "ERROR opening file input.txt" << endl;
        return 1;
    }

    vector<int> data;
    int num;
    while (inputFile >> num) {
        data.push_back(num);
    }
    inputFile.close();

    if (data.empty()) {
        cout << "file is hollow" << endl;
        return 1;
    }

    vector<int> original = data;

    int n;
    cout << "enter number n: ";
    cin >> n;

    int count_n = count(data.begin(), data.end(), n);
    cout << "\na. the number " << n << " occurs " << count_n << " time(s)" << endl;

    vector<int> positions;
    auto it = data.begin();
    while ((it = find(it, data.end(), n)) != data.end()) {
        positions.push_back(distance(data.begin(), it));
        ++it;
    }

    if (!positions.empty()) {
        cout << "   positions: ";
        for (size_t i = 0; i < positions.size(); ++i) {
            cout << positions[i];
            if (i != positions.size() - 1) cout << ", ";
        }
        cout << endl;
    }

    int even_count = count_if(data.begin(), data.end(),
        [](int x) { return x % 2 == 0; });
    int odd_count = data.size() - even_count;

    cout << "\nb. number of even elements: " << even_count << endl;

    cout << "   numbers fo even elements: ";
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] % 2 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    int sum_even = 0;
    for (int x : data) {
        if (x % 2 == 0) sum_even += x;
    }

    int sum_total = 0;
    for (int x : data) sum_total += x;

    int result_sum;
    if (even_count > odd_count) {
        result_sum = sum_even;
        cout << "   even numbers more than odd numbers: " << result_sum << endl;
    }
    else {
        result_sum = sum_total;
        cout << "   odd numbers more or equal, the sum of all elements: " << result_sum << endl;
    }

    sort(data.begin(), data.end());

    cout << "\nc. original data set: ";
    for (size_t i = 0; i < original.size(); ++i) {
        cout << original[i];
        if (i != original.size() - 1) cout << " ";
    }
    cout << endl;

    cout << "   sorted data set: ";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i];
        if (i != data.size() - 1) cout << " ";
    }
    cout << endl;

    if (!data.empty()) {
        swap(data.front(), data.back());
    }

    cout << "\nd. vector after swapping the first and last elements: ";
    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i];
        if (i != data.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}