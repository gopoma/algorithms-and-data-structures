#include "Array.h"

template <typename T>
void showArray(size_t length, T *arr) {
    for(size_t i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}