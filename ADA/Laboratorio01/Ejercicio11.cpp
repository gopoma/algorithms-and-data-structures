#include <iostream>

using namespace std;

float precioUnitario, total;
int cantidadProductos;
void pedirDatos();
float aplicarIGV(float precioUnitario);
void calcularTotal();
void mostrarTotal();

int main() {
    pedirDatos();
    calcularTotal();
    mostrarTotal();
}

void pedirDatos() {
    cout << "Precio Unitario: ";
    cin >> precioUnitario;
    
    cout << "Cantidad Productos: ";
    cin >> cantidadProductos;
}

float aplicarIGV(float precioUnitario) {
    return precioUnitario * 1.18;
}

void calcularTotal() {
    total = aplicarIGV(precioUnitario) * cantidadProductos;
}

void mostrarTotal() {
    cout << "Total: " << total << endl;
}