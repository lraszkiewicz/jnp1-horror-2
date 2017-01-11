// Łukasz Raszkiewicz, Maciej Gontar

#include <algorithm>

#include "helper.h"

Character::Character(HealthPoints health) : _health(health) {
    if (health <= 0)
        throw std::invalid_argument("Health must be greater than 0.");
}

HealthPoints Character::getHealth() const {
    return _health;
}

void Character::takeDamage(AttackPower damage) {
    _health = std::max(_health - damage, 0);
}

Attacker::Attacker(AttackPower attackPower) :
        _attackPower(attackPower) {
    if (attackPower <= 0)
        throw std::invalid_argument("AttackPower must be greater than 0.");
}

AttackPower Attacker::getAttackPower() const {
    return _attackPower;
}
