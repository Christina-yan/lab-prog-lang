#include "Polynomial.h"
#include <iostream>
#include <string>

using namespace std;

class Complex {
private:
    double re, im;
public:
    Complex(double r = 0, double i = 0) : re(r), im(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const {
        return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    bool operator==(const Complex& other) const {
        return re == other.re && im == other.im;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << "(" << c.re;
        if (c.im >= 0) out << "+";
        out << c.im << "i)";
        return out;
    }
};

int main() {
    //int

    Polynomial<int> p1({ 1, 2, 1 }); // 1 + 2x + x^2
    Polynomial<int> p2({ 1, 1 });     // 1 + x

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "Degree p1: " << p1.Degree() << endl;
    cout << "Degree p2: " << p2.Degree() << endl;

    cout << "coefficient of x^1 in p1: " << p1[1] << endl;
    cout << "coefficient of x^5 in p1: " << p1[5] << endl;

    Polynomial<int> p3 = p1 + p2;
    cout << "\np1 + p2 = " << p3 << endl;

    Polynomial<int> p4 = p1 - p2;
    cout << "p1 - p2 = " << p4 << endl;

    Polynomial<int> p5 = p1 * p2;
    cout << "p1 * p2 = " << p5 << endl;

    Polynomial<int> p6 = p1 + 5;
    cout << "\np1 + 5 = " << p6 << endl;

    Polynomial<int> p7 = 3 * p1;
    cout << "3 * p1 = " << p7 << endl;

    cout << "\np1(2) = " << p1(2) << endl;
    cout << "p2(3) = " << p2(3) << endl;

    Polynomial<int> p8({ 1, 1 });
    cout << "\np2 == p8: " << (p2 == p8) << endl;
    cout << "p1 == p2: " << (p1 == p2) << endl;
    cout << "p1 == 5: " << (p1 == 5) << endl;

    Polynomial<int> p9({ 1, 0, 1 }); // 1 + x^2
    p9 += p2;
    cout << "\np9 += p2 -> " << p9 << endl;

    p9 *= 2;
    cout << "p9 *= 2 -> " << p9 << endl;

    //complex

    Polynomial<Complex> cp1({ Complex(1, 0), Complex(2, 1), Complex(1, -1) });
    Polynomial<Complex> cp2({ Complex(1, 1), Complex(1, 0) });

    cout << "cp1: " << cp1 << endl;
    cout << "cp2: " << cp2 << endl;

    Polynomial<Complex> cp3 = cp1 + cp2;
    cout << "cp1 + cp2 = " << cp3 << endl;

    Polynomial<Complex> cp4 = cp1 * cp2;
    cout << "cp1 * cp2 = " << cp4 << endl;

    Complex x(1, 1);
    cout << "cp1(1+i) = " << cp1(x) << endl;

    Polynomial<int> zero;
    cout << "zero' polynomial: " << zero << endl;
    cout << "degreee of zero' polynomial: " << zero.Degree() << endl;

    Polynomial<int> constant(42);
    cout << "polynomial-constant: " << constant << endl;
    cout << "constant(10) = " << constant(10) << endl;

    Polynomial<int> p10 = 5 + p1;
    cout << "\n5 + p1 = " << p10 << endl;

    Polynomial<int> p11 = 10 - p1;
    cout << "10 - p1 = " << p11 << endl;

    cout << "p1 != p2: " << (p1 != p2) << endl;
    cout << "p1 != 5: " << (p1 != 5) << endl;

    return 0;
}