#pragma once

#include "Unit.h"
#include "Animal.h"

class Pig: public virtual Animal {
public:
    explicit Pig(int id, int hp=MAX_HP, int baseArmor=DEFAULT_ARMOR, int baseDamage=DEFAULT_DAMAGE);

    virtual void grunt();
};
