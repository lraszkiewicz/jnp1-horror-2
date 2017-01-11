// Łukasz Raszkiewicz, Maciej Gontar

#ifndef MONSTER_H
#define MONSTER_H

#include "helper.h"

class Monster : public virtual Character, public virtual Attacker {
public:
    Monster(HealthPoints health, AttackPower attackPower);
};

class Zombie : public Monster {
public:
    Zombie(HealthPoints health, AttackPower attackPower);
};

class Vampire : public Monster {
public:
    Vampire(HealthPoints health, AttackPower attackPower);
};

class Mummy : public Monster {
public:
    Mummy(HealthPoints health, AttackPower attackPower);
};

#endif  // MONSTER_H