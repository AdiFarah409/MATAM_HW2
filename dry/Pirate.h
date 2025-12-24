
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int bounty;
public:
    Pirate();

    Pirate(const string& name);
    int getBounty() const;            //Getters and Setters
    void setBounty(int bounty);
    ~Pirate() = default;

    void setName(const string& name);

    string getName();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
