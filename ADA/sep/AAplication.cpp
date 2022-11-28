#include <iostream>
#define INVALID_INPUT -1

using namespace std;
using i64 = long long;

i64 A(i64 m, i64 n) {
    if(m == 0) {
        return n + 1;
    } else if(m > 0 && n == 0) {
        return A(m - 1, 1);
    } else if(m > 0 && n > 0) {
        return A(m - 1, A(m, n - 1));
    }
    return INVALID_INPUT;
}

int main() {
    const int m = 2;
    const int n = 4;
    cout << A(m, n) << endl;

    return 0;
}