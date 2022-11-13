#include <iostream>

using namespace std;

#define x 2
#define y 13

long long pot(long long a, long long n) {
    if(n == 0) {
        return 1;
    } else {
        long long aux = pot(a, n/2);
        return (n % 2 == 0)? aux * aux : aux * aux * a;
    }
}

int main() {
    cout << pot(x, y) << endl;

    return 0;
}