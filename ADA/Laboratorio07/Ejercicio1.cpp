#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;
using i64 = long long;

template <typename T>
void show(size_t n, T arr[]) {
    for(size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const size_t n = 4;
    const size_t M = 5;
    i64 p[n] = {3, 4, 5, 2};
    i64 b[n] = {4, 5, 6, 3};

    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < n - i - 1; j++) {
            if(p[j] > p[j + 1]) {
                i64 tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;

                i64 tmp2 = b[j];
                b[j] = b[j + 1];
                b[j + 1] = tmp2;
            }
        }
    }

    cout << "Datos del problema:" << "\n";
    cout << "n: " << n << "\n";
    cout << "M: " << M << "\n";
    cout << "p = (";
    for(size_t i = 0; i < n-1; i++) {
        cout << p[i] << ", ";
    }
    cout << p[n-1] << ")" << "\n";

    cout << "b = (";
    for(size_t i = 0; i < n-1; i++) {
        cout << b[i] << ", ";
    }
    cout << b[n-1] << ")" << "\n" << "\n";

    i64 dp[n+1][M+1]{};
    for(size_t j = 1; j < M+1; j++) {
        for(size_t i = 1; i < n+1; i++) {
            if(p[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j-p[i-1]] + b[i-1], dp[i-1][j]);
            }
        }
    }

    cout << "Matriz de Arrastre:" << "\n";
    cout << " \t";
    for(size_t i = 0; i < M+1; i++) {
        cout << i << "\t";
    }
    cout << "\n";
    for(size_t i = 0; i < n+1; i++) {
        if(i > 0) {
            cout << "p=" << p[i-1] << " b=" << b[i-1] << "\t";
        } else {
            cout << "0" << "\t";
        }
        for(size_t j = 0; j < M+1; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";

    bool S[n]{};
    size_t i = n;
    size_t j = M;

    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j]) {
            S[i-1] = false;
        } else {
            S[i-1] = true;
            j -= p[i-1];
        }
        i--;
    }

    cout << "Representacion de la Solucion:" << "\n";
    cout << "S = (";
    for(size_t i = 0; i < n-1; i++) {
        cout << S[i] << ", ";
    }
    cout << S[n-1] << ")" << "\n";
    cout << "Beneficio Maximo: " << dp[n][M] << endl;

    return 0;
}