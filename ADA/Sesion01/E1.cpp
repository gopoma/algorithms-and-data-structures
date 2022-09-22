#include <iostream>
#include <vector>

using namespace std;

int sum(int arr[], int tam) {
    int result = 0;
    for(int i = 0; i < tam; i++) {
        result += arr[i];
    }
    return result;
}

int sum(vector<int> v) {
    int result = 0;
    for(int i = 0; i < v.size(); i++) {
        result += v[i];
    }
    return result;
}

int main() {    
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << sum(arr, 10) << endl;
    
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << sum(v) << endl;

    return 0;
}