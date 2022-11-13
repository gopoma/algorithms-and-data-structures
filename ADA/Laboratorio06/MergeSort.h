#ifndef ADA_SORTING_MERGESORT_H
#define ADA_SORTING_MERGESORT_H

#include "Definitions.h"

template <typename T>
void mergeSort(size_t length, T *arr);
 
template <typename T>
void mergeSort(T *arr, size_t left, size_t right);
 
template <typename T>
void merge(T *arr, size_t left, size_t middle, size_t right);
 
#endif