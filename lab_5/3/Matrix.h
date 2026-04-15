#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class Matrix {
private:
    vector<vector<T>> mtr;

    void MakeRectangle() {
        int max_size = 0;
        for (const auto& row : mtr) {
            if (row.size() > max_size) {
                max_size = row.size();
            }
        }
        for (auto& row : mtr) {
            row.resize(max_size);
        }
    }

public:
    Matrix(const vector<vector<T>>& m) : mtr(m) {
        MakeRectangle();
    }

    Matrix(int rows, int columns) {
        mtr.resize(rows);
        for (auto& row : mtr) {
            row.resize(columns);
        }
    }

    Matrix() {}

    ~Matrix() {}

    T Get(int i, int j) const {
        return mtr[i][j];
    }

    void Set(int i, int j, T num) {
        mtr[i][j] = num;
    }

    int GetRows() const {
        return mtr.size();
    }

    int GetCols() const {
        if (mtr.empty()) return 0;
        return mtr[0].size();
    }

    Matrix operator+ (const Matrix& m) const {
        if (mtr.size() != m.mtr.size() ||
            (mtr.size() > 0 && mtr[0].size() != m.mtr[0].size())) {
            cout << "ERROR! matrix's size is not match" << endl;
            return Matrix();
        }

        int rows = GetRows();
        int cols = GetCols();

        Matrix res(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res.mtr[i][j] = this->mtr[i][j] + m.mtr[i][j];
            }
        }
        return res;
    }

    Matrix operator* (const Matrix& m) const {
        if (GetCols() != m.GetRows()) {
            cout << "ERROR! Cannot multiply matrices: columns of first != rows of second" << endl;
            return Matrix();
        }

        int rows = GetRows();
        int cols = m.GetCols();
        int common = GetCols();

        Matrix res(rows, cols);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                T sum = T();
                for (int k = 0; k < common; k++) {
                    sum = sum + (mtr[i][k] * m.mtr[k][j]);
                }
                res.mtr[i][j] = sum;
            }
        }
        return res;
    }

    template<typename U>
    friend ostream& operator<< (ostream& out, const Matrix<U>& m);

    template<typename U>
    friend istream& operator>> (istream& in, Matrix<U>& m);
};

template<typename T>
ostream& operator<< (ostream& out, const Matrix<T>& m) {
    int rows = m.GetRows();
    int cols = m.GetCols();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            out << m.mtr[i][j] << "\t";
        }
        out << "\n";
    }
    return out;
}

template<typename T>
istream& operator>> (istream& in, Matrix<T>& m) {
    int rows, cols;
    cout << "Enter number of rows: ";
    in >> rows;
    cout << "Enter number of columns: ";
    in >> cols;

    m.mtr.resize(rows);
    for (int i = 0; i < rows; i++) {
        m.mtr[i].resize(cols);
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            in >> m.mtr[i][j];
        }
    }
    return in;
}

#endif 