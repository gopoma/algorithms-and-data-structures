// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 27/09/2022

#include <iostream>

using namespace std;

const int NOT_FOUND = -1;

long long calculateDeferredSum(int amountNums, long long nums[], int deferredIndex) {
    long long sum = 0, deferredSum = 0;
    for(int i = 0; i < amountNums; i++) {
        sum += nums[i];
    }
    deferredSum = sum - nums[deferredIndex];
    return deferredSum;
}

int hasHalfValue(int amountNums, long long nums[]) {
    for(int i = 0; i < amountNums; i++) {
        if(nums[i] == calculateDeferredSum(amountNums, nums, i)) {
            return i;
        }
    }
    return NOT_FOUND;
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

    int result = hasHalfValue(amountNums, nums);
    if(result != NOT_FOUND) {
        cout << nums[result] << " equivale a la suma de los demas numeros";
    } else {
        cout << "No hay un elemento cuyo valor equivalga la suma del resto de elementos del arreglo";
    }
    cout << endl;

    return 0;
}