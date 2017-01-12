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
    HealthPoints getHealth() const;
    virtual void takeDamage(AttackPower damage);

protected:
    explicit Character(const HealthPoints &health);

private:
    HealthPoints _health;
};


// Anything that can do damage is defined as an Attacker.
class Attacker {
public:
    AttackPower getAttackPower() const;

protected:
    explicit Attacker(const AttackPower &attackPower);
    void reduceAttackPower(const AttackPower &reduction);

private:
    AttackPower _attackPower;
};

#endif  // HELPER_H_
