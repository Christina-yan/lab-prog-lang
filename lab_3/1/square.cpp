#include <sstream>
#include "square.h"

using namespace std;

Square::Square(double height) : Figure("square") {
    this->height = new double(height);
}

Square::~Square() {
    delete this->height;
}

double Square::calc_area() {
    const double h = *this->height;

    return h * h;
}