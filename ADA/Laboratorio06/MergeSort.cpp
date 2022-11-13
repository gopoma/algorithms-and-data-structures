#include "MergeSort.h"
 
template <typename T>
void mergeSort(size_t length, T *arr) {
   mergeSort<T>(arr, 0, length - 1);
}
 
template <typename T>
void mergeSort(T *arr, size_t left, size_t right) {
   if(left < right) {
       size_t middle = (left + right)/2;
 
   mergeSort<T>(arr, left, middle);
   mergeSort<T>(arr, middle + 1, right);
 
   merge<T>(arr, left, middle, right);
   }
}
 
template <typename T>
void merge(T *arr, size_t left, size_t middle, size_t right) {
   size_t tmpLength = right - left + 1;
   T tmp[tmpLength];
   size_t i = left;
   size_t j = middle + 1;
   size_t k = 0;
 
   while(i <= middle && j <= right) {
       if(arr[i] < arr[j]) {
       tmp[k] = arr[i++];
   } else {
       tmp[k] = arr[j++];
   }
   k++;
   }
   while(i <= middle) {
   tmp[k++] = arr[i++];
   }
   while(j <= right) {
   tmp[k++] = arr[j++];
   }
 
   for(size_t i = 0; i < tmpLength; i++) {
       arr[left + i] = tmp[i];
   }
}