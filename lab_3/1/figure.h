#ifndef FIGURE_H
#define FIGURE_H

#include <string>

using namespace std;

class Figure {
protected:
    string figure_type = "\"unknown\"";

public:
    Figure(string t) : figure_type(t) {}

    virtual ~Figure() = default;

    virtual double calc_area() = 0;

    virtual string to_string();

};

double calc_cylinder_volume(Figure* base, double height);

#endif 