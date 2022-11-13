#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    bool wasFound = 0;

    while(!wasFound) {
        string casted = to_string(++N);
        set<char> *tmp = new set<char>(begin(casted), end(casted));
        if(tmp->count('0') == 0 && casted.size() == tmp->size()) {
            wasFound = true;
        }
    }

    cout << N << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
