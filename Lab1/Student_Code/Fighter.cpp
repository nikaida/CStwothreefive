#include "Fighter.h"

Fighter::Fighter(std::string name, int maxHP, int strength, int speed, int magic): 
    name(name), maxHP(maxHP), strength(strength), speed(speed), magic(magic) {
}

void Fighter::setStrength(int new_strength) {
    strength = new_strength;
}

void Fighter::setSpeed(int new_speed) {
    speed = new_speed;
}

void Fighter::setCurrentHP(int new_HP) {
    currentHP = new_HP;
}

std::string Fighter::getName() {
    return name;
}

int Fighter::getMaximumHP() {
    return maxHP;
}

int Fighter::getCurrentHP() {
    return currentHP;
}

int Fighter::getStrength() {
    return strength;
}

int Fighter::Fighter::getSpeed() {
    return speed;
}

int Fighter::getMagic() {
    return magic;
}

void Fighter::takeDamage(int damage) {
    double damage_taken = (damage - (speed * QUARTER));
    if (damage_taken < MINIMUM_DAMAGE) {
        damage_taken = 1;
    }
    currentHP -= damage_taken; 
    
}

void Fighter::reset() {
    currentHP = maxHP;
}

void Fighter::regenerate() {
    currentHP += (strength * REGENERATION_MULTIPLIER);
    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
}


