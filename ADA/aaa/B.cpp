#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll result = (n * (n + 1))/2;

    vector<string> d;
    for(ll i = 0; i < n; i++) {
        string subStr;
        for (ll j = i; j < n; j++) {
            subStr += s[j];

            if(subStr.size() > 1 && !count(d.begin(), d.end(), subStr)) {
                map<char, ll> tmp;
                ll max = 1;
                for(ll k = 0; k < subStr.size(); k++) {
                    if(tmp[subStr[k]] == 0) {
                        tmp[subStr[k]] = 1;
                    } else {
                        tmp[subStr[k]]++;
                        if(tmp[subStr[k]] > max) {
                            max = tmp[subStr[k]];
                        }
                    }
                }

                if(max > tmp.size()) {
                    result--;
                } else {
                    d.push_back(subStr);
                }
            }
        }
    }
    cout << result << endl;
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