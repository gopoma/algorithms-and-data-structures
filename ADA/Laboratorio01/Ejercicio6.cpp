// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio01 - Introducción
// Fecha: 27/09/2022

#include <iostream>

using namespace std;

int amountChars, amountChars2;
char chars[10000], chars2[10000], composed[20000];
void getInputData();
void buildComposed();
void showComposed();

int main() {
    getInputData();
    buildComposed();
    showComposed();

    return 0;
}

void getInputData() {
    cout << "Arreglo #1: " << endl;
    cout << "Cantidad de Elementos: ";
    cin >> amountChars;

    for(int i = 0; i < amountChars; i++) {
        cout << "Elemento #" << (i+1) << ": ";
        cin >> chars[i];
    }

    cout << "Arreglo #2: " << endl;
    cout << "Cantidad de Elementos: ";
    cin >> amountChars2;

    for(int i = 0; i < amountChars2; i++) {
        cout << "Elemento #" << (i+1) << ": ";
        cin >> chars2[i];
    }
}

void buildComposed() {
    for(int i = 0; i < amountChars; i++) {
        composed[i] = chars[i];
    }
    for(int i = 0; i < amountChars2; i++) {
        composed[amountChars + i] = chars2[i];
    }
}

void showComposed() {
    cout << "Arreglo Resultante: " << endl;
    for(int i = 0; i < amountChars + amountChars2; i++) {
        cout << composed[i] << " ";
    }
    cout << endl;
}