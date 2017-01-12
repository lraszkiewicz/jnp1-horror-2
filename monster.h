// Łukasz Raszkiewicz, Maciej Gontar

#ifndef MONSTER_H_
#define MONSTER_H_

#include <memory>
#include <vector>

#include "helper.h"

class Monster : public /* virtual */ Character, public /* virtual */ Attacker {
public:
    virtual std::string name() const = 0;
protected:
    Monster(const HealthPoints &health, const AttackPower &attackPower);
};


class Zombie : public Monster {
public:
    Zombie(const HealthPoints &health, const AttackPower &attackPower);
    virtual std::string name() const;
};

std::shared_ptr<Zombie> createZombie(HealthPoints health,
                                     AttackPower attackPower);


class Vampire : public Monster {
public:
    Vampire(const HealthPoints &health, const AttackPower &attackPower);
    virtual std::string name() const;
};

std::shared_ptr<Vampire> createVampire(HealthPoints health,
                                       AttackPower attackPower);


class Mummy : public Monster {
public:
    Mummy(const HealthPoints &health, const AttackPower &attackPower);
    virtual std::string name() const;
};

std::shared_ptr<Mummy> createMummy(HealthPoints health,
                                   AttackPower attackPower);


class GroupOfMonsters : public Monster {
public:
    explicit GroupOfMonsters(std::vector<std::shared_ptr<Monster>> monsters);
    explicit GroupOfMonsters(
            std::initializer_list<std::shared_ptr<Monster>> monsters);
    void takeDamage(AttackPower damage);
    virtual std::string name() const;

private:
    std::vector<std::shared_ptr<Monster>> _monsters;
};

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(
        const std::vector<std::shared_ptr<Monster>> &monsters);

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(
        const std::initializer_list<std::shared_ptr<Monster>> &monsters);

#endif  // MONSTER_H_
