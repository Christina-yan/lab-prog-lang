#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using namespace std;

class BaseCharacter;

class Weapon {
private:
    string name;
    int damage;
    double range;

public:
    Weapon(string n = "Fists", int d = 5, double r = 1.0);

    void hit(BaseCharacter* actor, BaseCharacter* target);

    string get_name() const;
    int get_damage() const;
    double get_range() const;

    friend ostream& operator<<(ostream& os, const Weapon& w);
    friend istream& operator>>(istream& is, Weapon& w);
};

#endif