// Łukasz Raszkiewicz, Maciej Gontar

#ifndef CITIZEN_H
#define CITIZEN_H

#include "helper.h"

class Citizen : public virtual Character {
public:
    Citizen(HealthPoints health, Age age) : Character(health), _age(age) {}
    Age getAge() const;
    void takeDamage (AttackPower damage) {}
private:
    const Age _age;
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age) : Citizen(health, age) {}
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age) : Citizen(health, age) {}
};

class Sheriff : public Adult, public virtual Attacker {
public:
    Sheriff(HealthPoints health, Age age, AttackPower attackPower) :
            Adult(health, age), Attacker(attackPower) {};
};

#endif  // CITIZEN_H