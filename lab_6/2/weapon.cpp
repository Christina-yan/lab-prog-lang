#include "weapon.h"
#include "base_character.h"

Weapon::Weapon(string n, int d, double r)
    : name(n), damage(d), range(r) {
}

string Weapon::get_name() const { return name; }
int Weapon::get_damage() const { return damage; }
double Weapon::get_range() const { return range; }

void Weapon::hit(BaseCharacter* actor, BaseCharacter* target) {
    if (!target->is_alive()) {
        cout << "Enemy is already defeated" << endl;
        return;
    }

    double dist = actor->distance_to(target);
    if (dist > range) {
        cout << "Enemy is too far for weapon " << name
            << " (distance: " << dist << ", need: " << range << ")" << endl;
        return;
    }

    cout << "Enemy hit with weapon " << name
        << " for " << damage << " damage!" << endl;
    target->get_damage(damage);
}

ostream& operator<<(ostream& os, const Weapon& w) {
    os << w.name;
    return os;
}

istream& operator>>(istream& is, Weapon& w) {
    cout << "Enter weapon name: ";
    is >> w.name;
    cout << "Enter damage: ";
    is >> w.damage;
    cout << "Enter range: ";
    is >> w.range;
    return is;
}