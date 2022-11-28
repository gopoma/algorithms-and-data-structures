#include <iostream>
#include <vector>

using namespace std;

vector<int> people;
vector<int> combination;

void go(int offset, int k) {
    if (k == 0) {
        return;
    }
    for (int i = offset; i <= people.size() - k; ++i) {
        combination.push_back(people[i]);
        go(i+1, k-1);
        combination.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 5, k = 2;

    for (int i = 0; i < n; ++i) { 
        people.push_back(i+1); 
    }
    go(0, k);

    return 0;
}