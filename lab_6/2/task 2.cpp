#include "game_utils.h"
#include <iostream>


int main() {
    setlocale(LC_ALL, "Russian");

    cout << "\nWELCOME TO THE GAME SYSTEM!" << endl;

    int choice;
    do {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. Start battle" << endl;
        cout << "2. Run class testing" << endl;
        cout << "3. Exit" << endl;
        cout << "==============================" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            battle();
            break;
        case 2:
            test_classes();
            break;
        case 3:
            cout << "\nGoodbye! Thanks for playing!" << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            delay(1000);
        }
    } while (choice != 3);

    return 0;
}