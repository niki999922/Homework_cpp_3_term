#include <cmath>
#include <iostream>

#include "Unit.h"

Unit::Unit(int id, int hp, int baseArmor, int baseDamage) {
    mId = id;
    setHp(hp);
    setArmor(baseArmor);
    setDamage(baseDamage);
}

void Unit::attack(Unit& other) const {
    attack(other, -1);
}

void Unit::attack(Unit& other, int damage) const {
    if (damage == -1) {
        damage = getDamage();
    }

    auto reduceCoefficient = (1 - other.mArmor * ARMOR_COEFFICIENT);
    if (reduceCoefficient < 0) {
        reduceCoefficient = 0;
    }

    int resultDamage = static_cast<int>(round(damage * reduceCoefficient));
    other.setHp(other.mHp - resultDamage);

    log("attack unit " +
        std::to_string(other.getId()) +
        ", dealing " + std::to_string(resultDamage) +
        " damage");
}

bool Unit::isDead() const {
    return (mHp <= 0);
}

void Unit::printInfo() const {
    std::cout << "[ID : " << getId() << ", HP : " << getHp() << ", ARMOR : " << getArmor() << ", DAMAGE : " << getDamage() << "]\n";
}

int Unit::getId() const {
    return mId;
}

int Unit::getHp() const {
    return mHp;
}

void Unit::setHp(int hp) {
    if (hp < 0) {
        hp = 0;
    } else if (hp > MAX_HP) {
        hp = MAX_HP;
    }
    mHp = hp;
}

int Unit::getArmor() const {
    return mArmor;
}

void Unit::setArmor(int armor) {
    mArmor = armor;
}

int Unit::getDamage() const {
    return mDamage;
}

void Unit::setDamage(int damage) {
    if (damage < 0) {
        damage = 0;
    }
    mDamage = damage;
}

void Unit::log(const std::string& message) const {
    std::cout << getId() << " : " << message << "\n";
}
