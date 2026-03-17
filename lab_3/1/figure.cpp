#include <sstream>
#include "figure.h"

using namespace std;

string Figure::to_string() {
    stringstream ss;


    ss << "{"
        << "\n\t"
        << "\"figure_type\": "
        << figure_type
        << "\n\t"
        << "\"area\": " << this->calc_area()
        << "\n"
        << "}";

    return ss.str();
}

double calc_cylinder_volume(Figure* base, double height) {
    if (base == nullptr || height < 0)
        return -1;

    return base->calc_area() * height;
}
