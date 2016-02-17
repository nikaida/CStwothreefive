#ifndef ARENA_H_
#define ARENA_H_

#include <iostream>
#include <map>
#include <sstream>
#include "ArenaInterface.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

class Arena : public ArenaInterface {
   //stuff goes here 
    private:
        std::map<std::string, FighterInterface*> arenaFighters;

    public:
        Arena(); 
        bool addFighter(std::string info);
        bool removeFighter(std::string name);
        FighterInterface* getFighter(std::string name);
        int getSize();
};

#endif
