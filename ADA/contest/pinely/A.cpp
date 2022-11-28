#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    
    if(n == a && a == b) {
        cout << "YES";
    } else if(a + b >= n) {
        cout << "NO";
    } else {
        if((n - (a + b)) == 1) {
            cout << "NO";
        } else {
            cout << "YES";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll t;
    cin >> t;
    
    while(t--) {
        solve();
    }
}