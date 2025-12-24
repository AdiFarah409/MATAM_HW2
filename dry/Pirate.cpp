
#include "Pirate.h"


Pirate::Pirate():name("") {}

Pirate::Pirate(const string& name): name(name) bounty(0){}


void Pirate::setName(const string& name){
    this->name = name;
}


std::string Pirate::getName(){
    return name;
}

int Pirate::getBounty() const {
    return bounty;
}

void Pirate::setBounty(int bounty) {
    this->bounty = bounty;
}
std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << " (Bounty: " << pirate.bounty << ")";
    return os;
}
