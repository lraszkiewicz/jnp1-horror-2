// Łukasz Raszkiewicz, Maciej Gontar

#ifndef HELPER_H
#define HELPER_H

using HealthPoints = int;
using Age = int;
using AttackPower = int;

// Anything that has health is defined as a Character.
class Character {
public:
    virtual Character(HealthPoints health);
    HealthPoints getHealth();
    void takeDamage(AttackPower damage);

private:
    HealthPoints _health;
};

// Anything that can do damage is defined as an Attacker.
class Attacker {
public:
    virtual Attacker(AttackPower attackPower);
    const AttackPower getAttackPower();

private:
    const AttackPower _attackPower;
};
#endif  // HELPER_H
