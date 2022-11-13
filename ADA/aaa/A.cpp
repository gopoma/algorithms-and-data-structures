#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
using i64 = long long;

void solve() {
    i64 n;
    cin >> n;

    i64 result = (n % 2 == 0) ? n / 2 : n / 2 + 1;
    cout << result << endl;
}

int main() {   
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    i64 t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}