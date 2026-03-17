#ifndef CIRCLE_H
#define CIRCLE_H

#define _USE_MATH_DEFINES
#include <string>
#include <math.h>
#include "figure.h"

using namespace std;

class Circle : public Figure {
    double* radius;

public:
    Circle(double radius);

    ~Circle() override;

    double calc_area() override;
};

#endif
