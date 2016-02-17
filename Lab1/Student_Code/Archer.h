#ifndef ARCHER_H_
#define ARCHER_H_

#include "Fighter.h"

class Archer : public Fighter {
    private:
        static const int SPEED_INCREASE = 1;
        const int original_speed;
    public:
        Archer(std::string name, int maxHP, int strength, int speed, int magic);
        int getDamage();
        void reset();
        bool useAbility();

};

#endif

