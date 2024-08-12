/* Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to  
 Add Two MATRIX objects. Write a main function to implement it*/

#include <iostream>
using namespace std;

class Matrix {
    int row, col;
    int **mat;

public:
  
    Matrix(int r, int c) {
        row = r;
        col = c;
        mat = new int *[r];
        for (int i = 0; i < r; i++) {
            mat[i] = new int[c];
            for (int j = 0; j < c; j++) {
                mat[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix &o) {
        row = o.row;
        col = o.col;
        mat = new int *[row];
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col];
            for (int j = 0; j < col; j++) {
                mat[i][j] = o.mat[i][j];
            }
        }
    }

    ~Matrix() {
        for (int i = 0; i < row; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }


    void input() {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> mat[i][j];
            }
        }
    }

    Matrix operator+(const Matrix &o) const {
        if (row == o.row && col == o.col) {
            Matrix result(row, col);
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    result.mat[i][j] = mat[i][j] + o.mat[i][j];
                }
            }
            return result;
        } else {
            cout << "Matrix dimensions should be equal for addition" << endl;
            return Matrix(0, 0);
        }
    }


    Matrix &operator=(const Matrix &o) {
        if (this != &o) {
            for (int i = 0; i < row; i++) {
                delete[] mat[i];
            }
            delete[] mat;

            row = o.row;
            col = o.col;
            mat = new int *[row];
            for (int i = 0; i < row; i++) {
                mat[i] = new int[col];
                for (int j = 0; j < col; j++) {
                    mat[i][j] = o.mat[i][j];
                }
            }
        }
        return *this;
    }
    void show() const {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    int r, c;
    cout << "Enter the rows and columns of the matrices: ";
    cin >> r >> c;

    Matrix m1(r, c);
    Matrix m2(r, c);

    cout << "Enter the matrix A: " << endl;
    m1.input();

    cout << "Enter the matrix B: " << endl;
    m2.input();

    Matrix m3 = m1 + m2;

    cout << "The sum of the matrices is: " << endl;
    m3.show();

    return 0;
}

