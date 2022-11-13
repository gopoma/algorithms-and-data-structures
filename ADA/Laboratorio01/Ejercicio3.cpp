// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 27/09/2022

#include <iostream>

using namespace std;

int amountNums, nums[10000];
void getInputData();
void invertNums();
void showNums();

int main() {
    getInputData();
    invertNums();
    showNums();
}

void getInputData() {
    cout << "Cantidad de Elementos: ";
    cin >> amountNums;

    for(int i = 0; i < amountNums; i++) {
        cout << "Elemento #" << (i+1) << ": ";
        cin >> nums[i];
    }
}

void invertNums() {
    for(int i = 0; i < amountNums/2; i++) {
        int aux = nums[i];
        nums[i] = nums[amountNums - i - 1];
        nums[amountNums - i - 1] = aux;
    }
}

void showNums() {
    for(int i = 0; i < amountNums; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}