// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio04 - Técnicas de Diseño de Algoritmos – Algoritmo de Strassen
// Fecha: 23/10/2022

#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;
using ll = long long;

template <typename T>
void mostrarMatriz(size_t cantidadFilas, size_t cantidadColumnas, T **matriz);

template <typename T>
void mostrarMatriz(size_t dimension, T **matriz);

template <typename T>
T **generarMatriz(size_t cantidadFilas, size_t cantidadColumnas);

template <typename T>
T **generarMatriz(size_t dimension);

template <typename T>
T **obtenerComponente(T **compuesta, size_t dimensionComponente, size_t desplazamientoFila, size_t desplazamientoColumna);

template <typename T>
T **restar(size_t cantidadFilas, size_t cantidadColumnas, T **A, T **B);

template <typename T>
T **restar(size_t dimension, T **A, T **B);

template <typename T>
T **sumar(size_t cantidadFilas, size_t cantidadColumnas, T **A, T **B);

template <typename T>
T **sumar(size_t dimension, T **A, T **B);

template <typename T>
void armarCompuesta(T **compuesta, size_t dimensionComponente, T **componente, size_t desplazamientoFila, size_t desplazamientoColumna);

template <typename T>
T **multiplicarRecursivamente(size_t dimension, T **A, T **B);

ll getNextPowerOfTwo(ll num);

template <typename T>
T **multiplicar(size_t cantidadFilasA, size_t cantidadColumnasA, T **A, size_t cantidadFilasB, size_t cantidadColumnasB, T **B, bool *success);


// Driver Code
int main() {
    size_t cantidadFilasA, cantidadColumnasA, cantidadFilasB, cantidadColumnasB;
    
    cout << "Matriz A:" << endl;
    cout << "Cantidad de Filas: ";
    cin >> cantidadFilasA;
    cout << "Cantidad de Columnas: ";
    cin >> cantidadColumnasA;
    cout << "Verificando la Consistencia de los Datos de la Matriz A..." << endl;
    if((ll)cantidadFilasA <= 0 || (ll)cantidadColumnasA <= 0) {
        cout << "Entrada Invalida: Dimension Invalida" << endl;
        return 0;
    }
    ll **A = generarMatriz<ll>(cantidadFilasA, cantidadColumnasA);
    for(int i = 0; i < cantidadFilasA; i++) {
        for(int j = 0; j < cantidadColumnasA; j++) {
            cout << "A[" << (i+1) << "][" << (j+1) << "]: "; 
            cin >> A[i][j];
        }
    }
    mostrarMatriz<ll>(cantidadFilasA, cantidadColumnasA, A);

    cout << "Matriz B:" << endl;
    cout << "Cantidad de Filas: ";
    cin >> cantidadFilasB;
    cout << "Cantidad de Columnas: ";
    cin >> cantidadColumnasB;
    cout << "Verificando la Consistencia de los Datos de la Matriz B..." << endl;
    if((ll)cantidadFilasB <= 0 || (ll)cantidadColumnasB <= 0) {
        cout << "Entrada Invalida: Dimension Invalida" << endl;
        return 0;
    }
    ll **B = generarMatriz<ll>(cantidadFilasB, cantidadColumnasB);
    for(int i = 0; i < cantidadFilasB; i++) {
        for(int j = 0; j < cantidadColumnasB; j++) {
            cout << "B[" << (i+1) << "][" << (j+1) << "]: ";
            cin >> B[i][j];
        }
    }
    mostrarMatriz<ll>(cantidadFilasB, cantidadColumnasB, B);

    bool ok = true;
    ll **result = multiplicar<ll>(cantidadFilasA, cantidadColumnasA, A, cantidadFilasB, cantidadColumnasB, B, &ok);
    if(ok) {
        mostrarMatriz<ll>(cantidadFilasA, cantidadColumnasB, result);   
    }

    delete[] A;
    A = nullptr;
    delete[] B;
    B = nullptr;
    delete[] result;
    result = nullptr;

    return 0;
}

ll getNextPowerOfTwo(ll num) {
    int count = 0;
 
    if (num > 0 && (num & (num - 1)) == 0) {
        return num;
    }
 
    while(num != 0) {
        num >>= 1;
        count += 1;
    }
 
    return 1 << count;
}

template <typename T>
T **multiplicar(size_t cantidadFilasA, size_t cantidadColumnasA, T **A, size_t cantidadFilasB, size_t cantidadColumnasB, T **B, bool *success) {
    cout << "Verificando el Criterio de Dimension..." << endl;
    if(cantidadColumnasA != cantidadFilasB) {
        cout << "Entrada Invalida: No cumple con el Criterio de Dimension [Entrada Esperada: A(pxq), B(qxr)]" << endl;
        *success = false;
        return nullptr;
    }

    cout << "Es posible calcular la Multiplicación de Matrices!" << endl;
    cout << "La Entradas para la Multiplicación por Strassen son dos Matrices de [2^ix2^i]" << endl;
    size_t dimension = getNextPowerOfTwo(max({cantidadFilasA, cantidadColumnasA, cantidadFilasB, cantidadColumnasB}));
    cout << "Empezando Proceso de Normalizacion..." << endl;
    T **ANormalizado = generarMatriz<T>(dimension);
    T **BNormalizado = generarMatriz<T>(dimension);
    for(int i = 0; i < cantidadFilasA; i++) {
        for(int j = 0; j < cantidadColumnasA; j++) {
            ANormalizado[i][j] = A[i][j];
        }
    }
    for(int i = 0; i < cantidadFilasB; i++) {
        for(int j = 0; j < cantidadColumnasB; j++) {
            BNormalizado[i][j] = B[i][j];
        }
    }

    cout << "Calculo del Resultado Parcial con Sobrecarga de Ceros:" << endl;
    T **resultadoParcial = multiplicarRecursivamente<T>(dimension, ANormalizado, BNormalizado);
    T **resultado = generarMatriz<T>(cantidadFilasA, cantidadColumnasB);
    cout << "Capturando el Componente Resultado Final..." << endl;
    for(int i = 0; i < cantidadFilasA; i++) {
        for(int j = 0; j < cantidadColumnasB; j++) {
            resultado[i][j] = resultadoParcial[i][j];
        }
    }
    return resultado;
}

template <typename T>
T **multiplicarRecursivamente(size_t dimension, T **A, T **B) {
    cout << "Generamos Matriz Resultante:" << endl;
    T **C = generarMatriz<T>(dimension);
    mostrarMatriz<T>(dimension, C);

    if(dimension == 1) {
        cout << "Entramos al Caso Base, la Matriz Resultante sera de 1x1" << endl;
        C[0][0] = A[0][0] * B[0][0];
    } else {
        cout << "Hallamos la Dimension del Componente:" << endl;
        size_t dimensionComponente = dimension/2;
        cout << "Dimension del Componente: " << dimensionComponente << endl;

        cout << "Extraemos los 4 Componentes de A [A11, A12, A21, A22] y B [A11, A12, A21, A22]:" << endl;
        T **A11 = obtenerComponente<T>(A, dimensionComponente, 0, 0);
        T **A12 = obtenerComponente<T>(A, dimensionComponente, 0, dimensionComponente);
        T **A21 = obtenerComponente<T>(A, dimensionComponente, dimensionComponente, 0);
        T **A22 = obtenerComponente<T>(A, dimensionComponente, dimensionComponente, dimensionComponente);
        T **B11 = obtenerComponente<T>(B, dimensionComponente, 0, 0);
        T **B12 = obtenerComponente<T>(B, dimensionComponente, 0, dimensionComponente);
        T **B21 = obtenerComponente<T>(B, dimensionComponente, dimensionComponente, 0);
        T **B22 = obtenerComponente<T>(B, dimensionComponente, dimensionComponente, dimensionComponente);
        cout << "Componente A11:" << endl;
        mostrarMatriz<T>(dimensionComponente, A11);
        cout << "Componente A12:" << endl;
        mostrarMatriz<T>(dimensionComponente, A12);
        cout << "Componente A21:" << endl;
        mostrarMatriz<T>(dimensionComponente, A21);
        cout << "Componente A22:" << endl;
        mostrarMatriz<T>(dimensionComponente, A22);
        cout << "Componente B11:" << endl;
        mostrarMatriz<T>(dimensionComponente, B11);
        cout << "Componente B12:" << endl;
        mostrarMatriz<T>(dimensionComponente, B12);
        cout << "Componente B21:" << endl;
        mostrarMatriz<T>(dimensionComponente, B21);
        cout << "Componente B22:" << endl;
        mostrarMatriz<T>(dimensionComponente, B22);

        cout << "Calculamos los Componentes Recursivos [M1, M2, M3, M4, M5, M6, M7]:" << endl;
        T **M1 = multiplicarRecursivamente<T>(dimensionComponente, A11, restar<T>(dimensionComponente, B12, B22));
        cout << "Componente Recursivo M1:" << endl;
        mostrarMatriz<T>(dimensionComponente, M1);

        T **M2 = multiplicarRecursivamente<T>(dimensionComponente, sumar<T>(dimensionComponente, A11, A12), B22);
        cout << "Componente Recursivo M2:" << endl;
        mostrarMatriz<T>(dimensionComponente, M2);

        T **M3 = multiplicarRecursivamente<T>(dimensionComponente, sumar<T>(dimensionComponente, A21, A22), B11);
        cout << "Componente Recursivo M3:" << endl;
        mostrarMatriz<T>(dimensionComponente, M3);

        T **M4 = multiplicarRecursivamente<T>(dimensionComponente, A22, restar<T>(dimensionComponente, B21, B11));
        cout << "Componente Recursivo M4:" << endl;
        mostrarMatriz<T>(dimensionComponente, M4);

        T **M5 = multiplicarRecursivamente<T>(dimensionComponente, sumar<T>(dimensionComponente, A11, A22), sumar<T>(dimensionComponente, B11, B22));
        cout << "Componente Recursivo M5:" << endl;
        mostrarMatriz<T>(dimensionComponente, M5);

        T **M6 = multiplicarRecursivamente<T>(dimensionComponente, restar<T>(dimensionComponente, A12, A22), sumar<T>(dimensionComponente, B21, B22));
        cout << "Componente Recursivo M6:" << endl;
        mostrarMatriz<T>(dimensionComponente, M6);

        T **M7 = multiplicarRecursivamente<T>(dimensionComponente, restar<T>(dimensionComponente, A11, A21), sumar<T>(dimensionComponente, B11, B12));
        cout << "Componente Recursivo M7:" << endl;
        mostrarMatriz<T>(dimensionComponente, M7);

        cout << "Calculamos los Componentes de la Matriz Resultante [C11, C12, C21, C22]:" << endl;
        T **C11 = sumar<T>(dimensionComponente, restar<T>(dimensionComponente, sumar<T>(dimensionComponente, M5, M4), M2), M6);
        T **C12 = sumar<T>(dimensionComponente, M1, M2);
        T **C21 = sumar<T>(dimensionComponente, M3, M4);
        T **C22 = sumar<T>(dimensionComponente, M5, restar<T>(dimensionComponente, restar<T>(dimensionComponente, M1, M3), M7));
        cout << "Componente Matriz Resultante C11:" << endl;
        mostrarMatriz<T>(dimensionComponente, C11);
        cout << "Componente Matriz Resultante C12:" << endl;
        mostrarMatriz<T>(dimensionComponente, C12);
        cout << "Componente Matriz Resultante C21:" << endl;
        mostrarMatriz<T>(dimensionComponente, C21);
        cout << "Componente Matriz Resultante C22:" << endl;
        mostrarMatriz<T>(dimensionComponente, C22);

        cout << "Armamos la Matriz Resultante con sus Componentes [C11, C12, C21, C22]" << endl;
        armarCompuesta<T>(C, dimensionComponente, C11, 0, 0);
        armarCompuesta<T>(C, dimensionComponente, C12, 0, dimensionComponente);
        armarCompuesta<T>(C, dimensionComponente, C21, dimensionComponente, 0);
        armarCompuesta<T>(C, dimensionComponente, C22, dimensionComponente, dimensionComponente);
    }

    cout << "Matriz Resultante:" << endl;
    mostrarMatriz<T>(dimension, C);
    return C;
}

template <typename T>
void mostrarMatriz(size_t cantidadFilas, size_t cantidadColumnas, T **matriz) {
    for(int i = 0; i < cantidadFilas; i++) {
        for(int j = 0; j < cantidadColumnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T>
void mostrarMatriz(size_t dimension, T **matriz) {
    mostrarMatriz<T>(dimension, dimension, matriz);
}

template <typename T>
void armarCompuesta(T **compuesta, size_t dimensionComponente, T **componente, size_t desplazamientoFila, size_t desplazamientoColumna) {
    for(int i = 0; i < dimensionComponente; i++) {
        for(int j = 0; j < dimensionComponente; j++) {
            compuesta[i + desplazamientoFila][j + desplazamientoColumna] = componente[i][j];
        }
    }
}

template <typename T>
T **restar(size_t cantidadFilas, size_t cantidadColumnas, T **A, T **B) {
    T **resultado = generarMatriz<T>(cantidadFilas, cantidadColumnas);
    for(int i = 0; i < cantidadFilas; i++) {
        for(int j = 0; j < cantidadColumnas; j++) {
            resultado[i][j] = A[i][j] -  B[i][j];
        }
    }
    return resultado;
}

template <typename T>
T **restar(size_t dimension, T **A, T **B) {
    return restar<T>(dimension, dimension, A, B);
}

template <typename T>
T **sumar(size_t cantidadFilas, size_t cantidadColumnas, T **A, T **B) {
    T **resultado = generarMatriz<T>(cantidadFilas, cantidadColumnas);
    for(int i = 0; i < cantidadFilas; i++) {
        for(int j = 0; j < cantidadColumnas; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
    return resultado;
}

template <typename T>
T **sumar(size_t dimension, T **A, T **B) {
    return sumar<T>(dimension, dimension, A, B);
}

template <typename T>
T **obtenerComponente(T **compuesta, size_t dimensionComponente, size_t desplazamientoFila, size_t desplazamientoColumna) {
    T **componente = generarMatriz<T>(dimensionComponente);
    for(int i = 0; i < dimensionComponente; i++) {
        for(int j = 0; j < dimensionComponente; j++) {
            componente[i][j] = compuesta[i + desplazamientoFila][j + desplazamientoColumna];
        }
    }
    return componente;
}

template <typename T>
T **generarMatriz(size_t cantidadFilas, size_t cantidadColumnas) {
    T **resultado = new T*[cantidadFilas];
    for(int i = 0; i < cantidadFilas; i++) {
        resultado[i] = new T[cantidadColumnas]{0};
    }
    return resultado;
}

template <typename T>
T **generarMatriz(size_t dimension) {
    return generarMatriz<T>(dimension, dimension);
}