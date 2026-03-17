#ifndef HUMAN_H
#define HUMAN_H

#include <string>

using namespace std;

class Human {
protected:
    string surname;
    string name;
    string patronymic;

public:
    Human();
    Human(string surname, string name, string patronymic);

    virtual ~Human() = default;

    string getSurnameAndInitials() const;
    string getFullName() const;
};

#endif