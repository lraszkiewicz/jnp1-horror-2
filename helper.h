// Łukasz Raszkiewicz, Maciej Gontar

#ifndef HELPER_H
#define HELPER_H

#include <memory>

typedef int HealthPoints;
typedef int Age;
typedef int AttackPower;

// Anything that has health is defined as Character.
class Character {
public:
    virtual Character(HealthPoints health);
    HealthPoints getHealth();
    void takeDamage(AttackPower damage);
private:
    HealthPoints _health;
};

// Anything that can do damage is defined as Attacker.
class Attacker {
public:
    virtual Attacker(AttackPower attackPower);
    const AttackPower getAttackPower();
private:
    const AttackPower _attackPower;
};
#endif  // HELPER_H