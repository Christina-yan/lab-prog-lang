#ifndef SUMMATOR_H
#define SUMMATOR_H

class Summator {
public:
    
    virtual ~Summator() = default;

    
    virtual long long transform(int i) const;

    
    long long sum(int N) const;
};

#endif