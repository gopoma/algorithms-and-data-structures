#include <iostream>
#include <cstddef>
#include <queue>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    size_t n;
    cin >> n;

    size_t k1;
    cin >> k1;
    queue<i64> A;
    queue<i64> base;
    for(size_t i = 0; i < k1; i++) {
        i64 v;
        cin >> v;
        A.push(v);
        base.push(v);
    }

    size_t k2;
    cin >> k2;
    queue<i64> B;
    queue<i64> base2;
    for(size_t i = 0; i < k2; i++) {
        i64 v;
        cin >> v;
        B.push(v);
        base2.push(v);
    }

    bool ok = true;
    i64 counter = 0;
    bool first = true;
    while(ok) {
        i64 a = A.front();
        i64 b = B.front();

        if(a > b) {
            A.push(b);
            A.push(a);
        } else {
            B.push(a);
            B.push(b);
        }
        A.pop();
        B.pop();

        counter++;
        if(A.empty() || B.empty()) {
            break;
        }

        if(!first && (base == A && base2 == B)) {
            ok = false;
            break;
        }
        first = false;
    }

    if(ok) {
        cout << counter << " ";
        if(A.empty()) {
            cout << 2 << endl;
        } else {
            cout << 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}