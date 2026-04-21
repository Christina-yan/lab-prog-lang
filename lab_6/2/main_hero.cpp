#include "main_hero.h"
#include "exceptions.h"
#include <algorithm>

MainHero::MainHero(double x, double y, string n, int health)
    : BaseCharacter(x, y, health), name(n), current_weapon_index(-1) {
}

void MainHero::hit(BaseEnemy* target) {
    if (!is_alive()) {
        cout << "Hero is dead and cannot attack!" << endl;
        return;
    }

    if (!target->is_alive()) {
        throw DeadTargetException();
    }

    if (inventory.empty() || current_weapon_index == -1) {
        throw NoWeaponException();
    }

    cout << name << " attacks!" << endl;
    inventory[current_weapon_index].hit(this, target);
}

void MainHero::add_weapon(Weapon weapon) {
    inventory.push_back(weapon);
    if (inventory.size() == 1) {
        current_weapon_index = 0;
    }
    cout << "Picked up " << weapon << "!" << endl;
}

void MainHero::next_weapon() {
    if (inventory.empty()) {
        cout << "I am unarmed!" << endl;
        return;
    }

    if (inventory.size() == 1) {
        cout << "I have only one weapon!" << endl;
        return;
    }

    current_weapon_index = (current_weapon_index + 1) % inventory.size();
    cout << "Switched weapon to " << inventory[current_weapon_index] << "!" << endl;
}

void MainHero::heal(int amount) {
    if (!is_alive()) {
        cout << "Hero is dead, cannot heal!" << endl;
        return;
    }

    int old_hp = hp;
    hp += amount;
    if (hp > 200) {
        hp = 200;
    }
    cout << "Healed! Health: " << old_hp << " -> " << hp << endl;
}

string MainHero::get_name() const { return name; }

void MainHero::show_status() const {
    cout << "\n=== " << name << "'s STATUS ===" << endl;
    cout << "Health: " << hp << "/200" << endl;
    cout << "Position: (" << pos_x << ", " << pos_y << ")" << endl;
    if (inventory.empty()) {
        cout << "Weapon: none" << endl;
    }
    else {
        cout << "Current weapon: " << inventory[current_weapon_index] << endl;
        cout << "Inventory: ";
        for (size_t i = 0; i < inventory.size(); i++) {
            if (i == (size_t)current_weapon_index) cout << "[";
            cout << inventory[i];
            if (i == (size_t)current_weapon_index) cout << "]";
            if (i < inventory.size() - 1) cout << ", ";
        }
        cout << endl;
    }
    cout << "==================" << endl;
}

ostream& operator<<(ostream& os, const MainHero& hero) {
    os << "Hero " << hero.name << " at position (" << hero.pos_x
        << ", " << hero.pos_y << ") with HP: " << hero.hp;
    return os;
}