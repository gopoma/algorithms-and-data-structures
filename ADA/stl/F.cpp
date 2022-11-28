#include <iostream>
#include <cstddef>
#include <stack>

using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    stack<char> tmp;
    bool ok = true;
    for(size_t i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            tmp.push(s[i]);
        } else {
            if(tmp.empty()) {
                ok = false;
                break;
            } else {
                tmp.pop();
            }
        }
    } 

    if(!ok || !tmp.empty()) {   
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}