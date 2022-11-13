#include <iostream>

using namespace std;

template <typename T>
T rFindMax(T *arr, int low, int high) {
    if(low == high) {
        return arr[low]; // arr[high]
    }

    int middle = (low + high) / 2;

    T maxLeft = rFindMax(arr, low, middle);
    T maxRight = rFindMax(arr, middle + 1, high);

    return max(maxLeft, maxRight);
}

template <typename T>
T rFindMax(int length, T *arr) {
    return rFindMax(arr, 0, length - 1);
}

int main() {
    int *p = new int[10]{-100, -25, -5, -666, -23, -1079, 89, -100, -34, -1025};
    cout << rFindMax(10, p) << endl;

    return 0;
}