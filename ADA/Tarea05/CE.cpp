#include <iostream>

using namespace std;

long long multiply(long long p, long long q) {
    if(q == 0) {
        return 0;
    }
    if(q == 1) {
        return p;
    }
    return (q % 2 == 0) ? multiply(2*p, q/2) : multiply(2*p, q/2) + p;
}

int main() {
    cout << multiply(256, 789) << endl;

    return 0;
}