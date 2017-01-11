// Łukasz Raszkiewicz, Maciej Gontar

#ifndef CITIZEN_H
#define CITIZEN_H

#include "helper.h"

class Citizen : public virtual Character {
public:
    virtual Citizen(HealthPoints health, Age age);
    const Age getAge();
private:
    const Age _age;
};

class Adult : public Citizen {
public:
    Adult(HealthPoints health, Age age);
};

class Teenager : public Citizen {
public:
    Teenager(HealthPoints health, Age age);
};

class Sheriff : public Adult, public virtual Attacker {
public:
    Sheriff(HealthPoints health, Age age, AttackPower attackPower);
};

#endif  // CITIZEN_H