#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;
using ll = long long;

template <typename T>
void showMatrix(size_t amountRows, size_t amountColumns, T **mtx) {
    for(int i = 0; i < amountRows; i++) {
        for(int j = 0; j < amountColumns; j++) {
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
T **generateMatrix(size_t amountRows, size_t amountColumns) {
    T **mtx = new T*[amountRows];
    for(int i = 0; i < amountRows; i++) {
        mtx[i] = new T[amountColumns]{0};
    }
    return mtx;
}

template <typename T>
T **multiply(size_t amountRowsA, size_t amountColumnsA, T **A, size_t amountRowsB, size_t amountColumnsB, T **B, bool *success) {
    if(amountColumnsA != amountRowsB) {
        cout << "Doesn't satisfy the Dimension Criteria for Matrix Multiplication!" << endl;
        *success = false;
        return nullptr;
    }

    T **C = generateMatrix<T>(amountRowsA, amountColumnsB);
    for(int i = 0; i < amountRowsA; i++) {
        for(int j = 0; j < amountColumnsB; j++) {
            for(int k = 0; k < amountColumnsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    *success = true;
    return C;
}

int main() {
    size_t amountRowsA = 3, amountColumnsA = 4;
    size_t amountRowsB = 4, amountColumnsB = 2;

    ll **A = new ll*[amountRowsA]{
        new ll[amountColumnsA]{1, 2, 3, 4},
        new ll[amountColumnsA]{5, 6, 7, 8},
        new ll[amountColumnsA]{9, 10, 11, 12}
    };
    cout << "Matrix A:" << endl;
    showMatrix<ll>(amountRowsA, amountColumnsA, A);

    ll **B = new ll*[amountRowsB]{
        new ll[amountColumnsB]{1, 2},
        new ll[amountColumnsB]{3, 4},
        new ll[amountColumnsB]{5, 6},
        new ll[amountColumnsB]{7, 8}
    };
    cout << "Matrix B:" << endl;
    showMatrix<ll>(amountRowsB, amountColumnsB, B);

    bool ok = true;
    ll **C = multiply(amountRowsA, amountColumnsA, A, amountRowsB, amountColumnsB, B, &ok);
    if(ok) {
        cout << "Matrix Multiplication:" << endl;
        showMatrix<ll>(amountRowsA, amountColumnsB, C);
    }

    return 0;
}