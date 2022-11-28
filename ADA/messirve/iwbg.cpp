#include <iostream>
#include <set>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    i64 n;
    cin >> n;

    set<i64> S;
    i64 p;
    cin >> p;
    for(i64 i = 0; i < p; i++) {
        i64 a;
        cin >> a;
        S.insert(a);
    }

    cin >> p;
    for(i64 i = 0; i < p; i++) {
        i64 a;
        cin >> a;
        S.insert(a);
    }

    if(S.size() == n) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
    cout << endl;

    return 0;
}