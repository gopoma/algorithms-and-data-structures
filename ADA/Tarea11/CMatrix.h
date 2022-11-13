#ifndef ADA_TEORIA_CMATRIX_H
#define ADA_TEORIA_CMATRIX_H

#include "Definitions.h"

template <typename T>
T **generateMatrix(size_t amountRows, size_t amountColumns);

template <typename T>
T **generateSquareMatrix(size_t dimension);

template <typename T>
void showVector(vector<T> v);

#endif