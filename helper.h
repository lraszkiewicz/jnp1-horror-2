// Łukasz Raszkiewicz, Maciej Gontar

#ifndef HELPER_H
#define HELPER_H

#include <stdexcept>

using HealthPoints = int;
using Age = int;
using AttackPower = int;

// Anything that has health is defined as a Character.
class Character {
public:
    virtual HealthPoints getHealth() const;
    virtual void takeDamage(AttackPower damage);

protected:
    Character(HealthPoints health);

private:
    HealthPoints _health;
};

// Anything that can do damage is defined as an Attacker.
class Attacker {
public:
    AttackPower getAttackPower() const;

protected:
    Attacker(AttackPower attackPower);

private:
    const AttackPower _attackPower;
};

#endif  // HELPER_H
