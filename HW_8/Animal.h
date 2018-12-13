#pragma once
#include "Unit.h"

class Animal: public virtual Unit {
public:
    static constexpr double HEAL_RATE = 0.1;

    explicit Animal(int id, int hp=MAX_HP, int baseArmor=DEFAULT_ARMOR, int baseDamage=DEFAULT_DAMAGE);

    void healWounds();
};
