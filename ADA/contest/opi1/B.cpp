#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    
    string S;
    cin >> S;

    ll frequencies[255]{0};
    for(ll i = 0; i < N; i++) {
        frequencies[S[i]]++;
    }

    ll m = -1;
    for(int i = 0; i < 255; i++) {
        if(frequencies[i] > m) {
            m = frequencies[i];
        }
    }

    cout << N - m << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}