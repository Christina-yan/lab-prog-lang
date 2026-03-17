#ifndef SQUARE_SUMMATOR_H
#define SQUARE_SUMMATOR_H

#include "summator.h"

class SquareSummator : public Summator {
public:
    ~SquareSummator() override = default;

    
    long long transform(int i) const override;
};

#endif