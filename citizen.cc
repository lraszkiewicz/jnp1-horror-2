// Łukasz Raszkiewicz, Maciej Gontar

#include <cassert>

#include "citizen.h"

Age Citizen::getAge() const { return _age; }

Adult::Adult(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= 18);
    assert(age <= 100);
}

Teenager::Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= 11);
    assert(age <= 17);
}

Sheriff::Sheriff(HealthPoints health, Age age, AttackPower attackPower) :
        Adult(health, age), Attacker(attackPower) {};