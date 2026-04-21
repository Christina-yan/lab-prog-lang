#include "base_character.h"
#include <cmath>

BaseCharacter::BaseCharacter(double x, double y, int health)
    : pos_x(x), pos_y(y), hp(health), alive(true) {
}

BaseCharacter::~BaseCharacter() {}

void BaseCharacter::move(double delta_x, double delta_y) {
    pos_x += delta_x;
    pos_y += delta_y;
}

bool BaseCharacter::is_alive() const {
    return alive;
}

void BaseCharacter::get_damage(int amount) {
    if (!alive) return;
    hp -= amount;
    if (hp <= 0) {
        hp = 0;
        alive = false;
        cout << "Character died!" << endl;
    }
}

double BaseCharacter::get_x() const { return pos_x; }
double BaseCharacter::get_y() const { return pos_y; }
int BaseCharacter::get_hp() const { return hp; }

double BaseCharacter::distance_to(const BaseCharacter* other) const {
    double dx = pos_x - other->pos_x;
    double dy = pos_y - other->pos_y;
    return sqrt(dx * dx + dy * dy);
}