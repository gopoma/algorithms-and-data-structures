#include <iostream>

using namespace std;

const long long MOD = 1000000007;

long long exp(long long a,long long b,long long c){
    if(b==0)return 1;
    long long dev=exp(a,b/2,c);
    dev=(dev*dev)%c;
    if(b&1)dev=(dev*a)%c;
    return dev;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long N, K;
    cin >> N >> K;

    const long long result = exp(K, N, MOD);
    cout << result << endl;

    return 0;
}