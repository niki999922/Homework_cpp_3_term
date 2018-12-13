#pragma once

#include "Pig.h"
#include "Bear.h"
#include "Man.h"

class BearPigMan: public Bear, public Pig, public Man {
public:
    explicit BearPigMan(int id, int hp=MAX_HP, int baseArmor=DEFAULT_ARMOR, int baseDamage=DEFAULT_DAMAGE);

    void attack(Unit& other, int damage=-1);

    void shout() const;
};