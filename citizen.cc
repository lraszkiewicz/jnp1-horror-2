// Łukasz Raszkiewicz, Maciej Gontar

#include <cassert>

#include "citizen.h"

virtual Citizen::Citizen(HealthPoints health, Age age) :
        Character(health), _age(age) {};

const Age Citizen::getAge() { return _age; }

Adult::Adult(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= 18);
    assert(age <= 100);
}

std::shared_ptr<Adult> createAdult(HealthPoints health, Age age) {
    return std::make_shared<Adult>(Adult(health, age));
}

Teenager::Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    assert(age >= 11);
    assert(age <= 17);
}

std::shared_ptr<Teenager> createTeenager(HealthPoints health, Age age) {
    return std::make_shared<Teenager>(Teenager(health, age));
}

Sheriff::Sheriff(HealthPoints health, Age age, AttackPower attackPower) :
        Adult(health, age), Attacker(attackPower) {};

std::shared_ptr<Sheriff> createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    return std::make_shared<Sheriff>(Sheriff(health, age, attackPower));
}