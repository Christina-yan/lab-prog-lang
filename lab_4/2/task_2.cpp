#include <iostream>
#include "Rational.h"

int main()
{
    Rational a(1, 2), b(-1, 3), c(1, -4), d(-4, -4);
    cout << "a = " << a << " = " << a.NumeratorDenominator()
        << endl
        << "b = " << b << " = " << b.NumeratorDenominator()
        << endl
        << "c = " << c << " = " << c.NumeratorDenominator()
        << endl
        << "d = " << d << " = " << d.NumeratorDenominator()
        << endl;

    cout << "-a = " << -a
            << endl
            << "+b = " << +b
            << endl;

    cout << "a + b = " << a + b
        << endl
        << "b - 2 = " << b - 2
        << endl
        << "c * 5 = " << c * 5
        << endl
        << "d / c = " << d / c
        << endl;
    
    a += b;
    b -= 2;
    c *= a;
    d /= -2;

    cout << "a += b : " << a
        << endl
        << "b -= 2 : " << b
        << endl
        << "c *= a : " << c
        << endl
        << "d /= -2 : " << d
        << endl;

    bool a_b = a == b, d_05 = d == -0.5;
    bool a__b = a != b, d__05 = d != -0.5;

    cout << "a == b : " << a_b 
        << endl
        << "a != b : " << a__b 
        << endl
        << "d == - 0.5 : " << d_05 
        << endl
        << "d != - 0.5 : " << d__05 
        << endl;

}

