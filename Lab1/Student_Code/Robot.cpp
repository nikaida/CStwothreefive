
#include "Robot.h"

Robot::Robot(std::string name, int maxHP, int strength, int speed, int magic):
    Fighter(name, maxHP, strength, speed, magic), 
    max_energy((Fighter::getMagic()) * MAGIC_MULTIPLIER),
    energy(max_energy) {
}

int Robot::getDamage(){
    int damage_dealt = (Fighter::getStrength() + bonus_damage);
    bonus_damage = 0;
    return damage_dealt;
}

void Robot::reset() {
    Fighter::reset();
    energy = max_energy;
    bonus_damage = 0;
}

bool Robot::useAbility() {
    if (energy >= ROBOT_ABILITY_COST) {
            bonus_damage = ((Fighter::getStrength()) * pow((energy/max_energy), ABILITY_EXPONENTIAL));
            energy -= ROBOT_ABILITY_COST; 
            return true;
    }
    else {
    return false;
    }
}




