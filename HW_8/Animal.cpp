#include <cmath>
#include "Animal.h"

Animal::Animal(int id, int hp, int baseArmor, int baseDamage) : Unit(id, hp, baseArmor, baseDamage) {}

void Animal::healWounds() {
    int newHp = static_cast<int>(round(MAX_HP * HEAL_RATE));
    setHp(getHp() + newHp);
    log("regenerate " + std::to_string(newHp) + " hp");
}
