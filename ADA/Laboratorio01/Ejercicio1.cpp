// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 27/09/2022

#include <iostream>

using namespace std;

long long multiply(int amountNums, int nums[]) {
    long long result = 1;
    for(int i = 0; i < amountNums; i++) {
        result *= nums[i];
    }
    return result;
}

int main() {
    int amountNums;
    cout << "Cantidad de Elementos: ";
    cin >> amountNums;

    int nums[amountNums];
    for(int i = 0; i < amountNums; i++) {
        cout << "Elemento #" << (i+1) << ": ";
        cin >> nums[i];
    }

    cout << "Multiplicacion de Elementos: " << multiply(amountNums, nums) << endl;

    return 0;
}