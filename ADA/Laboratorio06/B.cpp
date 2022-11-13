#include "Array.h"
#include "Array.cpp"

void solve() {
    size_t length = 8;
    i64 *nums = new i64[length]{6, 0, 3, 2, 5, 7, 4, 1};
 
    cout << "Arreglo Generado:" << "\n";
    showArray<i64>(length, nums);

    mergeSort<i64>(length, nums);
    cout << "\nArreglo Ordenado:" << "\n";
    showArray<i64>(length, nums);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}