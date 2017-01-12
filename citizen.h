// Łukasz Raszkiewicz, Maciej Gontar

#ifndef CITIZEN_H_
#define CITIZEN_H_

#include <memory>

#include "helper.h"

class Citizen : public /* virtual */ Character {
public:
    Age getAge() const;

protected:
    Citizen(const HealthPoints &health, const Age &age);

private:
    const Age _age;
};


class Adult : public Citizen {
public:
    Adult(const HealthPoints &health, const Age &age);
};

std::shared_ptr<Adult> createAdult(HealthPoints health, Age age);


class Teenager : public Citizen {
public:
    Teenager(const HealthPoints &health, const Age &age);
};

std::shared_ptr<Teenager> createTeenager(HealthPoints health, Age age);


class Sheriff : public Adult, public /* virtual */ Attacker {
public:
    Sheriff(const HealthPoints &health,
            const Age &age,
            const AttackPower &attackPower);
};

std::shared_ptr<Sheriff> createSheriff(HealthPoints health,
                                       Age age,
                                       AttackPower attackPower);

#endif  // CITIZEN_H_
