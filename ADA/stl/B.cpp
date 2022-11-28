#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    i64 n, k;
    cin >> n >> k;

    i64 a[n];
    for(i64 i = 0; i < n; i++) {
        cin >> a[i];
    }

    i64 current = a[0];
    i64 counter = 0;
    for(i64 i = 1; i < n; i++) {
        if(a[i] == n) {
            current = n;
            break;
        }
        if(current > a[i]) {
            counter++;
        } else {
            current = a[i];
            counter = 1;
        }
        if(counter == k) {
            break;
        }
    }
    cout << current << endl;

    return 0;
}