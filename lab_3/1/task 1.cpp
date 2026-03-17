#include <iostream>
#include "figure.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"

using namespace std;

int main()
{
    cout << "take the figure: " << endl
        << "0 - rectangle; 1 - circle; " << endl
        << "2 - square; 3 - triangle " << endl;

    Figure* c = nullptr;

    int number;
    cin >> number;

    switch (number) {
    case 0:
        c = new Rectangle(3, 4);
        break;
    case 1:
        c = new Circle(3);
        break;
    case 2:
        c = new Square(5);
        break;
    case 3:
        c = new Triangle(5, 8);
        break;
    default:
        break;
    }

    cout << c->to_string() << endl;

    cout << endl << "cylinder volume: ";

    cout << calc_cylinder_volume(c, 5) << endl;

}
