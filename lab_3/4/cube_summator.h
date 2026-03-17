#ifndef CUBE_SUMMATOR_H
#define CUBE_SUMMATOR_H

#include "summator.h"

class CubeSummator : public Summator {
public:
    ~CubeSummator() override = default;

    long long transform(int i) const override;
};

#endif