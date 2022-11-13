// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 28/09/2022

#include <iostream>

using namespace std;

void bubbleZeros(int amountNums, int *nums) {
    for(int i = 0; i < amountNums; i++) {
        for(int j = 0; j < amountNums - i - 1; j++) {
            if(nums[j] == 0) {
                nums[j] += nums[j + 1];
                nums[j + 1] = nums[j] - nums[j + 1];
                nums[j] -= nums[j + 1];
            }
        }
    }
}

void showNums(int amountNums, int nums[]) {
    cout << "Arreglo Resultante: " << endl;
    for(int i = 0; i < amountNums; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
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

    bubbleZeros(amountNums, nums);
    showNums(amountNums, nums);

    return 0;
}