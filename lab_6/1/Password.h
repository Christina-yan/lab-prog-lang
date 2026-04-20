#define PASSWORD_H
#ifdef PASSWORD_H

#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

class PasswordError : public exception {
public:
    const char* what() const noexcept override {
        return "Password error";
    }
};

class LengthError : public PasswordError {
public:
    const char* what() const noexcept override {
        return "LengthError: Password must be at least 9 characters long";
    }
};

class RegisterError : public PasswordError {
public:
    const char* what() const noexcept override {
        return "RegisterError: Password must contain both uppercase and lowercase letters";
    }
};

class DigitError : public PasswordError {
public:
    const char* what() const noexcept override {
        return "DigitError: Password must contain at least one digit";
    }
};

class ForbiddenLetterError : public PasswordError {
public:
    const char* what() const noexcept override {
        return "ForbiddenLetterError: Password contains confusing characters (l, I, 1, o, O, 0)";
    }
};

string get_password() {
    string password;
    cout << "Enter password: ";
    getline(cin, password);

    if (password.length() < 9) {
        throw LengthError();
    }

    // регистры
    bool has_lower = false;
    bool has_upper = false;

    // цифры
    bool has_digit = false;

    // запрещенка
    bool has_forbidden = false;

    for (char c : password) {
        if (islower(c)) has_lower = true;
        if (isupper(c)) has_upper = true;
        if (isdigit(c)) has_digit = true;

        if (c == 'l' || c == 'I' || c == '1' ||
            c == 'o' || c == 'O' || c == '0') {
            has_forbidden = true;
        }
    }
    if (has_forbidden) {
        throw ForbiddenLetterError();
    }
    if (!has_digit) {
        throw DigitError();
    }
    if (!has_lower || !has_upper) {
        throw RegisterError();
    }
    return password;
}

#endif // PASSWORD_H