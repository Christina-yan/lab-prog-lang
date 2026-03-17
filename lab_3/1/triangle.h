#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <string>
#include "figure.h"

using namespace std;

class Triangle : public Figure {
    double* height;
    double* widht;

public:
    Triangle(double height, double widht);

    ~Triangle() override;

    double calc_area() override;
};

#endif 

