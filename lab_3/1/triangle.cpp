#include <sstream>
#include "triangle.h"

using namespace std;

Triangle::Triangle(double height, double widht) : Figure("triangle") {
    this->height = new double(height);
    this->widht = new double(widht);
}

Triangle::~Triangle() {
    delete this->height;
    delete this->widht;
}

double Triangle::calc_area() {
    const double h = *this->height;
    const double w = *this->widht;

    return h * w * 0.5;
}