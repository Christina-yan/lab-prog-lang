#define MATRIX_H
#ifdef MATRIX_H

# include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Matrix {
private:
	vector<vector <T>> mtr;

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
	Matrix(const vector<vector <T>>& m): mtr(m) {
		MakeRectangle();
	}
	Matrix(int rows, int columns) {
		mtr.resize(rows);
		for (auto& row : mtr) {
			row.resize(columns);
		}
	}
	T Get(int i, int j) const {
		return mtr[i][j];
	}
	int GetRows() {
		return this->mtr.size();
	}
	int GetCols() {
		return this->mtr[0].size();
	}
	void Set(int i, int j, T num) {
		mtr[i][j] = num;
	}
	Matrix operator+ (const Matrix& m) const {

		if (mtr.size() != m.mtr.size()) {
			cout << "ERROR! matrix's size is not math" << endl;
			return 0;
			break;
		}
		
		int rows = mtr.GetRows();
		int cols = mtr.GetCols();
		
		Matrix res(rows, cols);

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				res.mtr[i][j] = this->mtr[i][j] + m.mtr[i][j];
			}
		}
		return res;
	};

	friend ostream& operator << (ostream& out, const Matrix<T>& m) {
		int rows = mtr.GetRows();
		int cols = mtr.GetCols();
		for (int i = 0; i != rows; i++) {
			for (int j = 0; j != cols; j++) {
				out << Matrix[i][j] << "\t";
			}
			out << "\n";
		}
		return out;
	}
};
#endif // 

