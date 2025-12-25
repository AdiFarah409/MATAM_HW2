
#include "Pirate.h"


Pirate::Pirate(){}

Pirate::Pirate(const string& name, int bounty, DEVIL_FRUIT devil_fruit): name(name),bounty(bounty),devilFruit(devil_fruit) {}





void Pirate::setName(const string& name){
    (*this).name = name;
}


void Pirate::set_DevilFruit(DEVIL_FRUIT devilFruit){
    (*this).devilFruit = devilFruit;
}


std::string Pirate::getName(){
    return name;
}


DEVIL_FRUIT Pirate::get_DevilFruit(){
    return devilFruit;
}


const char* const devilFruitNames[] = {
        "Gum Gum",
        "Smoke Smoke",
        "Flame Flame",
        "Rumble Rumble",
        "String String",
        "Ice Ice",
        "None"
};

std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name<< " (Bounty: " << pirate.bounty << ")"<< " (Devil Fruit: " << devilFruitNames[pirate.devilFruit] << ")";
    return os;
}
void Pirate::setBounty(int bounty) {
    (*this).bounty=bounty;
}
int Pirate::getBounty() {
    return bounty;
}
