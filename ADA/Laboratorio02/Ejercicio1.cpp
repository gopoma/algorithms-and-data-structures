// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 03/10/2022

#include <iostream>
#include <cstdlib>

using namespace std;

const int AMOUNT_NUMS = 10, LIMIT = 100;
int *p = new int[AMOUNT_NUMS];
void fillNums();
void showNums();
void showOddFilteredNums();

int main() {
    fillNums();
    cout << "Generated Nums: ";
    showNums();
    showOddFilteredNums();
    
    return 0;
}

void fillNums() {
    srand((unsigned) time(NULL));
    for(int i = 0; i < AMOUNT_NUMS; i++) {
        p[i] = rand() % LIMIT;
    }
}

void showNums() {
    for(int i = 0; i < AMOUNT_NUMS; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}

void showOddFilteredNums() {
    int j = 0;
    for(int i = 0; i < AMOUNT_NUMS; i++) {
        int num = *(p + i);
        if(num % 2 != 0) {
            cout << "Odd Num #" << (j++ + 1) << ":" << endl;
            cout << "Num: " << num << endl;
            cout << "Memory Location: " << (p + i) << endl << endl;
        }
    }
    cout << endl;
}
