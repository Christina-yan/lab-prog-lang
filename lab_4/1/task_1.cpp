#include "Complex.h"
#include <iostream>

int main()
{
    Complex a(4, 2), b(1, 5);
    Complex c = a + b;
    bool am = a < b, ab = a > b, ar = a == b, an = a != b;
    cout << a.to_string() << endl;
    
    cout << a++ << endl;
    a.set_im(12);

    cout << a
        << endl
        << b.to_string()
        << endl
        << c.to_string()
        << endl
        << c.abs() << ", " << c.arg() << ", " << c() << ", " << c.get_re()
        << endl
        << c.to_string_exp()
        << endl
        << c.to_string_trig()
        << endl
        << am
        << endl
        << ab
        << endl
        << ar
        << endl
        << an
        << endl;

    Complex j;
    cin >> j;
    cout << j
        << endl
        << j--
        << endl;
    j += b;
    cout << j
        << endl;
    j -= b;
    cout << j
        << endl;
    j *= b;
    cout << j
        << endl;
    j /= b;
    cout << j
        << endl;
    cout << j + b
        << endl
        << j- b
        << endl
        << j* b
        << endl
        << j/ b
        << endl;
    Complex a_orig;
    cin >> a_orig;
    Complex a_copy(a_orig);
    cout << a_orig
        << endl
        << a_copy
        << endl;
}