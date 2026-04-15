#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template<typename T>
class Polynomial {
private:
    vector<T> coefficients; 

    void trim() {
        while (!coefficients.empty() && coefficients.back() == T(0)) {
            coefficients.pop_back();
        }
    }
public:
    Polynomial() : coefficients() {}

    Polynomial(const vector<T>& coeff) : coefficients(coeff) {
        trim();
    }

    Polynomial(const T& coeff) : coefficients(1, coeff) {
        trim();
    }

    Polynomial(initializer_list<T> list) : coefficients(list) {
        trim();
    }

    bool operator==(const Polynomial& other) const {
        if (coefficients.size() != other.coefficients.size()) {
            Polynomial<T> temp1 = *this;
            Polynomial<T> temp2 = other;
            temp1.trim();
            temp2.trim();
            return temp1.coefficients == temp2.coefficients;
        }
        return coefficients == other.coefficients;
    }

    bool operator==(const T& scalar) const {
        Polynomial<T> temp = *this;
        temp.trim();
        return temp.coefficients.size() == 1 && temp.coefficients[0] == scalar;
    }

    bool operator!=(const Polynomial& other) const {
        return !(*this == other);
    }

    bool operator!=(const T& scalar) const {
        return !(*this == scalar);
    }

    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        vector<T> result(maxSize, T(0));

        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] = coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] = result[i] + other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator+(const T& scalar) const {
        Polynomial result = *this;
        if (result.coefficients.empty()) {
            result.coefficients.push_back(scalar);
        }
        else {
            result.coefficients[0] = result.coefficients[0] + scalar;
        }
        result.trim();
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        vector<T> result(maxSize, T(0));

        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] = coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); i++) {
            result[i] = result[i] - other.coefficients[i];
        }

        return Polynomial(result);
    }

    Polynomial operator-(const T& scalar) const {
        Polynomial result = *this;
        if (result.coefficients.empty()) {
            result.coefficients.push_back(-scalar);
        }
        else {
            result.coefficients[0] = result.coefficients[0] - scalar;
        }
        result.trim();
        return result;
    }

    Polynomial operator*(const Polynomial& other) const {
        if (coefficients.empty() || other.coefficients.empty()) {
            return Polynomial();
        }

        size_t newSize = coefficients.size() + other.coefficients.size() - 1;
        vector<T> result(newSize, T(0));

        for (size_t i = 0; i < coefficients.size(); i++) {
            for (size_t j = 0; j < other.coefficients.size(); j++) {
                result[i + j] = result[i + j] + coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(result);
    }

    Polynomial operator*(const T& scalar) const {
        vector<T> result(coefficients.size());
        for (size_t i = 0; i < coefficients.size(); i++) {
            result[i] = coefficients[i] * scalar;
        }
        return Polynomial(result);
    }

    Polynomial& operator+=(const Polynomial& other) {
        *this = *this + other;
        return *this;
    }

    Polynomial& operator+=(const T& scalar) {
        *this = *this + scalar;
        return *this;
    }

    Polynomial& operator-=(const Polynomial& other) {
        *this = *this - other;
        return *this;
    }

    Polynomial& operator-=(const T& scalar) {
        *this = *this - scalar;
        return *this;
    }

    Polynomial& operator*=(const Polynomial& other) {
        *this = *this * other;
        return *this;
    }

    Polynomial& operator*=(const T& scalar) {
        *this = *this * scalar;
        return *this;
    }

    T operator[](size_t degree) const {
        if (degree < coefficients.size()) {
            return coefficients[degree];
        }
        return T(0);
    }

    size_t Degree() const {
        if (coefficients.empty()) {
            return 0;
        }
        return coefficients.size() - 1;
    }

    T operator()(const T& x) const {
        if (coefficients.empty()) {
            return T(0);
        }

        T result = coefficients.back();
        for (int i = coefficients.size() - 2; i >= 0; i--) {
            result = result * x + coefficients[i];
        }
        return result;
    }

    template<typename U>
    friend ostream& operator<<(ostream& out, const Polynomial<U>& p);
};

template<typename T>
ostream& operator<<(ostream& out, const Polynomial<T>& p) {
    if (p.coefficients.empty()) {
        out << "0";
        return out;
    }

    for (int i = p.coefficients.size() - 1; i >= 0; i--) {
        out << p.coefficients[i];
        if (i > 0) {
            out << " ";
        }
    }
    return out;
}

template<typename T>
Polynomial<T> operator+(const T& scalar, const Polynomial<T>& poly) {
    return poly + scalar;
}

template<typename T>
Polynomial<T> operator-(const T& scalar, const Polynomial<T>& poly) {
    return Polynomial<T>(scalar) - poly;
}

template<typename T>
Polynomial<T> operator*(const T& scalar, const Polynomial<T>& poly) {
    return poly * scalar;
}

template<typename T>
bool operator==(const T& scalar, const Polynomial<T>& poly) {
    return poly == scalar;
}

template<typename T>
bool operator!=(const T& scalar, const Polynomial<T>& poly) {
    return poly != scalar;
}

#endif // POLYNOMIAL_H