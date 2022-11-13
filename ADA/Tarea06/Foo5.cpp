#include <iostream>

using namespace std;

template <typename T>
bool isSorted(int length, T *arr, int current) {
    if(current == length - 1) { // Base Case
        return true;
    } else { // Recursive Case
        return arr[current] < arr[current + 1] && isSorted(length, arr, current + 1);
    }
}

template <typename T>
bool isSorted(int length, T *arr) {
    return isSorted(length, arr, 0);
}

template <typename T>
bool isArraySorted(int length, T *arr) {
    for(int i = 0; i < length - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

long long fibonacci(int n) {
    return (n == 0 || n == 1)? n : fibonacci(n - 1) + fibonacci(n - 2);
}

long long calculateFactorial(int n) {
    return (n <= 0) ? 1 : n * calculateFactorial(n - 1);
}

int main() {
    const int tam = 4;
    long long *nums = new long long[tam]{-11, -2, 6, 44};
    cout << isArraySorted<long long>(tam, nums) << endl;

    return 0;
}