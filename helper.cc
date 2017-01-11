// Łukasz Raszkiewicz, Maciej Gontar

#include <algorithm>
#include <cassert>

#include "helper.h"

virtual Character::Character(HealthPoints health) : _health(health) {
    assert(health > 0);
}

HealthPoints Character::getHealth() { return _health; }

void Character::takeDamage(AttackPower damage) {
    _health = std::max(_health - damage, 0);
}

virtual Attacker::Attacker(AttackPower attackPower) : _attackPower(attackPower) {
    assert(attackPower > 0);
}

const AttackPower Attacker::getAttackPower() { return _attackPower; }

