#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned long long A, B, C, D, counter = 0;
    cin >> A >> B >> C >> D;

    for(int i = A; i <= B; i++) {
        if(i % C != 0 && i % D != 0) {
            counter++;
        }
    }

    cout << counter << endl;
}