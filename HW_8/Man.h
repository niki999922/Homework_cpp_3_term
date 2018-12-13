#pragma once

#include "Unit.h"

class Man: public virtual Unit {
public:
    static const int ARMOR_INCREASE = 1;

    explicit Man(int id, int hp=MAX_HP, int baseArmor=DEFAULT_ARMOR, int baseDamage=DEFAULT_DAMAGE);

    void shieldsUp();
};
