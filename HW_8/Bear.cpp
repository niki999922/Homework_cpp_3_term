#include <iostream>
#include "Bear.h"

Bear::Bear(int id, int hp, int baseArmor, int baseDamage) : Animal(id, hp, baseArmor, baseDamage), Unit(id, hp, baseArmor, baseDamage) {}

void Bear::sitIntoTheBurningCar() {
    log("I died =(");
    setHp(0);
}
