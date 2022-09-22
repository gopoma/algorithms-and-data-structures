#include <iostream>
#include <cctype>

using namespace std;

void generatePyramid(int h) {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < h - i; j++) {
            cout << " ";
        }
        for(int j = 0; j < 2 * (i + 1) - 1; j++) {
            cout << "*";
        }
        for(int j = 0; j < h - i; j++) {
            cout << " ";
        }
        cout << endl;
    }
}

int main() {
    int h;
    cout << "Ingrese la altura de la piramide: ";
    cin >> h;

    generatePyramid(h);

    return 0;
}