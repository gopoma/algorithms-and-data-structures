#include <iostream>
#include <algorithm>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    i64 a, b, c;
    cin >> a >> b >> c;

    if(a != 1 && b != 1 && c != 1) {
        cout << a * b * c;
    } else if(a == 1 && b == 1 && c == 1) {
        cout << 3;
    } else {
        if(a == 1 && b == 1) {
            cout << (2*c);
        } else if(a == 1 && c == 1) {
            cout << (b+2);
        } else if(b == 1 && c == 1) {
            cout << (2*a);
        } else if(a == 1) {
            cout << ((b+1)*c);
        } else if(b == 1) {
            cout << (max((a+1)*c, a*(1+c)));
        } else {
            cout << (a*(b+1));
        }
    }
    cout << endl;

    return 0;
}