#include "Cleric.h"

Cleric::Cleric(std::string name, int maxHP, int strength, int speed, int magic):
    Fighter(name, maxHP, strength, speed, magic), 
    max_mana(getMagic() * MANA_MULTIPLIER),
    mana(max_mana) {
}

int Cleric::getDamage() {
    int damage_dealt = Fighter::getMagic();
    return damage_dealt;
}

void Cleric::reset() {
    Fighter::reset();
    mana = max_mana; 
}

void Cleric::regenerate() {
    Fighter::regenerate();
    int bonus_mana = (Fighter::getMagic() * REGENERATION_MULTIPLIER);
    if (bonus_mana < INCREASE_MIN) {
        bonus_mana = INCREASE_MIN;
    }
    mana += bonus_mana;
    if (mana > max_mana) {
        mana = max_mana;
    }
}

bool Cleric::useAbility() {
    if (mana >= CLERIC_ABILITY_COST) {
        int bonus_HP = (Fighter::getMagic() * ABILITY_MULTIPLIER);
        if (bonus_HP < INCREASE_MIN) {
            bonus_HP = INCREASE_MIN;
        }
        int new_HP = (Fighter::getCurrentHP() + bonus_HP);
        if (new_HP > Fighter::getMaximumHP()) {
            new_HP = Fighter::getMaximumHP();
        }
        Fighter::setCurrentHP(new_HP);
        mana = (mana - CLERIC_ABILITY_COST);
        return true;
    }
    else {
        return false;
    }
}
