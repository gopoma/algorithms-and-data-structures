// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 28/09/2022

#include <iostream>

using namespace std;

bool hasZeroSubArray(int amountNums, long long nums[]) {
    for(int i = 1; i <= amountNums; i++) {
        for(int j = 0; j < amountNums - i + 1; j++) {
            long long sum = 0;
            for(int k = j; k < j + i; k++) {
                sum += nums[k];
            }
            if(sum == 0) {
                return true;
            }
        }
    }    
    return false;
}

int main() {
    int amountNums;
    cout << "Cantidad de Elementos: ";
    cin >> amountNums;

    long long nums[amountNums];
    for(int i = 0; i < amountNums; i++) {
        cout << "Elemento #" << (i+1) << ": ";
        cin >> nums[i];
    }

    if(hasZeroSubArray(amountNums, nums)) {
        cout << "Subarray existe.";
    } else {
        cout << "Subarray no existe.";
    }
    cout << endl;

    return 0;
}