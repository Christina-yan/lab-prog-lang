#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    set<char> common_letters;
    string word;
    bool first_word = true;

    if (cin >> word) {
        for (char c : word) {
            common_letters.insert(c);
        }
    }
    while (cin >> word) {
        set<char> current_word_letters;
        for (char c : word) {
            current_word_letters.insert(c);
        }
        set<char> new_common;
        for (char c : common_letters) {
            if (current_word_letters.count(c)) {
                new_common.insert(c);
            }
        }
        common_letters = new_common;

        if (common_letters.empty()) {
            break;
        }
    }

    for (char c : common_letters) {
        cout << c;
    }
    cout << endl;

    return 0;
}