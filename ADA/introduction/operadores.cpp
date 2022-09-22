#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int num1 = 2;
    num1--;

    cout << ++(--num1) << endl;

    float miFloat = 400.5f;
    float raizC = sqrt(miFloat);

    cout << raizC << endl;

    cout << pow(2, 8) << endl;

    double pi = 3.1416/2.0;
    cout << sin(pi) << endl;
    cout << cos(pi) << endl;
    cout << tan(pi) << endl;

    cout << "Manipulación de floats and doubles:" << endl;
    cout << round(2.56) << endl;
    cout << floor(2.8) << endl;
    cout << ceil(2.25) << endl;
    cout << trunc(45.666) << endl;

    return 0;
}