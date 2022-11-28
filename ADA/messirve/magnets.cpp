#include <iostream>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    i64 n;
    cin >> n;
    string base;
    cin >> base;
    i64 groups = 1;
    for(i64 i = 1; i < n; i++) {
        string current;
        cin >> current;

        if(base != current) {
            base = current;
            groups++;
        }
    }

    cout << groups << endl;

    return 0;
}