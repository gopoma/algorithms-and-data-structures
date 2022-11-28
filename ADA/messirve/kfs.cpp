#include <iostream>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    i64 n;
    cin >> n;

    i64 mnds = -1;
    i64 i = 0;
    i64 rr;
    cin >> rr;
    for(i64 j = 1; j < n; j++) {
        i64 a;
        cin >> a;

        if(a < rr) {
            if(j - i > mnds) {
                mnds = j - i;
            }
            i = j;
        }
        rr = a;
    }
    if(n - i > mnds) {
        mnds = n - i;
    }

    cout << mnds << endl;

    return 0;
}