
#pragma once

#include <iostream>

using std::string;

enum DEVIL_FRUIT {
    GUM_GUM_FRUIT,
    SMOKE_SMOKE_FRUIT,
    FLAME_FLAME_FRUIT,
    RUMBLE_RUMBLE_FRUIT,
    STRING_STRING_FRUIT,
    ICE_ICE_FRUIT,
    NONE // in case nothing is set
};

class Pirate {
private:
    string name;

    int bounty;
    DEVIL_FRUIT devilFruit;
public:
    // Constructors
    Pirate();
    Pirate(const string& name,int bounty, DEVIL_FRUIT devilFruit = DEVIL_FRUIT::NONE); // if no specific devil fruit is specified set to none
    ~Pirate() = default;

    //getters and setters
    void setBounty(int bounty);
    int getBounty();
    void setName(const string& name);
    void set_DevilFruit(DEVIL_FRUIT devilFruit);
    string getName();
    DEVIL_FRUIT get_DevilFruit();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
