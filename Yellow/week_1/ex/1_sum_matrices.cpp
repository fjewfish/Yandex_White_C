#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
private:
	int rows;
	int columns;
	vector<vector<int>> matrix;

public:
	Matrix() {
		rows = 0;
		columns = 0;
	}

	Matrix(int num_rows, int num_columns) {
		Reset(num_rows, num_columns);
	}

	void Reset(int num_rows, int num_columns) {
		if (num_columns < 0)
			throw out_of_range("num_columns < 0");
		if (num_rows < 0)
			throw out_of_range("num_ruws < 0");
		if (num_rows == 0 || num_columns == 0)
			num_rows = num_columns = 0;
		columns = num_columns;
		rows = num_rows;
		matrix.assign(num_rows, vector<int>(num_columns, 0));
	}

	int& At(int row, int column) {
		return matrix.at(row).at(column);
	}

	int At(int row, int column) const {
		return matrix.at(row).at(column);
	}

	int GetNumRows() const {
		return rows;
	}

	int GetNumColumns() const {
		return columns;
	}
};

bool operator==(const Matrix& one, const Matrix& two) {
	if (one.GetNumRows() == two.GetNumRows() && one.GetNumColumns() == two.GetNumColumns()) {
		for (int row = 0; row < one.GetNumRows(); row++){
			for (int column = 0; column < one.GetNumColumns(); column++) {
				if (one.At(row, column) != two.At(row, column))
					return false;
			}
		}
	} else {
		return false;
	}

	return true;
}

Matrix operator+(const Matrix& one, const Matrix& two) {
	if (one.GetNumRows() != two.GetNumRows() || one.GetNumColumns() != two.GetNumColumns())
		throw invalid_argument("Mismatched number of rows of columns");
	Matrix result(one.GetNumRows(), one.GetNumColumns());
	for (int row = 0; row < result.GetNumRows(); ++row) {
		for (int column = 0; column < result.GetNumColumns(); ++column) {
			result.At(row, column) = one.At(row, column) + two.At(row, column);
		}
	}

	return result;
}

istream& operator>>(istream& in, Matrix& matrix) {
	int rows, columns;
	in >> rows >> columns;
	matrix.Reset(rows, columns);
	for (int row = 0; row < rows; row++){
		for (int column = 0; column < columns; column++) {
			in >> matrix.At(row, column);
		}
	}

	return in;
}

ostream& operator<<(ostream& out, const Matrix& matrix) {
	out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
	for (int row = 0; row < matrix.GetNumRows(); row++) {
		for (int column = 0; column < matrix.GetNumColumns(); column++) {
			if (column > 0)
				out << " ";
			out << matrix.At(row, column);
		}
		out << endl;
	}

	return out;
}
