// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 6/10/2022

#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    int input;
    long long value;
    Queue<long long> *q = new Queue<long long>();
    do {
        cout << "Operaciones Disponibles:" << endl;
        cout << "[1] Insertar un Elemento a la Cola" << endl;
        cout << "[2] Aplicar la operacion de desencolar" << endl;
        cout << "[3] Mostrar todos los Elementos de la Cola" << endl;
        cout << "[4] Salir" << endl;
        cout << "Introduzca una opcion: ";
        cin >> input;
        switch(input) {
            case 1:
                cout << "Introduzca un Numero: ";
                cin >> value;
                q->enqueue(value);
                break;
            case 2:
                q->dequeue();
                break;
            case 3:
                q->show();
                break;
            case 4:
                break;
            default:
                cout << "Entrada invalida" << endl;
        }
        cout << endl;
    } while(input != 4);

    return 0;
}