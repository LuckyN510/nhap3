#include <bits/stdc++.h>
using namespace std;

class Matrix {
private:
    int row, col;
    vector<vector<int>> data;

public:
    // Matrix() : row(0), col(0) {}
    Matrix(int row, int col){
        this->row = row;
        this->col = col;
        data = vector<vector<int>>(row, vector<int>(col, 0));
    }

    friend istream& operator >> (istream &in, Matrix &A) {
        for (int i = 0; i < A.row; i++) {
            for (int j = 0; j < A.col; j++) {
                in >> A.data[i][j];
            }
        }
        return in;
    }

    // friend istream& operator >> (istream &in, Matrix &A) {
    //     // If Matrix is empty (row or col is 0), we can't input, so we ask for dimensions first
    //     if (A.row == 0 || A.col == 0) {
    //         in >> A.row >> A.col;  // Read the new dimensions
    //         A.data = vector<vector<int>>(A.row, vector<int>(A.col));  // Allocate the matrix
    //     }
        
    //     for (int i = 0; i < A.row; i++) {
    //         for (int j = 0; j < A.col; j++) {
    //             in >> A.data[i][j];
    //         }
    //     }
    //     return in;
    // }
    friend ostream& operator << (ostream &out, const Matrix &A) {
        for (int i = 0; i < A.row; i++) {
            for (int j = 0; j < A.col; j++) {
                out << A.data[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    // friend Matrix mul(Matrix &a, Matrix &b){
    //     Matrix other(a.row, b.col);
    //     for (int i = 0; i < a.row; i++) {
    //         for (int j = 0; j < b.col; j++) {
    //             other.data[i][j] = 0; 
    //             for (int k = 0; k < a.col; k++) {
    //                 other.data[i][j] += a.data[i][k] * b.data[k][j]; 
    //             }
    //         }
    //     }
    //     return other;
    // }

    friend Matrix operator * (Matrix &a, Matrix &b){
        Matrix other(a.row, b.col);
        for (int i = 0; i < a.row; i++) {
            for (int j = 0; j < b.col; j++) {
                other.data[i][j] = 0; 
                for (int k = 0; k < a.col; k++) {
                    other.data[i][j] += a.data[i][k] * b.data[k][j]; 
                }
            }
        }
        return other;
    }

    Matrix trans() const {
        Matrix res(col, row);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                res.data[j][i] = data[i][j];
            }
        }
        return res;
    }
};

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Matrix A(n, m);
        // Matrix A;
        // cin >> A;
        Matrix B = A.trans();
        cout << B << "\n";  
        cout << A << "\n";  
        // cout << mul(A, B); 
        cout << A * B;
    }
    return 0;
}
