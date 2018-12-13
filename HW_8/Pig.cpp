#include <iostream>
#include "Pig.h"

Pig::Pig(int id, int hp, int baseArmor, int baseDamage) : Animal(id, hp, baseArmor, baseDamage), Unit(id, hp, baseArmor, baseDamage) {}

void Pig::grunt() {
    log("RRRR!");
}
