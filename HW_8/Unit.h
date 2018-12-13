#pragma once

#include <string>

class Unit {
public:
    static const int MAX_HP = 100;
    static const int DEFAULT_ARMOR = 0;
    static const int DEFAULT_DAMAGE = 10;
    static constexpr double ARMOR_COEFFICIENT = 0.1;

    explicit Unit(int id, int hp=MAX_HP, int baseArmor=DEFAULT_ARMOR, int dRamage=DEFAULT_DAMAGE);

    virtual void attack(Unit& other) const;
    virtual void attack(Unit& other, int damage) const;

    bool isDead() const;

    void printInfo() const;

    int getId() const;

    int getHp() const;

    void setHp(int hp);

    int getArmor() const;

    void setArmor(int armor);

    int getDamage() const;

    void setDamage(int damage);

    void log(const std::string& message) const;

private:
    int mId;
    int mHp;
    int mArmor;
    int mDamage;
};
