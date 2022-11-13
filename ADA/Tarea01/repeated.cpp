#include <iostream>

using namespace std;

bool containsRepeated(int nums[], int tam) {
    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam - i - 1; j++) {
            if(nums[j] == nums[j + 1]) {
                return true;
            } else if(nums[j] > nums[j + 1]) {
                int aux = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = aux;
            }
        }
    }
    return false;
}

int main() {
    int tam;
    cin >> tam;

    int nums[tam];
    for(int i = 0; i < tam; i++) {
        cin >> nums[i];
    }

    if(containsRepeated(nums, tam)) {
        cout << "Contiene duplicados";
    } else {
        cout << "No contiene duplicados";
    }
    cout << endl;

    return 0;
}