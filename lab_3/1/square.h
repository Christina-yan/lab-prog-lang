#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "figure.h"

using namespace std;

class Square : public Figure {
    double* height;

public:
    Square(double height);

    ~Square() override;

    double calc_area() override;
};

#endif 

