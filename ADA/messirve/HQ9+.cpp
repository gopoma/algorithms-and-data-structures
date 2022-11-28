#include <iostream>
#include <cstddef>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string p;
    cin >> p;
    bool wprint = false;
    for(size_t i = 0; i < p.size(); i++) {
        if(p[i] == 'H' || p[i] == 'Q' || p[i] == '9') {
            wprint = true;
        }
    }

    if(wprint) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << endl;

    return 0;
}