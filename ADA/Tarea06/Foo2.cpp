#include <iostream>

using namespace std;

template <typename T>
int linearSearch(int length, T *arr, T value) {
    for(int i = 0; i < length; i++) {
        if(arr[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void bubbleSort(int length, T *arr) {
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

template <typename T>
void show(int length, T *arr) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

long long calculateFactorial(short int num) {
    if(num < 0) {
        return -1;
    } else {
        long long result = 1;
        for(short int i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }
}



void solve() {
    
}

int main() {
    solve();
}