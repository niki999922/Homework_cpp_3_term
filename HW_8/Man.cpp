#include "Man.h"

Man::Man(int id, int hp, int baseArmor, int baseDamage) : Unit(id, hp, baseArmor, baseDamage) {}

void Man::shieldsUp() {
    log("raise shield and gain " + std::to_string(ARMOR_INCREASE) + " armor");
    setArmor(getArmor() + ARMOR_INCREASE);
}
