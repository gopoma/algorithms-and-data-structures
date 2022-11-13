#include <iostream>

using namespace std;

template <typename T>
int rBinarySearch(T *arr, T value, int low, int high) {
    if(low > high) {
        return -1;
    }

    int middle = (low + high) / 2;

    if(value == arr[middle]) {
        return middle;
    }
    if(value < arr[middle]) {
        return rBinarySearch(arr, value, low, middle - 1);
    }
    if(value > arr[middle]) {
        return rBinarySearch(arr, value, middle + 1, high);
    }
    return -1;
}

template <typename T>
int rBinarySearch(int length, T *arr, T value) {
    return rBinarySearch(arr, value, 0, length - 1);
}

template <typename T>
void sort(int length, T *arr) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                T aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
}

int main() {
    const int tam = 10;
    int *arr = new int[tam]{4, 125, 16, -666, 1025, -1, 0, 79, 89, 123};
    // -666 -1 0 4 16 79 89 123 125 1025
    sort(tam, arr);
    cout << rBinarySearch(tam, arr, 79) << endl;

    return 0;
}