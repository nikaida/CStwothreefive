#ifndef FIGHTER_H_
#define FIGHTER_H_

#include <iostream>
#include "FighterInterface.h"

class Fighter : public FighterInterface {
    private:
        static constexpr double QUARTER = 0.25;
        static const int MINIMUM_DAMAGE = 1;
        static constexpr double REGENERATION_MULTIPLIER = (1/6);

        std::string name;
        const int maxHP;
        int currentHP;
        int strength;
        int speed;
        int magic;
        int damage;
    protected:
        void setStrength(int new_strength);
        void setSpeed(int new_speed);
        void setCurrentHP(int new_HP); 
    public:
        Fighter(std::string name, int maxHP, int strength, int speed, int magic);
        std::string getName();
        int getMaximumHP();
        int getCurrentHP();
        int getStrength();
        int getSpeed();
        int getMagic();
        virtual int getDamage() = 0;
        void takeDamage(int damage);
        virtual void reset();
        virtual void regenerate();
        virtual bool useAbility() = 0;
};


#endif
