// Łukasz Raszkiewicz, Maciej Gontar

#include "smalltown.h"

bool StandardAttack::attackTime(Time time) {
    return ((time % 3 == 0 || time % 13 == 0) && time % 7 != 0);
}

Status::Status(std::string monsterType,
               HealthPoints monsterHealth,
               int aliveCitizens) :
        _monsterType(monsterType),
        _monsterHealth(monsterHealth),
        _aliveCitizens(aliveCitizens) {}

std::string Status::getMonsterName() const {
    return _monsterType;
}

HealthPoints Status::getMonsterHealth() const {
    return _monsterHealth;
}

int Status::getAliveCitizens() const {
    return _aliveCitizens;
}

SmallTown::Builder SmallTown::Builder::strategy() {
    this->_attackStrategy = new StandardAttack;
    return *this;
}

SmallTown::Builder SmallTown::Builder::dayChange(Time dayChange) {
    this->_t1 = dayChange;
    return *this;
}

SmallTown::Builder SmallTown::Builder::startTime(Time startTime) {
    this->_t0 = startTime;
    return *this;
}

SmallTown::Builder SmallTown::Builder::monster(std::shared_ptr<Monster> monster) {
    this->_attacker = std::shared_ptr<Monster>(monster);
    return *this;
}

SmallTown::Builder SmallTown::Builder::citizen(std::shared_ptr<Citizen> citizen) {
    this->_citizens.push_back(citizen);
    return *this;
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(_attacker, _t0, _t1, _attackStrategy, _citizens);
}


