#include <iostream>

using namespace std;

long long raise(long long a, long long n) {
    if(n == 0) {
        return 1;
    } else {
        long long partial = raise(a, n/2);
        return (n % 2 == 0) ? partial * partial : partial * partial * a;
    }
}

int main() {
    cout << raise(2, 10) << endl;

    return 0;
}