#ifndef BIRD_H
#define BIRD_H

#include <string>
#include "animal.h"

using namespace std;

class Bird : public Animal {

public:
    Bird();

    ~Bird() override = default;

    string breath() override;

    string eat() override;

    string lay_eggs() override;

    virtual string fly();
};

#endif 

