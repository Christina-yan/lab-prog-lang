#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include <iostream>

using namespace std;

class BaseCharacter {
protected:
    double pos_x, pos_y;
    int hp;
    bool alive;

public:
    BaseCharacter(double x = 0, double y = 0, int health = 100);

    virtual ~BaseCharacter();

    void move(double delta_x, double delta_y);

    bool is_alive() const;
    virtual void get_damage(int amount);

    double get_x() const;
    double get_y() const;
    int get_hp() const;

    double distance_to(const BaseCharacter* other) const;
};

#endif