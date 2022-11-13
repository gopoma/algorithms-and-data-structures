// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 28/09/2022

#include <iostream>

using namespace std;

int amountNums = 10, multiplier;
long long nums[10], multiplied[10];
void getInputData();
void buildMultiplied();
void showMultiplied();

int main() {
    getInputData();
    buildMultiplied();
    showMultiplied();

    return 0;
}

void getInputData() {
    for(int i = 0; i < amountNums; i++) {
        cout << "Elemento #" << (i+1) << ": ";
        cin >> nums[i];
    }

    cout << "Multiplica: ";
    cin >> multiplier;
}

void buildMultiplied() {
    cout << "Arreglo Resultante: ";
    for(int i = 0; i < amountNums; i++) {
        multiplied[i] = nums[i] * multiplier;
    }
}

void showMultiplied() {
    for(int i = 0; i < amountNums; i++) {
        cout << multiplied[i] << " ";
    }
    cout << endl;
}