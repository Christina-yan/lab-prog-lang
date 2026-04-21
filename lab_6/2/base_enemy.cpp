#include "base_enemy.h"

BaseEnemy::BaseEnemy(double x, double y, Weapon w, int health)
    : BaseCharacter(x, y, health), weapon(w) {
}

void BaseEnemy::hit(BaseCharacter* target) {
    if (!is_alive()) {
        cout << "Enemy is dead and cannot attack!" << endl;
        return;
    }
    cout << "Enemy attacks!" << endl;
    weapon.hit(this, target);
}

Weapon& BaseEnemy::get_weapon() { return weapon; }

ostream& operator<<(ostream& os, const BaseEnemy& enemy) {
    os << "Enemy at position (" << enemy.pos_x << ", " << enemy.pos_y
        << ") with weapon " << enemy.weapon << " (HP: " << enemy.hp << ")";
    return os;
}