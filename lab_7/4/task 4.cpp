#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> word_count;
    string word;

    while (cin >> word) {
        word_count[word]++;
        cout << word_count[word] << endl;
    }
    return 0;
}