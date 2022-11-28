#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    vector<ll> a;
    for(ll i = 0; i < n; i++) {
        ll v;
        cin >> v;
        a.push_back(v);
    }

    ll counter = 0;

    while(!a.empty()) {
        if(a.size() <= 3) {
            counter += a.size();
            a.clear();
        } else {
            bool deleted = false;
            if(a[1] != a[a.size() - 1]) {
                a.erase(a.begin() + 0);
                counter++;
                continue;
            }
            for(ll i = 1; i < a.size() - 1; i++) {
                if(a[i - 1] != a[i + 1]) {
                    a.erase(a.begin() + i);
                    deleted = true;
                    counter++;
                }
            }
            if(a[a.size() - 2] != a[0]) {
                a.erase(a.begin() + a.size() - 1);
                deleted = true;
                counter++;
            }
            if(!deleted) {
                a.pop_back();
                a.pop_back();
                counter++;
            }
        }
    }
    cout << counter << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}