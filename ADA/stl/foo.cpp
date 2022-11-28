#include <iostream>
#include <queue>

using namespace std;
using i64 = long long;

int main() {
    queue<i64> A;
    A.push(1);
    A.push(2);
    queue<i64> B;
    B.push(1);
    B.push(3);

    cout << (A == B) << endl;

    return 0;
}