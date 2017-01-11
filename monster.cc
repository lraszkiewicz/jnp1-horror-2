// Łukasz Raszkiewicz, Maciej Gontar

#include "monster.h"

Monster::Monster(HealthPoints health, AttackPower attackPower) :
        Character(health), Attacker(attackPower) {};

Zombie::Zombie(HealthPoints health, AttackPower attackPower) :
        Monster(health, attackPower) {};

Vampire::Vampire(HealthPoints health, AttackPower attackPower) :
        Monster(health, attackPower) {};

Mummy::Mummy(HealthPoints health, AttackPower attackPower) :
        Monster(health, attackPower) {};