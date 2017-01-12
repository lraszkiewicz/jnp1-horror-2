// Łukasz Raszkiewicz, Maciej Gontar

#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include "helper.h"
#include "citizen.h"
#include "monster.h"

using Time = int;

class AttackStrategy {
public:
    virtual bool attackTime(Time time) const = 0;
};

class StandardAttack : public Strategy {
public:
    bool attackTime(Time time);
};

class Status {
public:
    Status(std::string monsterType, HealthPoints monsterHealth, int aliveCitizens);
    std::string getMonsterType const;
    HealthPoints getMonsterHealth() const;
    int getAliveCitizens() const;
private:
    const std::string _monsterType;
    HealthPoints _monsterHealth;
    int _aliveCitizens;
};

class SmallTown {
public:
    class Builder;
    SmallTown(Time t0, Time t1, ... );
    void tick(Time timeStep);
    Status getStatus();
private:
    StandardAttack _attackChecker;
    Time _currentTime;
    Time _dayChange;
    std::shared_ptr<Monster> _monster;
    std::vector<std::shared_ptr<Citizen>> _citizens;
};

class SmallTown::Builder {
public:
    Builder();
    Builder attackStrategy();
    Builder startTime(const Time time);
    Builder dayChange(const Time time);
    Builder monster(std::shared_ptr<Monster> monster);
    Builder citizen(std::shared_ptr<Citizen> citizen);
    SmallTown build();
private:
    AttackStrategy _attackStrategy;
    Time _t0;
    Time _t1;
    std::shared_ptr<Monster> _monster;
    std::vector<std::shared_ptr<Citizen>> _citizens;
};
#endif  // SMALLTOWN_H