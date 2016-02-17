#include "Archer.h"

Archer::Archer(std::string name, int maxHP, int strength, int speed, int magic):
    Fighter(name, maxHP, strength, speed, magic), original_speed(Fighter::getSpeed()) {
}

int Archer::getDamage() {
    int damage_dealt = Fighter::getSpeed();
    return damage_dealt;
}

void Archer::reset() {
    Fighter::reset(); 
    Fighter::setSpeed(original_speed);
}

bool Archer::useAbility() {
    int new_speed = (getSpeed() + SPEED_INCREASE);
    Fighter::setSpeed(new_speed);
    return true;
}



