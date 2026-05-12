#include <iostream>
#include <unordered_set>

using namespace std;

void processNumbers() {
    unordered_set<int> seen_numbers;
    int number;

    while (cin >> number) {
        if (seen_numbers.find(number) != seen_numbers.end()) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
            seen_numbers.insert(number);
        }
    }
}

int main() {
    processNumbers();
    return 0;
}