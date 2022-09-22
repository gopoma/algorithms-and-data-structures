#include <iostream>
#include <vector>

using namespace std;

vector<int> invert(vector<int> v) {
    vector<int> result;
    for(int i = v.size() - 1; i >= 0; i--) {
        result.push_back(v[i]);
    }
    return result;
}

void showVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int *invert(int result[], int arr[], int tam) {
    for(int i = 0; i < tam; i++) {
        result[i] = arr[tam - i - 1];
    }
    return result;
}

void showArray(int arr[], int tam) {
    for(int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    showVector(v);
    showVector(invert(v));

    int result[] = {0, 0, 0, 0, 0, 0, 0};
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int *r = invert(result, arr, 7);
    showArray(r, 7);

    return 0;
}