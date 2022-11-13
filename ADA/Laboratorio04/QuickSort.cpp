#include <iostream>

using namespace std;

#define tam 12

template <typename T>
void quicksort(T *arr, int low, int high) {
    const int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(arr[i] <= pivot && i < j) i++;
        while(arr[j] > pivot) j--;
        if(i < j) {
            const int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    if(low < j-1) {
        quicksort(arr, low, j-1);
    }
    if(j+1 < high) {
        quicksort(arr, j+1, high);
    }
}

template <typename T>
void quicksort(int length, T *arr) {
    quicksort(arr, 0, length - 1);
}

template <typename T>
void show(int length, T *arr) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    long long *nums = new long long[tam]{1025, -666, 79, 56, 1, -25, 75, 75, 89, -1, -1, 10};
    show<long long>(tam, nums);
    quicksort<long long>(tam, nums);
    show<long long>(tam, nums);

    return 0;
}