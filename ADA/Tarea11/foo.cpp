#include <iostream>
#include <set>
#include <cstddef>

using namespace std;

int main() {
    set<size_t> s;
    for(size_t i = 1; i < 10; i++) {
        s.insert(i);
    }

    for(size_t v: s) {
        cout << v << " ";
    }
    cout << endl;
    cout << *s.cbegin() << endl;
    s.erase(4);
    for(size_t v: s) {
        cout << v << " ";
    }
    cout << endl;
    s.erase(0);
    for(size_t v: s) {
        cout << v << " ";
    }
    s.erase(1);
    cout << endl;
    cout << *s.cbegin() << endl;

    return 0;
}