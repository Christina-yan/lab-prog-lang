#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "figure.h"

using namespace std;

class Rectangle : public Figure {
    double* height;
    double* widht;

public:
    Rectangle(double height, double widht);

    ~Rectangle() override;

    double calc_area() override;
};

#endif 

