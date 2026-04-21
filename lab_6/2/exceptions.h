#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

using namespace std;

class GameException : public exception {
private:
    string message;
public:
    GameException(const string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class NoWeaponException : public GameException {
public:
    NoWeaponException() : GameException("NoWeaponException: Hero has no weapon!") {}
};

class DeadTargetException : public GameException {
public:
    DeadTargetException() : GameException("DeadTargetException: Target is already dead!") {}
};

#endif