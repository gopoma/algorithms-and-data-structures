#include <iostream>

using namespace std;

void solve(int ancho, int largo) {
    for(int i = 0; i < largo; i++) {
        for(int j = 0; j < ancho; j++) {
            if(i == 0 || i == largo - 1) {
                cout << "*";
            } else if(j == 0 || j == ancho - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int ancho, largo;

    cout << "Ingresar el ancho del rectangulo, minimo 3: ";
    cin >> ancho;
    cout << "Ingresar el largo del rectangulo, minimo 3: ";
    cin >> largo;

    if(ancho <= 2 || largo <= 2) {
        cout << "Entrada invalida" << endl;
        return 0;
    }

    solve(ancho, largo);

    return 0;
}