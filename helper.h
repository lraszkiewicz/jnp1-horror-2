// Łukasz Raszkiewicz, Maciej Gontar

#ifndef HELPER_H
#define HELPER_H

typedef int HealthPoints;
typedef int Age;
typedef int AttackPower;

// Anything that has health is defined as Character.
class Character {
public:
    virtual Character(HealthPoints health) : _health(health) {};
    HealthPoints getHealth();
    virtual void takeDamage(AttackPower damage);
private:
    HealthPoints _health;
};

// Anything that can do damage is defined as Attacker.
class Attacker {
public:
    virtual Attacker(AttackPower attackPower) : _attackPower(attackPower) {};
    AttackPower getAttackPower();
private:
    AttackPower _attackPower;
};
#endif  // HELPER_H