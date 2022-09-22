#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int miEntera = 10;
    bool estaNublado = false;
    long long poblacionMundial = 7700000000;

    char miChar = 'A';
    char miOtroChar = 65;

    float pi = 3.1416f;
    double miDouble = 8.78832998234793243274;

    float result = 8.78832998234793243274; // Lo redondea

    double miDouble2 = 1234567890.0 / 10000000000.0;
    cout << miDouble2 << endl;
    cout << fixed << setprecision(2) << miDouble2 << endl;
    cout << fixed << setprecision(20) << miDouble2 << endl;

    return 0;
}