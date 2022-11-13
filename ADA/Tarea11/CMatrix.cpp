#include "CMatrix.h"

template <typename T>
T **generateMatrix(size_t amountRows, size_t amountColumns) {
    T **mtx = new T*[amountRows];
    for(size_t i = 0; i < amountRows; i++) {
        mtx[i] = new T[amountColumns]{0};
    }

    return mtx;
}

template <typename T>
T **generateSquareMatrix(size_t dimension) {
    return generateMatrix<T>(dimension, dimension);
}

template <typename T>
void showVector(vector<T> v) {
    for(T e: v) {
        cout << e << " ";
    }
    cout << "\n";
}