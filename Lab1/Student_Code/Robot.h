
#ifndef ROBOT_H_
#define ROBOT_H_

#include <math.h>
#include "Fighter.h"

class Robot : public Fighter {
    private:
        static const int MAGIC_MULTIPLIER = 2;
        static const int ABILITY_EXPONENTIAL = 4; 
        const int max_energy;
        int energy;
        int bonus_damage = 0;
    public:
        Robot(std::string name, int maxHP, int strength, int speed, int magic);
        int getDamage();
        void reset();
        bool useAbility();

};

#endif

