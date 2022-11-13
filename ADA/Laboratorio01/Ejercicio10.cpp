// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 28/09/2022

#include <iostream>

using namespace std;

int amountNums, amountEvens = 0, amountOdds = 0;
long long nums[10000], numPar[10000], numImpar[10000];
void getInputData();
void filterNums();
void showNums(int amountNums, long long nums[]);
void showResults();

int main() {
    getInputData();
    filterNums();
    showResults();

    return 0;
}

void getInputData() {
    cout << "Cantidad de Elementos: ";
    cin >> amountNums;
    
    for(int i = 0; i < amountNums; i++) {
        cout << "Elemento #" << (i+1) << ": ";
        cin >> nums[i];
    }
}

void filterNums() {
    for(int i = 0; i < amountNums; i++) {
        if(nums[i] % 2 == 0) {
            numPar[amountEvens++] = nums[i];
        } else {
            numImpar[amountOdds++] = nums[i];
        }
    }
}

void showNums(int amountNums, long long nums[]) {
    for(int i = 0; i < amountNums; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void showResults() {
    cout << "Numeros Pares: ";
    showNums(amountEvens, numPar);
    cout << "Numeros Impares: ";
    showNums(amountOdds, numImpar);
}