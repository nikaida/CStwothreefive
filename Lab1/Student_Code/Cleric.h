
#ifndef CLERIC_H_
#define CLERIC_H_

#include "Fighter.h"


class Cleric : public Fighter {
    private:
        static const int MANA_MULTIPLIER = 5;
        static constexpr double REGENERATION_MULTIPLIER = 0.2;
        static constexpr double ABILITY_MULTIPLIER = (1/3);
        static const int INCREASE_MIN = 1;

        int max_mana;
        int mana;
    public:
        Cleric(std::string name, int maxHP, int strength, int speed, int magic);
        int getDamage();
        void reset();
        void regenerate();
        bool useAbility();

};

#endif

