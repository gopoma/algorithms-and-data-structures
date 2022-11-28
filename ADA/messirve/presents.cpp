#include <iostream>
#include <cstddef>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    size_t n;
    cin >> n;
    i64 p[n];
    for(size_t i = 1; i <= n; i++) {
        i64 tmp;
        cin >> tmp;
        p[tmp-1] = i;
    }

    for(size_t i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}