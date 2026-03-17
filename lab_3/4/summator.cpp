#include "summator.h"


long long Summator::transform(int i) const {
    return i;
}


long long Summator::sum(int N) const {
    long long total = 0;
    for (int i = 1; i <= N; ++i) {
        total += this->transform(i); 
    }
    return total;
}