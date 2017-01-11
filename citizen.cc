// Łukasz Raszkiewicz, Maciej Gontar

#include <stdexcept>

#include "citizen.h"

virtual Citizen::Citizen(HealthPoints health, Age age) :
        Character(health), _age(age) {};

const Age Citizen::getAge() {
    return _age;
}

Adult::Adult(HealthPoints health, Age age) : Citizen(health, age) {
    if (age < 18 || age > 100)
        throw std::invalid_argument("Adult's age must be in [18;100].");
}

std::shared_ptr<Adult> createAdult(HealthPoints health, Age age) {
    return std::make_shared<Adult>(Adult(health, age));
}

Teenager::Teenager(HealthPoints health, Age age) : Citizen(health, age) {
    if (age < 11 || age > 17)
        throw std::invalid_argument("Teenager's age must be in [11;17].");
}

std::shared_ptr<Teenager> createTeenager(HealthPoints health, Age age) {
    return std::make_shared<Teenager>(Teenager(health, age));
}

Sheriff::Sheriff(HealthPoints health, Age age, AttackPower attackPower) :
        Adult(health, age), Attacker(attackPower) {};

std::shared_ptr<Sheriff> createSheriff(HealthPoints health, Age age, AttackPower attackPower) {
    return std::make_shared<Sheriff>(Sheriff(health, age, attackPower));
}
