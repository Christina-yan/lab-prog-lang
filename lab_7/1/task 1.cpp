#include <iostream>
#include <vector>

using namespace std;

template<typename Container>
void Print(const Container& container, const string& delimiter) {
    bool first = true;
    for (const auto& element : container) {
        if (!first) {
            cout << delimiter;
        }
        cout << element;
        first = false;
    }
    cout << endl;
}

int main() {
    vector<int> data = { 1, 2, 3 };
    Print(data, ", "); 

    vector<string> words = { "hello", "world" };
    Print(words, " - "); 
}
