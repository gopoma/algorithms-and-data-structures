#include <iostream>

using namespace std;

// Dado un arreglo de enteros como entrada, mostrar el arreglo ordenado
// Entrada:
// 4
// 4 2 1 3
// Salida:
// 1 2 3 4

int main() {
    int n;
    cin >> n;

    int nums[n];
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                int aux = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = aux;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}