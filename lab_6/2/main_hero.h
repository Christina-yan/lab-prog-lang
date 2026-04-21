#ifndef MAIN_HERO_H
#define MAIN_HERO_H

#include "base_character.h"
#include "base_enemy.h"
#include "weapon.h"
#include <vector>

class MainHero : public BaseCharacter {
private:
    string name;
    vector<Weapon> inventory;
    int current_weapon_index;

public:
    MainHero(double x, double y, string n, int health = 100);

    void hit(BaseEnemy* target);
    void add_weapon(Weapon weapon);
    void next_weapon();

    void heal(int amount);

    string get_name() const;

    void show_status() const;

    friend ostream& operator<<(ostream& os, const MainHero& hero);
};

#endif