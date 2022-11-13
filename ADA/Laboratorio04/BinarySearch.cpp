#include <iostream>

using namespace std;

#define tam 12

template <typename T>
int binarySearch(T *arr, T value, int low, int high) {
    if(low > high) {
        return -1;
    }
    int center = (low+high)/2;
    if(value == arr[center]) {
        return center;
    } else if(value < arr[center]) {
        return binarySearch(arr, value, low, center-1);
    } else {
        return binarySearch(arr, value, center+1, high);
    }
}

template <typename T>
int binarySearch(int length, T *arr, T value) {
    return binarySearch(arr, value, 0, length - 1);
}

int main() {
    long long *nums = new long long[tam]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    cout << binarySearch<long long>(tam, nums, 4) << endl;

    return 0;
}