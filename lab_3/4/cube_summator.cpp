#include "cube_summator.h"

// Returns i^3
long long CubeSummator::transform(int i) const {
    return static_cast<long long>(i) * i * i;
}