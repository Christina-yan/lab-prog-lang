#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using namespace std;

class Animal {
protected:
    string animal_type = "\"unknown\"";
    
public:
    Animal(string t) : animal_type(t) {}

    virtual ~Animal() = default;

    virtual string breath() = 0;

    virtual string eat() = 0;

    virtual string to_string();

    virtual string swim();

    virtual string lay_eggs();

    virtual string fly();
};

#endif