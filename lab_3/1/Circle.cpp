#include <sstream>
#include "Circle.h"

using namespace std;

Circle::Circle(double radius) : Figure("Circle") {
    this->radius = new double(radius);
}

Circle::~Circle() {
    delete this->radius;
}

double Circle::calc_area() {
    const double r = *this->radius;

    return r * r * M_PI;
}