// Łukasz Raszkiewicz, Maciej Gontar

#ifndef HELPER_H_
#define HELPER_H_

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
    explicit Character(HealthPoints health);

private:
    HealthPoints _health;
};

// Anything that can do damage is defined as an Attacker.
class Attacker {
public:
    virtual AttackPower getAttackPower() const;

protected:
    explicit Attacker(AttackPower attackPower);

private:
    const AttackPower _attackPower;
};

#endif  // HELPER_H_
