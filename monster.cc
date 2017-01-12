// Łukasz Raszkiewicz, Maciej Gontar

#include "monster.h"

Monster::Monster(HealthPoints health, AttackPower attackPower) :
        Character(health), Attacker(attackPower) {}

Zombie::Zombie(HealthPoints health, AttackPower attackPower) :
        Monster(health, attackPower) {}

std::shared_ptr<Zombie> createZombie(HealthPoints health,
                                     AttackPower attackPower) {
    return std::make_shared<Zombie>(Zombie(health, attackPower));
}

Vampire::Vampire(HealthPoints health, AttackPower attackPower) :
        Monster(health, attackPower) {}

std::shared_ptr<Vampire> createVampire(HealthPoints health,
                                       AttackPower attackPower) {
    return std::make_shared<Vampire>(Vampire(health, attackPower));
}

Mummy::Mummy(HealthPoints health, AttackPower attackPower) :
        Monster(health, attackPower) {}

std::shared_ptr<Mummy> createMummy(HealthPoints health,
                                   AttackPower attackPower) {
    return std::make_shared<Mummy>(Mummy(health, attackPower));
}

GroupOfMonsters::GroupOfMonsters(
    std::vector<std::shared_ptr<Monster>> monsters) :
        Monster(1, 1), _monsters(monsters) {}

GroupOfMonsters::GroupOfMonsters(
    std::initializer_list<std::shared_ptr<Monster>> monsters) :
        Monster(1, 1), _monsters(monsters) {}

HealthPoints GroupOfMonsters::getHealth() const {
    HealthPoints result = 0;
    for (auto monster : _monsters) {
        result += monster->getHealth();
    }
    return result;
}

AttackPower GroupOfMonsters::getAttackPower() const {
    AttackPower result = 0;
    for (auto monster : _monsters) {
        //TODO potencjalnie tymczasowy warunek, możliwe usuwanie potworów z listy
        if (monster->getHealth() > 0) {
            result += monster->getAttackPower();
        }
    }
    return result;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (auto & monster : _monsters) {
        monster->takeDamage(damage);
        if (monster->getHealth() == 0) {
            //TODO potencjalnie usuwanie potworów z listy
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
