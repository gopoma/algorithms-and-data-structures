// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 6/10/2022

#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    int input, value;
    Stack<long long> *s = new Stack<long long>();
    do {
        cout << "Operaciones Disponibles:" << endl;
        cout << "[1] Insertar un Elemento a la Pila" << endl;
        cout << "[2] Aplicar la operacion de desapilar" << endl;
        cout << "[3] Mostrar todos los Elementos de la Pila" << endl;
        cout << "[4] Salir" << endl;
        cout << "Introduzca una opcion: ";
        cin >> input;
        switch(input) {
            case 1:
                cout << "Introduzca un Numero: ";
                cin >> value;
                s->push(value);
                break;
            case 2:
                s->pop();
                break;
            case 3:
                cout << "Elementos de la Pila:" << endl;
                s->show();
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