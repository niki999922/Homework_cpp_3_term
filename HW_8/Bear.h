#pragma once

#include "Animal.h"

class Bear: public virtual Animal {
public:
    explicit Bear(int id, int hp=MAX_HP, int baseArmor=DEFAULT_ARMOR, int baseDamage=DEFAULT_DAMAGE);

    void sitIntoTheBurningCar();
};