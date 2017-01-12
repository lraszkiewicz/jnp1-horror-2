// Łukasz Raszkiewicz, Maciej Gontar

#ifndef SMALLTOWN_H_
#define SMALLTOWN_H_

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "helper.h"
#include "citizen.h"
#include "monster.h"

class AttackStrategy {
public:
    // Returns true if the monster should attack at Time time.
    virtual bool attackTime(const Time &time) const = 0;
};

class DefaultStrategy : public AttackStrategy {
public:
    bool attackTime(const Time &time) const;
};

class Status {
public:
    Status(std::string monsterType,
           HealthPoints monsterHealth,
           size_t aliveCitizens);
    std::string getMonsterName() const;
    HealthPoints getMonsterHealth() const;
    size_t getAliveCitizens() const;

private:
    const std::string _monsterName;
    HealthPoints _monsterHealth;
    size_t _aliveCitizens;
};

class SmallTown {
public:
    class Builder;
    void tick(const Time &timeStep);
    Status getStatus();

private:
    SmallTown(const std::shared_ptr<AttackStrategy> &attackStrategy,
              const Time &t0,
              const Time &t1,
              const std::shared_ptr<Monster> &monster,
              const std::vector<std::shared_ptr<Citizen>> &citizens);
    std::shared_ptr<AttackStrategy> _attackStrategy;
    Time _currentTime, _dayLength;
    std::shared_ptr<Monster> _monster;
    std::vector<std::shared_ptr<Citizen>> _citizens;
    size_t _aliveCitizens;
    static constexpr auto draw = "DRAW";
    static constexpr auto citizensWon = "CITIZENS WON";
    static constexpr auto monsterWon = "MONSTER WON";
};

class SmallTown::Builder {
public:
    Builder();
    Builder &attackStrategy(const std::shared_ptr<AttackStrategy> &strategy);
    Builder &startTime(const Time &time);
    Builder &maxTime(const Time &time);
    Builder &monster(const std::shared_ptr<Monster> &monster);
    Builder &citizen(const std::shared_ptr<Citizen> &citizen);
    SmallTown build();

private:
    std::shared_ptr<AttackStrategy> _attackStrategy;
    Time _t0, _t1;
    std::shared_ptr<Monster> _monster;
    std::vector<std::shared_ptr<Citizen>> _citizens;
};

#endif  // SMALLTOWN_H_
