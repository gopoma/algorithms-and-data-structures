#include <iostream>

using namespace std;

int cantidadVasos;
int cantidadCanicas;
int frecuencias[100];
void pedirDatos();
void inicializarFrecuencias();
void llenarFrecuencias();
void mostrarResultado();

int main() {
    pedirDatos();
    inicializarFrecuencias();
    llenarFrecuencias();
    mostrarResultado();
}

void pedirDatos() {
    cin >> cantidadVasos;
    cin >> cantidadCanicas;
}

void inicializarFrecuencias() {
    for(int i = 0; i < cantidadVasos; i++) {
        frecuencias[i] = 0;
    }
}

void llenarFrecuencias() {
    int numeroVaso;
    for(int i = 0; i < cantidadCanicas; i++) {
        cin >> numeroVaso;
        frecuencias[numeroVaso - 1]++;
    }
}

void mostrarResultado() {
    for(int i = 0; i < cantidadVasos; i++) {
        cout << "Han caido " << frecuencias[i] << " canicas en el Vaso #" << (i + 1) << endl;
    }
}