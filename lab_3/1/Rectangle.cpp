#include <sstream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double height, double widht) : Figure("rectangle") {
    this->height = new double(height);
    this->widht = new double(widht);
}

Rectangle::~Rectangle() {
    delete this->height;
    delete this->widht;
}

double Rectangle::calc_area() {
    const double h = *this->height;
    const double w = *this->widht;

    return h * w;
}