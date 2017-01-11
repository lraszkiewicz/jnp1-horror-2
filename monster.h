// Łukasz Raszkiewicz, Maciej Gontar

#ifndef MONSTER_H
#define MONSTER_H

#include <memory>
#include <vector>

#include "helper.h"

class Monster : public /* virtual */ Character, public /* virtual */ Attacker {
protected:
    Monster(HealthPoints health, AttackPower attackPower);
};

class Zombie : public Monster {
public:
    Zombie(HealthPoints health, AttackPower attackPower);
};

std::shared_ptr<Zombie> createZombie(HealthPoints health,
                                     AttackPower attackPower);

class Vampire : public Monster {
public:
    Vampire(HealthPoints health, AttackPower attackPower);
};

std::shared_ptr<Vampire> createVampire(HealthPoints health,
                                       AttackPower attackPower);

class Mummy : public Monster {
public:
    Mummy(HealthPoints health, AttackPower attackPower);
};

std::shared_ptr<Mummy> createMummy(HealthPoints health,
                                   AttackPower attackPower);

HealthPoints HPSum(std::vector<std::shared_ptr<Monster>> &monsters);

AttackPower APSum(std::vector<std::shared_ptr<Monster>> &monsters);

/// Obecnie GroupOfMonsters posiada HP i AP, ale nie mają one żadnego znaczenia
/// Aktualizacja stanu życia odbywa się indywidualnie na poziomie _monsters
/// Sądzę, że aktualizowanie tych wartości również na poziomie grupy jest zbędne
class GroupOfMonsters : public Monster {
public:
    GroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters);
    GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters);
    HealthPoints getHealth();
    AttackPower getAttackPower();
    void takeDamage(AttackPower damage);

private:
    std::vector<std::shared_ptr<Monster>> _monsters;
};

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(
        std::vector<std::shared_ptr<Monster>> monsters);

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(
        std::initializer_list<std::shared_ptr<Monster>> monsters);

#endif  // MONSTER_H
