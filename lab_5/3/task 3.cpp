#include "Matrix.h"
//#include <iostream>
//#include <vector>
//

int main() {
    
    //int
    Matrix<int> m1({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
        });

    cout << "Matrix m1:" << endl;
    cout << m1;

    cout << "Item m1[0][0] = " << m1.Get(0, 0) << endl;
    m1.Set(0, 0, 10);
    cout << "after Set: m1[0][0] = " << m1.Get(0, 0) << endl;

    Matrix<int> m2(3, 3);
    m2.Set(0, 0, 1);
    m2.Set(0, 1, 1);
    m2.Set(0, 2, 1);
    m2.Set(1, 0, 1);
    m2.Set(1, 1, 1);
    m2.Set(1, 2, 1);
    m2.Set(2, 0, 1);
    m2.Set(2, 1, 1);
    m2.Set(2, 2, 1);

    cout << "\nMatrix m2:" << endl;
    cout << m2;

    Matrix<int> m3 = m1 + m2;
    cout << "m1 + m2:" << endl;
    cout << m3;

    Matrix<int> m4({
        {1, 2},
        {3, 4}
        });

    Matrix<int> m5({
        {5, 6},
        {7, 8}
        });

    cout << "\nMatrix m4:" << endl;
    cout << m4;
    cout << "Matrix m5:" << endl;
    cout << m5;

    Matrix<int> m6 = m4 * m5;
    cout << "m4 * m5:" << endl;
    cout << m6;

    //string
    Matrix<string> s1({
        {"A", "B", "C"},
        {"D", "E", "F"},
        {"G", "H", "I"}
        });

    cout << "string matrix s1:" << endl;
    cout << s1;

    Matrix<string> s2(3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            s2.Set(i, j, "+");
        }
    }

    cout << "string matrix s2:" << endl;
    cout << s2;

    Matrix<string> s3 = s1 + s2;
    cout << "s1 + s2 :" << endl;
    cout << s3;

    Matrix<int> inputMatrix;
    cin >> inputMatrix;
    cout << "Matrix:" << endl;
    cout << inputMatrix;

    return 0;
}