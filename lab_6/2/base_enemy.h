#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "base_character.h"
#include "weapon.h"

class BaseEnemy : public BaseCharacter {
private:
    Weapon weapon;

public:
    BaseEnemy(double x, double y, Weapon w, int health = 50);

    void hit(BaseCharacter* target);

    Weapon& get_weapon();

    friend ostream& operator<<(ostream& os, const BaseEnemy& enemy);
};

#endif