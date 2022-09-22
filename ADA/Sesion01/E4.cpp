#include <iostream>
#include <vector>

using namespace std;

void sortDesc(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size() - i; j++) {
            if(v[j] < v[j + 1]) {
                int aux = v[j + 1];
                v[j + 1] = v[j];
                v[j] = aux;
            }
        }
    }
}

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(7);
    v.push_back(8);

    sortDesc(v);
    printVector(v);

    return 0;
}