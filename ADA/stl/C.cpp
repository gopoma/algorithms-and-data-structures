#include <iostream>
#include <cstddef>
#include <algorithm>

using namespace std;
using i64 = long long;

template <typename T>
void show(T arr[], size_t n) {
    for(size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void solve() {
    size_t n;
    cin >> n;
    size_t bs = n+2;
    i64 b[bs];
    i64 S = 0;
    for(size_t i = 0; i < bs; i++) {
        cin >> b[i];
        S += b[i];
    }

    sort(b, b+bs);
    S -= b[bs-1];

    size_t cc = 0;
    i64 r[n];
    bool found = false;
    for(size_t i = 0; i < bs-1; i++) {
        if(!found && S - b[i] == b[bs-1]) {
            found = true;
        } else {
            r[cc] = b[i];
            cc++;
        }
    }

    if(found || S == (2*b[bs - 2])) {
        show<i64>(r, n);
    } else {
        cout << -1 << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    i64 t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}