#ifndef FISH_H
#define FISH_H

#include <string>
#include "animal.h"

using namespace std;

class Fish : public Animal {

public:
    Fish();

    ~Fish() override = default;

    string breath() override;

    string eat() override;

    string swim() override;
};

#endif 

