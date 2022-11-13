// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 27/09/2022

#include <iostream>

using namespace std;

long long getMinimum(int amountNums, long long nums[]) {
    if(amountNums == 0) {
        return 0;
    }

    long long min = nums[0];
    for(int i = 0; i < amountNums; i++) {
        if(min > nums[i]) {
            min = nums[i];
        }
    }
    return min;
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

    cout << "Minimum Element: " << getMinimum(amountNums, nums) << endl;

    return 0;
}