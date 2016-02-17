#include "Arena.h"
Arena::Arena(){};

bool Arena::addFighter(std::string info) {
//    std::string tmp = "Fumblemore C 100 10 10 100";
    std::string name;
    char type;
    int maxHP;
    int strength;
    int speed;
    int magic;
    std::stringstream infostream(info);
    printf("%s\n", info.c_str());
    infostream >> name >> type >> maxHP >> strength >> speed >> magic;
    printf("%s,%c,%d,%d,%d,%d\n", name.c_str(), type, maxHP, strength, speed, magic);
    if (infostream.fail())
        printf("Something went wrong with infostream\n");
    FighterInterface* newFighter = NULL;
    switch (type) {
        case 'A': 
            newFighter = new Archer(name, maxHP, strength, speed, magic); 
            break;
        case 'C':
            newFighter = new Cleric(name, maxHP, strength, speed, magic); 
            break;
        case 'R': 
            newFighter = new Robot(name, maxHP, strength, speed, magic); 
            break;
        default: 
            return false; 
    }
    arenaFighters[name] = newFighter;

    std::cout << newFighter->getName();
    return true;
};

bool Arena::removeFighter(std::string name) {
    int deletionCheck = arenaFighters.erase(name);
    if (deletionCheck == 0) {
        return false;
    }
    else {
        return true;
    }
};

FighterInterface * Arena::getFighter(std::string name) {
    try{
        return arenaFighters.at(name);
    }
    catch(std::out_of_range){
        return NULL;
    }

};

int Arena::getSize() {
    return arenaFighters.size(); 
};



