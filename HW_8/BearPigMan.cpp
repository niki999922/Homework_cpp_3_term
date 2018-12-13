#include "BearPigMan.h"

BearPigMan::BearPigMan(int id, int hp, int baseArmor, int baseDamage) :
        Bear(id, hp, baseArmor, baseDamage),
        Pig(id, hp, baseArmor, baseDamage),
        Man(id, hp, baseArmor, baseDamage),
        Animal(id, hp, baseArmor, baseDamage),
        Unit(id, hp, baseArmor, baseDamage) {
}

void BearPigMan::attack(Unit& other, int damage) {
    Unit::attack(other, damage);
    shout();
}

void BearPigMan::shout() const {
    log("Hit!");
}
