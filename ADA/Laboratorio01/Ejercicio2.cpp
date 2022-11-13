// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 27/09/2022

#include <iostream>

using namespace std;

void showPositions(int amountNums, int nums[]) {
    for(int i = 0; i < amountNums; i++) {
        cout << i << " -> " << nums[i] << endl;
    }
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
 
    showPositions(amountNums, nums);

    return 0;
}