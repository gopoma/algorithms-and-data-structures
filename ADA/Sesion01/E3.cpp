#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> filterMultiples(vector<int> v, int num) {
    vector<int> multiples;
    vector<int> nonMultiples;

    for(int i = 0; i < v.size(); i++) {
        int current = v[i];
        if(current % num == 0) {
            multiples.push_back(current);
        } else {
            nonMultiples.push_back(current);
        }
    }

    vector<vector<int>> result;
    result.push_back(multiples);
    result.push_back(nonMultiples);
    return result;
}

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}   

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(10);

    vector<vector<int>> result = filterMultiples(v, 5);
    vector<int> multiples = result[0];
    vector<int> nonMultiples = result[1];

    printVector(multiples);
    printVector(nonMultiples);

    return 0;
}