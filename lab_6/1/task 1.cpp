#include "Password.h"

int main() {
    bool valid_password = false;

    while (!valid_password) {
        try {
            string password = get_password();
            cout << "Password accepted: " << password << endl;
            valid_password = true;
        }
        catch (const LengthError& e) {
            cerr << e.what() << endl;
            cout << "Please try again." << endl;
        }
        catch (const RegisterError& e) {
            cerr << e.what() << endl;
            cout << "Please try again." << endl;
        }
        catch (const DigitError& e) {
            cerr << e.what() << endl;
            cout << "Please try again." << endl;
        }
        catch (const ForbiddenLetterError& e) {
            cerr << e.what() << endl;
            cout << "Please try again." << endl;
        }
        catch (const PasswordError& e) {
            cerr << "Unknown password error: " << e.what() << endl;
            cout << "Please try again." << endl;
        }
        catch (...) {
            cerr << "Unexpected error occurred!" << endl;
            cout << "Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}