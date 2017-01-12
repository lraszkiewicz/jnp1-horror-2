// Łukasz Raszkiewicz, Maciej Gontar

#include <iostream>

#include "smalltown.h"


bool DefaultStrategy::attackTime(const Time &time) const {
    return ((time % 3 == 0 || time % 13 == 0) && time % 7 != 0);
}


Status::Status(std::string monsterType,
               HealthPoints monsterHealth,
               size_t aliveCitizens)
        : _monsterName(monsterType),
          _monsterHealth(monsterHealth),
          _aliveCitizens(aliveCitizens) {}

std::string Status::getMonsterName() const {
    return _monsterName;
}

HealthPoints Status::getMonsterHealth() const {
    return _monsterHealth;
}

size_t Status::getAliveCitizens() const {
    return _aliveCitizens;
}


SmallTown::SmallTown(const std::shared_ptr<AttackStrategy> &attackStrategy,
                     const Time &t0,
                     const Time &t1,
                     const std::shared_ptr<Monster> &monster,
                     const std::vector<std::shared_ptr<Citizen>> &citizens)
        : _attackStrategy(attackStrategy),
          _currentTime(t0),
          _dayLength(t1),
          _monster(monster),
          _citizens(citizens) {
    if (_monster == nullptr)
        throw std::logic_error("Monster not passed to SmallTown.");
    if (citizens.size() == 0)
        throw std::logic_error("No citizens passed to SmallTown.");
    _aliveCitizens = 0;
    for (auto &citizen : _citizens)
        if (citizen->getHealth() > 0)
            ++_aliveCitizens;
}

void SmallTown::tick(const Time &timeStep) {
    std::string message;
    if (_aliveCitizens == 0 && _monster->getHealth() == 0)
        message = draw;
    else if (_aliveCitizens == 0)
        message = monsterWon;
    else if (_monster->getHealth() == 0)
        message = citizensWon;
    if (!message.empty()) {
        std::cout << message << std::endl;
        return;
    }

    if (_attackStrategy->attackTime(_currentTime))
        for (auto &citizen : _citizens)
            if (citizen->getHealth() > 0) {
                citizen->beAttacked(_monster);
                if (citizen->getHealth() == 0)
                    --_aliveCitizens;
            }

    _currentTime = (_currentTime + timeStep) % (_dayLength + 1);
}

Status SmallTown::getStatus() {
    return Status(_monster->name(), _monster->getHealth(), _aliveCitizens);
}


SmallTown::Builder::Builder()
        : _attackStrategy(std::make_shared<DefaultStrategy>()),
          _t0(0),
          _t1(23),
          _monster(nullptr)  {}

SmallTown::Builder &SmallTown::Builder::attackStrategy(
        const std::shared_ptr<AttackStrategy> &strategy) {
    _attackStrategy = strategy;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::startTime(const Time &t0) {
    _t0 = t0;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::maxTime(const Time &t1) {
    _t1 = t1;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::monster(
        const std::shared_ptr<Monster> &monster) {
    _monster = monster;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::citizen(
        const std::shared_ptr<Citizen> &citizen) {
    for (auto &c : _citizens)
        if (c == citizen)
            return *this;
    _citizens.push_back(citizen);
    return *this;
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(_attackStrategy, _t0, _t1, _monster, _citizens);
}
