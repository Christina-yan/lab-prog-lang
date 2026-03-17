#ifndef FLYINGBIRD_H
#define FLYINGBIRD_H

#include <string>
#include "bird.h"

using namespace std;

class FlyingBird : public Bird {

public:
    FlyingBird();

    ~FlyingBird() override = default;

    //string breath() override;

    //string eat() override;

    string fly() override;
};

#endif 

