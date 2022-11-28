#include <iostream>
#include <map>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<i64, i64> frs;
    const i64 hs = 4;
    i64 first;
    cin >> first;
    frs[first] = 1;
    for(i64 i = 1; i < hs; i++) {
        i64 s;
        cin >> s;

        if(frs[s] == 0) {
            frs[s] = 1;
        } else {
            frs[s]++;
        }
    }

    i64 r = 0;
    for(auto const& [s, f]: frs) {
        if(f > 1) {
            r += f - 1;
        } 
    }
    cout << r << endl;

    return 0;
}