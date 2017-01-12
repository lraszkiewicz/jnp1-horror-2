// Łukasz Raszkiewicz, Maciej Gontar

#include <algorithm>

#include "monster.h"

Monster::Monster(const HealthPoints &health, const AttackPower &attackPower)
        : Character(health), Attacker(attackPower) {}


Zombie::Zombie(const HealthPoints &health, const AttackPower &attackPower)
        : Monster(health, attackPower) {}

std::string Zombie::name() const {
    return "Zombie";
}

std::shared_ptr<Zombie> createZombie(HealthPoints health,
                                     AttackPower attackPower) {
    return std::make_shared<Zombie>(Zombie(health, attackPower));
}


Vampire::Vampire(const HealthPoints &health, const AttackPower &attackPower)
        : Monster(health, attackPower) {}

std::string Vampire::name() const {
    return "Vampire";
}

std::shared_ptr<Vampire> createVampire(HealthPoints health,
                                       AttackPower attackPower) {
    return std::make_shared<Vampire>(Vampire(health, attackPower));
}


Mummy::Mummy(const HealthPoints &health, const AttackPower &attackPower)
        : Monster(health, attackPower) {}

std::string Mummy::name() const {
    return "Mummy";
}

std::shared_ptr<Mummy> createMummy(HealthPoints health,
                                   AttackPower attackPower) {
    return std::make_shared<Mummy>(Mummy(health, attackPower));
}


HealthPoints HPSum(const std::vector<std::shared_ptr<Monster>> &monsters) {
    HealthPoints result = 0;
    for (auto &monster : monsters)
        result += monster->getHealth();
    return result;
}

AttackPower APSum(const std::vector<std::shared_ptr<Monster>> &monsters) {
    AttackPower result = 0;
    for (auto &monster : monsters)
        if (monster->getHealth() > 0)
            result += monster->getAttackPower();
    return result;
}

GroupOfMonsters::GroupOfMonsters(
    std::vector<std::shared_ptr<Monster>> monsters)
        : Monster(HPSum(monsters), APSum(monsters)), _monsters(monsters) {}

GroupOfMonsters::GroupOfMonsters(
    std::initializer_list<std::shared_ptr<Monster>> monsters)
        : _monsters(monsters), Monster(HPSum(monsters), APSum(monsters)) {}

std::string GroupOfMonsters::name() const {
    return "GroupOfMonsters";
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (auto &monster : _monsters) {
        if (monster->getHealth() > 0) {
            Monster::takeDamage(std::min(monster->getHealth(), damage));
            monster->takeDamage(damage);
            if (monster->getHealth() == 0)
                Monster::reduceAttackPower(monster->getAttackPower());
        }
    }
}

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(
        const std::vector<std::shared_ptr<Monster>> &monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(
        const std::initializer_list<std::shared_ptr<Monster>> &monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}
