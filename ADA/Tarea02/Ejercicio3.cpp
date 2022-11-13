#include <iostream>

using namespace std;

// Dado un arreglo de enteros un valor como entradas, mostrar
// cuantás repeticiones del valor hay en el arreglo
// Entrada:
// 6
// 1 2 3 2 2 4
// 2
// Salida: 2 se repite 3 veces

int main() {
    int n, num, counter = 0;
    cin >> n;

    int nums[n];
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cin >> num;

    for(int i = 0; i < n; i++) {
        if(nums[i] == num) {
            counter++;
        }
    }

    cout << num << " se repite " << counter << " veces";
    
    return 0;
}